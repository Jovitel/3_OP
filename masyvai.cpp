#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

const int MAX_ND = 100;

struct duomenys {
    duomenys() : nd(new int[MAX_ND]) {} 
    string vard, pav;
    int *nd;
    int egzaminas;
    int nd_kiekis;
    double gal_vid, gal_bal, gal_med;
};
void func_input_hands() {
    int m = 100, n = 0, pazymys, sum = 0, a, s;
    duomenys *studentai = new duomenys[m];

    while (n < m) {
        cout << "iveskite varda: " << endl;
        cin >> studentai[n].vard;
        cout << "iveskite pavarde: " << endl;
        cin >> studentai[n].pav;

        studentai[n].nd_kiekis = 0;

        cout << "iveskite namu darbu rezultatus (Įveskite 0, kai norite baigti): " << endl;
        while (cin >> pazymys && pazymys != 0) {
            if (pazymys < 1 || pazymys > 10) {
                cout << "Netinkamas pazymys, iveskite nauja: ";
                continue;
            }
            if (studentai[n].nd_kiekis < MAX_ND) {
                studentai[n].nd[studentai[n].nd_kiekis++] = pazymys;
            } else {
                cout << "Pasiekėte maksimalų namų darbų skaičių!" << endl;
                break;
            }
        }
        
        cout << "Iveskite egzamino rezultata: ";
        cin >> studentai[n].egzaminas;
        if (studentai[n].egzaminas < 1 || studentai[n].egzaminas > 10) {
            cout << "Netinkamas pazymys, iveskite nauja: ";
            cin >> studentai[n].egzaminas;
        }

        sum = 0;
        for (int i = 0; i < studentai[n].nd_kiekis; ++i) {
            sum += studentai[n].nd[i];
        }
        studentai[n].gal_vid = 0.4 * (static_cast<double>(sum) / studentai[n].nd_kiekis) + 0.6 * studentai[n].egzaminas;
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

   //mediana ir vidurkis
    for (int i = 0; i < n; i++) {
        int dydis;
        dydis = 1 + studentai[i].nd_kiekis;
        int *pazymiai = new int[dydis];
        pazymiai[0] = studentai[i].egzaminas;
        for (int j = 0; j < studentai[i].nd_kiekis; j++) {
            pazymiai[j + 1] = studentai[i].nd[j];
        }

        sort(pazymiai, pazymiai + dydis);

        if (dydis % 2 == 0) {
            studentai[i].gal_med = (pazymiai[dydis / 2 - 1] + pazymiai[dydis / 2]) / 2;
        } else {
            studentai[i].gal_med = pazymiai[dydis / 2];
        }

        delete[] pazymiai;
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

    for (int i = 0; i < n; ++i) {
        delete[] studentai[i].nd;
    }
    delete[] studentai;
}


void func_generate_numbers() {
    int m = 100, n = 0, pazymys, sum = 0, a, s;
    duomenys *studentai = new duomenys[m];

    srand(time(0)); // Paleidžiame tik vieną kartą programos paleidimo metu

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
            studentai[n].nd = new int[studentai[n].nd_kiekis];
            for (int j = 0; j < studentai[n].nd_kiekis; j++) {
                studentai[n].nd[j] = rand() % 11;
            }
            studentai[n].egzaminas = rand() % 11;
        } else if (a == 0) {
            cout << "iveskite namu darbu rezultatus (Įveskite 0, kai norite baigti): " << endl;
            while (cin >> pazymys && pazymys != 0) {
                if (pazymys < 1 || pazymys > 10) {
                    cout << "Netinkamas pazymys, iveskite nauja: ";
                    continue;
                }
                if (studentai[n].nd_kiekis < 100) {
                    studentai[n].nd[studentai[n].nd_kiekis++] = pazymys;
                } else {
                    cout << "Pasiekėte maksimalų namų darbų skaičių!" << endl;
                    break;
                }

                cout << "Iveskite egzamino rezultata: ";
                cin >> studentai[n].egzaminas;
                if (studentai[n].egzaminas < 1 || studentai[n].egzaminas > 10) {
                    cout << "Netinkamas pazymys, iveskite nauja: ";
                    continue;
                }
            }
        }

        sum = 0;
        for (int i = 0; i < studentai[n].nd_kiekis; ++i) {
            sum += studentai[n].nd[i];
        }
        studentai[n].gal_vid = 0.4 * (static_cast<double>(sum) / studentai[n].nd_kiekis) + 0.6 * studentai[n].egzaminas;
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

    // Print median or average
    for (int i = 0; i < n; i++) {
        int dydis;
        dydis = 1 + studentai[i].nd_kiekis;
        int *pazymiai = new int[dydis];
        pazymiai[0] = studentai[i].egzaminas;
        for (int j = 0; j < studentai[i].nd_kiekis; j++) {
            pazymiai[j + 1] = studentai[i].nd[j];
        }

        sort(pazymiai, pazymiai + dydis);

        if (dydis % 2 == 0) {
            studentai[i].gal_med = (pazymiai[dydis / 2 - 1] + pazymiai[dydis / 2]) / 2;
        } else {
            studentai[i].gal_med = pazymiai[dydis / 2];
        }

        delete[] pazymiai;
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

    for (int i = 0; i < n; ++i) {
        delete[] studentai[i].nd;
    }
    delete[] studentai;
}

void func_generate_names() {
    int m = 100, n = 0, pazymys, sum = 0, a, s, w;
    duomenys *studentai = new duomenys[m];
    string vard[] = {"Jonas", "Juozas", "Ona", "Teresė", "Eglė", "Antanas", "Inga", "Eva", "Irma", "Jurga"};
    string pav[] = {"Kazlauskas", "Lapas", "Mileris", "Bondas", "Jonienė", "Milerienė", "Davida", "Garci", "Tulpienė", "Martinesa"};

    srand(time(0)); // Paleidžiame tik vieną kartą programos paleidimo metu

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
                studentai[n].nd[j] = rand() % 11;
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
            studentai[n].nd = new int[studentai[n].nd_kiekis];
            for (int j = 0; j < studentai[n].nd_kiekis; j++) {
                studentai[n].nd[j] = rand() % 11;
            }
            studentai[n].egzaminas = rand() % 11;
        } else if (a == 0) {
            cout << "iveskite namu darbu rezultatus (Įveskite 0, kai norite baigti): " << endl;
            while (cin >> pazymys && pazymys != 0) {
                if (pazymys < 1 || pazymys > 10) {
                    cout << "Netinkamas pazymys, iveskite nauja: ";
                    continue;
                }
                if (studentai[n].nd_kiekis < 100) {
                    studentai[n].nd[studentai[n].nd_kiekis++] = pazymys;
                } else {
                    cout << "Pasiekėte maksimalų namų darbų skaičių!" << endl;
                    break;
                }

                cout << "Iveskite egzamino rezultata: ";
                cin >> studentai[n].egzaminas;
                if (studentai[n].egzaminas < 1 || studentai[n].egzaminas > 10) {
                    cout << "Netinkamas pazymys, iveskite nauja: ";
                    continue;
                }
            }
        }

        sum = 0;
        for (int i = 0; i < studentai[n].nd_kiekis; ++i) {
            sum += studentai[n].nd[i];
        }
        studentai[n].gal_vid = 0.4 * (static_cast<double>(sum) / studentai[n].nd_kiekis) + 0.6 * studentai[n].egzaminas;
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
        int dydis;
        dydis = 1 + studentai[i].nd_kiekis;
        int *pazymiai = new int[dydis];
        pazymiai[0] = studentai[i].egzaminas;
        for (int j = 0; j < studentai[i].nd_kiekis; j++) {
            pazymiai[j + 1] = studentai[i].nd[j];
        }

        sort(pazymiai, pazymiai + dydis);

        if (dydis % 2 == 0) {
            studentai[i].gal_med = (pazymiai[dydis / 2 - 1] + pazymiai[dydis / 2]) / 2;
        } else {
            studentai[i].gal_med = pazymiai[dydis / 2];
        }

        delete[] pazymiai;
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

    for (int i = 0; i < n; ++i) {
        delete[] studentai[i].nd;
    }
    delete[] studentai;
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