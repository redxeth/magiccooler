// Source: https://github.com/redxeth/magiccooler
//
// NOTE:  If have problems loading onto Teensy-- try higher quality USB cable!!!
//
// Credit to: http://www.instructables.com/id/How-to-easily-play-music-with-buzzer-on-arduino-Th/
// NB: ALL NOTES DEFINED WITH STANDARD ENGLISH NAMES, EXCEPT FOR "A"
// WHICH HERE IS CALLED "AA" BECAUSE A0,A1...ARE THE ANALOG PINS ON ARDUINO.
// (Ab IS CALLED Ab AND NOT AAb)
#define	Eb8	4978.03
#define	Ds8	4978.03
#define	DD8	4698.64
#define	Db8	4434.92
#define	Cs8	4434.92
#define	CC8	4186.01
#define	BB7	3951.07
#define	Bb7	3729.31
#define	As7	3729.31
#define	AA7	3520.00
#define	Ab7	3322.44
#define	Gs7	3322.44
#define	GG7	3135.96
#define	Gb7	2959.96
#define	Fs7	2959.96
#define	FF7	2793.83
#define	EE7	2637.02
#define	Eb7	2489.02
#define	Ds7	2489.02
#define	DD7	2349.32
#define	Db7	2217.46
#define	Cs7	2217.46
#define	CC7	2093.00
#define	BB6	1975.53
#define	Bb6	1864.66
#define	As6	1864.66
#define	AA6	1760.00
#define	Ab6	1661.22
#define	Gs6	1661.22
#define	GG6	1567.98
#define	Gb6	1479.98
#define	Fs6	1479.98
#define	FF6	1396.91
#define	EE6	1318.51
#define	Eb6	1244.51
#define	Ds6	1244.51
#define	DD6	1174.66
#define	Db6	1108.73
#define	Cs6	1108.73
#define	CC6	1046.50
#define	BB5	987.77
#define	Bb5	932.33
#define	As5	932.33
#define	AA5	880.00
#define	Ab5	830.61
#define	Gs5	830.61
#define	GG5	783.99
#define	Gb5	739.99
#define	Fs5	739.99
#define	FF5	698.46 // <-- highest treble line
#define	EE5	659.26
#define	Eb5	622.25
#define	Ds5	622.25
#define	DD5	587.33
#define	Db5	554.37
#define	Cs5	554.37
#define	CC5	523.25
#define	BB4	493.88
#define	Bb4	466.16
#define	As4	466.16
#define	AA4	440.00 // <-- 49th key on ideal piano A4 (440Hz)
#define	Ab4	415.30
#define	Gs4	415.30
#define	GG4	392.00 // <-- treble G
#define	Gb4	369.99
#define	Fs4	369.99
#define	FF4	349.23
#define	EE4	329.63 // <-- lowest treble line
#define	Eb4	311.13
#define	Ds4	311.13
#define	DD4	293.66
#define	Db4	277.18
#define	Cs4	277.18
#define	CC4	261.63 // <-- middle C
#define	BB3	246.94
#define	Bb3	233.08
#define	As3	233.08
#define	AA3	220.00
#define	Ab3	207.65
#define	Gs3	207.65
#define	GG3	196.00
#define	Gb3	185.00
#define	Fs3	185.00
#define	FF3	174.61
#define	EE3	164.81
#define	Eb3	155.56
#define	Ds3	155.56
#define	DD3	146.83
#define	Db3	138.59
#define	Cs3	138.59
#define	CC3	130.81
#define	BB2	123.47
#define	Bb2	116.54
#define	As2	116.54
#define	AA2	110.00
#define	Ab2	103.83
#define	Gs2	103.83
#define	GG2	98.00
#define	Gb2	92.50
#define	Fs2	92.50
#define	FF2	87.31
#define	EE2	82.41
#define	Eb2	77.78
#define	Ds2	77.78
#define	DD2	73.42
#define	Db2	69.30
#define	Cs2	69.30
#define	CC2	65.41
#define	BB1	61.74
#define	Bb1	58.27
#define	As1	58.27
#define	AA1	55.00
#define	Ab1	51.91
#define	Gs1	51.91
#define	GG1	49.00
#define	Gb1	46.25
#define	Fs1	46.25
#define	FF1	43.65
#define	EE1	41.20
#define	Eb1	38.89
#define	Ds1	38.89
#define	DD1	36.71
#define	Db1	34.65
#define	Cs1	34.65
#define	CC1	32.70
#define	BB0	30.87
#define	Bb0	29.14
#define	As0	29.14
#define	AA0	27.50
#define	Ab0	25.96
#define	Gs0	25.96
#define	GG0	24.50
#define	Gb0	23.12
#define	Fs0	23.12
#define	FF0	21.83
#define	EE0	20.60
#define	Eb0	19.45
#define	Ds0	19.45
#define	DD0	18.35
#define	Db0	17.32
#define	Cs0	17.32
#define	CC0	16.35

