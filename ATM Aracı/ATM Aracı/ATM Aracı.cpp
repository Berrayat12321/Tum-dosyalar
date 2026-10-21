#include <iostream>

using namespace std;
int main()
{	
	int Bakiye = 0;
	int cevap;
	int Bool;
	int miktar;
	int para;

	do {
		cout << "1.Balance Inquiry" << endl;
		cout << "2.Deposit" << endl;
		cout << "3.Withdrawal" << endl;

		cout << "Please select the action you wish to perform..";

		cin >> cevap;

		if (cevap == 1) {
			cout << "Your balance:" << Bakiye << endl;
		}
		else if (cevap == 2) {
			cout << "Enter the amount you wish to deposit." << endl;
			cin >> miktar;

			cout << "Your balance:" << miktar + Bakiye << endl;
			Bakiye = miktar + Bakiye;
		}
		else if (cevap == 3) {
			cout << "Enter the amount you wish to withdraw." << endl;
			cin >> miktar;

			if (miktar  <= 99) {
				cout << "Enter a larger amount." << endl;
			}
			else if (miktar >> Bakiye) {
				cout << "Insufficient balance." << endl;
			}
			else if (miktar << Bakiye) {
				cout << "Your action has been completed." << endl;
				Bakiye = Bakiye - miktar;
			}
		

		}
		else {
			cout << "Action not found." << endl;
		}

		cout << "Is there anything else you would like to do?" << endl;

		cout << "1.Yes" << endl;
		cout << "2.No" << endl;

		cin >> Bool;

		
	} while (Bool == 1);




	return 0;
}
