//SpektrumSattelite Receiver Libriary
//Tested with Arduino DUE, Orange RX DSMX and Spektrum DX9
//To make it work on UNO or similar, change all shorts to ints and select the right serial
#include "SpektrumSattelite.h"

bool SpektrumSattelite::getFrame(void)
{	
	  while (Serial3.available() >= 16)
	  {
	  time = millis();
		for (i = 0; i <= 15; i++)
		{
		  inByte = Serial3.read();
		  inData[i] = inByte;
		}
	  }

    for (i = 1; i < 8; i++)
    {
      temp = inData[i * 2] * 256 + inData[i * 2 + 1];

      tempId = temp >> 11;

      tempVal = temp << 5;
      tempVal = tempVal >> 5;

		if (tempId < 9)
		{
		  chVal[tempId] = tempVal - 342;
		}
		else 
		{
		  //error, ignore ;)
		}
	}
	
	return getTrans();
  
}

bool SpektrumSattelite::getTrans()
{
	if (millis() - time > 1000)
	{
		return false;
	}
	else	
	{
		return true;
	}
}

short SpektrumSattelite::getChannelValue(short channelId)
{
	return chVal[channelId];
}

short SpektrumSattelite::getThro()
{
	return getChannelValue(0);
}

short SpektrumSattelite::getAile()
{
	return getChannelValue(1);
}

short SpektrumSattelite::getElev()
{
	return getChannelValue(2);
}

short SpektrumSattelite::getRudd()
{
	return getChannelValue(3);
}

short SpektrumSattelite::getGear()
{
	return getChannelValue(4);
}

short SpektrumSattelite::getPitc()
{
	return getChannelValue(5);
}

short SpektrumSattelite::getAux2()
{
	return getChannelValue(6);
}

short SpektrumSattelite::getAux3()
{
	return getChannelValue(7);
}

short SpektrumSattelite::getAux4()
{
	return getChannelValue(8);
}