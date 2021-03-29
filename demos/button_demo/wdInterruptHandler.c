#include <msp430.h>
#include "switches.h"
#include "led.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){ /* 250 interrupts/sec */
  static char blink_count = 0; /*every 1/4 sec*/

  //char p2val = switch_update_interrupt_sense();
 
  if (++blink_count == 62) {
    //switchSM();
     blink_count = 0;
  }
}
