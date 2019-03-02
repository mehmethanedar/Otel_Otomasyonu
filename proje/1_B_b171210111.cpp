/****************************************************************************
**					SAKARYA ÜNÝVERSÝTESÝ
**			         BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				    BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				          PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI.......:PROJE ÖDEVÝ
**				ÖÐRENCÝ ADI.........:Mehmet Nuri HANEDAR
**				ÖÐRENCÝ NUMARASI....:B171210111
**				DERS GRUBU..........:B
**
**
****************************************************************************/

#include<iostream>
#include<string>
#include<fstream>

using namespace std;
string secim, secim2;
string bos;
string odano, odaucret;
string musteri_no, musteri_ad, musteri_soyad, musteri_tc;

void odaekle();
void oda_islemleri();
bool kontrol(string x);
bool kontrolmusteri(string kontrol, string kontroltc);
void musteri_islemleri();
void oda_kayit_islemleri();
bool kayitodakontrol(string kontrol2);
bool kayitkontrol(string kontrol);

int main();


void odaekle()
{
	ofstream dosyayaz;
	dosyayaz.open("oda.txt", ios::app);
	do
	{
		cout << "Oda numarasý giriniz \t :";
		cin >> odano;
		cout << endl << "Oda ücreti giriniz \t :";
		cin >> odaucret;
	} while (kontrol(odano));
	dosyayaz << odano << "\t" << odaucret << "\n";
	dosyayaz.close();
	oda_islemleri();
}

//ayný odadan var mý diye kontrol eder
bool kontrol(string x)
{
	string kontroloda, kontrolucret;
	ifstream oku;
	oku.open("oda.txt");
	while (!oku.eof())
	{
		oku >> kontroloda >> kontrolucret;
		if (oku.eof())	break;
		if (x == kontroloda)
		{
			system("cls");
			cout << "Girilen oda numarasýna ait oda bulunmaktadýr!" << endl;
			oku.close();
			system("pause");
			oda_islemleri();
		}
	}
	oku.close();
	return false;
}

void odasil()
{
	string deger;
	system("cls");
	cout << "Silinecek oda numarasýný giriniz : ";
	cin >> deger;
	ifstream dosyaoku;
	dosyaoku.open("oda.txt");
	ofstream dosyayaz;
	dosyayaz.open("yedek_oda.txt", ios::app);
	while (!dosyaoku.eof())
	{
		dosyaoku >> odano >> odaucret;
		if (odano != deger)
		{
			if (dosyaoku.eof())		break;
			dosyayaz << odano << "\t" << odaucret << "\n";
		}
	}
	dosyaoku.close();
	dosyayaz.close();

	remove("oda.txt");
	rename("yedek_oda.txt", "oda.txt");

	oda_islemleri();
}

void odalari_listele()
{
	int a;
	ifstream dosyaoku;
	dosyaoku.open("oda.txt");
	while (!dosyaoku.eof())
	{
		dosyaoku >> odano >> odaucret;
		if (dosyaoku.eof())		break;
		cout << "Oda numarasý : " << odano << endl << "Oda ücreti   : " << odaucret << endl << endl;
	}
	do
	{
		cout << "99 - Üst Menü : ";
		cin >> a;
		if (a != 99)
		{
			cout << "Lütfen tekrar deneyiniz..." << endl << endl;
		}
	} while (a != 99);
	dosyaoku.close();
	oda_islemleri();
}

void oda_islemleri()
{
	do
	{
		system("cls");
		cout << "Oda Ýþlemleri" << endl;
		cout << "-------------------" << endl;
		cout << "1 - Oda ekle" << endl;
		cout << "2 - Oda Sil" << endl;
		cout << "3 - Odalarý Listele" << endl;
		cout << "99 - Üst Menü" << endl;
		cout << "Seçiminiz : ";
		cin >> secim2;
		system("cls");
		if (secim2 == "1")
		{
			odaekle();
		}
		else if (secim2 == "2")
		{
			odasil();
		}
		else if (secim2 == "3")
		{
			odalari_listele();
		}
		else if (secim2 == "99")
		{
			main();
		}
		else
		{
			system("cls");
			cout << "Hatalý Seçim" << endl;
			system("pause");
			system("cls");
		}
	} while (secim2 != "1" && secim2 != "2" && secim2 != "3" && secim2 != "99");
}

