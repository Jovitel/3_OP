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
    int nd;
    int egz;
    int sum;
    double gal_vid;
    double gal_bal;
    int gal_med;
};
duom duomenys[N];
int main()
{
    int n, sum = 0, m;
    cout << "keliu mokiniu skaiciuosite pazymius? " << endl;

    while (!(cin >> n) || n <= 0 || n > N)
    {
        cout << "Netinkamas skaicius, iveskite nauja: ";
        cin.clear();            //panaikina klaida ir galima vel priskirt
        cin.ignore(10000, '\n');
    }
    cout << "kiek irasysite namu darbu rezultatu? " << endl;

    while (!(cin >> m) || m <= 0 || m > N)
    {
        cout << "Netinkamas skaicius, iveskite nauja: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    for (int i = 0; i <= n-1; i++)
    {
        cout << "iveskite varda: " << endl;
        cin >> duomenys[i].vard;
        cout << "iveskite pavarde: " << endl;
        cin >> duomenys[i].pav;
        for (int j = 0; j <= m-1; j++)
        {
            cout << "iveskite namu darbu rezultatus (1-10): " << endl;
            while (!(cin >> duomenys[i].nd) || duomenys[i].nd < 1 || duomenys[i].nd > 10)
            {
                cout << "Netinkamas skaicius, iveskite nauja: ";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            duomenys[i].sum += duomenys[i].nd;
        }
        cout << "iveskite egzamino rezultata (1-10): " << endl;
        while (!(cin >> duomenys[i].egz) || duomenys[i].egz < 1 || duomenys[i].egz > 10)
        {
            cout << "Netinkamas skaicius, iveskite nauja: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        duomenys[i].gal_vid = duomenys[i].sum / m;
        duomenys[i].gal_bal = 0.4 * duomenys[i].gal_vid + 0.6 * duomenys[i].egz;
    }

    for (int i = 0; i <= n; i++)
    {
        vector<int> pazymiai;                 //sukuriamas vektorius, kuriame bus pazymiai visi
        pazymiai.push_back(duomenys[i].egz);  //idedami egzamino rezultatai
        for (int j = 0; j < m; j++)               //idedami namu darbu rezultatai
        {
            pazymiai.push_back(duomenys[i].nd);
        }

        sort(pazymiai.begin(), pazymiai.end()); //surusiuojam eiles tvarka

        int size = pazymiai.size();
        if (size % 2 == 0)                     //tikrina lyginis ar nelyginis skacius
        {
            duomenys[i].gal_med = (pazymiai[size / 2 - 1] + pazymiai[size / 2]) / 2;
        }
        else
        {
            duomenys[i].gal_med = pazymiai[size / 2];
        }
    }
    cout << left << setw(20) << "VARDAS" << setw(20) << "PAVARDĖ" << setw(16) << "GALUTINIS (VID.) " << setw(17) << "GALUTUNIS (MED.)" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    for (int i = 0; i <= n-1; i++)
    {
        cout << left << setw(20) << duomenys[i].vard << setw(20) << duomenys[i].pav << setw(16) << duomenys[i].gal_vid << setw(17) << duomenys[i].gal_med << endl;
    }

    return 0;
}
