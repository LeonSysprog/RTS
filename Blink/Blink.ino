const int pins[] = {3, 5, 6, 9, 10, 11};
int states[] = {LOW, LOW, LOW, LOW, LOW, LOW};
unsigned long currentTime;
unsigned long prevTime[] = {0, 0, 0, 0, 0, 0};
const long intervals[] = {30, 500, 6000, 10000, 50000, 100000};

void setup()
{
    for (int i = 0; i < 6; ++i)
    {
        pinMode(pin[i], OUTPUT);
    }
}

void loop()
{
    currentTime = micros();
    for (int i = 0; i < 6; ++i)
    {
        if (currentTime - prevTime[i] >= intervals[i])
        {
            prevTime[i] = currentTime;
        }

        states[i] = (states[i] == LOW) ? HIGH : LOW;
        digitalWrite(pins[i], states[i]);
    }
}