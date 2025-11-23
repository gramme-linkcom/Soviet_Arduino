const int buzzer = ;// ここに同志のArduinoマイコン上に繋がれたる圧電スピーカーのピン番号を共有せよ！

// ――― 音階（ドレミの周波数表） ―――
#define C4  262  // ド
#define D4  294  // レ
#define E4  330  // ミ
#define F4  349  // ファ
#define G4  392  // ソ
#define A4  440  // ラ
#define B4  494  // シ
#define C5  523  // ド
#define D5  587  // レ
#define E5	659  // ミ
#define F5  698  // ファ

#define REST 0

int melody[] = {
  G4, 
  C5, G4, A4,
  B4, E4, E4, REST,
  A4, G4, F4,
  G4, C4,
  D4, D4, E4,
  F4, F4, G4,
  A4, B4, C5,
  D5, REST,
  
  E5, D5, C5,
  D5, B4, G4,
  C5, B4, A4,
  B4, E4, E4,
  A4, G4, F4,
  G4, C4, C4,
  C5, B4, A4,
  G4, REST,

  E5, D5, C5, B4, C5,
  D5, G4, G4, REST,
  C5, B4, A4, G4, A4,
  B4, E4, E4, REST,

  C5, A4, B4,
  C5, A4, B4,
  C5, A4, C5,
  F5, REST,

  F5, E5, D5, C5, D5,
  E5, C5, C5, REST,
  D5, C5, B4, A4, B4,
  C5, A4, A4, REST,

  C5, B4, A4,
  G4, C4, C4,
  C5, B4, A4,
  G4, REST,
};

// 音の長さ
int duration[] = {
  400, 
  800, 500, 200,
  800, 400, 200, 200,
  800, 500, 200,
  800, 800,
  800, 500, 200,
  800, 500, 200,
  800, 400, 400,
  800, 800,
  
  800, 500, 200,
  800, 400, 400,
  800, 500, 200,
  800, 400, 400,
  800, 500, 200,
  800, 400, 400,
  800, 500, 200,
  800, 800,

  1600, 400, 400, 400, 400,
  1200, 400, 1200, 800,
  1600, 400, 400, 400, 400,
  1200, 400, 1200, 800,

  800, 500, 200,
  800, 500, 200,
  800, 500, 200,
  1200, 400,

  1600, 400, 400, 400, 400,
  1200, 400, 1200, 400,
  1600, 400, 400, 400, 400,
  1200, 400, 1200, 400,

  800, 500, 200,
  800, 500, 200,
  800, 500, 200,
  1200, 800,
};

int count = sizeof(melody) / sizeof(melody[0]);

void setup() {}

void loop() {
  for (int i = 0; i < count; i++) {
    if (melody[i] == REST) {
      delay(duration[i]);
    } else {
      tone(buzzer, melody[i], duration[i]);
      delay(duration[i] + 50);
    }
  }
  delay(1500);
}
