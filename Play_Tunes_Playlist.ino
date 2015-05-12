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

#define DEBUGME 0        // set to 0 for no debug, 1 for debug song arrays, 2 for print debug while playing music

// DURATION OF THE NOTES
#define S_S 1    // Q/4 // sixteenth 1/16
#define E   2    // Q/2   //eighth 1/8
#define Q   4    // 60000/bpm //quarter 1/4  // Here assumes 4/4 time signature!
#define H   8    // 2*Q //half 2/4
#define W   16   // 4*Q // whole 4/4
#define EE  8/3  // E*4/3 // slightly slow E or a quick Q

// Here list songs by name
#define IMPERIAL_MARCH             0
#define JINGLE_BELL_ROCK           1
#define SUPER_MARIO                2
#define NFL                        3
#define SCALES                     4
#define NUM_SONGS                  5  // update to be total number of songs in playlist


int num_leds = 10;                                // WRITE HERE TOTAL NUMBER OF LEDS CONNECTED
int speaker_connect = 23;                         // WRITE HERE WHICH PIN THE SPEAKER IS CONNECTED TO
int leds[] = {22,21,20,19,18,17,16,15,14,13};     // WRITE HERE WHICH PIN THE LEDS ARE CONNECTED TO:  1, 2, 3, 4, 5 .... 

// Use pointers for global variables
int *song;           // use to point to array of int.  E.G. to assign since 2d array: song = *song0;            to use: *(*(song+i)+j) <-- questionable
int *led_notes;      // use to point to array of int.  E.G. to assign since 1d array: led_notes = led_notes0;   to use: led_notes[i];
int *bpm;            // use to point to int.           E.G.                to assign: bpm = &bpm0;              to use: *bpm
int *num_notes;      // use to point to int.           E.G.                to assign: num_notes = &num_notes0;  to use: *num_notes


// DH TODO -- change it so that it divides High and Low note of song against how many LEDs there are so that ALL notes get played
//      no matter how many various notes there are-- need a way to analyze the song somehow to assign the lights??



// The Imperial March
int bpm0 = 120;         // WRITE HERE THE TEMPO OF THE SONG (BPM)
int song0[100][2] =  {  // WRITE HERE THE SONG IN FORMAT {{NOTE, DURATION}, {NOTE, DURATION}, ... {NOTE, DURATION}} MAX NOTES = 100
       {AA3,Q},{AA3,Q},{AA3,Q},{FF3,E+S_S},{CC4,S_S},{AA3,Q},{FF3,E+S_S},{CC4,S_S},{AA3,H},
       {EE4,Q},{EE4,Q},{EE4,Q},{FF4,E+S_S},{CC4,S_S},{Ab3,Q},{FF3,E+S_S},{CC4,S_S},{AA3,H},
       {AA4,Q},{AA3,E+S_S},{AA3,S_S},{AA4,Q},{Ab4,E+S_S},{GG4,S_S},
       {Gb4,S_S},{EE4,S_S},{FF4,E},{R,E},{Bb3,E},{Eb4,Q},{DD4,E+S_S},{Db4,S_S},
       {CC4,S_S},{BB3,S_S},{CC4,E},{R,E},{FF3,E},{Ab3,Q},{FF3,E+S_S},{AA3,S_S},
       {CC4,Q},{AA3,E+S_S},{CC4,S_S},{EE4,H},{AA4,Q},{AA3,E+S_S},{AA3,S_S},{AA4,Q},{Ab4,E+S_S},{GG4,S_S},
       {Gb4,S_S},{EE4,S_S},{FF4,E},{R,E},{Bb3,E},{Eb4,Q},{DD4,E+S_S},{Db4,S_S},
       {CC4,S_S},{BB3,S_S},{CC4,E},{R,E},{FF3,E},{Ab3,Q},{FF3,E+S_S},{CC4,S_S},
       {AA3,Q},{FF3,E+S_S},{CC4,S_S},{AA3,H}
};
int num_notes0 = 70;    // WRITE HERE HOW MANY NOTES IN THE SONG!
int led_notes0[] = {Ab3,AA3,FF3,CC4,EE4,FF4,Gb4,GG4};  //WRITE HERE WHAT NOTES TO LINK TO WHICH LEDS, MUST BE SAME NUMBER AS NUMBER OF LEDS ABOVE!

                                            


