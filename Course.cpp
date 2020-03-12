#include "Course.h"

Course::Course()
{
	numOfEnrolled = 1;

	courseNumber = "1234";

	courseName = "DGOAT'S CLASS";

	 semester = "GRADUATION";

	 Time myTime;
	 last_date_to_enroll = myTime;
	
	 students = new Student[numOfEnrolled];
}

Course::Course(string num, string name, string sem, Time last_date, Student * stdts, int numOfEnroll)
{
	courseNumber = num;
	courseName = name;
	semester = sem;
	last_date_to_enroll = last_date;

	if (numOfEnroll != 0)
	{
		numOfEnrolled = numOfEnroll;
		students = nullptr;
		delete[] students;
		students = new Student[numOfEnrolled];
	}

	else if (numOfEnroll == 0)
	{
		numOfEnrolled = numOfEnroll + 1;
		students = nullptr;
		delete[] students;
		students = new Student[numOfEnrolled];
	}

	for (int i = 0; i < numOfEnrolled; i++)
		students[i] = stdts[i];
	
	
}

Course::~Course()
{
	students = nullptr;
	delete[] students;
}

Course::Course(const Course & c)
{
	courseName = c.courseName;
	courseNumber = c.courseNumber;
	semester = c.semester;
	last_date_to_enroll = c.last_date_to_enroll;

	if (c.numOfEnrolled != 0)
	{
		numOfEnrolled = c.numOfEnrolled;
		students = nullptr;
		delete[] students;
		students = new Student[numOfEnrolled];
	}
	else if (c.numOfEnrolled == 0)
	{
		numOfEnrolled = c.numOfEnrolled + 1;
		students = nullptr;
		delete[] students;
		students = new Student[numOfEnrolled];
	}

	for (int i = 0; i < numOfEnrolled; i++)
		students[i] = c.students[i];
	//*students = *c.students;
}

Course& Course::operator=(const Course & c)
{
	courseName = c.courseName;
	courseNumber = c.courseNumber;
	semester = c.semester;
	last_date_to_enroll = c.last_date_to_enroll;

	if (c.numOfEnrolled != 0)
	{
		numOfEnrolled = c.numOfEnrolled;
		students = nullptr;
		delete[] students;
		students = new Student[numOfEnrolled];
	}
	else if (c.numOfEnrolled == 0)
	{
		numOfEnrolled = c.numOfEnrolled + 1;
		students = nullptr;
		delete[] students;
		students = new Student[numOfEnrolled];
	}

	for (int i = 0; i < numOfEnrolled; i++)
		students[i] = c.students[i];
	//*students = *c.students;

	return *this;
}

Student* Course::getStudent() const
{
	return students;
}

string Course::getCourseNumber() const
{
	return courseNumber;
}

string Course::getCourseName() const
{
	return courseName;
}

string Course::getSemester() const
{
	return semester;
}

string Course::getYear() const
{
	return last_date_to_enroll.getYear();
}

int Course::getNumberOfEnrollment() const
{
	return numOfEnrolled;
}

string Course::getLastDateToEnroll() const
{
	return last_date_to_enroll.toString();
}

Time Course::getTimeLastDateToEnroll() const
{
	return last_date_to_enroll;
}

void Course::setNumberOfEnrollment(int ne)
{
	numOfEnrolled = ne;
}

void Course::setRoster(Student * stdts)
{
	students = new Student[numOfEnrolled];
	// previously just without above and without loop
	if (stdts != nullptr)
		for (int i = 0; i < numOfEnrolled; i++)
			students[i] = stdts[i];


	// switch the first objects and increment by the number of enrollment
	//to get each individual student therefore precondition is that the
	// set enrollment is called and set to number of elements in stdts
	// talk to professor about precondition etc

	
}