#define R       0        // rest

#define DEBUGME 0        // set to 0 for no debug, 1 for debug song arrays, 2 for print debug while playing music


// DURATION OF THE NOTES
#define S_S 1    // Q/4 // sixteenth 1/16
#define E   2    // Q/2   //eighth 1/8
#define Q   4    // 60000/bpm //quarter 1/4  // Here assumes 4/4 time signature!
#define H   8    // 2*Q //half 2/4
#define W   16   // 4*Q // whole 4/4
#define EE  8/3  // E*4/3 // slightly slow E or a quick Q

// song stuff
int songNum = 0;                                  // song being played
const int numSongs = 4;                           // number of songs to play

// relay stuff
const int num_relays = 10;                              // WRITE HERE TOTAL NUMBER OF RELAYS CONNECTED
const int controls[] =   {22,21,20,19,18,17,16,15,14,13};   // Digital output pin on Teensy associated with the relay number defined below
//const int relay_nums[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};   // Relay number used below associated with the digital pins in controls[]
const int relay_nums[] = { 1, 2, 3, 4, 5, 7, 8, 9, 1, 2}; // relays 0 and 6 (1 and 7) are not connected to reuse have notes share relays -- remap so 0 and 6 aren't used

// speaker stuff
const int speaker_connect = 23;                   // pin to which audio output (speaker, headphones) is connected

// switch stuff
const int switchPin = 10;                         // pin where switch is connected
int switchState;                                  // reading of switch

// Button stuff
const int buttonPin = 2;                          // pin where button is connected
int reading;                                      // a reading off the input pin (not yet used to set the state)
int buttonState;                                  // current reading on input pin
int lastButtonState = LOW;                        // last reading on input pin
long lastDebounceTime = 0;                        // last time input pin was toggled
long debounceDelay = 50;                          // debounce time in mS

// mode stuff
int modeState = 0;                                // mode of device -- used for test features
const int modeMax = 22;                           // put here maximum mode to use, see relays_by_mode() for details on mode usage

// Use pointers for global variables
int *song;           // use to point to array of int.  E.G. to assign since 2d array: song = *song0;            to use: *(*(song+i)+j) <-- questionable
int *relay_notes;    // use to point to array of int.  E.G. to assign since 1d array: relay_notes = relay_notes0;   to use: relay_notes[i];
int *bpm;            // use to point to int.           E.G.                to assign: bpm = &bpm0;              to use: *bpm
int *num_notes;      // use to point to int.           E.G.                to assign: num_notes = &num_notes0;  to use: *num_notes


