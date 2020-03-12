#include "CTIME.h"



cTime::cTime()
{
	daysPerYear = "365.25";
	dayOfWeek = "SUN";
	month = "0";
	day = "0";
	hours = "0";
	min = "0";
	sec = "0";
	year = "0000";

}

cTime::cTime(time_t _seconds)
{
	int dayOfWeekInt = 0;
	int portionOfYr = 0;

	daysPerYear = intToString(365.25);
	double cFactor = 60 * 60 * 24 * 365.25;  // conversion factor (assume nonleap yr)
	double years = (_seconds / cFactor) + 1970;
	double rDays = (365.25) * (years - static_cast<int>(years));

	// if it is a leap year
	if (static_cast<int>(years) % 4 == 0)
	{
		if (static_cast<int>(years) % 100 != 0)
		{
			daysPerYear = intToString(366);
			cFactor = 60 * 60 * 24 * 366;
			years = (_seconds / cFactor) + 1970;
			rDays = (366) * (years - static_cast<int>(years));
		}
	}


	double rHours = ((24) * (rDays - static_cast<int>(rDays)) - 1);
	double rMins = (60) * (rHours - static_cast<int>(rHours));
	double rSeconds = (60) * (rMins - static_cast<int>(rMins));

	int p = static_cast<int>(rDays);

	// process number of days for output 
	year = intToString(years);
	sec = intToString(rSeconds);
	min = intToString(rMins);
	hours = intToString(rHours);
	month = getDayAndMonthOfYr(p, years); //
	day = intToString(p);
	dayOfWeek = currentDayOfWeek(rDays, static_cast<int>(years + 1970));

	while (hours.length() != 2)
	if (hours.length() != 2)
	{
		string str = "0" + hours;
		hours = str;
	}

	while (min.length() != 2)
	if (min.length() != 2)
	{
		string str = "0" + min;
		min = str;
	}

	while (sec.length() != 2)
	if (sec.length() != 2)
	{
		string str = "0" + sec;
		sec = str;
	}
}

string cTime::c_Time()
{
	{
		return dayOfWeek + " "
			+ month + " "
			+ day + " "
			+ hours + ":"
			+ min + ":"
			+ sec + " "
			+ year;
	}
}

string cTime::dateFormat()
{
	string Month = "";
	
	if (month == "Jan")
		Month = "01";

	else if(month == "Feb")
		Month = "02";

	else if(month == "Mar")
		Month = "03";

	else if (month == "Apr")
		Month = "04";

	else if (month == "May")
		Month = "05";

	else if (month == "Jun")
		Month = "06";

	else if (month == "Jul")
		Month = "07";

	else if (month == "Aug")
		Month = "08";

	else if (month == "Sep")
		Month = "09";

	else if (month == "Oct")
		Month = "10";

	else if (month == "Nov")
		Month = "11";

	else if (month ==  "Dec")
		Month = "12";
		
	if (day.length() < 2)
		day = "0" + day;

	return Month + "/" + day + "/" + year;
}

string cTime::currentYear()
{
	return year;
}



