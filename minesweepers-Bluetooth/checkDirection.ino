void CheckDirection(){
  
if(direct >= 340 && direct <= 20 && directionCheck != 'N'){//North
      encoderValue=0;
     }else if(direct >= 160 && direct <= 200 && directionCheck != 'S'){//South
     encoderValue=0;
    }else if(direct >= 70 && direct <= 110 && directionCheck !='E'){//East
    encoderValue=0;
    }else if(direct >= 250 && direct <= 290 && directionCheck != 'W'){//West    
     encoderValue=0;
    }
    
}
