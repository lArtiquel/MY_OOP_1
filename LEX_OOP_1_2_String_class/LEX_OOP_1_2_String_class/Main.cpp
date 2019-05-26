/*
Task:
	Реализовать класс String для работы со строками символов. Перегрузить операторов «=», «+=», «==», «<», «>», «!=», «<=», «>=».
	Предоставить конструктор копирования. Определить friend-функции для операторов ввода/вывода в поток.
*/

#include <iostream>
#include "String.h"

using namespace std;

int main()
{
	cout << "Welcome to String Tester!\n";
	String a("aaa");
	String b("bbb");
	cout << "a: " << a << '\n';
	cout << "b: " << b << '\n';
	// = operator test
	b = a;
	cout << "= operator test --> b(a): " << b << '\n';
	// = operator test
	b += a;
	cout << "= operator test --> b + a: " << b << '\n';
	cout << "b size: " << b.size() << '\n';
	// != operator test
	cout << "!= operator test\n";
	cout << "a = " << a << "; b = " << b << "\n";
	if (a != b) cout << "not equals <-- right answer\n";
	else cout << "equals <-- wrong answer\n";
	// == operator test
	cout << "== operator test\n";
	cout << "a = " << a << "; b = " << b << "\n";
	if (a == b) cout << "equals! <-- wrong answer\n";
	else cout << "not equals <-- right answer\n";
	// < operator test
	cout << "< operator test\n";
	cout << "a = " << a << "; b = " << b << "\n";
	if (a < b) cout << "a < b <-- right answer\n";
	else cout << "a > b <-- wrong answer\n";
	// > operator test
	cout << "> operator test\n";
	cout << "a = " << a << "; b = " << b << "\n";
	if (a > b) cout << "a > b <-- wrong answer\n";
	else cout << "a < b <-- right answer\n";
	// >= operator test
	cout << "> operator test\n";
	cout << "a = " << a << "; b = " << b << "\n";
	if (a >= b) cout << "a >= b <-- wrong answer\n";
	else cout << "a < b <-- right answer\n";
	// <+ operator test
	cout << "< operator test\n";
	cout << "a = " << a << "; b = " << b << "\n";
	if (a <= b) cout << "a <= b <-- right answer\n";
	else cout << "a > b <-- wrong answer\n";
	// copy c-tor with + test
	String c(b + a);
	cout << "copy c-tor with + test\n";
	cout << c << " <-- should be 'aaaaaaaaa'";
	cout << "; it's size: " << c.size() << '\n';
	/*needed to fix
		// testing in/out
		String d(b + c);
		cout << "testing in/out(input string and see it repeaded)\n";
		cin >> d;
		cout << "repeating string: " << d << " and it's size: " << d.size() << '\n';
	*/
	system("pause");
}