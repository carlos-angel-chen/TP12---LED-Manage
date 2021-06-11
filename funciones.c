#include "funciones.h"

/*******************************************************************************
 * • bitSet: Dado un puerto y un número de bit, debe cambiar su estado a 1.
 * La funcion bitSet recibe un uint8_t (char) para indicar qué tipo de puerto
 * tiene que acceder (A, B o D). 
 * Luego recibe el bit que quiere prender, este va de 0 a 7 si es puerto A o B y
 * de 0 a 15 si es puerto D.
 ******************************************************************************/
void bitSet(uint8_t port, uint16_t bit)
{
    int mask=1;                                                                 //es una mascara donde le doy el valor de 1 = b00000001
    if (port=='A' || port=='B' || port=='D')                                    //reviso que el port que ingrese sea de tipo A, B o D
    {
        switch(port)                                                            
        {
            case 'A':                                                           //si es puerto A
                if(bit>=CERO && bit <=BIT_8)                                           //verifico que el bit sea entre 0 y 7
                {
                    mask = mask<<bit;                                                  //hago un shifteo de bit veces el mask. quiere decir que si bit = 3
                    p.pAB.portA = p.pAB.portA | mask;                           //entonces mask vale b00001000 y coincide con el bit n° 3
                                                                                //luego accedo al puerto A (al ser variable global, tiene todos 0) y hago un or bit a bit con mask
                }                                                               
                else
                {
                    printf("ingresaste mal el bit del puerto A\n");
                }
                break;
            case 'B':                                                           //si es puerto B
                if(bit>=CERO && bit <=BIT_8)                                    //verifico que el bit sea entre 0 y 7
                {
                    mask = mask<<bit;                                           //hago un shifteo de bit veces el mask. quiere decir que si bit = 3
                    p.pAB.portB = p.pAB.portB | mask;                           //entonces mask vale b00001000 y coincide con el bit n° 3
                                                                                //luego accedo al puerto B (al ser variable global, tiene todos 0) y hago un or bit a bit con mask
                }                                                               
                else
                {
                    printf("ingresaste mal el bit del puerto B\n");
                }
                break;
            case 'D':                                                           //si es puerto B
                if(bit>=CERO && bit <=BIT_16)                                   //verifico que el bit sea entre 0 y 15
                {
                    mask = mask<<bit;                                           //hago un shifteo de bit veces el mask. quiere decir que si bit = 12
                    p.portD = p.portD | mask;                                   //entonces mask vale b0001.0000.0000.0000 y coincide con el bit n° 12
                                                                                //luego accedo al puerto D (al ser variable global, tiene todos 0) y hago un or bit a bit con mask
                }                                                               
                else
                {
                    printf("ingresaste mal el bit del puerto D\n");
                }
                break;
            default:
                printf("entraste al default de bitset");
                break;
        }
    }
    else
    {
        printf("Ingresaste mal el puerto\n");
    }
}
    
/*******************************************************************************
 * • bitClr: Dado un puerto y un número de bit, debe cambiar su estado a 0.
 * La funcion bitClr recibe un uint8_t (char) para indicar qué tipo de puerto 
 * tiene que acceder (A, B o D).
 * Luego recibe el bit que quiere apagar, este va de 0 a 7 si es puerto A o B y 
 * de 0 a 15 si es puerto D.
 ******************************************************************************/ 
void bitClr(uint8_t port, uint16_t bit)
{
    if (port=='A' || port=='B' || port=='C')
    {
        int mask = 1;                                                           //le doy el valor 1 a mask, b00000001
        switch(port)
        {
            case'A':
                if(bit>=CERO && bit<=BIT_8)                                     //verifico que el bit vaya de 0 a 7
                {
                    mask = mask<<bit;                                           //hago un shifteo bit veces el mask, quiere decir que si bit=4, mask vale b00010000
                    mask = ~mask;                                               //niego el valor de mask, y queda b11101111
                    p.pAB.portA = p.pAB.portA & mask;                           //hago un AND bit a bit con el puerto A para a apagar el bit que quiero 
                }
                else
                {
                    printf("ingresaste mal el bit del puerto A\n");
                }
                break;
            case'B':
                if(bit>=CERO && bit<=BIT_8)                                     //verifico que el bit vaya de 0 a 7
                {
                    mask = mask<<bit;                                           //hago un shifteo bit veces el mask, quiere decir que si bit=4, mask vale b00010000
                    mask = ~mask;                                               //niego el valor de mask, y queda b11101111
                    p.pAB.portB = p.pAB.portB & mask;                           //hago un AND bit a bit con el puerto B para a apagar el bit que quiero 
                }
                else
                {
                    printf("ingresaste mal el bit del puerto B\n");
                }
                break;
            case'D':
                if(bit>=CERO && bit<=BIT_16)                                           //verifico que el bit vaya de 0 a 15
                {
                    mask = mask<<bit;                                                  //hago un shifteo bit veces el mask, quiere decir que si bit=4, mask vale b0000.0000.0001.0000
                    mask = ~mask;                                               //niego el valor de mask, y queda b1111.1111.1110.1111
                    p.portD = p.portD & mask;                                   //hago un AND bit a bit con el puerto D para a apagar el bit que quiero 
                }
                else
                {
                    printf("ingresaste mal el bit del puerto D\n");
                }
                break;
            default:
                printf("entraste al default de bitClr\n");
                break;
        }           
    }
    else
    {
        printf("ingresaste mal los puertos en bitClr\n");
    }
}

