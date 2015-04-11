// From: http://www.instructables.com/id/How-to-easily-play-music-with-buzzer-on-arduino-Th/
// NB: ALL NOTES DEFINED WITH STANDARD ENGLISH NAMES, EXCEPT FOR "A"
// WHICH HERE IS CALLED "AA" BECAUSE A0,A1...ARE THE ANALOG PINS ON ARDUINO.
// (Ab IS CALLED Ab AND NOT AAb)
#define	CC0     16.35
#define	Db0	17.32
#define	DD0	18.35
#define	Eb0	19.45
#define	EE0	20.60
#define	FF0	21.83
#define	Gb0	23.12
#define	GG0	24.50
#define	Ab0	25.96
#define	AA0	27.50
#define	Bb0	29.14
#define	BB0	30.87
#define	CC1	32.70
#define	Db1	34.65
#define	DD1	36.71
#define	Eb1	38.89
#define	EE1	41.20
#define	FF1	43.65
#define	Gb1	46.25
#define	GG1	49.00
#define	Ab1	51.91
#define	AA1	55.00
#define	Bb1	58.27
#define	BB1	61.74
#define	CC2	65.41
#define	Db2	69.30
#define	DD2	73.42
#define	Eb2	77.78
#define	EE2	82.41
#define	FF2	87.31
#define	Gb2	92.50
#define	GG2	98.00
#define	Ab2	103.83
#define	AA2	110.00
#define	Bb2	116.54
#define	BB2	123.47
#define	CC3	130.81
#define	Db3	138.59
#define	DD3	146.83
#define	Eb3	155.56
#define	EE3	164.81
#define	FF3	174.61
#define	Gb3	185.00
#define	GG3	196.00
#define	Ab3	207.65
#define	AA3	220.00
#define	Bb3	233.08
#define	BB3	246.94
#define	CC4	261.63 // <-- MIDDLE C
#define	Db4	277.18
#define	DD4	293.66
#define	Eb4	311.13
#define	EE4	329.63
#define	FF4	349.23
#define	Gb4	369.99
#define	GG4	392.00
#define	Ab4	415.30
#define	AA4	440.00
#define	Bb4	466.16
#define	BB4	493.88
#define	CC5	523.25
#define	Db5	554.37
#define	DD5	587.33
#define	Eb5	622.25
#define	EE5	659.26
#define	FF5	698.46
#define	Gb5	739.99
#define	GG5	783.99
#define	Ab5	830.61
#define	AA5	880.00
#define	Bb5	932.33
#define	BB5	987.77
#define	CC6	1046.50
#define	Db6	1108.73
#define	DD6	1174.66
#define	Eb6	1244.51
#define	EE6	1318.51
#define	FF6	1396.91
#define	Gb6	1479.98
#define	GG6	1567.98
#define	Ab6	1661.22
#define	AA6	1760.00
#define	Bb6	1864.66
#define	BB6	1975.53
#define	CC7	2093.00
#define	Db7	2217.46
#define	DD7	2349.32
#define	Eb7	2489.02
#define	EE7	2637.02
#define	FF7	2793.83
#define	Gb7	2959.96
#define	GG7	3135.96
#define	Ab7	3322.44
#define	AA7	3520.01
#define	Bb7	3729.31
#define	BB7	3951.07
#define	CC8	4186.01
#define	Db8	4434.92
#define	DD8	4698.64
#define	Eb8	4978.03
#define R       0        // rest

// DURATION OF THE NOTES 
#define H   2*Q //half 2/4
#define Q   60000/bpm //quarter 1/4  // Here assumes 4/4 time signature!
#define E   Q/2   //eighth 1/8
#define S   Q/4 // sixteenth 1/16
#define W   4*Q // whole 4/4
#define EE  E*4/3 // slightly slow E or a quick Q

