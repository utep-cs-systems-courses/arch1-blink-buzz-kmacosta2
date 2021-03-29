#include "led.h"
#include "switches.h"
#include "buzzer.h"

void switchSM()
{
  if(switch_state_down) red_on = 1;//here call sm1 instead..
  else red_on = 0;
  if(switch_state_down2) green_on = 1;
  else green_on = 0;

  if(switch_state_down3 && !switch_state_down) buzzer_set_period(2000);
  else if (switch_state_down3 && switch_state_down) buzzer_set_period(1000);
  else buzzer_set_period(0);//silence
    //if(switch_state_down4)    
  led_changed = 1;
  led_update();
}

void sm1() //call this method for ssd == true
{
  static char state = 0;
  switch(state) { /*in my cases there'll be teh sequences of the lights & the frequencies. And use the wdInterrupt!! */
  case 0: red_on = 1; state++; buzzer_set_period(2000); break;
  case 1: red_on = 0; state = 0; buzzer_set_period(0); break;
  default: state = 0;
  }
}

void sm2()
{
  static char state = 0;
  switch(state) {
  case 0: green_on = 1; state++; buzzer_set_period(2000); break;
  case 1: green_on = 0; state = 0; buzzer_set_period(1000); break;
  default: state = 0; buzzer_set_period(0);
  }
} 
void sm3()
{
  static char state = 0;
  switch(state) {
  case 0: green_on = 1; red_on = 0; state++; buzzer_set_period(2000); break;
  case 1: green_on = 0; red_on = 1; state = 0; buzzer_set_period(1000); break;
  default: state = 0; buzzer_set_period(0);
  }
}
void sm4()
{
 static char state = 0;
  switch(state) {
  case 0: green_on = 1; red_on = 1; state++; buzzer_set_period(900); break;
  case 1: green_on = 0; red_on = 0; state = 0; buzzer_set_period(2000); break;
  default: state = 0; buzzer_set_period(0);
  }
} 
