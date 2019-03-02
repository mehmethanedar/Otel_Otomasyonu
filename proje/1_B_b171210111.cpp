/****************************************************************************
**					SAKARYA �N�VERS�TES�
**			         B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**				    B�LG�SAYAR M�HEND�SL��� B�L�M�
**				          PROGRAMLAMAYA G�R��� DERS�
**
**				�DEV NUMARASI.......:PROJE �DEV�
**				��RENC� ADI.........:Mehmet Nuri HANEDAR
**				��RENC� NUMARASI....:B171210111
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
		cout << "Oda numaras� giriniz \t :";
		cin >> odano;
		cout << endl << "Oda �creti giriniz \t :";
		cin >> odaucret;
	} while (kontrol(odano));
	dosyayaz << odano << "\t" << odaucret << "\n";
	dosyayaz.close();
	oda_islemleri();
}

//ayn� odadan var m� diye kontrol eder
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
			cout << "Girilen oda numaras�na ait oda bulunmaktad�r!" << endl;
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
	cout << "Silinecek oda numaras�n� giriniz : ";
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
		cout << "Oda numaras� : " << odano << endl << "Oda �creti   : " << odaucret << endl << endl;
	}
	do
	{
		cout << "99 - �st Men� : ";
		cin >> a;
		if (a != 99)
		{
			cout << "L�tfen tekrar deneyiniz..." << endl << endl;
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
		cout << "Oda ��lemleri" << endl;
		cout << "-------------------" << endl;
		cout << "1 - Oda ekle" << endl;
		cout << "2 - Oda Sil" << endl;
		cout << "3 - Odalar� Listele" << endl;
		cout << "99 - �st Men�" << endl;
		cout << "Se�iminiz : ";
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
			cout << "Hatal� Se�im" << endl;
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
		cout << "M��teri numaras� \t : ";
		cin >> musteri_no;

		cout << "M��terinin ad� \t : ";
		cin >> musteri_ad;
		cout << "M��terinin soyad� \t : ";
		cin >> musteri_soyad;
		cout << "TC kimlik Numaras� \t : ";
		do
		{
			cin >> musteri_tc;
			if (musteri_tc.length() != 11)
			{
				cout << "l�tfen 11 haneli TC kimlik numaras� giriniz : ";
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
			cout << "Girilen m��teri numaras�na ait kay�t bulunmaktad�r!" << endl << endl;
			oku.close();
			system("pause");
			musteri_islemleri();
		}
		if (kontrol2 == kontroltc)
		{
			system("cls");
			cout << "Girilen Tc kimlik numaras�na ait kay�t bulunmaktad�r!" << endl << endl;
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
	cout << "Silinecek m��teri numaras�n� giriniz : ";
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
		cout << "M��teri Numaras� : " << musteri_no << endl << "M��teri Ad� : " << musteri_ad << endl << "M��teri Soyad� : " << musteri_soyad << endl << "M��teri Tc : " << musteri_tc << endl << endl;
	}
	do
	{
		cout << "99 - �st Men� : ";
		cin >> a;
		if (a != 99)
		{
			cout << "L�tfen tekrar deneyiniz..." << endl << endl;
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
		cout << "M��teri ��lemleri" << endl;
		cout << "-------------------" << endl;
		cout << "1 - M��teri ekle" << endl;
		cout << "2 - M��teri Sil" << endl;
		cout << "3 - M��teri Listele" << endl;
		cout << "99 - �st Men�" << endl;
		cout << "Se�iminiz : ";
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
			cout << "Hatal� Se�im" << endl;
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
			cout << "Girdi�iniz odada m��teri bulunmaktad�r!..." << endl;
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
		cout << endl << "Oda numaras� : " << odano << endl << "Oda �creti   : " << odaucret << endl << "Oda durumu : " ;
		if (kayitodakontrol(odano))
		{
			cout << "bo�";
		}
		else
		{
			cout << "dolu";
		}
		cout << endl;
	}
	cout << endl;
	cout << "Oda numaras� se�iniz : ";
	cin >> secim_oda;
	kayitkontrol(secim_oda);
	system("cls");


	cout << "------M��TER�LER------" << endl;
	ifstream musterioku;
	musterioku.open("musteri.txt");
	while (!musterioku.eof())
	{
		musterioku >> musteri_no >> musteri_ad >> musteri_soyad >> musteri_tc;
		if (musterioku.eof())	break;
		cout << endl << "M��teri Numaras� : " << musteri_no << endl << "M��teri Ad� : " << musteri_ad << endl << "M��teri Soyad� : " << musteri_soyad << endl << "M��teri Tc : " << musteri_tc << endl;
	}
	cout << endl << "M��teri numaras� se�iniz : ";
	cin >> secim_musteri;
	system("cls");

	odaoku.close();
	musterioku.close();

	ifstream oday�oku;
	oday�oku.open("oda.txt");
	ifstream musteriyioku;
	musteriyioku.open("musteri.txt");
	ofstream yaz;
	yaz.open("oda_kayit.txt", ios::app);
	while (!oday�oku.eof())
	{
		oday�oku >> odano >> odaucret;
		if (oday�oku.eof())		break;
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
	oday�oku.close();
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
		cout << "Oda no \t\t  : " << odano << "\nOda �creti \t  : " << odaucret << "\nM��teri no \t  : " << musteri_no << "\nM��teri ad�-soyad�: " << musteri_ad << " " << musteri_soyad << "\nM��teri TC\t  : " << musteri_tc << "\n----------------------------\n";
	}
	oku.close();
	do
	{
		cout << "99 - �st Men� : ";
		cin >> a;
		if (a != 99)
		{
			cout << "L�tfen tekrar deneyiniz..." << endl << endl;
		}
	} while (a != 99);
	system("cls");
	oda_kayit_islemleri();
}

void oda_kayitlari_sil()
{
	string deger;
	cout << "Silinecek oda numas�n� giriniz : ";
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
		cout << "Oda Kay�t ��lemleri" << endl;
		cout << "-------------------" << endl;
		cout << "1 - Oda Kay�t ekle" << endl;
		cout << "2 - Oda Kay�t Sil" << endl;
		cout << "3 - Oda Kay�tlar� Listele" << endl;
		cout << "99 - �st Men�" << endl;
		cout << "Se�iminiz : ";
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
			cout << "Hatal� Se�im" << endl;
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
		cout << "Otel ��lemleri" << endl;
		cout << "-------------------" << endl;
		cout << "1 - Oda ��lemleri" << endl;
		cout << "2 - M��teri ��lemleri" << endl;
		cout << "3 - Oda Kay�t ��lemleri" << endl;
		cout << "99 - ��k��" << endl;
		cout << "Se�iminiz : ";
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
			cout << "Hatal� Se�im" << endl;
			system("pause");
			system("cls");
		}
	} while (secim != "1" && secim != "2" && secim != "3" && secim != "99");

	return 0;
}