#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

const int N = 100;
const int MAX_ND = 10;
struct duomeny
{
    string pav;
    string vard;
    int nd[MAX_ND];
    int nd_kiekis;
    int egz;
    int sum;
    double gal_vid;
    double gal_bal;
    int gal_med;
};
duomeny studentai[N];
int main()
{
    int m, s, a = 1, n = 0, pazymys, sum = 0, gen = 0;
    random_device rd;
    mt19937 gen(rd());
    while (a == 1 && n < 100)
    {
        cout << "iveskite varda: " << endl;
        cin >> studentai[n].vard;
        cout << "iveskite pavarde: " << endl;
        cin >> studentai[n].pav;
        
        cout<< "Ar norite, kad namų darbai būtu sugeneruoti? (taip - 1, ne - 0): "<<endl;
        cin>>gen;
         while (cin.fail() || (gen != 0 && gen != 1))
        {
            cout << "Ivestas netinkamas skaicius, rinkites is 1 ir 0: ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> gen;
        }
         if (gen == 1)
        {
            uniform_int_distribution<int> distrib(1, 10);

            for (int i = 0; i < MAX_ND; ++i)
            {
                studentai[n].nd[i] = distrib(gen); // Generuojame atsitiktinius namų darbų rezultatus
                studentai[n].nd_kiekis++;
            }
            studentai[n].egz = distrib(gen);
        }
        else if (gen == 0)
        {
            cout << "iveskite namu darbu rezultatus (Įveskite 0, kai norite baigti): " << endl;
            while (cin >> pazymys && pazymys != 0)
            {
                if (pazymys < 1 || pazymys > 10)
                {
                    cout << "Netinkamas pazymys, iveskite nauja: ";
                    continue;
                }
                if (studentai[n].nd_kiekis < 100)
                {
                    studentai[n].nd[studentai[n].nd_kiekis++] = pazymys; // Pridedame naują namų darbo rezultatą
                }
                else
                {
                    cout << "Pasiekėte maksimalų namų darbų skaičių!" << endl;
                    break;
                }

                cout << "Iveskite egzamino rezultata: ";
                cin >> studentai[n].egz;
                if (studentai[n].egz < 1 || studentai[n].egz > 10)
                {
                    cout << "Netinkamas pazymys, iveskite nauja: ";
                    continue;
                }
            }
        }
        

        for (int i = 0; i < studentai[n].nd_kiekis; ++i)
        {
            sum += studentai[n].nd[i];
        }
        studentai[n].gal_vid = 0.4 * (static_cast<double>(sum) / studentai[n].nd_kiekis) + 0.6 * studentai[n].egz;
        studentai[n].gal_bal = 0.4 * studentai[n].gal_vid + 0.6 * studentai[n].egz;
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
        dydis = 1 + studentai[i].nd_kiekis;
        int pazymiai[101];                         // Rezultatų masyvas, kuriame bus ir namų darbai, ir egzaminas
        pazymiai[0] = studentai[i].egz;             // Pirmas elementas yra egzaminas
        for (int j = 0; j < studentai[i].nd_kiekis; j++)
        {
            pazymiai[j + 1] = studentai[i].nd[j]; // Kiti elementai yra namų darbai
        }

        sort(pazymiai, pazymiai + dydis); // Surūšiuojame visus rezultatus

        if (dydis % 2 == 0) // Tikriname, ar rezultatų skaičius lyginis ar nelyginis
        {
            studentai[i].gal_med = (pazymiai[dydis / 2 - 1] + pazymiai[dydis / 2]) / 2;
        }
        else
        {
            studentai[i].gal_med = pazymiai[dydis / 2];
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
            cout << left << setw(20) << studentai[i].vard << setw(20) << studentai[i].pav << setw(10) << studentai[i].gal_med << endl;
        }

    }
    else if (s == 0)
    {
        cout << left << setw(20) << "VARDAS" << setw(20) << "PAVARDĖ" << setw(10) << "GALUTUNIS (VID.)" << endl;
        cout << "------------------------------------------------------------------------" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << left << setw(20) << studentai[i].vard << setw(20) << studentai[i].pav << setw(10) << studentai[i].gal_vid << endl;
        }
    }

    return 0;
}


