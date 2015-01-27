//SpektrumSattelite Receiver Libriary
//Tested with Arduino DUE, Orange RX DSMX and Spektrum DX9
//To make it work on UNO or similar, change all shorts to ints and select the right serial (in the libriary)
#include <SpektrumSattelite.h>

SpektrumSattelite rx;

void setup()
{
  Serial.begin(115200);
  Serial3.begin(115200); //Uses Serial3 for input as default
}

void loop()
{
  rx.getFrame();

  Serial.print(rx.getThro());
  Serial.print("\t");
  Serial.print(rx.getAile());
  Serial.print("\t");
  Serial.print(rx.getElev());
  Serial.print("\t");
  Serial.print(rx.getRudd());
  Serial.print("\t");
  Serial.print(rx.getGear());
  Serial.print("\t");
  Serial.print(rx.getPitc());
  Serial.print("\t");
  Serial.print(rx.getAux2());
  Serial.print("\t");
  Serial.print(rx.getAux3());
  Serial.print("\t");
  Serial.print(rx.getAux4());
  Serial.print("\t");
  
  Serial.print('\n');
}
