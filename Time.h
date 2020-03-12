#pragma once

#ifndef H_TIME
#define H_TIME


#include "CTIME.h"

using namespace std;

class Time
{

public:
	// CONSTRUCTORS AND DESTRUCTORS
	//___________________________________________________________
	/*
	Default Constuctor to initialize private member
	variable "secs"
	*/
	Time();
	
	/*
	Parameterized Constructor to initialize the private member
	variable "secs"
	@param t is the value to initialize the private member to
	*/
	Time(time_t t);

	/*
	Copy Constructor to create a deep copy
	of a Time object (t) and store in *this
	@param t = the object to be copied
	(which will be on the right of =)
	Ex. Time t1 = t2; means t = t2
	*/
	Time(const Time& t);


	// GETTERS, SETTERS, AND DISPLAY FUNCTIONS
	//______________________________________________________
	/*
	Function to display the Time object as a String
	@return time in the following format 
	Www Mmm dd hh : mm:ss yyyy
	*/
	string toString() const; 

	/*
	Function to display the date
	@return time in the format MM / DD / YYYY
	*/
	string getMMDDYYYY() const;

	/*
	Function to display the year 
	@return year of time
	*/
	string getYear() const;

	/*
	Function to compare to Time objects
	@return the result of the evaluation
	t1.compareTime(t2) which performs (t1 == t2);
	-1 if less than      (t1 < t2)
	0 if equal			 (t1 = t2)
	1 if greater than  (t1 > t2)
	*/
	int compareTime(const Time& t);

private:

	/* Represents time in seconds
	if secs = 0, it represents Jan 1st, 1970 
	*/
	time_t secs; 
};

#endif