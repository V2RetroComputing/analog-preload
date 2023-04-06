# ∀2 Retro Computing Analog VGA Card Firmware Data Preloader

This firmware data preloader is necessary when migrating from the old monolithic firmware builds.

This firmware image will wipe the entire flash storage and install the default fontset.

Font blocks 00 - 1F are converted from the ROMXce default fonts,
blocks 20-22 contain the default fonts for Apple II, IIE, and IIGS systems,
block 23 contains the default font used for Pravetz systems,
and block 24 is a custom font I designed. Blocks 25-27 are currently unassigned but contain copies of the Reactive Micros font.

The firmware will perform it's duties and then return to bootloader mode for the install of the actual V2 Analog firmware.

Full details are available at [∀2 Retro Computing](https://www.v2retrocomputing.com/).
