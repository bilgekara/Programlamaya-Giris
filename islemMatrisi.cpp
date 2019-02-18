/**********************************************************
Bizim tanımladıgımız bir matris ustunde gezen cekirdek matrisi ve bu matrisin kayma miktari kullanıcı tarafından giriliyor.
Eger cekirdek matrisi bizim matrisimizden tasarsa "islem yapilamaz" sonucu ekrana cikiyor.
Eger tasmazsa ust uste olan elemanları carpip hepsini topluyoruz ve yeni bir matrise atıyoruz.Kayma miktari kadar kayip işlemlere devam ediyor.
*********************************************************/
#include <iostream>
#include <cstdlib>
using namespace std;
struct Islemler {
	int giris[5][5]{ 3,2,5,1,4,
					 6,2,1,0,7,
					 3,0,0,2,0,
					 1,1,3,2,2,
					 0,3,1,0,0
	};
	int kaymaMiktari;
	int cekirdekBoyutu;
	int sonucBoyut[100][100];//sonucBoyut 100'den fazla olamaz cünkü giris matrisinden buyuk olamaz giris matrisi de en fazla 100*100 luk bir matris olabilir
};
void yazdir(Islemler k);//burada paremetre olarak verip main altinda fonksiyonu yazdim
void islemYap(Islemler d);
int main() {
	Islemler g;
	cout << "cekirdek boyutunu giriniz:";
	cin >> g.cekirdekBoyutu;
	cout << "kayma miktarini giriniz:";
	cin >> g.kaymaMiktari;
	cout << endl;
	int eleman = (sizeof(g.giris) / sizeof(int));//dizinin boyutunu belirlemek icin
	eleman = sqrt(eleman);//dizi iki boyutlu oldugu icin karekökünü alarak satir ve sütün boyutunu ogrenebiliyoruz
	float new_boyut = (((float)eleman - (float)g.cekirdekBoyutu) / (float)g.kaymaMiktari) + (float)1;//yeni matrisimizin boyutunu bulmaya yariyor 
	if (new_boyut != floor(new_boyut))//floor tam sayiya dönüstürüyor eğer new_boyut virgüllü cikarsa ,floor(new_boyut) virgullu new_boyut a esit olmicak ve islem yapilamayacak
	{
		cout << "bu islem yapilamaz.." << endl;
	}
	else {//eger new_boyut tam sayi ise
		islemYap(g);//islemYap fonksiyonunu cagiriyoruz
	}
	system("pause");
}
void yazdir(Islemler k) { //bu fonksiyon sonucmatrisini yazdirmaya yariyor bunu islemYap matrisi icinde cagiriyoruz
	int eleman = (sizeof(k.giris) / sizeof(int));//dizinin boyutunu belirlemek icin
	eleman = sqrt(eleman);
	float new_boyut = (((float)eleman - (float)k.cekirdekBoyutu) / (float)k.kaymaMiktari) + (float)1;
	for (int i = 0; i < new_boyut; i++) {
		for (int j = 0; j < new_boyut; j++) {
			cout << k.sonucBoyut[i][j] << "\t";
		}
		cout << endl;
	}
}
void islemYap(Islemler d) {
	int eleman = (sizeof(d.giris) / sizeof(int));//dizinin boyutunu belirlemek icin
	eleman = sqrt(eleman);
	float new_boyut = (((float)eleman - (float)d.cekirdekBoyutu) / (float)d.kaymaMiktari) + (float)1;
	int **cekirdek = (int **)malloc(sizeof(int)*d.cekirdekBoyutu);

	/*malloc kullanmamin sebebi diziyi dinamik yapabilmek*/

	for (int i = 0; i < d.cekirdekBoyutu; i++) {//amacimiz diziyi iki boyutlu hale getirmek

		cekirdek[i] = (int *)malloc(d.cekirdekBoyutu * sizeof(int));

	}
	for (int i = 0; i < d.cekirdekBoyutu; i++) {
		for (int j = 0; j < d.cekirdekBoyutu; j++) {
			cout << "cekirdek[" << i << "][" << j << "]:";
			cin >> cekirdek[i][j];
			cout << endl;
		}
	}
	cout << endl;
	int satir = 0;
	int sütun = 0;
	int temp_satir = d.cekirdekBoyutu;
	int temp_sütun = d.cekirdekBoyutu;
	int m, n;//gecici matrisinin boyutlari
	int a = 0;//sonuc matrisinin boyutlari
	int b = 0;
	int **gecici = (int **)malloc(sizeof(int)*d.cekirdekBoyutu);//pointer dizisi olusturma
	for (int i = 0; i < d.cekirdekBoyutu; i++) {
		gecici[i] = (int *)malloc(d.cekirdekBoyutu * sizeof(int));
	}
	for (int k = 0; k < new_boyut; k += d.kaymaMiktari) {
		for (int t = 0; t < new_boyut; t += d.kaymaMiktari) {
			m = 0;
			for (int i = satir; i < temp_satir; i++) {//matrisimizi kaydircikca kaydirdigimiz sayi kadar artiyor(satirlar icin)
				n = 0;
				for (int j = sütun; j < temp_sütun; j++) {//matrisimizi kaydircikca kaydirdigimiz sayi kadar artiyor(sütunlar icin)
					gecici[m][n] = d.giris[i][j];//islem yapicagimiz elemanlari gecici matrise atiyorum
					n++;
				}
				m++;
			}
			int T = 0;
			for (int i = 0; i < d.cekirdekBoyutu; i++) {
				for (int j = 0; j < d.cekirdekBoyutu; j++) {
					T += gecici[i][j] * cekirdek[i][j];//üst üste olan elemanlari carpip kendi arasinda topluyoruz
				}
			}
			d.sonucBoyut[a][b] = T;//buldugumuz toplam degiskenini sonuc matrisine atiyoruz
			sütun += d.kaymaMiktari;
			temp_sütun += d.kaymaMiktari;
			b++;//sonucBoyut un sutünunu kontrol icin
		}
		satir += d.kaymaMiktari;//satir kayma miktari kadar artmali
		temp_satir += d.kaymaMiktari;
		sütun = 0;//satir da ilerledigimiz zaman sütun sifir olmali
		temp_sütun = d.cekirdekBoyutu;//for'un kac kere donecegini belirledigi icin cekirdek_boyutuna geri döndürüyoruz
		a++;//sonucBoyut un satirini kontrol icin
		b = 0;//satir atlayinca sütun sifir olmali
	}
	yazdir(d);
}
