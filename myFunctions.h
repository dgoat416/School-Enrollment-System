#pragma once

#ifndef H_MYFUNC
#define H_MYFUNC	

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// provide class definition
char intToChar(int x);

string intToString(int x);
	
int charToInt(char x);

int stringToInt(string str);

bool isDigit(char c);

bool isAlpha(char c);

bool isAlpha(string _word);

string onlyAlphaChars(string _word);

string noLeadingWhiteSpace(string str);

string noEndingPunctuation(string _word);

bool isLeapYear(const int year);

string currentDayOfWeek(const int days, const int year);

string getDayAndMonthOfYr(int& days, const int year);

string scramble(string s);



#endif