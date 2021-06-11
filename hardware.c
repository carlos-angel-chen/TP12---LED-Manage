#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hardware.h"

const char *num_led[] = {"17", "4", "18", "23", "24", "25", "22", "27"};
const char route[] = "/sys/class/gpio/";
const char *gpio[] = {"gpio17","gpio4","gpio18","gpio23","gpio24","gpio25","gpio22","gpio27",};

void led_init(void)
{
	led_unexport();
	delay(200);			//para evitar glitches
	led_export();
	delay(200);
	led_direction();
	delay(200);
	led_active_low();
	delay(200);
	all_led_on();
	delay(2000);
	all_led_off();
	
}

/*
exporto todos los leds
*/
void led_export(void)
{
	FILE *handle_export;
	int n_written, i;
	char str[50];
	char export[] = "/export";
	strcpy(str,route);
	strcat(str,export);
	
	for (i=0; i<8; i++)
	{
		//printf("%s\n", str);
		if((handle_export = fopen(str, "w")) == NULL)
		{
			printf("no se pudo abrir EXPORT file\n");
			exit(1);
		}
		n_written = fputs(num_led[i], handle_export);
		if(n_written == -1)
		{
			printf("no se pudo EXPORT pin\n");
			exit(1);
		}
		else
		{
			printf("EXPORT pin succes\n");
		}
		fclose(handle_export);
	}
}

void led_unexport(void)
{
	FILE *handle_unexport;
	int n_written, i;
	char str[50];
	char unexport[] = "/unexport";
	strcpy(str,route);
	strcat(str,unexport);
	
	for (i=0; i<8; i++)
	{
		//printf("%s\n", str);
		if((handle_unexport = fopen(str, "w")) == NULL)
		{
			printf("no se pudo abrir UNEXPORT file\n");
			exit(1);
		}
		n_written = fputs(num_led[i], handle_unexport);
		if(n_written == -1)
		{
			printf("no se pudo UNEXPORT pin\n");
			exit(1);
		}
		else
		{
			printf("UNEXPORT pin succes\n");
		}
		fclose(handle_unexport);
	}
}

/*desactivo el activo bajo de todos los leds*/
void led_active_low(void)
{
	FILE *handle_active_low;
	int n_written, i;
	char str[50];
	char active_low[] = "/active_low";
	
	for (i=0; i<8; i++)
	{
		strcpy(str, route);
		strcat(str, gpio[i]);
		strcat(str, active_low);
		if((handle_active_low = fopen(str,"w"))==NULL)
		{
			printf("no se pudo abrir ACTIVE_LOW\n");
		}
		n_written = fputs(OFF, handle_active_low);
		if(n_written == -1)
		{
			printf("no se pudo ACTIVE_LOW\n");
		}
		else
		{
			printf("ACTIVE_LOW succes\n");
		}
		fclose(handle_active_low);
	}
}

/*pongo en OUT a todos los leds*/
void led_direction(void)
{
	FILE *handle_direction;
	int n_written, i;
	char str[50];
	char direction[] = "/direction";
	
	for (i=0; i<8; i++)
	{
		strcpy(str, route);
		strcat(str, gpio[i]);
		strcat(str, direction);
		if((handle_direction = fopen(str, "w"))==NULL)
		{
			printf("no se pudo abrir DIRECTION\n");
		}
		n_written = fputs("out", handle_direction);
		if(n_written==-1)
		{
			printf("no se pudo DIRECTION\n");
		}
		else
		{
			printf("DIRECTION succes\n");
		}
	fclose(handle_direction);
	}
}

/*activo o desactivo el led que quiero*/
void led_value(int n, char *onoff)
{
	FILE * handle_value;
	int n_written;
	char value[] = "/value";
	char str[50];

	strcpy(str,route);
	strcat(str, gpio[n]);
	strcat(str, value);

	if ((handle_value = fopen(str, "w"))==NULL)
	{
		printf("no se pudo abrir LED_VALUE\n");
		exit(1);
	}
	n_written = fputs(onoff, handle_value);
	if(n_written == -1)
	{
		printf("no se pudo escribir LED_VALUE\n");
		exit(1);
	}
	fclose(handle_value);
}

void all_led_on(void)
{
	FILE *handle_value;
	int i;
	char value[] = "/value";
	char str[50];

	for (i=0; i<8; i++)
	{
		strcpy(str,route);
		strcat(str, gpio[i]);
		strcat(str, value);
		handle_value = fopen(str, "w");
		fputs(ON, handle_value);
		fclose(handle_value);
	}
}

void all_led_off(void)
{
	FILE *handle_value;
	int i;
	char value[] = "/value";
	char str[50];

	for (i=0; i<8; i++)
	{
		strcpy(str,route);
		strcat(str, gpio[i]);
		strcat(str, value);
		handle_value = fopen(str, "w");
		fputs(OFF, handle_value);
		fclose(handle_value);
	}
}

void delay(int numSec)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * numSec;
  
    // Storing start time
    clock_t start_time = clock();
  
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}

/*
void all_led(void)
{
	FILE *handle_value;
	int i;
	char value[] = "/value";
	char str[50];

	for (i=0; i<8; i++)
	{
		strcpy(str,route);
		strcat(str, gpio[i]);
		strcat(str, value);
		handle_value = fopen(str, "w");
		fputs(ON, handle_value);
		fclose(handle_value);
	}
	delay(2000);
	for (i=0; i<8; i++)
	{
		strcpy(str,route);
		strcat(str, gpio[i]);
		strcat(str, value);
		handle_value = fopen(str, "w");
		fputs(OFF, handle_value);
		fclose(handle_value);
	}
}
*/