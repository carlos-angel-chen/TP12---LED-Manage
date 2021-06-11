/*
Cuando se realiza software para un microprocesador, no resulta conveniente 
probarlo en el mismo para cada modificación que se desea realizar. Es por esto 
que se suelen emular los dispositivos y puertos por software para la etapa de 
debuggeo.

Se pide escribir una librería que permita emular el funcionamiento de los 
puertos A, B y D. A y B son dos puertos de 8 bits, configurables tanto de 
entrada como de salida. D tiene 16 y es simplemente un alias para los puertos A 
y B juntos, siendo el B el menos significativo.

Crear las siguientes funciones o macros: bitSet, bitClr, bitToggle, bitGet,
maskOn, maskOff, maskToggle, utilizables para todos los puertos definidos
anteriormente.



El contenido de los puertos debe almacenarse en una variable estática dentro del
archivo fuente de la librería. El usuario debe poder leer y escribir en los puertos
solamente utilizando las funciones definidas.
*/

#include "funciones.h"
#include "user.h"
#include "teclado.h"
#include "hardware.h"

int main(void) 
{
    /*
    uint8_t puerto;
    uint16_t bit;
    uint16_t mask;
    
    puerto='D';
    bit=10;
    mask=5;
    
    bitSet(puerto, bit);
    printBits(puerto);
    maskOn(puerto, mask);
    printBits(puerto);
    */

    led_init();
    
    teclado();

    /*
    uint8_t puerto;
    puerto='A';
    teclado();
    */
    //printBits(puerto);

    return 0;   
}

