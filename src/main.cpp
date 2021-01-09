#include <CapacitiveSensor.h>

/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 */


CapacitiveSensor   cs_5_4 = CapacitiveSensor(5,4);        // 10M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil

void setup()                    
{
   //cs_5_4.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   cs_5_4.set_CS_Timeout_Millis(100000);

   Serial.begin(9600);
   pinMode(LED_BUILTIN, OUTPUT);                         //set d13 as led output for sensing
   pinMode(14, OUTPUT);
   }

void loop()                    
{
    long start = millis();
       long total3 =  cs_5_4.capacitiveSensor(30);

    Serial.print(millis() - start);        // check on performance in milliseconds
    Serial.print("\t");                    // tab character for debug windown spacing

    Serial.print("\t");
    Serial.println(total3);                // print sensor output 3

    if (total3 >= 2000)
    {
      digitalWrite(LED_BUILTIN, LOW);
      digitalWrite(14, LOW);
      delay(1000);
    }
    else
    {
      digitalWrite(LED_BUILTIN, HIGH);
      digitalWrite(14, HIGH);
    }
    
    
    // TESTING AREA 
  
    
    


    /* if (total3 > 20) digitalWrite(LED_BUILTIN, HIGH);
    else delay(1000); 
    digitalWrite(LED_BUILTIN, LOW); */


    // need to set output delay so touch is instant but off is delayed
    

  }