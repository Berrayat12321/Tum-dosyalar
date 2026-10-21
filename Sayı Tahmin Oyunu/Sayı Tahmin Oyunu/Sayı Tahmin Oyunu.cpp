#include <iostream>
using namespace std;
  

int main(){
	
	cout << "WELCOME TO THE NUMBER GUESSING GAME!!" << endl;
	cout << "You must guess the number! (Hint: Number is between 0 and 11)" << endl;

    srand(time(0));
	int sayi = rand() % 10 + 1;
	int tahmin;

	do {
		cout << "What is your guess?" << endl;

		cin >> tahmin;


		if (tahmin == sayi) {
			cout << "Easy peasy, lemon squeezy!!" << endl;
		}
		else if (tahmin != sayi && 0 < tahmin && tahmin < 11) {
			cout << "Don't be sad, Try Again!!" << endl;
		}
		else {
			cout << "What? Didn't you read the hint? I said its between 0 and 11 (1,2,3,4,5,6,7,8,9,10)" << endl;
		}
	} while (tahmin != sayi);
		return 0; 
}
