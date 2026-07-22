#include <iostream>
#include <Windows.h>
#include <string>
#include <ios>     
#include <cstdio>

using namespace std;

int genislik = 51;
int cizgirenk = 14;
int aktifmi = 1;

void DuzCizgi(char karakter, int adet, int renk)
{
	HANDLE degisken = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(degisken, renk);

	cout << string(adet, karakter) << endl;
}
void Baslik(string metin, int adet, int renk, int cevre)
{
	HANDLE degisken = GetStdHandle(STD_OUTPUT_HANDLE);

	int harfsayisi = metin.length();
	int bosluk = adet - harfsayisi - 4;
	int yaribosluk = bosluk / 2;




	SetConsoleTextAttribute(degisken, cevre);
	cout << "||";
	SetConsoleTextAttribute(degisken, renk);
	cout << string(yaribosluk, ' ') << metin << string(yaribosluk, ' ');
	SetConsoleTextAttribute(degisken, cevre);
	cout << "||" << endl;
}
void SecenekYaz(string metin, int adet, int renk, int cevre, bool secilimi)
{
	HANDLE degisken = GetStdHandle(STD_OUTPUT_HANDLE);

	int harfsayisi = metin.length();
	int bosluk = adet - harfsayisi - 9;

	SetConsoleTextAttribute(degisken, cevre);



	SetConsoleTextAttribute(degisken, cevre);
	cout << "||  ";
	if (secilimi)
	{
		SetConsoleTextAttribute(degisken, 160);
		cout << " > " << metin << string(bosluk, ' ');
	}
	else
	{
		SetConsoleTextAttribute(degisken, renk);
		cout << "   " << metin << string(bosluk, ' ');
	}
	SetConsoleTextAttribute(degisken, cevre);
	cout << "||" << endl;
}
int KlavyeKontrol(int aktiflik, int maksimumsayi)
{
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		aktiflik--;
		if (aktiflik < 1) aktiflik = maksimumsayi;
		Sleep(150);
	}
	else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		aktiflik++;
		if (aktiflik > maksimumsayi) aktiflik = 1;
		Sleep(150
		);
	}

	return aktiflik;
}
int YaziStill(int disaridanGelenYaziRengi)
{
	int yaziaktifmi = 1;
	Sleep(200);

	while (true)
	{
		HANDLE degisken = GetStdHandle(STD_OUTPUT_HANDLE);

		COORD enUstKose = { 0, 0 };
		SetConsoleCursorPosition(degisken, enUstKose);

		DuzCizgi('-', genislik, cizgirenk);

		
		if (disaridanGelenYaziRengi == -1) {
			Baslik("Select Text Color", genislik, 4, cizgirenk);
		}
		else {
			Baslik("Select the Background Color", genislik, 4, cizgirenk);
		}

		DuzCizgi('-', genislik, cizgirenk);

		for (int i = 1; i <= 16; i++) {
			string renkIsimleri[] = {
				"Black", "Blue", "Green", "Aqua", "Red", "Purple", "Yellow", "White",
				"Gray", "Light Blue", "Light Green", "Light Aqua", "Light Red ", "Light Purple", "Light Yellow", "Bright White"
			};

			int gecerliRenkIndeksi = i - 1;
			int basilacakRenkKodu = gecerliRenkIndeksi;

			
			if (disaridanGelenYaziRengi != -1) {
				
				basilacakRenkKodu = (gecerliRenkIndeksi * 16) + disaridanGelenYaziRengi;
			}

			
			SecenekYaz(renkIsimleri[gecerliRenkIndeksi], genislik, basilacakRenkKodu, cizgirenk, (yaziaktifmi == i));
		}

		DuzCizgi('-', genislik, cizgirenk);

		yaziaktifmi = KlavyeKontrol(yaziaktifmi, 16);
		if (GetAsyncKeyState(VK_RETURN) & 0x8000)
		{
			break;
		}

		Sleep(10);
	}
	return yaziaktifmi;
}








int main()
{
	Sleep(100);
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	setvbuf(stdout, NULL, _IONBF, 0);


	int yaziaktifmi2;

	HANDLE degisken = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(degisken, &cursorInfo);
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(degisken, &cursorInfo);






	while (true)
	{
		COORD enUstKose = { 0, 0 };
		SetConsoleCursorPosition(degisken, enUstKose);


		DuzCizgi('=', genislik, cizgirenk);
		Baslik("CKColorFinder", genislik, 4, cizgirenk);
		DuzCizgi('=', genislik, cizgirenk);
		SecenekYaz("Without background", genislik, 2, cizgirenk, (aktifmi == 1));
		SecenekYaz("With background", genislik, 2, cizgirenk, (aktifmi == 2));
		DuzCizgi('=', genislik, cizgirenk);

		aktifmi = KlavyeKontrol(aktifmi, 2);
		if (GetAsyncKeyState(VK_RETURN) & 0x8000)
		{
			break;
		}

		Sleep(10);
	}



	system("cls");

	switch (aktifmi)
	{
	case 1: {

		yaziaktifmi2 = YaziStill(-1);
		int yazikod = yaziaktifmi2 - 1;
		string yazicevap = "CODE: " + to_string(yazikod);

		DuzCizgi('=', genislik, cizgirenk);
		Baslik(yazicevap, genislik, 4, cizgirenk);
		DuzCizgi('=', genislik, cizgirenk);
		Baslik("Your text will look like this", genislik, yazikod, cizgirenk);
		DuzCizgi('=', genislik, cizgirenk);
		break;
	}


	case 2: {

		
		int secilenYaziSatiri = YaziStill(-1);
		int gercekYaziKodu = secilenYaziSatiri - 1;

		
		int secilenArkaplanSatiri = YaziStill(gercekYaziKodu);
		int gercekArkaplanKodu = secilenArkaplanSatiri - 1;

	
		int toplamRenkKodu = (gercekArkaplanKodu * 16) + gercekYaziKodu;

		
		SetConsoleTextAttribute(degisken, 4);
		

		
		string kombinasyonCevap = "CODE: " + to_string(toplamRenkKodu);

	
		DuzCizgi('=', genislik, cizgirenk);
		Baslik(kombinasyonCevap, genislik, 4, cizgirenk);
		DuzCizgi('=', genislik, cizgirenk);
		Baslik("Your text will look like this", genislik, toplamRenkKodu, cizgirenk);
		DuzCizgi('=', genislik, cizgirenk);

		break;
	}




	}

	cursorInfo.bVisible = TRUE;
	SetConsoleCursorInfo(degisken, &cursorInfo);

	

	
	
	 


	cin.clear();
	cin.ignore(10000, '\n');

	system("pause");
	system("cls");
	return main();
}