int num_leds = 12;                            // WRITE HERE TOTAL NUMBER OF LEDS CONNECTED
int speaker_connect = 23;                     // WRITE HERE WHICH PIN THE SPEAKER IS CONNECTED TO
int leds[] = {22,21,20,19,18,17,16,15,14,13,12,11};     // WRITE HERE WHICH PIN THE LEDS ARE CONNECTED TO:  1, 2, 3, 4, 5 .... 
// DH TODO -- change it so that it divides High and Low note of song against how many LEDs there are so that ALL notes get played
//      no matter how many various notes there are-- need a way to analyze the song somehow to assign the lights??

/*
// The Imperial March
int bpm = 120;      // WRITE HERE THE TEMPO OF THE SONG (BPM)
int song[100][2] = {  // WRITE HERE THE SONG IN FORMAT {{NOTE, DURATION}, {NOTE, DURATION}, ... {NOTE, DURATION}} MAX NOTES = 100
       {AA3,Q},{AA3,Q},{AA3,Q},{FF3,E+S},{CC4,S},{AA3,Q},{FF3,E+S},{CC4,S},{AA3,H},
       {EE4,Q},{EE4,Q},{EE4,Q},{FF4,E+S},{CC4,S},{Ab3,Q},{FF3,E+S},{CC4,S},{AA3,H},
       {AA4,Q},{AA3,E+S},{AA3,S},{AA4,Q},{Ab4,E+S},{GG4,S},
       {Gb4,S},{EE4,S},{FF4,E},{R,E},{Bb3,E},{Eb4,Q},{DD4,E+S},{Db4,S},
       {CC4,S},{BB3,S},{CC4,E},{R,E},{FF3,E},{Ab3,Q},{FF3,E+S},{AA3,S},
       {CC4,Q},{AA3,E+S},{CC4,S},{EE4,H},{AA4,Q},{AA3,E+S},{AA3,S},{AA4,Q},{Ab4,E+S},{GG4,S},
       {Gb4,S},{EE4,S},{FF4,E},{R,E},{Bb3,E},{Eb4,Q},{DD4,E+S},{Db4,S},
       {CC4,S},{BB3,S},{CC4,E},{R,E},{FF3,E},{Ab3,Q},{FF3,E+S},{CC4,S},
       {AA3,Q},{FF3,E+S},{CC4,S},{AA3,H}
};
int num_notes = 70; // WRITE HERE HOW MANY NOTES IN THE SONG!
int led_notes[] = {Ab3,AA3,FF3,CC4,EE4,FF4,Gb4,GG4};  //WRITE HERE WHAT NOTES TO LINK TO WHICH LEDS, MUST BE SAME NUMBER AS NUMBER OF LEDS ABOVE!
*/

/*
// Jingle Bell Rock
int bpm = 120;
int song[100][2] = {
  
 {R,Q},{CC6,E},{AA5,E},{BB5,E},{AA5,E},{GG5,Q},{CC6,Q},{Bb5,Q},{BB5,Q},{R,Q},{CC6,E},{CC6,E},{CC6,Q},{BB5,E},{BB5,E},{BB5,Q}, //COUNT OF 16
 {AA5,E},{BB5,E},{AA5,E},{EE5,E+H},{AA5,E},{BB5,E},{AA5,Q},{EE5,Q},{GG5,Q},{AA5,E},{BB5,E},{AA5,E},{FF5,H},  //COUNT OF 13
 {DD5,E},{EE5,Q},{FF5,E},{GG5,E},{AA5,Q},{GG5,E},{DD5,E},{EE5,E},{FF5,Q},{GG5,H},{R,Q},{AA5,E},{Bb5,E},{AA5,E},{GG5,E},{AA5,Q}, //COUNT OF 16
 {AA5,Q},{Eb5,E},{DD5,Q},{DD5,E},{R,Q},{CC6,E},{CC6,E},{CC6,Q},{BB5,E},{BB5,E},{BB5,Q},{AA5,E},{BB5,E},{AA5,E},{EE5,E},{EE5,H} //COUNT OF 16
 
};
int num_notes = 61;
int led_notes[] = {DD5,EE5,FF5,GG5,AA5,Bb5,BB5,CC6}; // only 8 notes thus far
*/

