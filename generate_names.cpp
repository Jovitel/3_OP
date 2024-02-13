#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <iomanip>

using namespace std;

const int N = 100;
const int MAX_ND = 10;

struct pazy
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

string generuojami_vardai(const vector<string>& vard, const vector<string>& pav) 
{
    int first_index = rand() % vard.size();
    int last_index = rand() % pav.size();
    
    return vard[first_index] + " " + pav[last_index];
}

int main()
{
    vector<string> vard = {"Jonas", "Juozas", "Ona", "Teresė", "Eglė", "Antanas", "Inga", "Eva", "Irma", "Jurga"};
    vector<string> pav = {"Kazlauskas", "Lapas", "Mileris", "Bondas", "Jonienė", "Milerienė", "Davida", "Garci", "Tulpienė", "Martinesa"};
    int pazymys, s, gen, kiek, n;
    vector<pazy> duomenys;
    char tesis;
    
    // Seed the random number generator
    srand(time(nullptr));

    do
    {
        pazy naujas_studentas;
        cout<< "Ar norite, kad vardai ir pavardės būtu sugeneruoti? (taip - 1, ne - 0): "<<endl;
        cin>>gen;
        while (cin.fail() || (gen != 0 && gen != 1))
        {
            cout << "Ivestas netinkamas skaicius, rinkitės iš 1 ir 0: ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> gen;
        }
         if (gen == 1)
        {
            naujas_studentas.vard = generuojami_vardai(vard, pav);
            naujas_studentas.pav = generuojami_vardai(vard, pav);
        }
        else if (gen == 0)
        {
            cout << "Iveskite varda: ";
            cin >> naujas_studentas.vard;
            cout << "Iveskite pavarde: ";
            cin >> naujas_studentas.pav;
        }
        
        cout<< "Ar norite, kad namų darbai būtu sugeneruoti? (taip - 1, ne - 0): "<<endl;
        cin>>gen;
        while (cin.fail() || (gen != 0 && gen != 1))
        {
            cout << "Ivestas netinkamas skaicius, rinkitės iš 1 ir 0: ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> gen;
        }
        
        if (gen == 1)
        {
            uniform_int_distribution<int> distrib(1, 10);
            cout << "Kiek namų darbų rezultatų sugeneruoti? ";
            cin >> kiek;
            for (int i = 0; i < kiek; ++i)
            {
                int rezultatas = distrib(gen);
                naujas_studentas.nd.push_back(rezultatas); // Pridedame atsitiktinį rezultatą į vektorių
            }
            naujas_studentas.egz = distrib(gen);
        }
        else if (gen == 0)
        {
            cout << "Iveskite namu darbu rezultatus (iveskite 0, kai norite baigti): ";
            while (cin >> pazymys && pazymys != 0)
            {
                if (pazymys < 1 || pazymys > 10)
                {
                    cout << "Netinkamas pazymys, iveskite nauja: ";
                    continue;
                }
                naujas_studentas.nd.push_back(pazymys);

                cout << "Iveskite egzamino rezultata: ";
                cin >> naujas_studentas.egz;
                if (naujas_studentas.egz < 1 || naujas_studentas.egz > 10)
                {
                    cout << "Netinkamas pazymys, iveskite nauja: ";
                    continue;
                }

                duomenys.push_back(naujas_studentas);
            }
        }

        cout << "Ar norite įvesti dar vieną studentą? (T/N): ";
        cin >> tesis;
    } while (tesis == 'T' || tesis == 't');

    for (size_t i = 0; i < duomenys.size(); ++i)
    {
        // Skaičiuojame studento vidurkį ir galutinį balą
        int sum = 0;
        for (size_t j = 0; j < duomenys[i].nd.size(); ++j)
        {
            sum += duomenys[i].nd[j];
        }
        duomenys[i].sum = sum;
        duomenys[i].gal_vid = 0.4 * (static_cast<double>(sum) / duomenys[i].nd.size()) + 0.6 * duomenys[i].egz;
        duomenys[i].gal_bal = 0.4 * duomenys[i].gal_vid + 0.6 * duomenys[i].egz;
    }

    for (size_t i = 0; i < duomenys.size(); ++i)
    {
        vector<int> pazymiai; // Vektorius, kuriame bus saugomi visi namų darbų ir egzamino rezultatai
        pazymiai.push_back(duomenys[i].egz); // Pridedame egzamino rezultatą
        pazymiai.insert(pazymiai.end(), duomenys[i].nd.begin(), duomenys[i].nd.end()); // Pridedame namų darbų rezultatus

        sort(pazymiai.begin(), pazymiai.end()); // Surūšiuojame rezultatus

        int dydis = pazymiai.size();
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
    cin >> s;
    if (s == 1)
    {
        cout << left << setw(20) << "VARDAS" << setw(20) << "PAVARDĖ" << setw(15) << "GALUTINIS BALAS" << setw(15) << "GALUTINE MED." << endl;
        cout << "-------------------------------------------------------------------------" << endl;
        for (size_t i = 0; i < duomenys.size(); ++i)
        {
            cout << left << setw(20) << duomenys[i].vard << setw(20) << duomenys[i].pav << setw(15) << duomenys[i].gal_bal << setw(15) << duomenys[i].gal_med << endl;
        }

    }
    else if (s == 0)
    {
        cout << left << setw(20) << "VARDAS" << setw(20) << "PAVARDĖ" << setw(15) << "GALUTINIS BALAS" << setw(15) << "GALUTINE VID." << endl;
        cout << "-------------------------------------------------------------------------" << endl;
        for (size_t i = 0; i < duomenys.size(); ++i)
        {
            cout << left << setw(20) << duomenys[i].vard << setw(20) << duomenys[i].pav << setw(15) << duomenys[i].gal_bal << setw(15) << duomenys[i].gal_vid << endl;
        }
    }

    return 0;
}
