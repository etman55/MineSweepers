void reportXY(){
  
  if(direct >= 340 && direct <= 20 ){//North
     CheckDirection();
     dist+=x;
//     bluetooth.println(xCoordinate[x]);
     
     }else if(direct >= 160 && direct <= 200){//South
     CheckDirection();
     dist-=x;
     
//     bluetooth.println(" "+yCoordinate);
    }else if(direct >= 70 && direct <= 110){//East
      CheckDirection();
      dist -=yCoordinate;
//      bluetooth.println(" "+yCoordinate);
    }else if(direct >= 250 && direct <= 290){//West
     CheckDirection();
     dist +=yCoordinate;  
//     bluetooth.println(" "+yCoordinate);
//     bluetooth.println(xCoordinate[x]);
     }
     bluetooth.println(xCoordinate[x]);
    bluetooth.println(yCoordinate);
}
