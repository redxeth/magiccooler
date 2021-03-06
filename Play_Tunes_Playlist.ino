// Source: https://github.com/redxeth/magiccooler
//
// Credit to: http://www.instructables.com/id/How-to-easily-play-music-with-buzzer-on-arduino-Th/
// NB: ALL NOTES DEFINED WITH STANDARD ENGLISH NAMES, EXCEPT FOR "A"
// WHICH HERE IS CALLED "AA" BECAUSE A0,A1...ARE THE ANALOG PINS ON ARDUINO.
// (Ab IS CALLED Ab AND NOT AAb)
#define	CC0     16.35
#define	Cs0	17.32
#define	Db0	17.32
#define	DD0	18.35
#define	Ds0	19.45
#define	Eb0	19.45
#define	EE0	20.60
#define	FF0	21.83
#define	Fs0	23.12
#define	Gb0	23.12
#define	GG0	24.50
#define Gs0     25.96
#define	Ab0	25.96
#define	AA0	27.50
#define As0     29.14
#define	Bb0	29.14
#define	BB0	30.87
#define	CC1	32.70
#define Cs1     34.65
#define	Db1	34.65
#define	DD1	36.71
#define Ds1     38.89
#define	Eb1	38.89
#define	EE1	41.20
#define	FF1	43.65
#define	Fs1	46.25
#define	Gb1	46.25
#define	GG1	49.00
#define	Gs1	51.91
#define	Ab1	51.91
#define	AA1	55.00
#define As1     58.27
#define	Bb1	58.27
#define	BB1	61.74
#define	CC2	65.41
#define Cs2     69.30
#define	Db2	69.30
#define	DD2	73.42
#define Ds2     77.78
#define	Eb2	77.78
#define	EE2	82.41
#define	FF2	87.31
#define Fs2     92.50
#define	Gb2	92.50
#define	GG2	98.00
#define Gs2     103.83
#define	Ab2	103.83
#define	AA2	110.00
#define As2     116.54
#define	Bb2	116.54
#define	BB2	123.47
#define	CC3	130.81
#define	Cs3	138.59
#define	Db3	138.59
#define	DD3	146.83
#define	Ds3	155.56
#define	Eb3	155.56
#define	EE3	164.81
#define	FF3	174.61
#define	Fs3	185.00
#define	Gb3	185.00
#define	GG3	196.00
#define	Gs3	207.65
#define	Ab3	207.65
#define	AA3	220.00
#define	As3	233.08
#define	Bb3	233.08
#define	BB3	246.94
#define	CC4	261.63 // <-- MIDDLE C
#define	Cs4	277.18
#define	Db4	277.18
#define	DD4	293.66
#define	Ds4	311.13
#define	Eb4	311.13
#define	EE4	329.63
#define	FF4	349.23
#define	Fs4	369.99
#define	Gb4	369.99
#define	GG4	392.00
#define	Gs4	415.30
#define	Ab4	415.30
#define	AA4	440.00
#define	As4	466.16
#define	Bb4	466.16
#define	BB4	493.88
#define	CC5	523.25
#define	Cs5	554.37
#define	Db5	554.37
#define	DD5	587.33
#define	Ds5	622.25
#define	Eb5	622.25
#define	EE5	659.26
#define	FF5	698.46
#define	Fs5	739.99
#define	Gb5	739.99
#define	GG5	783.99
#define	Gs5	830.61
#define	Ab5	830.61
#define	AA5	880.00
#define	As5	932.33
#define	Bb5	932.33
#define	BB5	987.77
#define	CC6	1046.50
#define	Cs6	1108.73
#define	Db6	1108.73
#define	DD6	1174.66
#define	Ds6	1244.51
#define	Eb6	1244.51
#define	EE6	1318.51
#define	FF6	1396.91
#define	Fs6	1479.98
#define	Gb6	1479.98
#define	GG6	1567.98
#define	Gs6	1661.22
#define	Ab6	1661.22
#define	AA6	1760.00
#define	As6	1864.66
#define	Bb6	1864.66
#define	BB6	1975.53
#define	CC7	2093.00
#define	Cs7	2217.46
#define	Db7	2217.46
#define	DD7	2349.32
#define	Ds7	2489.02
#define	Eb7	2489.02
#define	EE7	2637.02
#define	FF7	2793.83
#define	Fs7	2959.96
#define	Gb7	2959.96
#define	GG7	3135.96
#define	Gs7	3322.44
#define	Ab7	3322.44
#define	AA7	3520.01
#define	As7	3729.31
#define	Bb7	3729.31
#define	BB7	3951.07
#define	CC8	4186.01
#define	Cs8	4434.92
#define	Db8	4434.92
#define	DD8	4698.64
#define	Ds8	4978.03
#define	Eb8	4978.03
#define R       0        // rest

#define DEBUGME 0        // set to 0 for no debug, 1 for debug song arrays, 2 for print debug while playing music
#define RANDOM 0         // set to 0 for play songs sequential, 1 for random play

// DURATION OF THE NOTES
#define S_S 1    // Q/4 // sixteenth 1/16
#define E   2    // Q/2   //eighth 1/8
#define Q   4    // 60000/bpm //quarter 1/4  // Here assumes 4/4 time signature!
#define H   8    // 2*Q //half 2/4
#define W   16   // 4*Q // whole 4/4
#define EE  8/3  // E*4/3 // slightly slow E or a quick Q

