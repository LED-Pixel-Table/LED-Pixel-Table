/* Librería */
#include <Adafruit_NeoPixel.h>

/* Vabiables y constantes iniciales del juego y del tablero */
#define FIELD_WIDTH   10
#define FIELD_HEIGHT  10
const int NUMPIXELS = FIELD_WIDTH * FIELD_HEIGHT;
const int PIN = 6;
int tx = 1;
int rx = 0;
char junk;
String inputString="";

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int curLength;//Longitud de la serpiente
int xs[100];//Matriz que contiene todos los segmentos de la serpiente, su máxima longitud es el tamaño de la matriz
int ys[100];//xs es su posición en x, ys es su posición en y
int dir;//Dirección actual de la serpiente
#define SNAKEWIDTH  1 //Ancho de la serpiente
int ax = 0;//Posición en x de la manzana
int ay = 0;//Posición en y de la manzana
int pos = 0;//Posicion real en numeros de pixeles

boolean snakeGameOver;

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
#define  BTN_START 5 
#define  BTN_EXIT  6

/* Leer direcciones */
uint8_t curControl = BTN_NONE;

void readInput(){ 
   if(Serial.available()){
     while(Serial.available()){
       char inChar = (char)Serial.read();
       inputString+=inChar;
     }
     Serial.println(inputString);
     while(Serial.available()>0){
       junk=Serial.read();
     }
     if(inputString == "u"){
       curControl = BTN_UP;
     }
     else if(inputString == "d"){
       curControl = BTN_DOWN;
     }
     else if(inputString == "l"){
       curControl = BTN_LEFT;
     }
     else if(inputString == "r"){
       curControl = BTN_RIGHT;
     }
     inputString="";
   }
} 


/* Pintado de pixeles */
int r = 0;
int g = 0;
int b = 0;
void setTablePixel(int x, int y, int r, int g, int b){ 
   if(y%2==0){
    pos = y * FIELD_WIDTH + x;
    } else {
     pos = y * FIELD_WIDTH + ((FIELD_WIDTH - 1)- x);      
    }
    pixels.setPixelColor(pos, pixels.Color(r,g,b));
   }

void clearTablePixels(){
  for (int i=0; i<NUMPIXELS; i++){
    pixels.setPixelColor(i,pixels.Color(0,0,0));
  }
}
       
/* Funciones del juego */
void setup(){
  Serial.begin(9600);
  pinMode(tx, OUTPUT);
  pinMode(rx, INPUT);
  pixels.begin();
  pixels.show();
  runSnake();
}

void loop(){}

/* Detección de colisiones */
boolean collide(int x1, int x2, int y1, int y2, int w1, int w2, int h1, int h2){
  if ((x1+w1>x2) && (x1<x2+w2) && (y1+h1>y2) && (y1<y2+h2)){
    return true;
  } 
  else {
    return false;
  }
}

/* Morir */
void die(){
  snakeGameOver = true;
}

/* Direcciones */
void setDirection(){
  switch(curControl){
    case BTN_LEFT:
    if(dir==DIR_RIGHT){
      break;
    } else{
      dir = DIR_LEFT;
      break;
    }
    case BTN_RIGHT:
    if(dir==DIR_LEFT){
      break;
    } else{
      dir = DIR_RIGHT;
      break;   
    }
    case BTN_DOWN:
    if(dir==DIR_UP){
      break;
    }else{
      dir = DIR_DOWN;
      break;
    }
    case BTN_UP:
    if(dir==DIR_DOWN){
      break;
    }else{
      dir = DIR_UP;
      break;
    }
    case BTN_START:
      break;
  }
}


void snakeInit(){
  //Posición, dirección y variables iniciales de la serpiente
  curLength = 3;
  xs[0]=3; xs[1]=2; xs[2]=1;
  ys[0]=FIELD_HEIGHT/2; ys[1]=FIELD_HEIGHT/2; ys[2]=FIELD_HEIGHT/2;
  dir = DIR_RIGHT;
  //Crear manzana en una posición aleatoria
  ax = random(FIELD_WIDTH);
  ay = random(FIELD_HEIGHT);
  
  snakeGameOver = false;
}