/*******************************************************************************
 * • bitGet: Dado un puerto y un número de bit, debe devolver su valor.
 * La funcion bitGet recibe uint8_t (char) para indicar qué tipo de puerto tiene
 * que acceder (A, B o D).
 * Luego recibe el bit que quiere devolver. Este va de 0 a 7 para los puertos A
 * y B y de 0 a 15 para el puerto D.
 * El valor que devuelve es 1 o 0, dependiendo si el bit que quiere ver esta 
 * prendido o no
 ******************************************************************************/
int bitGet(uint8_t port, uint16_t bit)
{
    int result;
    if (port=='A' || port=='B' || port=='D')
    {
        switch(port)
        {
            case'A':
                if (bit>=CERO && bit<=BIT_8)                                    //verifico que el bit vaya de 0 a 7
                {
                    p.pAB.portA = p.pAB.portA>>bit;                             //hago un shifteo bit veces a la derecha, quiere decir si bit=3 y portA=b00001000
                    if(((p.pAB.portA)&2) == 0)                                    //luego del shifteo portA=b00000001. luego verifico si es multiplo de 2 o no
                    {                                                           //de serlo, quiere decir que el bit que queria esta apagado de lo contrario esta prendido
                        result = 0;
                    }
                    else
                    {
                        result = 1;
                    }
                }
                else
                {
                    printf("ingresaste mal el bit en el puerto A\n");
                }
                break;
            case'B':
                if (bit>=CERO && bit<=BIT_8)                                    //verifico que el bit vaya de 0 a 7
                {
                    p.pAB.portB = p.pAB.portB>>bit;                             //hago un shifteo bit veces a la derecha, quiere decir si bit=3 y portB=b00001000
                    if(((p.pAB.portB)&2) == 0)                                    //luego del shifteo portA=b00000001. luego verifico si es multiplo de 2 o no
                    {                                                           //de serlo, quiere decir que el bit que queria esta apagado de lo contrario esta prendido
                        result = 0;
                    }
                    else
                    {
                        result = 1;
                    }
                }
                else
                {
                    printf("ingresaste mal el bit en el puerto B\n");
                }
                break;
            case'D':
                if (bit>=CERO && bit<=BIT_16)                                   //verifico que el bit vaya de 0 a 15
                {
                    p.portD = p.portD>>bit;                                     //hago un shifteo bit veces a la derecha, quiere decir si bit=3 y portD=b0000.0000.0000.1000
                    if(((p.portD)&2) == 0)                                        //luego del shifteo portA=b0000.0000.0000.0001. luego verifico si es multiplo de 2 o no
                    {                                                           //de serlo, quiere decir que el bit que queria esta apagado de lo contrario esta prendido
                        result = 0;
                    }
                    else
                    {
                        result = 1;
                    }
                }
                else
                {
                    printf("ingresaste mal el bit en el puerto D\n");
                }
                break;
            default:
                printf("entraste en default de bitGet");
                break;
        }
    }
    else
    {
        printf("ingresaste mal el puerto en bitget\n");
    }
    return result;
}

/*******************************************************************************
 * • bitToggle: Dado un puerto y un número de bit, debe cambiar al estado 
 * opuesto en el que está (si está en 0 pasar a 1, y si está en 1 pasar a 0).
 * La funcion bitToogle recibe uint8_t (char) para indicar que tipo de puerto 
 * tiene que acceder (A, B o D).
 * Luego recibe el bit que necesita negar. Este va de 0 a 7 para los puertos A y
 * B y de 0 a 15 para el puerto D.
 * La funcion realiza un XOR bit a bit para negar el bit que indica el argumento
 ******************************************************************************/
