#include <wiringPi.h>
#include <wiringSerial.h>
#include <termios.h>
#include <debug/debug.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <cstdio>

#include "serial.h"
#include "mqttWrapper.h"

#define	LED	0

int main(void)
{
  serial serialDevice;
  mqttWrapper *mqttHandler;
  mqttHandler = new mqttWrapper("mqttTest","test","192.168.178.34", 1883);
  mqttHandler->send_message("test");
  while (true) 
  {
    if (serialDevice.serialRead() > 0) 
    {
      // if new data is available on the serial port, print it out
      std::cout << serialDevice.getData();
      mqttHandler->send_message("test");
    }
    else 
    {
      std::cout << "no data\n";
    }
  }

  while (true)
  {
		digitalWrite(LED, HIGH);  // On
		delay(100); // ms
		digitalWrite(LED, LOW);	  // Off
		delay(100);
	}
	return 0;
}