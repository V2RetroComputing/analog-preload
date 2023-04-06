#include <stdio.h>
#include <string.h>
#include <hardware/flash.h>
#include <hardware/dma.h>
#include <pico/bootrom.h>
#include <pico/stdlib.h>
#include "flash.h"
#include "fonts.h"

extern const uint8_t font_plusb[];
extern const uint32_t font_plusb_size;

int main() {
    // Erase chip
    flash_range_erase(0, FLASH_SIZE);

    flash_range_program((FLASH_FONT(0x00)-XIP_BASE), font_use, 2048);
    flash_range_program((FLASH_FONT(0x01)-XIP_BASE), font_usb, 2048);
    flash_range_program((FLASH_FONT(0x02)-XIP_BASE), font_clintonv1, 2048);
    flash_range_program((FLASH_FONT(0x03)-XIP_BASE), font_reactive, 2048);
    flash_range_program((FLASH_FONT(0x04)-XIP_BASE), font_paymar, 2048);
    flash_range_program((FLASH_FONT(0x05)-XIP_BASE), font_blippo, 2048);
    flash_range_program((FLASH_FONT(0x06)-XIP_BASE), font_byte, 2048);
    flash_range_program((FLASH_FONT(0x07)-XIP_BASE), font_colossal, 2048);
    flash_range_program((FLASH_FONT(0x08)-XIP_BASE), font_count, 2048);
    flash_range_program((FLASH_FONT(0x09)-XIP_BASE), font_flow, 2048);
    flash_range_program((FLASH_FONT(0x0a)-XIP_BASE), font_gothic, 2048);
    flash_range_program((FLASH_FONT(0x0b)-XIP_BASE), font_outline, 2048);
    flash_range_program((FLASH_FONT(0x0c)-XIP_BASE), font_pigfont, 2048);
    flash_range_program((FLASH_FONT(0x0d)-XIP_BASE), font_pinocchio, 2048);
    flash_range_program((FLASH_FONT(0x0e)-XIP_BASE), font_slant, 2048);
    flash_range_program((FLASH_FONT(0x0f)-XIP_BASE), font_stop, 2048);
    flash_range_program((FLASH_FONT(0x10)-XIP_BASE), font_eurob, 2048);
    flash_range_program((FLASH_FONT(0x11)-XIP_BASE), font_euroe, 2048);
    flash_range_program((FLASH_FONT(0x12)-XIP_BASE), font_clintonv2, 2048);
    flash_range_program((FLASH_FONT(0x13)-XIP_BASE), font_germane, 2048);
    flash_range_program((FLASH_FONT(0x14)-XIP_BASE), font_germanb, 2048);
    flash_range_program((FLASH_FONT(0x15)-XIP_BASE), font_frenche, 2048);
    flash_range_program((FLASH_FONT(0x16)-XIP_BASE), font_frenchb, 2048);
    flash_range_program((FLASH_FONT(0x17)-XIP_BASE), font_hebrewe, 2048);
    flash_range_program((FLASH_FONT(0x18)-XIP_BASE), font_hebrewb, 2048);
    flash_range_program((FLASH_FONT(0x19)-XIP_BASE), font_pluse, 2048);
    flash_range_program((FLASH_FONT(0x1a)-XIP_BASE), font_plusb, 2048);
    flash_range_program((FLASH_FONT(0x1b)-XIP_BASE), font_katakana, 2048);
    flash_range_program((FLASH_FONT(0x1c)-XIP_BASE), font_cyrillic, 2048);
    flash_range_program((FLASH_FONT(0x1d)-XIP_BASE), font_greek, 2048);
    flash_range_program((FLASH_FONT(0x1e)-XIP_BASE), font_esperanto, 2048);
    flash_range_program((FLASH_FONT(0x1f)-XIP_BASE), font_videx, 2048);
    flash_range_program((FLASH_FONT_APPLE_II-XIP_BASE), font_plusb, 2048);
    flash_range_program((FLASH_FONT_APPLE_IIE-XIP_BASE), font_reactive, 2048);
    flash_range_program((FLASH_FONT_APPLE_IIGS-XIP_BASE), font_reactive, 2048);
    flash_range_program((FLASH_FONT_PRAVETZ-XIP_BASE), font_cyrillic, 2048);
    flash_range_program((FLASH_FONT_EXTRA24-XIP_BASE), font_pcbold, 2048);
    flash_range_program((FLASH_FONT_EXTRA25-XIP_BASE), font_reactive, 2048);
    flash_range_program((FLASH_FONT_EXTRA26-XIP_BASE), font_reactive, 2048);
    flash_range_program((FLASH_FONT_EXTRA27-XIP_BASE), font_reactive, 2048);

#ifdef PICO_DEFAULT_LED_PIN
    // Flash LED for success
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
    for (int i = 0; i < 3; ++i) {
        gpio_put(PICO_DEFAULT_LED_PIN, 1);
        sleep_ms(100);
        gpio_put(PICO_DEFAULT_LED_PIN, 0);
        sleep_ms(100);
    }
#endif

    reset_usb_boot(0, 0);

    return 0;
}
