void up()
{
     digitalWrite(ma1,HIGH);
    digitalWrite(ma2,LOW);
    
    digitalWrite(mb1,HIGH);
    digitalWrite(mb2,LOW);
    delay(50);
  
}
void down(){
   
    digitalWrite(ma1,LOW);
    digitalWrite(ma2,HIGH);
    digitalWrite(mb1,LOW);
    digitalWrite(mb2,HIGH);
    delay(50);
  

}

void right()
{
    digitalWrite(ma1,LOW);
    digitalWrite(ma2,HIGH);
    digitalWrite(mb1,HIGH);
    digitalWrite(mb2,LOW);
    delay(50);
  
}


void left()
{
    digitalWrite(ma1,HIGH);
    digitalWrite(ma2,LOW);
    digitalWrite(mb1,LOW);
    digitalWrite(mb2,HIGH);
    delay(50);
  
}

void Stop()
{
    digitalWrite(ma1,LOW);
    digitalWrite(mb1,LOW);
    digitalWrite(ma2,LOW);
    digitalWrite(mb2,LOW);
    delay(50);
  
}

