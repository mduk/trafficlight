// ####################################################################################################
// Define what pins on the chip we want to use for what signals.
#define PIN_CLOCK 12
#define PIN_DATA 11
#define PIN_LATCH 8

// ####################################################################################################
// The data.


// ----------------------------------------------------------------------------------------------------
// First off we need to tell the computer how many patterns it knows about. This is so that the data
// structures for the parameters below can be sized correctly in memory.
#define N_PATTERNS 10



// ----------------------------------------------------------------------------------------------------
// This is the binary representation of the patterns that are displayed on the traffic light.
//   Here blank lines seperate each pattern to make it easier for humans to see where one pattern ends
//   and the other begins. The computer however just sees one continuous block of data.
//
//   The first parameter in the square brackets needs to be the total number of lines contained within
//   the block.
int patternData[ 53 ][4] = {
  
  // Pattern A: Off
  // Pattern B: Fill Up
  { 0b00000000, 0b00000000, 0b00000000, 0b00000000 }, // 0
  { 0b11111000, 0b00000000, 0b00000000, 0b00000000 },
  { 0b11111111, 0b11000000, 0b00000000, 0b00000000 },
  { 0b11111111, 0b11111110, 0b00000000, 0b00000000 },
  { 0b11111111, 0b11111111, 0b11110000, 0b00000000 },
  { 0b11111111, 0b11111111, 0b11111111, 0b10000000 }, // 5

  // Pattern C: Splosh
  { 0b00000000, 0b00001000, 0b00000000, 0b00000000 }, // 6
  { 0b00000011, 0b10010100, 0b11100000, 0b00000000 },
  { 0b11111100, 0b01100011, 0b00011111, 0b10000000 }, // 8

  // Pattern D: Dot-Ring
  { 0b00000000, 0b00001000, 0b00000000, 0b00000000 }, // 9
  { 0b11111100, 0b01100011, 0b00011111, 0b10000000 }, // 10

  // Pattern E: Halves
  { 0b11111111, 0b11000000, 0b00000000, 0b00000000 }, // 11
  { 0b00000000, 0b00000001, 0b11111111, 0b11111111 }, // 12

  // Pattern F: Clockwise Wedges
  { 0b00000000, 0b00001110, 0b00110000, 0b10000000 }, // 13
  { 0b00000000, 0b00001000, 0b01100011, 0b10000000 },
  { 0b00000000, 0b00001000, 0b11001110, 0b00000000 },
  { 0b00000000, 0b00111001, 0b10001000, 0b00000000 },
  { 0b10000110, 0b00111000, 0b00000000, 0b00000000 },
  { 0b11100011, 0b00001000, 0b00000000, 0b00000000 },
  { 0b00111001, 0b10001000, 0b00000000, 0b00000000 },
  { 0b00001000, 0b11001110, 0b00000000, 0b00000000 }, // 20

  // Pattern G: Up-Wipe
  { 0b11111000, 0b00000000, 0b00000000, 0b00000000 }, // 21
  { 0b00000111, 0b11000000, 0b00000000, 0b00000000 },
  { 0b00000000, 0b00111110, 0b00000000, 0b00000000 },
  { 0b00000000, 0b00000001, 0b11110000, 0b00000000 },
  { 0b00000000, 0b00000000, 0b00001111, 0b10000000 }, // 25

  // Pattern H: Spinny Dot
  { 0b00000010, 0b00000000, 0b00000000, 0b00000000 }, // 26
  { 0b00000001, 0b00000000, 0b00000000, 0b00000000 },
  { 0b00000000, 0b10000000, 0b00000000, 0b00000000 },
  { 0b00000000, 0b00000100, 0b00000000, 0b00000000 },
  { 0b00000000, 0b00000000, 0b00100000, 0b00000000 },
  { 0b00000000, 0b00000000, 0b01000000, 0b00000000 },
  { 0b00000000, 0b00000000, 0b10000000, 0b00000000 },
  { 0b00000000, 0b00010000, 0b00000000, 0b00000000 }, // 33

  // Pattern I: Circly Hatty Thing
  { 0b00000000, 0b00000000, 0b00000010, 0b00000000 }, // 34
  { 0b00000000, 0b00000000, 0b00000111, 0b00000000 },
  { 0b00000000, 0b00000000, 0b00001111, 0b10000000 },
  { 0b00000000, 0b00000001, 0b00011111, 0b10000000 },
  { 0b00000000, 0b00100011, 0b00011111, 0b10000000 },
  { 0b00000000, 0b00110111, 0b00011111, 0b10000000 },
  { 0b00000000, 0b00111111, 0b00011111, 0b10000000 },
  { 0b00000001, 0b00111111, 0b00011111, 0b10000000 },
  { 0b00100001, 0b00111111, 0b00011111, 0b10000000 },
  { 0b01110001, 0b00111111, 0b00011111, 0b10000000 },
  { 0b11111001, 0b00111111, 0b00011111, 0b10000000 },
  { 0b11111101, 0b01111111, 0b00011111, 0b10000000 },
  { 0b00000000, 0b00111110, 0b00000000, 0b00000000 }, // 46

  // J
  { 0b00000000, 0b00000000, 0b00000010, 0b00000000 },
  { 0b00000000, 0b00000000, 0b00000011, 0b00000000 },
  { 0b00000000, 0b00000000, 0b00000011, 0b10000000 },
  { 0b00000000, 0b00000000, 0b00100011, 0b10000000 },
  { 0b00000000, 0b00001000, 0b00100011, 0b10000000 },
  { 0b00000010, 0b00001000, 0b00100011, 0b10000000 }



  
};



