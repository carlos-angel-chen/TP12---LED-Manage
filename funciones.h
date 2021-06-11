/***************************************************************************//**
  @file     registro.h
  @brief    
  @author   carlos
 ******************************************************************************/

#ifndef _REGISTRO_H_
#define _REGISTRO_H_

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdint.h>
#include <stdio.h>

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
#define CERO 0
#define BIT_8 7
#define BIT_16 15
#define MAX_8BIT 256
#define MAX_16BIT 65536   
#define GAP 48

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

/* A y B son dos puertos de 8 bits, configurables tanto de entrada como de 
 * salida. D tiene 16 y es simplemente un alias para los puertos A y B 
 * juntos, siendo el B el menos significativo.*/
    
typedef struct
{
    uint8_t portB;
    uint8_t portA;
}portAB_t;

typedef union
{
    portAB_t pAB;
    uint16_t portD; 
}port_t;


/*******************************************************************************
 * VARIABLE PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

port_t p;

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

void bitSet(uint8_t port, uint16_t bit);

void bitClr(uint8_t port, uint16_t bit);

int bitGet(uint8_t port, uint16_t bit);

void bitToogle(uint8_t port, uint16_t bit);

void maskOn(uint8_t port, uint16_t mask);

void maskOff(uint8_t port, uint16_t mask);

void maskToogle(uint8_t port, uint16_t mask);


/*******************************************************************************
 ******************************************************************************/

#endif // _REGISTRO_H_
