/******************************************************
Yildizlari kullanarak sekil oluşturan program
 ****************************************************/
#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	int yildiz1 = 5;//ilk satırdaki yıldız sayısı 5 ten başlıyor giderek azalıyor
	int yildiz2 = 5;
	int sayac = 0;
	int bosluk = 4;//ilk satırda boşluk 4'ten başlayıp giderek artıyor
	while (sayac < 5) {
		for (int i = yildiz1; i > 0; i--) {//ilk satıra 5 yıldız yazdırıcak döngüden çıkıcak altta yıldız sayısını azaltıyoruz ve bir alt satıra geçmesini sağlıyoruz
			cout << "* ";
		}
		yildiz1--;
		cout << setw(bosluk);
		bosluk += 4;
		for (int i = yildiz2; i > 0; i--) {
			cout << "* ";
		}
		yildiz2--;
		cout << endl;
		sayac++;//while 5.satıra geldiğinde durması için sayaçı her seferinde 1 artırıyoruz
	} 
	cout << endl;
	int yildiz_1 = 1;
	int yildiz_2 = 1;
	int bosluk_ = 20;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < yildiz_1; j++) {//yıldız sayısı her satırda arttığı için yıldız diye değişken atıyoruz
			cout << "* ";
		}
		yildiz_1++;
		cout << setw(bosluk_);
		bosluk_ -= 4;
		for (int j = 0; j < yildiz_2; j++) {
			cout << "* ";
		}
		yildiz_2++;
		cout << endl;
	}
	system("pause");
}



