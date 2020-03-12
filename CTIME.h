#pragma once

#ifndef H_CTIME
#define H_CTIME

#include <ctime>
#include "myFunctions.h"
extern const int MAXCOURSE;
extern const int CAPACITY;

class cTime
{
public:
	
	/*
	Default constructor to initialize 
	private interface
	*/
	cTime();

	/*
	Parameterized constructor to initialize
	private interface
	*/
	cTime(time_t _seconds);

	/*
	Function to display the Time object as a String
	@return time in the following format
	Www Mmm dd hh : mm:ss yyyy
	*/
	string c_Time();

	/*
	Function to display the date
	@return time in the format MM/DD/YYYY
	*/
	string dateFormat();

	/*
	Function to display the year
	@return year of time
	*/
	string currentYear();


private:
	string daysPerYear;
	string dayOfWeek;
	string month;
	string day;
	string hours;
	string min;
	string sec;
	string year;

};

#endif