// Jingle Bell Rock (extended)
int bpm1 = 120;
int song1[200][2] = {
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
int num_notes1 = 164;
int led_notes1[] = {DD5,Eb5,EE5,FF5,GG5,AA5,Bb5,BB5,CC6,DD6};



// Super Mario Bros (1985) Overworld / Main Theme
int bpm2 = 240; // want slightly faster
int song2[100][2] = {
       {EE6,E},{EE6,Q},{EE6,Q},{CC6,E},{EE6,Q},{GG6,H},{GG5,H},
       {CC6,Q+E},{GG5,Q+E},{EE5,Q+E},{AA5,Q},{BB5,Q},{Bb5,E},{AA5,Q},{GG5,EE},{EE6,EE},{GG6,EE},{AA6,Q},{FF6,E},{GG6,Q},{EE6,Q},{CC6,E},{DD6,E},{BB5,Q+E},
       {CC6,Q+E},{GG5,Q+E},{EE5,Q+E},{AA5,Q},{BB5,Q},{Bb5,E},{AA5,Q},{GG5,EE},{EE6,EE},{GG6,EE},{AA6,Q},{FF6,E},{GG6,Q},{EE6,Q},{CC6,E},{DD6,E},{BB5,Q+E},
       {GG6,E},{Gb6,E},{FF6,E},{Eb6,Q},{EE6,Q},{Ab5,E},{AA5,E},{CC6,Q},{AA5,E},{CC6,E},{DD6,Q+E},{GG6,E},{Gb6,E},{FF6,E},{Eb6,Q},{EE6,Q},{AA6,Q},{AA6,E},{AA6,H}, //60
       {GG6,E},{Gb6,E},{FF6,E},{Eb6,Q},{EE6,Q},{Ab5,E},{AA5,E},{CC6,Q},{AA5,E},{CC6,E},{DD6,Q+E},{Eb6,Q+S_S},{DD6,Q+S_S},{CC6,H}
};
int num_notes2 = 74;
int led_notes2[] = {EE5,GG5,AA5,BB5,CC6,DD6,EE6,FF6,GG6,AA6}; 


// NFL THEME -- from https://www.youtube.com/watch?v=lctRoh5kiIk
int bpm3 = 112;
int song3[200][2] = {
    {R,E},{CC4,S_S},{Db4,S_S},{Eb4,E},{Db4,S_S},{CC4,S_S},{GG4,H},{CC3,Q},{R,E},
          {CC4,S_S},{Db4,S_S},{Eb4,E},{Db4,S_S},{CC4,S_S},{Ab4,H},{CC3,Q},{R,E},
          {CC4,S_S},{Db4,S_S},{Eb4,E},{Db4,S_S},{CC4,S_S},{GG4,Q},{GG5,Q},{Ab5,Q},{CC6,Q},{BB5,H},
    {CC3,H},{GG4,S_S},{Ab4,S_S},{Eb5,E},{GG4,S_S},{Ab4,S_S},{Eb5,E},{GG4,S_S},{Ab4,S_S},{Eb5,E+S_S},{FF5,E+S_S},{DD5,W},{CC3,H},   
          {R,E},{GG4,S_S},{Ab4,S_S},{Eb5,E},{GG4,S_S},{Ab4,S_S},{Eb5,E},{GG4,S_S},{Ab4,S_S},{Eb5,E+S_S},{GG5,E+S_S},{FF5,H},{DD5,Q},{R,E},{Ab5,E+S_S},
    {GG5,Q},{Ab5,Q},{Bb5,Q},{CC6,Q},{CC6,H},{DD6,H},
          {R,E},{GG4,S_S},{Ab4,S_S},{Eb5,E},{GG4,S_S},{Ab4,S_S},{Eb5,E},{GG4,S_S},{Ab4,S_S},{Eb5,E+S_S},{FF5,E+S_S},{DD5,W},{CC3,H},

    {CC3,H},{GG4,S_S},{Ab4,S_S},{Eb5,E},{GG4,S_S},{Ab4,S_S},{Eb5,E},{GG4,S_S},{Ab4,S_S},{Eb5,E+S_S},{Bb5,E+S_S},{Ab5,H},{FF5,H},{GG5,Q},{R,Q},
          {CC3,H},{CC3,H},{GG5,Q},{Ab5,Q},{CC6,Q},{BB5,H},
          
    {R,E},{CC4,S_S},{Db4,S_S},{Eb4,E},{Db4,S_S},{CC4,S_S},{GG4,H},{CC3,Q},{R,E},
          {CC4,S_S},{Db4,S_S},{Eb4,E},{Db4,S_S},{CC4,S_S},{Ab4,H},{CC3,Q},{R,E},
          {CC4,S_S},{Db4,S_S},{Eb4,E},{Db4,S_S},{CC4,S_S},{GG4,Q},{GG5,Q},{Ab5,Q},{CC6,Q},{BB5,H},{CC6,Q}      
         
  
};
int num_notes3 = 200;
int led_notes3[] = {CC3,CC4,Db4,Eb4,GG4,Ab4,DD5,FF5,GG5,Ab5,BB5,CC6};



// PLAY SCALES
int bpm4 = 112;
int song4[100][2] = {
// half notes
  {CC4,H},{DD4,H},{EE4,H},{FF4,H},{GG4,H},{AA4,H},{BB4,H},{CC5,H},{DD5,H},{EE5,H},
  {R,H},
  {EE5,H},{DD5,H},{CC5,H},{BB4,H},{AA4,H},{GG4,H},{FF4,H},{EE4,H},{DD4,H},{CC4,H},
  {R,H},

// quarter notes
  {CC4,Q},{DD4,Q},{EE4,Q},{FF4,Q},{GG4,Q},{AA4,Q},{BB4,Q},{CC5,Q},{DD5,Q},{EE5,Q},
  {R,Q},
  {EE5,Q},{DD5,Q},{CC5,Q},{BB4,Q},{AA4,Q},{GG4,Q},{FF4,Q},{EE4,Q},{DD4,Q},{CC4,Q},
  {R,Q},

// sixteenth notes
  {CC4,S_S},{DD4,S_S},{EE4,S_S},{FF4,S_S},{GG4,S_S},{AA4,S_S},{BB4,S_S},{CC5,S_S},{DD5,S_S},{EE5,S_S},
  {R,S_S},
  {EE5,S_S},{DD5,S_S},{CC5,S_S},{BB4,S_S},{AA4,S_S},{GG4,S_S},{FF4,S_S},{EE4,S_S},{DD4,S_S},{CC4,S_S},
  {R,S_S}


};
int num_notes4 = 66;
int led_notes4[] = {CC4,DD4,EE4,FF4,GG4,AA4,BB4,CC5,DD5,EE5};




// **********************************************************************************************
// **********************************************************************************************
// ******       DO NOT MODIFY BELOW THIS LINE!!! SONGS CODED ABOVE!  ****************************
// **********************************************************************************************
// **********************************************************************************************

// set song durations
// do once in setup only
void set_song_durations() {
  int i, j, duration;
  
  for(i=0; i < NUM_SONGS; i++){
    choose_song(i);
    for(j=0; j < (*num_notes*2); j+=2){
      // Adjust duration
     duration = ( (*(song+j+1)) * 60000 ) / ( (*bpm) * Q);
     (*(song+j+1)) = duration; // set new duration in mS
    }
  }
  
}

// Choose song you want to play next
// basically modify global variable pointers to point
// to set of song variables you want to use
// allows for modification
void choose_song(int which_song) {
  switch (which_song) {
   case IMPERIAL_MARCH: 
      bpm = &bpm0;
      num_notes = &num_notes0;
      song = *song0;             // assign pointer to 2d array (basically pointer contains address of 2d array)
      led_notes = led_notes0;   // assign pointer to 1d array (basically pointer contains address of first element of 1d array)
      break;
    case JINGLE_BELL_ROCK:
      bpm = &bpm1;
      num_notes = &num_notes1;
      song = *song1;
      led_notes = led_notes1;
      break;
    case SUPER_MARIO:
      bpm = &bpm2;
      num_notes = &num_notes2;
      song = *song2;
      led_notes = led_notes2;
      break;
    case NFL:
      bpm = &bpm3;
      num_notes = &num_notes3;
      song = *song3;
      led_notes = led_notes3;
      break;
    case SCALES:
      bpm = &bpm4;
      num_notes = &num_notes4;
      song = *song4;
      led_notes = led_notes4;
      break;
    
  }
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
      digitalWrite(leds[i],LOW); 
    } else {
      digitalWrite(leds[i],HIGH);
    }
  } 
}