/*
// Jingle Bell Rock (extended)
int bpm = 120;
int song[200][2] = {
 // INTRO
 {R,Q},{CC6,E},{AA5,E},{BB5,E},{AA5,E},{GG5,Q},{CC6,Q},{Bb5,Q},{BB5,Q},{R,Q},             //10
 // Jingle Bell, Jingle Bell,  Jingle Bell Rock
 {CC6,E},{CC6,E},{CC6,Q},{BB5,E},{BB5,E},{BB5,Q}, {AA5,E},{BB5,E},{AA5,E},{EE5,E+H},         //10
 // Jingle bell swing and jingle bells ring
 {AA5,E},{BB5,E},{AA5,Q},{EE5,Q},{GG5,Q},{AA5,E},{BB5,E},{AA5,E},{FF5,H},                 //9
 // Snowin' and blowin' up bushels of fun
 {DD5,E},{EE5,Q},{FF5,E},{GG5,E},{AA5,Q},{GG5,E},{DD5,E},{EE5,E},{FF5,Q},{GG5,H},             //10
 // Now the jingle hop has begun
 {R,Q},{AA5,E},{Bb5,E},{AA5,E},{GG5,E},{AA5,Q},{AA5,Q},{Eb5,E},{Eb5,Q+E},             //9
  // Jingle Bell, Jingle Bell,  Jingle Bell Rock
 {CC6,E},{CC6,E},{CC6,Q},{BB5,E},{BB5,E},{BB5,Q}, {AA5,E},{BB5,E},{AA5,E},{EE5,E+H},         //10
 // Jingle Bells chime in jingle bell time
 {AA5,E},{BB5,E},{AA5,Q},{EE5,Q},{GG5,Q},{AA5,E},{BB5,E},{AA5,E},{FF5,H},                 //9
 // dancin' and prancin' in Jingle bell square
 {DD5,E},{EE5,Q},{FF5,E},{GG5,E},{AA5,Q},{GG5,E},{DD5,E},{EE5,E},{FF5,Q},{GG5,H},             //10
 // in the frosty air...
 {R,Q},{AA5,E},{AA5,E},{BB5,E},{GG5,Q},{CC6,E+H+E},                                      //6
 
 // what a bright time, it's the right time
 {CC6,E},{CC6,E},{CC6,E},{DD6,Q},{CC6,E+Q},{AA5,E},{CC6,E},{CC6,E},{DD6,Q},{CC6,E+Q+E},        //10
 
 // to rock the night away
 {CC6,E},{CC6,Q},{BB5,Q},{AA5,Q},{GG5,Q},{EE5,H+E},                                        //6
 
 // Jingle bell time is a swell time
 {CC6,E},{CC6,E},{CC6,E},{DD6,Q},{CC6,E+Q},{AA5,E},{CC6,E},{DD6,Q+E},{CC6,E+H},               //9
 
 // to go glidin in a one horse sleigh
 {GG5,E},{GG5,Q},{AA5,E},{AA5,E},{AA5,E},{AA5,E},{BB5,E},{AA5,E},{GG5,E+Q},{R,Q},          //10
 
 // Giddy ap jingle horse, pick up your feet
 {CC6,E},{CC6,E},{CC6,Q},{BB5,E},{BB5,E},{BB5,Q}, {AA5,E},{BB5,E},{AA5,E},{EE5,E+H},           //10
 
 // jingle around the clock
 {AA5,E},{BB5,E},{AA5,Q},{EE5,Q},{GG5,Q},{AA5,W},                                         //6
 
 // mix and mingle in a jinglin beat
 {AA5,Q},{CC6,Q},{DD6,E},{DD6,E},{CC6,E},{CC6,E},{Ab5,E},{AA5,E},{CC6,E},{DD6,E+H},           //10
 
 // that's the jingle bell ...
 {R,Q},{CC6,E},{AA5,E},{BB5,E},{AA5,E},{GG5,Q},                                           //6
 
 // that's the jingle bell ...
 {R,Q},{CC6,E},{AA5,E},{BB5,E},{AA5,E},{GG5,Q},                                           //6
 
 // that's the jingle bell rock!
 {R,Q},{CC6,E},{AA5,E},{BB5,E},{CC6,E},{DD6,E},{CC6,W+H+E},                                 //7
 
 // REST A BIT
 {R,W}                                                                                 //1
 
};
int num_notes = 164;
int led_notes[] = {DD5,Eb5,EE5,FF5,GG5,AA5,Bb5,BB5,CC6,DD6};
*/

