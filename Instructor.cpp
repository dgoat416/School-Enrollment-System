#include "Instructor.h"


Instructor::Instructor()
{
	numOfCoursesTaught = 1;

	name = "Mr. M";

	 status = "Tenured";

	 courses = new Course[numOfCoursesTaught];
}

Instructor::Instructor(string _name, string _status, int _num, Course * _crs)
{
	name = _name;
	status = _status;

	if (_num == 0)
		_num++;

	numOfCoursesTaught = _num;
	courses = new Course[_num];
//	*courses = *_crs;

	for (int i = 0; i < _num; i++)
		courses[i] = _crs[i];
}

Instructor::Instructor(const Instructor & i)
{
	name = i.name;
	status = i.status;
	
	if (numOfCoursesTaught != 0)
	{
		numOfCoursesTaught = i.numOfCoursesTaught;
		courses = new Course[numOfCoursesTaught];
	}

	else if (numOfCoursesTaught == 0)
	{
		numOfCoursesTaught = i.numOfCoursesTaught +1;
		courses = new Course[numOfCoursesTaught];
	}

	*courses = *i.courses;
}

Instructor::~Instructor()
{
	courses = nullptr;
	delete[] courses;
}

Course * Instructor::getCourse() const
{
	return courses;
}

int Instructor::getNumberOfCoursesTaught() const
{
	return numOfCoursesTaught;
}

string Instructor::getName() const
{
	return name;
}

string Instructor::getStatus() const
{
	return status;
}

string Instructor::getStudentStatus(const Student & s, const Course & c) const
{
	// find the  course "c" in the instructor's course list
	// find the student in that course
	// return the student's status in that course

	// temp holds the list of students in the instructor's course
	Student* temp = courses->getStudent();

	for (int i = 0; i < numOfCoursesTaught; i++)
	{
		if ( courses[i].getCourseNumber() == c.getCourseNumber())
		{
			for (int j = 0; j < courses[i].getNumberOfEnrollment(); j++)
			{
				if (temp[j].getId() == s.getId() )
					return s.getStatus();
			}
		}
	}
	
	return "FAIL";
}

int Instructor::addStudent(const Student & s, Course & c)
{
	// find course "c" in instructor's list of courses
	// search for student in the students pointer from course
	// return the expected values

	for (int i = 0; i < numOfCoursesTaught; i++)
	{
		if (courses[i].getCourseNumber() == c.getCourseNumber())
		{

			// temp holds the students in all the courses
			Student* temp = courses[i].getStudent();

			// check if student already in the class
			for (int j = 0; j < courses[i].getNumberOfEnrollment(); j++)
			{
				if (temp[j].getId() == s.getId()) // student already in the class
				{
					temp = nullptr;
					delete[] temp;
					return -1;
				}
			}

			// add student to course:
			if (temp[0].getStatus() != "OTIS") // if not blank object
			{
				// increment number of enrollment
				int newSize = courses[i].getNumberOfEnrollment() + 1;
				courses[i].setNumberOfEnrollment(newSize);
				Student* newRoster = new Student[newSize];
				Student newStudent = s;

				// enrolled or added
				if (s.getTimeOfAction().compareTime(courses[i].getTimeLastDateToEnroll()) == -1
					|| s.getTimeOfAction().compareTime(courses[i].getTimeLastDateToEnroll()) == 0)
					newStudent.setStatus("Enrolled");
				else
					if (s.getTimeOfAction().compareTime(courses[i].getTimeLastDateToEnroll()) == 1)
						newStudent.setStatus("Added");


				// add student to the array students in course use setRoster
				// assign temp to new roster and add student to the last spot
				for (int k = 0; k < newSize; k++)
				{
					if (k == newSize - 1)
					{
						newRoster[k] = newStudent;
						break;
					}

					else
						newRoster[k] = temp[k];
				}

				courses[i].setRoster(newRoster);

				newRoster = nullptr;
				delete[] newRoster;

				temp = nullptr;
				delete[] temp;


				if (newStudent.getStatus() == "Enrolled")
				{
					updateRawData(newStudent, courses[i]);
					formattedData(newStudent, courses[i]);
					return 0;
				}

				else if (newStudent.getStatus() == "Added")
				{
					updateRawData(newStudent, courses[i]);
					formattedData(newStudent, courses[i]);
					return 1;
				}
			}

			else // the first student in the array needs to be overwritten bc it is an empty object
			{
				Student newStudent = s;

				// enrolled or added
				if (s.getTimeOfAction().compareTime(courses[i].getTimeLastDateToEnroll()) == -1
					|| s.getTimeOfAction().compareTime(courses[i].getTimeLastDateToEnroll()) == 0)
					newStudent.setStatus("Enrolled");
				else
					if (s.getTimeOfAction().compareTime(courses[i].getTimeLastDateToEnroll()) == 1)
						newStudent.setStatus("Added");

				// set first array position to newStudent (s) after updating status
				temp[0] = newStudent;
				courses[i].setRoster(temp);


				temp = nullptr;
				delete[] temp;

				if (newStudent.getStatus() == "Enrolled")
				{
					updateRawData(newStudent, courses[i]);
					formattedData(newStudent, courses[i]);
					return 0;
				}

				else if (newStudent.getStatus() == "Added")
				{
					updateRawData(newStudent, courses[i]);
					formattedData(newStudent, courses[i]);
					return 1;
				}
			}
		}

	}

}