// Here list songs by name
#define IMPERIAL_MARCH             0  //DH
#define JINGLE_BELL_ROCK           1  //DH
#define SUPER_MARIO                2  //DH
#define NFL                        3  //DH
#define SCALES                     4  //DH
#define ODE_TO_JOY                 5  //DH
#define MOUNTAIN_KING              6  //DH
#define BAA_BAA                    7  //GRH
#define BAT_MAN                    8  //DH
#define GILLIGAN                   9  //DH
#define STAR_WARS                  10 //DH
#define TWINKLE_TWINKLE            11 //GRH
#define CLOCKS                     12 //GRH
#define POKER_FACE                 13 //GRH
#define AVENGERS                   14 //Bryan's song
#define INSPECTOR_GADGET           15 //DH
#define AUDITION                   16 //Kid?
#define MULBERRY_BUSH              17 //Luka
#define LONDON_BRIDGE              18 //SH
#define HAPPY_BIRTHDAY             19 //SH
#define SHOO_FLY                   20 //SH
#define NUM_SONGS                  21 // update to be total number of songs in playlist

// FUTURE SONGS
//  - what child is this
//  - blackbird
//  - house of the rising sun
//  - good bad and ugly
//  - chestnuts roasting on open fire
//  - dear prudence

int num_leds = 10;                                // WRITE HERE TOTAL NUMBER OF LEDS CONNECTED
int speaker_connect = 23;                         // WRITE HERE WHICH PIN THE SPEAKER IS CONNECTED TO
int switch_connect = 0;                           // WRITE HERE WHICH PIN THE MODE SWITCH IS CONNECTED TO
int leds[] = {22,21,20,19,18,17,16,15,14,13};     // WRITE HERE WHICH PIN THE LEDS ARE CONNECTED TO:  1, 2, 3, 4, 5 .... 
int music_mode;                                   // mode read from switch

// Use pointers for global variables
int *song;           // use to point to array of int.  E.G. to assign since 2d array: song = *song0;            to use: *(*(song+i)+j) <-- questionable
int *led_notes;      // use to point to array of int.  E.G. to assign since 1d array: led_notes = led_notes0;   to use: led_notes[i];
int *bpm;            // use to point to int.           E.G.                to assign: bpm = &bpm0;              to use: *bpm
int *num_notes;      // use to point to int.           E.G.                to assign: num_notes = &num_notes0;  to use: *num_notes


// DH TODO LIST
//  - Need a way to prevent skipping lights!!
//  - Randomizer-- play songs randomly
//  - Store songs in NVM! (256kB) and load into RAM upon 'choose song'.  Not sure the loading how to do yet... // PROGMEM in Arduino reference.  May have to modify to have
//    the durations based on BPM while song is playing-- and not precalculated as arrays are stored... or I guess they coud be stored then modified upon song switching?  Not
//    while song is playing
//  - need to o-scope what the output sound wave looks like -- DAC sinusoid?  what levels?
//  - Change LED selection from specifying the notes to having code prepare which LEDs to play based on notes automatically
//    so that it divides High and Low note of song against how many LEDs there are so that ALL notes get played
//    no matter how many various notes there are.
//  - Assign key to song-- so can shift key if desired (or even octave)
//  - easier way to defines songs, stores in file or SD card? use MIDI format or something...
//  - genre of song?
//  - title of song?
//  - multitone play capability (chords and 4-part harmony) -- up to 4 separate outputs!  Or some what to combine the tones so that only 1 output is still required
//  - button to choose song or go to next song (would have to interrupt song so would have to use interrupts).  Debounce obviously.





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
int led_notes0[] = {Ab3,AA3,BB3,FF3,CC4,EE4,FF4,Gb4,Ab4,GG4};  //WRITE HERE WHAT NOTES TO LINK TO WHICH LEDS, MUST BE SAME NUMBER AS NUMBER OF LEDS ABOVE!

                                            


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
int led_notes3[] = {CC3,CC4,Db4,Eb4,GG4,Ab4,GG5,Ab5,BB5,CC6};



// PLAY SCALES
int bpm4 = 112;
int song4[100][2] = {
// half notes
  {CC4,H},{DD4,H},{EE4,H},{FF4,H},{GG4,H},{AA4,H},{BB4,H},{CC5,H},{DD5,H},{EE5,H},
  {DD5,H},{CC5,H},{BB4,H},{AA4,H},{GG4,H},{FF4,H},{EE4,H},{DD4,H},{CC4,H},
  {R,S_S},

// quarter notes
  {CC4,Q},{DD4,Q},{EE4,Q},{FF4,Q},{GG4,Q},{AA4,Q},{BB4,Q},{CC5,Q},{DD5,Q},{EE5,Q},
  {DD5,Q},{CC5,Q},{BB4,Q},{AA4,Q},{GG4,Q},{FF4,Q},{EE4,Q},{DD4,Q},{CC4,Q},
  {R,S_S},

// sixteenth notes
  {CC4,S_S},{DD4,S_S},{EE4,S_S},{FF4,S_S},{GG4,S_S},{AA4,S_S},{BB4,S_S},{CC5,S_S},{DD5,S_S},{EE5,S_S},
  {DD5,S_S},{CC5,S_S},{BB4,S_S},{AA4,S_S},{GG4,S_S},{FF4,S_S},{EE4,S_S},{DD4,S_S},{CC4,S_S},
  {R,S_S}

};
int num_notes4 = 66;
int led_notes4[] = {CC4,DD4,EE4,FF4,GG4,AA4,BB4,CC5,DD5,EE5};



// ODE TO JOY
int bpm5 = 120;
int song5[100][2] = {{EE4,Q},{EE4,Q},{FF4,Q},{GG4,Q},{GG4,Q},{FF4,Q},{EE4,Q},{DD4,Q},
                     {CC4,Q},{CC4,Q},{DD4,Q},{EE4,Q},{EE4,Q},{DD4,Q},{DD4,H},
                     {EE4,Q},{EE4,Q},{FF4,Q},{GG4,Q},{GG4,Q},{FF4,Q},{EE4,Q},{DD4,Q},
                     {CC4,Q},{CC4,Q},{DD4,Q},{EE4,Q},{DD4,Q},{CC4,Q},{CC4,H},
                     
                     {DD4,Q},{DD4,Q},{EE4,Q},{CC4,Q},{DD4,Q},{FF4,Q},{EE4,Q},{CC4,Q},
                     {DD4,Q},{FF4,Q},{EE4,Q},{DD4,Q},{CC4,Q},{DD4,Q},{GG4,H},                     
                     {EE4,Q},{EE4,Q},{FF4,Q},{GG4,Q},{GG4,Q},{FF4,Q},{EE4,Q},{DD4,Q},
                     {CC4,Q},{CC4,Q},{DD4,Q},{EE4,Q},{DD4,Q},{CC4,Q},{CC4,H}                     
};