/*
// Super Mario Bros (1985) Overworld / Main Theme
int bpm = 240; // want slightly faster
int song[100][2] = {
       {EE6,E},{EE6,Q},{EE6,Q},{CC6,E},{EE6,Q},{GG6,H},{GG5,H},
       {CC6,Q+E},{GG5,Q+E},{EE5,Q+E},{AA5,Q},{BB5,Q},{Bb5,E},{AA5,Q},{GG5,EE},{EE6,EE},{GG6,EE},{AA6,Q},{FF6,E},{GG6,Q},{EE6,Q},{CC6,E},{DD6,E},{BB5,Q+E},
       {CC6,Q+E},{GG5,Q+E},{EE5,Q+E},{AA5,Q},{BB5,Q},{Bb5,E},{AA5,Q},{GG5,EE},{EE6,EE},{GG6,EE},{AA6,Q},{FF6,E},{GG6,Q},{EE6,Q},{CC6,E},{DD6,E},{BB5,Q+E},
       {GG6,E},{Gb6,E},{FF6,E},{Eb6,Q},{EE6,Q},{Ab5,E},{AA5,E},{CC6,Q},{AA5,E},{CC6,E},{DD6,Q+E},{GG6,E},{Gb6,E},{FF6,E},{Eb6,Q},{EE6,Q},{AA6,Q},{AA6,E},{AA6,H}, //60
       {GG6,E},{Gb6,E},{FF6,E},{Eb6,Q},{EE6,Q},{Ab5,E},{AA5,E},{CC6,Q},{AA5,E},{CC6,E},{DD6,Q+E},{Eb6,Q+S},{DD6,Q+S},{CC6,H}
};
int num_notes = 74;
int led_notes[] = {EE5,GG5,AA5,BB5,CC6,DD6,EE6,FF6,GG6,AA6}; 
*/

// NFL THEME -- from https://www.youtube.com/watch?v=lctRoh5kiIk
int bpm = 112;
int song[200][2] = {
    {R,E},{CC4,S},{Db4,S},{Eb4,E},{Db4,S},{CC4,S},{GG4,H},{CC3,Q},{R,E},
          {CC4,S},{Db4,S},{Eb4,E},{Db4,S},{CC4,S},{Ab4,H},{CC3,Q},{R,E},
          {CC4,S},{Db4,S},{Eb4,E},{Db4,S},{CC4,S},{GG4,Q},{GG5,Q},{Ab5,Q},{CC6,Q},{BB5,H},
    {CC3,H},{GG4,S},{Ab4,S},{Eb5,E},{GG4,S},{Ab4,S},{Eb5,E},{GG4,S},{Ab4,S},{Eb5,E+S},{FF5,E+S},{DD5,W},{CC3,H},   
          {R,E},{GG4,S},{Ab4,S},{Eb5,E},{GG4,S},{Ab4,S},{Eb5,E},{GG4,S},{Ab4,S},{Eb5,E+S},{GG5,E+S},{FF5,H},{DD5,Q},{R,E},{Ab5,E+S},
    {GG5,Q},{Ab5,Q},{Bb5,Q},{CC6,Q},{CC6,H},{DD6,H},
          {R,E},{GG4,S},{Ab4,S},{Eb5,E},{GG4,S},{Ab4,S},{Eb5,E},{GG4,S},{Ab4,S},{Eb5,E+S},{FF5,E+S},{DD5,W},{CC3,H},

    {CC3,H},{GG4,S},{Ab4,S},{Eb5,E},{GG4,S},{Ab4,S},{Eb5,E},{GG4,S},{Ab4,S},{Eb5,E+S},{Bb5,E+S},{Ab5,H},{FF5,H},{GG5,Q},{R,Q},
          {CC3,H},{CC3,H},{GG5,Q},{Ab5,Q},{CC6,Q},{BB5,H},
          
    {R,E},{CC4,S},{Db4,S},{Eb4,E},{Db4,S},{CC4,S},{GG4,H},{CC3,Q},{R,E},
          {CC4,S},{Db4,S},{Eb4,E},{Db4,S},{CC4,S},{Ab4,H},{CC3,Q},{R,E},
          {CC4,S},{Db4,S},{Eb4,E},{Db4,S},{CC4,S},{GG4,Q},{GG5,Q},{Ab5,Q},{CC6,Q},{BB5,H},{CC6,Q}      
         
  
};
int num_notes = 200;
int led_notes[] = {CC3,CC4,Db4,Eb4,GG4,Ab4,DD5,FF5,GG5,Ab5,BB5,CC6};


