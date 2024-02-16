#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct duom
{
    string pav;
    string vard;
    vector<int> nd;
    int egz;
    int sum;
    double gal_vid;
    double gal_bal;
    int gal_med;
};

int main()
{
    vector<duom> duomenys;
    int n, m, s;

    cout << "keliu mokiniu skaiciuosite pazymius? " << endl;
    while (!(cin >> n) || n <= 0)
    {
        cout << "Netinkamas skaicius, iveskite nauja: ";
        cin.clear();            
        cin.ignore(10000, '\n');
    }

    cout << "kiek irasysite namu darbu rezultatu? " << endl;
    while (!(cin >> m) || m <= 0)
    {
        cout << "Netinkamas skaicius, iveskite nauja: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    duomenys.resize(n);

    for (int i = 0; i < n; i++)
    {
        cout << "iveskite varda: " << endl;
        cin >> duomenys[i].vard;
        cout << "iveskite pavarde: " << endl;
        cin >> duomenys[i].pav;
        duomenys[i].nd.resize(m);

        duomenys[i].sum = 0;
        for (int j = 0; j < m; j++)
        {
            cout << "iveskite " << j + 1 << " namu darbo rezultata (1-10): " << endl;
            while (!(cin >> duomenys[i].nd[j]) || duomenys[i].nd[j] < 1 || duomenys[i].nd[j] > 10)
            {
                cout << "Netinkamas skaicius, iveskite nauja: ";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            duomenys[i].sum += duomenys[i].nd[j];
        }
        cout << "iveskite egzamino rezultata (1-10): " << endl;
        while (!(cin >> duomenys[i].egz) || duomenys[i].egz < 1 || duomenys[i].egz > 10)
        {
            cout << "Netinkamas skaicius, iveskite nauja: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        duomenys[i].gal_vid = duomenys[i].sum / static_cast<double>(m);
        duomenys[i].gal_bal = 0.4 * duomenys[i].gal_vid + 0.6 * duomenys[i].egz;
    }

    for (int i = 0; i < n; i++)
    {
        vector<int> pazymiai = duomenys[i].nd;
        pazymiai.push_back(duomenys[i].egz);
        sort(pazymiai.begin(), pazymiai.end());

        int size = pazymiai.size();
        if (size % 2 == 0)
        {
            duomenys[i].gal_med = (pazymiai[size / 2 - 1] + pazymiai[size / 2]) / 2;
        }
        else
        {
            duomenys[i].gal_med = pazymiai[size / 2];
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
