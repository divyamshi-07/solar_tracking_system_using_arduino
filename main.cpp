#include <EEPROM.h>
#include <Servo.h>

Servo myservo;

const int sensor1 = A1;
const int sensor2 = A0;
const int calswitch = 2;

int val1, val2;
int pos = 45;          // Start at center position
int error = 0;
byte state = 0;

const int threshold = 20;   // Prevent servo jitter

void setup()
{
    pinMode(sensor1, INPUT);
    pinMode(sensor2, INPUT);
    pinMode(calswitch, INPUT_PULLUP);

    myservo.attach(10);
    myservo.write(pos);

    EEPROM.get(0, error);
    state = EEPROM.read(sizeof(int));

    if (state > 1)
        state = 0;
}

void loop()
{
    // Calibration Mode (switch pressed)
    if (digitalRead(calswitch) == LOW)
    {
        myservo.detach();

        val1 = analogRead(sensor1);
        val2 = analogRead(sensor2);

        if (val1 > val2)
        {
            error = val1 - val2;
            state = 0;
        }
        else
        {
            error = val2 - val1;
            state = 1;
        }

        EEPROM.put(0, error);
        EEPROM.update(sizeof(int), state);

        delay(500);
    }
    else
    {
        if (!myservo.attached())
        {
            myservo.attach(10);
        }

        val1 = analogRead(sensor1);
        val2 = analogRead(sensor2);

        EEPROM.get(0, error);
        state = EEPROM.read(sizeof(int));

        // Apply calibration correction
        if (state == 0)
        {
            val1 -= error;
        }
        else
        {
            val2 -= error;
        }

        // Tracking logic
        if (val1 > val2 + threshold)
        {
            pos--;
        }
        else if (val2 > val1 + threshold)
        {
            pos++;
        }

        // Limit servo movement
        pos = constrain(pos, 0, 180);

        myservo.write(pos);

        delay(20);
    }
}