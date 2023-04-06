#!/bin/bash

if [ -z ${PICO_SDK:+x} ]; then
  echo You must set PICO_SDK to the path where you downloaded https://github.com/raspberrypi/pico-sdk.git
  exit 1
fi

build_firmware() {
  if [ ! -d build ]; then
    ( mkdir -p build && cd build && cmake .. )
  fi
  make -C build
}

make -C defaults && build_firmware
