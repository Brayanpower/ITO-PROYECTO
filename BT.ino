
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <ESP32Servo.h>
#include "Ultrasonic.h"

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0



// Cambiando esto, va mas rápido o lento. Cuanto mayor es el valor, más rápido va.
int tempo = 108;
//
//leds
int stcp_Pin = 18;
int shcp_Pin = 19;
int ds_Pin = 21;
// El pin donde se conecta el buzzer
int buzzer = 12;
int led = 14;
int led1 = 5;
// Se ponen las notas, seguidas de la duración.
// El número 4 es un cuarto de nota, 8 un octavo y 16 es 1/16
// los valores negativos son para marcar notas con puntillo

int melody[] = {

  // Jingle Bells,

  NOTE_E5, 8, NOTE_E5, 8, NOTE_E5, 4,
  NOTE_E5, 8, NOTE_E5, 8, NOTE_E5, 4,
  NOTE_E5, 8, NOTE_G5, 8, NOTE_C5, 8, NOTE_D5, 8,
  NOTE_E5, 2,
  NOTE_F5, 8, NOTE_F5, 8, NOTE_F5, 8, NOTE_F5, 8,
  NOTE_F5, 8, NOTE_E5, 8, NOTE_E5, 8, NOTE_E5, 16, NOTE_E5, 16,
  NOTE_E5, 8, NOTE_D5, 8, NOTE_D5, 8, NOTE_E5, 8,
  NOTE_D5, 4, NOTE_G5, 4,

  NOTE_E5, 8, NOTE_E5, 8, NOTE_E5, 4,
  NOTE_E5, 8, NOTE_E5, 8, NOTE_E5, 4,
  NOTE_E5, 8, NOTE_G5, 8, NOTE_C5, 8, NOTE_D5, 8,
  NOTE_E5, 2,
  NOTE_F5, 8, NOTE_F5, 8, NOTE_F5, 8, NOTE_F5, 8,
  NOTE_F5, 8, NOTE_E5, 8, NOTE_E5, 8, NOTE_E5, 16, NOTE_E5, 16,
  NOTE_E5, 8, NOTE_D5, 8, NOTE_D5, 8, NOTE_E5, 8,
  NOTE_D5, 4, NOTE_G5, 4,
  
  REST, 1,  //Para que no suene

  // Santa Claus is coming to town

  NOTE_G4, 8,
  NOTE_E4, 8, NOTE_F4, 8, NOTE_G4, 4, NOTE_G4, 4, NOTE_G4, 4,
  NOTE_A4, 8, NOTE_B4, 8, NOTE_C5, 4, NOTE_C5, 4, NOTE_C5, 4,
  NOTE_E4, 8, NOTE_F4, 8, NOTE_G4, 4, NOTE_G4, 4, NOTE_G4, 4,
  NOTE_A4, 8, NOTE_G4, 8, NOTE_F4, 4, NOTE_F4, 2,
  NOTE_E4, 4, NOTE_G4, 4, NOTE_C4, 4, NOTE_E4, 4,
  NOTE_D4, 4, NOTE_F4, 2, NOTE_B3, 4,
  NOTE_C4, 1,

  NOTE_G4, 8,
  NOTE_E4, 8, NOTE_F4, 8, NOTE_G4, 4, NOTE_G4, 4, NOTE_G4, 4,
  NOTE_A4, 8, NOTE_B4, 8, NOTE_C5, 4, NOTE_C5, 4, NOTE_C5, 4,
  NOTE_E4, 8, NOTE_F4, 8, NOTE_G4, 4, NOTE_G4, 4, NOTE_G4, 4,
  NOTE_A4, 8, NOTE_G4, 8, NOTE_F4, 4, NOTE_F4, 2,
  NOTE_E4, 4, NOTE_G4, 4, NOTE_C4, 4, NOTE_E4, 4,
  NOTE_D4, 4, NOTE_F4, 2, NOTE_B3, 4,
  NOTE_C4, 1,

  REST, 1, //Para que no suene
  
  // We Wish You a Merry Christmas

  NOTE_C5, 4, //1
  NOTE_F5, 4, NOTE_F5, 8, NOTE_G5, 8, NOTE_F5, 8, NOTE_E5, 8,
  NOTE_D5, 4, NOTE_D5, 4, NOTE_D5, 4,
  NOTE_G5, 4, NOTE_G5, 8, NOTE_A5, 8, NOTE_G5, 8, NOTE_F5, 8,
  NOTE_E5, 4, NOTE_C5, 4, NOTE_C5, 4,
  NOTE_A5, 4, NOTE_A5, 8, NOTE_AS5, 8, NOTE_A5, 8, NOTE_G5, 8,
  NOTE_F5, 4, NOTE_D5, 4, NOTE_C5, 8, NOTE_C5, 8,
  NOTE_D5, 4, NOTE_G5, 4, NOTE_E5, 4,

  NOTE_F5, 2, NOTE_C5, 4, //8
  NOTE_F5, 4, NOTE_F5, 8, NOTE_G5, 8, NOTE_F5, 8, NOTE_E5, 8,
  NOTE_D5, 4, NOTE_D5, 4, NOTE_D5, 4,
  NOTE_G5, 4, NOTE_G5, 8, NOTE_A5, 8, NOTE_G5, 8, NOTE_F5, 8,
  NOTE_E5, 4, NOTE_C5, 4, NOTE_C5, 4,
  NOTE_A5, 4, NOTE_A5, 8, NOTE_AS5, 8, NOTE_A5, 8, NOTE_G5, 8,
  NOTE_F5, 4, NOTE_D5, 4, NOTE_C5, 8, NOTE_C5, 8,
  NOTE_D5, 4, NOTE_G5, 4, NOTE_E5, 4,
  NOTE_F5, 2, NOTE_C5, 4,

  NOTE_F5, 4, NOTE_F5, 4, NOTE_F5, 4, //17
  NOTE_E5, 2, NOTE_E5, 4,
  NOTE_F5, 4, NOTE_E5, 4, NOTE_D5, 4,
  NOTE_C5, 2, NOTE_A5, 4,
  NOTE_AS5, 4, NOTE_A5, 4, NOTE_G5, 4,
  NOTE_C6, 4, NOTE_C5, 4, NOTE_C5, 8, NOTE_C5, 8,
  NOTE_D5, 4, NOTE_G5, 4, NOTE_E5, 4,
  NOTE_F5, 2, NOTE_C5, 4,
  NOTE_F5, 4, NOTE_F5, 8, NOTE_G5, 8, NOTE_F5, 8, NOTE_E5, 8,
  NOTE_D5, 4, NOTE_D5, 4, NOTE_D5, 4,

  NOTE_G5, 4, NOTE_G5, 8, NOTE_A5, 8, NOTE_G5, 8, NOTE_F5, 8, //27
  NOTE_E5, 4, NOTE_C5, 4, NOTE_C5, 4,
  NOTE_A5, 4, NOTE_A5, 8, NOTE_AS5, 8, NOTE_A5, 8, NOTE_G5, 8,
  NOTE_F5, 4, NOTE_D5, 4, NOTE_C5, 8, NOTE_C5, 8,
  NOTE_D5, 4, NOTE_G5, 4, NOTE_E5, 4,
  NOTE_F5, 2, NOTE_C5, 4,
  NOTE_F5, 4, NOTE_F5, 4, NOTE_F5, 4,
  NOTE_E5, 2, NOTE_E5, 4,
  NOTE_F5, 4, NOTE_E5, 4, NOTE_D5, 4,

  NOTE_C5, 2, NOTE_A5, 4, //36
  NOTE_AS5, 4, NOTE_A5, 4, NOTE_G5, 4,
  NOTE_C6, 4, NOTE_C5, 4, NOTE_C5, 8, NOTE_C5, 8,
  NOTE_D5, 4, NOTE_G5, 4, NOTE_E5, 4,
  NOTE_F5, 2, NOTE_C5, 4,
  NOTE_F5, 4, NOTE_F5, 8, NOTE_G5, 8, NOTE_F5, 8, NOTE_E5, 8,
  NOTE_D5, 4, NOTE_D5, 4, NOTE_D5, 4,
  NOTE_G5, 4, NOTE_G5, 8, NOTE_A5, 8, NOTE_G5, 8, NOTE_F5, 8,
  NOTE_E5, 4, NOTE_C5, 4, NOTE_C5, 4,

  NOTE_A5, 4, NOTE_A5, 8, NOTE_AS5, 8, NOTE_A5, 8, NOTE_G5, 8, //45
  NOTE_F5, 4, NOTE_D5, 4, NOTE_C5, 8, NOTE_C5, 8,
  NOTE_D5, 4, NOTE_G5, 4, NOTE_E5, 4,
  NOTE_F5, 2, NOTE_C5, 4,
  NOTE_F5, 4, NOTE_F5, 8, NOTE_G5, 8, NOTE_F5, 8, NOTE_E5, 8,
  NOTE_D5, 4, NOTE_D5, 4, NOTE_D5, 4,
  NOTE_G5, 4, NOTE_G5, 8, NOTE_A5, 8, NOTE_G5, 8, NOTE_F5, 8,
  NOTE_E5, 4, NOTE_C5, 4, NOTE_C5, 4,

  NOTE_A5, 4, NOTE_A5, 8, NOTE_AS5, 8, NOTE_A5, 8, NOTE_G5, 8, //53
  NOTE_F5, 4, NOTE_D5, 4, NOTE_C5, 8, NOTE_C5, 8,
  NOTE_D5, 4, NOTE_G5, 4, NOTE_E5, 4,
  NOTE_F5, 2,

  REST, 1, //Para que no suene

  // Jingle Bells,

  NOTE_E5, 8, NOTE_E5, 8, NOTE_E5, 4,
  NOTE_E5, 8, NOTE_E5, 8, NOTE_E5, 4,
  NOTE_E5, 8, NOTE_G5, 8, NOTE_C5, 8, NOTE_D5, 8,
  NOTE_E5, 2,
  NOTE_F5, 8, NOTE_F5, 8, NOTE_F5, 8, NOTE_F5, 8,
  NOTE_F5, 8, NOTE_E5, 8, NOTE_E5, 8, NOTE_E5, 16, NOTE_E5, 16,
  NOTE_E5, 8, NOTE_D5, 8, NOTE_D5, 8, NOTE_E5, 8,
  NOTE_D5, 4, NOTE_G5, 4,

  NOTE_E5, 8, NOTE_E5, 8, NOTE_E5, 4,
  NOTE_E5, 8, NOTE_E5, 8, NOTE_E5, 4,
  NOTE_E5, 8, NOTE_G5, 8, NOTE_C5, 8, NOTE_D5, 8,
  NOTE_E5, 2,
  NOTE_F5, 8, NOTE_F5, 8, NOTE_F5, 8, NOTE_F5, 8,
  NOTE_F5, 8, NOTE_E5, 8, NOTE_E5, 8, NOTE_E5, 16, NOTE_E5, 16,
  NOTE_E5, 8, NOTE_D5, 8, NOTE_D5, 8, NOTE_E5, 8,
  NOTE_D5, 4, NOTE_G5, 4,
  
  REST, 1, //Para que no suene

  // Santa Claus is coming to town

  NOTE_G4, 8,
  NOTE_E4, 8, NOTE_F4, 8, NOTE_G4, 4, NOTE_G4, 4, NOTE_G4, 4,
  NOTE_A4, 8, NOTE_B4, 8, NOTE_C5, 4, NOTE_C5, 4, NOTE_C5, 4,
  NOTE_E4, 8, NOTE_F4, 8, NOTE_G4, 4, NOTE_G4, 4, NOTE_G4, 4,
  NOTE_A4, 8, NOTE_G4, 8, NOTE_F4, 4, NOTE_F4, 2,
  NOTE_E4, 4, NOTE_G4, 4, NOTE_C4, 4, NOTE_E4, 4,
  NOTE_D4, 4, NOTE_F4, 2, NOTE_B3, 4,
  NOTE_C4, 1,

  NOTE_G4, 8,
  NOTE_E4, 8, NOTE_F4, 8, NOTE_G4, 4, NOTE_G4, 4, NOTE_G4, 4,
  NOTE_A4, 8, NOTE_B4, 8, NOTE_C5, 4, NOTE_C5, 4, NOTE_C5, 4,
  NOTE_E4, 8, NOTE_F4, 8, NOTE_G4, 4, NOTE_G4, 4, NOTE_G4, 4,
  NOTE_A4, 8, NOTE_G4, 8, NOTE_F4, 4, NOTE_F4, 2,
  NOTE_E4, 4, NOTE_G4, 4, NOTE_C4, 4, NOTE_E4, 4,
  NOTE_D4, 4, NOTE_F4, 2, NOTE_B3, 4,
  NOTE_C4, 1,

  REST, 1, //Para que no suene

  // We Wish You a Merry Christmas


  NOTE_C5, 4, //1
  NOTE_F5, 4, NOTE_F5, 8, NOTE_G5, 8, NOTE_F5, 8, NOTE_E5, 8,
  NOTE_D5, 4, NOTE_D5, 4, NOTE_D5, 4,
  NOTE_G5, 4, NOTE_G5, 8, NOTE_A5, 8, NOTE_G5, 8, NOTE_F5, 8,
  NOTE_E5, 4, NOTE_C5, 4, NOTE_C5, 4,
  NOTE_A5, 4, NOTE_A5, 8, NOTE_AS5, 8, NOTE_A5, 8, NOTE_G5, 8,
  NOTE_F5, 4, NOTE_D5, 4, NOTE_C5, 8, NOTE_C5, 8,
  NOTE_D5, 4, NOTE_G5, 4, NOTE_E5, 4,

  NOTE_F5, 2, NOTE_C5, 4, //8
  NOTE_F5, 4, NOTE_F5, 8, NOTE_G5, 8, NOTE_F5, 8, NOTE_E5, 8,
  NOTE_D5, 4, NOTE_D5, 4, NOTE_D5, 4,
  NOTE_G5, 4, NOTE_G5, 8, NOTE_A5, 8, NOTE_G5, 8, NOTE_F5, 8,
  NOTE_E5, 4, NOTE_C5, 4, NOTE_C5, 4,
  NOTE_A5, 4, NOTE_A5, 8, NOTE_AS5, 8, NOTE_A5, 8, NOTE_G5, 8,
  NOTE_F5, 4, NOTE_D5, 4, NOTE_C5, 8, NOTE_C5, 8,
  NOTE_D5, 4, NOTE_G5, 4, NOTE_E5, 4,
  NOTE_F5, 2, NOTE_C5, 4,


};

