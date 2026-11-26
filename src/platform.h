#ifndef PLATFORM_H
#define PLATFORM_H

#define SCREEN_W 320
#define SCREEN_H 240

void pixel(int x, int y, unsigned char color);
void draw_rect(int start_x, int start_y, int width, int height, unsigned char color);
void draw_vline(int x, int start_y, int end_y, unsigned char color);

// ===== I/O =====
int get_sw(void);
int get_btn(void);
void set_leds(int led_mask);
void set_displays(int display_number, int value);
int digit_to_segments(int digit);

// ===== Timer =====
#define TICKS_PER_SEC 10                 // ett tick var 100 ms

extern volatile unsigned int timer_ticks;
void timer_init(void);

#endif