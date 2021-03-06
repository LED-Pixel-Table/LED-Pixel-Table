/* Librería */
#include <Adafruit_NeoPixel.h>

/* Vabiables y constantes del tablero */
#define FIELD_WIDTH   10
#define FIELD_HEIGHT  10
const int NUMPIXELS = FIELD_WIDTH * FIELD_HEIGHT;
const int PIN = 6;
int tx = 1;
int rx = 0;
String inputString = "";

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

/* Controles del juego */
#define  DIR_UP    1
#define  DIR_DOWN  2
#define  DIR_LEFT  3
#define  DIR_RIGHT 4

/* Botones del bluetooth */
#define  BTN_NONE  0
#define  BTN_UP    1
#define  BTN_DOWN  2
#define  BTN_LEFT  3
#define  BTN_RIGHT 4
#define  BTN_EXIT  5
#define  BTN_START 6

/* Leer direcciones */
uint8_t curControl = BTN_NONE;

void readInput() {
  if (Serial.available()) {
    while (Serial.available()) {
      char inChar = Serial.read();
      inputString += inChar;
    }
    if (inputString == "u") {
      curControl = BTN_UP;
    }
    else if (inputString == "d") {
      curControl = BTN_DOWN;
    }
    else if (inputString == "l") {
      curControl = BTN_LEFT;
    }
    else if (inputString == "r") {
      curControl = BTN_RIGHT;
    }
    else if (inputString == "e") {
      curControl = BTN_EXIT;
    }
    else if (inputString == "s") {
      curControl = BTN_START;
    }
    inputString = "";
  }
}


/* Pintado de pixeles */
int pos = 0;//Posicion real en numeros de pixeles

void setTablePixel(int x, int y, int r, int g, int b) {
  if (y % 2 == 0) {
    pos = y * FIELD_WIDTH + x;
  } else {
    pos = y * FIELD_WIDTH + ((FIELD_WIDTH - 1) - x);
  }
  pixels.setPixelColor(pos, pixels.Color(r, g, b));
}

void clearTablePixels() {
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
  }
}

/* Funciones iniciales */
void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
  pinMode(tx, OUTPUT);
  pinMode(rx, INPUT);
  pixels.begin();
  pixels.show();
  runSnake();
}

void loop() {}