// DH TODO LIST
//  - Randomizer-- play songs randomly
//  - Store songs in NVM! (256kB) and load into RAM upon 'choose song'.  Not sure the loading how to do yet... // PROGMEM in Arduino reference.  May have to modify to have
//    the durations based on BPM while song is playing-- and not precalculated as arrays are stored... or I guess they coud be stored then modified upon song switching?  Not
//    while song is playing
//  - need to o-scope what the output sound wave looks like -- DAC sinusoid?  what levels?
//  - Change relay selection from specifying the notes to having code prepare which relays to play based on notes automatically
//    so that it divides High and Low note of song against how many relays there are so that ALL notes get played
//    no matter how many various notes there are.
//  - Assign key to song-- so can shift key if desired (or even octave)
//  - easier way to defines songs, stores in file or SD card? use MIDI format or something...
//  - genre of song?
//  - title of song?
//  - multitone play capability (chords and 4-part harmony) -- up to 4 separate outputs!  Or some what to combine the tones so that only 1 output is still required
//  - button to choose song or go to next song (would have to interrupt song so would have to use interrupts).  Debounce obviously.

// Oh Little Town of Bethlehem - HYMN 361 (LSB)
int bpm0 = 120;         // WRITE HERE THE TEMPO OF THE SONG (BPM)
int song0[100][2] =  {  // WRITE HERE THE SONG IN FORMAT {{NOTE, DURATION}, {NOTE, DURATION}, ... {NOTE, DURATION}} MAX NOTES = 100
       {AA4,Q},{AA4,Q},{AA4,Q},{Gs4,Q},{AA4,Q},{CC5,Q},{Bb4,Q},{DD4,Q},{GG4,Q},{FF4,Q},{EE4,E},{FF4,E},{GG4,Q},{CC4,Q},{AA4,H+Q}, //15
       {AA4,Q},{AA4,Q},{AA4,Q},{DD5,Q},{CC5,Q},{CC5,Q},{Bb4,Q},{DD4,Q},{GG4,Q},{FF4,Q},{EE4,E},{FF4,E},{AA4,Q},{GG4,Q},{FF4,H+Q}, //15
       {AA4,Q},{AA4,Q},{AA4,Q},{GG4,Q},{FF4,Q},{EE4,H},{EE4,Q},{EE4,Q},{DD4,Q},{EE4,Q},{FF4,Q},{GG4,Q},{AA4,H+Q},                 //13
       {AA4,Q},{AA4,Q},{AA4,Q},{Gs4,Q},{AA4,Q},{CC5,Q},{Bb4,Q},{DD4,Q},{DD5,Q},{CC5,Q},{FF4,Q},{AA4,Q+E},{GG4,E},{FF4,H+Q}        //14
}; 

int num_notes0 = 57;    // WRITE HERE HOW MANY NOTES IN THE SONG!
int relay_notes0[]     = {CC4,DD4,EE4,FF4,GG4,Gs4,AA4,Bb4,CC5,DD5};  //be sure to have 10 notes (repeat a note if you have to!

/*
// TEST SONG
int bpm0 = 60;
int song0[100][2] =  {  // WRITE HERE THE SONG IN FORMAT {{NOTE, DURATION}, {NOTE, DURATION}, ... {NOTE, DURATION}} MAX NOTES = 100
       {CC4,Q},{DD4,Q},{EE4,Q},{FF4,Q},{GG4,Q},{Gs4,Q},{AA4,Q},{Bb4,Q},{CC5,Q},{DD5,Q},
};
int num_notes0 = 10;    // WRITE HERE HOW MANY NOTES IN THE SONG!

int relay_notes0[]     = {CC4,DD4,EE4,FF4,GG4,Gs4,AA4,Bb4,CC5,DD5};  //be sure to have 10 notes (repeat a note if you have to!
*/

// SONGS would like to add:
// Hark! The Herald Angels Sing (LSB 380)
// O Come, All Ye Faithful (LSB 379)
// O Come, O Come Emmanuel.. (LSB ??)
                                            

