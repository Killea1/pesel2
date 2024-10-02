#include <iostream>
using namespace std;

/**************************************
* nazwa funkcji:        SprawdzeniePeselu
* opis funkcji:         Funkcja sprawdza czy podany pesel jest poprawny poprzez sprawdzenie liczby kontrolnej peselu
* parametry:            pesel - lancuch znakow ktory jest peselem 
* zwracany typ i opis:  bool zwraca "true" lub "false" zaleznie od tego czy podany pesel jest poprawny
* autor:                00000000000
**************************************/
bool SprawdzeniePeselu(string pesel)
{

    int S = 0;
    for (int i = 0; i <= 10; i++)
    {
        if (i == 0 || i == 4 || i == 8)
        {
            S = S + ((int)pesel[i]-48) * 1;
        }
        else if (i == 1 || i == 5 || i == 9)
        {
            S = S + ((int)pesel[i]-48) * 3;
        }

        else if (i == 2 || i == 6) {
            S = S + ((int)pesel[i]-48) * 7;
        }

        else if (i == 3 || i == 7)
        {
            S = S + ((int)pesel[i]-48) * 9;
        }
    }
    int M = S % 10;
    int R;
    if (M == 0)
    {
        R = 0;
    }
    else
    {
        R = 10 - M;
    }
    if ( R == ((int)pesel[10]-48))
    {
        return true;
    }
    else
    {
        return false;
    }

}




string SprawdzeniePlci(string pesel)
{
    if (pesel[9] % 2 == 0)
    {
        return "K";
    }
    else
    {
        return "M";
    }


}

int main()
{
    cout << "Podaj swoj pesel" << endl;
    string pesel;
    while (pesel.length() != 11)
    {
        cin >> pesel;
        if (pesel.length() < 11)
        {
            cout << "Podaj poprawny pesel (pesel jest za krotki)" << endl;
        }
        else if (pesel.length() > 11)
        {
            cout << "Podaj poprawny pesel (pesel jest za dlugi)" << endl;
        }
    }
    if (SprawdzeniePlci(pesel) == "K")
    {
        cout << "Kobieta" << endl;
    }
    else
    {
        cout << "Mezczyzna" << endl;
    }
    if (SprawdzeniePeselu(pesel) == true)
    {
        cout << "Pesel jest zgodny" << endl;
    }
    else
    {
        cout << "Pesel jest niezgodny" << endl;
    }
}

