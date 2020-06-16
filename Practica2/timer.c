/*--- ficheros de cabecera ---*/
#include "44b.h"
#include "44blib.h"
/*--- funciones externas ---*/
extern void leds_switch();
extern void D8Led_symbol(int value);
/*--- declaracion de funciones ---*/
void timer0_ISR(void) __attribute__ ((interrupt ("IRQ")));
void timer2_ISR(void) __attribute__ ((interrupt ("IRQ")));
void timer4_ISR(void) __attribute__ ((interrupt ("IRQ")));
void timer_init(void);
/*--- codigo de las funciones ---*/
int numero;
void timer_init(void)
{
	numero=0;
	/* Configuracion del controlador de interrupciones */	
	rINTMOD=0x0;// Configurar las lineas como de tipo IRQ	
	rINTCON=0x1;// Habilitar int. vectorizadas y la linea IRQ (FIQ no)	
	rINTMSK = rINTMSK & ~(BIT_TIMER0 |BIT_TIMER2| BIT_GLOBAL);// Enmascarar todas las lineas excepto Timer0 y el bit global
	/* Establece la rutina de servicio para TIMER0 */
	pISR_TIMER0=(unsigned)timer0_ISR;
	pISR_TIMER2=(unsigned)timer2_ISR;
	/* Configurar el Timer0 y Timer2(el resto de los timers se dejan a la
	configuración por defecto) */
	rTCFG0|=0x5FFF;// pre-escalado = 255
	rTCFG1 &= 0xFFFF20;// divisor = 1/2 timer  0  y 1/8 timer2
	rTCNTB0=65535;
	rTCMPB0=12800;
	rTCNTB2=65535;
	rTCMPB2=12800;
	
	rTCON=rTCON|(0x01<<1);// establecer manual_update timer0
	rTCON=rTCON|(0x01<<13);// establecer manual_update timer2
	rTCON=rTCON & ~(0x01<<1);// DESACTIVA manual_update
	rTCON=rTCON & ~(0x01<<13);// DESACTIVA manual_update
	rTCON=rTCON|(0x01<<3);//activar modo auto-reload tmer 0
	rTCON=rTCON|(0x01<<15);//activar modo auto-reload timer 2
	rTCON=rTCON|(0x01<<0);// iniciar timer0
	rTCON=rTCON|(0x01<<12);// iniciar timer2
}
void timer_init4(void)
{
	/* Configuracion del controlador de interrupciones */
	rINTMOD=0x0;// Configurar las lineas como de tipo IRQ
	rINTCON=0x1;// Habilitar int. vectorizadas y la linea IRQ (FIQ no)
	rINTMSK = rINTMSK & ~(BIT_TIMER4| BIT_GLOBAL);// Enmascarar todas las lineas excepto Timer0 y el bit global
	/* Establece la rutina de servicio para TIMER0 */
	pISR_TIMER4=(unsigned)timer4_ISR;
	/* Configurar el Timer0 y Timer2(el resto de los timers se dejan a la
	configuración por defecto) */
	rTCFG0|=0x5F5FFF;// pre-escalado = 255
	rTCFG1 &= 0xFFFFF0;// divisor = 1/2 timer  0  y 1/8 timer2
	rTCNTB4=65535;
	rTCMPB4=12800;

	rTCON=rTCON|(0x01<<21);// establecer manual_update timer4
	rTCON=rTCON & ~(0x01<<21);// DESACTIVA manual_update
	rTCON=rTCON|(0x01<<23);//activar modo auto-reload tmer 4
	rTCON=rTCON|(0x01<<20);// iniciar timer0

}

void timer0_ISR(void){
	leds_switch();
	rI_ISPC |= BIT_TIMER0;
}

void timer2_ISR(void){
	D8Led_symbol(numero);
	numero=(numero+1)%16;
	rI_ISPC |= BIT_TIMER2;
}
void timer4_ISR(void){
	leds_switch();
		rI_ISPC |= BIT_TIMER4;
}
