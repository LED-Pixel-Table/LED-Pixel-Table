int x_zero[10] = {27, 31, 33, 46, 48, 51, 53, 66, 68, 72};
int x_one[9] = {27, 32, 33, 47, 52, 67, 71, 72, 73};
int x_two[9] = {26, 27, 31, 48, 52, 66, 71, 72, 73};
int x_three[8] = {26, 27, 31, 47, 51, 68, 72, 73};
int x_four[10] = {26, 31, 33, 46, 48, 51, 52, 53, 68, 71};
int x_five[10] = {26, 27, 28, 33, 46, 47, 51, 68, 72, 73};
int x_six[11] = {27, 28, 33, 46, 47, 51, 53, 66, 68, 71, 72};
int x_seven[8] = {26, 27, 28, 31, 48, 52, 67, 72};
int x_eight[9] = {27, 31, 33, 47, 51, 53, 66, 68, 72};
int x_nine[11] = {26, 27, 31, 33, 46, 48, 51, 52, 68, 72, 73};

int zero_x[10] = {22, 36, 38, 41, 43, 56, 58, 61, 63, 77};
int one_x[9] = {22, 37, 38, 42, 57, 62, 76, 77, 78};
int two_x[9] = {21, 22, 36, 43, 57, 61, 76, 77, 78};
int three_x[8] = {21, 22, 36, 42, 56, 63, 77, 78};
int four_x[10] = {21, 36, 37, 41, 43, 56, 57, 58, 63, 76};
int five_x[10] = {21, 22, 23, 38, 41, 42, 56, 63, 77, 78};
int six_x[11] = {22, 23, 38, 41, 42, 56, 58, 61, 63, 76, 77};
int seven_x[8] = {21, 22, 23, 36, 43, 57, 62, 77};
int eight_x[9] = {22, 36, 38, 42, 56, 58, 61, 63, 77};
int nine_x[11] = {21, 22, 36, 38, 41, 43, 56, 57, 63, 77, 78};

