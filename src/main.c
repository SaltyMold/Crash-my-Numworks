#include "eadk.h"

const char eadk_app_name[] __attribute__((section(".rodata.eadk_app_name"))) = "Crash-my-Numworks";
const uint32_t eadk_api_level  __attribute__((section(".rodata.eadk_api_level"))) = 0;

int main(int argc, char * argv[]) {
  eadk_display_push_rect_uniform(eadk_screen_rect, eadk_color_black);
  eadk_display_draw_string("Presse Home to cancel", (eadk_point_t){60, 80}, true, eadk_color_white, eadk_color_black);
  eadk_display_draw_string("Presse 9 to crash", (eadk_point_t){60, 100}, true, eadk_color_white, eadk_color_black);

  while (1) {
    eadk_keyboard_state_t state = eadk_keyboard_scan();

    if (eadk_keyboard_key_down(state, eadk_key_home)) {
        break;
    } else if (eadk_keyboard_key_down(state, eadk_key_nine)) {
      volatile int *ptr = (int *)0xFFFFFFFF;
      *ptr = 0;
    }
  }
  return 0; 
}
