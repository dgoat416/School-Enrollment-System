#include "Student.h"



Student::Student()
{
	level = "Freshman";
	id = "000000000";
	name = "DGOAT WASHINGTON II";
	status = "OTIS";

	Time myTime(date_of_action);
}

Student::Student(string _id, string _name, string _level, Time __date_of_action)
{
	id = _id;
	name = _name;
	level = _level;
	date_of_action = __date_of_action;

	// INSERT determine status by the add date vs the date that ends enrollment 
}

Student::Student(const Student & s)
{
	level = s.level;
	id = s.id;
	name = s.name;
	date_of_action = s.date_of_action;
}

Student& Student::operator=(const Student & s)
{
	s.getId();
	level = s.level;
	id = s.id;
	name = s.name;
	status = s.status;
	date_of_action = s.date_of_action;

	return *this;
}

bool Student::operator!=(const Student & s)
{
	if (this->id == s.id
		&& this->level == s.level
		&& this->date_of_action.getMMDDYYYY() == s.date_of_action.getMMDDYYYY()
		&& this->name == s.name
		&& this->status == s.status)
	{
		return false;
	}
	
	else
	return true;
}

string Student::getLevel() const
{
	return level;
}

string Student::getId() const
{
	return id;
}

string Student::getName() const
{
	return name;
}

string Student::getDateOfAction() const
{
	return date_of_action.toString();
}

string Student::getFormattedDate() const
{
	return date_of_action.getMMDDYYYY();
}

Time Student::getTimeOfAction() const
{
	return date_of_action;
}

string Student::getStatus() const
{
	return status;
}

void Student::setStatus(string stat)
{
	status = stat;
}

void Student::setTimeOfAction(Time act)
{
	date_of_action = act;
}



