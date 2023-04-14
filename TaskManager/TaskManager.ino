#include <TaskManager.h>

const int pins[] = {3, 5, 6, 9, 10, 11};
int states[] = {LOW, LOW, LOW, LOW, LOW, LOW};
unsigned long prevTime[] = {0, 0, 0, 0, 0, 0};
const long intervals[] = {30, 500, 6000, 10000, 50000, 100000};

void setup()
{
    for (int i = 0; i < 6; ++i)
    {
        pinMode(pins[i], OUTPUT);
	      taskManager.scheduleFixedRate(intervals[i], [i]()
	      {
		        states[i] = (states[i] == LOW) ? HIGH : LOW;
		        digitalWrite(pins[i], states[i]);
	      }, TIME_MICROS);
    }
}

void loop()
{
    taskManager.runLoop();
}