void runSnake(){
  snakeInit();
  unsigned long prevUpdateTime = 0;
  boolean snakeRunning = true;
  while(snakeRunning){    
    //Revisar colisión de la serpiente consigo misma
    int i=curLength-1;
    while (i>=4){
      if (collide(xs[0], xs[i], ys[0], ys[i], SNAKEWIDTH, SNAKEWIDTH, SNAKEWIDTH, SNAKEWIDTH)){
        die();
      }
      i = i-1;
    }
    
    if (snakeGameOver){
      snakeRunning = false;
      clearTablePixels();
      break;
    }

    //Revisar colisión de la serpiente con la manzana
    if (collide(xs[0], ax, ys[0], ay, SNAKEWIDTH, SNAKEWIDTH, SNAKEWIDTH, SNAKEWIDTH)){
      //Incrementar longitud de la serpiente
      curLength = curLength +1;
      //Nuevo segmento de la serpiente con posición temporal
      xs[curLength-1] = 255;
      ys[curLength-1] = 255;
      
      //Crear otra manzana en una posición aleatoria
      ax = random(FIELD_WIDTH);
      ay = random(FIELD_HEIGHT);

      //Asegurarse de que la manzana no se genere dentro del cuerpo de la serpiente
      int i=curLength-1;
      for(int i=0; i<curLength; i++) {
        if (collide(ax, xs[i], ay, ys[i], SNAKEWIDTH, SNAKEWIDTH, SNAKEWIDTH, SNAKEWIDTH)){
           ax = random(FIELD_WIDTH);
           ay = random(FIELD_HEIGHT);
           i=0;
        }
      }
    }
    
    //Desfasar los segmentos del cuerpo de la serpiente
    i = curLength-1;
    while (i>=1){
      xs[i] = xs[i-1];
      ys[i] = ys[i-1];
      i = i-1;
    }
    //Determinar nueva direción de la cabeza de la serpiente
    if (dir == DIR_RIGHT){           //Derecha
      xs[0] = xs[0] + SNAKEWIDTH;
    } 
    else if (dir == DIR_LEFT){       //Izquierda
      xs[0] = xs[0] - SNAKEWIDTH;
    } 
    else if (dir == DIR_UP){         //Arriba
      ys[0] = ys[0] - SNAKEWIDTH;
    } 
    else {                           //Abajo
      ys[0] = ys[0] + SNAKEWIDTH;
    }
    
    //Revisar si la serpiente sale de los bordes del tablero
    if ((xs[0]<0) || (xs[0]>=FIELD_WIDTH) || (ys[0]<0) || (ys[0]>=FIELD_HEIGHT)){
      if (xs[0]<0) {xs[0] =FIELD_WIDTH -1;}
      else if (xs[0]>=FIELD_WIDTH) {xs[0] = 0;}      
      else if (ys[0]<0) {ys[0] =FIELD_HEIGHT -1;}
      else if (ys[0]>=FIELD_HEIGHT) {ys[0] = 0;}    
    }
    
    clearTablePixels();
   
    //Dibujar la manzana
    setTablePixel (ax, ay, 15, 0, 0);

    //Dibujar la serpiente
    for (int i=0; i<curLength; i++){
      setTablePixel(xs[i], ys[i], 0, 15, 0);
    }
    
    pixels.show();

    //Revisar dirección de la serpiente mientras se espera otra dirección
    unsigned long curTime;
    do{
      readInput();
      if (curControl == BTN_EXIT){
        snakeRunning = false;
        break;
      }
      if (curControl != BTN_NONE){//Solo se puede cambiar de dirección una vez
        setDirection();
      }
      curTime = millis();
      }
      while((curTime - prevUpdateTime) < 250);//Luego de 250ms la serpiente se mueve
      prevUpdateTime = curTime;
    }
  }
