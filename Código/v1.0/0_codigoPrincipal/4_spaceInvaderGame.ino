/* Vabiables iniciales del juego */
byte posPlayerSpace;
byte bulletx;
byte bullety;

byte iazules[10];
byte ivioletas[10];
byte icelestes[10];
byte iverdes[10];
byte iamarillos[10];
byte irojos[10];

byte scoreSpace;

void bulletDirection () {
  switch (BALL_DIR) {
    case DIR_UP:
      if (bullety == 0) {
        bullety = 255;
        break;
      } else {
        --bullety;
      }
  }
}

void setCirculation() {
  switch (curControl) {
    case BTN_LEFT:
      if (posPlayerSpace == 1) {
        break;
      } else {
        --posPlayerSpace;
        break;
      }
    case BTN_RIGHT:
      if (posPlayerSpace == FIELD_WIDTH - 2) {
        break;
      } else {
        ++posPlayerSpace;
        break;
      }
    case BTN_FIRE:
      bulletx = posPlayerSpace;
      bullety = FIELD_HEIGHT - 3;
      BALL_DIR = DIR_UP;
      break;
    case BTN_DOWN:
      break;
    case BTN_UP:
      break;
  }
}

void spaceInit () {
  posPlayerSpace = FIELD_HEIGHT / 2;
  bulletx = 255;
  bullety = 255;

  iazules [1] = 1; iazules [2] = 2; iazules [3] = 3; iazules [4] = 4; iazules [5] = 5; iazules [6] = 6; iazules [7] = 7; iazules [8] = 8;
  ivioletas [1] = 1; ivioletas [2] = 2; ivioletas [3] = 3; ivioletas [4] = 4; ivioletas [5] = 5; ivioletas [6] = 6; ivioletas [7] = 7; ivioletas [8] = 8;
  icelestes [1] = 1; icelestes [2] = 2; icelestes [3] = 3; icelestes [4] = 4; icelestes [5] = 5; icelestes [6] = 6; icelestes [7] = 7; icelestes [8] = 8;
  iverdes [1] = 1; iverdes [2] = 2; iverdes [3] = 3; iverdes [4] = 4; iverdes [5] = 5; iverdes [6] = 6; iverdes [7] = 7; iverdes [8] = 8;
  iamarillos [1] = 1; iamarillos [2] = 2; iamarillos [3] = 3; iamarillos [4] = 4; iamarillos [5] = 5; iamarillos [6] = 6; iamarillos [7] = 7; iamarillos [8] = 8;
  irojos [1] = 1; irojos [2] = 2; irojos [3] = 3; irojos [4] = 4; irojos [5] = 5; irojos [6] = 6; irojos [7] = 7; irojos [8] = 8;

  scoreSpace = 0;
}

void runSpaceInvader () {
  spaceInit();

  unsigned long prevUpdateTime = 0;
  boolean spaceRunning = true;

  while (spaceRunning) {

    if (scoreSpace == 48) {
      Serial.print("e");
      spaceRunning = false;
      gameOverAnim(4);
      break;
    }

    setCirculation();

    for (byte i = 1; i < FIELD_WIDTH - 1; i++) {
      if (collide(bulletx, irojos[i], bullety, 5)) {
        irojos[i] = 255;
        bulletx = 255;
        bullety = 255;
        ++scoreSpace;
        Serial.print(scoreSpace);
      }
      else if (collide(bulletx, iamarillos[i], bullety, 4)) {
        iamarillos[i] = 255;
        bulletx = 255;
        bullety = 255;
        ++scoreSpace;
        Serial.print(scoreSpace);
      }
      else if (collide(bulletx, iverdes[i], bullety, 3)) {
        iverdes[i] = 255;
        bulletx = 255;
        bullety = 255;
        ++scoreSpace;
        Serial.print(scoreSpace);
      }
      else if (collide(bulletx, icelestes[i], bullety, 2)) {
        icelestes[i] = 255;
        bulletx = 255;
        bullety = 255;
        ++scoreSpace;
        Serial.print(scoreSpace);
      }
      else if (collide(bulletx, ivioletas[i], bullety, 1)) {
        ivioletas[i] = 255;
        bulletx = 255;
        bullety = 255;
        ++scoreSpace;
        Serial.print(scoreSpace);
      }
      else if (collide(bulletx, iazules[i], bullety, 0)) {
        iazules[i] = 255;
        bulletx = 255;
        bullety = 255;
        ++scoreSpace;
        Serial.print(scoreSpace);
      }
    }

    bulletDirection ();
    clearTablePixels();

    /* Dibujar bala */
    setTablePixel(bulletx, bullety, 15, 15, 15);


    /* Dibujar invaders */
    for (byte i = 1; i < FIELD_WIDTH - 1; i++) {
      setTablePixel(iazules[i], 0, 0, 0, 15);
      setTablePixel(ivioletas[i], 1, 15, 0, 15);
      setTablePixel(icelestes[i], 2, 0, 7, 15);
      setTablePixel(iverdes[i], 3, 7, 15, 0);
      setTablePixel(iamarillos[i], 4, 15, 15, 0);
      setTablePixel(irojos[i], 5, 15, 0, 0);
    }

    /* Dibujar al jugador */
    for (byte i = posPlayerSpace - 1; i <= posPlayerSpace + 1; i++) {
      if (i == posPlayerSpace) {
        setTablePixel(i, 9, 15, 15, 15);
        setTablePixel(i, 8, 15, 15, 15);
      } else {
        setTablePixel(i, 9, 15, 15, 15);
      }
    }

    pixels.show();


    unsigned long curTime;
    boolean dirChanged = false;
    do {
      readInput();
      if (curControl == BTN_EXIT) {
        spaceRunning = false;
        gameOverAnim(4);
        break;
      }
      if (curControl != BTN_NONE && !dirChanged) { //Solo se puede cambiar de dirección una vez
        dirChanged = true;
        setCirculation();
        curControl = BTN_NONE;
      }
      curTime = millis();
    }
    while ((curTime - prevUpdateTime) < 250); //Luego de 250ms el juegador se mueve
    prevUpdateTime = curTime;
  }
}
