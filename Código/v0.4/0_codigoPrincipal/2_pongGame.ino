/* Vabiables y constantes iniciales del juego */
int posPlayerIzq;
int posPlayerDer;

void setPosition() {
  switch (curControl) {
    case BTN_LEFT:
      break;
    case BTN_RIGHT:
      break;
    case BTN_DOWN:
      if (posPlayerIzq == (FIELD_HEIGHT - 2))
        break;
      else {
        ++posPlayerIzq;
        break;
      }
    case BTN_UP:
      if (posPlayerIzq == 1)
        break;
      else {
        --posPlayerIzq;
        break;
      }
  }
}



void pongInit() {
  posPlayerIzq = FIELD_HEIGHT / 2;
  posPlayerDer = FIELD_HEIGHT / 2;
}

void runPong() {
  pongInit();

  unsigned long prevUpdateTime = 0;
  boolean pongRunning = true;
  while (pongRunning) {


    //Dibujar el jugador de la izquierda
    for (int i = posPlayerIzq - 1; i <= posPlayerIzq + 1; i++) {
      setTablePixel(0, i, 0, 0, 15);
    }

    //Dibujar el jugador de la derecha
    for (int  i = posPlayerDer - 1; i <= posPlayerDer + 1; i++) {
      setTablePixel((FIELD_WIDTH - 1), i, 15, 0, 0);
    }

    unsigned long curTime;
    do {
      readInput();
      if (curControl == BTN_EXIT) {
        pongRunning = false;
        break;
      }
      if (curControl != BTN_NONE) { //Can only change direction once per loop
        setPosition();
      }
      curTime = millis();
    }
    while ((curTime - prevUpdateTime) < 250); //Once enough time  has passed, proceed. The lower this number, the faster the game is
    prevUpdateTime = curTime;
  }
}
