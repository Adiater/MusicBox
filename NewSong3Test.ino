#include <Volume.h>
#include <def.h>

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

#define trigPin 13

#define echoPin 12

#define B 9

#define G 10

#define R 11

#define NewSong 0

enum color{
  RED,GREEN,BLUE,PURPLE,CYAN,YELLOW
};

int cal = 0;
int r_volt;
int start_v = 0;
int prev = 0;
int offset = 30;
int change = 0;
int curVol = 150;
long duration, distance, prevDistance, caliberate = 0;
int numSongs = 2;
int track = 1;
int stop = 0;
int h = 0;
Volume vol;
 
void setup() {
  // put your setup code here, to run once:

  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(B,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(R,OUTPUT);
    
  vol.begin();
  vol.setMasterVolume(1);
  
  caliberateLED();
  caliberateUNS();

  prevDistance = 0;
  prev = start_v;

  beep(3);
  delay(2000);
}


void loop(){

  playSong1();
}

void playSong1(){
  
    int length = 200;
 
    int melody[] =  {0, NOTE_CS5,  NOTE_E5,  NOTE_CS5,  NOTE_CS5,  NOTE_E5, NOTE_CS5,  NOTE_CS5,  NOTE_E5,  NOTE_CS5,  NOTE_DS5, NOTE_CS5, NOTE_B4,  NOTE_CS5,  NOTE_E5,  NOTE_CS5,  NOTE_CS5,  NOTE_E5, NOTE_CS5,  NOTE_CS5,  NOTE_E5,  NOTE_CS5,  NOTE_DS5, NOTE_CS5, NOTE_B4,
    
    NOTE_E5,  NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_FS5, NOTE_GS5, NOTE_GS5, 0,
        
    NOTE_B5, NOTE_GS5,  NOTE_GS5,  NOTE_GS5,  NOTE_GS5,   NOTE_GS5,  
    
    
    NOTE_FS5,  NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_E5, NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_E5, NOTE_CS5, NOTE_GS4, NOTE_GS4, NOTE_B4, NOTE_CS5, NOTE_CS5, 
    
    NOTE_CS5, NOTE_CS5, NOTE_CS5, NOTE_B4, NOTE_CS5, NOTE_GS5, NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_GS5, NOTE_FS5, NOTE_E5, NOTE_CS5, NOTE_E5, NOTE_GS5, NOTE_E5, NOTE_FS5, NOTE_CS5, NOTE_B5, NOTE_GS5, NOTE_GS5, NOTE_FS5, NOTE_E5, NOTE_E5, NOTE_CS5, NOTE_FS5, NOTE_FS5, NOTE_GS5, NOTE_FS5, NOTE_E5, NOTE_FS5, NOTE_E5, NOTE_CS5, NOTE_B4, 

    
    NOTE_CS5, NOTE_CS5, NOTE_CS5, NOTE_B4, NOTE_CS5, NOTE_GS5, NOTE_FS5, NOTE_FS5, NOTE_FS5, NOTE_GS5, NOTE_FS5, NOTE_E5, NOTE_CS5, NOTE_E5, NOTE_GS5, NOTE_E5, NOTE_FS5, NOTE_CS5, NOTE_B5, NOTE_GS5, NOTE_GS5, NOTE_FS5, NOTE_E5, NOTE_E5, NOTE_CS5, 0, NOTE_B5, NOTE_GS5, NOTE_GS5, NOTE_FS5, NOTE_E5, NOTE_E5, NOTE_CS5, NOTE_GS4, NOTE_B4, NOTE_CS5,
    
    0, NOTE_E5, NOTE_FS5, NOTE_GS5, NOTE_FS5, NOTE_E5, NOTE_E5, NOTE_FS5, NOTE_FS5, 0, NOTE_E5, NOTE_FS5, NOTE_GS5, NOTE_FS5, NOTE_E5, NOTE_E5, NOTE_FS5, NOTE_CS5, 0, NOTE_E5, NOTE_FS5, NOTE_GS5, NOTE_FS5, NOTE_E5, NOTE_E5, NOTE_FS5, NOTE_FS5, 0, NOTE_E5, NOTE_FS5, NOTE_GS5, NOTE_FS5, NOTE_E5, NOTE_FS5,
     
    NOTE_CS5, NOTE_CS5, NOTE_CS5, NOTE_CS5, NOTE_CS5, NOTE_E5, NOTE_FS5, NOTE_GS5, NOTE_CS5, NOTE_E5, NOTE_FS5, NOTE_FS5, 0, NOTE_E5, NOTE_FS5, NOTE_GS5, NOTE_FS5, NOTE_E5, NOTE_FS5, NOTE_FS5, NOTE_CS5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};  

    
    int noteDurations[] = {4, 6, 6, 8, 6, 6, 8, 6, 6, 8, 6, 6, 8, 6, 6, 8, 6, 6, 8, 6, 6, 8, 6, 6, 8,
    8, 16, 16, 16, 16, 8, 16, 16, 16, 16, 16, 16, 16, 8, 8, 16, 8, 4, 4, 
    16, 16, 16, 8, 8, 16, 8, 8, 8, 16, 16, 8, 8, 8, 16, 4, 
    16, 16, 16, 16, 16, 8, 8, 8, 8, 8, 8, 4, 16, 8, 16, 8, 8, 8, 8, 16, 16, 8, 4, 
    16, 16, 8, 16, 16, 8, 4, 16, 8, 16, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 4, 16, 8, 16, 8, 8, 8, 8, 16, 16, 8, 4,
    16, 16, 8, 16, 16, 8, 8, 8, 16, 16, 8, 16, 16, 8, 8, 8, 8, 4, 4,
    16, 16, 8, 16, 16, 8, 8, 8, 4, 16, 16, 8, 16, 16, 8, 8, 8, 4, 16, 16, 8, 16, 16, 8, 8, 8, 4,
    16, 16, 8, 16, 16, 6, 6, 16, 16, 16, 16, 16, 16, 8, 8, 8, 8, 4, 8, 16, 16, 8, 16, 16, 8, 8, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    for (int thisNote = 0; thisNote < length ; thisNote++) {

//     if(changeSong() == 1){
//      
//        interruptProtocol();       
//        return;
//     }

     if(prevDistance > caliberate - 100 && distance > 90){

        prevDistance = 100;
     }else if(prevDistance > caliberate - 100 && distance < 20){

        prevDistance = 0;
     }

     setDistance();
  
     if(distance < caliberate - 50 && prevDistance - 10 > distance && curVol - 50 >= 0){
      
        Serial.print("Decrease Volume\n Distance:");
        Serial.print(distance);
        Serial.print("\n Previous distance:");
        Serial.print(prevDistance);
        Serial.print("\n");
        curVol = curVol - 50;
        prevDistance = distance;
        delay(1000);
    }else if(distance < caliberate - 50 && prevDistance + 10 < distance && curVol + 50 < 255){
      
        Serial.print("Increase Volume\n Distance:");
        Serial.print(distance);
        Serial.print("\n Previous distance:");
        Serial.print(prevDistance);
        Serial.print("\n");
        curVol = curVol +50;
        prevDistance = distance;
        delay(1000);
    }

      Serial.print(distance);
      Serial.print("\n");

    int start = startLED();

    if(start == 1){

       if(h == 0){
        playLED(CYAN);
        
        h = 1;

       }else{
        playLED(PURPLE);
        h = 0;
       }
       start == 0;
  }

    int noteDuration = 1000 / noteDurations[thisNote];
    int pauseBetweenNotes = noteDuration * 80;
    delay(pauseBetweenNotes);
    Serial.print("\n");

    vol.tone(melody[thisNote], curVol);
    vol.delay(noteDuration/2);
    killLED();
    vol.delay(noteDuration/2);
    vol.tone(melody[thisNote], 0);

    
  }
}

void beep(int n){

 for(int i = 0; i < n ; i++){
  vol.tone(NOTE_CS5, curVol);
  vol.delay(250);
  vol.tone(NOTE_CS5, 0);
  vol.delay(250);
 }
}

void caliberateUNS(){

    caliberate = 0;

  for(int i = 0; i<20 ; i++){
    
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    caliberate = caliberate + (duration / 2) / 5;
  }

  caliberate = caliberate/20;
  Serial.print("Caliberate:");
  Serial.print(caliberate);
  Serial.print("\n");
}

void caliberateLED(){

  for(int i = 0; i< 20; i++){

    start_v = start_v + analogRead(NewSong);
  }

  start_v = start_v/20; 
}

int findOffset(){

  int max = 0;
  int avg = 0;

  for(int i = 0; i<20 ; i++){

     r_volt = analogRead(NewSong);

     if(max < r_volt && (max-r_volt < 30 || max-r_volt > -30)){

      max = r_volt;
     }

     avg = avg + r_volt;
  }

  avg = avg/20;

  return (max-avg);
}

int changeSong(){

  r_volt = analogRead(NewSong);
  Serial.print(r_volt);
  Serial.print("\n Start_v:");
  Serial.print(start_v);
  Serial.print("\n");
 
  prev = start_v;
  
  if(prev + offset < r_volt || r_volt < prev - offset){
    
    Serial.print("Caliberate\n prev:");
    Serial.print(prev);
    Serial.print("\n r_volt:");
    Serial.print(r_volt);
    Serial.print("\n");
    caliberateLED();
    change = findOffset();
    cal = 1;
  }
    
  if((r_volt > start_v + change)){
    
    Serial.print("LED ON\n r_volt:");
    Serial.print(r_volt);
    Serial.print("\n start_v:");
    Serial.print(start_v + change);
    Serial.print("\n");
    return 1;
  }

  return 0;
}

void interruptProtocol(){

  cal = 0;
  r_volt = 0;
  
  if(track > numSongs){
  
    track = 0;
  }else{
  
    track++;
  }
}

long setDistance(){

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 5;

  return distance;
}

void playLED(color col){

  switch(col){

    case RED:

      digitalWrite(R,LOW);
      digitalWrite(G,HIGH);
      digitalWrite(B,HIGH);
      break;

    case GREEN:

      digitalWrite(R,HIGH);
      digitalWrite(G,LOW);
      digitalWrite(B,HIGH);
      break;

    case BLUE:

      digitalWrite(R,HIGH);
      digitalWrite(G,HIGH);
      digitalWrite(B,LOW);
      break;

    case PURPLE:

      digitalWrite(R,LOW);
      digitalWrite(G,HIGH);
      digitalWrite(B,LOW);
      break;

    case YELLOW:

      digitalWrite(R,LOW);
      digitalWrite(G,LOW);
      digitalWrite(B,HIGH);
      break;

    case CYAN:

      digitalWrite(R,HIGH);
      digitalWrite(G,LOW);
      digitalWrite(B,LOW);
      break;
  }
}

int startLED(){

  long r_volt = analogRead(NewSong);
//  Serial.print("Complete Darkness:");
//  Serial.print(r_volt);
//  Serial.print("\n");

  if(r_volt > 300){
    return 1;
  }

  return 0;
}

void killLED(){

  digitalWrite(R,HIGH);
  digitalWrite(G,HIGH);
  digitalWrite(B,HIGH);
}



