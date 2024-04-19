#ifndef PWMm_H_  // Directiva del preprocesador para evitar la inclusi�n m�ltiple
#define PWMm_H_

#include <avr/io.h>   // Incluye la librer�a avr/io.h para acceder a los registros de E/S de AVR
#include <stdint.h>   // Incluye la librer�a stdint.h para definir tipos de datos enteros con ancho espec�fico

// Definiciones de constantes para facilitar la configuraci�n del PWM
#define invertido 1      // Constante para indicar que la salida PWM est� invertida
#define no_invertido 0   // Constante para indicar que la salida PWM no est� invertida

// Declaraci�n de las funciones p�blicas del m�dulo PWMm
void SelecMode(uint8_t mode, uint16_t inverted);

#endif  // Fin de la directiva del preprocesador