int num_notes5 = 60;
int led_notes5[] = {CC4,DD4,EE4,FF4,GG4};


// IN THE HALL OF THE MOUNTAIN KING
int bpm6 = 120;
int song6[200][2] = {
                     {AA3,E},{BB3,E},{CC4,E},{DD4,E},{EE4,E},{CC4,E},{EE4,Q},          // meas 1
                     {Ds4,E},{BB3,E},{Ds4,Q},{DD4,E},{Bb3,E},{DD4,Q},                  // meas 2
                     {AA3,E},{BB3,E},{CC4,E},{DD4,E},{EE4,E},{CC4,E},{EE4,E},{AA4,E},  // meas 3
                     {GG4,E},{EE4,E},{CC4,E},{EE4,E},{GG4,H},                          // meas 4
                     
                     {AA4,E},{BB4,E},{CC5,E},{DD5,E},{EE5,E},{CC5,E},{EE5,Q},          // meas 5
                     {Ds5,E},{BB4,E},{Ds5,Q},{DD5,E},{Bb4,E},{DD5,Q},                  // meas 6
                     {AA4,E},{BB4,E},{CC5,E},{DD5,E},{EE5,E},{CC5,E},{EE5,E},{AA5,E},  // meas 7
                     {GG5,E},{EE5,E},{CC5,E},{EE5,E},{GG5,H},                          // meas 8
                     
                     {EE4,E},{Fs4,E},{Gs4,E},{AA4,E},{BB4,E},{Ab4,E},{BB4,Q},          // meas 9
                     {CC5,E},{Gs4,E},{CC5,Q},{BB4,E},{Gs4,E},{BB4,Q},                  // meas 10
                     {EE4,E},{Fs4,E},{Gs4,E},{AA4,E},{BB4,E},{Ab4,E},{BB4,Q},          // meas 11
                     {CC5,E},{Gs4,E},{CC5,Q},{BB4,H},                                  // meas 12
                     
                     {EE4,E},{Fs4,E},{Gs4,E},{AA4,E},{BB4,E},{Ab4,E},{BB4,Q},          // meas 13 (repeat 9)
                     {CC5,E},{Gs4,E},{CC5,Q},{BB4,E},{Gs4,E},{BB4,Q},                  // meas 14 (repeat 10)
                     {EE4,E},{Fs4,E},{Gs4,E},{AA4,E},{BB4,E},{Ab4,E},{BB4,Q},          // meas 15 (repeat 11)
                     {CC5,E},{Gs4,E},{CC5,Q},{BB4,H},                                  // meas 16 (repeat 12)

                     {AA3,E},{BB3,E},{CC4,E},{DD4,E},{EE4,E},{CC4,E},{EE4,Q},          // meas 17
                     {Ds4,E},{BB3,E},{Ds4,Q},{DD4,E},{Bb3,E},{DD4,Q},                  // meas 18
                     {AA3,E},{BB3,E},{CC4,E},{DD4,E},{EE4,E},{CC4,E},{EE4,E},{AA4,E},  // meas 19
                     {GG4,E},{EE4,E},{CC4,E},{EE4,E},{AA3,H}                           // meas 20
                     

};

int num_notes6 = 126; // 20 measures

int led_notes6[] = {AA3,Bb3,BB3,CC4,DD4,Eb4,EE4,CC5,DD5,EE5};


// BAA BAA BLACK SHEEP
int bpm7 = 120;
int song7[52][2] = {
                      {CC4,Q}, {CC4,Q}, {GG4,Q}, {GG4,Q}, {AA4,E}, {AA4,E}, {AA4,E}, {AA4,E}, {GG4,H}, //9 Baa baa black sheep, have you any wool?
                      {FF4,Q}, {FF4,Q}, {EE4,Q},{EE4,Q}, {DD4,Q}, {DD4,Q},  {CC4,H}, //7 Yes sir, yes sir, three bags full.
                      {GG4,Q}, {GG4,E}, {GG4,E}, {FF4,Q}, {FF4,Q}, {EE4,Q}, {EE4,E}, {EE4,E}, {DD4,H}, //9
                      {GG4,Q}, {GG4,E}, {GG4,E}, {FF4,E}, {FF4,E}, {FF4,E}, {FF4,E}, {EE4,Q}, {EE4,E}, {EE4,E}, {DD4,H}, //11
                      {CC4,Q}, {CC4,Q}, {GG4,Q}, {GG4,Q}, {AA4,E}, {AA4,E}, {AA4,E}, {AA4,E}, {GG4,H}, //9 Baa baa black sheep, have you any wool?
                      {FF4,Q}, {FF4,Q}, {EE4,Q},{EE4,Q}, {DD4,Q}, {DD4,Q},  {CC4,H}, //7 Yes sir, yes sir, three bags full.
};
int num_notes7 = 52;
int led_notes7[] = {CC4,DD4,EE4,FF4,GG4,AA4,BB4,CC5,DD5,EE5};



