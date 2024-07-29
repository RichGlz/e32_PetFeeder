#include <Arduino.h>

// Bibliotecas de I2C
#include <SPI.h>
#include <Wire.h>

// Biblioteca del display
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Bibliotecas personalizadas
#include <Configuraciones.h>
#include <Tiempos.h>

// Biblioteca del sensor BMP280
// #include <Adafruit_BMP280.h>

// Variables de configuración del sensor BMP280
// Adafruit_BMP280 bmp; // use I2C interface
// Adafruit_Sensor *bmp_temp = bmp.getTemperatureSensor();
// Adafruit_Sensor *bmp_pressure = bmp.getPressureSensor();

// Variables de configuración del Display
#define SCREEN_WIDTH    128     // OLED display width, in pixels
#define SCREEN_HEIGHT   64      // OLED display height, in pixels
#define OLED_RESET      -1      // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS  0x3C    //< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

const uint8_t ledDeLaBoard = 2;

void setup() {

  s_serial();
  s_interrupciones();

  Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

}

void loop() {
  

}
