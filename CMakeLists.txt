cmake_minimum_required(VERSION 3.16)

# Pull in SDK (must be before project)
include(cmake/pico_sdk_import.cmake)

project(v2-analog)
set(CMAKE_C_STANDARD 11)

pico_sdk_init()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DPICO_USE_MALLOC_MUTEX=1")

add_executable(v2-analog-preloader)

target_sources(v2-analog-preloader PUBLIC
    main.c
    defaults/blippo.o
    defaults/cyrillic.o
    defaults/frenche.o
    defaults/hebrewe.o
    defaults/pinocchio.o
    defaults/usb.o
    defaults/byte.o
    defaults/esperanto.o
    defaults/germanb.o
    defaults/katakana.o
    defaults/plusb.o
    defaults/use.o
    defaults/clintonv1.o
    defaults/clintonv2.o
    defaults/eurob.o
    defaults/germane.o
    defaults/outline.o
    defaults/pluse.o
    defaults/videx.o
    defaults/euroe.o
    defaults/gothic.o
    defaults/paymar.o
    defaults/reactive.o
    defaults/colossal.o
    defaults/flow.o
    defaults/greek.o
    defaults/pcbold.o
    defaults/slant.o
    defaults/count.o
    defaults/frenchb.o
    defaults/hebrewb.o
    defaults/pigfont.o
    defaults/stop.o
)

target_include_directories(v2-analog-preloader PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(v2-analog-preloader PUBLIC
    pico_multicore
    pico_stdlib
    pico_bootrom
    hardware_flash
)

pico_add_extra_outputs(v2-analog-preloader)
pico_set_binary_type(v2-analog-preloader no_flash)
