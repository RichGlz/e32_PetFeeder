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
#include <Adafruit_BMP280.h>

// Biblioteca SSD1306 Global


#define _displayAncho 128   // ANCHO del display OLED en pixeles
#define _displayAlto 64     // ALTO del display OLED en pixeles
#define OLED_RESET -1       // # Pin de Reset (o -1 si se comparte el pin de reset del Arduino)
#define SCREEN_ADDRESS 0x3C // mira el datasheet Para la dirección; puede ser 0x3C o 0x3D.

Adafruit_SSD1306 display(_displayAncho, _displayAlto, &Wire, OLED_RESET);

// Variables de configuración del sensor BMP280
Adafruit_BMP280 bmp; // use I2C interface
Adafruit_Sensor *bmp_temp = bmp.getTemperatureSensor();
Adafruit_Sensor *bmp_pressure = bmp.getPressureSensor();

uint8_t _ancho = 128-1;
uint8_t _alto = 64-1;

int8_t interr1 = 15;
const uint8_t ledDeLaBoard = 2;

void interr_1() {
    Serial.println("\n");
    Serial.println("Presionado");
    digitalWrite(ledDeLaBoard, HIGH);
    delay_2seg;
    digitalWrite(ledDeLaBoard, LOW);
}

void marcoPantalla();


void setup() {

  s_serial();


  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  
  //INTERRUPCIONES
  pinMode(interr1, INPUT_PULLDOWN);
  pinMode(ledDeLaBoard, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(interr1), interr_1, RISING);

  // SENSOR BMP240
  if (!bmp.begin()) {
    Serial.println(F("No se encuentra un sensor BMP280 válido, revise la conexion "
    "Intente una dirección diferente"));
    while (1) delay(10);
  }

  /* Default settings from datasheet. */
  bmp.setSampling(Adafruit_BMP280::MODE_FORCED,     /* Operating Mode. */
  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */

  display.clearDisplay();
  marcoPantalla();
  
}

void loop() {
  
  display.clearDisplay();
  display.setTextSize(1);               // Tamaño del texto (del 1 al 6).
  display.setTextColor(WHITE);
  display.setCursor(0, 17);             // Se pone el cursor en la posición x=42, y=4.

  // must call this to wake sensor up and get new measurement data
  // it blocks until measurement is complete
  if (bmp.takeForcedMeasurement()) {
    // can now print out the new measurements
    Serial.print(("Temp: "));
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");

      display.print("T:");
      display.print(bmp.readTemperature());
      display.println(" *C");

    Serial.print(("Presion: "));
    Serial.print(bmp.readPressure());
    Serial.println(" Pa");

      display.print(("Presion: "));
      display.print(bmp.readPressure());
      display.println(" Pa");


    Serial.print(("altitud (aprox): "));
    Serial.print(bmp.readAltitude(1013.25)); /* Adjusted to local forecast! */
    Serial.println(" m");

      display.print(("Alt: "));
      display.print(bmp.readAltitude(1013.25)); /* Adjusted to local forecast! */
      display.println(" m");

    Serial.println();



    delay(2000);
  } else {
    Serial.println("Tomas de medidas forzadas fallaron!");
  }
  
  marcoPantalla();
  display.display();
}

void marcoPantalla(){

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
}
