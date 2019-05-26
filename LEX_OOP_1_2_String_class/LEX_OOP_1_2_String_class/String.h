#pragma once
#include <iostream>
#include <cctype>	 // isspace
#include <algorithm> // max
#include <cassert>	 // for assert macro

using namespace std;

class String
{
private:
	unsigned int _size;
	char* _s;		 // not counting null-term

	static unsigned int myStrlen(const char *str);

public:
	// c-tor by default
	String() : _size(0), _s(nullptr) {}
	// copy c-tor
	String(const String&);
	// char c-tor
	String(const char* str);
	// move c-tor
	String(String&& other);

	String& operator=(const String& other);
	String& operator+=(const String& other);
	String& operator+(const String& other);
	bool operator==(const String& other);
	bool operator!=(const String& other);
	bool operator<(const String& other);
	bool operator>(const String& other);
	bool operator>=(const String& other);
	bool operator<=(const String& other);

	friend ostream& operator<<(ostream& out, const String& str);
	friend istream& operator>>(istream& in, String& str);

	unsigned int size() { return _size; }
	~String();
};