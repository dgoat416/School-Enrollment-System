#pragma once

#ifndef H_STUDENT
#define H_STUDENT

#include "Time.h"			// my time class 

class Student
{
public:
	// CONSTRUCTORS AND DESTRUCTORS
	//___________________________________________________________
	
	/* 
	Default Constructor to initialize all private member variables
	*/
	Student();

	/*
	Parameterized Constructor to initialize all private member variables
	to the parameters
	@params 
	- id = student ID
	- name = student name
	- level = the year of the student (freshman, sophmore, etc.)
	- status = enrolled, added, or dropped
	- date_of_action= date the student added, dropped, or enrolled
	*/
	Student(string _id, string _name,
	   	        string _level, Time __date_of_action);

	/*
	Copy Constructor to create a deep copy of s
	and store in *this 
	@param
	s = the student object to be copied
	(will be on right side of =)
	Ex. Student a = b; b = s	
	*/
	Student(const Student& s);

	/*
	=Operator Overload to create a deep copy of s
	and store in *this 
	@param s = student object to be copied
	(will be on the right side of the =)
	Ex. a = b; b = s
	*/
	Student& operator=(const Student& s);
	

	/*
	!= Operator Overload to determine if two objects
	are equal or not
	@param s = student object on the right side of !=
	Ex. a != b; b = s
	*/
	bool operator!=(const Student& s);

	// GETTERS, SETTERS, AND DISPLAY FUNCTIONS
	//__________________________________________________________
	
	/*
	Function to return the level of the student
	@return level
	*/
	string getLevel() const;

	/*
	Function to return the ID of the student
	@return id	
	*/
	string getId() const;

	/*
	Function to return the name of the student
	@return name
	*/
	string getName() const;

	/*
	Function to return the date of action of the student
	@return date_of_action
	in the format: Www Mmm dd hh:mm:ss yyyy
	*/
	string getDateOfAction() const;

	/*
	Function to return the date of action of the student
	@return date_of_action
	in the format: MM/dd/yyyy
	*/
	string getFormattedDate() const;

	/*
	Function to return the time of action of the student
	@return _date_of_action in seconds
	*/
	Time getTimeOfAction() const;

	/*
	Function to return the status of the student
	@return status
	*/
	string getStatus() const;

	/*
	Function to set the status of the student
	@param stat = status of the student
	*/
	void setStatus(string stat);

	/*
	Function to set the time of action of the student
	@param act = date of action 
	*/
	void setTimeOfAction(Time act);
	
private:
	/* Freshman, Sophomore,Junior, Senior */
	string level;	

	/* Student ID */
	string id;

	/* Student name formatted as First Last (no middle name) */
	string name;	
	
	/* Added, Enrolled, Dropped */
	string status;

	/* time in secs when enroll, add or drop occurs */
	Time date_of_action;	

};

#endif