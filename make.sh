#!/bin/bash

rm -rf layout/Applications/AirDropHelper.app/
LAYOUT="layout"
CONTROL_FILE=control
DPKG_DEBIAN_PATH="$LAYOUT"/DEBIAN
APPS="$LAYOUT"/Applications
mkdir -p $APPS

pushd AirDropHelper
rm -rf build
xcodebuild BUILD_ROOT=../build | xcpretty
ldid -Sent.plist build/Release-appletvos/AirDropHelper.app/AirDropHelper
rm -rf build/Release-appletvos/AirDropHelper.app/embedded.mobileprovision
rm -rf build/Release-appletvos/AirDropHelper.app/_CodeSignature
cp -r build/Release-appletvos/AirDropHelper.app ../layout/Applications/
popd

SDK_PATH="`xcrun --sdk appletvos --show-sdk-path`"

pushd breezyd
xcrun -sdk appletvos clang -v -isysroot $SDK_PATH -arch arm64 -Iinclude -framework Foundation -framework TVServices -mappletvos-version-min=9.0 -o breezyd breezyd.m

ldid -Sent.plist breezyd
cp breezyd ../layout/usr/bin/
popd
