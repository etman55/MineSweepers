  #include<Wire.h> //I2C Arduino Library
  #include <SoftwareSerial.h>
  #include <Servo.h> 
  #define address 0x1E //Slave Address for HMC5883L Compass
  
  //servor object  
  Servo myservo;
  int pos = 0;//degrees for the servo
  
  //software serial object  
  SoftwareSerial bluetooth(10, 11); // RX, TX
  char BluetoothData;// char for reading the bluetooth buffer
    
  //Metal Detector
  int detectPin= 4;
  
  
  //Compass
  float headingDegrees;
  float initialHeadingDegrees;
  bool ini= false;
  float direct;
  
  //for checking if the robot has rotated or not
  static char directionCheck;
  
  //these pins can not be changed 2/3 are special pins
  int encoderPin1 = 2;
  int encoderPin2 = 3;
  volatile int lastEncoded = 0;
  volatile long encoderValue = 0;
  // storing the distance the robot moved
  int  dist;
  
  //Ultra sonic pins  
  int trigPin =12; //trigger pin 
  int echoPin =13; // echo pin 
  
  //H-Bridge pins
  int ma1=8;
  int ma2=9;
  int mb1=6;
  int mb2=7;
  
  // ini the data to be sent to mobile for drawing map
  int mineStatus;
  char* xCoordinate[19] = {" A", " B", " C", " D", " E", " F",
            " G"," H"," I", " J"," K"," L"," M"," N"," O"," P"," Q"," R"," S"};
  static int x;
  static int yCoordinate;
  

void setup() {
  
  //H-Bridge pins
  pinMode(ma1,OUTPUT);
  pinMode(ma2,OUTPUT);
  pinMode(mb1,OUTPUT);
  pinMode(mb2,OUTPUT);
  
  //servo pins
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
 
  //metal detector pins
  pinMode(detectPin, INPUT); // detector densor as input 
  
  //I2C protocol ini for the compass
  Wire.begin();
  Wire.beginTransmission(address); //open communication with HMC5883
  Wire.write(0x02); //select mode register
  Wire.write(0x00); //continuous measurement mode
  Wire.endTransmission();
  
  //serial and bluetooth ini
  Serial.begin(9600);
  bluetooth.begin(9600);
  
  
  //encoder pins
  pinMode(encoderPin1, INPUT); 
  pinMode(encoderPin2, INPUT);
  digitalWrite(encoderPin1, HIGH); //turn pullup resistor on
  digitalWrite(encoderPin2, HIGH); //turn pullup resistor on
  //call updateEncoder() when any high/low changed seen
  //on interrupt 0 (pin 2), or interrupt 1 (pin 3) 
  attachInterrupt(0, updateEncoder, CHANGE); 
  attachInterrupt(1, updateEncoder, CHANGE);
}

void loop() {
   if(ini == false){
      compass();
      xCoordinate[0];
      yCoordinate=0;     
      ini= true;
  }
  
  // update the robot moved distance  
  dist=(encoderValue*2*PI*5/48)/100;



  if (bluetooth.available())
  {
  BluetoothData=bluetooth.read();   
  if(BluetoothData=='1')          //robot forward
  {
    up();
    //Serial.println("Moving Up");
    //bluetooth.println(" Up");
  
  }
  else if(BluetoothData=='3')  {//robot right
    
    right();
    CheckDirection();
    compass();
    //Serial.println("Moving Right");
    //bluetooth.println(" Right");
    
  }
  else if(BluetoothData=='4')  {//robot left
      left();  
      CheckDirection();
      compass();
      //bluetooth.println(" Left");
      //Serial.println("Moving Left");
  
  }
  else if(BluetoothData=='2')  {//robot back
      down();
      //bluetooth.println(" Down");
      //Serial.println("Moving down");
  
  }
  else if(BluetoothData=='0')  {
      Stop();
      //bluetooth.println(" Stopped");        
      //Serial.println("Robot stopped");
      }
      else if (BluetoothData=='5'){ //Scan mines
      
      //bluetooth.print(" 1"); //test appeared mine
      
      //bluetooth.println(" 15");
        metalScan();
        }
     
  }

}
