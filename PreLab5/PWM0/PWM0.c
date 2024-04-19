#include "PWM0.h"  // Incluye la librería PWM0.h

// Función para inicializar el PWM en el pin A del Timer/Counter 0 en modo rápido
void initPWM0FastA(uint8_t inverted, uint16_t precaler){
	DDRD |= (1<<DDD6);  // Configura el pin D6 como salida
	
	TCCR0A = 0;  // Limpia el registro TCCR0A
	
	// Configuración de la salida PWM en el pin A del Timer/Counter 0
	if (inverted) {
		TCCR0A |= (1<<COM0A1)|(1<<COM0A0);  // Salida PWM invertida
		} else {
		TCCR0A |= (1<<COM0A1);  // Salida PWM no invertida
	}
	
	// Modo de operación del Timer/Counter 0 (Fast PWM con TOP en 0xFF)
	TCCR0A |= (1<<WGM01)|(1<<WGM00);
	
	// Configuración del preescalador del Timer/Counter 0
	if (precaler == 1024) {
		TCCR0B |= (1<<CS02)|(1<<CS00);  // Preescalador de 1024
	}
}

// Función para actualizar el ciclo de trabajo del PWM en el pin A del Timer/Counter 0
void updateDCA(uint8_t duty){
	OCR0A = duty;  // Establece el ciclo de trabajo del PWM en el pin A
}


