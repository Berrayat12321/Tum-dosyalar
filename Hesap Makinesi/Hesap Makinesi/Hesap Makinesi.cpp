#include <iostream>
#include <clocale>
using namespace std;
int main()
{

	int a;
	int b;

	string işlem;

	string input;

	cout << "Operation 1: Addition (+)" << endl;
	cout << "Operation 2: Subtraction (-)" << endl;
	cout << "Operation 3: Collision (x)" << endl;
	cout << "Operation 4: Division (/)" << endl;



	cout << "Which action would you like to perform?" << endl;

	cin >> işlem;

	if (işlem == "1") {
		cout << "a:";
		cin >> a;
		cout << "b:";
		cin >> b;

		cout << "Result:" << a + b << endl;
	}

	else if (işlem == "2") {
		cout << "a:";
		cin >> a;
		cout << "b:";
		cin >> b;

		cout << "Result:" << a - b << endl;
	}

	else if (işlem == "3") {
		cout << "a:";
		cin >> a;
		cout << "b:";
		cin >> b;

		cout << "Result:" << a * b << endl;
	}

	else if (işlem == "4") {
		cout << "a:";
		cin >> a;
		cout << "b:";
		cin >> b;

		cout << "Result:" << (float)a / b << endl;
	}
	else {
		cout << "İnvalid Action" << endl;
	}


	return 0;
}