void musteri_ekle()
{
	system("cls");
	ofstream dosyaYazz("musteri.txt", ios::app);
	do
	{
		cout << "Müþteri numarasý \t : ";
		cin >> musteri_no;

		cout << "Müþterinin adý \t : ";
		cin >> musteri_ad;
		cout << "Müþterinin soyadý \t : ";
		cin >> musteri_soyad;
		cout << "TC kimlik Numarasý \t : ";
		do
		{
			cin >> musteri_tc;
			if (musteri_tc.length() != 11)
			{
				cout << "lütfen 11 haneli TC kimlik numarasý giriniz : ";
			}
		} while (musteri_tc.length() != 11);
	} while (kontrolmusteri(musteri_no, musteri_tc));
	dosyaYazz << musteri_no << "\t" << musteri_ad << "\t" << musteri_soyad << "\t" << musteri_tc << "\n";
	dosyaYazz.close();
	system("cls");
	musteri_islemleri();
}

bool kontrolmusteri(string kontrol, string kontrol2)
{
	string kontrolno, kontrolad, kontrolsoyad, kontroltc;
	ifstream oku;
	oku.open("musteri.txt");
	while (!oku.eof())
	{
		oku >> kontrolno >> kontrolad >> kontrolsoyad >> kontroltc;
		if (oku.eof())	break;
		if (kontrol == kontrolno)
		{
			system("cls");
			cout << "Girilen müþteri numarasýna ait kayýt bulunmaktadýr!" << endl << endl;
			oku.close();
			system("pause");
			musteri_islemleri();
		}
		if (kontrol2 == kontroltc)
		{
			system("cls");
			cout << "Girilen Tc kimlik numarasýna ait kayýt bulunmaktadýr!" << endl << endl;
			oku.close();
			system("pause");
			musteri_islemleri();
		}
	}
	oku.close();
	return false;
}

void musteri_sil()
{
	system("cls");
	string no;
	cout << "Silinecek müþteri numarasýný giriniz : ";
	cin >> no;
	ifstream dosyaoku;
	dosyaoku.open("musteri.txt");
	ofstream dosyayaz;
	dosyayaz.open("yedekmusteri.txt");
	while (!dosyaoku.eof())
	{
		dosyaoku >> musteri_no >> musteri_ad >> musteri_soyad >> musteri_tc;
		if (no != musteri_no)
		{
			if (dosyaoku.eof())
			{
				break;
			}
			dosyayaz << musteri_no << "\t" << musteri_ad << "\t" << musteri_soyad << "\t" << musteri_tc << "\n";
		}
	}
	dosyayaz.close();
	dosyaoku.close();
	remove("musteri.txt");
	rename("yedekmusteri.txt", "musteri.txt");
	musteri_islemleri();
}

void musteri_sirala()
{
	system("cls");
	int a;
	ifstream dosyaoku;
	dosyaoku.open("musteri.txt");
	while (!dosyaoku.eof())
	{

		dosyaoku >> musteri_no >> musteri_ad >> musteri_soyad >> musteri_tc;
		if (dosyaoku.eof())
		{
			break;
		}
		cout << "Müþteri Numarasý : " << musteri_no << endl << "Müþteri Adý : " << musteri_ad << endl << "Müþteri Soyadý : " << musteri_soyad << endl << "Müþteri Tc : " << musteri_tc << endl << endl;
	}
	do
	{
		cout << "99 - Üst Menü : ";
		cin >> a;
		if (a != 99)
		{
			cout << "Lütfen tekrar deneyiniz..." << endl << endl;
		}
	} while (a != 99);
	dosyaoku.close();
	system("cls");
	musteri_islemleri();
}

