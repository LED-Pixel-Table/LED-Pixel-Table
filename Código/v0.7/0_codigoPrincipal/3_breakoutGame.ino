/* Vabiables y constantes iniciales del juego */
int posPlayer;
int ballbx;
int ballby;
int lrojos[10];
int lnaranjas[10];
int lamarillos[10];
int lverdes[10];
int lazules[10];

void ballBreakOutDirection() {
  switch (BALL_DIR) {
    case DIR_UP:
      --ballby;
      break;
    case DIR_DOWN:
      ++ballby;
      break;
    case DIR_DOWNRIGHT:
      if (ballbx == 9) {
        break;
      } else {
        ++ballby;
        ++ballbx;
        break;
      }
    case DIR_UPRIGHT:
      --ballby;
      ++ballbx;
      break;
    case DIR_DOWNLEFT:
      if (ballbx == 0) {
        break;
      } else {
        ++ballby;
        --ballbx;
        break;
      }
    case DIR_UPLEFT:
      --ballby;
      --ballbx;
      break;
  }
}

void setMovement() {
  switch (curControl) {
    case BTN_LEFT:
      if (posPlayer == 1) {
        break;
      } else {
        --posPlayer;
        break;
      }
    case BTN_RIGHT:
      if (posPlayer == (FIELD_WIDTH - 2)) {
        break;
      } else {
        ++posPlayer;
        break;
      }
    case BTN_DOWN:
      break;
    case BTN_UP:
      break;
  }
}

void breakoutInit() {
  posPlayer = FIELD_WIDTH / 2;
  ballbx = FIELD_WIDTH / 2;
  ballby = (FIELD_WIDTH / 2) + 1;
  lrojos[0] = 0; lrojos[1] = 1; lrojos[2] = 2; lrojos[3] = 3; lrojos[4] = 4; lrojos[5] = 5; lrojos[6] = 6; lrojos[7] = 7; lrojos[8] = 8; lrojos[9] = 9;
  lnaranjas[0] = 0; lnaranjas[1] = 1; lnaranjas[2] = 2; lnaranjas[3] = 3; lnaranjas[4] = 4; lnaranjas[5] = 5; lnaranjas[6] = 6; lnaranjas[7] = 7; lnaranjas[8] = 8; lnaranjas[9] = 9;
  lamarillos[0] = 0; lamarillos[1] = 1; lamarillos[2] = 2; lamarillos[3] = 3; lamarillos[4] = 4; lamarillos[5] = 5; lamarillos[6] = 6; lamarillos[7] = 7; lamarillos[8] = 8; lamarillos[9] = 9;
  lverdes[0] = 0; lverdes[1] = 1; lverdes[2] = 2; lverdes[3] = 3; lverdes[4] = 4; lverdes[5] = 5; lverdes[6] = 6; lverdes[7] = 7; lverdes[8] = 8; lverdes[9] = 9;
  lazules[0] = 0; lazules[1] = 1; lazules[2] = 2; lazules[3] = 3; lazules[4] = 4; lazules[5] = 5; lazules[6] = 6; lazules[7] = 7; lazules[8] = 8; lazules[9] = 9;
  BALL_DIR = DIR_DOWN;
}

