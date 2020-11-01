void gameOverAnim(int game) {
  if (game == 1) {
    unsigned long prevUpdateTime = 0;
    for (int i = 0; i < 4; i++) {
      setTablePixel (ax, ay, 15, 0, 0);
      for (int i = 0; i < curLength; i++) {
        setTablePixel(xs[i], ys[i], 0, 15, 0);
      }
      pixels.show();
      clearTablePixels();
      delay(500);
      pixels.show();
      delay(500);
    }
    snakeGameOverAnim();
    mainMenu();
  }
  else if (game == 2) {
    unsigned long prevUpdateTime = 0;
    for (int i = 0; i < 4; i++) {
      setTablePixel(ballx, bally, 0, 15, 0);
      for (int i = posPlayerIzq - 1; i <= posPlayerIzq + 1; i++) {
        setTablePixel(0, i, 0, 0, 15);
      }
      for (int  i = posPlayerDer - 1; i <= posPlayerDer + 1; i++) {
        setTablePixel((FIELD_WIDTH - 1), i, 15, 0, 0);
      }
      pixels.show();
      clearTablePixels();
      delay(500);
      pixels.show();
      delay(500);
    }
    pongGameOverAnim();
    pixels.show();
    delay(2500);
    mainMenu();
  }
}

void nextFrame() {
  pixels.show();
  clearTablePixels();
  delay(200);
}

void pongGameOverAnim() {
  if (scoreIzq == 0) {
    pixels.setPixelColor(22, pixels.Color(0, 0, 15));
    pixels.setPixelColor(36, pixels.Color(0, 0, 15));
    pixels.setPixelColor(38, pixels.Color(0, 0, 15));
    pixels.setPixelColor(41, pixels.Color(0, 0, 15));
    pixels.setPixelColor(43, pixels.Color(0, 0, 15));
    pixels.setPixelColor(56, pixels.Color(0, 0, 15));
    pixels.setPixelColor(58, pixels.Color(0, 0, 15));
    pixels.setPixelColor(61, pixels.Color(0, 0, 15));
    pixels.setPixelColor(63, pixels.Color(0, 0, 15));
    pixels.setPixelColor(77, pixels.Color(0, 0, 15));
  }
  else if (scoreIzq == 1) {
    pixels.setPixelColor(22, pixels.Color(0, 0, 15));
    pixels.setPixelColor(37, pixels.Color(0, 0, 15));
    pixels.setPixelColor(38, pixels.Color(0, 0, 15));
    pixels.setPixelColor(42, pixels.Color(0, 0, 15));
    pixels.setPixelColor(57, pixels.Color(0, 0, 15));
    pixels.setPixelColor(62, pixels.Color(0, 0, 15));
    pixels.setPixelColor(76, pixels.Color(0, 0, 15));
    pixels.setPixelColor(77, pixels.Color(0, 0, 15));
    pixels.setPixelColor(78, pixels.Color(0, 0, 15));
  }
  else if (scoreIzq == 2) {
    pixels.setPixelColor(21, pixels.Color(0, 0, 15));
    pixels.setPixelColor(22, pixels.Color(0, 0, 15));
    pixels.setPixelColor(36, pixels.Color(0, 0, 15));
    pixels.setPixelColor(43, pixels.Color(0, 0, 15));
    pixels.setPixelColor(57, pixels.Color(0, 0, 15));
    pixels.setPixelColor(61, pixels.Color(0, 0, 15));
    pixels.setPixelColor(76, pixels.Color(0, 0, 15));
    pixels.setPixelColor(77, pixels.Color(0, 0, 15));
    pixels.setPixelColor(78, pixels.Color(0, 0, 15));
  }
  else if (scoreIzq == 3) {
    pixels.setPixelColor(21, pixels.Color(0, 0, 15));
    pixels.setPixelColor(22, pixels.Color(0, 0, 15));
    pixels.setPixelColor(36, pixels.Color(0, 0, 15));
    pixels.setPixelColor(42, pixels.Color(0, 0, 15));
    pixels.setPixelColor(56, pixels.Color(0, 0, 15));
    pixels.setPixelColor(63, pixels.Color(0, 0, 15));
    pixels.setPixelColor(77, pixels.Color(0, 0, 15));
    pixels.setPixelColor(78, pixels.Color(0, 0, 15));
  }
  else if (scoreIzq == 4) {
    pixels.setPixelColor(21, pixels.Color(0, 0, 15));
    pixels.setPixelColor(36, pixels.Color(0, 0, 15));
    pixels.setPixelColor(38, pixels.Color(0, 0, 15));
    pixels.setPixelColor(41, pixels.Color(0, 0, 15));
    pixels.setPixelColor(43, pixels.Color(0, 0, 15));
    pixels.setPixelColor(56, pixels.Color(0, 0, 15));
    pixels.setPixelColor(57, pixels.Color(0, 0, 15));
    pixels.setPixelColor(58, pixels.Color(0, 0, 15));
    pixels.setPixelColor(63, pixels.Color(0, 0, 15));
    pixels.setPixelColor(76, pixels.Color(0, 0, 15));
  }
  else if (scoreIzq == 5) {
    pixels.setPixelColor(21, pixels.Color(0, 0, 15));
    pixels.setPixelColor(22, pixels.Color(0, 0, 15));
    pixels.setPixelColor(23, pixels.Color(0, 0, 15));
    pixels.setPixelColor(38, pixels.Color(0, 0, 15));
    pixels.setPixelColor(41, pixels.Color(0, 0, 15));
    pixels.setPixelColor(42, pixels.Color(0, 0, 15));
    pixels.setPixelColor(56, pixels.Color(0, 0, 15));
    pixels.setPixelColor(63, pixels.Color(0, 0, 15));
    pixels.setPixelColor(77, pixels.Color(0, 0, 15));
    pixels.setPixelColor(78, pixels.Color(0, 0, 15));
  }

  if (scoreDer == 0) {
    pixels.setPixelColor(27, pixels.Color(15, 0, 0));
    pixels.setPixelColor(31, pixels.Color(15, 0, 0));
    pixels.setPixelColor(33, pixels.Color(15, 0, 0));
    pixels.setPixelColor(46, pixels.Color(15, 0, 0));
    pixels.setPixelColor(48, pixels.Color(15, 0, 0));
    pixels.setPixelColor(51, pixels.Color(15, 0, 0));
    pixels.setPixelColor(53, pixels.Color(15, 0, 0));
    pixels.setPixelColor(66, pixels.Color(15, 0, 0));
    pixels.setPixelColor(68, pixels.Color(15, 0, 0));
    pixels.setPixelColor(72, pixels.Color(15, 0, 0));
  }
  else if (scoreDer == 1) {
    pixels.setPixelColor(27, pixels.Color(15, 0, 0));
    pixels.setPixelColor(32, pixels.Color(15, 0, 0));
    pixels.setPixelColor(33, pixels.Color(15, 0, 0));
    pixels.setPixelColor(47, pixels.Color(15, 0, 0));
    pixels.setPixelColor(52, pixels.Color(15, 0, 0));
    pixels.setPixelColor(67, pixels.Color(15, 0, 0));
    pixels.setPixelColor(71, pixels.Color(15, 0, 0));
    pixels.setPixelColor(72, pixels.Color(15, 0, 0));
    pixels.setPixelColor(73, pixels.Color(15, 0, 0));
  }
  else if (scoreDer == 2) {
    pixels.setPixelColor(26, pixels.Color(15, 0, 0));
    pixels.setPixelColor(27, pixels.Color(15, 0, 0));
    pixels.setPixelColor(31, pixels.Color(15, 0, 0));
    pixels.setPixelColor(48, pixels.Color(15, 0, 0));
    pixels.setPixelColor(52, pixels.Color(15, 0, 0));
    pixels.setPixelColor(66, pixels.Color(15, 0, 0));
    pixels.setPixelColor(71, pixels.Color(15, 0, 0));
    pixels.setPixelColor(72, pixels.Color(15, 0, 0));
    pixels.setPixelColor(73, pixels.Color(15, 0, 0));
  }
  else if (scoreDer == 3) {
    pixels.setPixelColor(26, pixels.Color(15, 0, 0));
    pixels.setPixelColor(27, pixels.Color(15, 0, 0));
    pixels.setPixelColor(31, pixels.Color(15, 0, 0));
    pixels.setPixelColor(47, pixels.Color(15, 0, 0));
    pixels.setPixelColor(51, pixels.Color(15, 0, 0));
    pixels.setPixelColor(68, pixels.Color(15, 0, 0));
    pixels.setPixelColor(72, pixels.Color(15, 0, 0));
    pixels.setPixelColor(73, pixels.Color(15, 0, 0));
  }
  else if (scoreDer == 4) {
    pixels.setPixelColor(26, pixels.Color(15, 0, 0));
    pixels.setPixelColor(31, pixels.Color(15, 0, 0));
    pixels.setPixelColor(33, pixels.Color(15, 0, 0));
    pixels.setPixelColor(46, pixels.Color(15, 0, 0));
    pixels.setPixelColor(48, pixels.Color(15, 0, 0));
    pixels.setPixelColor(51, pixels.Color(15, 0, 0));
    pixels.setPixelColor(52, pixels.Color(15, 0, 0));
    pixels.setPixelColor(53, pixels.Color(15, 0, 0));
    pixels.setPixelColor(68, pixels.Color(15, 0, 0));
    pixels.setPixelColor(71, pixels.Color(15, 0, 0));
  }
  else if (scoreDer == 5) {
    pixels.setPixelColor(26, pixels.Color(15, 0, 0));
    pixels.setPixelColor(27, pixels.Color(15, 0, 0));
    pixels.setPixelColor(28, pixels.Color(15, 0, 0));
    pixels.setPixelColor(33, pixels.Color(15, 0, 0));
    pixels.setPixelColor(46, pixels.Color(15, 0, 0));
    pixels.setPixelColor(47, pixels.Color(15, 0, 0));
    pixels.setPixelColor(51, pixels.Color(15, 0, 0));
    pixels.setPixelColor(68, pixels.Color(15, 0, 0));
    pixels.setPixelColor(72, pixels.Color(15, 0, 0));
    pixels.setPixelColor(73, pixels.Color(15, 0, 0));
  }
}

