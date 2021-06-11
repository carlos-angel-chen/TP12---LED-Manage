#ifndef HARDWARE_H
#define HARDWARE_H

#define OFF "0"
#define ON "1"

void led_export(void);
void led_active_low(void);
void led_direction(void);
void all_led_on(void);
void all_led_off(void);
void led_init(void);
void delay(int numSec);
void led_unexport(void);
void led_value(int, char*);

#endif /* HARDWARE_H */

