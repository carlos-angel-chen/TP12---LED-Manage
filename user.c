#include "funciones.h"
#include "user.h"

uint8_t check(uint8_t port)
{
    uint8_t puerto;
    if(port=='A' || port=='B' || port=='D')
    {
        switch(port)
        {
            case'A':
                puerto = 'A';
                break;
            case'B':
                puerto = 'B';
                break;
            case'D':
                puerto = 'D';
                break;
            default:
                printf("entraste a default de check\n");
                break;
        }
    }
    else
    {
        printf("ingresaste mal los puertos\n");
    }
    return puerto;
}

void printBits(uint8_t port)
{
    uint8_t puerto;
    int16_t portA, portB, portD, i;
    puerto = check(port);
    
    switch(puerto)
    {
        case'A':
            portA = p.pAB.portA;
            for(i=BIT_8; i>=CERO; i--)
            {
                arrAB[i] = portA%2;
                portA = portA/2;
            }
            for(i=CERO; i<=BIT_8; i++)
            {
                printf("%hu", arrAB[i]);
            }
            printf("\n");
            break;
        case'B':
            portB = p.pAB.portB;
            for(i=BIT_8; i>=CERO; i--)
            {
                arrAB[i] = portB%2;
                portB = portB/2;
            }
            for(i=CERO; i<=BIT_8; i++)
            {
                printf("%hu", arrAB[i]);
            }
            printf("\n");
            break;
        case'D':
            portD = p.portD;
            for(i=BIT_16; i>=CERO; i--)
            {
                arrD[i] = portD%2;
                portD = portD/2;
            }
            for(i=CERO; i<=BIT_16; i++)
            {
                printf("%hu", arrD[i]);
            }
            printf("\n");
            break;
    }
}
