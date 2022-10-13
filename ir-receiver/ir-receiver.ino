
#include <IRremote.h>
int recvPin = 13;
IRrecv irrecv(recvPin);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
}


void loop() {
  if (irrecv.decode(&results)) 
  {
   Serial.println("a value"); 
   Serial.println(results.value, HEX);
   irrecv.resume();
  }
}
