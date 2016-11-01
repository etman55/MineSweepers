//Check If The Mine Under Or Over The Ground
void underOver(){
  int duration, distance; //duration used to calc distance 
  digitalWrite(trigPin, HIGH); //sending on tigger to ultrasonic
  delay(1000);
  digitalWrite(trigPin, LOW); //low trigger to claculate the duration & distance in "this" pulse 

  duration= pulseIn(echoPin, HIGH); 
  /* Reads a pulse (either HIGH or LOW) on a pin. For example, if value is HIGH, pulseIn() waits for the pin to go HIGH, starts timing, then waits for the pin to go LOW and stops timing.
  Returns the length of the pulse in microseconds. Gives up and returns 0 if no pulse starts within a specified time out.
  The timing of this function has been determined empirically and will probably show errors in longer pulses. Works on pulses from 10 microseconds to 3 minutes in length. */
  distance = (duration*0.0343)/2; //the equation 
  
  if(distance <= 70){
    mineStatus= 1;
  }else{
    mineStatus= 2;
  }
  
}
