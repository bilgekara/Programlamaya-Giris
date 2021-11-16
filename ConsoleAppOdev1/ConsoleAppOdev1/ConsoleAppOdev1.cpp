

#include <iostream>
#include <time.h>
#include <string>
#include <vector>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");

	int enBuyuk = 0; int enKucuk = 50;
	string sehirBuyuk = ""; string sehirKucuk = "";
	int random; int sayac;

	string iller[81]{
		"Adana", "Adıyaman", "Afyonkarahisar", "Ağrı", "Aksaray", "Amasya", "Ankara", "Antalya", "Ardahan", "Artvin", "Aydın", "Balıkesir", "Bartın", "Batman", "Bayburt", "Bilecik", "Bingöl", "Bitlis", "Bolu", "Burdur", "Bursa", "Çanakkale", "Çankırı", "Çorum", "Denizli", "Diyarbakır", "Düzce", "Edirne", "Elazığ", "Erzincan", "Erzurum", "Eskişehir", "Gaziantep", "Giresun", "Gümüşhane", "Hakkâri", "Hatay", "Iğdır", "Isparta", "İstanbul", "İzmir", "Kahramanmaraş", "Karabük", "Karaman", "Kars", "Kastamonu", "Kayseri", "Kilis", "Kırıkkale", "Kırklareli", "Kırşehir", "Kocaeli", "Konya", "Kütahya", "Malatya", "Manisa", "Mardin", "Mersin", "Muğla", "Muş", "Nevşehir", "Niğde", "Ordu", "Osmaniye", "Rize", "Sakarya", "Samsun", "Şanlıurfa", "Siirt", "Sinop", "Sivas", "Şırnak", "Tekirdağ", "Tokat", "Trabzon", "Tunceli", "Uşak", "Van", "Yalova", "Yozgat", "Zonguldak"
	};


	for (int i = 0; i < 81; i++) {
		if (enBuyuk < iller[i].size()) {
			enBuyuk = iller[i].size();
			sehirBuyuk = iller[i];
		}
		if (enKucuk > iller[i].size()) {
			enKucuk = iller[i].size();
			sehirKucuk = iller[i];
		}
	}
	cout << "En küçük şehir -> " << sehirKucuk << "--" << enKucuk << endl;
	cout << "En büyük şehir -> " << sehirBuyuk << "--" << enBuyuk << endl;
	cout << "-----------------" << endl << endl;
	for (int k = 0; k < enBuyuk; k++) {

		vector<string> secilmisDizi; int secilmisDiziKisa = 50;

		bool bulunduMu = false;
		sayac = 0;
		while (bulunduMu == false && sayac < 1000) {

			secilmisDizi.clear();
			for (int i = 0; i < enKucuk; i++) {
				srand(time(NULL)); random = 1 + rand() % 81;
				if (secilmisDiziKisa > iller[random].size()) {
					// rastgele secilmis dizideki en kucuk elemani buluyoruz
					secilmisDiziKisa = iller[random].size();
				}
				secilmisDizi.push_back(iller[random]);
			}

			for (int i = 0; i < secilmisDiziKisa; i++) {
				string temp = "";
				for (int j = 0; j < enKucuk; j++) {
					temp += secilmisDizi.operator[](j).substr(i, 1);
				}
				temp = "Adana";
				if (temp == sehirKucuk) {
					cout << enKucuk << " harfli şehir bulundu -> " << temp << endl;
					bulunduMu = true;
					break;
				}
			}
			sayac++;
		}

		if (bulunduMu == false) {
			cout << enKucuk << " harfli şehir bulunamadı." << endl;
		}
		enKucuk++;
		for (int i = 0; i < 81; i++) {
			if (enKucuk == iller[i].size()) {
				enKucuk = iller[i].size();
				sehirKucuk = iller[i];
				break;
			}
		}
	}


}