// Joy to the World - HYMN 387 (LSB)
int bpm1 = 120;
int song1[100][2] = {
      {DD5,Q},{Cs5,E+S_S},{BB4,S_S},{AA4,Q+E},{GG4,E},{Fs4,Q},{EE4,Q},{DD4,Q+E},{AA4,E},{BB4,Q+E},{BB4,E},{Cs5,Q+E},{Cs5,E}, //13
      {DD5,Q+E},{DD5,E},{DD5,E},{Cs5,E},{BB4,E},{AA4,E},{AA4,E+S_S},{GG4,S_S},{Fs4,E},{DD5,E},{DD5,E},{Cs5,E},{BB4,E},{AA4,E}, //14
      {AA4,E+S_S},{GG4,S_S},{Fs4,E},{Fs4,E},{Fs4,E},{Fs4,E},{Fs4,E},{Fs4,S_S},{GG4,S_S},{AA4,Q+E},{GG4,S_S},{Fs4,S_S},{EE4,E},{EE4,E},{EE4,E},{EE4,S_S},{Fs4,S_S}, //17
      {GG4,Q+E},{Fs4,S_S},{EE4,S_S},{DD4,E},{DD5,Q},{BB4,E},{AA4,E+S_S},{GG4,S_S},{Fs4,E},{GG4,E},{Fs4,Q},{EE4,Q},{DD4,H} //13 
};
int num_notes1 = 57;
int relay_notes1[] = {DD4,EE4,FF4,Fs4,GG4,AA4,BB4,Cs5,DD5,DD4}; //be sure to have 10 notes (repeat a note if you have to!



// Silent Night, Holy Night - HYMN 646 (TLH)
int bpm2 = 120;
int song2[100][2] = {
   {GG4,Q+E},{AA4,E},{GG4,Q},{EE4,H+Q},{GG4,Q+E},{AA4,E},{GG4,Q},{EE4,H+Q},{DD5,H},{DD5,Q},{BB4,H+Q}, //11
   {CC5,H},{CC5,Q},{GG4,H+Q},{AA4,H},{AA4,Q},{CC5,Q+E},{BB4,E},{AA4,Q},{GG4,Q+E},{AA4,E},{GG4,Q},{EE4,H+Q}, //12
   {AA4,H},{AA4,Q},{CC5,Q+E},{BB4,E},{AA4,Q},{GG4,Q+E},{AA4,E},{GG4,Q},{EE4,H+Q},{DD5,H},{DD5,Q}, //11
   {FF5,Q+E},{DD5,E},{BB4,Q},{CC5,H+Q},{EE5,H+Q},{CC5,Q+E},{GG4,E},{EE4,Q},{GG4,Q+E},{FF4,E},{DD4,Q},{CC4,H},{CC4,H} //13


};
int num_notes2 = 47;
int relay_notes2[] = {CC4,EE4,FF4,GG4,AA4,BB4,CC5,DD5,EE5,FF5};  //be sure to have 10 notes (repeat a note if you have to!


// O Come, O Come, Emmanuel - HYMN 357 (LSB)
int bpm3 = 60;
int song3[100][2] = {
   {EE4,E},{GG4,E},{BB4, E},{BB4, E},{BB4, E},{AA4, E},{CC5, E},{BB4, E},{AA4, E},{GG4, Q+E},{AA4, E},{BB4, E},{GG4, E},{EE4, E},{GG4, E}, //15
   {AA4, E},{Fs4, E},{EE4, E},{DD4, E},{EE4, Q+E},{AA4, E},{AA4, E},{EE4, E},{EE4, E},{Fs4, E},{GG4, Q},{Fs4, E},{EE4, E},{DD4, Q+E},  //14
 {GG4, E},{AA4, E},{BB4, E},{BB4, E},{BB4, E},{AA4, E},{CC5, E},{BB4, E},{AA4, E},{GG4, Q+E},{DD5, E},{DD5, Q+E},{BB4, E}, {BB4,Q+E},//14
 {BB4,E},{AA4, E},{CC5, E},{BB4, E},{AA4, E},{GG4, Q+E},{AA4, E},{BB4, E},{GG4, E},{EE4, E},{GG4, E},{AA4, E},{Fs4, E},{EE4, E},{DD4, E},{EE4, Q+E} //16
};
int num_notes3 = 59;
int relay_notes3[] = {CC4,DD4,EE4,Fs4,GG4,AA4,BB4,CC5,CC4,DD4};  //be sure to have 10 notes (repeat a note if you have to!