// Turn off all LEDs
void leds_off() {
  for (int i=0; i < num_leds; i++) {
    digitalWrite(leds[i],HIGH);  
  }
}

// Plays a single note
void play_note(int note, long duration) {
  int blink_lights = 1;     // whether to blink lights or not (1=yes, 0=no)
  
  if (blink_lights == 1) {  // Turn on LED corresponding to note, if any
     leds_on_v2(note);
  }

  if (note != R) {                 // only play if not a rest
    tone(speaker_connect, note, duration); // http://arduino.cc/en/Reference/Tone // pin, freq of tone in Hz (unsigned int), duration in mS (unsigned long)
  }
  delay(duration);
  
//  if (blink_lights == 1) {  // Turn off all LEDs
//     leds_off();
//  }
  noTone(speaker_connect); // Fix intermittent issue where doesn't play properly on Teensy 3.1 if tone() called back to back
  delay(1); // note separator
  
}

// Play an entire song
void play_song(int which_song) {
  int note, duration;
  choose_song(which_song);
  //int len = sizeof(melody)/sizeof(int);
  for (int i=0; i < (*num_notes*2); i+=2) {
    note = *(song+i);             // equiv to note = song[i][0]
    duration = *(song+i+1);    // equiv to duration = song[i][1]
    play_note(note, duration);
  }
}

