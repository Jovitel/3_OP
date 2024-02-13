#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <random>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;

const int N = 100;
const int MAX_ND = 10;
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

struct duomeny
{
<<<<<<< HEAD
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


void func()
{
=======
>>>>>>> v.pradinė
    int n, m, s;
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

    for (int i = 0; i <= n - 1; i++)
    {
        cout << "iveskite varda: " << endl;
        cin >> duomenys[i].vard;
        cout << "iveskite pavarde: " << endl;
        cin >> duomenys[i].pav;
        for (int j = 0; j <= m - 1; j++)
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
<<<<<<< HEAD
    cout << "Jei norite išvesti MEDIANĄ, įrašykite 1, o jei norite išvesti GALUTINĮ BALĄ, įrašykite 0" << endl;
=======
      cout << "Jei norite išvesti MEDIANĄ, įrašykite 1, o jei norite išvesti GALUTINĮ BALĄ, įrašykite 0" << endl;
>>>>>>> v.pradinė
    while (true)
    {
        cin >> s;
        if (cin.fail() || (s != 0 && s != 1))
        {
            cout << "Įrašėte netinkamą skaičių, rinkitės iš 1 ir 0: ";
<<<<<<< HEAD
            cin.clear();
            cin.ignore(10000, '\n');
=======
            cin.clear(); 
            cin.ignore(10000, '\n'); 
>>>>>>> v.pradinė
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

}
void func_a()
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
            }
        }
        cout << "Iveskite egzamino rezultata: ";
        cin >> studentai[n].egz;
        if (studentai[n].egz < 1 || studentai[n].egz > 10)
        {
            cout << "Netinkamas pazymys, iveskite nauja: ";
            continue;
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
}
void func_b()
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
}
int main()
{
    int pas;
    cout << "Pasirinkite: (1 - ranką, 2 - generuoti pažymius, 3 - generuoti ir pažymius ir studentų vardus, pavardės, 4 - baigti darbą)" << endl;
    cin >> pas;

    if (pas == 1)
    {
        func();

    }
    else if (pas == 2)
    {
        func_a();
    }
    else if (pas == 3)
    {
        func_b();
    }
    else if (pas == 4)
    {
        cout<<"Baigiama"<<endl;
    }
    return 0;
}