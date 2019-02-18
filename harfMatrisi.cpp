/**********************************************************
Rastgele tekrarsiz bir harf matrisi olusturan ve bunlari alfabeye gore siralayan program
***********************************************************/
#include <iostream> 
#include <ctime>
using namespace std;
int main() {
	srand(time(NULL));//zamana gore farkli degerler olmasi icin
	char Harf[5][10];
	int temp;//diziye atamak istedigimiz degeri gecici olarak tutmak icin
	cout << "Tekrarsiz ve rastgele dizi:" << endl;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			bool check;//kontrol amacli bir bool degiskeni olusturuyoruz(ayni harf var mi?)
			do {
				if (j % 2 == 0)//matrisimizin sutunu cift olunca buyuk harf yazdiriyoruz amacimiz bir buyuk bir kucuk harf yazdirmak
				{
					temp = 65 + rand() % 26;//buyuk harfleri rastgele atamak icin(ascii de A=65)
				}
				else
				{
					temp = 97 + rand() % 26;//kucuk harfleri rastgele atamak icin
				}
				check = true;
				for (int i = 0; i < 5; i++) {
					for (int j = 0; j < 10; j++) {
						if (temp == Harf[i][j]) {//eger yeni atadigimiz deger daha once dizi icerisinde varsa donguye giricek ifademizi false yapip yeni deger atiyacak.
							check = false;
							break;
						}
					}
				}
			} while (!check);//eger temp bir elemana esit olmazsa check hic false olmayacak ve while dongusunden cikacak
			Harf[i][j] = temp;
			cout << Harf[i][j] << "   ";
		}
		cout << endl;
	}
#pragma region siralama
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			int tmp = Harf[i][j];//ilk olarak tmp'e atiyoruz ki karsilastirma yapabilelim
			int l = j + 1;
			for (int k = i; k < 5; k++) {
				while (l < 10) {
					if (tmp > Harf[k][l]) {
						tmp = Harf[k][l];
						Harf[k][l] = Harf[i][j];
						Harf[i][j] = tmp;
					}
					l++;
				}
				l = 0;
			}
		}
	}
#pragma endregion
	cout << "Siralanmis Dizi:" << endl;
	for (int i = 0; i < 5; i++) {//yeni matrisimizi yazdiriyor
		for (int j = 0; j < 10; j++) {
			cout << Harf[i][j] << "   ";
		}
		cout << endl;
	}
	system("pause");
}