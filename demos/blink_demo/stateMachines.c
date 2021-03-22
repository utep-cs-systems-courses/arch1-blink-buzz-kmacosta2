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
  case 1:
    red_on = 0;
    state = 2;
    break;
  case 2:
    red_on = 1;
    state = 3;
    break;
  case 3:
    red_on = 0;
    state = 4;
  case 4:
    red_on = 1;
    state = 5;
    break;
  case 5:
    red_on = 0;
    state = 0;
    break;
  }
  return 1;			/*doesn't always change an led */
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

  static int state = 0;
  static enum {R=0, G=1, R2=2, R3=3} color = G;
  switch (state++) {
  case 0: red_on = 1; green_on = 0; break;
  case 1: red_on = 0; break; 
  case 2: red_on = 1; break;
  case 3: state = 0; red_on = 0; green_on = 1; break;
  }
  changed = 1;

  led_changed = changed;
  led_update();
}

