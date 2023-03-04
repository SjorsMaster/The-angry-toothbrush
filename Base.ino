#include "signalenzo.h" //Thanks to Aeralius for helping create this library!

  float lastValue;
  bool on;

  void setup() {
     //Opening connection
     Serial.begin(9600);

    pinMode(7, OUTPUT);
    //Regestering all the buttons  
    //pinMode(7, INPUT_PULLUP);
    //registerSignalCommand(1);
    //pinMode(6, INPUT_PULLUP);
    //registerSignalCommand(6);  
    //pinMode(4, INPUT_PULLUP);
    //registerSignalCommand(4);  
    pinMode(5, INPUT_PULLUP);
  }

  void loop() {
    //Don't torture the Arduino :)
    delay(50);
    checkSignals();
  

    float Input = analogRead(0);
    
    float five = digitalRead(5);
    Serial.print("A0,"); Serial.print(Input); Serial.print(" || "); Serial.print("D5,"); Serial.print(five); Serial.print("\n");

    ////Check if laying down, if so, turn on
    //if(five == 0 && Input > 200 && !on){
    //on = true;
    //Serial.print("\n\n\n\n---offandlaying!!!!---\n\n\n\n");
         
    //digitalWrite(7,LOW);
    //delay(1000);
    //}
    ////

    ////Check if pressure
    if(Input > 200){ //Which means off
    //on = false;
    digitalWrite(7,HIGH);
    
    
    delay(1000);
      }
    else if(Input <= 200){ //means on
          if(Input > 10){         
    digitalWrite(7,HIGH);
    delay(100);
    digitalWrite(7,LOW);
    
    Serial.print("TURNING OFF\n,"); 
    
          }
      }

    
    
  }