// **********************************************************************************************
// **********************************************************************************************
// ******       DO NOT MODIFY BELOW THIS LINE!!! SONGS CODED ABOVE!  ****************************
// **********************************************************************************************
// **********************************************************************************************

/*
// assign relays to each song
void set_song_relays() {
  // find highest and lowest note in song
  // set markers for 
} */


// set song durations
// do once in setup only
void set_song_durations() {
  int i, j, duration;
  
  for(i=0; i < numSongs; i++){
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
  if (DEBUGME == 1) {
    Serial.printf("Song Chosen: %i\r\n", which_song);
  }
  switch (which_song) {
   case 0: 
      bpm = &bpm0;                         // assign pointer to address of variable
      num_notes = &num_notes0;             // assign pointer to address of variable
      song = *song0;                       // assign pointer to 2d array (basically pointer contains address of 2d array)
      relay_notes = relay_notes0;          // assign pointer to 1d array (basically pointer contains address of first element of 1d array)    
      break;
    case 1:
      bpm = &bpm1;
      num_notes = &num_notes1;
      song = *song1;
      relay_notes = relay_notes1;
      break;
    case 2:
      bpm = &bpm2;
      num_notes = &num_notes2;
      song = *song2;
      relay_notes = relay_notes2;
      break; 
    case 3:
      bpm = &bpm3;
      num_notes = &num_notes3;
      song = *song3;
      relay_notes = relay_notes3;
      break;   } 
}




// set relay on or off that matches note
void match_relay(int note, int state) {
  
  // only set or unset relays that match the note
  for (int i=0; i < num_relays; i++) {
    if (relay_notes[i] == note) {
      if (DEBUGME == 1) {
        Serial.printf("Match Found at i = : %i, relay_notes[i] = %i, relay_nums[i] = %i, controls[relay_nums[i]] = %i \r\n", i, relay_notes[i], relay_nums[i], controls[relay_nums[i]]);
      }
      digitalWrite(controls[relay_nums[i]],state); // set control
    } 
  } 
}

// Plays a single note
void play_note(int note, long duration) {
  match_relay(note, LOW);               // turn on relay if matches note
  
  if (note != R) {                 // only play if not a rest
    tone(speaker_connect, note, duration); // http://arduino.cc/en/Reference/Tone // pin, freq of tone in Hz (unsigned int), duration in mS (unsigned long)
  }
  delay(duration);  
  noTone(speaker_connect); // Fix intermittent issue where doesn't play properly on Teensy 3.1 if tone() called back to back
  
  match_relay(note, HIGH);               // turn off relay if matches note
  delay(5); // note separator -- DH maybe needs to be bigger?
}

// Play an entire song
void play_song(int which_song) {
  int note, duration;
  choose_song(which_song);
  //int len = sizeof(melody)/sizeof(int);
  if (DEBUGME == 1) {
    Serial.printf("Play Song: %i\r\n", which_song);
  }
  for (int i=0; i < (*num_notes*2); i+=2) {
    note = *(song+i);             // equiv to note = song[i][0]
    duration = *(song+i+1);       // equiv to duration = song[i][1]
    play_note(note, duration);
  }
}

/*  NOT DEBUGGED LATELY
// for debug prints out the song assigned
void debug_print_song(int which_song) {
  // FOR DEBUG ONLY

  Serial.printf("*********************************************\r\n");  
  Serial.printf("Num_notes0: %i\r\n", num_notes0);
  Serial.printf("BPM0: %i\r\n", bpm0);
  Serial.printf("relay_notes0:  ");
  for (int i=0; i < num_relays; i++) {
    Serial.printf("%i, ", relay_notes0[i]); 
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
  Serial.printf("relay_notes:  ");
  for (int i=0; i < num_relays; i++) {
    Serial.printf("%i, ", relay_notes[i]); 
  }
  Serial.printf("*********************************************\r\n");
  for (int i=0; i < 100; i++) {
    Serial.printf("\r\n");
  }
  Serial.printf("SONG:  \r\n");
  for (int i=0; i < (*num_notes*2); i+=2) {
    Serial.printf("    NOTE: %i, DURATION: %i\r\n", (*(song+i)), (*(song+i+1)));
  }

} */


////////////// RELAY BUTTON STUFF

// handle reading the button, debounce
// causes modeState to change
void buttonStuff() {
  // read current state of input pin
  reading = digitalRead(buttonPin);
 
  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      // then change current buttonState
      buttonState = reading;

      // only toggle the relay if the new button state is HIGH
      if (buttonState == HIGH) {
        // CHANGE MODE
        if (modeState < modeMax) {
          modeState++;
        } else {
          modeState=0;
        }
      }
    }
  }
  // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  lastButtonState = reading;
}

