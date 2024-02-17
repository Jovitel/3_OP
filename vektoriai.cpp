#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <ctime>

using namespace std;

const int MAX_ND = 100;

struct duomenys {
    string vard, pav;
    vector<int> nd;
    int egzaminas;
    double gal_vid, gal_bal, gal_med;
    int nd_kiekis;
};

void func_input_hands() {
    int m = 100, n = 0, pazymys, sum = 0, a, s;
    vector<duomenys> studentai(m);

    while (n < m) {
        cout << "iveskite varda: " << endl;
        cin >> studentai[n].vard;
        cout << "iveskite pavarde: " << endl;
        cin >> studentai[n].pav;

        studentai[n].nd.clear();

        cout << "iveskite namu darbu rezultatus (Įveskite 0, kai norite baigti): " << endl;
        while (cin >> pazymys && pazymys != 0) {
            if (pazymys < 1 || pazymys > 10) {
                cout << "Netinkamas pazymys, iveskite nauja: ";
                continue;
            }
            studentai[n].nd.push_back(pazymys);
        }

        cout << "Iveskite egzamino rezultata: ";
        cin >> studentai[n].egzaminas;
        if (studentai[n].egzaminas < 1 || studentai[n].egzaminas > 10) {
            cout << "Netinkamas pazymys, iveskite nauja: ";
            cin >> studentai[n].egzaminas;
        }

        sum = accumulate(studentai[n].nd.begin(), studentai[n].nd.end(), 0);
        studentai[n].gal_vid = 0.4 * (static_cast<double>(sum) / studentai[n].nd.size()) + 0.6 * studentai[n].egzaminas;
        studentai[n].gal_bal = 0.4 * studentai[n].gal_vid + 0.6 * studentai[n].egzaminas;
        sum = 0;

        cout << "Jei vesite toliau, iveskite 1, jei norite uzbaigti iveskite 0: ";
        cin >> a;
        while (cin.fail() || (a != 0 && a != 1)) {
            cout << "Ivestas netinkamas skaicius, rinkites is 1 ir 0: ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> a;
        }
        ++n;
        if (a == 0)
            break;
    }

    for (int i = 0; i < n; i++) {
        vector<int> pazymiai = studentai[i].nd;

        sort(pazymiai.begin(), pazymiai.end());

        int dydis = pazymiai.size();
        if (dydis % 2 == 0) {
            studentai[i].gal_med = (pazymiai[dydis / 2 - 1] + pazymiai[dydis / 2]) / 2.0;
        } else {
            studentai[i].gal_med = pazymiai[dydis / 2];
        }
    }

    cout << "Jei norite išvesti MEDIANĄ, įrašykite 1, o jei norite išvesti GALUTINĮ BALĄ, įrašykite 0" << endl;
    while (true) {
        cin >> s;
        if (cin.fail() || (s != 0 && s != 1)) {
            cout << "Įrašėte netinkamą skaičių, rinkitės iš 1 ir 0: ";
            cin.clear();
            cin.ignore(10000, '\n');
        } else {
            break;
        }
    }

    if (s == 1) {
        cout << left << setw(20) << "VARDAS" << setw(20) << "PAVARDĖ" << setw(10) << "GALUTUNIS (MED.)" << endl;
        cout << "------------------------------------------------------------------------" << endl;
        for (int i = 0; i < n; i++) {
            cout << left << setw(20) << studentai[i].vard << setw(20) << studentai[i].pav << setw(10) << fixed << setprecision(2) << studentai[i].gal_med << endl;
        }
    } else if (s == 0) {
        cout << left << setw(20) << "VARDAS" << setw(20) << "PAVARDĖ" << setw(10) << "GALUTUNIS (VID.)" << endl;
        cout << "------------------------------------------------------------------------" << endl;
        for (int i = 0; i < n; i++) {
            cout << left << setw(20) << studentai[i].vard << setw(20) << studentai[i].pav << setw(10) << fixed << setprecision(2) << studentai[i].gal_vid << endl;
        }
    }
}