// for debug prints out the song assigned
void debug_print_song(int which_song) {
  // FOR DEBUG ONLY

  Serial.printf("*********************************************\r\n");  
  Serial.printf("Num_notes0: %i\r\n", num_notes0);
  Serial.printf("BPM0: %i\r\n", bpm0);
  Serial.printf("LED_NOTES0:  ");
  for (int i=0; i < num_leds; i++) {
    Serial.printf("%i, ", led_notes0[i]); 
  }
  Serial.printf("\r\n");
  Serial.printf("SONG0:  \r\n");
  for (int i=0; i < num_notes0; i++) {
    Serial.printf("    NOTE: %i, DURATION: %i\r\n", song0[i][0],song0[i][1]); 
  }
  
  
  choose_song(which_song);
  Serial.printf("Choosing song %d\r\n", which_song);
  Serial.printf("Num_notes: %i\r\n", *num_notes);
  Serial.printf("BPM: %i\r\n", *bpm);
  Serial.printf("LED_NOTES:  ");
  for (int i=0; i < num_leds; i++) {
    Serial.printf("%i, ", led_notes[i]); 
  }
  Serial.printf("*********************************************\r\n");
  for (int i=0; i < 100; i++) {
    Serial.printf("\r\n");
  }
  Serial.printf("SONG:  \r\n");
  for (int i=0; i < (*num_notes*2); i+=2) {
    Serial.printf("    NOTE: %i, DURATION: %i\r\n", (*(song+i)), (*(song+i+1)));
  }

}

// initial setup for LEDs and speaker ports
void setup() {
 set_song_durations();  // Do this only in setup -- so as to not slow things down
 if (DEBUGME == 1) {
   Serial.begin(9600);
 }
 
 
 //
  pinMode(speaker_connect, OUTPUT);   
  for (int i=0; i < num_leds; i++) {
    pinMode(leds[i], OUTPUT);
  } 
  leds_off();
  delay(1000); // delay 1sec before starting music
}

// the loop routine runs over and over again forever
// basically like main with while(1).
void loop() {
 if (DEBUGME == 1) {
   debug_print_song(IMPERIAL_MARCH);
 }
 play_song(IMPERIAL_MARCH);
 delay(1000);
 play_song(JINGLE_BELL_ROCK);
 delay(1000);
 play_song(SUPER_MARIO);
 delay(1000);
  play_song(NFL);
 delay(1000); 
 play_song(SCALES); // doesn't work
 delay(1000);
}
    
    



