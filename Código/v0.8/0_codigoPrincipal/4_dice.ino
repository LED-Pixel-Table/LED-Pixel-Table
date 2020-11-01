int diceface = 0;

int one[29]   = {11, 12, 13, 14, 15, 16, 17, 21, 29, 30, 38, 41, 49, 50, 54, 58, 61, 69, 70, 78, 81, 89, 91, 92, 93, 94, 95, 96, 97};
int two[30]   = {11, 12, 13, 14, 15, 16, 17, 21, 29, 30, 36, 38, 41, 49, 50, 58, 61, 69, 70, 72, 78, 81, 89, 91, 92, 93, 94, 95, 96, 97};
int three[31] = {11, 12, 13, 14, 15, 16, 17, 21, 29, 30, 36, 38, 41, 49, 50, 54, 58, 61, 69, 70, 72, 78, 81, 89, 91, 92, 93, 94, 95, 96, 97};
int four[32]  = {11, 12, 13, 14, 15, 16, 17, 21, 29, 30, 32, 36, 38, 41, 49, 50, 58, 61, 69, 70, 72, 76, 78, 81, 89, 91, 92, 93, 94, 95, 96, 97};
int five[33]  = {11, 12, 13, 14, 15, 16, 17, 21, 29, 30, 32, 36, 38, 41, 49, 50, 54, 58, 61, 69, 70, 72, 76, 78, 81, 89, 91, 92, 93, 94, 95, 96, 97};
int six[34]   = {11, 12, 13, 14, 15, 16, 17, 21, 29, 30, 32, 36, 38, 41, 49, 50, 52, 56, 58, 61, 69, 70, 72, 76, 78, 81, 89, 91, 92, 93, 94, 95, 96, 97};


void runDice() {
  boolean diceRunning = true;
  unsigned long prevUpdateTime = 0;

  while (diceRunning) {
    if (diceface == 1) {
      for (int i = 0; i < 29; i++) {
        pixels.setPixelColor(one[i], pixels.Color(15, 0, 0));
        diceface = 0;
      }
    }
    else if (diceface == 2) {
      for (int i = 0; i < 30; i++) {
        pixels.setPixelColor(two[i], pixels.Color(15, 0, 0));
        diceface = 0;
      }
    }
    else if (diceface == 3) {
      for (int i = 0; i < 31; i++) {
        pixels.setPixelColor(three[i], pixels.Color(15, 0, 0));
        diceface = 0;
      }
    }
    else if (diceface == 4) {
      for (int i = 0; i < 32; i++) {
        pixels.setPixelColor(four[i], pixels.Color(15, 0, 0));
        diceface = 0;
      }
    }
    else if (diceface == 5) {
      for (int i = 0; i < 33; i++) {
        pixels.setPixelColor(five[i], pixels.Color(15, 0, 0));
        diceface = 0;
      }
    }
    else if (diceface == 6) {
      for (int i = 0; i < 34; i++) {
        pixels.setPixelColor(six[i], pixels.Color(15, 0, 0));
        diceface = 0;
      }
    }

    pixels.show();
    delay(2500);
    clearTablePixels();

    unsigned long curTime;
    do {
      readInput();
      if (curControl == BTN_EXIT) {
        diceRunning = false;
        break;
      }
      if (curControl != BTN_NONE) { 
        diceface = random(1, 7);
        break;
      }
      curTime = millis();
    }
    while ((curTime - prevUpdateTime) < 250); 
    prevUpdateTime = curTime;
    curControl = BTN_NONE;
  }
}
