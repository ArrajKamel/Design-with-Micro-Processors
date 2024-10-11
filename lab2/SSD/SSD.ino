const unsigned char ssdlut[] = {
//0bDotGFEDCBA
    0b00111111, //0
    0b00000110, //1
    0b01011011, //2
    0b01001111, //3
    0b01100110, //4
    0b01101101, //5
    0b01111101, //6
    0b00000111, //7
    0b01111111, //8
    0b01101111 //9
    // 0b01110111, //A
    // 0b01111100, //b
    // 0b00111001, //c
    // 0b01011110, //d
    // 0b01111001, //E
    // 0b11110001, //F
  };

// the size of the lut
// const int lutsize = 16; // for hexadecimal counting 
const int lutsize = 10;

int cpos_left = 0; // current position
int cpos_right = 0 ; 
int cdigit = 0; // first digit from the two
unsigned char outvalue = 0;
bool indecator = false; 

void setup() {
  DDRA = 0b11111111;
}

void loop() {
  // outvalue = cdigit > 0 ? 0x80 : 0;
  // // which cathode are we choosing ? (00000000 or 10000000)
  // // the cathode is wired to bit7 from port A, through this
  // //operation we are setting bit 7 on
  // //logical 1 or
  // //0, alternatively, the following bits will be attached
  // //through a logical OR operation in the
  // //following
  // //line of code
  // PORTA = (ssdlut[cpos] | outvalue); // we make an OR
  // //between the value from the LUT
  // // and the selected cathode
  // cpos++; // we increment the current position
  // if (cpos>=lutsize) { // if we reached the final position
  //   cpos = 0; // we come back at 0
  // cdigit^=1; // if the previus digit was 0 we make it a
  // //1 and vice versa

  // if(cdigit > 0)
  //   outvalue = 0x80; 
  // else 
  //   outvalue = 0x00; 


//////////////////////DISPLALY TWO DIGIT SIMULTANEOUSLY///// 
    // cpos_left = 0;
    // PORTA = (ssdlut[cpos_left] | outvalue); // we make an OR
    // outvalue = 0x00;
    // delay(5);
    
    // cpos_right = 5;
    // PORTA = (ssdlut[cpos_right] | outvalue); // we make an OR
    // outvalue = 0x80;
    // delay(5);


  // wait 0.5 sec
  // delay(500);
}
