/*--- ficheros de cabecera ---*/
#include "44blib.h"
#include "44b.h"
#include "stdio.h"
#include <stdlib.h>
#include <math.h>


/*--- funciones externas ---*/
int jugador1=-1,jugador2=-1;
int turno=-1;
int key=-1;
int acabado=0;
int num;
extern void leds_off();
extern void led1_on();
extern void led2_on();
extern void leds_on();
extern void timer_init();
extern void keyboard_init();
extern void D8Led_symbol(int);
extern void D8Led_init();
extern void Eint4567_init();
extern void timer_init4();

/*--- declaracion de funciones ---*/
void Main(void);
/*--- codigo de funciones ---*/
void Main(void)
{
	/* Inicializar controladores */
	acabado=0;
	sys_init(); // Inicializacion de la placa, interrupciones y puertos
	timer_init(); // Inicializacion del temporizador
    Eint4567_init();
	/* Establecer valor inicial de los LEDs */
	keyboard_init();
	leds_off();
	led1_on();
	num= rand () % 16;
	D8Led_init();
	D8Led_symbol(0);
	while (1){


		if( turno==1&&key!=-1){

			jugador1=key;
			key=-1;

		}
		else if(turno==2&&key!=-1){

			jugador2=key;
			key=-1;

		}

		if(acabado==1){
			leds_off();
			//iniciamos un timer
			timer_init4();
			//delay xs seg
			DelayMs(1500);
			//desactivamos timer
			rINTMSK = rINTMSK | BIT_TIMER4;
			leds_off();
			DelayMs(750);
			//ganador
			if(fabs(jugador1-num)<fabs(jugador2-num)){
				led1_on();
			}
			else if(fabs(jugador1-num)>fabs(jugador2-num)){
				led2_on();
			}
			else{
				leds_on();
			}
			D8Led_symbol(0);
			Delay(100);
			//mostrar numero elegido
			D8Led_symbol(num);
			//inizializar tambores timer
			while(acabado==1){
				if(key==0){
					acabado=0;
					key=-1;
				}
			}
			leds_off();
			led1_on();
			acabado=0;
			turno=-1;
			jugador1=-1;
			jugador2=-1;
			timer_init();
			num= rand () % 16;


			//pulsar 0 para reiniciar
		}

	}
}