void func_generate_numbers() {
    int m = 100, n = 0, pazymys, sum = 0, a, s;
    vector<duomenys> studentai(m);

    srand(time(0)); 

    while (n < m) {
        cout << "iveskite varda: " << endl;
        cin >> studentai[n].vard;
        cout << "iveskite pavarde: " << endl;
        cin >> studentai[n].pav;

        cout << "Ar norite, kad namų darbai būtu sugeneruoti? (taip - 1, ne - 0): " << endl;
        cin >> a;
        while (cin.fail() || (a != 0 && a != 1)) {
            cout << "Ivestas netinkamas skaicius, rinkites is 1 ir 0: ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> a;
        }

        if (a == 1) {
            studentai[n].nd_kiekis = rand() % (MAX_ND + 1);
            for (int j = 0; j < studentai[n].nd_kiekis; j++) {
                studentai[n].nd.push_back(rand() % 11);
            }
            studentai[n].egzaminas = rand() % 11;
        } else if (a == 0) {
            cout << "iveskite namu darbu rezultatus (Įveskite 0, kai norite baigti): " << endl;
            while (cin >> pazymys && pazymys != 0) {
                if (pazymys < 1 || pazymys > 10) {
                    cout << "Netinkamas pazymys, iveskite nauja: ";
                    continue;
                }
                studentai[n].nd.push_back(pazymys);
            }

            cout << "Iveskite egzamino rezultata: ";
            cin >> studentai[n].egzaminas;
            if (studentai[n].egzaminas < 1 || studentai[n].egzaminas > 10) {
                cout << "Netinkamas pazymys, iveskite nauja: ";
                cin >> studentai[n].egzaminas;
            }
        }

        sum = accumulate(studentai[n].nd.begin(), studentai[n].nd.end(), 0);
        studentai[n].gal_vid = 0.4 * (static_cast<double>(sum) / studentai[n].nd.size()) + 0.6 * studentai[n].egzaminas;
        studentai[n].gal_bal = 0.4 * studentai[n].gal_vid + 0.6 * studentai[n].egzaminas;
        sum = 0;

        cout << "Jei vesite toliau, iveskite 1, jei norite uzbaigti iveskite 0: ";
        cin >> a;
        while (cin.fail() || (a != 0 && a != 1)) {
            cout << "Ivestas netinkamas skaicius, rinkites is 1 ir 0: ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> a;
        }
        ++n;
        if (a == 0)
            break;
    }

    for (int i = 0; i < n; i++) {
        vector<int> pazymiai = studentai[i].nd;

        sort(pazymiai.begin(), pazymiai.end());

        int dydis = pazymiai.size();
        if (dydis % 2 == 0) {
            studentai[i].gal_med = (pazymiai[dydis / 2 - 1] + pazymiai[dydis / 2]) / 2.0;
        } else {
            studentai[i].gal_med = pazymiai[dydis / 2];
        }
    }

    cout << "Jei norite išvesti MEDIANĄ, įrašykite 1, o jei norite išvesti GALUTINĮ BALĄ, įrašykite 0" << endl;
    while (true) {
        cin >> s;
        if (cin.fail() || (s != 0 && s != 1)) {
            cout << "Įrašėte netinkamą skaičių, rinkitės iš 1 ir 0: ";
            cin.clear();
            cin.ignore(10000, '\n');
        } else {
            break;
        }
    }

    if (s == 1) {
        cout << left << setw(20) << "VARDAS" << setw(20) << "PAVARDĖ" << setw(10) << "GALUTUNIS (MED.)" << endl;
        cout << "------------------------------------------------------------------------" << endl;
        for (int i = 0; i < n; i++) {
            cout << left << setw(20) << studentai[i].vard << setw(20) << studentai[i].pav << setw(10) << fixed << setprecision(2) << studentai[i].gal_med << endl;
        }
    } else if (s == 0) {
        cout << left << setw(20) << "VARDAS" << setw(20) << "PAVARDĖ" << setw(10) << "GALUTUNIS (VID.)" << endl;
        cout << "------------------------------------------------------------------------" << endl;
        for (int i = 0; i < n; i++) {
            cout << left << setw(20) << studentai[i].vard << setw(20) << studentai[i].pav << setw(10) << fixed << setprecision(2) << studentai[i].gal_vid << endl;
        }
    }
}

