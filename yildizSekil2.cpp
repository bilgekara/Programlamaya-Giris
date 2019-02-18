/******************************************************
Yildizlari kullanarak sekil olusturan program 2
****************************************************/
#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	int bos = 4;
	for (int i = 5; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			cout << "* ";
		}
		cout << setw(bos);
		bos += 4;
		for (int j = i; j > 0; j--) {
			cout << "* ";
		}
		cout << endl;
	}
	cout << endl;
	int bosluk_ = 20;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < i + 1; j++) {
			cout << "* ";
		}
		cout << setw(bosluk_);
		bosluk_ -= 4;
		for (int j = 0; j < i + 1; j++) {
			cout << "* ";
		}
		cout << endl;
	}
	system("pause");
}


