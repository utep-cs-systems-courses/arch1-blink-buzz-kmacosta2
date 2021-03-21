#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

char toggle_red()		/* always toggle! */
{
  static char state = 0;
  char changed_2 = 0;

  switch (state) {  /*everytime we come back to red's state, it blinks one more time than last time and it will alternate back to green to blink once*/
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 1;
    state = 2;
    break;
  case 2:
    red_on = 1;
    state = 3;
    break;
  case 3:
    red_on = 1;
    state = 4;
    break;
  case 4:
    red_on = 0;
    state = 0;
    changed_2 = 1;
    break;
  }
  return changed_2;			/*doesn't always change an led */
}

char toggle_green()  /* only toggle green if red is off  */
{
  char changed = 0;
  if (red_on) {
    green_on ^= 1;
    changed = 1;
  }
  return changed;
}


void state_advance()		/* alternate between toggling red & green */
{
  char changed = 0;  

  static enum {R=0, G=1} color = G;
  switch (color) {
  case R: changed = toggle_red(); color = G; break;
  case G: changed = toggle_green(); color = R; break;
  }

  led_changed = changed;
  led_update();
}