void bitToogle(uint8_t port, uint16_t bit)
{
    if(port=='A' || port=='B' || port=='D')
    {
        switch(port)
        {
            case'A':
                if (bit>=CERO && bit<=BIT_8)                                           //verifico que el bit vaya de 0 a 7
                {
                    p.pAB.portA = p.pAB.portA ^ bit;                            //hago un xor bit a bit del valor de "bit" con el puerto A
                }                                                               //si portA=b10101111 y bit=2=00000010 da como resultado 
                else                                                            //b10101101
                {
                    printf("mal ingreso de bit en puerto A\n");
                }
                break;
            case'B':
                if (bit>=CERO && bit<=BIT_8)                                           //verifico que el bit vaya de 0 a 7
                {
                    p.pAB.portB = p.pAB.portB ^ bit;                            //hago un xor bit a bit del valor de "bit" con el puerto B
                }                                                               //si portD=b10101111 y bit=2=00000010 da como resultado 
                else                                                            //b10101101
                {
                    printf("mal ingreso de bit en puerto B\n");
                }
                break;
            case'D':
                if (bit>=CERO && bit<=BIT_16)                                          //verifico que el bit vaya de 0 a 7
                {
                    p.portD = p.portD ^ bit;                                    //hago un xor bit a bit del valor de "bit" con el puerto D
                }                                                               //si portD=b0000.0000.1010.1111 y bit=2=00000010 da como resultado 
                else                                                            //b0000.0000.1010.1101
                {
                    printf("mal ingreso de bit en puerto D\n");
                }
                break;
            default:
                printf("entraste a default de bitToogle\n");
                break;
        }
    }
    else
    {
        printf("ingreso mal los puertos en bitToogle\n");
    }
}

/*******************************************************************************
 * • maskOn: Dado un puerto y una máscara, debe prender todos aquellos bits que
estén prendidos en la máscara, sin cambiar el estado de los restantes. Por
ejemplo, dado el puerto A, que originalmente se encuentra en el estado 0x01,
al aplicarle la máscara 0x0A, el resultado será 0xB.
 * La funcion maskOn recibe uint8_t (char) para indicar que tipo de puerto tiene
 * que acceder (A, B o D)
 * Luego recibe una mascara, el cual se lo compara con el puerto seleccionado y 
 * los bits que estan apagados en el puerto pero prendidos en la mascara, esos 
 * los enciende. Para ello se hace un OR entre puerto y mask
 ******************************************************************************/
void maskOn(uint8_t port, uint16_t mask)
{
    if(port=='A' || port=='B' || port=='D')
    {
        switch(port)
        {
            case'A':
                if(mask<MAX_8BIT && mask>=CERO)                                 //verifico que la mascara sea de 8 bits
                {
                    p.pAB.portA = p.pAB.portA | mask;                           //hago un OR bit a bit con el puerto A. si portA=10010011 y mask=b11011011 
                }                                                               //deberia prenderse el bit 6 y 3. luego del OR queda b11011011
                else
                {
                    printf("mal ingreso de mask en puerto A\n");
                }
                break;
            case'B':
                if(mask<MAX_8BIT && mask>=CERO)                                 //verifico que la mascara sea de 8 bits
                {
                    p.pAB.portB = p.pAB.portB | mask;                           //hago un OR bit a bit con el puerto B. si portB=10010011 y mask=b11011011 
                }                                                               //deberia prenderse el bit 6 y 3. luego del OR queda b11011011
                else
                {
                    printf("mal ingreso de mask en puerto B\n");
                }
                break;
            case'D':
                if(mask<MAX_16BIT && mask>=CERO)                                //verifico que la mascara sea de 16 bits
                {
                    p.portD = p.portD | mask;                                   //hago un OR bit a bit con el puerto D. si portD=0000.0000.1001.0011 y mask=b0000.0000.1101.1011 
                }                                                               //deberia prenderse el bit 6 y 3. luego del OR queda b0000.0000.1101.1011
                else
                {
                    printf("mal ingreso de mask en puerto D\n");
                }
                break;
            default:
                printf("entraste en default maskOn\n");
                break;
        }
    }
    else
    {
        printf("ingresaste mal el puerto en maskOn\n");
    }
}

/*******************************************************************************
 * • maskOff: Dado un puerto y una máscara, debe apagar todos aquellos bits que
estén prendidos en la máscara, sin cambiar el estado de los restantes. Por
ejemplo, dado el puerto A, que originalmente se encuentra en el estado 0x0A,
al aplicarle la máscara 0x02, el resultado será 0x08.
 * La funcion maskToogle recibe uint8_t (char) para indicar que tipo de puerto 
 * tiene que acceder (A, B o D)
 * Luego recibe una mascara, esta es negada y luego se le hace un and bit a bit
 * con el puerto
 ******************************************************************************/