void func_generate_names() {
    int m = 100, n = 0, pazymys, sum = 0, a, s, w;
    vector<duomenys> studentai(m);
    string vard[] = {"Jonas", "Juozas", "Ona", "Teresė", "Eglė", "Antanas", "Inga", "Eva", "Irma", "Jurga"};
    string pav[] = {"Kazlauskas", "Lapas", "Mileris", "Bondas", "Jonienė", "Milerienė", "Davida", "Garci", "Tulpienė", "Martinesa"};

    srand(time(0)); 

    while (n < m) {
        cout << "Ar norite, kad vardai ir pavardės būtų sugeneruoti? (taip - 1, ne - 0): " << endl;
        cin >> w;
        while (cin.fail() || (w != 0 && w != 1)) {
            cout << "Ivestas netinkamas skaicius, rinkitės iš 1 ir 0: ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> w;
        }

        if (w == 1) {
            studentai[n].vard = vard[rand() % 10];
            studentai[n].pav = pav[rand() % 10];
            studentai[n].nd_kiekis = rand() % (MAX_ND + 1);
            for (int j = 0; j < studentai[n].nd_kiekis; j++) {
                studentai[n].nd.push_back(rand() % 11);
            }
        } else if (w == 0) {
            cout << "iveskite varda: " << endl;
            cin >> studentai[n].vard;
            cout << "iveskite pavarde: " << endl;
            cin >> studentai[n].pav;
        }

        cout << "Ar norite, kad namų darbai būtu sugeneruoti? (taip - 1, ne - 0): " << endl;
        cin >> a;
        while (cin.fail() || (a != 0 && a != 1)) {
            cout << "Ivestas netinkamas skaicius, rinkites is 1 ir 0: ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> a;
        }

        if (a == 1) {
            studentai[n].nd_kiekis = rand() % (MAX_ND + 1);
            for (int j = 0; j < studentai[n].nd_kiekis; j++) {
                studentai[n].nd.push_back(rand() % 11);
            }
            studentai[n].egzaminas = rand() % 11;
        } else if (a == 0) {
            cout << "iveskite namu darbu rezultatus (Įveskite 0, kai norite baigti): " << endl;
            while (cin >> pazymys && pazymys != 0) {
                if (pazymys < 1 || pazymys > 10) {
                    cout << "Netinkamas pazymys, iveskite nauja: ";
                    continue;
                }
                studentai[n].nd.push_back(pazymys);

                cout << "Iveskite egzamino rezultata: ";
                cin >> studentai[n].egzaminas;
                if (studentai[n].egzaminas < 1 || studentai[n].egzaminas > 10) {
                    cout << "Netinkamas pazymys, iveskite nauja: ";
                    continue;
                }
            }
        }

        sum = accumulate(studentai[n].nd.begin(), studentai[n].nd.end(), 0);
        studentai[n].gal_vid = 0.4 * (static_cast<double>(sum) / studentai[n].nd.size()) + 0.6 * studentai[n].egzaminas;
        studentai[n].gal_bal = 0.4 * studentai[n].gal_vid + 0.6 * studentai[n].egzaminas;
        sum = 0;

        cout << "Jei vesite toliau, iveskite 1, jei norite uzbaigti iveskite 0: ";
        cin >> s;
        while (cin.fail() || (s != 0 && s != 1)) {
            cout << "Ivestas netinkamas skaicius, rinkites is 1 ir 0: ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> s;
        }
        ++n;
        if (s == 0)
            break;
    }

    for (int i = 0; i < n; i++) {
        vector<int> pazymiai = studentai[i].nd;

        sort(pazymiai.begin(), pazymiai.end());

        int dydis = pazymiai.size();
        if (dydis % 2 == 0) {
            studentai[i].gal_med = (pazymiai[dydis / 2 - 1] + pazymiai[dydis / 2]) / 2.0;
        } else {
            studentai[i].gal_med = pazymiai[dydis / 2];
        }
    }

    cout << "Jei norite išvesti MEDIANĄ, įrašykite 1, o jei norite išvesti GALUTINĮ BALĄ, įrašykite 0" << endl;
    while (true) {
        cin >> s;
        if (cin.fail() || (s != 0 && s != 1)) {
            cout << "Įrašėte netinkamą skaičių, rinkitės iš 1 ir 0: ";
            cin.clear();
            cin.ignore(10000, '\n');
        } else {
            break;
        }
    }

    if (s == 1) {
        cout << left << setw(20) << "VARDAS" << setw(20) << "PAVARDĖ" << setw(10) << "GALUTUNIS (MED.)" << endl;
        cout << "------------------------------------------------------------------------" << endl;
        for (int i = 0; i < n; i++) {
            cout << left << setw(20) << studentai[i].vard << setw(20) << studentai[i].pav << setw(10) << fixed << setprecision(2) << studentai[i].gal_med << endl;
        }
    } else if (s == 0) {
        cout << left << setw(20) << "VARDAS" << setw(20) << "PAVARDĖ" << setw(10) << "GALUTUNIS (VID.)" << endl;
        cout << "------------------------------------------------------------------------" << endl;
        for (int i = 0; i < n; i++) {
            cout << left << setw(20) << studentai[i].vard << setw(20) << studentai[i].pav << setw(10) << fixed << setprecision(2) << studentai[i].gal_vid << endl;
        }
    }
}

int main() {
     int choice;

    cout << "Pasirinkite, kaip norite įvesti studentų duomenis: " << endl;
    cout << "1 - ranka" << endl;
    cout << "2 - sugeneruoti pažymius" << endl;
    cout << "3 - sugeneruoti pažymius ir vardus" << endl;
    cout << "4 - užbaigti programą" << endl;
    cin >> choice;

    while (cin.fail() || (choice < 1 || choice > 4)) {
        cout << "Netinkamas pasirinkimas. Įveskite 1, 2, 3 arba 4: ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> choice;
    }

    if (choice == 1) {
        func_input_hands();
    } else if (choice == 2) {
        func_generate_numbers();
    } else if (choice == 3) {
        func_generate_names();
    } else if (choice == 4) {
        cout<<"Užbaigėte";
    } 
    return 0;
}
