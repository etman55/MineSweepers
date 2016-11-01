//Watch Direction
void compass(){
  int xAxis, yAxis, zAxis; //triple axis data
  
  

  //Tell the HMC5883L where to begin reading data
  Wire.beginTransmission(address);
  Wire.write(0x03); //select register 3, X MSB register
  Wire.endTransmission();
  
 
  //Read data from each axis, 2 registers per axis
  Wire.requestFrom(address, 6); 
  /*"Wire.requestFrom(address, quantity)" 
  address: the 7-bit address of the device to request bytes from
  quantity: the number of "bytes" to request*/
  
  //"wire.available()" means the available bits or the read bit like "wire.read()"
  if(6 <= Wire.available()){ 
    xAxis = Wire.read()<<8; //X msb
    xAxis |= Wire.read(); //X lsb
    zAxis = Wire.read()<<8; //Z msb
    zAxis |= Wire.read(); //Z lsb
    yAxis = Wire.read()<<8; //Y msb
    yAxis |= Wire.read(); //Y lsb
  }
  float heading = atan2(yAxis, xAxis); // arc tangent of y/x
  
  // Once you have your heading, you must then add your 'Declination Angle', which is the 'Error' of the magnetic field in your location.
  // Find yours here: http://www.magnetic-declination.com/
  // Mine is: 2� 37' W, which is 2.617 Degrees, or (which we need) 0.0456752665 radians, I will use 0.0457
  // If you cannot find your Declination, comment out these two lines, your compass will be slightly off.
  float declinationAngle = 0.483;
  /*AZ ZAQAZIQ ASH SHARQIYAH
  Latitude: 30° 35' 15.7" N
  Longitude: 31° 30' 7.2" E
  Magnetic declination: 4° 8' EAST
  Declination is POSITIVE
  Inclination: 45° 18' 
  Magnetic field strength: 43683.8 nT*/
  heading += declinationAngle;
  
  // Correct for when signs are reversed.
  if(heading < 0)
    heading= heading + 2*PI;
    
  // Check for wrap due to addition of declination.
  if(heading > 2*PI)
    heading= heading - 2*PI;
   
  // Convert radians to degrees for readability.
  headingDegrees= heading * 180/M_PI; 
  
  
  if(ini == false){
    initialHeadingDegrees= headingDegrees;
  }
  direct= headingDegrees - initialHeadingDegrees;
  
  
   // Correct for when signs are reversed.
  if(direct < 0)
    direct= direct + 360;
    
  // Check for wrap due to addition of declination.
  if(direct > 360)
    direct= direct - 360;
  
  Serial.println(direct);
  if(direct >= 340 && direct <= 20){//North
      directionCheck ='N';
     }else if(direct >= 160 && direct <= 200){//South
       directionCheck ='S';
    }else if(direct >= 70 && direct <= 110){//East
      directionCheck ='E';
    }else if(direct >= 250 && direct <= 290){//West    
      directionCheck ='W';
    }
}
