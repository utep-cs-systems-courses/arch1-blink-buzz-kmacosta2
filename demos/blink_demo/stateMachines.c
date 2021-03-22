#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

char toggle_red()		/* always toggle! */
{
  static char state = 0;
  char changed_2 = 0;

  switch (state) { //want it to consistently blink five times then go back to green
  case 0:      //making sure it starts turned on until it reaches state 5
    red_on = 1;
    state = 1;
    break;
  case 4:
    red_on = 1;
    state = 5;
    break;
  case 5:
    red_on = 0;
    state = 0;
    changed_2 = 1;
    break;
  default:
    state++;
  }
  return changed_2;			/*doesn't always change an led */
}

char toggle_green()  /* only toggle green if red is off  */
{
  char changed = 0;
  if (1-red_on) {
    green_on ^= 1;
    changed = 1;
  }
  return changed;
}


void state_advance()		/* alternate between toggling red & green */
/* */
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

