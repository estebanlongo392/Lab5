#ifndef PWM0_H_  // Directiva del preprocesador para evitar la inclusi�n m�ltiple
#define PWM0_H_

#include <avr/io.h>   // Incluye la librer�a avr/io.h para acceder a los registros de E/S de AVR
#include <stdint.h>   // Incluye la librer�a stdint.h para definir tipos de datos enteros con ancho espec�fico

// Definiciones de constantes para facilitar la configuraci�n del PWM
#define invertido 1      // Constante para indicar que la salida PWM est� invertida
#define no_invertido 0   // Constante para indicar que la salida PWM no est� invertida

// Declaraci�n de las funciones p�blicas del m�dulo PWM0
void initPWM0FastA(uint8_t inverted, uint16_t precaler);
void updateDCA(uint8_t duty);


#endif  // Fin de la directiva del preprocesador
