#include <iostream>

#define ERROR -1 //Wartoœæ zwracana w przypadku b³êdu

using namespace std;

long long int dodawanieModuloN(long long int a, long long int b, long long int n) //Funkcja zwracaj¹ca wartoœæ dodowania modulo n liczb a i b
{
	return ((a % n) + (b % n)) % n;
}

long long int mnozenieModuloN(long long int a, long long int b, long long int n) //Funkcja zwracaj¹ca wartoœæ mno¿enia modulo n liczb a i b
{
	return ((a % n) * (b % n)) % n;
}

long long int znajdzElementPrzeciwny(long long int b, long long int n) //Funkcja zwracaj¹ca wartoœæ elementu przeciwnego do b w zbiorze Zn
{
	b %= n;
	return (n - b);
}

long long int odejmowanieModuloN(long long int a, long long int b, long long int n) //Funkcja zwracaj¹ca wartoœæ dowania modulo n liczb a i -b
{
	long long int e = znajdzElementPrzeciwny(b, n);
	if (e == ERROR)
		return ERROR;
	else
		return dodawanieModuloN(a, e, n);
}

long long int znajdzElementOdwortny(long long int b, long long int n) //Funkcja zwracaj¹ca wartoœæ elementu odwrotnego do b w zbiorze Zn (jeœli istnieje)
{
	b %= n;
	/*for (long long int i = 0; i < n; i++)
		if (mnozenieModuloN(b, i, n) == 1)
			return i;*/
	long long int u = 1, w = b, x = 0, z = n, temp;
	while (w != 0)
	{
		if (w < z)
		{
			temp = u; u = x; x = temp;
			temp = w; w = z; z = temp;
		}
		temp = w / z;
		u -= temp*x;
		w -= temp*z;
	}
	if (z == 1)
	{
		if (x < 0) x += n;
		return x;
	}
	else return ERROR;
	
}

long long int dzielenieModuloN(long long int a, long long int b, long long int n) //Funkcja zwracaj¹ca wartoœæ mno¿enia modulo n liczb a i b^(-1)
{
	if (b == 0)
		return ERROR;
	long long int e = znajdzElementOdwortny(b, n);
	if (e == ERROR)
		return ERROR;
	else
		return mnozenieModuloN(a, e, n);
}

void wyswietlWyniki(long long int a, long long int b, long long int n) //Funkcja wyœwietlaj¹ca wyniki wszystkich mo¿liwych dzia³añ modulo n na liczbach a i b
{
	long long int wynik;
	for (int i = 0; i < 4; i++)
	{
		switch (i)
		{
		case 0: wynik = dodawanieModuloN(a, b, n); cout << "Wynik dodawania modulo " << n << " " << a << "+" << b << " = "; break;
		case 1: wynik = mnozenieModuloN(a, b, n); cout << "Wynik mnodzenia modulo " << n << " " << a << "*" << b << " = "; break;
		case 2: wynik = odejmowanieModuloN(a, b, n); cout << "Wynik dodawania modulo " << n << " " << a << "+(-" << b << ") = "; break;
		case 3: wynik = dzielenieModuloN(a, b, n); cout << "Wynik mnozenia modulo " << n << " " << a << "*" << b << "^(-1) = "; break;
		}
		if (wynik == ERROR)
			cout << "Blad - dzialania nie da sie wykonac" << endl;
		else
			cout << wynik << endl;
	}
	return;
}

int main()
{
	long long int a, b, n;
	a = b = n = 0;
	char id;

	do
	{
		cout << "Dostepne opcje:\n"
			<< "i - Wprowadz nowe liczby a, b, n,\n"
			<< "q - Wyjscie.\n"
			<< "Wybor: ";
		cin >> id;

		switch (id)
		{
			case 'i':
				cout << "Podaj liczby a b n: ";
				cin >> a >> b >> n;
				if (n <= 1 || a < 0 || b < 0) //Sprawdzenie czy mo¿na wykonaæ dzia³ania na liczbach podanych przez u¿ytkownika
					cout << "Dzialania nie maja sensu." << endl;
				else
					wyswietlWyniki(a, b, n);
				break;
			case 'q': break;
			default:
				cout << "Nieznana komenda" << endl;
				continue; break;
		}
	} while (id != 'q');
	return 0;
}