// handle switch
void switchStuff() {
  switchState = digitalRead(switchPin);
}

// Turn on only one specific relay
// option to leave other relays on if already on
void relays_by_num(int which_relay, int leaveon) {
  
  for (int i=0; i < num_relays; i++) {
    if (i == which_relay - 1) {
      digitalWrite(controls[i],LOW);  
    } else {
      if (leaveon == LOW) {
      digitalWrite(controls[i],HIGH);  
    }
  }
}
}

// Set relays according to mode
// mode            function
// 0               all relays off
// 1-10            activate that particular relay only
// 11              all relays on
// 12              all relays off
// 13-22           turn relays on but leave them on as you turn them on, to test out how many can be turned on at once...

void relays_by_mode() {
 if (DEBUGME == 1) {
   Serial.printf("Mode %i\r\n",modeState);
 }
  switch (modeState) {
    case 0:
        all_relays_off();
      break;
    case 11:
        all_relays_on();
      break;
    case 12:
      all_relays_off();
      break;
    default: // 1-10 or 13-22
      if (modeState < 11) // relays 1 to 10, one at a time
        relays_by_num(modeState,LOW);
      else
        relays_by_num(modeState-12,HIGH); // relays 1 to 10, leave on as turn on      
      break;
  }
}

// Turn on all relays
void all_relays_on() {
  for (int i=0; i < num_relays; i++) {
    digitalWrite(controls[i],LOW);  
  }
}

// Turn off all relays
void all_relays_off() {
  for (int i=0; i < num_relays; i++) {
    digitalWrite(controls[i],HIGH);  
  }
}


// initial setup for relays and speaker ports
void setup() {
 // Do this only in setup -- so as to not slow things down 
 set_song_durations();
 
 if (DEBUGME == 1) {
   Serial.begin(9600);
 }
 // set inputs
 pinMode(buttonPin, INPUT);
 pinMode(switchPin, INPUT);

 // set outputs
  pinMode(speaker_connect, OUTPUT);   
  for (int i=0; i < num_relays; i++) {
    pinMode(controls[i], OUTPUT);
  } 
  all_relays_off();
  delay(1000); // delay 1sec before starting music

  modeState = 0;

}

// the loop routine runs over and over again forever
// basically like main with while(1).
void loop() {

  // handle the switch
  switchStuff();

  // handle the button
  buttonStuff();
 
  if (switchState == HIGH) {
    // test mode for testing relays
    relays_by_mode();
    //songNum=0;
  } else {
    // play songs normally
    if (DEBUGME == 1) {
      Serial.printf("Play Song %i\r\n", 0);
    } 
   play_song(songNum);
   if (songNum < numSongs - 1){
     songNum++;
   } else {
     songNum=0;
   } 
    // wait a second between songs
    if (DEBUGME == 1) {
      Serial.printf("Delay 1 second\r\n");
    }
    delay(1000);
  }
  
//  play_song(3);
//  delay(1000);
 
}
    
    



