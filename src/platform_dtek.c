#include "platform.h"

// Framebuffer: varje byte här är en pixel på skärmen
static volatile unsigned char *VGA = (volatile unsigned char *) 0x08000000;

void pixel(int x, int y, unsigned char color) {
    if (x < 0 || x >= SCREEN_W || y < 0 || y >= SCREEN_H) return; // protect memory
    VGA[y * SCREEN_W + x] = color;
}

void draw_rect(int start_x, int start_y, int width, int height, unsigned char color) {
    for (int y = start_y; y < start_y + height; y++) {
        for (int x = start_x; x < start_x + width; x++) {
            pixel(x, y, color);
        }
    }
}

void draw_vline(int x, int start_y, int end_y, unsigned char color) {
    for (int y = start_y; y < end_y; y++) {
        pixel(x, y, color);
    }
}

int get_sw(void){
  volatile int *sw = (volatile int *) 0x04000010;
  return *sw;
}

int get_btn(void){
  volatile int *btn = (volatile int *) 0x040000d0;
  return *btn;
}

void set_leds(int led_mask) {
  volatile int *leds = (volatile int *) 0x04000000;
  *leds = led_mask;
}

void set_displays(int display_number, int value){
  volatile int *display = (volatile int *) ((display_number * 0x00000010) + 0x04000050);
  *display = value;
}

int digit_to_segments(int digit) {
    switch (digit) {
        case 0: return 0xC0;   // 0b11000000
        case 1: return 0xF9;   // 0b11111001
        case 2: return 0xA4;   // 0b10100100
        case 3: return 0xB0;   // 0b10110000
        case 4: return 0x99;   // 0b10011001
        case 5: return 0x92;   // 0b10010010
        case 6: return 0x82;   // 0b10000010
        case 7: return 0xF8;   // 0b11111000
        case 8: return 0x80;   // 0b10000000
        case 9: return 0x90;   // 0b10010000
        default: return 0xFF;  // all segments off (blank)
    }
}
// ===== Timer (0x04000020, se TIMER.pdf) =====
// Register: [0] status (TO), [1] control (ITO/CONT/START), [2] periodl, [3] periodh
static volatile int *TIMER = (volatile int *) 0x04000020;

#define TIMER_IRQ    16                       // mcause för timeravbrott på DTEK-V
#define TICK_PERIOD  (30000000 / TICKS_PER_SEC - 1) // 30 MHz, perioden räknas som värde+1

volatile unsigned int timer_ticks = 0;        // ökas av avbrottet, läses av spelloopen

extern void enable_interrupt(void);           // boot.S

void timer_init(void) {
    TIMER[2] = TICK_PERIOD & 0xFFFF;          // periodl
    TIMER[3] = (TICK_PERIOD >> 16) & 0xFFFF;  // periodh
    TIMER[0] = 0;                             // nollställ ev. gammal TO-flagga
    TIMER[1] = 0x7;                           // ITO + CONT + START
    enable_interrupt();                       // sist, när allt annat är klart
}

void handle_interrupt(unsigned cause) {
    if (cause == TIMER_IRQ) {
        TIMER[0] = 0;                         // kvittera, annars avbryts vi direkt igen
        timer_ticks++;
    }
}
