/*
Name: Deron Washington II
Class: CECS 282
Instructor: Minhthong Nguyen
Purpose of the program: Represent school enrollment
Last updated: October 11th, 2019
*/

#include <iostream>	// i/o
#include <fstream>	// file i/o
#include "Time.h"
#include "Student.h"
#include "Course.h"
#include "Instructor.h"
#include <string>
#include <array>
#include <vector>
#include <time.h>
#include <algorithm>
#include <iomanip>

const int MAXCOURSE = 3;
const int CAPACITY = 35;

using namespace std;

void clearFile()
{
	ofstream outFile;
	
	if (outFile.is_open() == false)
		outFile.open("raw_data_courseNumber.txt");

	outFile.clear();
	outFile.close();

	ofstream outFile2;
	if (outFile2.is_open() == false)
		outFile2.open("courseName_courseNumber.txt");

	outFile2.clear();
	outFile2.close();
}

void main()
{
	clearFile();
		time_t secs = time(0);//This is the current time (GMT +0)
		Time last_date(secs - 10000);//Set up the last date of enrollment

		Student* students = new Student[CAPACITY];//Set up the student dynamic array with CAPACITY. The CAPACITY for this test is 2.
		//Create 4 students
		Student s("123456789", "Kobe Bryant", "Senior", 0);
		Student s1("987654321", "Lebron James", "Sophomore", 1000);
		Student s2("123654987", "James Harden","Senior", secs - 10);
		Student s3("345698712", "Anthony Davis", "Sophomore", 1007770);

		Course* courses = new Course[MAXCOURSE];//Set up the courses dynamic array with MAXCOURSE. The MAXCOURSE for this test is 3
		//Create 3 courses;
		Course c("1456", "CECS228", "Fall", last_date, students, 0);
		Course c1("1345", "CECS228", "Fall", last_date, students, 0);
		Course c2("1234", "CECS282", "Fall", last_date, students, 0);
		Course c3("1233", "CECS282", "Fall", last_date, students, 0);

		//Create an instructor
		Instructor inst("Minhthong Nguyen", "Part-time", 0, courses);

		//Comment out line(s) or combination of lines below and observe the effect of add and drop.
		/*for instance, with line "inst.addCourse(c)" activated, the output is
			Part-time Instructor: Minhthong Nguyen
			Course Number: 1456
			Course Name: CECS228
			Semester: Fall 2019
			Last Date To Enroll: Thu Sep 26 12:19:11 2019
			Number of enrollment: 0
			Maximum Enrollment: 2
		*/
		//Add courses
		inst.addCourse(c);
		inst.addCourse(c1);
		inst.addCourse(c2);
		inst.addCourse(c2);//Add the same course again should have no effect on the course that an instructor teaches.

		//Add students to the courses
		inst.addStudent(s, c);
		inst.addStudent(s2, c);
		inst.addStudent(s3, c);
		inst.addStudent(s1, c);
		inst.addStudent(s1, c);//Add the same student again to the same class should have no effect.

		inst.addStudent(s, c2);
		inst.addStudent(s2, c2);
		inst.addStudent(s3, c2);

		inst.addStudent(s1, c1);
		inst.addStudent(s, c1);
		inst.addStudent(s2, c1);
		inst.addStudent(s1, c1); // should return -1

		//Add student to a non-existing course should have no effect, and the number of enrollment of that course should not increase.
		inst.addStudent(s, c3);
		//cout << "Enrollment: " << c3.getNumberOfEnrollment() << endl;

		//Drop students from the courses
		inst.dropStudent(s2, c, secs);
		inst.dropStudent(s1, c1, secs);
		inst.dropStudent(s, c2, secs);
		inst.dropStudent(s2, c2, secs);

		//Drop student from a non-existing course should have no effect
		inst.dropStudent(s, c3, secs);

		//Displaying the Information of a course
		//Also display all students in that course
		Course* temp = inst.getCourse();
		for (int i = 0; i < inst.getNumberOfCoursesTaught(); i++)
		{
			cout << inst.getStatus() << " Instructor: " << inst.getName() << endl;
			cout << "Course Number: " << temp[i].getCourseNumber() << "\nCourse Name: " << temp[i].getCourseName() << "\n" << "Semester: " << temp[i].getSemester() << " " << temp[i].getYear() << "\n" << "Last Date To Enroll: " << temp[i].getLastDateToEnroll() << "\nNumber of enrollment: " << temp[i].getNumberOfEnrollment() << "\nMaximum Enrollment: " << CAPACITY << endl;
			Student* tmp = temp[i].getStudent();
			for (int j = 0; j < temp[i].getNumberOfEnrollment(); j++)
			{
				cout << tmp[j].getId() << " " << tmp[j].getName() << " " << tmp[j].getLevel() << " " << tmp[j].getStatus() << " " << tmp[j].getDateOfAction() << endl;
			}
			cout << "---------------------------------------------------------------------" << endl;
		}
	//// testing for time and CTIME classes
	//Time myTime;
	//
	//// testing for instructor class
	//Student yeeet("444444", "yeeet", "sEnIoR4", "aDdEd", myTime);
	//Student Otis("555555", "Otis", "juNioR416", "ENROLLED", myTime);
	//Student Jswish("454545", "JSwish", "sEnIoR4", "DRoPpEd", myTime);
	//Student Octeye("585858", "Octeye", "juNioR416", "eNRoLLeD", myTime);
	//Student Lbj("777777", "Lbj", "fReShIe", "aDdeD", myTime);
	//Student* myClass = new Student[2];
	//myClass[0] = yeeet;
	//myClass[1] = Otis;
	//Student* yourClass = new Student[3];
	//yourClass[0] = Jswish;
	//yourClass[1] = Octeye;
	//yourClass[2] = Lbj;
	//Course Class1;
	//Course Class2;
	//Class1.setNumberOfEnrollment(2);
	//Class2.setNumberOfEnrollment(3);
	//Class1.setRoster(myClass);
	//Class2.setRoster(yourClass);
	//Course* course = new Course[2];
	//course[0] = Class1;
	//course[1] = Class2;

	//cout << "Array: \n";
	//cout << myClass[0].getName() << myClass[0].getId() << endl;
	//cout << myClass[1].getName() << myClass[1].getId() << endl;
	//cout << "Incrementing Pointer	\n";
	//cout << myClass->getName() << myClass->getId();
	//myClass++;
	//cout << myClass->getName() << myClass->getId();

	//Instructor myGuy("MyGuy", "Tenured", 2, course);

	//for (int i = 0; i < 2; i++)
	//{
	//	cout << "\n\n\n";
	//	cout << "Starting Enrollment: " << myGuy.getCourse()[i].getNumberOfEnrollment();
	//	// has this student should return -1 
	//	cout << "\nShould return -1: " << myGuy.addStudent(yeeet, course[i]); 
	//	// find student should return 1 cuz student is in the class
	//	cout << "Find student should return 1: " << myGuy.findStudent(yeeet, course[i]);
	//	// should have same enrollment as starting
	//	cout << "\nShould be same as starting: "<< myGuy.getCourse()[i].getNumberOfEnrollment();
	//	// should be able to add so return 1 or 0
	//	cout << "\nShould return 1 or 0 depending on time: " << myGuy.addStudent(Lbj, course[i]); 
	//	// enrollment should be 1 greater
	//	cout << "\nShould be 1 person greater than starting: "<< myGuy.getCourse()[i].getNumberOfEnrollment();
	//	// drop student should return 1
	//	cout << "\nShould return 1: " << myGuy.dropStudent(Lbj, course[i], myTime);
	//	// enrollment should decrease by 1
	//	cout << "\nShould be same as starting: " << myGuy.getCourse()[i].getNumberOfEnrollment();
	//	// drop student should return 1
	//	cout << "\nShould return 1: " << myGuy.dropStudent(yeeet, course[i], myTime);
	//	// find student should return 0 already deleted
	//	cout << "Find student should return 0: " << myGuy.findStudent(yeeet, course[i]);
	//	// enrollment should be same as starting
	//	cout << "\nShould be same as starting: "<< myGuy.getCourse()[i].getNumberOfEnrollment();
	//}

	//delete[] myClass;
	printf("\n\n");
	system("pause");
}