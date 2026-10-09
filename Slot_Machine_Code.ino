// Carissa Lee and Ella Stephani
// This file contains the C++ code responsible for controlling the slot machine's hardware, LED animations, and game logic.

// defining variables
// defining the bytes where the LED bits will be stored once
// they are landed on
// allows us to keep one column stable while scrolling the next column
// also allows us to check the color of the LEDs at the end of the game
byte bitstream0 ;
byte bitstream1 ;
byte bitstream2 ;
byte bitstream3 ;
byte bitstream00 ;
byte bitstream11 ;
byte bitstream22 ;
byte bitstream33 ;
byte bitstream000 ;
byte bitstream111 ;
byte bitstream222 ;
byte bitstream333 ;
// defining pins
// shift register 0
int clockPin0 = 2;
int latchPin0 = 3;
int dataPin0 = 4;
// shift register 1
int clockPin1 = 5;
int latchPin1 = 6;
int dataPin1 = 7;
// shift register 2
int clockPin2 = 8;
int latchPin2 = 9;
int dataPin2 = 10;
// shift register 3
int clockPin3 = 11;
int latchPin3 = 12;
int dataPin3 = 13;
// scrolling condition
bool scrollStarted = false ;
void setup ( ) {
// setting pin modes for shift registers
pinMode ( clockPin0 , OUTPUT) ;
pinMode ( latchPin0 , OUTPUT) ;
pinMode ( dataPin0 , OUTPUT) ;
pinMode ( clockPin1 , OUTPUT) ;
pinMode ( latchPin1 , OUTPUT) ;
pinMode ( dataPin1 , OUTPUT) ;
pinMode ( clockPin2 , OUTPUT) ;
pinMode ( latchPin2 , OUTPUT) ;
pinMode ( dataPin2 , OUTPUT) ;
pinMode ( clockPin3 , OUTPUT) ;
pinMode ( latchPin3 , OUTPUT) ;
pinMode ( dataPin3 , OUTPUT) ;
// setting pin modes for medium LED
pinMode (A0 , OUTPUT) ;
pinMode (A1 , OUTPUT) ;
// setting pin mode for joystick
pinMode (A5 , INPUT ) ;
// setting all LEDs off
digitalWrite ( latchPin0 , LOW) ;
shiftOut ( dataPin0 , clockPin0 , LSBFIRST , 0 ) ;
digitalWrite ( latchPin0 , HIGH ) ;
digitalWrite ( latchPin1 , LOW) ;
shiftOut ( dataPin1 , clockPin1 , LSBFIRST , 0 ) ;
digitalWrite ( latchPin1 , HIGH ) ;
digitalWrite ( latchPin2 , LOW) ;
shiftOut ( dataPin2 , clockPin2 , LSBFIRST , 0 ) ;
digitalWrite ( latchPin2 , HIGH ) ;
digitalWrite ( latchPin3 , LOW) ;
shiftOut ( dataPin3 , clockPin3 , LSBFIRST , 0 ) ;
digitalWrite ( latchPin3 , HIGH ) ;
// unused pin for a random seed
randomSeed ( analogRead (A2 ) ) ;
// serial monitor for debugging
Serial.begin ( 9600 ) ;
}
void loop ( ) {
// setting LEDs off
digitalWrite ( latchPin0 , LOW) ;
shiftOut ( dataPin0 , clockPin0 , LSBFIRST , 0 ) ;
digitalWrite ( latchPin0 , HIGH ) ;
digitalWrite ( latchPin1 , LOW) ;
shiftOut ( dataPin1 , clockPin1 , LSBFIRST , 0 ) ;
digitalWrite ( latchPin1 , HIGH ) ;
digitalWrite ( latchPin2 , LOW) ;
shiftOut ( dataPin2 , clockPin2 , LSBFIRST , 0 ) ;
digitalWrite ( latchPin2 , HIGH ) ;
digitalWrite ( latchPin3 , LOW) ;
shiftOut ( dataPin3 , clockPin3 , LSBFIRST , 0 ) ;
digitalWrite ( latchPin3 , HIGH ) ;
// defining joystick value
int joystickval = analogRead (A5 ) ;
// intro scroll
// when the joystick is pushed , the scroll begins
if ( ! scrollStarted && ( joystickval > 700)) {
scrollStarted = true ;
// small delay
delay ( 300 ) ;
// scrolling through this loop 8 times
for ( int i = 0; i < 8; i ++){
// all latch pins = LOW to set the data
digitalWrite ( latchPin0 , LOW) ;
digitalWrite ( latchPin1 , LOW) ;
digitalWrite ( latchPin2 , LOW) ;
digitalWrite ( latchPin3 , LOW) ;
// row 1 = red
// row 2 = purple
// row 3 = blue
shiftOut ( dataPin0 , clockPin0 , MSBFIRST , 0b10010010 ) ;
shiftOut ( dataPin1 , clockPin1 , MSBFIRST , 0b01101000 ) ;
shiftOut ( dataPin2 , clockPin2 , MSBFIRST , 0b10010110 ) ;
shiftOut ( dataPin3 , clockPin3 , MSBFIRST , 0b01001000 ) ;
// all latch pins = HIGH to send the data
digitalWrite ( latchPin0 , HIGH ) ;
digitalWrite ( latchPin1 , HIGH ) ;
digitalWrite ( latchPin2 , HIGH ) ;
digitalWrite ( latchPin3 , HIGH ) ;
// delay to keep the colors for 100 ms
delay ( 100 ) ;
// all latch pins = LOW to set the data
digitalWrite ( latchPin0 , LOW) ;
digitalWrite ( latchPin1 , LOW) ;
digitalWrite ( latchPin2 , LOW) ;
digitalWrite ( latchPin3 , LOW) ;
// row 1 = yellow
// row 2 = red
// row 3 = purple
shiftOut ( dataPin0 , clockPin0 , MSBFIRST , 0b10110110 ) ;
shiftOut ( dataPin1 , clockPin1 , MSBFIRST , 0b01001010 ) ;
shiftOut ( dataPin2 , clockPin2 , MSBFIRST , 0b10100100 ) ;
shiftOut ( dataPin3 , clockPin3 , MSBFIRST , 0b01011010 ) ;
// all latch pins = HIGH to send the data
digitalWrite ( latchPin0 , HIGH ) ;
digitalWrite ( latchPin1 , HIGH ) ;
digitalWrite ( latchPin2 , HIGH ) ;
digitalWrite ( latchPin3 , HIGH ) ;
// delay to keep the colors for 100 ms
delay ( 100 ) ;
// all latch pins = LOW to set the data
digitalWrite ( latchPin0 , LOW) ;
digitalWrite ( latchPin1 , LOW) ;
digitalWrite ( latchPin2 , LOW) ;
digitalWrite ( latchPin3 , LOW) ;
// row 1 = green
// row 2 = yellow
// row 3 = red
shiftOut ( dataPin0 , clockPin0 , MSBFIRST , 0b00100100 ) ;
shiftOut ( dataPin1 , clockPin1 , MSBFIRST , 0b11011010 ) ;
shiftOut ( dataPin2 , clockPin2 , MSBFIRST , 0b00101100 ) ;
shiftOut ( dataPin3 , clockPin3 , MSBFIRST , 0b00010010 ) ;
// all latch pins = HIGH to send the data
digitalWrite ( latchPin0 , HIGH ) ;
digitalWrite ( latchPin1 , HIGH ) ;
digitalWrite ( latchPin2 , HIGH ) ;
digitalWrite ( latchPin3 , HIGH ) ;
// delay to keep the colors for 100 ms
delay ( 100 ) ;
// all latch pins = LOW to set the data
digitalWrite ( latchPin0 , LOW) ;
digitalWrite ( latchPin1 , LOW) ;
digitalWrite ( latchPin2 , LOW) ;
digitalWrite ( latchPin3 , LOW) ;
// row 1 = blue-green
// row 2 = green
// row 3 = yellow
shiftOut ( dataPin0 , clockPin0 , MSBFIRST , 0b01101100 ) ;
shiftOut ( dataPin1 , clockPin1 , MSBFIRST , 0b10010110 ) ;
shiftOut ( dataPin2 , clockPin2 , MSBFIRST , 0b01101000 ) ;
shiftOut ( dataPin3 , clockPin3 , MSBFIRST , 0b00110110 ) ;
// all latch pins = HIGH to send the data
digitalWrite ( latchPin0 , HIGH ) ;
digitalWrite ( latchPin1 , HIGH ) ;
digitalWrite ( latchPin2 , HIGH ) ;
digitalWrite ( latchPin3 , HIGH ) ;
// delay to keep the colors for 100 ms
delay ( 100 ) ;
// all latch pins = LOW to set the data
digitalWrite ( latchPin0 , LOW) ;
digitalWrite ( latchPin1 , LOW) ;
digitalWrite ( latchPin2 , LOW) ;
digitalWrite ( latchPin3 , LOW) ;
// row 1 = blue
// row 2 = blue-green
// row 3 = green
shiftOut ( dataPin0 , clockPin0 , MSBFIRST , 0b01001000 ) ;
shiftOut ( dataPin1 , clockPin1 , MSBFIRST , 0b10110100 ) ;
shiftOut ( dataPin2 , clockPin2 , MSBFIRST , 0b01011010 ) ;
shiftOut ( dataPin3 , clockPin3 , MSBFIRST , 0b00100100 ) ;
// all latch pins = HIGH to send the data
digitalWrite ( latchPin0 , HIGH ) ;
digitalWrite ( latchPin1 , HIGH ) ;
digitalWrite ( latchPin2 , HIGH ) ;
digitalWrite ( latchPin3 , HIGH ) ;
// delay to keep the colors for 100 ms
delay ( 100 ) ;
// all latch pins = LOW to set the data
digitalWrite ( latchPin0 , LOW) ;
digitalWrite ( latchPin1 , LOW) ;
digitalWrite ( latchPin2 , LOW) ;
digitalWrite ( latchPin3 , LOW) ;
// row 1 = purple
// row 2 = blue
// row 3 = blue-green
shiftOut ( dataPin0 , clockPin0 , MSBFIRST , 0b11011010 ) ;
shiftOut ( dataPin1 , clockPin1 , MSBFIRST , 0b00100100 ) ;
shiftOut ( dataPin2 , clockPin2 , MSBFIRST , 0b11010010 ) ;
shiftOut ( dataPin3 , clockPin3 , MSBFIRST , 0b01101100 ) ;
// all latch pins = HIGH to send the data
digitalWrite ( latchPin0 , HIGH ) ;
digitalWrite ( latchPin1 , HIGH ) ;
digitalWrite ( latchPin2 , HIGH ) ;
digitalWrite ( latchPin3 , HIGH ) ;
// delay to keep the colors for 100 ms
delay ( 100 ) ;
}
// scrolling first column
// setting a random breakpoint between 12 and 50 color changes
// for the first while loop
int breakpoint1 = random (12 , 50 ) ;
// start with 0 color changes
int i = 0;
// making sure while loop cannot go past 51 changes
while ( i <51){
// latches low to set data
digitalWrite ( latchPin0 , LOW) ;
digitalWrite ( latchPin1 , LOW) ;
digitalWrite ( latchPin2 , LOW) ;
digitalWrite ( latchPin3 , LOW) ;
// col 1 row 1 = red
shiftOut ( dataPin0 , clockPin0 , MSBFIRST , 0b00000010 ) ;
// storing the value of the LED by grabbing only the three bits
// that control it
bitstream0 = 0b00001110 & 0b00000010 ;
// col 1 row 2 = purple
shiftOut ( dataPin1 , clockPin1 , MSBFIRST , 0b00101000 ) ;
// storing the value of the LED by grabbing only the three bits
// that control it
bitstream1 = 0b00111000 & 0b00101000 ;
// col 1 row 3 = blue
shiftOut ( dataPin2 , clockPin2 , MSBFIRST , 0b10000000 ) ;
// storing the value of the LED by grabbing only the three bits
// that control it
bitstream2 = 0b11100000 & 0b10000000 ;
// third shift register goes unused in this column ; but still
// included for consistency
shiftOut ( dataPin3 , clockPin3 , MSBFIRST , 0b00000000 ) ;
bitstream3 = 0b00000000 ;
// latches high to send data
digitalWrite ( latchPin0 , HIGH ) ;
digitalWrite ( latchPin1 , HIGH ) ;
digitalWrite ( latchPin2 , HIGH ) ;
digitalWrite ( latchPin3 , HIGH ) ;
// small delay to see colors
delay ( 100 ) ;
// checking to see if the random breakpoint is reached
if ( i == breakpoint1 ){
break ;
}
// if not , add 1 to i
else {
i ++;
}
// latches low to set data
digitalWrite ( latchPin0 , LOW) ;
digitalWrite ( latchPin1 , LOW) ;
digitalWrite ( latchPin2 , LOW) ;
digitalWrite ( latchPin3 , LOW) ;
// col 1 row 1 = yellow
shiftOut ( dataPin0 , clockPin0 , MSBFIRST , 0b00000110 ) ;
// storing the value of the LED by grabbing only the three bits
// that control it
bitstream0 = 0b00001110 & 0b00000110 ;
// col 1 row 2 = red
shiftOut ( dataPin1 , clockPin1 , MSBFIRST , 0b00001000 ) ;
// storing the value of the LED by grabbing only the three bits
// that control it
bitstream1 = 0b00111000 & 0b00001000 ;
// col 1 row 3 = purple
shiftOut ( dataPin2 , clockPin2 , MSBFIRST , 0b10100000 ) ;
// storing the value of the LED by grabbing only the three bits
// that control it
bitstream2 = 0b11100000 & 0b10100000 ;
// third shift register goes unused in this column ; but still
// included for consistency
shiftOut ( dataPin3 , clockPin3 , MSBFIRST , 0b00000000 ) ;
bitstream3 = 0b00000000 ;
// latches high to send data
digitalWrite ( latchPin0 , HIGH ) ;
digitalWrite ( latchPin1 , HIGH ) ;
digitalWrite ( latchPin2 , HIGH ) ;
digitalWrite ( latchPin3 , HIGH ) ;
// small delay to see colors
delay ( 100 ) ;
// checking to see if the random breakpoint is reached
if ( i == breakpoint1 ){
break ;
}
// if not , add 1 to i
else {
i ++;
}
// latches low to set data
digitalWrite ( latchPin0 , LOW) ;
digitalWrite ( latchPin1 , LOW) ;
digitalWrite ( latchPin2 , LOW) ;
digitalWrite ( latchPin3 , LOW) ;
// col 1 row 1 = green
shiftOut ( dataPin0 , clockPin0 , MSBFIRST , 0b00000100 ) ;
// storing the value of the LED by grabbing only the three bits
// that control it
bitstream0 = 0b00001110 & 0b00000100 ;
// col 1 row 2 = yellow
shiftOut ( dataPin1 , clockPin1 , MSBFIRST , 0b00011000 ) ;
// storing the value of the LED by grabbing only the three bits
// that control it
bitstream1 = 0b00111000 & 0b00011000 ;
// col 1 row 3 = red
shiftOut ( dataPin2 , clockPin2 , MSBFIRST , 0b00100000 ) ;
// storing the value of the LED by grabbing only the three bits
// that control it
bitstream2 = 0b11100000 & 0b00100000 ;
// third shift register goes unused in this column ; but still
// included for consistency
shiftOut ( dataPin3 , clockPin3 , MSBFIRST , 0b00000000 ) ;
bitstream3 = 0b00000000 ;
// latches high to send data
digitalWrite ( latchPin0 , HIGH ) ;
digitalWrite ( latchPin1 , HIGH ) ;
digitalWrite ( latchPin2 , HIGH ) ;
digitalWrite ( latchPin3 , HIGH ) ;
// small delay to see colors
delay ( 100 ) ;
// checking to see if the random breakpoint is reached
if ( i == breakpoint1 ){
break ;
}
// if not , add 1 to i
else {
i ++;
}
// latches low to set data
digitalWrite ( latchPin0 , LOW) ;
digitalWrite ( latchPin1 , LOW) ;
digitalWrite ( latchPin2 , LOW) ;
digitalWrite ( latchPin3 , LOW) ;
// col 1 row 1 = blue-green
shiftOut ( dataPin0 , clockPin0 , MSBFIRST , 0b00001100 ) ;
// storing the value of the LED by grabbing only the three bits
// that control it
bitstream0 = 0b00001110 & 0b00001100 ;
// col 1 row 2 = green
shiftOut ( dataPin1 , clockPin1 , MSBFIRST , 0b00010000 ) ;
// storing the value of the LED by grabbing only the three bits
// that control it
bitstream1 = 0b00111000 & 0b00010000 ;
// col 1 row 3 = yellow
shiftOut ( dataPin2 , clockPin2 , MSBFIRST , 0b01100000 ) ;
// storing the value of the LED by grabbing only the three bits
// that control it
bitstream2 = 0b11100000 & 0b01100000 ;
// third shift register goes unused in this column ; but still
// included for consistency
shiftOut ( dataPin3 , clockPin3 , MSBFIRST , 0b00000000 ) ;
bitstream3 = 0b00000000 ;
// latches high to send data
digitalWrite ( latchPin0 , HIGH ) ;
digitalWrite ( latchPin1 , HIGH ) ;
digitalWrite ( latchPin2 , HIGH ) ;
digitalWrite ( latchPin3 , HIGH ) ;
// small delay to see colors
delay ( 100 ) ;
// checking to see if the random breakpoint is reached
if ( i == breakpoint1 ){
break ;
}
// if not , add 1 to i
else {
i ++;
}
// latches low to set data
digitalWrite ( latchPin0 , LOW) ;
digitalWrite ( latchPin1 , LOW) ;
digitalWrite ( latchPin2 , LOW) ;
digitalWrite ( latchPin3 , LOW) ;
// col 1 row 1 = blue
shiftOut ( dataPin0 , clockPin0 , MSBFIRST , 0b00001000 ) ;
// storing the value of the LED by grabbing only the three bits
// that control it
bitstream0 = 0b00001110 & 0b00001000 ;
// col 1 row 2 = blue-green
shiftOut ( dataPin1 , clockPin1 , MSBFIRST , 0b00110000 ) ;
// storing the value of the LED by grabbing only the three bits
// that control it
bitstream1 = 0b00111000 & 0b00110000 ;
// col 1 row 3 = green
shiftOut ( dataPin2 , clockPin2 , MSBFIRST , 0b01000000 ) ;
// storing the value of the LED by grabbing only the three bits
// that control it
bitstream2 = 0b11100000 & 0b01000000 ;
// third shift register goes unused in this column ; but still
// included for consistency
shiftOut ( dataPin3 , clockPin3 , MSBFIRST , 0b00000000 ) ;
bitstream3 = 0b00000000 ;
// latches high to send data
digitalWrite ( latchPin0 , HIGH ) ;
digitalWrite ( latchPin1 , HIGH ) ;
digitalWrite ( latchPin2 , HIGH ) ;
digitalWrite ( latchPin3 , HIGH ) ;
// small delay to see colors
delay ( 100 ) ;
// checking to see if the random breakpoint is reached
if ( i == breakpoint1 ){
break ;
}
// if not , add 1 to i
else {
i ++;
}
// latches low to set data
digitalWrite ( latchPin0 , LOW) ;
digitalWrite ( latchPin1 , LOW) ;
digitalWrite ( latchPin2 , LOW) ;
digitalWrite ( latchPin3 , LOW) ;
// col 1 row 1 = purple
shiftOut ( dataPin0 , clockPin0 , MSBFIRST , 0b00001010 ) ;
// storing the value of the LED by grabbing only the three bits
// that control it
bitstream0 = 0b00001110 & 0b00001010 ;
// col 1 row 1 = blue
shiftOut ( dataPin1 , clockPin1 , MSBFIRST , 0b00100000 ) ;
// storing the value of the LED by grabbing only the three bits
// that control it
bitstream1 = 0b00111000 & 0b00100000 ;
// col 1 row 1 = blue-green
shiftOut ( dataPin2 , clockPin2 , MSBFIRST , 0b11000000 ) ;
// storing the value of the LED by grabbing only the three bits
// that control it
bitstream2 = 0b11100000 & 0b11000000 ;
// third shift register goes unused in this column ; but still
// included for consistency
shiftOut ( dataPin3 , clockPin3 , MSBFIRST , 0b00000000 ) ;
bitstream3 = 0b00000000 ;
// latches high to send data
digitalWrite ( latchPin0 , HIGH ) ;
digitalWrite ( latchPin1 , HIGH ) ;
digitalWrite ( latchPin2 , HIGH ) ;
digitalWrite ( latchPin3 , HIGH ) ;
// small delay to see colors
delay ( 100 ) ;
// checking to see if the random breakpoint is reached
if ( i == breakpoint1 ){
break ;
}
// if not , add 1 to i
else {
i ++;
}
}
delay ( 1000 ) ;
// scrolling second column
// setting a random breakpoint between 12 and 51 color changes
// for the second while loop
int breakpoint2 = random (12 , 51 ) ;
// start with 0 color changes
int i2 = 0;
// making sure while loop does not exceed 51 color changes
while ( i2 <51){
// latches low to set data
digitalWrite ( latchPin0 , LOW) ;
digitalWrite ( latchPin1 , LOW) ;
digitalWrite ( latchPin2 , LOW) ;
digitalWrite ( latchPin3 , LOW) ;
// row 1 = red
// row 2 = purple
// row 3 = blue
shiftOut ( dataPin0 , clockPin0 , MSBFIRST , bitstream0 | 0b00010000 ) ;
// holding the value of the first column LED and the second column LED
bitstream00 = 0b01111110 & ( bitstream0 | 0b00010000 ) ;
shiftOut ( dataPin1 , clockPin1 , MSBFIRST , bitstream1 | 0b01000000 ) ;
// holding the value of the first column LED and the second column LED
bitstream11 = 0b11111000 & ( bitstream1 | 0b01000000 ) ;
shiftOut ( dataPin2 , clockPin2 , MSBFIRST , bitstream2 | 0b00000010 ) ;
// holding the value of the first column LED and the second column LED
bitstream22 = 0b11100010 & ( bitstream2 | 0b00000010 ) ;
shiftOut ( dataPin3 , clockPin3 , MSBFIRST , bitstream3 | 0b00001000 ) ;
// holding the value of the first column LED and the second column LED
bitstream33 = 0b00001110 & ( bitstream3 | 0b00001000 ) ;
// latches high to send data
digitalWrite ( latchPin0 , HIGH ) ;
digitalWrite ( latchPin1 , HIGH ) ;
digitalWrite ( latchPin2 , HIGH ) ;
digitalWrite ( latchPin3 , HIGH ) ;
delay ( 100 ) ;
// checking to see if the random breakpoint is reached
if ( i2 == breakpoint2 ){
break ;
}
// if not , add 1 to i
else {
i2 ++;
}
// latches low to set data
digitalWrite ( latchPin0 , LOW) ;
digitalWrite ( latchPin1 , LOW) ;
digitalWrite ( latchPin2 , LOW) ;
digitalWrite ( latchPin3 , LOW) ;
// row 1 = yellow
// row 2 = red
// row 3 = purple
shiftOut ( dataPin0 , clockPin0 , MSBFIRST , bitstream0 | 0b00110000 ) ;
// holding the value of the first column LED and the second column LED
bitstream00 = 0b01111110 & ( bitstream0 | 0b00110000 ) ;
shiftOut ( dataPin1 , clockPin1 , MSBFIRST , bitstream1 | 0b01000000 ) ;
// holding the value of the first column LED and the second column LED
bitstream11 = 0b11111000 & ( bitstream1 | 0b01000000 ) ;
shiftOut ( dataPin2 , clockPin2 , MSBFIRST , bitstream2 | 0b00000000 ) ;
// holding the value of the first column LED and the second column LED
bitstream22 = 0b11100010 & ( bitstream2 | 0b00000000 ) ;
shiftOut ( dataPin3 , clockPin3 , MSBFIRST , bitstream3 | 0b00001010 ) ;
// holding the value of the first column LED and the second column LED
bitstream33 = 0b00001110 & ( bitstream3 | 0b00001010 ) ;
// latches high to send data
digitalWrite ( latchPin0 , HIGH ) ;
digitalWrite ( latchPin1 , HIGH ) ;
digitalWrite ( latchPin2 , HIGH ) ;
digitalWrite ( latchPin3 , HIGH ) ;
delay ( 100 ) ;
// checking to see if the random breakpoint is reached
if ( i2 == breakpoint2 ){
break ;
}
// if not , add 1 to i
else {
i2 ++;
}
// latches low to set data
digitalWrite ( latchPin0 , LOW) ;
digitalWrite ( latchPin1 , LOW) ;
digitalWrite ( latchPin2 , LOW) ;
digitalWrite ( latchPin3 , LOW) ;
// row 1 = green
// row 2 = yellow
// row 3 = red
shiftOut ( dataPin0 , clockPin0 , MSBFIRST , bitstream0 | 0b00100000 ) ;
// holding the value of the first column LED and the second column LED
bitstream00 = 0b01111110 & ( bitstream0 | 0b00100000 ) ;
shiftOut ( dataPin1 , clockPin1 , MSBFIRST , bitstream1 | 0b11000000 ) ;
// holding the value of the first column LED and the second column LED
bitstream11 = 0b11111000 & ( bitstream1 | 0b11000000 ) ;
shiftOut ( dataPin2 , clockPin2 , MSBFIRST , bitstream2 | 0b00000000 ) ;
// holding the value of the first column LED and the second column LED
bitstream22 = 0b11100010 & ( bitstream2 | 0b00000000 ) ;
shiftOut ( dataPin3 , clockPin3 , MSBFIRST , bitstream3 | 0b00000010 ) ;
// holding the value of the first column LED and the second column LED
bitstream33 = 0b00001110 & ( bitstream3 | 0b00000010 ) ;
// latches high to send data
digitalWrite ( latchPin0 , HIGH ) ;
digitalWrite ( latchPin1 , HIGH ) ;
digitalWrite ( latchPin2 , HIGH ) ;
digitalWrite ( latchPin3 , HIGH ) ;
delay ( 100 ) ;
// checking to see if the random breakpoint is reached
if ( i2 == breakpoint2 ){
break ;
}
// if not , add 1 to i
else {
i2 ++;
}
// latches low to set data
digitalWrite ( latchPin0 , LOW) ;
digitalWrite ( latchPin1 , LOW) ;
digitalWrite ( latchPin2 , LOW) ;
digitalWrite ( latchPin3 , LOW) ;
// row 1 = blue-green
// row 2 = green
// row 3 = yellow
shiftOut ( dataPin0 , clockPin0 , MSBFIRST , bitstream0 | 0b01100000 ) ;
// holding the value of the first column LED and the second column LED
bitstream00 = 0b01111110 & ( bitstream0 | 0b01100000 ) ;
shiftOut ( dataPin1 , clockPin1 , MSBFIRST , bitstream1 | 0b10000000 ) ;
// holding the value of the first column LED and the second column LED
bitstream11 = 0b11111000 & ( bitstream1 | 0b10000000 ) ;
shiftOut ( dataPin2 , clockPin2 , MSBFIRST , bitstream2 | 0b00000000 ) ;
// holding the value of the first column LED and the second column LED
bitstream22 = 0b11100010 & ( bitstream2 | 0b00000000 ) ;
shiftOut ( dataPin3 , clockPin3 , MSBFIRST , bitstream3 | 0b00000110 ) ;
// holding the value of the first column LED and the second column LED
bitstream33 = 0b00001110 & ( bitstream3 | 0b00000110 ) ;
// latches high to send data
digitalWrite ( latchPin0 , HIGH ) ;
digitalWrite ( latchPin1 , HIGH ) ;
digitalWrite ( latchPin2 , HIGH ) ;
digitalWrite ( latchPin3 , HIGH ) ;
delay ( 100 ) ;
// checking to see if the random breakpoint is reached
if ( i2 == breakpoint2 ){
break ;
}
// if not , add 1 to i
else {
i2 ++;
}
// latches low to set data
digitalWrite ( latchPin0 , LOW) ;
digitalWrite ( latchPin1 , LOW) ;
digitalWrite ( latchPin2 , LOW) ;
digitalWrite ( latchPin3 , LOW) ;
// row 1 = blue
// row 2 = blue-green
// row 3 = green
shiftOut ( dataPin0 , clockPin0 , MSBFIRST , bitstream0 | 0b01000000 ) ;
// holding the value of the first column LED and the second column LED
bitstream00 = 0b01111110 & ( bitstream0 | 0b01000000 ) ;
shiftOut ( dataPin1 , clockPin1 , MSBFIRST , bitstream1 | 0b10000000 ) ;
// holding the value of the first column LED and the second column LED
bitstream11 = 0b11111000 & ( bitstream1 | 0b10000000 ) ;
shiftOut ( dataPin2 , clockPin2 , MSBFIRST , bitstream2 | 0b00000010 ) ;
// holding the value of the first column LED and the second column LED
bitstream22 = 0b11100010 & ( bitstream2 | 0b00000010 ) ;
shiftOut ( dataPin3 , clockPin3 , MSBFIRST , bitstream3 | 0b00000100 ) ;
// holding the value of the first column LED and the second column LED
bitstream33 = 0b00001110 & ( bitstream3 | 0b00000100 ) ;
// latches high to send data
digitalWrite ( latchPin0 , HIGH ) ;
digitalWrite ( latchPin1 , HIGH ) ;
digitalWrite ( latchPin2 , HIGH ) ;
digitalWrite ( latchPin3 , HIGH ) ;
delay ( 100 ) ;
// checking to see if the random breakpoint is reached
if ( i2 == breakpoint2 ){
break ;
}
// if not , add 1 to i
else {
i2 ++;
}
// latches low to set data
digitalWrite ( latchPin0 , LOW) ;
digitalWrite ( latchPin1 , LOW) ;
digitalWrite ( latchPin2 , LOW) ;
digitalWrite ( latchPin3 , LOW) ;
// row 1 = purple
// row 2 = blue
// row 3 = blue-green
shiftOut ( dataPin0 , clockPin0 , MSBFIRST , bitstream0 | 0b01010000 ) ;
// holding the value of the first column LED and the second column LED
bitstream00 = 0b01111110 & ( bitstream0 | 0b01010000 ) ;
shiftOut ( dataPin1 , clockPin1 , MSBFIRST , bitstream1 | 0b00000000 ) ;
// holding the value of the first column LED and the second column LED
bitstream11 = 0b11111000 & ( bitstream1 | 0b00000000 ) ;
shiftOut ( dataPin2 , clockPin2 , MSBFIRST , bitstream2 | 0b00000010 ) ;
// holding the value of the first column LED and the second column LED
bitstream22 = 0b11100010 & ( bitstream2 | 0b00000010 ) ;
shiftOut ( dataPin3 , clockPin3 , MSBFIRST , bitstream3 | 0b00001100 ) ;
// holding the value of the first column LED and the second column LED
bitstream33 = 0b00001110 & ( bitstream3 | 0b00001100 ) ;
// latches high to send data
digitalWrite ( latchPin0 , HIGH ) ;
digitalWrite ( latchPin1 , HIGH ) ;
digitalWrite ( latchPin2 , HIGH ) ;
digitalWrite ( latchPin3 , HIGH ) ;
delay ( 100 ) ;
// checking to see if the random breakpoint is reached
if ( i2 == breakpoint2 ){
break ;
}
// if not , add 1 to i
else {
i2 ++;
}
}
delay ( 1000 ) ;
// scrolling column 3
// setting a random breakpoint between 12 and 51 color changes
// for the third while loop
int breakpoint3 = random (12 , 51 ) ;
// setting i to 0 color changes
int i3 = 0;
// making sure while loop does not exceed 51 color changes
while ( i3 <51){
// latches low to set data
digitalWrite ( latchPin0 , LOW) ;
digitalWrite ( latchPin1 , LOW) ;
digitalWrite ( latchPin2 , LOW) ;
digitalWrite ( latchPin3 , LOW) ;
// row 1 = red
// row 2 = purple
// row 3 = blue
shiftOut ( dataPin0 , clockPin0 , MSBFIRST , bitstream00 | 0b10000000 ) ;
// holding the value of the first , second , and third column LEDs
bitstream000 = 0b11111110 & ( bitstream00 | 0b10000000 ) ;
shiftOut ( dataPin1 , clockPin1 , MSBFIRST , bitstream11 | 0b00000000 ) ;
// holding the value of the first , second , and third column LEDs
bitstream111 = 0b11111110 & ( bitstream11 | 0b00000000 ) ;
shiftOut ( dataPin2 , clockPin2 , MSBFIRST , bitstream22 | 0b00010100 ) ;
// holding the value of the first , second , and third column LEDs
bitstream222 = 0b11111110 & ( bitstream22 | 0b00010100 ) ;
shiftOut ( dataPin3 , clockPin3 , MSBFIRST , bitstream33 | 0b01000000 ) ;
// holding the value of the first , second , and third column LEDs
bitstream333 = 0b01111110 & ( bitstream33 | 0b01000000 ) ;
// latches high to send data
digitalWrite ( latchPin0 , HIGH ) ;
digitalWrite ( latchPin1 , HIGH ) ;
digitalWrite ( latchPin2 , HIGH ) ;
digitalWrite ( latchPin3 , HIGH ) ;
delay ( 100 ) ;
// checking to see if the random breakpoint is reached
if ( i3 == breakpoint3 ){
break ;
}
// if not , add 1 to i
else {
i3 ++;
}
// latches low to set data
digitalWrite ( latchPin0 , LOW) ;
digitalWrite ( latchPin1 , LOW) ;
digitalWrite ( latchPin2 , LOW) ;
digitalWrite ( latchPin3 , LOW) ;
// row 1 = yellow
// row 2 = red
// row 3 = purple
shiftOut ( dataPin0 , clockPin0 , MSBFIRST , bitstream00 | 0b10000000 ) ;
// holding the value of the first , second , and third column LEDs
bitstream000 = 0b11111110 & ( bitstream00 | 0b10000000 ) ;
shiftOut ( dataPin1 , clockPin1 , MSBFIRST , bitstream11 | 0b00000010 ) ;
// holding the value of the first , second , and third column LEDs
bitstream111 = 0b11111110 & ( bitstream11 | 0b00000010 ) ;
shiftOut ( dataPin2 , clockPin2 , MSBFIRST , bitstream22 | 0b00000100 ) ;
// holding the value of the first , second , and third column LEDs
bitstream222 = 0b11111110 & ( bitstream22 | 0b00000100 ) ;
shiftOut ( dataPin3 , clockPin3 , MSBFIRST , bitstream33 | 0b01010000 ) ;
// holding the value of the first , second , and third column LEDs
bitstream333 = 0b01111110 & ( bitstream33 | 0b01010000 ) ;
// latches high to send data
digitalWrite ( latchPin0 , HIGH ) ;
digitalWrite ( latchPin1 , HIGH ) ;
digitalWrite ( latchPin2 , HIGH ) ;
digitalWrite ( latchPin3 , HIGH ) ;
delay ( 100 ) ;
// checking to see if the random breakpoint is reached
if ( i3 == breakpoint3 ){
break ;
}
// if not , add 1 to i
else {
i3 ++;
}
// latches low to set data
digitalWrite ( latchPin0 , LOW) ;
digitalWrite ( latchPin1 , LOW) ;
digitalWrite ( latchPin2 , LOW) ;
digitalWrite ( latchPin3 , LOW) ;
// row 1 = green
// row 2 = yellow
// row 3 = red
shiftOut ( dataPin0 , clockPin0 , MSBFIRST , bitstream00 | 0b00000000 ) ;
// holding the value of the first , second , and third column LEDs
bitstream000 = 0b11111110 & ( bitstream00 | 0b00000000 ) ;
shiftOut ( dataPin1 , clockPin1 , MSBFIRST , bitstream11 | 0b00000100 ) ;
// holding the value of the first , second , and third column LEDs
bitstream111 = 0b11111110 & ( bitstream11 | 0b00000100 ) ;
shiftOut ( dataPin2 , clockPin2 , MSBFIRST , bitstream22 | 0b00011000 ) ;
// holding the value of the first , second , and third column LEDs
bitstream222 = 0b11111110 & ( bitstream22 | 0b00011000 ) ;
shiftOut ( dataPin3 , clockPin3 , MSBFIRST , bitstream33 | 0b00100000 ) ;
// holding the value of the first , second , and third column LEDs
bitstream333 = 0b01111110 & ( bitstream33 | 0b00100000 ) ;
// latches high to send data
digitalWrite ( latchPin0 , HIGH ) ;
digitalWrite ( latchPin1 , HIGH ) ;
digitalWrite ( latchPin2 , HIGH ) ;
digitalWrite ( latchPin3 , HIGH ) ;
delay ( 100 ) ;
// checking to see if the random breakpoint is reached
if ( i3 == breakpoint3 ){
break ;
}
// if not , add 1 to i
else {
i3 ++;
}
// latches low to set data
digitalWrite ( latchPin0 , LOW) ;
digitalWrite ( latchPin1 , LOW) ;
digitalWrite ( latchPin2 , LOW) ;
digitalWrite ( latchPin3 , LOW) ;
// row 1 = blue-green
// row 2 = green
// row 3 = yellow
shiftOut ( dataPin0 , clockPin0 , MSBFIRST , bitstream00 | 0b00000000 ) ;
// holding the value of the first , second , and third column LEDs
bitstream000 = 0b11111110 & ( bitstream00 | 0b00000000 ) ;
shiftOut ( dataPin1 , clockPin1 , MSBFIRST , bitstream11 | 0b00000110 ) ;
// holding the value of the first , second , and third column LEDs
bitstream111 = 0b11111110 & ( bitstream11 | 0b00000110 ) ;
shiftOut ( dataPin2 , clockPin2 , MSBFIRST , bitstream22 | 0b00001000 ) ;
// holding the value of the first , second , and third column LEDs
bitstream222 = 0b11111110 & ( bitstream22 | 0b00001000 ) ;
shiftOut ( dataPin3 , clockPin3 , MSBFIRST , bitstream33 | 0b00110000 ) ;
// holding the value of the first , second , and third column LEDs
bitstream333 = 0b01111110 & ( bitstream33 | 0b00110000 ) ;
// latches high to send data
digitalWrite ( latchPin0 , HIGH ) ;
digitalWrite ( latchPin1 , HIGH ) ;
digitalWrite ( latchPin2 , HIGH ) ;
digitalWrite ( latchPin3 , HIGH ) ;
delay ( 100 ) ;
// checking to see if the random breakpoint is reached
if ( i3 == breakpoint3 ){
break ;
}
// if not , add 1 to i
else {
i3 ++;
}
// latches low to set data
digitalWrite ( latchPin0 , LOW) ;
digitalWrite ( latchPin1 , LOW) ;
digitalWrite ( latchPin2 , LOW) ;
digitalWrite ( latchPin3 , LOW) ;
// row 1 = blue
// row 2 = blue-green
// row 3 = green
shiftOut ( dataPin0 , clockPin0 , MSBFIRST , bitstream00 | 0b00000000 ) ;
// holding the value of the first , second , and third column LEDs
bitstream000 = 0b11111110 & ( bitstream00 | 0b00000000 ) ;
shiftOut ( dataPin1 , clockPin1 , MSBFIRST , bitstream11 | 0b00000010 ) ;
// holding the value of the first , second , and third column LEDs
bitstream111 = 0b11111110 & ( bitstream11 | 0b00000010 ) ;
shiftOut ( dataPin2 , clockPin2 , MSBFIRST , bitstream22 | 0b00001100 ) ;
// holding the value of the first , second , and third column LEDs
bitstream222 = 0b11111110 & ( bitstream22 | 0b00001100 ) ;
shiftOut ( dataPin3 , clockPin3 , MSBFIRST , bitstream33 | 0b00010000 ) ;
// holding the value of the first , second , and third column LEDs
bitstream333 = 0b01111110 & ( bitstream33 | 0b00010000 ) ;
// latches high to send data
digitalWrite ( latchPin0 , HIGH ) ;
digitalWrite ( latchPin1 , HIGH ) ;
digitalWrite ( latchPin2 , HIGH ) ;
digitalWrite ( latchPin3 , HIGH ) ;
delay ( 100 ) ;
// checking to see if the random breakpoint is reached
if ( i3 == breakpoint3 ){
break ;
}
// if not , add 1 to i
else {
i3 ++;
}
// latches low to set data
digitalWrite ( latchPin0 , LOW) ;
digitalWrite ( latchPin1 , LOW) ;
digitalWrite ( latchPin2 , LOW) ;
digitalWrite ( latchPin3 , LOW) ;
// row 1 = purple
// row 2 = blue
// row 3 = blue-green
shiftOut ( dataPin0 , clockPin0 , MSBFIRST , bitstream00 | 0b10000000 ) ;
// holding the value of the first , second , and third column LEDs
bitstream000 = 0b11111110 & ( bitstream00 | 0b10000000 ) ;
shiftOut ( dataPin1 , clockPin1 , MSBFIRST , bitstream11 | 0b00000100 ) ;
// holding the value of the first , second , and third column LEDs
bitstream111 = 0b11111110 & ( bitstream11 | 0b00000100 ) ;
shiftOut ( dataPin2 , clockPin2 , MSBFIRST , bitstream22 | 0b00010000 ) ;
// holding the value of the first , second , and third column LEDs
bitstream222 = 0b11111110 & ( bitstream22 | 0b00010000 ) ;
shiftOut ( dataPin3 , clockPin3 , MSBFIRST , bitstream33 | 0b01100000 ) ;
// holding the value of the first , second , and third column LEDs
bitstream333 = 0b01111110 & ( bitstream33 | 0b01100000 ) ;
// latches high to send data
digitalWrite ( latchPin0 , HIGH ) ;
digitalWrite ( latchPin1 , HIGH ) ;
digitalWrite ( latchPin2 , HIGH ) ;
digitalWrite ( latchPin3 , HIGH ) ;
delay ( 100 ) ;
// checking to see if the random breakpoint is reached
if ( i3 == breakpoint3 ){
break ;
}
// if not , add 1 to i
else {
i3 ++;
}
}
// win/lose
// grabbing the bits from all LEDs in row 3
// moving the LED bits over to make them comparable
byte bitsA = ( bitstream2 & 0b11100000 ) >> 5;
// this number at the end is essentially deleting the zeros
byte bitsB = ( bitstream33 & 0b00001110 ) >> 1;
byte bitsC = ( bitstream333 & 0b01110000 ) >> 4;
// printing for troubleshooting
Serial.print (" bitsA : " ) ; Serial.println ( bitsA , BIN ) ;
Serial.print (" bitsB : " ) ; Serial.println ( bitsB , BIN ) ;
Serial.print (" bitsC : " ) ; Serial.println ( bitsC , BIN ) ;
// if all 3 LEDs are equal
if ( bitsA == bitsB && bitsB == bitsC ) {
// blinking green on medium LED
digitalWrite (A1 , HIGH ) ;
delay ( 200 ) ;
digitalWrite (A1 , LOW) ;
delay ( 200 ) ;
digitalWrite (A1 , HIGH ) ;
delay ( 200 ) ;
digitalWrite (A1 , LOW) ;
delay ( 200 ) ;
digitalWrite (A1 , HIGH ) ;
delay ( 200 ) ;
digitalWrite (A1 , LOW) ;
delay ( 200 ) ;
digitalWrite (A1 , HIGH ) ;
delay ( 200 ) ;
digitalWrite (A1 , LOW) ;
delay ( 200 ) ;
digitalWrite (A1 , HIGH ) ;
delay ( 200 ) ;
digitalWrite (A1 , LOW) ;
delay ( 200 ) ;
digitalWrite (A1 , HIGH ) ;
// hold green for 10 s
delay ( 5000 ) ;
// LED off
digitalWrite (A1 , LOW) ;
}
// if LEDs are different
else {
// medium LED turns red
digitalWrite (A0 , HIGH ) ;
// holds for 5 s
delay ( 3000 ) ;
// LED off
digitalWrite (A0 , LOW) ;
}
// reset game
scrollStarted = false ;
}
}
