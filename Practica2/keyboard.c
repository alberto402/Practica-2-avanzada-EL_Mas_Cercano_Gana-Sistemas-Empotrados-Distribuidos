/*--- Ficheros de cabecera ---*/
#include "44b.h"
#include "44blib.h"
#include "def.h"
/*--- Definición de macros ---*/
#define KEY_VALUE_MASK 0xF
/*--- Variables globales ---*/
volatile UCHAR *keyboard_base = (UCHAR *)0x06000000;
extern int key;
extern int acabado;
/*--- Funciones externas ---*/
void D8Led_symbol(int value);
/*--- Declaracion de funciones ---*/
void keyboard_init();
void KeyboardInt(void) __attribute__ ((interrupt ("IRQ")));
/*--- Codigo de las funciones ---*/
void keyboard_init()
{
	/* Configurar el puerto G (si no lo estuviese ya) */	

	// Establece la funcion de los pines (EINT0-7)
	rPCONG = 0xffff;
	// Habilita el "pull up" del puerto
	rPUPG = 0;

	// Configura las lineas de int. como de flanco de bajada mediante EXTINT
	rEXTINT = 0x33333333;
	/* Establece la rutina de servicio para EINT1 */
	pISR_EINT1 = (unsigned) KeyboardInt;
	/* Configurar controlador de interrupciones */
	// Borra INTPND escribiendo 1s en I_ISPC
	rI_ISPC = 0xfffffff;
	// Configura las lineas como de tipo IRQ mediante INTMOD
	rINTMOD = 0x0000000;
	// Habilita int. vectorizadas y la linea IRQ (FIQ no) mediante INTCON
	rINTCON = 0x1;

	/* Habilitar linea EINT1 */
	rINTMSK = rINTMSK & ~BIT_GLOBAL& ~(BIT_EINT1);
	/* Por precaucion, se vuelven a borrar los bits de INTPND correspondientes*/
	//
	rEXTINTPND = 0xf;
	rI_ISPC = 0xfffffff;
}
 KeyboardInt(void)
{
	/* Esperar trp mediante la funcion DelayMs()*/
	DelayMs(20);
	/* Identificar la tecla */
	key = key_read();
	/* Si la tecla se ha identificado, visualizarla en el 8SEG*/
	if(key > -1)
	{
		if(acabado==0)
			D8Led_symbol(key);
	}
	/* Esperar a se libere la tecla: consultar bit 1 del registro de datos del puerto G */
	while ((rPDATG & 0x00000002) == 0){
		//NOTHING
	}
	/* Esperar trd mediante la funcion Delay() */
	DelayMs(100);
	/* Borrar interrupción de teclado */
	rI_ISPC = BIT_EINT1;
}
int key_read()
{
	int value= -1;
	char temp;
	UCHAR values[] = {0xfd, 0xfb, 0xf7, 0xef};
	// Identificar la tecla mediante ''scanning''
	// Si la identificación falla la función debe devolver -1

	//Usamos KEY_VALUE_MASK para quedarnos con los 4 bits menos significativos
	int i=0;
	for(i; i<4;i++){
		temp = *(keyboard_base + values[i]) & KEY_VALUE_MASK;
		switch (temp) {
		case 0x7:  value = 12-i*4; break;
		case 0xB:  value = 13-i*4; break;
		case 0xD:  value = 14-i*4; break;
		case 0xE:  value = 15-i*4; break;
		}
	}


	return value;

}
