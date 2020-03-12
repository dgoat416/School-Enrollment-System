#include "Time.h"


Time::Time()
{
	secs = time(NULL);
}

Time::Time(time_t t)
{
	secs = t;
}

Time::Time(const Time& t)
{
	Time copy(t.secs);
	*this = copy;
}

string Time::toString() const
{
	cTime myTime(secs);
	return myTime.c_Time();
	
}

string Time::getMMDDYYYY() const
{
	cTime myTime(secs);

	return myTime.dateFormat();

}

string Time::getYear() const
{
	cTime myTime(secs);

	return myTime.currentYear();
}

int Time::compareTime(const Time & t)
{
	if (secs == t.secs)
		return 0;
	else if (secs < t.secs)
		return -1;
	else if (secs > t.secs)
		return 1;
	return 0;
}







