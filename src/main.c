#include "eadk.h"

const char eadk_app_name[] __attribute__((section(".rodata.eadk_app_name"))) = "Crash-my-Numworks";
const uint32_t eadk_api_level  __attribute__((section(".rodata.eadk_api_level"))) = 0;

int main(int argc, char * argv[]) {
  volatile int *ptr = (int *)0xFFFFFFFF;
  *ptr = 0;
  return 0; 
}