void musteri_islemleri()
{
	do
	{
		system("cls");
		cout << "Müþteri Ýþlemleri" << endl;
		cout << "-------------------" << endl;
		cout << "1 - Müþteri ekle" << endl;
		cout << "2 - Müþteri Sil" << endl;
		cout << "3 - Müþteri Listele" << endl;
		cout << "99 - Üst Menü" << endl;
		cout << "Seçiminiz : ";
		cin >> secim2;
		if (secim2 == "1")
		{
			musteri_ekle();
		}
		else if (secim2 == "2")
		{
			musteri_sil();
		}
		else if (secim2 == "3")
		{
			musteri_sirala();
		}
		else if (secim2 == "99")
		{
			main();
		}
		else
		{
			system("cls");
			cout << "Hatalý Seçim" << endl;
			system("pause");
			system("cls");
		}
		system("cls");
	} while (secim2 != "1" && secim2 != "2" && secim2 != "3" && secim2 != "99");
}


bool kayitkontrol(string kontrol)
{
	ifstream oku;
	oku.open("oda_kayit.txt");
	while (!oku.eof())
	{
		oku >> odano >> odaucret >> musteri_no >> musteri_ad >> musteri_soyad >> musteri_tc;
		if (oku.eof()) break;
		if (kontrol == odano)
		{
			system("cls");
			cout << "Girdiðiniz odada müþteri bulunmaktadýr!..." << endl;
			system("pause");
			oku.close();
			oda_kayit_islemleri();
		}
	}
	oku.close();
	return true;
}

void oda_kayit_ekle()
{
	string secim_oda, secim_musteri;
	cout << "------ODALAR------" << endl;
	ifstream odaoku;
	odaoku.open("oda.txt");
	while (!odaoku.eof())
	{
		odaoku >> odano >> odaucret;
		if (odaoku.eof())		break;
		cout << endl << "Oda numarasý : " << odano << endl << "Oda ücreti   : " << odaucret << endl << "Oda durumu : " ;
		if (kayitodakontrol(odano))
		{
			cout << "boþ";
		}
		else
		{
			cout << "dolu";
		}
		cout << endl;
	}
	cout << endl;
	cout << "Oda numarasý seçiniz : ";
	cin >> secim_oda;
	kayitkontrol(secim_oda);
	system("cls");


	cout << "------MÜÞTERÝLER------" << endl;
	ifstream musterioku;
	musterioku.open("musteri.txt");
	while (!musterioku.eof())
	{
		musterioku >> musteri_no >> musteri_ad >> musteri_soyad >> musteri_tc;
		if (musterioku.eof())	break;
		cout << endl << "Müþteri Numarasý : " << musteri_no << endl << "Müþteri Adý : " << musteri_ad << endl << "Müþteri Soyadý : " << musteri_soyad << endl << "Müþteri Tc : " << musteri_tc << endl;
	}
	cout << endl << "Müþteri numarasý seçiniz : ";
	cin >> secim_musteri;
	system("cls");

	odaoku.close();
	musterioku.close();

	ifstream odayýoku;
	odayýoku.open("oda.txt");
	ifstream musteriyioku;
	musteriyioku.open("musteri.txt");
	ofstream yaz;
	yaz.open("oda_kayit.txt", ios::app);
	while (!odayýoku.eof())
	{
		odayýoku >> odano >> odaucret;
		if (odayýoku.eof())		break;
		if (secim_oda == odano)
		{
			yaz << odano << "\t" << odaucret << "\t";
			break;
		}
	}

	while (!musteriyioku.eof())
	{
		musteriyioku >> musteri_no >> musteri_ad >> musteri_soyad >> musteri_tc;
		if (musteriyioku.eof())	break;
		if (musteri_no == secim_musteri)
		{
			yaz << musteri_no << "\t" << musteri_ad << "\t" << musteri_soyad << "\t" << musteri_tc << "\n";
			break;
		}
	}

	yaz.close();
	odayýoku.close();
	musteriyioku.close();
	oda_kayit_islemleri();
}

bool kayitodakontrol(string kontrol2)
{
	ifstream oku;
	oku.open("oda_kayit.txt");
	while (!oku.eof())
	{
		oku >> odano >> odaucret >> musteri_no >> musteri_ad >> musteri_soyad >> musteri_tc;
		if (oku.eof()) break;
		if (kontrol2 == odano)
		{
			oku.close();
			return false;
		}
	}
	oku.close();
	return true;
}

