

#define n 20000

int motor_pin_1 = 8;
int motor_pin_2 = 9;
int motor_pin_3 = 10;
int motor_pin_4 = 11;
int no;
void setup()
{ Serial.begin (9600);
  pinMode(motor_pin_1, OUTPUT);
  pinMode(motor_pin_2, OUTPUT);
  pinMode(motor_pin_3, OUTPUT);
  pinMode(motor_pin_4, OUTPUT);
}

void loop ()
{
  for (int i = 0; i <= 3; i++)
  {

    switch (i) {
      case 0:  // 1010
        digitalWrite(motor_pin_1, HIGH);
        digitalWrite(motor_pin_2, LOW);
        digitalWrite(motor_pin_3, LOW );
        digitalWrite(motor_pin_4, LOW);
        delayMicroseconds(n);
        break;
      case 1:  // 0110
        digitalWrite(motor_pin_1, LOW);
        digitalWrite(motor_pin_2, LOW );
        digitalWrite(motor_pin_3, HIGH );
        digitalWrite(motor_pin_4, LOW);
        delayMicroseconds(n);
        break;
      case 2:  //0101
        digitalWrite(motor_pin_1, LOW);
        digitalWrite(motor_pin_2, HIGH );
        digitalWrite(motor_pin_3,LOW );
        digitalWrite(motor_pin_4, LOW );
        delayMicroseconds(n);
        break;
      case 3:  //1001
        digitalWrite(motor_pin_1, LOW);
        digitalWrite(motor_pin_2, LOW);
        digitalWrite(motor_pin_3, LOW);
        digitalWrite(motor_pin_4, HIGH);
        delayMicroseconds(n);
        break;


    }
  }
}