void paintNumbers(int number[], int r, int g, int b) {
  if (number == zero_x || number == x_zero) {
    for (int i = 0; i < 10; i++) {
      pixels.setPixelColor(number[i], pixels.Color(r, g, b));
    }
  }
  else if (number == one_x || number == x_one) {
    for (int i = 0; i < 9; i++) {
      pixels.setPixelColor(number[i], pixels.Color(r, g, b));
    }
  }
  else if (number == two_x || number == x_two) {
    for (int i = 0; i < 9; i++) {
      pixels.setPixelColor(number[i], pixels.Color(r, g, b));
    }
  }
  else if (number == three_x || number == x_three) {
    for (int i = 0; i < 8; i++) {
      pixels.setPixelColor(number[i], pixels.Color(r, g, b));
    }
  }
  else if (number == four_x || number == x_four) {
    for (int i = 0; i < 10; i++) {
      pixels.setPixelColor(number[i], pixels.Color(r, g, b));
    }
  }
  else if (number == five_x || number == x_five) {
    for (int i = 0; i < 10; i++) {
      pixels.setPixelColor(number[i], pixels.Color(r, g, b));
    }
  }
  else if (number == six_x || number == x_six) {
    for (int i = 0; i < 11; i++) {
      pixels.setPixelColor(number[i], pixels.Color(r, g, b));
    }
  }
  else if (number == seven_x || number == x_seven) {
    for (int i = 0; i < 8; i++) {
      pixels.setPixelColor(number[i], pixels.Color(r, g, b));
    }
  }
  else if (number == eight_x || number == x_eight) {
    for (int i = 0; i < 9; i++) {
      pixels.setPixelColor(number[i], pixels.Color(r, g, b));
    }
  }
  else if (number == nine_x || number == x_nine) {
    for (int i = 0; i < 11; i++) {
      pixels.setPixelColor(number[i], pixels.Color(r, g, b));
    }
  }
}

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
    genericGameOverAnim();
    genericScoreAnim(scoreSnake, 0, 15, 0);
    pixels.show();
    delay(2500);
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
    genericGameOverAnim();
    pongScoreAnim();
    pixels.show();
    delay(2500);
    mainMenu();
  }
  else if (game == 3) {
    for (int i = 0; i < 4; i++) {
      setTablePixel(ballbx, ballby, 15, 15, 15);
      for (int i = 0; i < FIELD_WIDTH; i++) {
        if (lrojos[i] != 255) {
          setTablePixel(lrojos[i], 0, 15, 0, 0);
        }
        if (lnaranjas[i] != 255) {
          setTablePixel(lnaranjas[i], 1, 15, 7, 0);
        }
        if (lamarillos[i] != 255) {
          setTablePixel(lamarillos[i], 2, 15, 15, 0);
        }
        if (lverdes[i] != 255) {
          setTablePixel(lverdes[i], 3, 7, 15, 0);
        }
        if (lazules[i] != 255) {
          setTablePixel(lazules[i], 4, 0, 7, 15);
        }
      }
      for (int i = posPlayer - 1; i <= posPlayer + 1; i++) {
        setTablePixel(i, 9, 15, 15, 15);
      }
      pixels.show();
      clearTablePixels();
      delay(500);
      pixels.show();
      delay(500);
    }
    genericGameOverAnim();
    genericScoreAnim(scoreBreakout, 15, 15, 15);
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

void genericScoreAnim(int score, int r, int g, int b) {
  switch (score) {
    case 0:
      paintNumbers(zero_x, r, g, b);
      paintNumbers(x_zero, r, g, b);
      break;
    case 1:
      paintNumbers(zero_x, r, g, b);
      paintNumbers(x_one, r, g, b);
      break;
    case 2:
      paintNumbers(zero_x, r, g, b);
      paintNumbers(x_two, r, g, b);
      break;
    case 3:
      paintNumbers(zero_x, r, g, b);
      paintNumbers(x_three, r, g, b);
      break;
    case 4:
      paintNumbers(zero_x, r, g, b);
      paintNumbers(x_four, r, g, b);
      break;
    case 5:
      paintNumbers(zero_x, r, g, b);
      paintNumbers(x_five, r, g, b);
      break;
    case 6:
      paintNumbers(zero_x, r, g, b);
      paintNumbers(x_six, r, g, b);
      break;
    case 7:
      paintNumbers(zero_x, r, g, b);
      paintNumbers(x_seven, r, g, b);
      break;
    case 8:
      paintNumbers(zero_x, r, g, b);
      paintNumbers(x_eight, r, g, b);
      break;
    case 9:
      paintNumbers(zero_x, r, g, b);
      paintNumbers(x_nine, r, g, b);
      break;
    case 10:
      paintNumbers(one_x, r, g, b);
      paintNumbers(x_zero, r, g, b);
      break;
    case 11:
      paintNumbers(one_x, r, g, b);
      paintNumbers(x_one, r, g, b);
      break;
    case 12:
      paintNumbers(one_x, r, g, b);
      paintNumbers(x_two, r, g, b);
      break;
    case 13:
      paintNumbers(one_x, r, g, b);
      paintNumbers(x_three, r, g, b);
      break;
    case 14:
      paintNumbers(one_x, r, g, b);
      paintNumbers(x_four, r, g, b);
      break;
    case 15:
      paintNumbers(one_x, r, g, b);
      paintNumbers(x_five, r, g, b);
      break;
    case 16:
      paintNumbers(one_x, r, g, b);
      paintNumbers(x_six, r, g, b);
      break;
    case 17:
      paintNumbers(one_x, r, g, b);
      paintNumbers(x_seven, r, g, b);
      break;
    case 18:
      paintNumbers(one_x, r, g, b);
      paintNumbers(x_eight, r, g, b);
      break;
    case 19:
      paintNumbers(one_x, r, g, b);
      paintNumbers(x_nine, r, g, b);
      break;
    case 20:
      paintNumbers(two_x, r, g, b);
      paintNumbers(x_zero, r, g, b);
      break;
    case 21:
      paintNumbers(two_x, r, g, b);
      paintNumbers(x_one, r, g, b);
      break;
    case 22:
      paintNumbers(two_x, r, g, b);
      paintNumbers(x_two, r, g, b);
      break;
    case 23:
      paintNumbers(two_x, r, g, b);
      paintNumbers(x_three, r, g, b);
      break;
    case 24:
      paintNumbers(two_x, r, g, b);
      paintNumbers(x_four, r, g, b);
      break;
    case 25:
      paintNumbers(two_x, r, g, b);
      paintNumbers(x_five, r, g, b);
      break;
    case 26:
      paintNumbers(two_x, r, g, b);
      paintNumbers(x_six, r, g, b);
      break;
    case 27:
      paintNumbers(two_x, r, g, b);
      paintNumbers(x_seven, r, g, b);
      break;
    case 28:
      paintNumbers(two_x, r, g, b);
      paintNumbers(x_eight, r, g, b);
      break;
    case 29:
      paintNumbers(two_x, r, g, b);
      paintNumbers(x_nine, r, g, b);
      break;
    case 30:
      paintNumbers(three_x, r, g, b);
      paintNumbers(x_zero, r, g, b);
      break;
    case 31:
      paintNumbers(three_x, r, g, b);
      paintNumbers(x_one, r, g, b);
      break;
    case 32:
      paintNumbers(three_x, r, g, b);
      paintNumbers(x_two, r, g, b);
      break;
    case 33:
      paintNumbers(three_x, r, g, b);
      paintNumbers(x_three, r, g, b);
      break;
    case 34:
      paintNumbers(three_x, r, g, b);
      paintNumbers(x_four, r, g, b);
      break;
    case 35:
      paintNumbers(three_x, r, g, b);
      paintNumbers(x_five, r, g, b);
      break;
    case 36:
      paintNumbers(three_x, r, g, b);
      paintNumbers(x_six, r, g, b);
      break;
    case 37:
      paintNumbers(three_x, r, g, b);
      paintNumbers(x_seven, r, g, b);
      break;
    case 38:
      paintNumbers(three_x, r, g, b);
      paintNumbers(x_eight, r, g, b);
      break;
    case 39:
      paintNumbers(three_x, r, g, b);
      paintNumbers(x_nine, r, g, b);
      break;
    case 40:
      paintNumbers(four_x, r, g, b);
      paintNumbers(x_zero, r, g, b);
      break;
    case 41:
      paintNumbers(four_x, r, g, b);
      paintNumbers(x_one, r, g, b);
      break;
    case 42:
      paintNumbers(four_x, r, g, b);
      paintNumbers(x_two, r, g, b);
      break;
    case 43:
      paintNumbers(four_x, r, g, b);
      paintNumbers(x_three, r, g, b);
      break;
    case 44:
      paintNumbers(four_x, r, g, b);
      paintNumbers(x_four, r, g, b);
      break;
    case 45:
      paintNumbers(four_x, r, g, b);
      paintNumbers(x_five, r, g, b);
      break;
    case 46:
      paintNumbers(four_x, r, g, b);
      paintNumbers(x_six, r, g, b);
      break;
    case 47:
      paintNumbers(four_x, r, g, b);
      paintNumbers(x_seven, r, g, b);
      break;
    case 48:
      paintNumbers(four_x, r, g, b);
      paintNumbers(x_eight, r, g, b);
      break;
    case 49:
      paintNumbers(four_x, r, g, b);
      paintNumbers(x_nine, r, g, b);
      break;
    case 50:
      paintNumbers(five_x, r, g, b);
      paintNumbers(x_zero, r, g, b);
      break;
    case 51:
      paintNumbers(five_x, r, g, b);
      paintNumbers(x_one, r, g, b);
      break;
    case 52:
      paintNumbers(five_x, r, g, b);
      paintNumbers(x_two, r, g, b);
      break;
    case 53:
      paintNumbers(five_x, r, g, b);
      paintNumbers(x_three, r, g, b);
      break;
    case 54:
      paintNumbers(five_x, r, g, b);
      paintNumbers(x_four, r, g, b);
      break;
    case 55:
      paintNumbers(five_x, r, g, b);
      paintNumbers(x_five, r, g, b);
      break;
    case 56:
      paintNumbers(five_x, r, g, b);
      paintNumbers(x_six, r, g, b);
      break;
    case 57:
      paintNumbers(five_x, r, g, b);
      paintNumbers(x_seven, r, g, b);
      break;
    case 58:
      paintNumbers(five_x, r, g, b);
      paintNumbers(x_eight, r, g, b);
      break;
    case 59:
      paintNumbers(five_x, r, g, b);
      paintNumbers(x_nine, r, g, b);
      break;
    case 60:
      paintNumbers(six_x, r, g, b);
      paintNumbers(x_zero, r, g, b);
      break;
    case 61:
      paintNumbers(six_x, r, g, b);
      paintNumbers(x_one, r, g, b);
      break;
    case 62:
      paintNumbers(six_x, r, g, b);
      paintNumbers(x_two, r, g, b);
      break;
    case 63:
      paintNumbers(six_x, r, g, b);
      paintNumbers(x_three, r, g, b);
      break;
    case 64:
      paintNumbers(six_x, r, g, b);
      paintNumbers(x_four, r, g, b);
      break;
    case 65:
      paintNumbers(six_x, r, g, b);
      paintNumbers(x_five, r, g, b);
      break;
    case 66:
      paintNumbers(six_x, r, g, b);
      paintNumbers(x_six, r, g, b);
      break;
    case 67:
      paintNumbers(six_x, r, g, b);
      paintNumbers(x_seven, r, g, b);
      break;
    case 68:
      paintNumbers(six_x, r, g, b);
      paintNumbers(x_eight, r, g, b);
      break;
    case 69:
      paintNumbers(six_x, r, g, b);
      paintNumbers(x_nine, r, g, b);
      break;
    case 70:
      paintNumbers(seven_x, r, g, b);
      paintNumbers(x_zero, r, g, b);
      break;
    case 71:
      paintNumbers(seven_x, r, g, b);
      paintNumbers(x_one, r, g, b);
      break;
    case 72:
      paintNumbers(seven_x, r, g, b);
      paintNumbers(x_two, r, g, b);
      break;
    case 73:
      paintNumbers(seven_x, r, g, b);
      paintNumbers(x_three, r, g, b);
      break;
    case 74:
      paintNumbers(seven_x, r, g, b);
      paintNumbers(x_four, r, g, b);
      break;
    case 75:
      paintNumbers(seven_x, r, g, b);
      paintNumbers(x_five, r, g, b);
      break;
    case 76:
      paintNumbers(seven_x, r, g, b);
      paintNumbers(x_six, r, g, b);
      break;
    case 77:
      paintNumbers(seven_x, r, g, b);
      paintNumbers(x_seven, r, g, b);
      break;
    case 78:
      paintNumbers(seven_x, r, g, b);
      paintNumbers(x_eight, r, g, b);
      break;
    case 79:
      paintNumbers(seven_x, r, g, b);
      paintNumbers(x_nine, r, g, b);
      break;
    case 80:
      paintNumbers(eight_x, r, g, b);
      paintNumbers(x_zero, r, g, b);
      break;
    case 81:
      paintNumbers(eight_x, r, g, b);
      paintNumbers(x_one, r, g, b);
      break;
    case 82:
      paintNumbers(eight_x, r, g, b);
      paintNumbers(x_two, r, g, b);
      break;
    case 83:
      paintNumbers(eight_x, r, g, b);
      paintNumbers(x_three, r, g, b);
      break;
    case 84:
      paintNumbers(eight_x, r, g, b);
      paintNumbers(x_four, r, g, b);
      break;
    case 85:
      paintNumbers(eight_x, r, g, b);
      paintNumbers(x_five, r, g, b);
      break;
    case 86:
      paintNumbers(eight_x, r, g, b);
      paintNumbers(x_six, r, g, b);
      break;
    case 87:
      paintNumbers(eight_x, r, g, b);
      paintNumbers(x_seven, r, g, b);
      break;
    case 88:
      paintNumbers(eight_x, r, g, b);
      paintNumbers(x_eight, r, g, b);
      break;
    case 89:
      paintNumbers(eight_x, r, g, b);
      paintNumbers(x_nine, r, g, b);
      break;
    case 90:
      paintNumbers(nine_x, r, g, b);
      paintNumbers(x_zero, r, g, b);
      break;
    case 91:
      paintNumbers(nine_x, r, g, b);
      paintNumbers(x_one, r, g, b);
      break;
    case 92:
      paintNumbers(nine_x, r, g, b);
      paintNumbers(x_two, r, g, b);
      break;
    case 93:
      paintNumbers(nine_x, r, g, b);
      paintNumbers(x_three, r, g, b);
      break;
    case 94:
      paintNumbers(nine_x, r, g, b);
      paintNumbers(x_four, r, g, b);
      break;
    case 95:
      paintNumbers(nine_x, r, g, b);
      paintNumbers(x_five, r, g, b);
      break;
    case 96:
      paintNumbers(nine_x, r, g, b);
      paintNumbers(x_six, r, g, b);
      break;
    case 97:
      paintNumbers(nine_x, r, g, b);
      paintNumbers(x_seven, r, g, b);
      break;
    case 98:
      paintNumbers(nine_x, r, g, b);
      paintNumbers(x_eight, r, g, b);
      break;
    case 99:
      paintNumbers(nine_x, r, g, b);
      paintNumbers(x_nine, r, g, b);
      break;
  }
}

void pongScoreAnim() {
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

void genericGameOverAnim() {
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
