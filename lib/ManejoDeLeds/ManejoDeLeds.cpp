#include <ManejoDeLeds.h>

// Declaración de LED
void declaraLed( const uint8_t pin ) {
    pinMode(pin, OUTPUT);
} 

// EnciendeLED
void enciendeLed( const uint8_t pin ) {
    digitalWrite(pin, HIGH);
} 

// ApagaLED
void apagaLed( const uint8_t pin ) {
    digitalWrite(pin, LOW);
}
