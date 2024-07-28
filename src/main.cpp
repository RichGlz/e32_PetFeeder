// #include <Arduino.h>



// // Variables
// const int8_t btn1 = 2;
// int_fast32_t millisActual = 0;

// // Declaración de Funciones
// void interr_btn1();

// // Configuración
// void setup() {
//   pinMode(btn1, INPUT_PULLUP);

//   /* Interrupción btn1 */
//   attachInterrupt(digitalPinToInterrupt(btn1), interr_btn1, RISING);
//   Serial.begin(115200);

//   millis();

// }

// void loop() {
//   // put your main code here, to run repeatedly:
// }

// // put function definitions here:
// void interr_btn1() {
// }

#include <Arduino.h>
// Bibliotecas de I2C
#include <SPI.h>
#include <Wire.h>

// Biblioteca del display
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Bibliotecas personalizadas
#include "ManejoDeLeds.h"

// Biblioteca del sensor BMP280
// #include <Adafruit_BMP280.h>

// Variables de configuración del Display
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

// Variables de configuración del sensor BMP280
// Adafruit_BMP280 bmp; // use I2C interface
// Adafruit_Sensor *bmp_temp = bmp.getTemperatureSensor();
// Adafruit_Sensor *bmp_pressure = bmp.getPressureSensor();


const uint8_t ledDeLaBoard = 2;

void setup() {
  Serial.begin(115200);

  Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Limpia el buffer.
  display.clearDisplay();

  // Se agrega al buffer líneas horizontales en color blanco.
  display.drawLine(0, 0,128, 0, WHITE); // Línea horizontal, con Y =  0
  display.drawLine(0,15,128,15, WHITE); // Línea horizontal, con Y = 15
  display.drawLine(0,16,128,16, WHITE); // Línea horizontal, con Y = 16
  display.drawLine(0,63,128,63, WHITE); // Línea horizontal, con Y = 63

  // Se agrega al buffer las letras "Geeksium".
  display.setTextColor(WHITE);          // Se configura el color comoblanco
  display.setTextSize(1);               // Tamaño del texto (del 1 al 6).
  display.setCursor(42, 4);             // Se pone el cursor en la posición x=42, y=4.
  display.println("Geeksium");          // Se imprime la cadena "Geeksium".

  // Muestra el buffer de la pantalla. Tienes que invocar la función "display()"
  // después para hacer los elementos visibles en la pantalla.
  display.display();
  delay(2000);
  // display.display() NO es necesario que se ponga en en cada línea
  // a menos que sea lo que quieras, de otra manera haz al configuración
  // y ejecuta la función "display.display()" al final.

    int valor1 = 1;
    int valor2 = 2;

    declaraLed(ledDeLaBoard);
    enciendeLed(ledDeLaBoard);
    delay(2000);
    apagaLed(ledDeLaBoard);

}

void loop() {

  // Serial.println(suma(2,4));
  // Serial.println(multi(6,3));
}
