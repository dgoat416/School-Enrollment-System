#include "myFunctions.h"

char intToChar(int x)
{
	char y = '\0';
	switch (x)
	{
	case 0:
	{
		y = '0';
		break;
	}
	case 1:
	{
		y = '1';
		break;
	}
	case 2:
	{
		y = '2';
		break;
	}
	case 3:
	{
		y = '3';
		break;
	}
	case 4:
	{
		y = '4';
		break;
	}
	case 5:
	{
		y = '5';
		break;
	}
	case 6:
	{
		y = '6';
		break;
	}
	case 7:
	{
		y = '7';
		break;
	}
	case 8:
	{
		y = '8';
		break;
	}
	case 9:
	{
		y = '9';
		break;
	}
	} // end switch

	return y;
}

string intToString(int x)
{
	string str = "";
	vector<int> digits;
	int temp = x;
	int i = 0;

	// how many digits is in the integer
	while (temp > 0)
	{
		digits.push_back(temp % 10);
		temp /= 10;
		i++;
	}

	for (int j = digits.size() - 1; j >= 0; j--)
	{
		str += intToChar(digits[j]);
	}


	return str;
}

int charToInt(char x)
{
	int y = 0;
	switch (x)
	{
	case '0':
	{
		y = 0;
		break;
	}
	case '1':
	{
		y = 1;
		break;
	}
	case '2':
	{
		y = 2;
		break;
	}
	case '3':
	{
		y = 3;
		break;
	}
	case '4':
	{
		y = 4;
		break;
	}
	case '5':
	{
		y = 5;
		break;
	}
	case '6':
	{
		y = 6;
		break;
	}
	case '7':
	{
		y = 7;
		break;
	}
	case '8':
	{
		y = 8;
		break;
	}
	case '9':
	{
		y = 9;
		break;
	}
	} // end switch

	return y;
}

int stringToInt(string str)
{
	//Integer x(0);
	//Integer temp(0);

	int x = 0;
	int temp = 0;
	int multiplier = str.size() - 1;

	for (int i = 0; i < str.size(); i++)
	{

		//temp.setInteger(charToInt(str[i])* pow(10, multiplier - i));

		temp = charToInt(str[i])* pow(10, multiplier - i);
		x += temp;
	}

	return x;
}

bool isDigit(char c)
{
	if (!(c >= '0' && c <= '9'))// if not number return false
		return false;

	else
		return true;
}

bool isAlpha(char c)
{
	if (!(c >= 'A' && c <= 'Z')
		|| !(c >= 'a' && c <= 'z'))// if not alpha char return false
		return false;

	else
		return true;
}

bool isAlpha(string _word)
{
	for (int i = 0; i < _word.size(); i++)
	{
		if (!(_word[i] >= 'A' && _word[i] <= 'Z')
			|| !(_word[i] >= 'a' && _word[i] <= 'z'))// if not alpha char return false
			return false;
	}

	return true;
}

string onlyAlphaChars(string _word)
{
	string temp = "";
	for (int i = 0; i < _word.size(); i++)
	{
		if ((_word[i] >= 'A' && _word[i] <= 'Z')
			|| (_word[i] >= 'a' && _word[i] <= 'z')
			|| (_word[i] == ' '))				// if not alpha char erase it
			temp += _word[i];
	}

	return temp;
}

string noLeadingWhiteSpace(string str)
{
	string temp = "";
	int first = 0;
	// holds index of first non white space char

		// start adding to temp when you encounter the first non white space char
	for (int j = 0; j < str.length(); j++)
	{
		if (str[j] != 32)
		{
			first = j;

			for (int i = first; i < str.length(); i++)
				temp += str[i];

			break;
		}
	}

	return temp;
}

string noEndingPunctuation(string _word)
{
	string temp = _word;
	bool done = false;

	while (done != true)
	{
		// get rid of ending punctuation 
		// if not alpha char or number erase it
		if (!(temp[temp.size() - 1] >= 'A' && temp[temp.size() - 1] <= 'Z')
			|| !(temp[temp.size() - 1] >= 'a' && temp[temp.size() - 1] <= 'z')
			|| !(temp[temp.size() - 1] >= '0' && temp[temp.size() - 1] <= '9'))
			temp = temp.erase(temp.size() - 1);

		if (isDigit(temp[temp.size() - 1]))
			done = true;
	}

	return temp;
}

