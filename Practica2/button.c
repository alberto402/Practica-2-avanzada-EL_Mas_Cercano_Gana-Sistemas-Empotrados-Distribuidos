/*--- ficheros de cabecera ---*/
#include "44b.h"
#include "44blib.h"
#include "def.h"
/*--- variables globales ---*/
int symbol = 0;
extern int jugador1,jugador2;
extern int turno;
extern int acabado;
extern int num;
/*--- funciones externas ---*/
//extern void D8Led_Symbol(int value);
/*--- declaracion de funciones ---*/
void Eint4567_ISR(void) __attribute__ ((interrupt ("IRQ")));
void Eint4567_init(void);
extern void leds_switch ();
extern void D8Led_symbol(int value);
//int numero;
/*--- codigo de funciones ---*/
void Eint4567_init(void)
{

	//numero=0;

	/* Configuracion del controlador de interrupciones */
	// Borra EXTINTPND escribiendo 1s en el propio registro
	rEXTINTPND = 0xf;


	// Borra INTPND escribiendo 1s en I_ISPC
	rI_ISPC = 0xfffffff;

	// Configura las lineas como de tipo IRQ mediante INTMOD
	rINTMOD = 0x0000000;

	// Habilita int. vectorizadas y la linea IRQ (FIQ no) mediante INTCON
	rINTCON = 0x1;

	// Enmascara todas las lineas excepto Eint4567 y el bit global (INTMSK)
	rINTMSK = rINTMSK &~BIT_GLOBAL & ~BIT_EINT4567;

	// Establecer la rutina de servicio para Eint4567
	pISR_EINT4567 = (unsigned) Eint4567_ISR;

	/* Configuracion del puerto G */
	// Establece la funcion de los pines (EINT7-EINT0)
	rPCONG = 0xffff;

	//Habilita las resistencias de pull-up
	rPUPG = 0;

	// Configura las lineas de int. como de flanco de bajada mediante EXTINT
	rEXTINT = 0x33333333;

	/* Por precaucion, se vuelven a borrar los bits de INTPND y EXTINTPND */
	rEXTINTPND = 0xf;

	rI_ISPC = 0xfffffff;

}


/*COMENTAR PARA LA PARTE DEL 8-SEGMENTOS
 DESCOMENTAR PARA LA PRIMERA PARTE CON INTERRUPCIONES
 */
/*
void Eint4567_ISR(void)
 {

	//mientras alguno de los dos este pulsado
	while ( (rPDATG & 0x00000040) == 0 || (rPDATG & 0x00000080) == 0) {}

	//Conmutamos LEDs
	leds_switch();
	//Delay para eliminar rebotes
	DelayMs(100);
	//Atendemos interrupciones
	//Borramos EXTINTPND ambas líneas EINT7 y EINT6
	rEXTINTPND = 0xC;
	//Borramos INTPND usando ISPC
	rI_ISPC = BIT_EINT4567;
  }
 */

//DESCOMENTAR PARA LA PARTE DEL 8-SEGMENTOS
//COMENTAR PARA LA PRIMERA PARTE CON INTERRUPCIONES

int which_int;
void Eint4567_ISR(void)
{

	if(acabado==0){

		rINTMSK = rINTMSK | BIT_TIMER0 | BIT_TIMER2;
		while ( (rPDATG & 0x00000040) == 0 || (rPDATG & 0x00000080) == 0) {}


		//Identificar la interrupcion
		which_int = rEXTINTPND;

		// Actualizar simbolo
		switch (which_int) {

		// Iz (ascendente)
		case 0x4:
			if(turno==-1 ||(turno==2&&jugador2!=-1)){
				leds_off();
				led1_on();
				D8Led_symbol(16);
				/*numero++;

		numero %= 16;*/
				turno=1;
			}

			break;

			// Dr (descendente)
		case 0x8:
			if(turno==-1||(turno==1&&jugador1!=-1)){
				leds_off();

				led2_on();
				D8Led_symbol(16);
				/*numero++;

				numero %= 16;*/
				turno=2;
			}

			break;
		}

		if(jugador1!=-1 && jugador2!=-1){
			acabado=1;
			D8Led_symbol(16);
		}
	}
	else{
		while ( (rPDATG & 0x00000040) == 0){D8Led_symbol(jugador1);	DelayMs(100);}
		while((rPDATG & 0x00000080) == 0) {D8Led_symbol(jugador2);	DelayMs(100);}
		D8Led_symbol(num);


		}
	// espera 100ms para evitar rebotes
	DelayMs(100);

	// borra los bits en EXTINTPND
	rEXTINTPND = 0xC;

	// borra el bit pendiente en INTPND
	rI_ISPC = BIT_EINT4567;
}
