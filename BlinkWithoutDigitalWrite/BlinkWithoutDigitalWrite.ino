const int pins[] = {3, 5, 6, 9, 10, 11};
int states[] = {LOW, LOW, LOW, LOW, LOW, LOW};
unsigned long currentTime;
unsigned long prevTime[] = {0, 0, 0, 0, 0, 0};
const long intervals[] = {30, 500, 6000, 10000, 50000, 100000};

void setup()
{
    DDRD = B01101000;
    DDRB = B00001110;
}

void loop()
{
    for (int i = 0; i < 6; ++i)
    {
        currentTime = micros();
        if (currentTime - prevTime[i] >= intervals[i])
        {
            prevTime[i] = currentTime;
            states[i] = (states[i] == LOW) ? HIGH : LOW;
            if (states[i]) 
            {
                switch(pins[i]) 
                {
                    case 3:
                        PORTD |= B00001000;
                        break;
                    case 5:
                        PORTD |= B00100000;
                        break;
                    case 6:
                        PORTD |= B01000000;
                        break;
                    case 9:
                        PORTB |= B00000010;
                        break;
                    case 10:
                        PORTB |= B00000100;
                        break;
                    case 11:
                        PORTB |= B00001000;
                        break;
                }
            }
            else
            {
                switch(pins[i]) 
                {
                    case 3:
                        PORTD &= ~B00001000;
                        break;
                    case 5:
                        PORTD &= ~B00100000;
                        break;
                    case 6:
                        PORTD &= ~B01000000;
                        break;
                    case 9:
                        PORTB &= ~B00000010;
                        break;
                    case 10:
                        PORTB &= ~B00000100;
                        break;
                    case 11:
                        PORTB &= ~B00001000;
                        break;
                }
            }
    }
}