// THE BATMAN THEME
int bpm8 = 240;
int song8[200][2] = {
                        {DD3,Q},{DD3,Q},{Db3,Q},{Db3,Q}, //meas 1
                        {CC3,Q},{CC3,Q},{Cs3,Q},{Cs3,Q}, //meas 2
                        {DD3,Q},{DD3,Q},{Db3,Q},{Db3,Q}, //meas 3
                        {CC3,Q},{CC3,Q},{Cs3,Q},{Cs3,Q}, //meas 4

                        {DD3,Q},{DD3,Q},{Db3,Q},{Db3,Q}, //meas 5
                        {CC3,Q},{CC3,Q},{Cs3,Q},{Cs3,Q}, //meas 6
                        {DD3,Q},{DD3,Q},{Db3,Q},{Db3,Q}, //meas 7
                        {CC3,Q},{CC3,Q},{Cs3,Q},{Ds3,Q}, //meas 8
                        
                        {GG3,Q},{GG3,Q},{Gb3,Q},{Gb3,Q}, //meas 9
                        {FF3,Q},{FF3,Q},{Fs3,Q},{Fs3,Q}, //meas 10
                        {GG3,Q},{GG3,Q},{Gb3,Q},{Gb3,Q}, //meas 11
                        {FF3,Q},{FF3,Q},{Fs3,Q},{Gs3,Q}, //meas 12

                        {DD3,Q},{DD3,Q},{Db3,Q},{Db3,Q}, //meas 13
                        {CC3,Q},{CC3,Q},{Cs3,Q},{Cs3,Q}, //meas 14
                        {DD3,Q},{DD3,Q},{Db3,Q},{Db3,Q}, //meas 15
                        {CC3,Q},{CC3,Q},{Cs3,Q},{Ds3,Q}, //meas 16
                        
                        {AA3,Q},{AA3,Q},{Ab3,Q},{Ab3,Q}, //meas 17
                        {GG3,Q},{GG3,Q},{Gs3,Q},{AA3,Q}, //meas 18                        
                        {GG3,Q},{GG3,Q},{Gb3,Q},{Gb3,Q}, //meas 19                        
                        {FF3,Q},{FF3,Q},{Fs3,Q},{GG3,Q}, //meas 20

                        {DD3,Q},{DD3,Q},{Db3,Q},{Db3,Q}, //meas 21
                        {CC3,Q},{CC3,Q},{Cs3,Q},{Cs3,Q}, //meas 22
                        {DD3,Q},{DD3,Q},{Db3,Q},{Db3,Q}, //meas 23
                        {CC3,Q},{CC3,Q},{Cs3,Q},{Cs3,Q}, //meas 24 
                        
                        {DD4,Q},{DD4,Q},{Db4,Q},{Db4,Q}, //meas 25
                        {CC4,Q},{CC4,Q},{Cs4,Q},{Cs4,Q}, //meas 26
                        {DD4,Q},{DD4,Q},{Db4,Q},{Db4,Q}, //meas 27
                        {CC4,Q},{CC4,Q},{Cs4,Q},{Cs4,Q}, //meas 28 
                        
                        {DD5,Q},{DD5,Q},{Cs5,Q},{Cs5,Q}, //meas 29
                        {CC5,Q},{CC5,Q},{Cs5,Q},{Cs5,Q}, //meas 30
                        {DD5,Q},{R,H},                   //meas 31
                        {FF5,H},{R,S_S},{FF5,H},{FF5,W}  //meas 32
                        

}; 
int num_notes8 = 126;
int led_notes8[] ={CC3,DD3,Db3,FF3,Fs3,Gb3,GG3,Ab3,AA3,CC5};


