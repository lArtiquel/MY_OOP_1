
#include "String.h"

// copy c-tor
String::String(const String& other)
{
	this->_s = new char[other._size + 1];
	this->_size = other._size;
	memcpy(this->_s, other._s, other._size + 1);
}

// usual char c-tor
String::String(const char* str)
{
	unsigned int len = myStrlen(str) + 1;	// +1 because of null-term
	this->_s = new char[len];	
	this->_size = len - 1;
	memcpy(this->_s, str, len);
}

//move c-tor
String::String(String&& other) : _s(other._s), _size(other._size)
{
	delete[] other._s;
	other._size = 0;
}

// static my strlen function
unsigned int String::myStrlen(const char * str)
{
	unsigned int count = 0;

	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}

// overloaded copy operator
String& String::operator=(const String& other)
{
	delete[] this->_s;
	this->_s = new char[other._size + 1];
	this->_size = other._size;
	memcpy(this->_s, other._s, other._size + 1);
	return *this;
}

// overloaded += operator
String& String::operator+=(const String& other)
{
	unsigned int sumLen = this->_size + other._size + 1;

	char* temp = new char[sumLen];
	memcpy(temp, this->_s, this->_size);
	memcpy(temp + this->_size, other._s, other._size + 1);
	delete[] this->_s;
	this->_size = sumLen - 1;	// without null-term
	this->_s = temp;
	return *this;
}

// overloaded += operator
String& String::operator+(const String& other)
{
	unsigned int sumLen = this->_size + other._size + 1;

	char* temp = new char[sumLen];
	memcpy(temp, this->_s, this->_size);
	memcpy(temp + this->_size, other._s, other._size + 1);
	delete[] this->_s;
	this->_size = sumLen - 1;	// without null-term
	this->_s = temp;
	return *this;
}

// overloaded operator==
bool String::operator==(const String& other)
{
	if (this->_size != other._size) return false;

	if (this->_size > other._size)
	{
		for (int i = 0; i < other._size; i++)
		{
			if (this->_s[i] == other._s[i]) continue;
			return false;
		}
	}
	else
	{
		for (int i = 0; i < this->_size; i++)
		{
			if (this->_s[i] == other._s[i]) continue;
			return false;
		}
	}

	return true;
}

// overloaded operator==
bool String::operator!=(const String& other)
{
	if (this->_size != other._size) return true;

	if (this->_size > other._size)
	{
		for (int i = 0; i < other._size; i++)
		{
			if (this->_s[i] == other._s[i]) continue;
			return true;
		}
	}
	else
	{
		for (int i = 0; i < this->_size; i++)
		{
			if (this->_s[i] == other._s[i]) continue;
			return true;
		}
	}

	return false;
}

// overloaded operator<
bool String::operator<(const String& other)
{
	if (this->_size > other._size)
	{
		for (int i = 0; i < other._size; i++)
		{
			if (this->_s[i] == other._s[i]) continue;
			return (this->_s[i] < other._s[i])? true: false;
		}
	}
	else
	{
		for (int i = 0; i < this->_size; i++)
		{
			if (this->_s[i] == other._s[i]) continue;
			return (this->_s[i] < other._s[i])? true : false;
		}
	}

	return (this->_size < other._size) ? true : false;
}

// overloaded operator>
bool String::operator>(const String& other)
{
	if (this->_size > other._size)
	{
		for (int i = 0; i < other._size; i++)
		{
			if (this->_s[i] == other._s[i]) continue;
			return (this->_s[i] > other._s[i]) ? true : false;
		}
	}
	else
	{
		for (int i = 0; i < this->_size; i++)
		{
			if (this->_s[i] == other._s[i]) continue;
			return (this->_s[i] > other._s[i]) ? true : false;
		}
	}

	return (this->_size > other._size) ? true : false;
}

// overloaded operator>=
bool String::operator>=(const String& other)
{
	if (this->_size > other._size)
	{
		for (int i = 0; i < other._size; i++)
		{
			if (this->_s[i] == other._s[i]) continue;
			return (this->_s[i] >= other._s[i]) ? true : false;
		}
	}
	else
	{
		for (int i = 0; i < this->_size; i++)
		{
			if (this->_s[i] == other._s[i]) continue;
			return (this->_s[i] >= other._s[i]) ? true : false;
		}
	}

	return (this->_size >= other._size) ? true : false;
}

// overloaded operator<=
bool String::operator<=(const String& other)
{
	if (this->_size > other._size)
	{
		for (int i = 0; i < other._size; i++)
		{
			if (this->_s[i] == other._s[i]) continue;
			return (this->_s[i] <= other._s[i]) ? true : false;
		}
	}
	else
	{
		for (int i = 0; i < this->_size; i++)
		{
			if (this->_s[i] == other._s[i]) continue;
			return (this->_s[i] <= other._s[i]) ? true : false;
		}
	}

	return (this->_size <= other._size) ? true : false;
}

// overloaded ostream operator <<
ostream& operator<<(ostream& out, const String& str)
{
	out << str._s;
	return out;
}

// overloaded istream operator >>
istream& operator>>(istream& in, String& str)
{
	// @verify no errors are set, flush tied streams, strip leading whitespace.
	istream::sentry sentry(in);
	if (!sentry)
		return in;

	str._size = 0;	// @null length of string
	unsigned int tail = 0;
	int next;		// @note int not char (to record EOF).
	delete[] str._s;	// @delete previous string

	while ((next = in.get()) != in.eof() && !isspace(next)) {
		// if temp buffer is exhausted, then double the buffer size.
		// (base size of 16).
		if (tail == str._size) {
			unsigned int newsize = max(2 * str._size, 16u);
			char* newtemp = new char[newsize + 1];
			memcpy(newtemp, str._s, str._size);
			str._s[str._size] = '\0';
			delete[] str._s;
			str._s = newtemp;
			str._size = newsize;
		}
		str._s[tail++] = next;
	}
	// @note because the stream is prepeared with istream::sentry, there
	// will be at least one non-whitespace character in the stream.
	assert(str._s != nullptr);

	// shrink_to_fit buffer
	char *temp = new char[tail + 1];
	memcpy(temp, str._s, tail);
	str._s[str._size] = '\0';
	delete[] str._s;
	str._s = temp;
	str._size = tail;
	str._s[tail] = '\0';

	return in;
}

String::~String()
{
	delete[] this->_s;
}