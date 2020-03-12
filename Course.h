#pragma once

#ifndef H_COURSE
#define H_COURSE

#include "Student.h"


class Course
{
public:
	// CONSTRUCTORS, DESTRUCTORS, & OPERATOR OVERLOAD
	//_______________________________________________________
	/*
	Default Constructor to initialize
	all private member variables 
	*/
	Course();

	/*
	Parameterized Constructor to intialize all private 
	member variables to the values of the parameters
	@params
	- num = course number
	- name = course name
	- sem = the semester
	- last_date = last date to enroll in the class
	- stdts = pointer to a Student class object
	- numOfEnroll = number of students enrolled
	*/
	Course(string num, string name,
		string sem, Time last_date, Student*
		stdts, int numOfEnroll);

	/*
	Destructor to deallocate the memory allocated
	by *students 
	*/
	~Course();

	/*
	Copy Constructor to create a deep copy 
	of a Course object (c) and store in *this
	@param c = the object to be copied
	(which is on the right side of the =)
	Ex. Course c2 = c1; means c = c1
	*/
	Course(const Course& c);

	/*
	The = operator overload function to create
	a deep copy of c and store in *this
	@param c = the object to be copied
	(which is on the right side of the =)
	Ex. c2 = c1; means c is c1
	*/
	Course& operator=(const Course& c);
	
	// GETTERS, SETTERS, AND DISPLAY FUNCTIONS
	//______________________________________________________

	/*
	Function to get the Student object
	@return students member variable 
	*/
	Student* getStudent() const;

	/*
	Function to get the course number 
	@return courseNumber
	*/
	string getCourseNumber() const;

	/*
	Function to return the course name
	@return courseName
	*/
	string getCourseName() const;

	/*
	Function to return the semester
	@return semester
	*/
	string getSemester() const;

	/*
	Function to return the year of the semester
	(assumed to be the year of the last date to enroll)
	@return year (YYYY)
	*/
	string getYear() const; 

	/*
	Function to return the number of enrolled students
	in the course
	@return numOfEnrolled
	*/
	int getNumberOfEnrollment() const;

	/*
	Function to return the last date to enroll 
	@return last_date_to_enroll
	in format Www Mmm dd hh:mm:ss yyyy
	*/
	string getLastDateToEnroll() const;  

	/*
	Function to return the last date to enroll as a 
	Time object 
	@return last_date_to_enroll in seconds
	*/
	Time getTimeLastDateToEnroll() const; 

	/*
	Function to set the number of enrolled students
	@param ne = number of students enrolled 
	POSTCONDITON: numOfEnrolled = ne;
	*/
	void setNumberOfEnrollment(int ne);


	/*
	Function to set the roster of students using the 
	pointer to the Students object 
	@param stdts = pointer to a Students class object
	POSTCONDITON: students = stdts;
	*/
	void setRoster(Student* stdts);

private:

	/*number of students enrolled */
	int numOfEnrolled;		

	/* four-digit integer */
	string courseNumber;

	/* name of the course */
	string courseName;

	/* Fall, Winter, Spring, Summer */
	string semester;

	/* time in secs */
	Time last_date_to_enroll;

	/* pointer to array of students */
	Student* students;
};

#endif
