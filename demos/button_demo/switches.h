#ifndef switches_included
#define switches_included
//P2.0 - P2.3
#define SW1 BIT0
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3
#define SWITCHES  (SW1 | SW2 | SW3 | SW4)

void switch_init();
void switch_interrupt_handler();
void switchSM();

extern char switch_state_down, switch_state_down2, switch_state_down3, switch_state_down4, switch_state_changed; /* effectively boolean */

#endif // included