Ultrasonic ultrasonic(22, 23);
int distance;

// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
// there are two values per note (pitch and duration), so for each note there are four bytes
int notes = sizeof(melody) / sizeof(melody[0]) / 2;

// this calculates the duration of a whole note in ms
int wholenote = (60000 * 4) / tempo;

int divider = 0, noteDuration = 0;
//--------------------------------------
#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
BluetoothSerial SerialBT;


void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
//------------------------------------------------------
  //--------------------------
  pinMode(stcp_Pin, OUTPUT);
  pinMode(shcp_Pin, OUTPUT);
  pinMode(ds_Pin, OUTPUT);
  //-------------------------
Serial.begin(9600);
  ///--------------------------
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);
    pinMode(led1, OUTPUT);
  digitalWrite(led1, HIGH);

}
bool playingMelody = false;
void apagarLuces() {
for (int number = 255; number >= 0; number--) {
      digitalWrite(stcp_Pin, LOW);
      shiftOut(ds_Pin, shcp_Pin, LSBFIRST, number);
      digitalWrite(stcp_Pin, HIGH);
      delay(50);
}
}
void luces(){
      for (int number = 0; number < 256; number++) {
    digitalWrite(stcp_Pin, LOW);
    shiftOut(ds_Pin, shcp_Pin, LSBFIRST, number);
    digitalWrite(stcp_Pin, HIGH);
    delay(100);
  }

  // Mantener todos los LEDs encendidos después del ciclo
  digitalWrite(stcp_Pin, LOW);
  shiftOut(ds_Pin, shcp_Pin, LSBFIRST, 255); // Encender todos los LEDs (255 en binario es 11111111)
  digitalWrite(stcp_Pin, HIGH);
  

  }
  
void playMelody() {
  playingMelody = true;
  // sizeof da el número de bytes, cada valor int está compuesto por dos bytes (16 bits)
  // hay dos valores por nota (tono y duración), por lo que para cada nota hay cuatro bytes
  int notes = sizeof(melody) / sizeof(melody[0]) / 2;
  int wholenote = (60000 * 4) / tempo;
  int divider = 0, noteDuration = 0;

  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
    divider = melody[thisNote + 1];
    if (divider > 0) {
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5;
    }

    tone(buzzer, melody[thisNote], noteDuration * 0.9);
    delay(noteDuration);
    noTone(buzzer);
  }
  playingMelody = false;
}

void stopBuzzer() {
  // Detener el sonido del buzzer
  noTone(buzzer);
  delay(noteDuration); // Opcional: agregar un pequeño retraso
}
void loop() {
  if (SerialBT.available()) {

    char data = SerialBT.read();
    if (data == '0') {
      luces();
    } else if (data == '1') {
      apagarLuces(); // Apagar los LEDs
    }
    else if (data == '2') {
      playMelody(); // Apagar los LEDs
    }
    else if (data == '2') {
      stopBuzzer(); // Apagar los LEDs
    }
  }
}