int Instructor::dropStudent(const Student & s, Course & c, Time t)
{
	// find student in the course
	// change their status to dropped
	// set time of action to t
	// return expected values
	for (int j = 0; j < numOfCoursesTaught; j++)
	{
		// if courses match
		if (c.getCourseNumber() == courses[j].getCourseNumber())
		{
			Student* temp = courses[j].getStudent();

			// attempt to find student in the class
			for (int i = 0; i < courses[j].getNumberOfEnrollment(); i++)
			{
				if (s.getId() == temp[i].getId()
					&& s.getStatus() != "Dropped") // add if not = dropped so return 1 only if currently dropping
				{
					// drop student by changing the status of the student
					// dont drop student from roster which means don't 
					// change enrollment either

					temp[i].setTimeOfAction(t);
					temp[i].setStatus("Dropped");
					courses[j].setRoster(temp);
					temp = nullptr;
					delete[] temp;
					updateRawData(s, courses[j]);
					return 1;

				}
			
			}

			temp = nullptr;
			delete[] temp;
			return 0;
		}

	}


	return 0; // INSERT
}

int Instructor::findStudent(const Student & s, const Course & c)
{
	int numOfStudents = c.getNumberOfEnrollment();
	Student* temp = new Student[numOfStudents];

	for (int i = 0; i < numOfStudents; i++)
	{
		temp[i] = c.getStudent()[i];
	}

	// find student in the course 
	for (int j = 0; j < getNumberOfCoursesTaught(); j++)
	{
		// if courses match
		if (c.getCourseNumber() == courses[j].getCourseNumber())
		{
			// attempt to find student in the class
			for (int i = 0; i < courses[j].getNumberOfEnrollment(); i++)
			{
				if (s.getId() == temp[i].getId())
				{
					temp = nullptr;
					delete[] temp;
					return 1; // student found

				}

			}

			temp = nullptr;
			delete[] temp;
			return 0; // student not found
		}
	}


	temp = nullptr;
	delete[] temp;
	return 0; // student not found
}

void Instructor::updateRawData(const Student& s, const Course& c)
{
	ofstream outFile;
	ifstream inFile("raw_data_courseNumber.txt");
	
	if (outFile.is_open() == false)
	{
		// open the file in append mode so that it doesn't overwrite contents
		outFile.open("raw_data_courseNumber.txt", ios::app); 

		// courses
		// find c in courses because c hasn't been updated so find the updated
		// version of c in courses and store in cTemp
		Course cTemp;

		for (int i = 0; i < numOfCoursesTaught; i++)
		{
			if (courses[i].getCourseNumber() == c.getCourseNumber())
			{
				cTemp = courses[i];
				break;
			}
		}

		// students
		Student* temp = cTemp.getStudent();
		Student sTemp;

		// search for student in course and use that student
		for (int i = 0; i < cTemp.getNumberOfEnrollment(); i++)
		{
			if (temp[i].getId() == s.getId())
			{
				sTemp = temp[i];
				break;
			}

		}

		// SETUP IDDDDDDDDDDDD
		char id[10];
		memset(id, '\0', 10); // 9 chars and last char is null char
		string sID = sTemp.getId();

		for (int i = 0; i < sID.size(); i++)
			id[i] = sID[i];


		// SETUP NAMEEEEEEEEEEEEE
		string name = sTemp.getName();
		char first[16]; // 15 chars and last char is null char
		memset(first, '\0', 16);
		char last[16]; // 15 chars and last char is null char
		memset(last, '\0', 16);
		bool firstName = true;
		int j = 0;

		for (int i = 0; i < name.size(); i++)
		{
			if (name[i] != ' ' && firstName == true && i <= 14)
				first[i] += name[i];

			else if (name[i] == ' ')
			{
				firstName = false;
				continue;
			}

			else if (name[i] != ' ' && firstName == false && j <= 14)
			{
				last[j] += name[i];
				j++;
			}
		}

		// SETUP LEVEL
		string lvl = sTemp.getLevel();
		char level[10]; // 9 chars and last char is null char
		memset(level, '\0', 10);

		for (int i = 0; i < lvl.size(); i++)
			level[i] = lvl[i];


		// SETUP STATUS
		string status = sTemp.getStatus();
		char statuS[9]; // 8 chars and last char is null char
		memset(statuS, '\0', 9);

		for (int i = 0; i < status.size(); i++)
			statuS[i] = status[i];

		string date = sTemp.getDateOfAction();

		if (inFile.peek() != ifstream::traits_type::eof())
			outFile << endl;

		outFile << sID << " " << last << " " << first << " "
			<< level << " " << statuS << " " << date;

		delete[] temp;
	}

	if (outFile.is_open())
	{
		outFile.close();
		inFile.close();
	}

}

