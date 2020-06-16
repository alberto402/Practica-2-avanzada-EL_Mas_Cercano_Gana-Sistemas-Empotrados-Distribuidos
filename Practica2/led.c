/*--- ficheros de cabecera ---*/
#include "44b.h"
#include "44blib.h"
/*--- variables globales ---*/
int led_state; // estado del LED
/*--- declaracion de funciones ---*/
void leds_on(); // todos los LEDs encendidos
void leds_off(); // todos los LEDs apagados
void led1_on(); // LED 1 encendido
void led1_off(); // LED 1 apagado
void led2_on(); // LED 2 encendido
void led2_off(); // LED 2 apagado
void leds_switch(); // invierte el valor de los LEDs
void Led_Display(int LedStatus); // control directo del LED
/*--- codigo de las funciones ---*/
void leds_on()
{
	Led_Display(0x3);
}
void leds_off()
{
	Led_Display(0x0);
}
void led1_on()
{
	led_state = led_state | 0x1;
	Led_Display(led_state);
}
void led1_off()
{
	led_state = led_state & 0xfe;
	Led_Display(led_state);
}
void led2_on()
{
	led_state = led_state | 0x2;
	Led_Display(led_state);
}
void led2_off()
{
	led_state = led_state & 0xfd;
	Led_Display(led_state);
}
void leds_switch ()
{
	led_state ^= 0x03;
	Led_Display(led_state);
}
void Led_Display(int LedStatus)
{
	led_state = LedStatus;
	if ((LedStatus&0x01) == 0x01)	
		rPDATB=rPDATB & ~(0x01<<9)
	;// poner a 0 el bit 9 del registro de datos del puerto B
	else
		rPDATB=rPDATB |(0x01<<9)
	;// poner a 1 el bit 9 del registro de datos del puerto B
	if ((LedStatus&0x02) == 0x02)
		rPDATB=rPDATB & ~(0x01<<10)
	;// poner a 0 el bit 10 del registro de datos del puerto B
	else
		rPDATB=rPDATB |(0x01<<10)
	;// poner a 1 el bit 10 del registro de datos del puerto B
}