// ----------------------------------------------------------------------------------------------------
// Since the computer only sees a continuous block of data, we need to tell it where each pattern begins
// and how many frames it has. This allows us to single out a particular pattern from within the block
// of data.



// ----------------------------------------------------------------------------------------------------
// For each pattern we have in data, we must also have a number in this list that defines the starting
// point of that data. In this case they can be thought of as "what line does it start on? (minus one)"
int patternStartOffset[ N_PATTERNS ] = {
  0,  // Pattern A starts at 0
  0,  // Pattern B also starts at 0
  6,  // Pattern C starts at 6
  9,  // Pattern D starts at 9
  11, // Pattern E starts at 11
  13, // Pattern F starts at 13
  21, // Pattern G starts at 21
  26,
  34,
  47
};



// ----------------------------------------------------------------------------------------------------
// Again for each pattern we have, we must also tell the computer how many frames the pattern consists
// of. "How many lines are there?"
int patternFrameCount[ N_PATTERNS ] = {
  1, // Pattern A has 1 frame
  6, // Pattern B has 6 frames
  3, // Pattern C has 3 frames
  2, // Pattern D has 2 frames
  2, // Pattern E has 2 frames
  8, // Pattern F has 8 frames
  5, // Pattern G has 5 frames
  8,
  12,
  5
};



// ----------------------------------------------------------------------------------------------------
// Initial starting pattern for each light when the traffic light is powered up
int greenLightPattern = 0;
int redLightPattern = 0;



// ----------------------------------------------------------------------------------------------------
// Here we define two variables to hold both light's state.
//   The computer needs to keep track of where in the pattern it is and what frame to display next
//   so we use these variables to make note of which frame we displayed last.
int greenLightPatternPreviousFrame = 0;
int redLightPatternPreviousFrame = 0;



// ####################################################################################################
// Here we define some helper functions to keep the main bulk of our code concise.



// ----------------------------------------------------------------------------------------------------
// This function takes care of the latching signal, lets us set it HIGH or LOW.
void latch( int state )
{
  digitalWrite( PIN_LATCH, state );
}



// ----------------------------------------------------------------------------------------------------
// Given four bytes of bits in left-to-right order which is natural for english-speaking humans,
// transmit them to the traffic light in the reversed order required by the traffic light.
void shiftOutFourBytes( byte one, byte two, byte three, byte four ) {
  shiftOut( PIN_DATA, PIN_CLOCK, LSBFIRST, four );
  shiftOut( PIN_DATA, PIN_CLOCK, LSBFIRST, three );
  shiftOut( PIN_DATA, PIN_CLOCK, LSBFIRST, two );
  shiftOut( PIN_DATA, PIN_CLOCK, LSBFIRST, one );
}

// ####################################################################################################
// This block of code will be run once when we turn on the traffic light.
void setup() {



  // Start a serial connection over USB, this is our text console and user interface.
  Serial.begin( 9600 );


  
  // We require three pins to communicate with the traffic light.
  //   A Latch to tell the traffic light when we have finished writing data to it.
  //   A Clock signal so the traffic light and the computer can stay in sync
  //   A Data signal to carry the data to the traffic light.
  pinMode( PIN_LATCH, OUTPUT );
  pinMode( PIN_CLOCK, OUTPUT );
  pinMode( PIN_DATA, OUTPUT );


  
  // Initialise all those pins with LOW/off/0 out of good form mostly
  //   It's a generally safe bet that they'll be LOW anyway, but it's not always guaranteed.
  digitalWrite( PIN_LATCH, LOW );
  digitalWrite( PIN_CLOCK, LOW );
  digitalWrite( PIN_DATA, LOW );



  // Blank both lights
  //   When power is first applied, "noise" can get into the shift registers and there will
  //   be random data in them. This just sets everything to zero. We don't really need to
  //   do this as such, but it helps to avoid random flickers.
  shiftOutFourBytes( 0b00000000, 0b00000000, 0b00000000, 0b00000000 );
  shiftOutFourBytes( 0b00000000, 0b00000000, 0b00000000, 0b00000000 );



  // Print out some usage information on the serial console.
  Serial.println( "To change the light pattern, enter a letter and press return." );
  Serial.println( "    Lowercase letters will change the Green light" );
  Serial.println( "    Uppercase letters will change the Red light" );
  Serial.println();
  Serial.println( "Go-go-go!" );
  Serial.println();
}