// GILLIGAN'S ISLAND
int bpm9 = 160;
int song9[200][2] = { {AA4,Q},                                 //meas 0

                      {DD4,Q},{AA4,Q},{AA4,Q},{AA4,E},{AA4,E}, //meas 1
                      {GG4,Q},{EE4,Q},{CC4,Q},{R,E},{CC4,E},   //meas 2
                      {DD4,Q},{AA4,E},{AA4,E},{AA4,Q},{AA4,Q}, //meas 3
                     
                      {GG4,H},{R,Q},{EE4,Q},                   //meas 4
                      {DD4,Q},{AA4,Q},{AA4,Q},{AA4,Q},         //meas 5
                      {GG4,Q},{CC5,Q},{CC5,Q},{GG4,Q},         //meas 6
                      {FF4,Q},{FF4,Q},{EE4,Q},{CC4,Q},         //meas 7

                      {DD4,H},{R,Q},{DD4,Q},                   //meas 8 (repeat 1)
                      {DD4,Q},{AA4,Q},{AA4,Q},{AA4,E},{AA4,E}, //meas 1
                      {GG4,Q},{EE4,Q},{CC4,Q},{R,E},{CC4,E},   //meas 2
                      {DD4,Q},{AA4,E},{AA4,E},{AA4,Q},{AA4,Q}, //meas 3
                     
                      {GG4,H},{R,Q},{EE4,Q},                   //meas 4
                      {DD4,Q},{AA4,Q},{AA4,Q},{AA4,Q},         //meas 5
                      {GG4,Q},{CC5,Q},{CC5,Q},{GG4,Q},         //meas 6
                      {FF4,Q},{FF4,Q},{EE4,Q},{CC4,Q},         //meas 7

                      {DD4,H},{R,Q},{DD4,Q},                   //meas 8 (repeat 2)
                      {FF4,H},{EE4,Q},{CC4,Q},                 //meas 9
                      {DD4,H},{R,Q},{DD4,Q},                   //meas 10
                      
                      {EE4,Q},{BB4,Q},{BB4,Q},{BB4,Q},         //meas 11
                      {AA4,Q},{Fs4,Q},{DD4,Q},{R,E},{DD4,E},   //meas 12
                      {EE4,Q},{BB4,Q},{BB4,Q},{BB4,Q},         //meas 13
                      
                      {AA4,H},{R,Q},{AA4,Q},                   //meas 14
                      {EE4,Q},{BB4,E},{BB4,E},{BB4,E},{BB4,E},{BB4,E},{BB4,E}, //meas 15
                      {AA4,Q},{DD5,Q},{DD5,Q},{AA4,Q},         //meas 15
                      {GG4,Q},{GG4,Q},{Fs4,Q},{DD4,Q},         //meas 16
                      {EE4,H},{R,Q},{EE4,Q},                   //meas 17
                      {GG4,Q},{GG4,Q},{Fs4,Q},{DD4,Q},         //meas 18
                      {EE4,H},{R,Q},{DD4,Q},                   //meas 19
                      
                      
                      {EE4,Q},{BB4,Q},{BB4,Q},{BB4,E},{BB4,E},
                      {AA4,Q},{Fs4,Q},{DD4,Q},{DD4,Q},
                      {EE4,Q},{BB4,Q},{BB4,Q},{BB4,Q},
                      {AA4,H},{R,Q},{DD4,Q},
                      
                      {EE4,Q},{BB4,Q},{BB4,H+H},               // Gilligan
                      {GG4,Q},{AA4,Q},{DD4,Q},{DD4,H+H},{R,Q}, // the skipper too
                      {DD4,Q},{EE4,Q},{BB4,Q},{BB4,H+H},       // the millionaire
                      {AA4,Q},{GG4,Q},{AA4,W},                 // and his wife
                      {R,Q},{Fs4,Q},{EE4,H},{BB4,Q},{AA4,H},   // the movie star
                      {R,Q},{Fs4,E},{Fs4,E},{EE4,Q},{EE4,Q},   // the professor
                      {BB4,H},{AA4,Q},{AA4,Q},{DD5,H},         // and Mary Ann,
                      
                      {R,Q},{EE5,H},{EE5,Q},                   // here on 
                      {Fs5,Q},{Fs5,Q},{DD5,H},                 // Gilligan's
                      {EE5,W+Q}                                // Isle!
                      
}; 
int num_notes9 = 166;
int led_notes9[]={AA4,BB4,CC4,DD4,EE4,FF4,DD5,GG4,DD5,EE5};

 
// STAR WARS
int bpm10 = 140;
int song10[200][2] = {
                     {DD4,E},{DD4,E},{DD4,E},                  //meas 1
                     {GG4,H},{DD5,H},                          //meas 2
                     {CC5,E},{BB4,E},{AA4,E},{GG5,H},{DD5,Q},  //meas 3
                     {CC5,E},{BB4,E},{AA4,E},{GG5,H},{DD5,Q},  //meas 4
                     {CC5,E},{BB4,E},{CC5,E},{AA4,H},{R,Q},{DD4,E},{DD4,E},{DD4,E},    //meas 5 (23)
                     
                     {GG4,H},{DD5,H},                          //meas 6
                     {CC5,E},{BB4,E},{AA4,E},{GG5,H},{DD5,Q},  //meas 7
                     {CC5,E},{BB4,E},{AA4,E},{GG5,H},{DD5,Q},  //meas 8
                     {CC5,E},{BB4,E},{CC5,E},{AA4,H},{R,Q},{DD4,E},{DD4,E},    //meas 9 (41)
                     
                     {EE4,Q+E},{EE4,E},{CC5,E},{BB4,E},{AA4,E},{GG4,E}, //meas 10 (page 2)
                     {GG4,E},{AA4,E},{BB4,E},{AA4,E},{EE4,E},{Fs4,Q},{DD4,E},{DD4,E}, //meas 11
                     {EE4,Q+E},{EE4,E},{CC5,E},{BB4,E},{AA4,E},{GG4,E}, //meas 12
                     {DD5,Q},{AA4,H},{DD4,E},{DD4,E},                   //meas 13
                     {EE4,Q+E},{EE4,E},{CC5,E},{BB4,E},{AA4,E},{GG4,E}, //meas 14
                     {GG4,E},{AA4,E},{BB4,E},{AA4,E},{EE4,E},{Fs4,Q},{DD5,E},{DD5,E}, //meas 15
                     {GG5,E},{FF5,E},{Eb5,E},{DD5,E},{CC5,E},{Bb4,E},{AA4,E},{GG4,E}, //meas 16
                     {DD5,H+Q},{DD4,E},{DD4,E},{DD4,E},{DD4,Q},{DD4,E},{DD4,E},{DD4,E}, // meas 17 (95)
                     
                     {GG4,H},{DD5,H},                          //meas 18 page 3
                     {CC5,E},{BB4,E},{AA4,E},{GG5,H},{DD5,Q},  //meas 19
                     {CC5,E},{BB4,E},{AA4,E},{GG5,H},{DD5,Q},  //meas 20
                     {CC5,E},{BB4,E},{CC5,E},{AA4,H},{R,Q},{DD4,E},{DD4,E},{DD4,E},    //meas 21 (115) 
                     
                     {GG4,H},{DD5,H},                          //meas 22
                     {CC5,E},{BB4,E},{AA4,E},{GG5,H},{DD5,Q},  //meas 23
                     {GG5,E},{FF5,E},{Db5,E},{Bb5,H},{AA5,Q},  //meas 24
                     {GG5,H+Q},{GG3,E},{GG3,E},{GG3,E},{GG3,Q},{R,Q} //meas 25   (133) 
                       
};
int num_notes10 = 133;
int led_notes10[]={GG3,AA4,BB4,DD4,GG4,CC5,DD5,GG5,AA5,BB5};

