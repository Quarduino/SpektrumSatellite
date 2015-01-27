//SpektrumSattelite Receiver Libriary
#ifndef SPECTRUMRECEIVER_H_
#define SPECTRUMRECEIVER_H_

#include "Arduino.h"
class SpektrumSattelite
{
	public:
		bool getFrame();
		short getChannelValue(short);
		short getThro();
		short getAile();
		short getElev();
		short getRudd();
		short getGear();
		short getPitc();
		short getAux2();
		short getAux3();
		short getAux4();
		bool getTrans();
	private:
		short inData[16];
		short i;
		short inByte;
		
		short chVal[9];
		unsigned short tempData;
		unsigned short temp;
		unsigned short tempId;
		unsigned short tempVal;
		unsigned long time;
};


#endif /* SPECTRUMRECEIVER_H_ */
