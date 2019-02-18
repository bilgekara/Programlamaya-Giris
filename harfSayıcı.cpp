/******************************************************
Girilen metindeki ünlü harfleri bulan ve sayısını tablo şeklinde çıkaran program
 ****************************************************/
#include<iostream>
#include <iomanip>
using namespace std;
int main() {
	char cumle[50];
	cout << "Please enter the text:";
	cin.get(cumle, 50);
	int sayaca = 0;
	int sayace = 0;
	int sayaci = 0;
	int sayaco = 0;
	int sayacu = 0;
	for (int i = 0; i < 50; i++) {//dizinin boyutu kadar dönüp içerideki harfleri sayıyor
		if (cumle[i] == 'a') sayaca++;
		if (cumle[i] == 'e') sayace++;
		if (cumle[i] == 'i') sayaci++;
		if (cumle[i] == 'o') sayaco++;
		if (cumle[i] == 'u') sayacu++;
	}
	int sayacdizisi[5] = { sayaca,sayace,sayaci,sayaco,sayacu };//en büyük elemanı bulma sebebim tabloda en fazla olan harf sayısı kadar sayı çıkması
	int enb = sayacdizisi[0];
	for (int i = 0; i < 5; i++) {
		if (enb < sayacdizisi[i]) enb = sayacdizisi[i];
	}
	cout << "H" << " \t" << "TS" << "\t";//harf,tekrar sayısı
	for (int i = 1; i <= enb; i++) {
		cout << i << setw(3);
		if (i == enb) cout << " ";
	}
	cout << endl << "a" << "\t" << sayaca << "\t";
	for (int i = 0; i < sayaca; i++) {
		cout << "a  ";
	}
	cout << endl << "e" << "\t" << sayace << "\t";
	for (int i = 0; i < sayace; i++) {
		cout << "e  ";
	}
	cout << endl << "i" << "\t" << sayaci << "\t";
	for (int i = 0; i < sayaci; i++) {
		cout << "i  ";
	}
	cout << endl << "o" << "\t" << sayaco << "\t";
	for (int i = 0; i < sayaco; i++) {
		cout << "o  ";
	}
	cout << endl << "u" << "\t" << sayacu << "\t";
	for (int i = 0; i < sayacu; i++) {
		cout << "u  ";
	}
	system("PAUSE");
}
