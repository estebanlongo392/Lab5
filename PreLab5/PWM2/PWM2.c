#include "PWM2.h"  // Incluye la librería PWM0.h

// Función para inicializar el PWM en el pin B del Timer/Counter 0 en modo rápido
void initPWM0FastB(uint8_t inverted, uint16_t precaler){
	DDRD |= (1<<DDD5);  // Configura el pin D5 como salida
	
	TCCR0B = 0;  // Limpia el registro TCCR0B
	
	// Configuración de la salida PWM en el pin B del Timer/Counter 0
	if (inverted) {
		TCCR0A |= (1<<COM0B1)|(1<<COM0B0);  // Salida PWM invertida
		} else {
		TCCR0A |= (1<<COM0B1);  // Salida PWM no invertida
	}
	
	// Modo de operación del Timer/Counter 0 (Fast PWM con TOP en 0xFF)
	TCCR0A |= (1<<WGM01)|(1<<WGM00);
	
	// Configuración del preescalador del Timer/Counter 0 (siempre preescalador de 1024)
	TCCR0B |= (1<<CS02)|(1<<CS00);  // Preescalador de 1024
}

// Función para actualizar el ciclo de trabajo del PWM en el pin B del Timer/Counter 0
void updateDCB(uint8_t duty){
	OCR0B = duty;  // Establece el ciclo de trabajo del PWM en el pin B
}