void Instructor::formattedData(const Student & s, const Course & c)
{
	//Displaying the Information of a course
	//Also display all students in that course
	Course* temp = courses;
	Course cTemp;
	ofstream outFile;
	ifstream inFile("courseName_courseNumber.txt");
	if (outFile.is_open() == false)
	{
		// open the file in append mode so that it doesn't overwrite contents
		outFile.open("courseName_courseNumber.txt", ios::app);

		for (int i = 0; i < numOfCoursesTaught; i++)
		{
			if (temp[i].getCourseNumber() == c.getCourseNumber())
			{
				cTemp = temp[i];
				break;
			}
		}


				outFile << status << " Instructor: " << name << endl
					 << "Course Number: " << cTemp.getCourseNumber()
					<< "\nCourse: " << cTemp.getCourseName() << endl
					<< "Semester: " << cTemp.getSemester() << " " << cTemp.getYear() << endl
					<< "Enrollment: " << cTemp.getNumberOfEnrollment() << endl
					<< "Maximum Enrollment: " << CAPACITY << endl
					<< "Last Date To Enroll: " << cTemp.getLastDateToEnroll() << endl
					<< left << setw(10) << setfill(' ') << "ID"
					<< left << setw(16) << setfill(' ') << "Last Name"
					<< left << setw(16) << setfill(' ') << "First Name"
					<< left << setw(10) << setfill(' ') << "Level"
					<< left << setw(9) << setfill(' ') << "Status"
					<< left << setw(11) << setfill(' ') << "Date";

				Student* curr = cTemp.getStudent();
				//Student sTemp;

				//// search for student in course and use that student
				//for (int i = 0; i < cTemp.getNumberOfEnrollment(); i++)
				//{
				//	if (curr[i].getId() == s.getId())
				//	{
				//		sTemp = curr[i];
				//		break;
				//	}

				//}


				for (int j = 0; j < cTemp.getNumberOfEnrollment(); j++)
				{
					// SETUP NAMEEEEEEEEEEEEE
					string name = curr[j].getName();
					char first[16]; // 15 chars and last char is null char
					memset(first, '\0', 16);
					char last[16]; // 15 chars and last char is null char
					memset(last, '\0', 16);
					bool firstName = true;
					int k = 0;

					for (int i = 0; i < name.size(); i++)
					{
						if (name[i] != ' ' && firstName == true && i <= 14)
							first[i] += name[i];

						else if (name[i] == ' ')
						{
							firstName = false;
							continue;
						}

						else if (name[i] != ' ' && firstName == false && j <= 14)
						{
							last[k] += name[i];
							k++;
						}
					}

					if (inFile.peek() != ifstream::traits_type::eof())
						outFile << endl;

					outFile << left << setw(10) << setfill(' ') << curr[j].getId()
						<< left << setw(16) << setfill(' ') << last
						<< left << setw(16) << setfill(' ') << first
						<< left << setw(10) << setfill(' ') << curr[j].getLevel()
						<< left << setw(9) << setfill(' ') << curr[j].getStatus()
						<< left << setw(11) << setfill(' ') << curr[j].getFormattedDate();
				}

				outFile << endl << "---------------------------------------------------------------------" << endl;	


	}

	if (outFile.is_open())
	{
		outFile.close();
		inFile.close();
	}

}

int Instructor::addCourse(const Course & c)
{

	if (numOfCoursesTaught >= MAXCOURSE)
		return 0; //can't add anymore classes

	for (int i = 0; i < numOfCoursesTaught; i++)
	{
		if (courses[i].getCourseNumber() == c.getCourseNumber())
		{
			return -1; // course already exists
		}
	}

	if (courses[0].getSemester() != "GRADUATION")
	{
		Course* temp = new Course[++numOfCoursesTaught];

		for (int i = 0; i < numOfCoursesTaught; i++)
		{
			if (i == numOfCoursesTaught - 1)
				temp[i] = c;

			else
				temp[i] = courses[i];
		}

		courses = new Course[numOfCoursesTaught];

		for (int i = 0; i < numOfCoursesTaught; i++)
			courses[i] = temp[i];

		temp = nullptr;
		delete[] temp;
		return 1; // class could be added
	}
	else // the first course in array should b overriden because it is a blank obj
	{
		courses[0] = c;
		return 1; // the class could be added
	}
}

int Instructor::findCourse(const Course & c)
{
	for (int i = 0; i < numOfCoursesTaught; i++)
	{
		if (courses[i].getCourseNumber() == c.getCourseNumber())
			return 1; // found
	}

	return 0; // not found
}