// TWINKLE TWINKLE LITTLE STAR
int bpm11 = 120;
int song11[100][2] = { {CC4,Q}, {CC4,Q}, {GG4,Q}, {GG4,Q}, {AA4,Q}, {AA4,Q}, {GG4,H}, //7 TWINKLE TWINKLE LITTLE STAR
                      {FF4,Q}, {FF4,Q}, {EE4,Q}, {EE4,Q}, {DD4,Q}, {DD4,Q}, {CC4,H}, //7 HOW I WONDER WHAT YOU ARE
                      {GG4,Q}, {GG4,Q}, {FF4,Q}, {FF4,Q}, {EE4,Q}, {EE4,Q}, {DD4,H}, //7 UP ABOVE THE WORLD SO HIGH
                      {GG4,Q}, {GG4,Q}, {FF4,Q}, {FF4,Q}, {EE4,Q}, {EE4,Q}, {DD4,H}, //7 LIKE A DIAMOND IN THE SKY
                      {CC4,Q}, {CC4,Q}, {GG4,Q}, {GG4,Q}, {AA4,Q}, {AA4,Q}, {GG4,H}, //6 TWINKLE TWINKLE LITTLE STAR
                      {FF4,Q}, {FF4,Q}, {EE4,Q}, {EE4,Q}, {DD4,Q}, {DD4,Q}, {CC4,H} //7 HOW I WONDER WHAT YOU ARE
};
int num_notes11 = 42;
int led_notes11[]={CC4,DD4,EE4,FF4,GG4,AA4,BB4,CC5,DD5,EE5};


// CLOCKS
int bpm12 = 120;
int song12[100][2] = { {Eb5,E}, {Bb4,E}, {GG4,E}, {Eb5,E}, {Bb4,E}, {GG4,E}, {Eb5,E}, {Bb4,E},
                      {Db5,E}, {Bb4,E}, {FF4,E}, {Db5,E}, {Bb4,E}, {FF4,E}, {Db5,E}, {Bb4,E},
                      {Db5,E}, {Bb4,E}, {FF4,E}, {Db5,E}, {Bb4,E}, {FF4,E}, {Db5,E}, {Bb4,E}, 
                      {CC5,E}, {Ab4,E}, {FF4,E}, {CC5,E}, {Ab4,E}, {FF4,E}, {CC5,E}, {Ab4,E},
                      {Eb5,E}, {Bb4,E}, {GG4,E}, {Eb5,E}, {Bb4,E}, {GG4,E}, {Eb5,E}, {Bb4,E},
                      {Db5,E}, {Bb4,E}, {FF4,E}, {Db5,E}, {Bb4,E}, {FF4,E}, {Db5,E}, {Bb4,E},
                      {Db5,E}, {Bb4,E}, {FF4,E}, {Db5,E}, {Bb4,E}, {FF4,E}, {Db5,E}, {Bb4,E}, 
                      {CC5,E}, {Ab4,E}, {FF4,E}, {CC5,E}, {Ab4,E}, {FF4,E}, {CC5,E}, {Ab4,E},
};
int num_notes12 = 64;
int led_notes12[]={FF4,GG4,Ab4,Bb4,CC5,Db5,Eb5,FF5,GG5,Ab5};

// POKER FACE
int bpm13 = 120;
int song13[100][2] = { {AA4,E}, {AA4,E}, {AA3,E}, {AA3,E}, {EE4,E}, {EE4,E}, {AA3,E}, {AA3,E},
                      {AA4,E}, {AA4,E}, {FF4,E}, {CC4,E}, {GG4,E}, {GG4,E}, {GG3,E}, {GG3,E},
                      
                      {AA4,E}, {AA4,E}, {AA3,E}, {AA3,E}, {EE4,E}, {EE4,E}, {AA3,E}, {AA3,E},
                      {AA4,E}, {AA4,E}, {FF4,E}, {CC4,E}, {GG4,E}, {GG4,E}, {GG3,E}, {GG3,E},
                      
                      {CC5,E}, {CC5,E}, {CC5,E}, {CC5,E}, {CC5,E}, {CC5,E}, {CC5,E}, {CC5,E}, {CC5,E}, {CC5,E}, {CC5,E}, {CC5,E}, {DD5,E}, {CC5,E}, {DD5,E}, {CC5,E},
                      {EE5,E}, {EE5,E}, {EE5,E}, {EE5,E}, {EE5,E}, {EE5,E}, {EE5,E}, {EE5,E}, {EE5,E}, {EE5,E}, {EE5,E}, {EE5,E}, {FF5,E}, {EE5,E}, {FF5,E}, {EE5,E},
};
int num_notes13 = 64;
int led_notes13[]={GG3,AA3,CC4,EE4,FF4,GG4,AA4,CC5,DD5,EE5,};

// Avengers
int bpm14 = 120;
int song14[100][2] = {
                     {DD4,Q+E}, {DD4,S_S}, {DD4,S_S}, {DD4,Q}, {DD4,E}, {DD4,S_S}, {DD4,S_S},
                      {Eb4,S_S}, {Eb4,S_S}, {Eb4,Q}, {Eb4,S_S}, {Eb4,S_S}, {EE4,E}, {EE4,S_S}, {EE4,S_S}, {EE4, E},
                      {FF4,S_S}, {FF4,S_S}, {FF4,Q}, {FF4,S_S}, {FF4,S_S}, {EE4,Q}, {EE4,S_S}, {EE4,S_S}, {EE4, E},
                      {Eb4,S_S}, {Eb4,S_S}, {Eb4,Q}, {DD4,S_S}, {DD4,S_S}, {EE4,Q}, {GG4,Q},
                      
                      {DD4,Q+E}, {DD4,S_S}, {DD4,S_S}, {DD4,Q}, {DD4,E}, {DD4,S_S}, {DD4,S_S},
                      {Eb4,S_S}, {Eb4,S_S}, {Eb4,Q}, {Eb4,S_S}, {Eb4,S_S}, {EE4,E}, {EE4,S_S}, {EE4,S_S}, {EE4, E},
                      {FF4,S_S}, {FF4,S_S}, {FF4,Q}, {FF4,S_S}, {FF4,S_S}, {EE4,Q}, {EE4,S_S}, {EE4,S_S}, {EE4, E},
                      {Eb4,S_S}, {Eb4,S_S}, {Eb4,Q}, {DD4,S_S}, {DD4,S_S}, {EE4,Q}, {GG4,Q}
                      
};
int num_notes14 = 64;
int led_notes14[]={GG4,AA4,CC4,EE4,FF4,GG4,AA4,CC5,DD5,EE5};