void maskOff(uint8_t port, uint16_t mask)
{
    if(port=='A' || port=='B' || port=='D')
    {
        switch(port)
        {
            case'A':
                if(mask<MAX_8BIT && mask>=CERO)                                 //verifico que la mascara sera de 8 bits
                {
                    p.pAB.portA = p.pAB.portA & (~mask);                        //niego primero la mascara y luego le hago el AND bit a bit con el puerto
                }                                                               //si port=b11110000 y mask=b10100000, entonces deberia apagar los bits 7 y 5
                else                                                            //~mask=01011111 y la hago el & con port y queda b01010000
                {
                    printf("mal ingreso de mask en puerto A\n");
                }
                break;
            case'B':
                if(mask<MAX_8BIT && mask>=CERO)                                 //verifico que la mascara sera de 8 bits
                {
                    p.pAB.portB = p.pAB.portB & (~mask);                        //niego primero la mascara y luego le hago el AND bit a bit con el puerto
                }                                                               //si port=b11110000 y mask=b10100000, entonces deberia apagar los bits 7 y 5
                else                                                            //~mask=01011111 y la hago el & con port y queda b01010000
                {
                    printf("mal ingreso de mask en puerto B\n");
                }
                break;
            case'D':
                if(mask<MAX_16BIT && mask>=CERO)                                //verifico que la mascara sera de 8 bits
                {
                    p.portD = p.portD & (~mask);                                //niego primero la mascara y luego le hago el AND bit a bit con el puerto
                }                                                               //si port=b11110000 y mask=b10100000, entonces deberia apagar los bits 7 y 5
                else                                                            //~mask=01011111 y la hago el & con port y queda b01010000
                {
                    printf("mal ingreso de mask en puerto D\n");
                }
                break;
            default:
                printf("entraste en default de maskOff\n");
                break;
        }
    }
    else
    {
        printf("mal ingreso de puerto en maskOff\n");
    }
}

/*******************************************************************************
 * • maskToggle: Dado un puerto y una máscara, debe cambiar el estado de todos
aquellos bits que estén prendidos en la máscara al opuesto, sin cambiar el
estado de los restantes. Por ejemplo, dado el puerto A, que originalmente se
encuentra en el estado 0x02, al aplicarle la máscara 0x03, el resultado será
0x01.
 * La funcion maskToogle recibe uint8_t (char) para indicar que tipo de puerto 
 * tiene que acceder (A, B o D)
 * Luego recibe la mascara donde se hace un XOR bit a bit con el puerto y en 
 * base a los bits que estan prendidos en la mask, apaga o prende esos mismo en 
 * el puerto
 ******************************************************************************/
void maskToogle(uint8_t port, uint16_t mask)
{
    if(port=='A' || port=='B' || port=='D')
    {
        switch(port)
        {
            case'A':
                if(mask<MAX_8BIT && mask>=CERO)                                 //verifico que la mascara sea de 8 bits
                {
                    p.pAB.portA = p.pAB.portA ^ mask;                           //hago un XOR bit a bit con la mascara. si tengo que port=b00001010 y mask=b00000010
                }                                                               //se deberia apagar el bit 2 de port, entonces hago un XOR entre port y mask y como resultado
                else                                                            //se obtiene b00001000
                {
                    printf("ingresaste mal mask en puerto A\n");
                }
                break;
            case'B':
                if(mask<MAX_8BIT && mask>=CERO)                                 //verifico que la mascara sea de 8 bits
                {
                    p.pAB.portB = p.pAB.portB ^ mask;                           //hago un XOR bit a bit con la mascara. si tengo que port=b00001010 y mask=b00000010
                }                                                               //se deberia apagar el bit 2 de port, entonces hago un XOR entre port y mask y como resultado
                else                                                            //se obtiene b00001000
                {
                    printf("ingresaste mal mask en puerto B\n");
                }
                break;
            case'D':
                if(mask<MAX_16BIT && mask>=CERO)                                //verifico que la mascara sea de 16 bits
                {
                    p.portD = p.portD ^ mask;                                   //hago un XOR bit a bit con la mascara. si tengo que port=b0000000000001010 y mask=b0000000000000010
                }                                                               //se deberia apagar el bit 2 de port, entonces hago un XOR entre port y mask y como resultado
                else                                                            //se obtiene b0000.0000.0000.01000
                {
                    printf("ingresaste mal mask en puerto D\n");
                }
                break;
            default:
                printf("entraste en default de maskOff\n");
                break;
        }
    }
    else
    {
        printf("ingresaste mal el puerto en maskOff\n");
    }
}