#include "stats.h"

int emailAlertCallCount=0;
int ledAlertCallCount=0;

void emailAlerter()
{
    emailAlertCallCount++;
}

void ledAlerter()
{
   ledAlertCallCount++;
}
