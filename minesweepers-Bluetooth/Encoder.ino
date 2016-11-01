void updateEncoder()
{
  int MSB = digitalRead(encoderPin1); //MSB = most significant bit
  int LSB = digitalRead(encoderPin2); //LSB = least significant bit

  int encoded = (MSB << 1) | LSB;
  /* "variable << number of bits " means -> shift left by 1 step then add with LSB
  as variable is integer it is sored in 16 bits 
  -------converting the 2 pin value to single number*/
  
  int sum  = (lastEncoded << 2) | encoded; 
  /*int a =  92;    // in binary: 0000000001011100
    int b = 101;    // in binary: 0000000001100101
    int c = a | b;  // result:    0000000001111101, or 125 in decimal. 
    -----adding it to the previous encoded value*/

//clock wise movement
  if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) encoderValue ++;
// counter-clockwise movement
  if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) encoderValue --;

  lastEncoded = encoded; //store this value for next time
  
}