void oda_kayitlari_listele()
{
	int a;
	ifstream oku;
	oku.open("oda_kayit.txt");
	cout << "-------KAYITLI ODALAR-------" << endl;
	while (!oku.eof())
	{
		oku >> odano >> odaucret >> musteri_no >> musteri_ad >> musteri_soyad >> musteri_tc;
		if (oku.eof()) break;
		cout << "Oda no \t\t  : " << odano << "\nOda ücreti \t  : " << odaucret << "\nMüþteri no \t  : " << musteri_no << "\nMüþteri adý-soyadý: " << musteri_ad << " " << musteri_soyad << "\nMüþteri TC\t  : " << musteri_tc << "\n----------------------------\n";
	}
	oku.close();
	do
	{
		cout << "99 - Üst Menü : ";
		cin >> a;
		if (a != 99)
		{
			cout << "Lütfen tekrar deneyiniz..." << endl << endl;
		}
	} while (a != 99);
	system("cls");
	oda_kayit_islemleri();
}

void oda_kayitlari_sil()
{
	string deger;
	cout << "Silinecek oda numasýný giriniz : ";
	cin >> deger;
	
	ifstream okuu;
	okuu.open("oda_kayit.txt");
	ofstream yaz;
	yaz.open("yedek_kayit.txt", ios::app);
	
	while (!okuu.eof())
	{
		okuu >> odano >> odaucret >> musteri_no >> musteri_ad >> musteri_soyad >> musteri_tc;	
		if (odano != deger)
		{
			if (okuu.eof())		break;
			yaz << odano << "\t" << odaucret << "\t" << musteri_no << "\t" << musteri_ad << "\t" << musteri_soyad << "\t" << musteri_tc << "\n";
		}	
	}
	yaz.close();
	okuu.close();
	remove("oda_kayit.txt");
	rename("yedek_kayit.txt", "oda_kayit.txt");
	oda_kayit_islemleri();
}


void oda_kayit_islemleri()
{
	do
	{
		system("cls");
		cout << "Oda Kayýt Ýþlemleri" << endl;
		cout << "-------------------" << endl;
		cout << "1 - Oda Kayýt ekle" << endl;
		cout << "2 - Oda Kayýt Sil" << endl;
		cout << "3 - Oda Kayýtlarý Listele" << endl;
		cout << "99 - Üst Menü" << endl;
		cout << "Seçiminiz : ";
		cin >> secim2;
		system("cls");
		if (secim2 == "1")
		{
			oda_kayit_ekle();
		}
		else if (secim2 == "2")
		{
			oda_kayitlari_sil();
		}
		else if (secim2 == "3")
		{
			oda_kayitlari_listele();
		}
		else if (secim2 == "99")
		{
			main();
		}
		else
		{
			system("cls");
			cout << "Hatalý Seçim" << endl;
			system("pause");
			system("cls");
		}
	} while (secim2 != "1" && secim2 != "2" && secim2 != "3" && secim2 != "99");
}

int main()
{
	setlocale(LC_ALL, "turkish");
	do
	{
		system("cls");
		cout << "Otel Ýþlemleri" << endl;
		cout << "-------------------" << endl;
		cout << "1 - Oda Ýþlemleri" << endl;
		cout << "2 - Müþteri Ýþlemleri" << endl;
		cout << "3 - Oda Kayýt Ýþlemleri" << endl;
		cout << "99 - Çýkýþ" << endl;
		cout << "Seçiminiz : ";
		cin >> secim;
		if (secim == "1")
		{
			oda_islemleri();
		}
		else if (secim == "2")
		{
			musteri_islemleri();
		}
		else if (secim == "3")
		{
			oda_kayit_islemleri();
		}
		else if (secim == "99")
		{

		}
		else
		{
			system("cls");
			cout << "Hatalý Seçim" << endl;
			system("pause");
			system("cls");
		}
	} while (secim != "1" && secim != "2" && secim != "3" && secim != "99");

	return 0;
}