void runBreakout() {
  breakoutInit();

  unsigned long prevUpdateTime = 0;
  boolean breakoutRunning = true;
  while (breakoutRunning) {

    //Revisar colisión del jugador con la pelota
    for (int i = posPlayer - 1; i <= posPlayer + 1; i++) {
      if (collide(ballbx, i, ballby, 8)) {
        if (i == posPlayer) {
          BALL_DIR = DIR_UP;
        }
        else if (i == posPlayer - 1 || i == posPlayer + 1) {
          if (BALL_DIR == DIR_DOWN || BALL_DIR == DIR_DOWNRIGHT) {
            BALL_DIR = DIR_UPRIGHT;
          }
          else if (BALL_DIR == DIR_DOWNLEFT) {
            BALL_DIR = DIR_UPLEFT;
          }
        }
      }
    }
    
    //Revisar colisión de la pelota con los extremos
    for (int i = 0; i < FIELD_WIDTH; i++) {
      if (collide(ballbx, 9, ballby, i )) {
        if (BALL_DIR == DIR_UPRIGHT) {
          BALL_DIR = DIR_UPLEFT;
        }
        else if (BALL_DIR == DIR_DOWNRIGHT) {
          BALL_DIR = DIR_DOWNLEFT;
        }
      }
      else if (collide(ballbx, 0, ballby, i)) {
        if (BALL_DIR == DIR_UPLEFT) {
          BALL_DIR = DIR_UPRIGHT;
        }
        else if (BALL_DIR == DIR_DOWNLEFT) {
          BALL_DIR = DIR_DOWNRIGHT;
        }
      }
    }

    //Revisar colisión de la pelota con los ladrillos dependiendo de su direccion
    for (int i = 0; i < FIELD_WIDTH; i++) {
      //Direccion arriba
      if (BALL_DIR == DIR_UP) {
        if (collide(ballbx, lazules[i] , ballby, 5)) {
          lazules[i] = 255;
          BALL_DIR = DIR_DOWN;
        }
        else if (collide(ballbx, lverdes[i] , ballby, 4)) {
          lverdes[i] = 255;
          BALL_DIR = DIR_DOWN;
        }
        else if (collide(ballbx, lamarillos[i] , ballby, 3)) {
          lamarillos[i] = 255;
          BALL_DIR = DIR_DOWN;
        }
        else if (collide(ballbx, lnaranjas[i] , ballby, 2)) {
          lnaranjas[i] = 255;
          BALL_DIR = DIR_DOWN;
        }
        else if (collide(ballbx, lrojos[i] , ballby, 1)) {
          lrojos[i] = 255;
          BALL_DIR = DIR_DOWN;
        }
      }

      //Direccion arriba-derecha
      else if (BALL_DIR == DIR_UPRIGHT) {
        //Azules
        if (collide(ballbx, lazules[i] , ballby, 5)) {
          lazules[i] = 255;
          BALL_DIR = DIR_DOWNRIGHT;
        }
        else if (collide(ballbx, lazules[i] - 1 , ballby, 4)) {
          lazules[i] = 255;
          BALL_DIR = DIR_UPLEFT;
        }
        else if (collide(ballbx, lazules[i] - 1, ballby, 5) && !collide(ballbx, lazules[i - 1] , ballby, 5)) {
          lazules[i] = 255;
          BALL_DIR = DIR_DOWNLEFT;
        }

        //Verdes
        else if (collide(ballbx, lverdes[i] , ballby, 4)) {
          lverdes[i] = 255;
          BALL_DIR = DIR_DOWNRIGHT;
        }
        else if (collide(ballbx, lverdes[i] - 1 , ballby, 3)) {
          lverdes[i] = 255;
          BALL_DIR = DIR_UPLEFT;
        }
        else if (collide(ballbx, lverdes[i] - 1, ballby, 4) && !collide(ballbx, lverdes[i - 1] , ballby, 4) &&
                 !collide(ballbx, lazules[i] - 1 , ballby, 4)) {
          lverdes[i] = 255;
          BALL_DIR = DIR_DOWNLEFT;
        }

        //Amarillos
        else if (collide(ballbx, lamarillos[i] , ballby, 3)) {
          lamarillos[i] = 255;
          BALL_DIR = DIR_DOWNRIGHT;
        }
        else if (collide(ballbx, lamarillos[i] - 1 , ballby, 2)) {
          lamarillos[i] = 255;
          BALL_DIR = DIR_UPLEFT;
        }
        else if (collide(ballbx, lamarillos[i] - 1, ballby, 3) && !collide(ballbx, lamarillos[i - 1] , ballby, 3) &&
                 !collide(ballbx, lverdes[i] - 1 , ballby, 2)) {
          lamarillos[i] = 255;
          BALL_DIR = DIR_DOWNLEFT;
        }

        //Naranjas
        else if (collide(ballbx, lnaranjas[i] , ballby, 2)) {
          lnaranjas[i] = 255;
          BALL_DIR = DIR_DOWNRIGHT;
        }
        else if (collide(ballbx, lnaranjas[i] - 1 , ballby, 1)) {
          lnaranjas[i] = 255;
          BALL_DIR = DIR_UPLEFT;
        }
        else if (collide(ballbx, lnaranjas[i] - 1, ballby, 2) && !collide(ballbx, lnaranjas[i - 1] , ballby, 2) &&
                 !collide(ballbx, lamarillos[i] - 1 , ballby, 2)) {
          lnaranjas[i] = 255;
          BALL_DIR = DIR_DOWNLEFT;
        }

        //Rojos
        else if (collide(ballbx, lrojos[i] , ballby, 1)) {
          lrojos[i] = 255;
          BALL_DIR = DIR_DOWNRIGHT;
        }
        else if (collide(ballbx, lrojos[i] - 1 , ballby, 0)) {
          lrojos[i] = 255;
          BALL_DIR = DIR_UPLEFT;
        }
        else if (collide(ballbx, lrojos[i] - 1, ballby, 1) && !collide(ballbx, lrojos[i - 1] , ballby, 1) &&
                 !collide(ballbx, lnaranjas[i] - 1 , ballby, 1)) {
          lrojos[i] = 255;
          BALL_DIR = DIR_DOWNLEFT;
        }
      }


      //Direccion arriba-izquierda
      else if (BALL_DIR == DIR_UPLEFT) {
        //Azules
        if (collide(ballbx, lazules[i], ballby, 5)) {
          lazules[i] = 255;
          BALL_DIR = DIR_DOWNLEFT;
        }
        else if (collide(ballbx, lazules[i] + 1 , ballby, 4)) {
          lazules[i] = 255;
          BALL_DIR = DIR_UPRIGHT;
        }
        else if (collide(ballbx, lazules[i] + 1, ballby, 5) && !collide(ballbx, lazules[i + 1] , ballby, 5)) {
          lazules[i] = 255;
          BALL_DIR = DIR_DOWNRIGHT;
        }

        //Verdes
        else if (collide(ballbx, lverdes[i] , ballby, 4)) {
          lverdes[i] = 255;
          BALL_DIR = DIR_DOWNLEFT;
        }
        else if (collide(ballbx, lverdes[i] + 1 , ballby, 3)) {
          lverdes[i] = 255;
          BALL_DIR = DIR_UPRIGHT;
        }
        else if (collide(ballbx, lverdes[i] + 1, ballby, 4) && !collide(ballbx, lverdes[i + 1] , ballby, 4) &&
                 !collide(ballbx, lazules[i] + 1 , ballby, 4)) {
          lverdes[i] = 255;
          BALL_DIR = DIR_DOWNRIGHT;
        }

        //Amarillos
        else if (collide(ballbx, lamarillos[i] , ballby, 3)) {
          lamarillos[i] = 255;
          BALL_DIR = DIR_DOWNLEFT;
        }
        else if (collide(ballbx, lamarillos[i] + 1 , ballby, 2)) {
          lamarillos[i] = 255;
          BALL_DIR = DIR_UPRIGHT;
        }
        else if (collide(ballbx, lamarillos[i] + 1, ballby, 3) && !collide(ballbx, lamarillos[i + 1] , ballby, 3) &&
                 !collide(ballbx, lverdes[i] + 1 , ballby, 3)) {
          lamarillos[i] = 255;
          BALL_DIR = DIR_DOWNRIGHT;
        }

        //Naranjas
        else if (collide(ballbx, lnaranjas[i] , ballby, 2)) {
          lnaranjas[i] = 255;
          BALL_DIR = DIR_DOWNLEFT;
        }
        else if (collide(ballbx, lnaranjas[i] + 1 , ballby, 1)) {
          lnaranjas[i] = 255;
          BALL_DIR = DIR_UPRIGHT;
        }
        else if (collide(ballbx, lnaranjas[i] + 1, ballby, 2) && !collide(ballbx, lnaranjas[i + 1] , ballby, 2) &&
                 !collide(ballbx, lamarillos[i] + 1 , ballby, 2)) {
          lnaranjas[i] = 255;
          BALL_DIR = DIR_DOWNRIGHT;
        }

        //Rojos
        else if (collide(ballbx, lrojos[i] , ballby, 1)) {
          lrojos[i] = 255;
          BALL_DIR = DIR_DOWNLEFT;
        }
        else if (collide(ballbx, lrojos[i] + 1 , ballby, 0)) {
          lrojos[i] = 255;
          BALL_DIR = DIR_UPRIGHT;
        }
        else if (collide(ballbx, lrojos[i] + 1, ballby, 1) && !collide(ballbx, lrojos[i + 1] , ballby, 1) &&
                 !collide(ballbx, lnaranjas[i] + 1 , ballby, 1)) {
          lrojos[i] = 255;
          BALL_DIR = DIR_DOWNRIGHT;
        }
      }
    }

    ballBreakOutDirection();

    clearTablePixels();

    //Dibujar la pelota
    setTablePixel(ballbx, ballby, 15, 0, 0);

    //Dibujar los ladrillos
    for (int i = 0; i < FIELD_WIDTH; i++) {
      setTablePixel(lrojos[i], 0, 15, 0, 0);      // Ladrillos rojos,
      setTablePixel(lnaranjas[i], 1, 15, 7, 0);   // naranjas,
      setTablePixel(lamarillos[i], 2, 15, 15, 0); // amarillos,
      setTablePixel(lverdes[i], 3, 7, 15, 0);     // verdes,
      setTablePixel(lazules[i], 4, 0, 7, 15);     // y azules
    }

    //Dibujar al jugador
    for (int i = posPlayer - 1; i <= posPlayer + 1; i++) {
      setTablePixel(i, 9, 15, 15, 15);
    }

    pixels.show();

    unsigned long curTime;
    boolean dirChanged = false;
    do {
      readInput();
      if (curControl == BTN_EXIT) {
        breakoutRunning = false;
        gameOverAnim(3);
        mainMenu();
        break;
      }
      if (curControl != BTN_NONE && !dirChanged) { //Solo se puede cambiar de dirección una vez
        dirChanged = true;
        setMovement();
      }
      curTime = millis();
    }
    while ((curTime - prevUpdateTime) < 250); //Luego de 250ms la serpiente se mueve
    prevUpdateTime = curTime;
    curControl = BTN_NONE;
  }
}
