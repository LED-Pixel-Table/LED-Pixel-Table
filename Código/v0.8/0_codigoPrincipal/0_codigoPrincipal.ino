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
boolean menu;
int BALL_DIR;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

/* Controles del juego */
#define  DIR_UP        1
#define  DIR_DOWN      2
#define  DIR_LEFT      3
#define  DIR_RIGHT     4
#define  DIR_DOWNRIGHT 6
#define  DIR_UPRIGHT   7
#define  DIR_DOWNLEFT  8
#define  DIR_UPLEFT    9

/* Botones del bluetooth */
#define  BTN_NONE  0
#define  BTN_UP    1
#define  BTN_DOWN  2
#define  BTN_LEFT  3
#define  BTN_RIGHT 4
#define  BTN_EXIT  5
#define  BTN_START 6
#define  BTN_SNAKE 7
#define  BTN_PONG  8
#define  BTN_BREAKOUT  9
#define  BTN_DICE  10
#define  BTN_CENTER  10

/* Leer direcciones */
uint8_t curControl = BTN_NONE;

void readInput() {
  if (Serial.available()) {
    while (Serial.available()) {
      char inChar = Serial.read();
      inputString += inChar;
    }
    Serial.println(inputString);
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
    else if (inputString == "c") {
      curControl = BTN_CENTER;
    }
    else if (inputString == "1") {
      curControl = BTN_SNAKE;
    }
    else if (inputString == "2") {
      curControl = BTN_PONG;
    }
    else if (inputString == "3") {
      curControl = BTN_BREAKOUT;
    }
    else if (inputString == "4") {
      curControl = BTN_DICE;
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

/* Detección de colisiones */
boolean collide(int x1, int x2, int y1, int y2) {
  if ((x1 == x2) && (y1 == y2)) {
    return true;
  }
  else {
    return false;
  }
}

void start () {
  clearTablePixels();
  boolean inicio = true;

  while (inicio) {
    readInput();

    if (curControl == BTN_START) {
      inicio = false;
      curControl = BTN_NONE;
      mainMenu();
      break;
    }
  }
}

void mainMenu() {
  menu = true;

  while (menu) {
    unsigned long prevUpdateTime = 0;
    unsigned long curTime;

    for (int i = 0; i < NUMPIXELS; i++) {
      int rr = random(15);
      int gg = random(15);
      int bb = random(15);
      pixels.setPixelColor(i, pixels.Color(rr, gg, bb));
      delay(10);
    }
    pixels.show();

    do {
      readInput();
      if (curControl == BTN_NONE) {
        break;
      }
      else if (curControl == BTN_SNAKE) {
        clearTablePixels();
        runSnake();
        curControl = BTN_NONE;
        menu = false;
        break;
      }
      else if (curControl == BTN_PONG) {
        clearTablePixels();
        runPong();
        curControl = BTN_NONE;
        menu = false;
        break;
      }
      else if (curControl == BTN_BREAKOUT) {
        clearTablePixels();
        runBreakout();
        curControl = BTN_NONE;
        menu = false;
        break;
      }
      else if (curControl == BTN_DICE) {
        clearTablePixels();
        runDice();
        curControl = BTN_NONE;
        menu = false;
        break;
      }
      else if (curControl == BTN_EXIT) {
        menu = false;
        curControl = BTN_NONE;
        start();
        break;
      }
      curTime = millis();
    }
    while ((curTime - prevUpdateTime) < 250);
    prevUpdateTime = curTime;
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
  start();
}

void loop() {}