// ####################################################################################################
// After the setup code has been run, this block of code is run over and over and over until the end
// of time. Or until we turn it off, whichever comes firt.
void loop() {



  // ====================================================================================================
  // If data is available from the serial port, then a pattern is being changed.
  //   The byte received will be an ASCII character.
  //   Lowercase letters are in the range of 97 to 122 (eg: 97 = 'a', 98 = 'b', 99 = 'c'...)
  //   Uppercase letters are in the range of 65 to 90 (eg: 65 = 'A', 66 = 'B', 67 = 'C'...)
  if ( Serial.available() == 1 ) {



    // Read that byte
    char c = Serial.read();



    // Echo it back to the serial console so we can see what was received
    Serial.print( "Received Command: " );
    Serial.println( c );



    // If the byte is within the lowercase range, then change the Green light.
    if ( c >= 'a' && c <= 'z' ) {
      
      // Subtract the base number to get a 0 to 26 integer (representing 'a' through 'z')
      int pattern = c - 'a';

      // Set the light's active pattern
      greenLightPattern = pattern;

      // Reset the counter so the pattern plays from the beginning
      greenLightPatternPreviousFrame = 0;
    }



    // If the byte is within the uppercase range, then change the Red light.
    if ( c >= 'A' && c <= 'Z' ) {
      
      // Subtract the base number to get a 0 to 26 integer (representing 'A' through 'Z')
      int pattern = c - 'A';
      
      // Set the light's active pattern
      redLightPattern = pattern;
      
      // Reset the counter so the pattern plays from the beginning
      redLightPatternPreviousFrame = 0;
    }
  }



  // ====================================================================================================
  // Start sending the data


  
  // ----------------------------------------------------------------------------------------------------
  // Hold data on the outputs while we shift new data in
  latch( LOW );


  
  // ====================================================================================================
  // Red Light
  int redLightPatternStartOffset = patternStartOffset[ redLightPattern ];
  int redLightEndOfPatternLocation = redLightPatternStartOffset + patternFrameCount[ redLightPattern ] - 1;
  int redLightNextFrameLocation = redLightPatternStartOffset + redLightPatternPreviousFrame;

  // If we hit the last frame of the pattern, reset to the first.
  if ( redLightNextFrameLocation > redLightEndOfPatternLocation ) {
    redLightNextFrameLocation = redLightPatternStartOffset;
    redLightPatternPreviousFrame = 0;
  }

  // Grab the frame to display
  int* redLightFrame = patternData[ redLightNextFrameLocation ];

  // Send the data to the light
  shiftOutFourBytes( redLightFrame[0], redLightFrame[1], redLightFrame[2], redLightFrame[3]);

  // Now that we've output the frame, increment the previous frame pointer
  redLightPatternPreviousFrame++;


  
  // ====================================================================================================
  // Green Light
  int greenLightPatternStartOffset = patternStartOffset[ greenLightPattern ];
  int greenLightEndOfPatternLocation = greenLightPatternStartOffset + patternFrameCount[ greenLightPattern ] - 1;
  int greenLightNextFrameLocation = greenLightPatternStartOffset + greenLightPatternPreviousFrame;

  // If we hit the last frame of the pattern, reset to the first.
  if ( greenLightNextFrameLocation > greenLightEndOfPatternLocation ) {
    greenLightNextFrameLocation = greenLightPatternStartOffset;
    greenLightPatternPreviousFrame = 0;
  }

  // Grab the frame to display
  int* greenLightFrame = patternData[ greenLightNextFrameLocation ];

  // Send the data to the light
  shiftOutFourBytes( greenLightFrame[0], greenLightFrame[1], greenLightFrame[2], greenLightFrame[3]);

  // Now that we've output the frame, increment the previous frame pointer
  greenLightPatternPreviousFrame++;



  // ====================================================================================================
  // Finished sending the data


  
  // ----------------------------------------------------------------------------------------------------
  // Output shifted data to LEDs
  latch( HIGH );



  // ----------------------------------------------------------------------------------------------------
  // Hold for a moment so our eyes have a chance to distinguish the frame
  delay( 500 );
}








