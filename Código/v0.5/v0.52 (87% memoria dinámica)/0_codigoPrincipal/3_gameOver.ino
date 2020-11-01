void snakeGameOverAnim(boolean r) {
  unsigned long prevUpdateTime = 0;
  for (int z = 0; z < 4; z++) {
    setTablePixel (ax, ay, 15, 0, 0);
    for (int i = 0; i < curLength; i++) {
      setTablePixel(xs[i], ys[i], 0, 15, 0);
    }
    pixels.show();
    delay(500);
    clearTablePixels();
    pixels.show();
    delay(500);
  }
  gameOverAnim();
  while (!r) {
    unsigned long curTime;
    do {
      readInput();
      if (curControl == BTN_START) {
        runSnake();
        curControl = BTN_NONE;
        break;
      }
      curTime = millis();
    }
    while ((curTime - prevUpdateTime) < 250);
    prevUpdateTime = curTime;
  }
}

void nextFrame() {
  pixels.show();
  delay(200);
  clearTablePixels();
}

void gameOverAnim() {
  /*Frame 1*/
  int goFi[] = {30, 49, 50, 69};
  for (int i = 0; i < 4; i++) {
    pixels.setPixelColor(goFi[i], pixels.Color(15, 15, 15));
  }
  nextFrame();

  /*Frame 2*/
  int goFii[] = {28, 29, 32, 47, 50, 52, 67, 70, 71};
  for (int i = 0; i < 9; i++) {
    pixels.setPixelColor(goFii[i], pixels.Color(15, 15, 15));
  }
  nextFrame();

  /*Frame 3*/
  int goFiii[] = {26, 27, 28, 30, 34, 45, 50, 51, 52, 54, 65, 69, 71, 72, 73};
  for (int i = 0; i < 15; i++) {
    pixels.setPixelColor(goFiii[i], pixels.Color(15, 15, 15));
  }
  nextFrame();

  /*Frame 4*/
  int goFiv[] = {24, 25, 26, 32, 36, 43, 49, 50, 52, 53, 54, 56, 63, 67, 69, 70, 73, 74, 75};
  for (int i = 0; i < 19; i++) {
    pixels.setPixelColor(goFiv[i], pixels.Color(15, 15, 15));
  }
  nextFrame();

  /*Frame 5*/
  int goFv[] = {22, 23, 24, 29, 31, 34, 38, 41, 47, 50, 51, 52, 54, 55, 56, 58, 61, 65, 67, 72, 76, 77};
  for (int i = 0; i < 22; i++) {
    pixels.setPixelColor(goFv[i], pixels.Color(15, 15, 15));
  }
  nextFrame();

  /*Frame 6*/
  int goFvi[] = {20, 21, 22, 27, 28, 29, 30, 33, 36, 45, 49, 50, 51, 52, 53, 54, 56, 57, 58, 63, 65, 69, 70, 74, 77, 78, 79};
  for (int i = 0; i < 27; i++) {
    pixels.setPixelColor(goFvi[i], pixels.Color(15, 15, 15));
  }
  nextFrame();

  /*Frame 7*/
  int goFvii[] = {20, 25, 26, 27, 29, 30, 32, 35, 38, 43, 47, 49, 50, 52, 53, 54, 55, 56, 58, 59, 61, 63, 67, 69, 70, 72, 76, 79};
  for (int i = 0; i < 28; i++) {
    pixels.setPixelColor(goFvii[i], pixels.Color(15, 15, 15));
  }
  nextFrame();

  /*Frame 8*/
  int goFviii[] = {23, 24, 25, 27, 31, 32, 34, 37, 41, 45, 47, 49, 52, 54, 55, 56, 57, 58, 61, 65, 67, 72, 74, 78};
  for (int i = 0; i < 24; i++) {
    pixels.setPixelColor(goFviii[i], pixels.Color(15, 15, 15));
  }
  nextFrame();

  /*Frame 9*/
  int goFix[] = {21, 22, 23, 25, 29, 30, 31, 33, 34, 36, 39, 43, 45, 47, 49, 50, 54, 56, 57, 58, 59, 63, 65, 69, 70, 74, 76};
  for (int i = 0; i < 24; i++) {
    pixels.setPixelColor(goFix[i], pixels.Color(15, 15, 15));
  }
  nextFrame();

  /*Frame 10*/
  int goFx[] = {20, 21, 23, 27, 29, 30, 32, 33, 35, 36, 38, 41, 43, 45, 47, 49, 50, 52, 56, 58, 59, 61, 63, 67, 69, 70, 72, 76, 78};
  for (int i = 0; i < 29; i++) {
    pixels.setPixelColor(goFx[i], pixels.Color(15, 15, 15));
  }
  nextFrame();

  /*Frame 11*/
  int goFxi[] = {21, 25, 27, 28, 29, 32, 34, 35, 37, 38, 41, 43, 45, 47, 48, 49, 52, 54, 58, 61, 65, 67, 70, 71, 72, 74, 78};
  for (int i = 0; i < 27; i++) {
    pixels.setPixelColor(goFxi[i], pixels.Color(15, 15, 15));
  }
  nextFrame();

  /*Frame 12*/
  int goFxii[] = {23, 25, 26, 27, 28, 34, 37, 39, 41, 43, 45, 46, 47, 54, 56, 63, 65, 71, 72, 73, 74, 76};
  for (int i = 0; i < 22; i++) {
    pixels.setPixelColor(goFxii[i], pixels.Color(15, 15, 15));
  }
  nextFrame();

  /*Frame 13*/
  int goFxiii[] = {21, 23, 24, 25, 26, 36, 38, 39, 41, 43, 44, 45, 58, 56, 61, 63, 73, 74, 75, 76, 78};
  for (int i = 0; i < 21; i++) {
    pixels.setPixelColor(goFxiii[i], pixels.Color(15, 15, 15));
  }
  nextFrame();

  /*Frame 14*/
  int goFxiv[] = {21, 22, 23, 24, 30, 38, 41, 42, 43, 49, 50, 58, 61, 69, 75, 76, 77, 78};
  for (int i = 0; i < 18; i++) {
    pixels.setPixelColor(goFxiv[i], pixels.Color(15, 15, 15));
  }
  nextFrame();

  /*Frame 15*/
  int goFxv[] = {20, 21, 22, 28, 29, 32, 40, 41, 47, 52, 67, 70, 71, 77, 78, 79};
  for (int i = 0; i < 16; i++) {
    pixels.setPixelColor(goFxv[i], pixels.Color(15, 15, 15));
  }
  nextFrame();

  /*Frame 16*/
  int goFxvi[] = {20, 26, 27, 28, 30, 34, 45, 49, 50, 54, 65, 69, 71, 72, 73, 79};
  for (int i = 0; i < 16; i++) {
    pixels.setPixelColor(goFxvi[i], pixels.Color(15, 15, 15));
  }
  nextFrame();

  /*Frame 17*/
  int goFxvii[] = {24, 25, 26, 29, 30, 32, 36, 43, 47, 49, 52, 56, 63, 67, 73, 74, 75};
  for (int i = 0; i < 17; i++) {
    pixels.setPixelColor(goFxvii[i], pixels.Color(15, 15, 15));
  }
  nextFrame();

  /*Frame 18*/
  int goFxviii[] = {22, 23, 24, 27, 32, 34, 38, 41, 45, 47, 51, 54, 58, 61, 65, 68, 70, 75, 76, 77};
  for (int i = 0; i < 20; i++) {
    pixels.setPixelColor(goFxviii[i], pixels.Color(15, 15, 15));
  }
  nextFrame();

  /*Frame 19*/
  int goFxix[] = {20, 21, 22, 25, 29, 30, 34, 36, 43, 45, 49, 51, 53, 56, 63, 66, 68, 72, 77, 78, 79};
  for (int i = 0; i < 21; i++) {
    pixels.setPixelColor(goFxix[i], pixels.Color(15, 15, 15));
  }
  nextFrame();

  /*Frame 20*/
  int goFxx[] = {20, 23, 27, 29, 30, 32, 36, 38, 41, 43, 47, 49, 50, 53, 55, 58, 61, 64, 66, 69, 70, 74, 79};
  for (int i = 0; i < 23; i++) {
    pixels.setPixelColor(goFxx[i], pixels.Color(15, 15, 15));
  }
  nextFrame();

  /*Frame 21*/
  int goFxxi[] = {21, 25, 27, 28, 29, 32, 34, 38, 41, 45, 47, 48, 49, 52, 57, 62, 64, 67, 70, 71, 72, 76};
  for (int i = 0; i < 22; i++) {
    pixels.setPixelColor(goFxxi[i], pixels.Color(15, 15, 15));
  }
  nextFrame();
  
  /*Frame 22*/
  int goFxxii[] = {23, 25, 26, 27, 28, 34, 36, 43, 45, 46, 47, 54, 57, 59, 60, 62, 65, 71, 72, 73, 74, 78};
  for (int i = 0; i < 22; i++) {
    pixels.setPixelColor(goFxxii[i], pixels.Color(15, 15, 15));
  }
  nextFrame();

  /*Frame 23*/
  int goFxxiii[] = {21, 23, 24, 25, 26, 28, 29, 31, 36, 38, 41, 43, 44, 45, 48, 50, 51, 56, 59, 60, 63, 68, 71, 73, 74, 75, 76};
  for (int i = 0; i < 27; i++) {
    pixels.setPixelColor(goFxxiii[i], pixels.Color(15, 15, 15));
  }
  nextFrame();

  /*Frame 24*/
  int goFxxiv[] = {21, 22, 23, 24, 26, 27, 28, 29, 33, 38, 41, 42, 43, 46, 50, 51, 52, 53, 58, 61, 66, 73, 75, 76, 77, 78};
  for (int i = 0; i < 26; i++) {
    pixels.setPixelColor(goFxxiv[i], pixels.Color(15, 15, 15));
  }
  nextFrame();

  /*Frame 25*/
  int goFxxv[] = {20, 21, 22, 24, 25, 26, 27, 31, 35, 40, 41, 44, 48, 52, 53, 54, 55, 64, 68, 71, 75, 77, 78, 79};
  for (int i = 0; i < 24; i++) {
    pixels.setPixelColor(goFxxv[i], pixels.Color(15, 15, 15));
  }
  nextFrame();

  /*Frame 26*/
  int goFxxvi[] = {20, 22, 23, 24, 25, 33, 37, 42, 46, 54, 55, 56, 57, 62, 66, 73, 77, 79};
  for (int i = 0; i < 18; i++) {
    pixels.setPixelColor(goFxxvi[i], pixels.Color(15, 15, 15));
  }
  nextFrame();

  /*Frame 27*/
  int goFxxvii[] = {20, 21, 22, 23, 35, 39, 40, 44, 56, 57, 58, 59, 60, 64, 75, 79};
  for (int i = 0; i < 16; i++) {
    pixels.setPixelColor(goFxxvii[i], pixels.Color(15, 15, 15));
  }
  nextFrame();

  /*Frame 28*/
  int goFxxviii[] = {20, 21, 37, 42, 58, 59, 62, 77};
  for (int i = 0; i < 8; i++) {
    pixels.setPixelColor(goFxxviii[i], pixels.Color(15, 15, 15));
  }
  nextFrame();

  /*Frame 29*/
  int goFxxix[] = {39, 40, 60, 79};
  for (int i = 0; i < 4; i++) {
    pixels.setPixelColor(goFxxix[i], pixels.Color(15, 15, 15));
  }
  nextFrame();

  /*Final*/
  pixels.show();
}
