//Check If Mine Exsists
void metalScan(){
  int mine= digitalRead(detectPin); // read input value & store in Val 
  if(mine == HIGH){
    underOver(); 
        bluetooth.print(mineStatus); 
    delay(70);
    reportXY();
      
        
  }else{
    mineStatus= 0;

  }
   
}
