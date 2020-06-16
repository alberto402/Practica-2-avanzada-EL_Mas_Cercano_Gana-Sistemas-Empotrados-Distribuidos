/*--- ficheros de cabecera ---*/
#include "44b.h"
#include "44blib.h"
/*--- definicion de macros ---*/
/* Mapa de bits de cada segmento
(valor que se debe escribir para que se ilumine el segmento) */
#define SEGMENT_A 0x7F
#define SEGMENT_B 0xBF
#define SEGMENT_C 0xDF 
#define SEGMENT_D 0xF7 
#define SEGMENT_E 0xFB 
#define SEGMENT_F 0xFD 
#define SEGMENT_G 0xFE 
#define SEGMENT_P 0xEF 

#define DIGIT_F (SEGMENT_A & SEGMENT_G & SEGMENT_E & SEGMENT_F)
#define DIGIT_E (SEGMENT_A & SEGMENT_G & SEGMENT_E & SEGMENT_F & SEGMENT_D)
#define DIGIT_D (SEGMENT_B & SEGMENT_C & SEGMENT_D & SEGMENT_F & SEGMENT_E)
#define DIGIT_C (SEGMENT_A & SEGMENT_D & SEGMENT_E & SEGMENT_G)
#define DIGIT_B (SEGMENT_C & SEGMENT_D & SEGMENT_F & SEGMENT_E & SEGMENT_G)
#define DIGIT_A (SEGMENT_A & SEGMENT_B & SEGMENT_C & SEGMENT_F & SEGMENT_E & SEGMENT_G)
#define DIGIT_9 (SEGMENT_A & SEGMENT_B & SEGMENT_C & SEGMENT_F & SEGMENT_G)
#define DIGIT_0 (SEGMENT_A & SEGMENT_B & SEGMENT_C & SEGMENT_D & SEGMENT_E & SEGMENT_G)
#define DIGIT_1 (SEGMENT_B & SEGMENT_C)
#define DIGIT_2 (SEGMENT_A & SEGMENT_B & SEGMENT_F & SEGMENT_E & SEGMENT_D)
#define DIGIT_3 (SEGMENT_A & SEGMENT_B & SEGMENT_F & SEGMENT_C & SEGMENT_D)
#define DIGIT_4 (SEGMENT_B & SEGMENT_C & SEGMENT_F & SEGMENT_G)
#define DIGIT_5 (SEGMENT_A & SEGMENT_C & SEGMENT_D & SEGMENT_F & SEGMENT_G)
#define DIGIT_6 (SEGMENT_A & SEGMENT_C & SEGMENT_D & SEGMENT_E & SEGMENT_F & SEGMENT_G)
#define DIGIT_7 (SEGMENT_A & SEGMENT_B & SEGMENT_C)
#define DIGIT_8 (SEGMENT_A & SEGMENT_B & SEGMENT_C & SEGMENT_D & SEGMENT_E & SEGMENT_F & SEGMENT_G)
#define BARRA (SEGMENT_F )

/*--- variables globales ---*/
/* tabla de segmentos */
int Symbol[] = {DIGIT_0, DIGIT_1, DIGIT_2, DIGIT_3, DIGIT_4, DIGIT_5,
					DIGIT_6, DIGIT_7, DIGIT_8, DIGIT_9, DIGIT_A, DIGIT_B,
					DIGIT_C, DIGIT_D, DIGIT_E, DIGIT_F,BARRA};
/*--- declaracion de funciones ---*/
void D8Led_init(void);
void D8Led_symbol(int value);
/*--- codigo de las funciones ---*/
void D8Led_init(void)
{
/* Estado inicial del display con todos los segmentos iluminados
(buscar en los ficheros de cabecera la direccion implicada--->44blib.h) */ 
	LED8ADDR = 0; 
}
void D8Led_symbol(int value)
{
// muestra Symbol[value] en el display
	LED8ADDR=Symbol[value];
}