bool isLeapYear(const int year)
{
	if ((year % 4 == 0) && (year % 100 != 0)) // if it is a leap year
	{
		return true;
	}
	else
		return false;
}

string currentDayOfWeek(const int days, const int year)
{

	const int epochYear = 1973;
	int yearsAfterLeapYr = 0;
	int temp = epochYear;

	while (temp != year)
	{
		if (isLeapYear(temp - 1))
			yearsAfterLeapYr++;

		temp++;
	}

	// day of the week the year started on
	int dayOfWeek = ((year - 1973) + yearsAfterLeapYr) % 7;

	// day of the week of the current time
	dayOfWeek += days % 7;

	if (dayOfWeek == 7)
		dayOfWeek = 0;

	else if (dayOfWeek > 7)
	{
		while (dayOfWeek > 7)
		{
			dayOfWeek -= 7;
		}
	}

	switch (dayOfWeek)
	{
	case 0:
	{
		return "Mon";
		break;
	}
	case 1:
	{
		return "Tue";
		break;
	}
	case 2:
	{
		return "Wed";
		break;
	}
	case 3:
	{
		return "Thu";
		break;
	}
	case 4:
	{
		return "Fri";
		break;
	}
	case 5:
	{
		return "Sat";
		break;
	}
	case 6:
	{
		return "Sun";
		break;
	}
	default:
	{
		return "Fail";
		break;
	}
	}
}

string getDayAndMonthOfYr(int& days, const int year)
{
	enum
	{
		Jan = 31,
		Feb = 28,
		Mar = 31,
		April = 30,
		May = 31,
		June = 30,
		July = 31,
		Aug = 31,
		Sept = 30,
		Oct = 31,
		Nov = 30,
		Dec = 31
	} months;

	// put jan, feb, etc. in first part and corresponding days in second part
	map < int, int> myMap;

	// JANUARY
	myMap.insert(pair<int, int>(1, Jan));

	// FEBRUARY
	if (isLeapYear(year))
		myMap.insert(pair<int, int>(2, 29));
	else
		myMap.insert(pair<int, int>(2, Feb));

	// MARCH
	myMap.insert(pair<int, int>(3, Mar));

	// APRIL
	myMap.insert(pair<int, int>(4, April));

	// MAY
	myMap.insert(pair<int, int>(5, May));

	// JUNE
	myMap.insert(pair<int, int>(6, June));

	// JULY
	myMap.insert(pair<int, int>(7, July));

	// AUGUST
	myMap.insert(pair<int, int>(8, Aug));

	// SEPTEMBER
	myMap.insert(pair<int, int>(9, Sept));

	// OCTOBER
	myMap.insert(pair<int, int>(10, Oct));

	// NOVEMBER
	myMap.insert(pair<int, int>(11, Nov));

	// DECEMBER
	myMap.insert(pair<int, int>(12, Dec));

	int month = 1;
	int daysLeft = days;

	while (daysLeft > 31)
	{
		daysLeft -= myMap.at(month);

		month++;

		if (month > 12)
			month = 1;
	}

	if (month < 1)
		month = 12;

	// if current days > days of current month
	if (daysLeft > myMap.at(month))
	{
		daysLeft -= myMap.at(month);
	}

	days = daysLeft + 1;

	switch (month)
	{
	case 1:
		return "Jan";

	case 2:
		return "Feb";

	case 3:
		return "Mar";

	case 4:
		return "Apr";

	case 5:
		return "May";

	case 6:
		return "Jun";

	case 7:
		return "Jul";

	case 8:
		return "Aug";

	case 9:
		return "Sep";

	case 10:
		return "Oct";

	case 11:
		return "Nov";

	case 12:
		return "Dec";
	default:
		return "FAIL";
	} // end switch statement
}

string scramble(string s)
{
	int value = rand() % s.size(); // 0 - last index of string 
	int i = 0; // index in the temp array
	vector<int> listOfValues;
	vector<int>::iterator it;
	vector<char> tChar;
	string temp = "";

	while (tChar.size() != s.size())
	{
		value = rand() % s.size();
		it = find(listOfValues.begin(), listOfValues.end(), value);

		if (it == listOfValues.end())
		{
			tChar.push_back(s[value]);
			listOfValues.push_back(value);
		}
		else
			continue;

	}

	for (int i = 0; i < tChar.size(); i++)
	{
		temp += tChar[i];
	}

	return temp;
}