void snakeGameOverAnim() {
  /*Frame 1*/
  pixels.setPixelColor(30, pixels.Color(15, 15, 15));
  pixels.setPixelColor(49, pixels.Color(15, 15, 15));
  pixels.setPixelColor(50, pixels.Color(15, 15, 15));
  pixels.setPixelColor(69, pixels.Color(15, 15, 15));
  nextFrame();

  /*Frame 3*/
  pixels.setPixelColor(28, pixels.Color(15, 15, 15));
  pixels.setPixelColor(29, pixels.Color(15, 15, 15));
  pixels.setPixelColor(32, pixels.Color(15, 15, 15));
  pixels.setPixelColor(47, pixels.Color(15, 15, 15));
  pixels.setPixelColor(50, pixels.Color(15, 15, 15));
  pixels.setPixelColor(52, pixels.Color(15, 15, 15));
  pixels.setPixelColor(67, pixels.Color(15, 15, 15));
  pixels.setPixelColor(70, pixels.Color(15, 15, 15));
  pixels.setPixelColor(71, pixels.Color(15, 15, 15));
  nextFrame();

  /*Frame 5*/
  pixels.setPixelColor(26, pixels.Color(15, 15, 15));
  pixels.setPixelColor(27, pixels.Color(15, 15, 15));
  pixels.setPixelColor(28, pixels.Color(15, 15, 15));
  pixels.setPixelColor(30, pixels.Color(15, 15, 15));
  pixels.setPixelColor(34, pixels.Color(15, 15, 15));
  pixels.setPixelColor(45, pixels.Color(15, 15, 15));
  pixels.setPixelColor(50, pixels.Color(15, 15, 15));
  pixels.setPixelColor(51, pixels.Color(15, 15, 15));
  pixels.setPixelColor(52, pixels.Color(15, 15, 15));
  pixels.setPixelColor(54, pixels.Color(15, 15, 15));
  pixels.setPixelColor(65, pixels.Color(15, 15, 15));
  pixels.setPixelColor(69, pixels.Color(15, 15, 15));
  pixels.setPixelColor(71, pixels.Color(15, 15, 15));
  pixels.setPixelColor(72, pixels.Color(15, 15, 15));
  pixels.setPixelColor(73, pixels.Color(15, 15, 15));
  nextFrame();

  /*Frame 7*/
  pixels.setPixelColor(24, pixels.Color(15, 15, 15));
  pixels.setPixelColor(25, pixels.Color(15, 15, 15));
  pixels.setPixelColor(26, pixels.Color(15, 15, 15));
  pixels.setPixelColor(32, pixels.Color(15, 15, 15));
  pixels.setPixelColor(36, pixels.Color(15, 15, 15));
  pixels.setPixelColor(43, pixels.Color(15, 15, 15));
  pixels.setPixelColor(49, pixels.Color(15, 15, 15));
  pixels.setPixelColor(50, pixels.Color(15, 15, 15));
  pixels.setPixelColor(52, pixels.Color(15, 15, 15));
  pixels.setPixelColor(53, pixels.Color(15, 15, 15));
  pixels.setPixelColor(54, pixels.Color(15, 15, 15));
  pixels.setPixelColor(56, pixels.Color(15, 15, 15));
  pixels.setPixelColor(63, pixels.Color(15, 15, 15));
  pixels.setPixelColor(67, pixels.Color(15, 15, 15));
  pixels.setPixelColor(69, pixels.Color(15, 15, 15));
  pixels.setPixelColor(70, pixels.Color(15, 15, 15));
  pixels.setPixelColor(73, pixels.Color(15, 15, 15));
  pixels.setPixelColor(74, pixels.Color(15, 15, 15));
  pixels.setPixelColor(75, pixels.Color(15, 15, 15));
  nextFrame();

  /*Frame 9*/
  pixels.setPixelColor(22, pixels.Color(15, 15, 15));
  pixels.setPixelColor(23, pixels.Color(15, 15, 15));
  pixels.setPixelColor(24, pixels.Color(15, 15, 15));
  pixels.setPixelColor(29, pixels.Color(15, 15, 15));
  pixels.setPixelColor(31, pixels.Color(15, 15, 15));
  pixels.setPixelColor(34, pixels.Color(15, 15, 15));
  pixels.setPixelColor(38, pixels.Color(15, 15, 15));
  pixels.setPixelColor(41, pixels.Color(15, 15, 15));
  pixels.setPixelColor(47, pixels.Color(15, 15, 15));
  pixels.setPixelColor(50, pixels.Color(15, 15, 15));
  pixels.setPixelColor(51, pixels.Color(15, 15, 15));
  pixels.setPixelColor(52, pixels.Color(15, 15, 15));
  pixels.setPixelColor(54, pixels.Color(15, 15, 15));
  pixels.setPixelColor(55, pixels.Color(15, 15, 15));
  pixels.setPixelColor(56, pixels.Color(15, 15, 15));
  pixels.setPixelColor(58, pixels.Color(15, 15, 15));
  pixels.setPixelColor(61, pixels.Color(15, 15, 15));
  pixels.setPixelColor(65, pixels.Color(15, 15, 15));
  pixels.setPixelColor(67, pixels.Color(15, 15, 15));
  pixels.setPixelColor(72, pixels.Color(15, 15, 15));
  pixels.setPixelColor(75, pixels.Color(15, 15, 15));
  pixels.setPixelColor(76, pixels.Color(15, 15, 15));
  pixels.setPixelColor(77, pixels.Color(15, 15, 15));
  nextFrame();

  /*Frame 11*/
  pixels.setPixelColor(20, pixels.Color(15, 15, 15));
  pixels.setPixelColor(21, pixels.Color(15, 15, 15));
  pixels.setPixelColor(22, pixels.Color(15, 15, 15));
  pixels.setPixelColor(27, pixels.Color(15, 15, 15));
  pixels.setPixelColor(28, pixels.Color(15, 15, 15));
  pixels.setPixelColor(29, pixels.Color(15, 15, 15));
  pixels.setPixelColor(30, pixels.Color(15, 15, 15));
  pixels.setPixelColor(33, pixels.Color(15, 15, 15));
  pixels.setPixelColor(36, pixels.Color(15, 15, 15));
  pixels.setPixelColor(45, pixels.Color(15, 15, 15));
  pixels.setPixelColor(49, pixels.Color(15, 15, 15));
  pixels.setPixelColor(50, pixels.Color(15, 15, 15));
  pixels.setPixelColor(51, pixels.Color(15, 15, 15));
  pixels.setPixelColor(52, pixels.Color(15, 15, 15));
  pixels.setPixelColor(53, pixels.Color(15, 15, 15));
  pixels.setPixelColor(54, pixels.Color(15, 15, 15));
  pixels.setPixelColor(56, pixels.Color(15, 15, 15));
  pixels.setPixelColor(57, pixels.Color(15, 15, 15));
  pixels.setPixelColor(58, pixels.Color(15, 15, 15));
  pixels.setPixelColor(63, pixels.Color(15, 15, 15));
  pixels.setPixelColor(65, pixels.Color(15, 15, 15));
  pixels.setPixelColor(69, pixels.Color(15, 15, 15));
  pixels.setPixelColor(70, pixels.Color(15, 15, 15));
  pixels.setPixelColor(74, pixels.Color(15, 15, 15));
  pixels.setPixelColor(77, pixels.Color(15, 15, 15));
  pixels.setPixelColor(78, pixels.Color(15, 15, 15));
  pixels.setPixelColor(79, pixels.Color(15, 15, 15));
  nextFrame();

  /*Frame 13*/
  pixels.setPixelColor(20, pixels.Color(15, 15, 15));
  pixels.setPixelColor(25, pixels.Color(15, 15, 15));
  pixels.setPixelColor(26, pixels.Color(15, 15, 15));
  pixels.setPixelColor(27, pixels.Color(15, 15, 15));
  pixels.setPixelColor(29, pixels.Color(15, 15, 15));
  pixels.setPixelColor(30, pixels.Color(15, 15, 15));
  pixels.setPixelColor(32, pixels.Color(15, 15, 15));
  pixels.setPixelColor(35, pixels.Color(15, 15, 15));
  pixels.setPixelColor(38, pixels.Color(15, 15, 15));
  pixels.setPixelColor(43, pixels.Color(15, 15, 15));
  pixels.setPixelColor(47, pixels.Color(15, 15, 15));
  pixels.setPixelColor(49, pixels.Color(15, 15, 15));
  pixels.setPixelColor(50, pixels.Color(15, 15, 15));
  pixels.setPixelColor(52, pixels.Color(15, 15, 15));
  pixels.setPixelColor(53, pixels.Color(15, 15, 15));
  pixels.setPixelColor(54, pixels.Color(15, 15, 15));
  pixels.setPixelColor(55, pixels.Color(15, 15, 15));
  pixels.setPixelColor(56, pixels.Color(15, 15, 15));
  pixels.setPixelColor(58, pixels.Color(15, 15, 15));
  pixels.setPixelColor(59, pixels.Color(15, 15, 15));
  pixels.setPixelColor(61, pixels.Color(15, 15, 15));
  pixels.setPixelColor(63, pixels.Color(15, 15, 15));
  pixels.setPixelColor(67, pixels.Color(15, 15, 15));
  pixels.setPixelColor(69, pixels.Color(15, 15, 15));
  pixels.setPixelColor(70, pixels.Color(15, 15, 15));
  pixels.setPixelColor(72, pixels.Color(15, 15, 15));
  pixels.setPixelColor(76, pixels.Color(15, 15, 15));
  pixels.setPixelColor(79, pixels.Color(15, 15, 15));
  nextFrame();

  /*Frame 15*/
  pixels.setPixelColor(23, pixels.Color(15, 15, 15));
  pixels.setPixelColor(24, pixels.Color(15, 15, 15));
  pixels.setPixelColor(25, pixels.Color(15, 15, 15));
  pixels.setPixelColor(27, pixels.Color(15, 15, 15));
  pixels.setPixelColor(31, pixels.Color(15, 15, 15));
  pixels.setPixelColor(32, pixels.Color(15, 15, 15));
  pixels.setPixelColor(34, pixels.Color(15, 15, 15));
  pixels.setPixelColor(37, pixels.Color(15, 15, 15));
  pixels.setPixelColor(41, pixels.Color(15, 15, 15));
  pixels.setPixelColor(45, pixels.Color(15, 15, 15));
  pixels.setPixelColor(47, pixels.Color(15, 15, 15));
  pixels.setPixelColor(49, pixels.Color(15, 15, 15));
  pixels.setPixelColor(52, pixels.Color(15, 15, 15));
  pixels.setPixelColor(54, pixels.Color(15, 15, 15));
  pixels.setPixelColor(55, pixels.Color(15, 15, 15));
  pixels.setPixelColor(56, pixels.Color(15, 15, 15));
  pixels.setPixelColor(57, pixels.Color(15, 15, 15));
  pixels.setPixelColor(58, pixels.Color(15, 15, 15));
  pixels.setPixelColor(61, pixels.Color(15, 15, 15));
  pixels.setPixelColor(65, pixels.Color(15, 15, 15));
  pixels.setPixelColor(67, pixels.Color(15, 15, 15));
  pixels.setPixelColor(72, pixels.Color(15, 15, 15));
  pixels.setPixelColor(74, pixels.Color(15, 15, 15));
  pixels.setPixelColor(78, pixels.Color(15, 15, 15));
  nextFrame();

  /*Frame 17*/
  pixels.setPixelColor(21, pixels.Color(15, 15, 15));
  pixels.setPixelColor(22, pixels.Color(15, 15, 15));
  pixels.setPixelColor(23, pixels.Color(15, 15, 15));
  pixels.setPixelColor(25, pixels.Color(15, 15, 15));
  pixels.setPixelColor(29, pixels.Color(15, 15, 15));
  pixels.setPixelColor(30, pixels.Color(15, 15, 15));
  pixels.setPixelColor(31, pixels.Color(15, 15, 15));
  pixels.setPixelColor(33, pixels.Color(15, 15, 15));
  pixels.setPixelColor(34, pixels.Color(15, 15, 15));
  pixels.setPixelColor(36, pixels.Color(15, 15, 15));
  pixels.setPixelColor(39, pixels.Color(15, 15, 15));
  pixels.setPixelColor(43, pixels.Color(15, 15, 15));
  pixels.setPixelColor(45, pixels.Color(15, 15, 15));
  pixels.setPixelColor(47, pixels.Color(15, 15, 15));
  pixels.setPixelColor(49, pixels.Color(15, 15, 15));
  pixels.setPixelColor(50, pixels.Color(15, 15, 15));
  pixels.setPixelColor(54, pixels.Color(15, 15, 15));
  pixels.setPixelColor(56, pixels.Color(15, 15, 15));
  pixels.setPixelColor(57, pixels.Color(15, 15, 15));
  pixels.setPixelColor(58, pixels.Color(15, 15, 15));
  pixels.setPixelColor(59, pixels.Color(15, 15, 15));
  pixels.setPixelColor(63, pixels.Color(15, 15, 15));
  pixels.setPixelColor(65, pixels.Color(15, 15, 15));
  pixels.setPixelColor(69, pixels.Color(15, 15, 15));
  pixels.setPixelColor(70, pixels.Color(15, 15, 15));
  pixels.setPixelColor(74, pixels.Color(15, 15, 15));
  pixels.setPixelColor(76, pixels.Color(15, 15, 15));
  nextFrame();

  /*Frame 19*/
  pixels.setPixelColor(20, pixels.Color(15, 15, 15));
  pixels.setPixelColor(21, pixels.Color(15, 15, 15));
  pixels.setPixelColor(23, pixels.Color(15, 15, 15));
  pixels.setPixelColor(27, pixels.Color(15, 15, 15));
  pixels.setPixelColor(29, pixels.Color(15, 15, 15));
  pixels.setPixelColor(30, pixels.Color(15, 15, 15));
  pixels.setPixelColor(32, pixels.Color(15, 15, 15));
  pixels.setPixelColor(33, pixels.Color(15, 15, 15));
  pixels.setPixelColor(35, pixels.Color(15, 15, 15));
  pixels.setPixelColor(36, pixels.Color(15, 15, 15));
  pixels.setPixelColor(38, pixels.Color(15, 15, 15));
  pixels.setPixelColor(41, pixels.Color(15, 15, 15));
  pixels.setPixelColor(43, pixels.Color(15, 15, 15));
  pixels.setPixelColor(45, pixels.Color(15, 15, 15));
  pixels.setPixelColor(47, pixels.Color(15, 15, 15));
  pixels.setPixelColor(49, pixels.Color(15, 15, 15));
  pixels.setPixelColor(50, pixels.Color(15, 15, 15));
  pixels.setPixelColor(52, pixels.Color(15, 15, 15));
  pixels.setPixelColor(56, pixels.Color(15, 15, 15));
  pixels.setPixelColor(58, pixels.Color(15, 15, 15));
  pixels.setPixelColor(59, pixels.Color(15, 15, 15));
  pixels.setPixelColor(61, pixels.Color(15, 15, 15));
  pixels.setPixelColor(63, pixels.Color(15, 15, 15));
  pixels.setPixelColor(67, pixels.Color(15, 15, 15));
  pixels.setPixelColor(69, pixels.Color(15, 15, 15));
  pixels.setPixelColor(70, pixels.Color(15, 15, 15));
  pixels.setPixelColor(72, pixels.Color(15, 15, 15));
  pixels.setPixelColor(76, pixels.Color(15, 15, 15));
  pixels.setPixelColor(78, pixels.Color(15, 15, 15));
  nextFrame();

  /*Frame 21*/
  pixels.setPixelColor(21, pixels.Color(15, 15, 15));
  pixels.setPixelColor(25, pixels.Color(15, 15, 15));
  pixels.setPixelColor(27, pixels.Color(15, 15, 15));
  pixels.setPixelColor(28, pixels.Color(15, 15, 15));
  pixels.setPixelColor(29, pixels.Color(15, 15, 15));
  pixels.setPixelColor(32, pixels.Color(15, 15, 15));
  pixels.setPixelColor(34, pixels.Color(15, 15, 15));
  pixels.setPixelColor(35, pixels.Color(15, 15, 15));
  pixels.setPixelColor(37, pixels.Color(15, 15, 15));
  pixels.setPixelColor(38, pixels.Color(15, 15, 15));
  pixels.setPixelColor(41, pixels.Color(15, 15, 15));
  pixels.setPixelColor(43, pixels.Color(15, 15, 15));
  pixels.setPixelColor(45, pixels.Color(15, 15, 15));
  pixels.setPixelColor(47, pixels.Color(15, 15, 15));
  pixels.setPixelColor(48, pixels.Color(15, 15, 15));
  pixels.setPixelColor(49, pixels.Color(15, 15, 15));
  pixels.setPixelColor(52, pixels.Color(15, 15, 15));
  pixels.setPixelColor(54, pixels.Color(15, 15, 15));
  pixels.setPixelColor(58, pixels.Color(15, 15, 15));
  pixels.setPixelColor(61, pixels.Color(15, 15, 15));
  pixels.setPixelColor(65, pixels.Color(15, 15, 15));
  pixels.setPixelColor(67, pixels.Color(15, 15, 15));
  pixels.setPixelColor(70, pixels.Color(15, 15, 15));
  pixels.setPixelColor(71, pixels.Color(15, 15, 15));
  pixels.setPixelColor(72, pixels.Color(15, 15, 15));
  pixels.setPixelColor(74, pixels.Color(15, 15, 15));
  pixels.setPixelColor(78, pixels.Color(15, 15, 15));
  nextFrame();

  /*Frame 23*/
  pixels.setPixelColor(23, pixels.Color(15, 15, 15));
  pixels.setPixelColor(25, pixels.Color(15, 15, 15));
  pixels.setPixelColor(26, pixels.Color(15, 15, 15));
  pixels.setPixelColor(27, pixels.Color(15, 15, 15));
  pixels.setPixelColor(28, pixels.Color(15, 15, 15));
  pixels.setPixelColor(34, pixels.Color(15, 15, 15));
  pixels.setPixelColor(36, pixels.Color(15, 15, 15));
  pixels.setPixelColor(37, pixels.Color(15, 15, 15));
  pixels.setPixelColor(39, pixels.Color(15, 15, 15));
  pixels.setPixelColor(41, pixels.Color(15, 15, 15));
  pixels.setPixelColor(43, pixels.Color(15, 15, 15));
  pixels.setPixelColor(45, pixels.Color(15, 15, 15));
  pixels.setPixelColor(46, pixels.Color(15, 15, 15));
  pixels.setPixelColor(47, pixels.Color(15, 15, 15));
  pixels.setPixelColor(54, pixels.Color(15, 15, 15));
  pixels.setPixelColor(56, pixels.Color(15, 15, 15));
  pixels.setPixelColor(63, pixels.Color(15, 15, 15));
  pixels.setPixelColor(65, pixels.Color(15, 15, 15));
  pixels.setPixelColor(71, pixels.Color(15, 15, 15));
  pixels.setPixelColor(72, pixels.Color(15, 15, 15));
  pixels.setPixelColor(73, pixels.Color(15, 15, 15));
  pixels.setPixelColor(74, pixels.Color(15, 15, 15));
  pixels.setPixelColor(76, pixels.Color(15, 15, 15));
  nextFrame();

  /*Frame 25*/
  pixels.setPixelColor(21, pixels.Color(15, 15, 15));
  pixels.setPixelColor(23, pixels.Color(15, 15, 15));
  pixels.setPixelColor(24, pixels.Color(15, 15, 15));
  pixels.setPixelColor(25, pixels.Color(15, 15, 15));
  pixels.setPixelColor(26, pixels.Color(15, 15, 15));
  pixels.setPixelColor(36, pixels.Color(15, 15, 15));
  pixels.setPixelColor(38, pixels.Color(15, 15, 15));
  pixels.setPixelColor(39, pixels.Color(15, 15, 15));
  pixels.setPixelColor(41, pixels.Color(15, 15, 15));
  pixels.setPixelColor(43, pixels.Color(15, 15, 15));
  pixels.setPixelColor(44, pixels.Color(15, 15, 15));
  pixels.setPixelColor(45, pixels.Color(15, 15, 15));
  pixels.setPixelColor(58, pixels.Color(15, 15, 15));
  pixels.setPixelColor(56, pixels.Color(15, 15, 15));
  pixels.setPixelColor(61, pixels.Color(15, 15, 15));
  pixels.setPixelColor(63, pixels.Color(15, 15, 15));
  pixels.setPixelColor(73, pixels.Color(15, 15, 15));
  pixels.setPixelColor(74, pixels.Color(15, 15, 15));
  pixels.setPixelColor(75, pixels.Color(15, 15, 15));
  pixels.setPixelColor(76, pixels.Color(15, 15, 15));
  pixels.setPixelColor(78, pixels.Color(15, 15, 15));
  nextFrame();

  /*Frame 27*/
  pixels.setPixelColor(21, pixels.Color(15, 15, 15));
  pixels.setPixelColor(22, pixels.Color(15, 15, 15));
  pixels.setPixelColor(23, pixels.Color(15, 15, 15));
  pixels.setPixelColor(24, pixels.Color(15, 15, 15));
  pixels.setPixelColor(30, pixels.Color(15, 15, 15));
  pixels.setPixelColor(38, pixels.Color(15, 15, 15));
  pixels.setPixelColor(41, pixels.Color(15, 15, 15));
  pixels.setPixelColor(42, pixels.Color(15, 15, 15));
  pixels.setPixelColor(43, pixels.Color(15, 15, 15));
  pixels.setPixelColor(49, pixels.Color(15, 15, 15));
  pixels.setPixelColor(50, pixels.Color(15, 15, 15));
  pixels.setPixelColor(58, pixels.Color(15, 15, 15));
  pixels.setPixelColor(61, pixels.Color(15, 15, 15));
  pixels.setPixelColor(69, pixels.Color(15, 15, 15));
  pixels.setPixelColor(75, pixels.Color(15, 15, 15));
  pixels.setPixelColor(76, pixels.Color(15, 15, 15));
  pixels.setPixelColor(77, pixels.Color(15, 15, 15));
  pixels.setPixelColor(78, pixels.Color(15, 15, 15));
  nextFrame();

  /*Frame 29*/
  pixels.setPixelColor(20, pixels.Color(15, 15, 15));
  pixels.setPixelColor(21, pixels.Color(15, 15, 15));
  pixels.setPixelColor(22, pixels.Color(15, 15, 15));
  pixels.setPixelColor(28, pixels.Color(15, 15, 15));
  pixels.setPixelColor(29, pixels.Color(15, 15, 15));
  pixels.setPixelColor(32, pixels.Color(15, 15, 15));
  pixels.setPixelColor(40, pixels.Color(15, 15, 15));
  pixels.setPixelColor(41, pixels.Color(15, 15, 15));
  pixels.setPixelColor(47, pixels.Color(15, 15, 15));
  pixels.setPixelColor(52, pixels.Color(15, 15, 15));
  pixels.setPixelColor(67, pixels.Color(15, 15, 15));
  pixels.setPixelColor(70, pixels.Color(15, 15, 15));
  pixels.setPixelColor(71, pixels.Color(15, 15, 15));
  pixels.setPixelColor(77, pixels.Color(15, 15, 15));
  pixels.setPixelColor(78, pixels.Color(15, 15, 15));
  pixels.setPixelColor(79, pixels.Color(15, 15, 15));
  nextFrame();

  /*Frame 31*/
  pixels.setPixelColor(20, pixels.Color(15, 15, 15));
  pixels.setPixelColor(26, pixels.Color(15, 15, 15));
  pixels.setPixelColor(27, pixels.Color(15, 15, 15));
  pixels.setPixelColor(28, pixels.Color(15, 15, 15));
  pixels.setPixelColor(30, pixels.Color(15, 15, 15));
  pixels.setPixelColor(34, pixels.Color(15, 15, 15));
  pixels.setPixelColor(45, pixels.Color(15, 15, 15));
  pixels.setPixelColor(49, pixels.Color(15, 15, 15));
  pixels.setPixelColor(50, pixels.Color(15, 15, 15));
  pixels.setPixelColor(54, pixels.Color(15, 15, 15));
  pixels.setPixelColor(65, pixels.Color(15, 15, 15));
  pixels.setPixelColor(69, pixels.Color(15, 15, 15));
  pixels.setPixelColor(71, pixels.Color(15, 15, 15));
  pixels.setPixelColor(72, pixels.Color(15, 15, 15));
  pixels.setPixelColor(73, pixels.Color(15, 15, 15));
  pixels.setPixelColor(79, pixels.Color(15, 15, 15));
  nextFrame();

  /*Frame 33*/
  pixels.setPixelColor(24, pixels.Color(15, 15, 15));
  pixels.setPixelColor(25, pixels.Color(15, 15, 15));
  pixels.setPixelColor(26, pixels.Color(15, 15, 15));
  pixels.setPixelColor(29, pixels.Color(15, 15, 15));
  pixels.setPixelColor(30, pixels.Color(15, 15, 15));
  pixels.setPixelColor(32, pixels.Color(15, 15, 15));
  pixels.setPixelColor(36, pixels.Color(15, 15, 15));
  pixels.setPixelColor(43, pixels.Color(15, 15, 15));
  pixels.setPixelColor(47, pixels.Color(15, 15, 15));
  pixels.setPixelColor(49, pixels.Color(15, 15, 15));
  pixels.setPixelColor(52, pixels.Color(15, 15, 15));
  pixels.setPixelColor(56, pixels.Color(15, 15, 15));
  pixels.setPixelColor(63, pixels.Color(15, 15, 15));
  pixels.setPixelColor(67, pixels.Color(15, 15, 15));
  pixels.setPixelColor(73, pixels.Color(15, 15, 15));
  pixels.setPixelColor(74, pixels.Color(15, 15, 15));
  pixels.setPixelColor(75, pixels.Color(15, 15, 15));
  pixels.show();
  delay(200);
  clearTablePixels();

  /*Frame 35*/
  pixels.setPixelColor(22, pixels.Color(15, 15, 15));
  pixels.setPixelColor(23, pixels.Color(15, 15, 15));
  pixels.setPixelColor(24, pixels.Color(15, 15, 15));
  pixels.setPixelColor(27, pixels.Color(15, 15, 15));
  pixels.setPixelColor(32, pixels.Color(15, 15, 15));
  pixels.setPixelColor(34, pixels.Color(15, 15, 15));
  pixels.setPixelColor(38, pixels.Color(15, 15, 15));
  pixels.setPixelColor(41, pixels.Color(15, 15, 15));
  pixels.setPixelColor(45, pixels.Color(15, 15, 15));
  pixels.setPixelColor(47, pixels.Color(15, 15, 15));
  pixels.setPixelColor(51, pixels.Color(15, 15, 15));
  pixels.setPixelColor(54, pixels.Color(15, 15, 15));
  pixels.setPixelColor(58, pixels.Color(15, 15, 15));
  pixels.setPixelColor(61, pixels.Color(15, 15, 15));
  pixels.setPixelColor(65, pixels.Color(15, 15, 15));
  pixels.setPixelColor(68, pixels.Color(15, 15, 15));
  pixels.setPixelColor(70, pixels.Color(15, 15, 15));
  pixels.setPixelColor(75, pixels.Color(15, 15, 15));
  pixels.setPixelColor(76, pixels.Color(15, 15, 15));
  pixels.setPixelColor(77, pixels.Color(15, 15, 15));
  pixels.show();
  delay(200);
  clearTablePixels();

  /*Frame 37*/
  pixels.setPixelColor(20, pixels.Color(15, 15, 15));
  pixels.setPixelColor(21, pixels.Color(15, 15, 15));
  pixels.setPixelColor(22, pixels.Color(15, 15, 15));
  pixels.setPixelColor(25, pixels.Color(15, 15, 15));
  pixels.setPixelColor(29, pixels.Color(15, 15, 15));
  pixels.setPixelColor(30, pixels.Color(15, 15, 15));
  pixels.setPixelColor(34, pixels.Color(15, 15, 15));
  pixels.setPixelColor(36, pixels.Color(15, 15, 15));
  pixels.setPixelColor(43, pixels.Color(15, 15, 15));
  pixels.setPixelColor(45, pixels.Color(15, 15, 15));
  pixels.setPixelColor(49, pixels.Color(15, 15, 15));
  pixels.setPixelColor(51, pixels.Color(15, 15, 15));
  pixels.setPixelColor(53, pixels.Color(15, 15, 15));
  pixels.setPixelColor(56, pixels.Color(15, 15, 15));
  pixels.setPixelColor(63, pixels.Color(15, 15, 15));
  pixels.setPixelColor(66, pixels.Color(15, 15, 15));
  pixels.setPixelColor(68, pixels.Color(15, 15, 15));
  pixels.setPixelColor(72, pixels.Color(15, 15, 15));
  pixels.setPixelColor(77, pixels.Color(15, 15, 15));
  pixels.setPixelColor(78, pixels.Color(15, 15, 15));
  pixels.setPixelColor(79, pixels.Color(15, 15, 15));
  nextFrame();

  /*Frame 39*/
  pixels.setPixelColor(20, pixels.Color(15, 15, 15));
  pixels.setPixelColor(23, pixels.Color(15, 15, 15));
  pixels.setPixelColor(27, pixels.Color(15, 15, 15));
  pixels.setPixelColor(29, pixels.Color(15, 15, 15));
  pixels.setPixelColor(30, pixels.Color(15, 15, 15));
  pixels.setPixelColor(32, pixels.Color(15, 15, 15));
  pixels.setPixelColor(36, pixels.Color(15, 15, 15));
  pixels.setPixelColor(38, pixels.Color(15, 15, 15));
  pixels.setPixelColor(41, pixels.Color(15, 15, 15));
  pixels.setPixelColor(43, pixels.Color(15, 15, 15));
  pixels.setPixelColor(47, pixels.Color(15, 15, 15));
  pixels.setPixelColor(49, pixels.Color(15, 15, 15));
  pixels.setPixelColor(50, pixels.Color(15, 15, 15));
  pixels.setPixelColor(53, pixels.Color(15, 15, 15));
  pixels.setPixelColor(55, pixels.Color(15, 15, 15));
  pixels.setPixelColor(58, pixels.Color(15, 15, 15));
  pixels.setPixelColor(61, pixels.Color(15, 15, 15));
  pixels.setPixelColor(64, pixels.Color(15, 15, 15));
  pixels.setPixelColor(66, pixels.Color(15, 15, 15));
  pixels.setPixelColor(69, pixels.Color(15, 15, 15));
  pixels.setPixelColor(70, pixels.Color(15, 15, 15));
  pixels.setPixelColor(74, pixels.Color(15, 15, 15));
  pixels.setPixelColor(79, pixels.Color(15, 15, 15));
  nextFrame();

  /*Frame 41*/
  pixels.setPixelColor(21, pixels.Color(15, 15, 15));
  pixels.setPixelColor(25, pixels.Color(15, 15, 15));
  pixels.setPixelColor(27, pixels.Color(15, 15, 15));
  pixels.setPixelColor(28, pixels.Color(15, 15, 15));
  pixels.setPixelColor(29, pixels.Color(15, 15, 15));
  pixels.setPixelColor(32, pixels.Color(15, 15, 15));
  pixels.setPixelColor(34, pixels.Color(15, 15, 15));
  pixels.setPixelColor(38, pixels.Color(15, 15, 15));
  pixels.setPixelColor(41, pixels.Color(15, 15, 15));
  pixels.setPixelColor(45, pixels.Color(15, 15, 15));
  pixels.setPixelColor(47, pixels.Color(15, 15, 15));
  pixels.setPixelColor(48, pixels.Color(15, 15, 15));
  pixels.setPixelColor(49, pixels.Color(15, 15, 15));
  pixels.setPixelColor(52, pixels.Color(15, 15, 15));
  pixels.setPixelColor(55, pixels.Color(15, 15, 15));
  pixels.setPixelColor(57, pixels.Color(15, 15, 15));
  pixels.setPixelColor(62, pixels.Color(15, 15, 15));
  pixels.setPixelColor(64, pixels.Color(15, 15, 15));
  pixels.setPixelColor(67, pixels.Color(15, 15, 15));
  pixels.setPixelColor(70, pixels.Color(15, 15, 15));
  pixels.setPixelColor(71, pixels.Color(15, 15, 15));
  pixels.setPixelColor(72, pixels.Color(15, 15, 15));
  pixels.setPixelColor(76, pixels.Color(15, 15, 15));
  nextFrame();

  /*Frame 43*/
  pixels.setPixelColor(23, pixels.Color(15, 15, 15));
  pixels.setPixelColor(25, pixels.Color(15, 15, 15));
  pixels.setPixelColor(26, pixels.Color(15, 15, 15));
  pixels.setPixelColor(27, pixels.Color(15, 15, 15));
  pixels.setPixelColor(28, pixels.Color(15, 15, 15));
  pixels.setPixelColor(34, pixels.Color(15, 15, 15));
  pixels.setPixelColor(36, pixels.Color(15, 15, 15));
  pixels.setPixelColor(43, pixels.Color(15, 15, 15));
  pixels.setPixelColor(45, pixels.Color(15, 15, 15));
  pixels.setPixelColor(46, pixels.Color(15, 15, 15));
  pixels.setPixelColor(47, pixels.Color(15, 15, 15));
  pixels.setPixelColor(54, pixels.Color(15, 15, 15));
  pixels.setPixelColor(57, pixels.Color(15, 15, 15));
  pixels.setPixelColor(59, pixels.Color(15, 15, 15));
  pixels.setPixelColor(60, pixels.Color(15, 15, 15));
  pixels.setPixelColor(62, pixels.Color(15, 15, 15));
  pixels.setPixelColor(65, pixels.Color(15, 15, 15));
  pixels.setPixelColor(71, pixels.Color(15, 15, 15));
  pixels.setPixelColor(72, pixels.Color(15, 15, 15));
  pixels.setPixelColor(73, pixels.Color(15, 15, 15));
  pixels.setPixelColor(74, pixels.Color(15, 15, 15));
  pixels.setPixelColor(78, pixels.Color(15, 15, 15));
  nextFrame();

  /*Frame 45*/
  pixels.setPixelColor(21, pixels.Color(15, 15, 15));
  pixels.setPixelColor(23, pixels.Color(15, 15, 15));
  pixels.setPixelColor(24, pixels.Color(15, 15, 15));
  pixels.setPixelColor(25, pixels.Color(15, 15, 15));
  pixels.setPixelColor(26, pixels.Color(15, 15, 15));
  pixels.setPixelColor(28, pixels.Color(15, 15, 15));
  pixels.setPixelColor(29, pixels.Color(15, 15, 15));
  pixels.setPixelColor(31, pixels.Color(15, 15, 15));
  pixels.setPixelColor(36, pixels.Color(15, 15, 15));
  pixels.setPixelColor(38, pixels.Color(15, 15, 15));
  pixels.setPixelColor(41, pixels.Color(15, 15, 15));
  pixels.setPixelColor(43, pixels.Color(15, 15, 15));
  pixels.setPixelColor(44, pixels.Color(15, 15, 15));
  pixels.setPixelColor(45, pixels.Color(15, 15, 15));
  pixels.setPixelColor(48, pixels.Color(15, 15, 15));
  pixels.setPixelColor(50, pixels.Color(15, 15, 15));
  pixels.setPixelColor(51, pixels.Color(15, 15, 15));
  pixels.setPixelColor(56, pixels.Color(15, 15, 15));
  pixels.setPixelColor(59, pixels.Color(15, 15, 15));
  pixels.setPixelColor(60, pixels.Color(15, 15, 15));
  pixels.setPixelColor(63, pixels.Color(15, 15, 15));
  pixels.setPixelColor(68, pixels.Color(15, 15, 15));
  pixels.setPixelColor(71, pixels.Color(15, 15, 15));
  pixels.setPixelColor(73, pixels.Color(15, 15, 15));
  pixels.setPixelColor(74, pixels.Color(15, 15, 15));
  pixels.setPixelColor(75, pixels.Color(15, 15, 15));
  pixels.setPixelColor(76, pixels.Color(15, 15, 15));
  nextFrame();

  /*Frame 47*/
  pixels.setPixelColor(21, pixels.Color(15, 15, 15));
  pixels.setPixelColor(22, pixels.Color(15, 15, 15));
  pixels.setPixelColor(23, pixels.Color(15, 15, 15));
  pixels.setPixelColor(24, pixels.Color(15, 15, 15));
  pixels.setPixelColor(26, pixels.Color(15, 15, 15));
  pixels.setPixelColor(27, pixels.Color(15, 15, 15));
  pixels.setPixelColor(28, pixels.Color(15, 15, 15));
  pixels.setPixelColor(29, pixels.Color(15, 15, 15));
  pixels.setPixelColor(33, pixels.Color(15, 15, 15));
  pixels.setPixelColor(38, pixels.Color(15, 15, 15));
  pixels.setPixelColor(41, pixels.Color(15, 15, 15));
  pixels.setPixelColor(42, pixels.Color(15, 15, 15));
  pixels.setPixelColor(43, pixels.Color(15, 15, 15));
  pixels.setPixelColor(46, pixels.Color(15, 15, 15));
  pixels.setPixelColor(50, pixels.Color(15, 15, 15));
  pixels.setPixelColor(51, pixels.Color(15, 15, 15));
  pixels.setPixelColor(52, pixels.Color(15, 15, 15));
  pixels.setPixelColor(53, pixels.Color(15, 15, 15));
  pixels.setPixelColor(58, pixels.Color(15, 15, 15));
  pixels.setPixelColor(61, pixels.Color(15, 15, 15));
  pixels.setPixelColor(66, pixels.Color(15, 15, 15));
  pixels.setPixelColor(73, pixels.Color(15, 15, 15));
  pixels.setPixelColor(75, pixels.Color(15, 15, 15));
  pixels.setPixelColor(76, pixels.Color(15, 15, 15));
  pixels.setPixelColor(77, pixels.Color(15, 15, 15));
  pixels.setPixelColor(78, pixels.Color(15, 15, 15));
  nextFrame();

  /*Frame 49*/
  pixels.setPixelColor(20, pixels.Color(15, 15, 15));
  pixels.setPixelColor(21, pixels.Color(15, 15, 15));
  pixels.setPixelColor(22, pixels.Color(15, 15, 15));
  pixels.setPixelColor(24, pixels.Color(15, 15, 15));
  pixels.setPixelColor(25, pixels.Color(15, 15, 15));
  pixels.setPixelColor(26, pixels.Color(15, 15, 15));
  pixels.setPixelColor(27, pixels.Color(15, 15, 15));
  pixels.setPixelColor(31, pixels.Color(15, 15, 15));
  pixels.setPixelColor(35, pixels.Color(15, 15, 15));
  pixels.setPixelColor(40, pixels.Color(15, 15, 15));
  pixels.setPixelColor(41, pixels.Color(15, 15, 15));
  pixels.setPixelColor(44, pixels.Color(15, 15, 15));
  pixels.setPixelColor(48, pixels.Color(15, 15, 15));
  pixels.setPixelColor(52, pixels.Color(15, 15, 15));
  pixels.setPixelColor(53, pixels.Color(15, 15, 15));
  pixels.setPixelColor(54, pixels.Color(15, 15, 15));
  pixels.setPixelColor(55, pixels.Color(15, 15, 15));
  pixels.setPixelColor(64, pixels.Color(15, 15, 15));
  pixels.setPixelColor(68, pixels.Color(15, 15, 15));
  pixels.setPixelColor(71, pixels.Color(15, 15, 15));
  pixels.setPixelColor(75, pixels.Color(15, 15, 15));
  pixels.setPixelColor(77, pixels.Color(15, 15, 15));
  pixels.setPixelColor(78, pixels.Color(15, 15, 15));
  pixels.setPixelColor(79, pixels.Color(15, 15, 15));
  nextFrame();

  /*Frame 51*/
  pixels.setPixelColor(20, pixels.Color(15, 15, 15));
  pixels.setPixelColor(22, pixels.Color(15, 15, 15));
  pixels.setPixelColor(23, pixels.Color(15, 15, 15));
  pixels.setPixelColor(24, pixels.Color(15, 15, 15));
  pixels.setPixelColor(25, pixels.Color(15, 15, 15));
  pixels.setPixelColor(33, pixels.Color(15, 15, 15));
  pixels.setPixelColor(37, pixels.Color(15, 15, 15));
  pixels.setPixelColor(42, pixels.Color(15, 15, 15));
  pixels.setPixelColor(46, pixels.Color(15, 15, 15));
  pixels.setPixelColor(54, pixels.Color(15, 15, 15));
  pixels.setPixelColor(55, pixels.Color(15, 15, 15));
  pixels.setPixelColor(56, pixels.Color(15, 15, 15));
  pixels.setPixelColor(57, pixels.Color(15, 15, 15));
  pixels.setPixelColor(62, pixels.Color(15, 15, 15));
  pixels.setPixelColor(66, pixels.Color(15, 15, 15));
  pixels.setPixelColor(73, pixels.Color(15, 15, 15));
  pixels.setPixelColor(77, pixels.Color(15, 15, 15));
  pixels.setPixelColor(79, pixels.Color(15, 15, 15));
  nextFrame();

  /*Frame 53*/
  pixels.setPixelColor(20, pixels.Color(15, 15, 15));
  pixels.setPixelColor(21, pixels.Color(15, 15, 15));
  pixels.setPixelColor(22, pixels.Color(15, 15, 15));
  pixels.setPixelColor(23, pixels.Color(15, 15, 15));
  pixels.setPixelColor(35, pixels.Color(15, 15, 15));
  pixels.setPixelColor(39, pixels.Color(15, 15, 15));
  pixels.setPixelColor(40, pixels.Color(15, 15, 15));
  pixels.setPixelColor(44, pixels.Color(15, 15, 15));
  pixels.setPixelColor(56, pixels.Color(15, 15, 15));
  pixels.setPixelColor(57, pixels.Color(15, 15, 15));
  pixels.setPixelColor(58, pixels.Color(15, 15, 15));
  pixels.setPixelColor(59, pixels.Color(15, 15, 15));
  pixels.setPixelColor(60, pixels.Color(15, 15, 15));
  pixels.setPixelColor(64, pixels.Color(15, 15, 15));
  pixels.setPixelColor(75, pixels.Color(15, 15, 15));
  pixels.setPixelColor(79, pixels.Color(15, 15, 15));
  nextFrame();

  /*Frame 55*/
  pixels.setPixelColor(20, pixels.Color(15, 15, 15));
  pixels.setPixelColor(21, pixels.Color(15, 15, 15));
  pixels.setPixelColor(37, pixels.Color(15, 15, 15));
  pixels.setPixelColor(42, pixels.Color(15, 15, 15));
  pixels.setPixelColor(58, pixels.Color(15, 15, 15));
  pixels.setPixelColor(59, pixels.Color(15, 15, 15));
  pixels.setPixelColor(62, pixels.Color(15, 15, 15));
  pixels.setPixelColor(77, pixels.Color(15, 15, 15));
  nextFrame();

  /*Frame 57*/
  pixels.setPixelColor(39, pixels.Color(15, 15, 15));
  pixels.setPixelColor(40, pixels.Color(15, 15, 15));
  pixels.setPixelColor(60, pixels.Color(15, 15, 15));
  pixels.setPixelColor(79, pixels.Color(15, 15, 15));
  nextFrame();

  pixels.show();
}
