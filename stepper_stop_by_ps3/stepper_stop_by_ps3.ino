#include <PS3USB.h>

#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>
int c=0;

USB Usb;
PS3USB PS3(&Usb); // This will just create the instance
//PS3USB PS3(&Usb,0x00,0x15,0x83,0x3D,0x0A,0x57); // This will also store the bluetooth address - this can be obtained from the dongle when running the sketch

bool printAngle;
uint8_t state = 0;

#include <Stepper.h>


#define STEPS 200

Stepper stepper(STEPS, 8, 9, 10, 11);

int maxspeed = 60;

int previous = 0;
int count = 0;
void setup()
{ Serial.begin(115200);


#if !defined(__MIPSEL__)
  while (!Serial);
#endif
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); //halt
  }
  Serial.print(F("\r\nPS3 USB Library Started"));
     c=count % 200;
    Serial.println(c);
}

void loop()
{
  Usb.Task();

  if (PS3.PS3Connected || PS3.PS3NavigationConnected)
  { //////////////////////////////////////

    if (PS3.getAnalogButton(L2) || PS3.getAnalogButton(R2))
    {
      if (PS3.getButtonClick(L1))
      {
        Serial.print(F("\r\nL1"));
        for (int i = 0; ;i++)
        {
          stepper.step(1);
          count++;
        }
      }
    }
  

    if (PS3.getButtonClick(R1))
    {
      Serial.print(F("\r\nR1"));
      
     if(c==0)
     {
      stepper.step(150);
      }
      else
      {count++;
      stepper.step(1);}

    }
  }
}
