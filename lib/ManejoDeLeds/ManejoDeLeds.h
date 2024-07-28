#ifndef MANEJODELEDS_H
#define MANEJODELEDS_H

#include <Arduino.h>

void declaraLed( const uint8_t pin );     // Declaración de LED
void enciendeLed( const uint8_t pin );    // Encender LED
void apagaLed( const uint8_t pin ) ;      // Apaga LED
  
#endif // MANEJODELEDS_H