// INSPECTOR GADGET- Daniel-- not quite done
int bpm15 = 200;
int song15[100][2] = {
                  //    {EE3,Q+E},{R,Q},{EE2,Q},{R,Q},                                   //meas 1
                  //    {EE3,E+S_S},{EE3,E+S_S},{DD3,Q+E},{CC3,Q+E},{BB3,Q+E},           //meas 2
                  
                      {AA3,E},{BB3,E},{CC4,E},{DD4,E},{EE4,Q+E},{CC4,Q},               //meas 3
                      {Ds4,Q},{BB3,Q},{DD4,Q},{CC4,Q},                                 //meas 4  
                      
                      {AA3,E},{BB3,E},{CC4,E},{DD4,E},{EE4,Q+E},{AA4,Q},               //meas 5
                      {CC4,H},                                                       //meas 6
                      
                      {AA3,E},{BB3,E},{CC4,E},{DD4,E},{EE4,Q+E},{CC4,Q},               //meas 7 (page 2)
                      {Ds4,Q},{BB3,Q},{DD4,Q},{CC4,Q},                                 //meas 8  
                      
                      {AA3,Q+E},{R,Q+H},                                               //meas 9
                      {R,Q},{EE4,Q},{AA4,H},                                           //meas 10
                      {R,Q},{FF3,E},{Ab3,E},{DD4,Q+E},{Bb3,E},{DD4,E},                 //meas 11
                      
                      {FF4,H},{R,H},                                                   //meas 12
                         
                      {AA3,E},{BB3,E},{CC4,E},{DD4,E},{EE4,Q+E},{CC4,Q},               //meas 3
                      {Ds4,Q},{BB3,Q},{DD4,Q},{CC4,Q},                                 //meas 4  
                      
                      {AA3,E},{BB3,E},{CC4,E},{DD4,E},{EE4,Q+E},{AA4,Q},               //meas 5
                      {AA4,W},                                                        //meas 6
                      
                      {AA3,E},{BB3,E},{CC4,E},{DD4,E},{EE4,Q+E},{CC4,Q},               //meas 7 (page 2)
                      {Ds4,Q},{BB3,Q},{DD4,Q},{CC4,Q},                                 //meas 8  
                      
                      {FF2,Q},{EE2,Q},{FF2,Q},{EE2,Q},                                  //meas 13
                      {AA2,Q},{Gs2,Q},{CC3,Q},{AA2,Q}                                   //meas 14
                      
};


                      

int num_notes15= 60;//  up to meas 8 minus meas 2
int led_notes15[]={EE2,CC3,DD3,EE3};


// AUDITION - ??? Not quite done
int bpm16 = 40;
int song16[200][2] = {
       {FF2,E},{Bb2,S_S},{AA2,S_S},{Bb2,S_S},{CC3,S_S},{DD3,E},{FF2,E},{Bb2,S_S},
     {AA2,S_S},{Bb2,S_S},{CC3,S_S},{DD3,E},{DD3,E},{CC3,E},{DD3,S_S},{CC3,E},
   {Bb2,S_S},{AA2,S_S},{Bb2,S_S},{CC3,S_S},{DD3,E},{FF2,E},{Bb2,S_S},{AA2,S_S},{Bb2,S_S},{CC3,S_S},{DD3,E},{Bb2,E},{FF2,Q},
       {FF2,S_S},{Eb2,S_S},{DD2,S_S},{CC2,S_S},{Bb1,E},{Bb1,E},{Bb1,H}
     };
  
int num_notes16 = 100;
int led_notes16[] = {};


//MULBERRY BUSH - Luka - not quite done...
int bpm17 = 240;
int song17[200][2] = {
   {FF4,Q},{R,S_S},{FF4,Q},{R,S_S},{FF4,Q},{R,S_S},{FF4,H},{AA4,Q},{CC5,Q},{R,S_S},{CC5,Q},{AA4,Q},{FF4,H},{R,S_S},{FF4,Q}

};

int num_notes17=100;
int led_notes17[]= {AA4};


// London Bridge - Samuel
int bpm18 = 100;
int song18[50][2] = {{GG4,Q}, {AA4,Q}, {GG4,Q}, {FF4,Q}, {EE4,Q}, {FF4,Q}, {GG4,H}, {DD4,Q}, {EE4,Q}, {FF4,H}, {EE4,Q}, {FF4,Q}, {GG4,H}, 
{GG4,Q}, {AA4,Q}, {GG4,Q}, {FF4,Q}, {EE4,Q}, {FF4,Q}, {GG4,H}, {DD4,H}, {GG4,H}, {EE4,Q}, {CC4,H+Q}        
};
int num_notes18 = 24;
int led_notes18[]={CC4,DD4,EE4,FF4,GG4,AA4,BB4,CC5,DD5,EE5};


//HAPPY BIRTHDAY - Samuel
int bpm19 = 90;
int song19[50][2] = {{BB4,E}, {BB4,E}, {Cs5,Q}, {BB4,Q}, {EE5,Q}, {Ds5,H}, {BB4,E}, {BB4,E}, {Cs5,Q}, {BB4,Q}, {Fs5,Q}, {EE5,H}, 
{BB4,E}, {BB4,E}, {BB5,Q}, {Gs5,Q}, {EE5,Q}, {Ds5,Q}, {Cs5,Q+E}, {AA5,E}, {AA5,E}, {Gs5,Q}, {EE5,Q}, {Fs5,Q}, {EE5,H+Q}
};

int num_notes19 = 26;
int led_notes19[]={BB4,Cs5,Ds5,EE5,Fs5,Gs5,AA5,BB5,CC6,DD6};

