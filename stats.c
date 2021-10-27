#include "stats.h"
#include <math.h>

struct Stats compute_statistics(const float* numberset, int setlength) 
{
    struct Stats s;
	float sum = 0.0, min = numberset[0], max = numberset[0];
	int i;
	if(setlength != 0)
    {
		for(i = 0; i < setlength; i++)
        {
			sum += numberset[i];
			if (numberset[i] > max)
            {
				max =  numberset[i];
			}
			if (numberset[i] < min)
            {
				min = numberset[i];
			}
    	s.average = (sum/setlength);
	    s.min = min;
    	s.max = max;
		}
	}
    else
    {
	    s.average = NAN;
    	s.min = NAN;
	    s.max = NAN;
	}
	return s;
}

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats){
	if(computedStats.max >  maxThreshold){
		alerters[0]();
		alerters[1]();
	}
}


