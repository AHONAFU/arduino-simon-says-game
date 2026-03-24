#define green 7         //1
#define red 6           //2
#define blue 5          //3
#define green_Button 2  //1
#define red_Button 3    //2
#define blue_Button 4   //3
#define buzzer 8

#define A 10
#define B 9
#define F 11
#define G 12
#define C A5
#define D A4
#define E A3

const int segmentPins[] = { 10, 9, A5, A4, A3, 11, 12 };

const int digits[10][7] = {
  { 1, 1, 1, 1, 1, 1, 0 },  // 0
  { 0, 1, 1, 0, 0, 0, 0 },  // 1
  { 1, 1, 0, 1, 1, 0, 1 },  // 2
  { 1, 1, 1, 1, 0, 0, 1 },  // 3
  { 0, 1, 1, 0, 0, 1, 1 },  // 4
  { 1, 0, 1, 1, 0, 1, 1 },  // 5
  { 1, 0, 1, 1, 1, 1, 1 },  // 6
  { 1, 1, 1, 0, 0, 0, 0 },  // 7
  { 1, 1, 1, 1, 1, 1, 1 },  // 8
  { 1, 1, 1, 1, 0, 1, 1 }   // 9
};

int ledPin[] = { 7, 6, 5 };
int butPin[] = { 2, 3, 4 };


void setup() {
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);

  pinMode(green_Button, INPUT);
  pinMode(red_Button, INPUT);
  pinMode(blue_Button, INPUT);

  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }

  randomSeed(analogRead(0));
}

void winDance() {
  for (int repeat = 0; repeat < 3; repeat++) {
    digitalWrite(green, HIGH);
    delay(150);
    digitalWrite(green, LOW);
    delay(50);
  }
  delay(1000);
}

void loseDance() {
  for (int repeat = 0; repeat < 3; repeat++) {
    digitalWrite(red, HIGH);
    tone(buzzer, 400, 150);
    delay(150);
    digitalWrite(red, LOW);
    delay(50);
  }
  delay(1000);
}
int game_mech(int stage) {
  int rand_arr[3 + stage];
  int reply[3 + stage];

  //generate the random number set
  for (int i = 0; i < 3 + stage; i++) {
    int rand_num = random(0, 3);
    rand_arr[i] = rand_num;

    digitalWrite(ledPin[rand_arr[i]], HIGH);
    delay(500);
    digitalWrite(ledPin[rand_arr[i]], LOW);
    delay(50);
  }

  //user reply
  for (int j = 0; j < 3 + stage; j++) {
    bool waiting = true;

    while (waiting) {
      if (digitalRead(green_Button) == LOW) {
        digitalWrite(green, HIGH);
        delay(500);
        digitalWrite(green, LOW);
        delay(50);
        reply[j] = 0;
        waiting = false;
      } else if (digitalRead(red_Button) == LOW) {
        digitalWrite(red, HIGH);
        delay(500);
        digitalWrite(red, LOW);
        delay(50);
        reply[j] = 1;
        waiting = false;
      } else if (digitalRead(blue_Button) == LOW) {
        digitalWrite(blue, HIGH);
        delay(500);
        digitalWrite(blue, LOW);
        delay(50);
        reply[j] = 2;
        waiting = false;
      }
    }

    delay(100);
  }

  int winState = 0;

  for (int k = 0; k < 3 + stage; k++) {
    if (reply[k] == rand_arr[k])
      winState = 1;
    else {
      winState = 0;
      break;
    }
  }

  return winState;
}

int high_score(int stage) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], digits[stage][i]);
  }
}

void startDance() {
  // Chase forward
  for (int repeat = 0; repeat < 2; repeat++) {
    for (int i = 0; i < 3; i++) {
      digitalWrite(ledPin[i], HIGH);
      delay(100);
      digitalWrite(ledPin[i], LOW);
      delay(50);
    }
  }

  // Chase backward
  for (int repeat = 0; repeat < 2; repeat++) {
    for (int i = 2; i >= 0; i--) {
      digitalWrite(ledPin[i], HIGH);
      delay(100);
      digitalWrite(ledPin[i], LOW);
      delay(50);
    }
  }

  // All blink together
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) digitalWrite(ledPin[j], HIGH);
    delay(150);
    for (int j = 0; j < 3; j++) digitalWrite(ledPin[j], LOW);
    delay(150);
  }
}

void loop() {
  int stage = 0;


  while (1) {
    high_score(stage);
    int winState = game_mech(stage);

    if (winState == 1) {
      winDance();
      stage = stage + 1;
    } else {
      loseDance();
      digitalWrite(green, HIGH);
      digitalWrite(red, HIGH);

      bool restart = true;
      while (restart) {
        if (digitalRead(green_Button) == LOW) {
          digitalWrite(green, LOW);
          digitalWrite(red, LOW);
          delay(1000);
          loop();
          restart = false;
        } else if (digitalRead(red_Button) == LOW) {
          digitalWrite(green, LOW);
          digitalWrite(red, LOW);
          restart = false;
          startDance();
        }
      }
    }
  }
}