//SHOO FLY - Not quite done yet... Samuel
int bpm20 = 100;
int song20[50][2] = {
                     {BB4,E}, {GG4,Q+E}, {AA4,Q}, {BB4,Q}, {CC4,E}, {AA4,Q+E}, {AA4,Q}, {Fs4,Q+E}, {GG4,Q+E}, {AA4,Q}, {BB4,Q}, {GG4,Q+E}, {BB4,E}, 
                     {GG4,Q+E}, {AA4,Q}, {BB4,Q}, {CC4,E}, {AA4,Q+E}, {DD4,Q}, {DD4,Q}, {DD4,Q}, {CC5,Q}, {BB4,Q}, {AA4,Q}, {GG4,W} 
};

int num_notes20 = 26;
int led_notes20[]={Fs4,GG4,AA4,BB4,CC4,DD5,EE5,Fs5,GG5,AA5};



/* int bpm17 = 120;
int song17[200][2] = {

};

int num_notes = 100;
int led_notes16[]= {}

int bpm17 = 120;
int song17[200][2] = {

};

int num_notes = 100;
int led_notes16[]= {}

int bpm17 = 120;
int song17[200][2] = {

};

int num_notes = 100;
int led_notes16[]= {}*/

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
    case ODE_TO_JOY:
      bpm = &bpm5;
      num_notes = &num_notes5;
      song = *song5;
      led_notes = led_notes5;
      break;
    case MOUNTAIN_KING:
      bpm = &bpm6;
      num_notes = &num_notes6;
      song = *song6;
      led_notes = led_notes6;
      break;
    case BAA_BAA:
      bpm = &bpm7;
      num_notes = &num_notes7;
      song = *song7;
      led_notes = led_notes7;
      break;
    case BAT_MAN:
      bpm = &bpm8;
      num_notes = &num_notes8;
      song = *song8;
      led_notes = led_notes8;
      break;      
     case GILLIGAN:
      bpm = &bpm9;
      num_notes = &num_notes9;
      song = *song9;
      led_notes = led_notes9;
      break;        
     case STAR_WARS:
      bpm = &bpm10;
      num_notes = &num_notes10;
      song = *song10;
      led_notes = led_notes10;
      break;
    case TWINKLE_TWINKLE:
      bpm = &bpm11;
      num_notes = &num_notes11;
      song = *song11;
      led_notes = led_notes11;
      break;
     case CLOCKS:
      bpm = &bpm12;
      num_notes = &num_notes12;
      song = *song12;
      led_notes = led_notes12;
      break;
     case POKER_FACE:
      bpm = &bpm13;
      num_notes = &num_notes13;
      song = *song13;
      led_notes = led_notes13;
      break;      
    case AVENGERS:
      bpm = &bpm14;
      num_notes = &num_notes14;
      song = *song14;
      led_notes = led_notes14;
      break;
    case INSPECTOR_GADGET:
      bpm = &bpm15;
      num_notes = &num_notes15;
      song = *song15;
      led_notes = led_notes15;
      break;  
    case AUDITION:
      bpm = &bpm16;
      num_notes = &num_notes16;
      song = *song16;
      led_notes = led_notes16;
      break; 
    case MULBERRY_BUSH:
      bpm = &bpm17;
      num_notes = &num_notes17;
      song = *song17;
      led_notes = led_notes17;
      break;   
    case LONDON_BRIDGE:
      bpm = &bpm18;
      num_notes = &num_notes18;
      song = *song18;
      led_notes = led_notes18;
      break;
    case HAPPY_BIRTHDAY:
      bpm = &bpm19;
      num_notes = &num_notes19;
      song = *song19;
      led_notes = led_notes19;
      break; 
    case SHOO_FLY:
      bpm = &bpm20;
      num_notes = &num_notes20;
      song = *song20;
      led_notes = led_notes20;
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
 // set inputs
// pinMode(switch_connect, INPUT);
 
 
 // set outputs
  pinMode(speaker_connect, OUTPUT);   
  for (int i=0; i < num_leds; i++) {
    pinMode(leds[i], OUTPUT);
  } 
  leds_off();
  delay(1000); // delay 1sec before starting music
//  randomSeed(analogRead(14)); // seed random generator using Analog pin 14 (assuming not connected)
}

// the loop routine runs over and over again forever
// basically like main with while(1).
void loop() {
  volatile int random_song;
//  volatile int last_random_song;
// music_mode = digitalRead(switch_connect);
 
 if (DEBUGME == 1) {
   debug_print_song(IMPERIAL_MARCH);
 }
 
 if (RANDOM == 1) {
   random_song = random(1,NUM_SONGS+1);
  /* while (random_song == last_random_song) { // prevent song from playing twice consecutively
     randomSeed(analogRead(14));
     random_song = random(1,NUM_SONGS+1); // get different random song
   } */

   play_song(random_song);
   delay(1000);
//   last_random_song = random_song;
 } else {
  
   play_song(MOUNTAIN_KING);
   delay(1000);
 play_song(IMPERIAL_MARCH);
 delay(1000);
 play_song(JINGLE_BELL_ROCK);
 delay(1000);
 play_song(SUPER_MARIO);
 delay(1000);
  play_song(NFL);
 delay(1000); 
   play_song(ODE_TO_JOY);
 delay(1000);
    play_song(BAA_BAA);
    delay(1000); 
    play_song(BAT_MAN);
    delay(1000);
    play_song(GILLIGAN);
    delay(1000); 
    play_song(STAR_WARS);
    delay(1000); 
    play_song(TWINKLE_TWINKLE);
    delay(1000);
    play_song(CLOCKS);
    delay(1000); 
    play_song(POKER_FACE);
    delay(1000);    
    play_song(INSPECTOR_GADGET);
    delay(1000);
    play_song(MULBERRY_BUSH);
    delay(1000);
    play_song(AVENGERS);
    delay(1000); 
    play_song(LONDON_BRIDGE);
    delay(1000);
    play_song(HAPPY_BIRTHDAY);
    delay(1000);


    // scales should always be played last!    
   play_song(SCALES);
   delay(1000);
 }

}
    
    