/*
// PLAY SCALES
int bpm = 112;
int song[100][2] = { //CC4 and GG5 not working on way up, GG4 on way down??
  {CC3,Q},{CC4,Q},{Db4,Q},{Eb4,Q},{GG4,Q},{Ab4,Q},{GG5,Q},{Ab5,Q},{BB5,Q},{CC6,Q},
  {R,H},
  {CC6,Q},{BB5,Q},{Ab5,Q},{GG5,Q},{Ab4,Q},{GG4,Q},{Eb4,Q},{Db4,Q},{CC4,Q},{CC3,Q},
  {R,H},
  {CC3,Q},{CC4,Q},{Db4,Q},{Eb4,Q},{GG4,Q},{Ab4,Q},{GG5,Q},{Ab5,Q},{BB5,Q},{CC6,Q}  
};
int num_notes = 32;
int led_notes[] = {CC3,CC4,Db4,Eb4,GG4,Ab4,GG5,Ab5,BB5,CC6};

*/






// DO NOT MODIFY BELOW THIS LINE!!! SONGS CODED ABOVE!
//
//

void setup() {     
  pinMode(speaker_connect, OUTPUT);   
  for (int i=0; i < num_leds; i++) {
    pinMode(leds[i], OUTPUT);
  } 
  delay(1000); // delay 1sec before starting music
}

// turn on LED that matches note
void leds_on(int note) {
  for (int i=0; i < num_leds; i++) {
    if (led_notes[i] == note) {
      digitalWrite(leds[i],HIGH); 
    }
  } 
}

// turn on LED that matches note, turn off all others
void leds_on_v2(int note) {
  for (int i=0; i < num_leds; i++) {
    if (led_notes[i] == note) {
      digitalWrite(leds[i],HIGH); 
    } else {
      digitalWrite(leds[i],LOW);
    }
  } 
}


void leds_off() { // turn off all LEDs
  for (int i=0; i < num_leds; i++) {
    digitalWrite(leds[i],LOW);  
  }
}


void play_note(int note, long duration) {
  int blink_lights = 1;     // whether to blink lights or not (1=yes, 0=no)
  
  if (blink_lights == 1) {  // Turn on LED corresponding to note, if any
     leds_on_v2(note);
  }
  
  if (note != R) {                 // only play if not a rest
    tone(speaker_connect, note, duration); // http://arduino.cc/en/Reference/Tone 
  }
  delay(duration);
  
//  if (blink_lights == 1) {  // Turn off all LEDs
//     leds_off();
//  }
  noTone(speaker_connect); // Fix intermittent issue where doesn't play properly on Teensy 3.1 if tone() called back to back
  delay(1); // note separator
  
}

void play_song(int which_song) {
  //int len = sizeof(melody)/sizeof(int);
  for (int i=0; i < num_notes; i++) {
    play_note(song[i][0], song[i][1]);
  }
}

// the loop routine runs over and over again forever:
void loop() {
    play_song(0);
    delay(1000);
}
    
    



