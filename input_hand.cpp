#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 100;
struct duom
{
    string pav;
    string vard;
    int nd[100];
    int nd_kiekis;
    int egz;
    int sum;
    double gal_vid;
    double gal_bal;
    int gal_med;
};
duom duomenys[N];
int main()
{
    int m, s, a = 1, n = 0, pazymys, sum = 0;
    while (a == 1 && n < 100)
    {
        cout << "iveskite varda: " << endl;
        cin >> duomenys[n].vard;
        cout << "iveskite pavarde: " << endl;
        cin >> duomenys[n].pav;
        
        cout << "iveskite namu darbu rezultatus (Įveskite 0, kai norite baigti): " << endl;
        while (cin >> pazymys && pazymys != 0)
        {
            if (pazymys < 1 || pazymys > 10)
            {
                cout << "Netinkamas pazymys, iveskite nauja: ";
                continue;
            }
            if (duomenys[n].nd_kiekis < 100)
            {
                duomenys[n].nd[duomenys[n].nd_kiekis++] = pazymys; // Pridedame naują namų darbo rezultatą
            }
            else
            {
                cout << "Pasiekėte maksimalų namų darbų skaičių!" << endl;
                break;
            }
        }
        cout << "Iveskite egzamino rezultata: ";
        cin >> duomenys[n].egz;
        if (duomenys[n].egz < 1 || duomenys[n].egz > 10)
        {
            cout << "Netinkamas pazymys, iveskite nauja: ";
            continue;
        }

        for (int i = 0; i < duomenys[n].nd_kiekis; ++i)
        {
            sum += duomenys[n].nd[i];
        }
        duomenys[n].gal_vid = 0.4 * (static_cast<double>(sum) / duomenys[n].nd_kiekis) + 0.6 * duomenys[n].egz;
        duomenys[n].gal_bal = 0.4 * duomenys[n].gal_vid + 0.6 * duomenys[n].egz;
        sum = 0; 

        // Pradedame naujo studento įrašymą arba baigiame įvedimą
        cout << "Jei vesite toliau, iveskite 1, jei norite uzbaigti iveskite 0: ";
        cin >> a;
        while (cin.fail() || (a != 0 && a != 1))
        {
            cout << "Ivestas netinkamas skaicius, rinkites is 1 ir 0: ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> a;
        }
        ++n;
        if (a == 0) // Jei pasirinko baigti, nutraukia ciklą
            break;
        
    }

    for (int i = 0; i <= n; i++)
    {
        int dydis;
        dydis = 1 + duomenys[i].nd_kiekis;
        int pazymiai[101];                         // Rezultatų masyvas, kuriame bus ir namų darbai, ir egzaminas
        pazymiai[0] = duomenys[i].egz;             // Pirmas elementas yra egzaminas
        for (int j = 0; j < duomenys[i].nd_kiekis; j++)
        {
            pazymiai[j + 1] = duomenys[i].nd[j]; // Kiti elementai yra namų darbai
        }

        sort(pazymiai, pazymiai + dydis); // Surūšiuojame visus rezultatus

        if (dydis % 2 == 0) // Tikriname, ar rezultatų skaičius lyginis ar nelyginis
        {
            duomenys[i].gal_med = (pazymiai[dydis / 2 - 1] + pazymiai[dydis / 2]) / 2;
        }
        else
        {
            duomenys[i].gal_med = pazymiai[dydis / 2];
        }
    }
    cout << "Jei norite išvesti MEDIANĄ, įrašykite 1, o jei norite išvesti GALUTINĮ BALĄ, įrašykite 0" << endl;
    while (true)
    {
        cin >> s;
        if (cin.fail() || (s != 0 && s != 1))
        {
            cout << "Įrašėte netinkamą skaičių, rinkitės iš 1 ir 0: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else
        {
            break;
        }
    }

    if (s == 1)
    {
        cout << left << setw(20) << "VARDAS" << setw(20) << "PAVARDĖ" << setw(10) << "GALUTUNIS (MED.)" << endl;
        cout << "------------------------------------------------------------------------" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << left << setw(20) << duomenys[i].vard << setw(20) << duomenys[i].pav << setw(10) << duomenys[i].gal_med << endl;
        }

    }
    else if (s == 0)
    {
        cout << left << setw(20) << "VARDAS" << setw(20) << "PAVARDĖ" << setw(10) << "GALUTUNIS (VID.)" << endl;
        cout << "------------------------------------------------------------------------" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << left << setw(20) << duomenys[i].vard << setw(20) << duomenys[i].pav << setw(10) << duomenys[i].gal_vid << endl;
        }
    }

    return 0;
}
