#include <Configuraciones.h>
#include "Tiempos.h"

// INTERRUPCIONES
int8_t interr2 = 3;
int8_t interr3 = 4;
int8_t interr4 = 5;

// Biblioteca del sensor BMP280
#include <Adafruit_BMP280.h>

// ---------------------------SETUP-----------------------------
void s_serial(){
    Serial.begin(115200);
}

void s_interrupciones(){
    pinMode(interr2, INPUT_PULLUP);
    pinMode(interr3, INPUT_PULLUP);
    pinMode(interr4, INPUT_PULLUP);


    /* Interrupción btn1 */
    attachInterrupt(digitalPinToInterrupt(interr2), interr_2, RISING);
    attachInterrupt(digitalPinToInterrupt(interr3), interr_3, RISING);
    attachInterrupt(digitalPinToInterrupt(interr4), interr_4, RISING);
}



// ---------------------------LOOP------------------------------

// -------------------------FUNCIONES----------------------------

void interr_2() {  }
void interr_3() {  }
void interr_4() {  }
