#include <iostream>
#define ERROR -1
using namespace std;

int dodawanieModuloN(int a, int b, int n)
{
	return ((a % n) + (b % n)) % n;
}

int mnozenieModuloN(int a, int b, int n)
{
	return ((a % n) * (b % n)) % n;
}

int znajdzElementPrzeciwny(int b, int n)
{
	b %= n;
	for (int i = 0; i < n; i++)
		if ((b + i) % n == 0)
			return i;
	return ERROR;
}

int odejmowanieModuloN(int a, int b, int n)
{
	int e = znajdzElementPrzeciwny(b, n);
	if (e == ERROR)
		return ERROR;
	else 
		return ((a % n) + e) % n;
}

int znajdzElementOdwortny(int b, int n)
{
	b %= n;
	for (int i = 0; i < n; i++)
		if ((b * i) % n == 1)
			return i;
	return ERROR;
}

int dzielenieModuloN(int a, int b, int n)
{
	int e = znajdzElementOdwortny(b, n);
	if (b == 0 || e == ERROR)
		return ERROR;
	else
		return ((a % n) * e) % n;
}

int main()
{
	int a, b, n, wynik;
	a = b = n = wynik = 0;
	char id;

	while (true)
	{
		cout << "a" << " = " << a << ", " << "b" << " = " << b << ", " << "n" << " = " << n <<"\n" 
			<<"Dostepne opcje:\n"
			<< "0. Wprowadz nowe liczby a, b, n,\n"
			<< "1. Dodawanie a+b modulo n,\n"
			<< "2. Mnozenie a*b modulo n,\n"
			<< "3. Odejmowanie a-b modulo n,\n"
			<< "4. Dzielenie a/b modulo n.\n"
			<< "5. Wyjscie\n"
			<< "Twoj wybor: ";
		cin >> id;

		switch (id)
		{
			case '0':
				cout << "Podaj liczby a, b, n: ";
				cin >> a >> b >> n;
				if (n == 1 || n == 0)
				{
					cout << "Dzialania nie maja sensu." << endl;
					cout << "Nacisnij Enter" << endl;
					cin.ignore().get();
				}
			case '1':
				wynik = dodawanieModuloN(a, b, n);
				cout << "Wynik dodawania " << a << "+" << b << " modulo " << n << ": ";
				break;
			case '2': wynik = mnozenieModuloN(a, b, n);
				cout << "Wynik mnozenia " << a << "*" << b << " modulo " << n << ": ";
				break;
			case '3': wynik = odejmowanieModuloN(a, b, n);
				cout << "Wynik odejmowania " << a << "-" << b << " modulo " << n << ": ";
				break;
			case '4': wynik = dzielenieModuloN(a, b, n);
				cout << "Wynik dzielenia " << a << "/" << b << " modulo " << n << ": ";
				break;
			case '5': return 0; break;
			default: break;
		}
		if (id == '0')
			system("cls");
		else if (wynik == ERROR)
		{
			cout << "Blad - dzialanie nie wykonalne." << endl;
			cout << "Nacisnij Enter" << endl;
			cin.ignore().get();
			system("cls");
		}
		else
		{
			cout << wynik << endl;
			cout << "Nacisnij Enter" << endl;
			cin.ignore().get();
			system("cls");
		}
	}
	return 0;
}