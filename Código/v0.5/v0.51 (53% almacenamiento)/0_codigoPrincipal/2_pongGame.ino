/* Vabiables y constantes iniciales del juego */
#define MAX_SCORE 5
#define DIR_DOWNRIGHT 6
#define DIR_UPRIGHT 7
#define DIR_DOWNLEFT 8
#define DIR_UPLEFT 9

int posPlayerIzq;
int posPlayerDer;
int scoreIzq;
int scoreDer;
int ballx;
int bally;
int BALL_DIR;


void ballDirection() {
  switch (BALL_DIR) {
    case DIR_LEFT:
      --ballx;
      break;
    case DIR_RIGHT:
      ++ballx;
      break;
    case DIR_DOWNRIGHT:
      ++bally;
      ++ballx;
      break;
    case DIR_UPRIGHT:
      --bally;
      ++ballx;
      break;
    case DIR_DOWNLEFT:
      ++bally;
      --ballx;
      break;
    case DIR_UPLEFT:
      --bally;
      --ballx;
      break;
  }
}

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
  ballx = 4;
  bally = FIELD_HEIGHT / 2;
  BALL_DIR = DIR_RIGHT;
  curControl = BTN_NONE;
}

void runPong() {
  pongInit();

  unsigned long prevUpdateTime = 0;
  boolean pongRunning = true;
  while (pongRunning) {

    if (scoreIzq == MAX_SCORE || scoreDer == MAX_SCORE) {
      clearTablePixels();
      pixels.show();
      pongRunning = false;
      snakeGameOverAnim(pongRunning);
      break;
    }


    for (int i = posPlayerIzq - 1; i <= posPlayerIzq + 1; i++) {
      if (collide(ballx, 1, bally, i)) {
        if (i == posPlayerIzq) {
          BALL_DIR = DIR_RIGHT;
        }
        else if (i == posPlayerIzq + 1) {
          if (BALL_DIR == DIR_LEFT || BALL_DIR == DIR_DOWNLEFT) {
            BALL_DIR = DIR_DOWNRIGHT;
          }
          else if (BALL_DIR == DIR_UPLEFT) {
            BALL_DIR = DIR_UPRIGHT;
          }
        }
        else if (i == posPlayerIzq - 1) {
          if (BALL_DIR == DIR_LEFT || BALL_DIR == DIR_UPLEFT) {
            BALL_DIR = DIR_UPRIGHT;
          }
          else if (BALL_DIR == DIR_DOWNLEFT) {
            BALL_DIR = DIR_DOWNRIGHT;
          }
        }
      }
    }


    for (int i = posPlayerDer - 1; i <= posPlayerDer + 1; i++) {
      if (collide(ballx, 8, bally, i)) {
        if (i == posPlayerDer) {
          BALL_DIR = DIR_LEFT;
        }
        else if (i == posPlayerDer + 1) {
          if (BALL_DIR == DIR_RIGHT || BALL_DIR == DIR_DOWNRIGHT) {
            BALL_DIR = DIR_DOWNLEFT;
          }
          else if (BALL_DIR == DIR_UPRIGHT) {
            BALL_DIR = DIR_UPLEFT;
          }
        }
        else if (i == posPlayerDer - 1) {
          if (BALL_DIR == DIR_RIGHT || BALL_DIR == DIR_UPRIGHT) {
            BALL_DIR = DIR_UPLEFT;
          }
          else if (BALL_DIR == DIR_DOWNRIGHT) {
            BALL_DIR = DIR_DOWNLEFT;
          }
        }
      }
    }

    for (int i = 0; i < FIELD_WIDTH; i++) {
      if (collide(ballx, i, bally, 9 )) {
        if (BALL_DIR == DIR_DOWNRIGHT) {
          BALL_DIR = DIR_UPRIGHT;
        }
        else if (BALL_DIR == DIR_DOWNLEFT) {
          BALL_DIR = DIR_UPLEFT;
        }
      }
      else if (collide(ballx, i, bally, 0)) {
        if (BALL_DIR == DIR_UPRIGHT) {
          BALL_DIR = DIR_DOWNRIGHT;
        }
        else if (BALL_DIR == DIR_UPLEFT) {
          BALL_DIR = DIR_DOWNLEFT;
        }
      }
    }

    if (ballx == 0) {
      ++scoreDer;
      ballx = 5;
      bally = FIELD_HEIGHT / 2;
      BALL_DIR = DIR_LEFT;
    }
    else if (ballx == 9) {
      ++scoreIzq;
      ballx = 4;
      bally = FIELD_HEIGHT / 2;
      BALL_DIR = DIR_RIGHT;
    }

    ballDirection();

    if (posPlayerDer != 8 && posPlayerDer != 1 && ballx > 4) {
      if (bally == posPlayerDer) {
        posPlayerDer = bally;
      }

      else if (bally > posPlayerDer) {
        ++posPlayerDer;
      }

      else if (bally < posPlayerDer) {
        --posPlayerDer;
      }
    } else {
      if (bally == 7 && posPlayerDer == 8) {
        --posPlayerDer;
      }
      else if (bally == 2 && posPlayerDer == 1) {
        ++posPlayerDer;
      }
    }


    clearTablePixels();

    //Dibujar la pelota
    setTablePixel(ballx, bally, 0, 15, 0);

    //Dibujar el jugador de la izquierda
    for (int i = posPlayerIzq - 1; i <= posPlayerIzq + 1; i++) {
      setTablePixel(0, i, 0, 0, 15);
    }

    //Dibujar el jugador de la derecha
    for (int  i = posPlayerDer - 1; i <= posPlayerDer + 1; i++) {
      setTablePixel((FIELD_WIDTH - 1), i, 15, 0, 0);
    }

    pixels.show();

    unsigned long curTime;
    boolean dirChanged = false;
    do {
      readInput();
      if (curControl == BTN_EXIT) {
        pongRunning = false;
        break;
      }
      if (curControl != BTN_NONE && !dirChanged) { //Solo se puede cambiar de dirección una vez
        dirChanged = true;
        setPosition();
      }
      curTime = millis();
    }
    while ((curTime - prevUpdateTime) < 250); //Luego de 250ms la serpiente se mueve
    prevUpdateTime = curTime;
    curControl = BTN_NONE;
  }
}
