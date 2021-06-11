#include "funciones.h"
#include "teclado.h"
#include "user.h"
#include "hardware.h"

//el teclado es solamente para el puerto A
void teclado (void)
{
    //cambiar puerto por PUERTO 
    char c, mask;
    int n, i;

    while ((c = getchar())!='q')
    {
        mask=1;
        //fprintf(stderr,"clean");
        if (c>='0' && c<='7')
        {
            //mask = 1;
            n = c-GAP;
            mask<<=n;
            //if(bigGet(A,n))   //MODIFICAR
            if(p.pAB.portA & mask)
            {
                pSwitch(&bitClr, PUERTO, n);
                led_value(n, OFF);
            }
            else
            {
                pSwitch(&bitSet, PUERTO, n);
                led_value(n, ON);
            }
            //printBits(PUERTO); 
        }
        else if (c == 't')
        {   //mask=1;
            pSwitch(&maskToogle, PUERTO, 0xFF);
            //printBits(PUERTO);
            for (i=0; i<8; i++)
            {   
                if (p.pAB.portA & mask)     //1010 mask=0001 ==>0000
                {                           //1010 mask=0010 ==>0010
                    led_value(i, OFF);
                }
                else
                {
                    led_value(i, ON);
                }
                
                mask<<=1;
            }
            
        }
        else if (c == 's')
        {
            pSwitch(&maskOn, PUERTO, ALL_LED);
            //printBits(PUERTO);
            all_led_on();
        }
        else if (c == 'c')
        {
            pSwitch(&maskOff, PUERTO, ALL_LED);
            //printBits(PUERTO);
            all_led_off();
        }
        else
        {
            printf("entraste en DEFAULT TECLADO\n");
        }
        cleanBuffer();
    }
    all_led_off();
    led_unexport();
    printf("fin del programa\n");
}

void cleanBuffer(void)
{
    char c;
    while((c=getchar())!='\n'){}
}

//void en los argumentos y luego los casteo en p2func(uint8_t puerto, uint16_t n)
void pSwitch(void (*p2func)(uint8_t, uint16_t), uint8_t puerto, uint16_t n)
{
    p2func(puerto, n);
}

/*
case '0':
                n = c-GAP;
                pSwitch(&bitSet, puerto, n);
                printBits(puerto);
                cleanBuffer();
                break;
            case '1':
                n = c-GAP;
                pSwitch(&bitSet, puerto, n);
                printBits(puerto);
                cleanBuffer();
                break;
            case '2':
                n = c-GAP;
                pSwitch(&bitSet, puerto, n);
                printBits(puerto);
                cleanBuffer();
                break;
            case '3':
                n = c-GAP;
                pSwitch(&bitSet, puerto, n);
                printBits(puerto);
                cleanBuffer();
                break;
            case '4':
                n = c-GAP;
                pSwitch(&bitSet, puerto, n);
                printBits(puerto);
                cleanBuffer();
                break;
            case '5':
                n = c-GAP;
                pSwitch(&bitSet, puerto, n);
                printBits(puerto);
                cleanBuffer();
                break;
            case '6':
                n = c-GAP;
                pSwitch(&bitSet, puerto, n);
                printBits(puerto);
                cleanBuffer();
                break;
            case '7':
                n = c-GAP;
                pSwitch(&bitSet, puerto, n);
                printBits(puerto);
                cleanBuffer();
                break;

            se INVIERTEN todos los LEDs
            case 't':
                pSwitch(&maskToogle, puerto, n);
                printBits(puerto);
                cleanBuffer();
                break;
            se PRENDEN todos los LEDs
            case 's':
                printf("imprimo %c\n", c);
                pSwitch(&maskOn, puerto, ALL_LED);
                printBits(puerto);
                cleanBuffer();
                break;
            se APAGAN todos los LEDs
            case 'c':
                printf("imprimo %c\n", c);
                pSwitch(&maskOff, puerto, ALL_LED);
                printBits(puerto);
                cleanBuffer();
                break;
*/