#ifndef PWM0_H_  // Directiva del preprocesador para evitar la inclusión múltiple
#define PWM0_H_

#include <avr/io.h>   // Incluye la librería avr/io.h para acceder a los registros de E/S de AVR
#include <stdint.h>   // Incluye la librería stdint.h para definir tipos de datos enteros con ancho específico

// Definiciones de constantes para facilitar la configuración del PWM
#define invertido 1      // Constante para indicar que la salida PWM está invertida
#define no_invertido 0   // Constante para indicar que la salida PWM no está invertida

// Declaración de las funciones públicas del módulo PWM0
void initPWM0FastA(uint8_t inverted, uint16_t precaler);
void updateDCA(uint8_t duty);


#endif  // Fin de la directiva del preprocesador
