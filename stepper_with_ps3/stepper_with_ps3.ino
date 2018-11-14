#include <PS3USB.h>

#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>

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
}

void loop()
{
  Usb.Task();

  if (PS3.PS3Connected || PS3.PS3NavigationConnected)
  { //////////////////////////////////////

    if (PS3.getAnalogButton(L2) || PS3.getAnalogButton(R2))
    {
      {Serial.print(F("\r\nL2: "));
      Serial.print(PS3.getAnalogButton(L2));
      int antispeed = map (PS3.getAnalogButton(L2), 0, 255, 0, maxspeed);
      while (antispeed > 60)
      { stepper.setSpeed(antispeed);
        stepper.step(-1);
      }}



      if (!PS3.PS3NavigationConnected)
      {
        Serial.print(F("\tR2: "));
        Serial.print(PS3.getAnalogButton(R2));
        int clspeed = map (PS3.getAnalogButton(L2), 0, 255, 0, maxspeed);
        while (clspeed > 60)
        { stepper.setSpeed(clspeed);
          stepper.step(1);
        }
      }
    }
  }
}
