//*****************************************************************************
//Universidad del Valle de Guatemala
//Programaci�n de Microcontroladores
//Archivo:Prelab_05
//Hardware:ATMEGA328P
//Autor:Esteban Longo
//Carnet:22649
//*****************************************************************************
#define F_CPU 16000000  // Define la frecuencia del CPU a 16 MHz

// Incluye las definiciones de los registros de entrada/salida
#include <avr/io.h>
#include <util/delay.h> // Incluye la librer�a para las funciones de retraso
#include <avr/interrupt.h>
#include "PWM0/PWM0.h"  // Incluye la librer�a PWM0.h
#include "PWM2/PWM2.h"  // Incluye la librer�a PWM2.h

void setup(void);  // Declaraci�n de la funci�n setup

unsigned char ADCpot = 0;  // Variable para almacenar el valor del potenci�metro del ADC
uint8_t dutyCycle1 = 0;    // Variable para almacenar el ciclo de trabajo del PWM 1
uint8_t dutyCycle2 = 0;    // Variable para almacenar el ciclo de trabajo del PWM 2

// Funci�n para inicializar el ADC
void initADC(void){
	ADMUX = 0;  // Limpia el registro ADMUX
	
	// Configuraci�n de referencia de voltaje (AVCC con referencia externa en pin AREF)
	ADMUX |= (1<<REFS0);  // Bit REFS0 en 1
	ADMUX &= ~(1<<REFS1); // Bit REFS1 en 0
	
	ADMUX |= (1<<ADLAR);  // Ajuste de resultado a la izquierda
	
	ADCSRA = 0;  // Limpia el registro ADCSRA
	
	ADCSRA |= (1<<ADEN); // Habilita el ADC
	
	// Configuraci�n del prescaler a 128 (Frecuencia del reloj de ADC a 125 kHz)
	ADCSRA |= (ADPS2)|(ADPS1)|(ADPS0);  // Bits ADPS2, ADPS1 y ADPS0 en 1
	
	DIDR0 |= (1<<ADC5D); // Deshabilita la funci�n digital del pin ADC5
}

// Funci�n para leer el valor del ADC
uint16_t valorADC (uint8_t canal) {
	ADMUX &= 0xF0;  // Limpia los bits del canal
	ADMUX |= canal; // Selecciona el canal
	
	ADCSRA |= (1 << ADSC);  // Inicia la conversi�n
	
	while (ADCSRA & (1 << ADSC));  // Espera a que la conversi�n termine
	
	return ADCH; // Devuelve el valor del ADC
}
void timer0_init() {
	// Set timer0 interrupt at 1 Hz
	TCCR0A = (1 << WGM01); // CTC mode
	TCCR0B = (1 << CS01) | (1 << CS00); // Set prescaler to 64
	OCR0A = 156; // Compare match register 16MHz/64/1Hz
	TIMSK0 |= (1 << OCIE0A); // Enable timer0 compare interrupt
}

// Funci�n principal
int main(void) {
	// Inicializaci�n de los PWM y del ADC
	initPWM0FastA(0,1024);  // Inicializa PWM0 en modo r�pido para el pin A
	initPWM0FastB(0,1024);  // Inicializa PWM0 en modo r�pido para el pin B
	setup();  // Llama a la funci�n setup
	initADC();  // Inicializa el ADC
	
	void timer0_init() {
		// Set timer0 interrupt at 1 Hz
		TCCR0A = (1 << WGM01); // CTC mode
		TCCR0B = (1 << CS01) | (1 << CS00); // Set prescaler to 64
		OCR0A = 156; // Compare match register 16MHz/64/1Hz
		TIMSK0 |= (1 << OCIE0A); // Enable timer0 compare interrupt
	}
	// Variables para almacenar los valores del ADC
	uint16_t dutyCycle1 = valorADC(6);
	uint16_t dutyCycle2 = valorADC(7);
	
	// Loop infinito
	while (1) {
		// Lectura del valor del ADC para el PWM 1
		dutyCycle1 = valorADC(6);
		_delay_ms(10);  // Retardo de 10 ms
		
		// Actualizaci�n del ciclo de trabajo del PWM 1
		updateDCA(dutyCycle1);
		
		// Lectura del valor del ADC para el PWM 2
		dutyCycle2 = valorADC(7);
		_delay_ms(10);  // Retardo de 10 ms
		
		// Actualizaci�n del ciclo de trabajo del PWM 2
		updateDCB(dutyCycle2);
		
		_delay_ms(25);  // Retardo de 25 ms
	}
	
	return 0; // Retorno est�ndar de finalizaci�n
}

// Funci�n setup (vac�a)
void setup(void){
	// Esta funci�n puede ser utilizada para cualquier configuraci�n inicial adicional necesaria
}
ISR(TIMER0_COMPA_vect) {
	// Interrupcion timer 0
}