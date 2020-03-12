#pragma once

#ifndef H_INSTRUCTOR
#define H_INSTRUCTOR

#include <string>
#include <fstream>
#include <iomanip>
#include "Course.h"
#include "Student.h"	


class Instructor
{
public:
	// CONSTRUCTORS AND DESTRUCTORS
	//___________________________________________________________
	
	/*
	Default Constructor to initialize all private member
	variables and allocate memory for *courses
	*/
	Instructor();

	/*
	Parameterized Construcor to intialize all private member 
	variables to parameters
	@params 
	- name = name of the Instructor
	- status = status (full time or part time or tenured)
	- crs = courses the teachers teaches
	- num = number of courses the teacher teachers
	*/
	Instructor(string _name, string _status, 
					int _num, Course* _crs);

	/*
	Copy Constructor to create a deep copy of an Instructor
	object and store in *this
	@param i = object to be copied
	(which will be on the right side of the =)
	Ex. Instructor a = b; means b = i
	*/
	Instructor(const Instructor& i);

	/*
	Destructor to deallocate the memory allocated by courses*/
	~Instructor();

	// GETTERS, SETTERS, AND DISPLAY FUNCTIONS
	//______________________________________________________

	/*
	Function to get the courses
	@return *courses
	*/
	Course* getCourse() const;

	/*
	Function to get the number of courses the teacher
	teaches
	@return numOfCoursesTaught
	*/
	int getNumberOfCoursesTaught() const;

	/*
	Function to return the name of the Instructor
	@return name
	*/
	string getName() const;

	/*
	Function to return the status of the Instructor
	@return status Part-time or Full-time or Tenured
	*/
	string getStatus() const; 

	/*
	Function to return the status of the student
	@params
	- s = student object that will have it's status returned
	- c = course object that the status of s will be returned for
	@return s.status 
	or Enrolled
	or Added
	or Dropped
	*/
	string getStudentStatus(const Student& s, const Course& c) const; 

	/*
	Function to add a student to the class
	@params
	- s = student object that is attempting to be added
	- c = course that the s is attempting to add
	@return 
	=  -1 if a student already exists in the class
	= 0 if a student has been successfully enrolled in the course
	= 1 if the student has been successfully added to the course
	 (update status to "Added" if after the enrollment date)
	 (update status to "Enrolled" if before or on the enrollment date)
	 (update time of action)	*/
	int addStudent(const Student& s, Course& c); 

	/*
	Function to drop a student from the class 
	@params
	- s = student object that will be dropped 
	- c = course that the s is attempting to drop
	- t = the time object to save the time when s drops
	@return 
	= 0 if student is not on the roster
	= Otherwise, return 1
	(update status to "Dropped")
	(update time of action)
	*/
	int dropStudent(const Student& s, Course& c, Time t); 

	/*
	Function to find a student in a course
	@params
	- s is the student object that is being searched for
	- c is the course object that s is supposedly enrolled/added in
	@return 
	= 0 if a student is not found on the roster
	= Otherwise, return 1.
	*/
	int findStudent(const Student& s,	const Course& c);	

	/*
	Function to format and output "raw_data_courseNumber.txt"
	*/
	void updateRawData(const Student& s, const Course& c);

	/*
	Function to format and output "courseName_courseNumber.txt"
	*/
	void formattedData(const Student& s, const Course& c);

	/*
	Function to add a course to the instructor's list (*courses)
	@param c = the course that is trying to be added
	@return 
	= -1 if course already exists
	= 0 if the numOfCoursesTaught >= MAXCOURSE
	= Otherwise, add the course and return 1.
	*/
	int addCourse(const Course& c); 

	/*
	Function to find a course in the instructor's list (*courses)
	@param c = course that is being searched for
	@return 
	= 0 if a course is not found
	= Otherwise, return 1.
	*/
	int findCourse(const Course& c); 

private:

	/* the number of courses the instructor teaches */
	int numOfCoursesTaught;

	/* Instructor's name formatted as First Last(no middle name) */
	string name; 

	/* Full-time or Part-time or Tenured */
	string status; 

	/* pointer to array of courses that the teacher teaches */
	Course* courses; 
};

#endif

