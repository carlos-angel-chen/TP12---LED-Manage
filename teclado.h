#ifndef TECLADO_H
#define TECLADO_H

#define ALL_LED 255
#define GAP 48
#define PUERTO 'A'

void teclado(void);
void cleanBuffer(void);
void pSwitch(void (*p2func)(uint8_t, uint16_t), uint8_t puerto, uint16_t n);

#endif /* TECLADO_H */

