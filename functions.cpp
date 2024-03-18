#include "functions.h"

void func_input_hands() {
    int m = 100, n = 0, pazymys, sum = 0, a, s;
    vector<duomenys> studentai(m);

    while (n < m) {
        cout << "iveskite varda: " << endl;
        cin >> studentai[n].vard;
        cout << "iveskite pavarde: " << endl;
        cin >> studentai[n].pav;

        studentai[n].nd.clear();

        cout << "Įveskite namų darbų rezultatus (Įveskite 0, kai norite baigti): " << endl;
        while (cin >> pazymys && pazymys != 0) {
            if (pazymys < 1 || pazymys > 10) {
                cout << "Netinkamas pažymys, įveskite naują: ";
                continue;
            }
            studentai[n].nd.push_back(pazymys);
        }

        cout << "Įveskite egzamino rezultatą: ";
        cin >> studentai[n].egzaminas;
        if (studentai[n].egzaminas < 1 || studentai[n].egzaminas > 10) {
            cout << "Netinkamas pažymys, įveskite naują: ";
            cin >> studentai[n].egzaminas;
        }

        sum = accumulate(studentai[n].nd.begin(), studentai[n].nd.end(), 0);
        studentai[n].gal_vid = 0.4 * (static_cast<double>(sum) / studentai[n].nd.size()) + 0.6 * studentai[n].egzaminas;
        studentai[n].gal_bal = 0.4 * studentai[n].gal_vid + 0.6 * studentai[n].egzaminas;
        sum = 0;

        cout << "Jei vesite toliau, įveskite 1, jei norite užbaigti įveskite 0: ";
        cin >> a;
        while (cin.fail() || (a != 0 && a != 1)) {
            cout << "Įvestas netinkamas skaičius, rinkitės iš 1 ir 0: ";
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
        cout << "Įveskite vardą: " << endl;
        cin >> studentai[n].vard;
        cout << "Įveskite pavardę: " << endl;
        cin >> studentai[n].pav;

        cout << "Ar norite, kad namų darbai būtu sugeneruoti? (taip - 1, ne - 0): " << endl;
        cin >> a;
        while (cin.fail() || (a != 0 && a != 1)) {
            cout << "Įvestas netinkamas skaičius, rinkitės iš 1 ir 0: ";
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
            cout << "Įveskite namų darbų rezultatus (Įveskite 0, kai norite baigti): " << endl;
            while (cin >> pazymys && pazymys != 0) {
                if (pazymys < 1 || pazymys > 10) {
                    cout << "Netinkamas pažymys, įveskite naują: ";
                    continue;
                }
                studentai[n].nd.push_back(pazymys);
            }

            cout << "Įveskite egzamino rezultatą: ";
            cin >> studentai[n].egzaminas;
            if (studentai[n].egzaminas < 1 || studentai[n].egzaminas > 10) {
                cout << "Netinkamas pažymys, įveskite naują: ";
                cin >> studentai[n].egzaminas;
            }
        }

        sum = accumulate(studentai[n].nd.begin(), studentai[n].nd.end(), 0);
        studentai[n].gal_vid = 0.4 * (static_cast<double>(sum) / studentai[n].nd.size()) + 0.6 * studentai[n].egzaminas;
        studentai[n].gal_bal = 0.4 * studentai[n].gal_vid + 0.6 * studentai[n].egzaminas;
        sum = 0;

        cout << "Jei vesite toliau, įveskite 1, jei norite užbaigti įveskite 0: ";
        cin >> a;
        while (cin.fail() || (a != 0 && a != 1)) {
            cout << "Įvestas netinkamas skaičius, rinkitės iš 1 ir 0: ";
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
            cout << "Įvestas netinkamas skaičius, rinkitės iš 1 ir 0: ";
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
            cout << "Įveskite vardą: " << endl;
            cin >> studentai[n].vard;
            cout << "Įveskite pavardę: " << endl;
            cin >> studentai[n].pav;
        }

        cout << "Ar norite, kad namų darbai būtu sugeneruoti? (taip - 1, ne - 0): " << endl;
        cin >> a;
        while (cin.fail() || (a != 0 && a != 1)) {
            cout << "Įvestas netinkamas skaičius, rinkitės iš 1 ir 0: ";
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
            cout << "įveskite namų darbų rezultatus (Įveskite 0, kai norite baigti): " << endl;
            while (cin >> pazymys && pazymys != 0) {
                if (pazymys < 1 || pazymys > 10) {
                    cout << "Netinkamas pažymys, įveskite naują: ";
                    continue;
                }
                studentai[n].nd.push_back(pazymys);

                cout << "Įveskite egzamino rezultatą: ";
                cin >> studentai[n].egzaminas;
                if (studentai[n].egzaminas < 1 || studentai[n].egzaminas > 10) {
                    cout << "Netinkamas pažymys, įveskite naują: ";
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

void func_input_file() {
    try {
        int s, rez;
        vector<duomenys> studentai;
        string line;
        duomenys studentas;
        int choice = 0;
        
        cout << "KURI FAILĄ NAUDOTI: " << endl;
        cout << "kursiokai.txt - 1 " << endl;
        cout << "studentai10000.txt - 2 " << endl;
        cout << "studentai100000 - 3" << endl;
        cout << "studentai1000000 - 4" << endl;
        cin >> choice;
        while (cin.fail() || (choice < 1 || choice > 4)) {
            cout << "Netinkamas pasirinkimas. Įveskite 1, 2, 3 arba 4: ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> choice;
        }

        string file_name;
        switch (choice) {
            case 1:
                file_name = "C:/Users/JV/Desktop/nuskaitymui/kursiokai.txt";
                break;
            case 2:
                file_name = "C:/Users/JV/Desktop/nuskaitymui/studentai10000.txt";
                break;
            case 3:
                file_name = "C:/Users/JV/Desktop/nuskaitymui/studentai100000.txt";
                break;
            case 4:
                file_name = "C:/Users/JV/Desktop/nuskaitymui/studentai1000000.txt";
                break;
        }
      
        ifstream fd(file_name); // Atidarome pasirinktą failą

        // Patikriname, ar failas buvo sėkmingai atidarytas
        if (!fd.is_open()) {
            throw runtime_error("Nepavyko atidaryti failo!");
        }
        
        bool firstLine = true; // Kintamasis, nurodantis, ar tai pirmoji eilutė

        // Skaitome duomenis iš failo
        auto start = chrono::steady_clock::now();
        while (getline(fd, line)) {
            if (firstLine) {
                firstLine = false;
                continue; // Praleidžiame pirmą eilutę
            }

            istringstream iss(line);
            iss >> studentas.vard >> studentas.pav;

            int pazymys;
            while (iss >> pazymys) {
                studentas.nd.push_back(pazymys);
            }

            // Skaitome egzamino rezultatą
            iss.clear();
            iss >> studentas.egzaminas;

            studentai.push_back(studentas);
        }

        fd.close();
          auto end = chrono::steady_clock::now(); // Baigiame matuoti laiką sekundemis
            cout << "Failo nuskaitymo laikas: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl; // Išvedame laiką į ekraną

        // Skaičiuojame medianą ir vidurkį
        for (int i = 0; i < studentai.size(); ++i) {
            //cout<<"skaiciuojama"<<endl;
            vector<int> pazymiai = studentai[i].nd;
            sort(pazymiai.begin(), pazymiai.end());

            int dydis = pazymiai.size();
            if (!pazymiai.empty()) {
                if (dydis % 2 == 0) {
                    int middle1 = dydis / 2 - 1;
                    int middle2 = dydis / 2;
                    studentai[i].gal_med = (pazymiai[middle1] + pazymiai[middle2]) / 2.0;
                } else {
                    int middle = dydis / 2;
                    studentai[i].gal_med = pazymiai[middle];
                }
            } else {
                // Tvarkome atvejį, kai nėra įvertinimų
                studentai[i].gal_med = 0.0; // arba kita tinkama vertė
            }

            double sum = accumulate(pazymiai.begin(), pazymiai.end(), 0.0);
            studentai[i].gal_vid = 0.4 * (sum / pazymiai.size()) + 0.6 * studentai[i].egzaminas;
        }

        int choicee = 0;
        cout << "RYKIUOTI PAGAL: " << endl;
        cout << "vardą - 1 " << endl;
        cout << "pavardę - 2" << endl;
        cout << "Pagal vidurkį - 3" << endl;
        cout << "Pagal mediana - 4" << endl;
        cin >> choicee;
        while (cin.fail() || (choicee < 1 || choicee > 4)) {
            cout << "Netinkamas pasirinkimas. Įveskite 1, 2, 3 arba 4: ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> choicee;
        }

        switch (choicee) {
            case 1:
                sort(studentai.begin(), studentai.end(), [](const duomenys &a, const duomenys &b) {
                    return a.vard < b.vard;
                });
                break;
            case 2:
                sort(studentai.begin(), studentai.end(), [](const duomenys &a, const duomenys &b) {
                    return a.pav < b.pav;
                });
                break;
            case 3:
                sort(studentai.begin(), studentai.end(), [](const duomenys &a, const duomenys &b) {
                    return a.gal_vid > b.gal_vid;
                });
                break;
            case 4:
                sort(studentai.begin(), studentai.end(), [](const duomenys &a, const duomenys &b) {
                    return a.gal_med > b.gal_med;
                });
                break;
        }

        cout << "Jei rezultatus norite išvesti ekrane spauskite 1," << endl;
        cout << " o jei norite išvesti į failą (rezultatai.txt), spauskite 0" << endl;
        // Išvedame rezultatus į failą arba į konsolę
        ofstream fdd("C:/Users/JV/Desktop/nuskaitymui/rezultatai.txt");
        while (true) {
            cin >> rez;
            if (cin.fail() || (rez != 0 && rez != 1)) {
                cout << "Įrašėte netinkamą skaičių, rinkitės iš 1 ir 0: ";
                cin.clear();
                cin.ignore(10000, '\n');
            } else {
                break;
            }
        }

        cout << "Pasirinkite, ar norite išvesti medianą (1) ar vidurkį (0): ";
        cin >> s;
        while (cin.fail() || (s != 0 && s != 1)) {
            cout << "Netinkamas pasirinkimas. Įveskite 1 arba 0: ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> s;
        }

        if (rez == 1) {
            if (s == 1) {
                cout << left << setw(20) << "VARDAS" << setw(20) << "PAVARDĖ" << setw(20) << "GALUTUNIS (MED.)" << endl;
                cout << "------------------------------------------------------------------------" << endl;
                for (int i = 0; i < studentai.size(); i++) {
                    cout << left << setw(20) << studentai[i].vard << setw(20) << studentai[i].pav << setw(20) << fixed << setprecision(2) << studentai[i].gal_med << endl;
                }
            } else if (s == 0) {
                cout << left << setw(20) << "VARDAS" << setw(20) << "PAVARDĖ" << setw(20) << "GALUTUNIS (VID.)" << endl;
                cout << "------------------------------------------------------------------------" << endl;
                for (int i = 0; i < studentai.size(); i++) {
                    cout << left << setw(20) << studentai[i].vard << setw(20) << studentai[i].pav << setw(20) << fixed << setprecision(2) << studentai[i].gal_vid << endl;
                }
            }
        } else if (rez == 0) {
            if (s == 1) {
                fdd << left << setw(20) << "VARDAS" << setw(20) << "PAVARDĖ" << setw(20) << "GALUTUNIS (MED.)" << endl;
                fdd << "------------------------------------------------------------------------" << endl;
                for (int i = 0; i < studentai.size(); i++) {
                    fdd << left << setw(20) << studentai[i].vard << setw(20) << studentai[i].pav << setw(20) << fixed << setprecision(2) << studentai[i].gal_med << endl;
                }
            } else if (s == 0) {
                fdd << left << setw(20) << "VARDAS" << setw(20) << "PAVARDĖ" << setw(20) << "GALUTUNIS (VID.)" << endl;
                fdd << "------------------------------------------------------------------------" << endl;
                for (int i = 0; i < studentai.size(); i++) {
                    fdd << left << setw(20) << studentai[i].vard << setw(20) << studentai[i].pav << setw(20) << fixed << setprecision(2) << studentai[i].gal_vid << endl;
                }
            }
        }
        fdd.close();
    } catch (const exception &e) {
        cerr << "Klaida: " << e.what() << endl;
    }
}

void generate_new_file() {
     string filename;
    cout << "Iveskite failo pavadinima: ";
    cin >> filename;

    int numStudents, numMarks;

    cout << "Iveskite mokiniu skaiciu: ";
    cin >> numStudents;

    cout << "Iveskite pazymiu skaiciu: ";
    cin >> numMarks;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10);

    auto start = chrono::steady_clock::now(); // Pradedame matuoti laiką

    ofstream sortedFile(filename);

    sortedFile << "Vardas\tPavarde";
    for (int i = 1; i <= numMarks; ++i) {
        sortedFile << "\tND" << i;
    }
    sortedFile << "\tEgz." << endl;

    vector<duomenys> students;

    for (int i = 1; i <= numStudents; ++i) {
        duomenys student;
        student.vard = "Vardas" + to_string(i);
        student.pav = "Pavarde" + to_string(i);
        student.nd.resize(numMarks);
        for (int& mark : student.nd) {
            mark = dis(gen);
        }
        student.egzaminas = dis(gen);

        students.push_back(student);
    }

    // Rikiuojame studentus pagal galutinį vidurkį didėjančia tvarka
    sort(students.begin(), students.end(), [](const duomenys& a, const duomenys& b) {
        return a.egzaminas < b.egzaminas;
    });

    // Įrašome išrikiuotus duomenis į failą
    for (const auto& student : students) {
        sortedFile << student.vard << "\t" << student.pav;
        for (int mark : student.nd) {
            sortedFile << "\t" << mark;
        }
        sortedFile << "\t" << student.egzaminas << endl;
    }

    sortedFile.close();
    auto end_read = chrono::steady_clock::now();
    auto duration_read = chrono::duration_cast<chrono::milliseconds>(end_read - start);
    double seconds_read = duration_read.count() / 1000.0; // Konvertuojame milisekundes į sekundes
    cout << "Failo kurimas ir jo uzdarymas:  " << seconds_read << " s" << endl;
   
}

void use_existing_file() {
    auto startt = chrono::steady_clock::now(); // Baigiame matuoti laiką sekundėmis
    string file_name;
    cout << "Kuri faila norite nuskaityti? " << endl;
    cin >> file_name;
     ifstream fd(file_name); // Atidarome pasirinktą failą

    vector<duomenys> students;
    string line;
    int numMarks = 0; // Kintamasis saugantis namų darbų skaičių

    // Skaitome duomenis iš failo
    auto start_read = chrono::steady_clock::now(); // Pradedame matuoti laiką
    while (getline(fd, line)) {
        istringstream iss(line);
        duomenys student;

        // Nuskaitome vardą ir pavardę
        iss >> student.vard >> student.pav;

        // Nuskaitome namų darbų skaičių iš pirmosios eilutės
        if (numMarks == 0) {
            string mark;
            while (iss >> mark) {
                if (mark != "Vardas" && mark != "Pavarde") {
                    if (mark != "Egz.") {
                        numMarks++;
                    }
                }
            }
            continue; // Praleidžiame pirmą eilutę
        }

        // Nuskaitome namų darbus
        for (int i = 0; i < numMarks; ++i) {
            int mark;
            iss >> mark;
            student.nd.push_back(mark);
        }

        // Nuskaitome egzamino rezultatą
        iss >> student.egzaminas;

        // Apskaičiuojame galutinį vidurkį
        student.gal_vid = 0.4 * (accumulate(student.nd.begin(), student.nd.end(), 0.0) / numMarks) + 0.6 * student.egzaminas;

        students.push_back(student);
    }
    auto end_read = chrono::steady_clock::now(); // Baigiame matuoti laiką sekundėmis
    auto duration_read1 = chrono::duration_cast<chrono::milliseconds>(end_read - start_read);
    double seconds_read1 = duration_read1.count() / 1000.0; // Konvertuojame milisekundes į sekundes
    cout << "Duomenu nuskaitymas is failo:  " << seconds_read1 << " s" << endl;

    fd.close();

    // Rikiuojame studentus pagal galutinį vidurkį didėjančia tvarka
    auto start_sort = chrono::steady_clock::now(); // Pradedame matuoti laiką
    sort(students.begin(), students.end(), [](const duomenys& a, const duomenys& b) {
        return a.gal_vid > b.gal_vid; // Rūšiuojame nuo didžiausio iki mažiausio galutinio balo
    });
    for (auto& student : students) {
        student.rusis = (student.gal_vid >= 5.0) ? "kietiakas" : "vargsiukas";
    }
    auto end_sort = chrono::steady_clock::now(); // Baigiame matuoti laiką
    auto duration_sort = chrono::duration_cast<chrono::milliseconds>(end_sort - start_sort);
    double seconds_sort = duration_sort.count() / 1000.0; // Konvertuojame milisekundes į sekundes
    cout << "Studentu rusiavimas i dvi grupes:  " << seconds_sort << " s" << endl;

     // Sukurkime naujus konteinerius kietuoliams ir vargsiukams
    vector<duomenys> kietiakai;
    vector<duomenys> vargsiukai;

    // Perskirstome studentus į kietuolius ir vargsiukus
    auto start_split = chrono::steady_clock::now(); // Pradedame matuoti laiką
    for (const auto& student : students) {
        if (student.gal_vid >= 5.0) {
            kietiakai.push_back(student);
        } else {
            vargsiukai.push_back(student);
        }
    }
    
    // Išvedame kietuolius ir vargsiukus į atskirus failus
    ofstream kietiakaiFile("kietiakai_" + file_name + ".txt");
    ofstream vargsiukaiFile("vargsiukai_" + file_name + ".txt");

    // Pirmiausia išvedame antrą eilutę
    kietiakaiFile << "Vardas" << "\t" << "Pavarde";
    vargsiukaiFile << "Vardas" << "\t" << "Pavarde";
    auto start_output = chrono::steady_clock::now(); // Pradedame matuoti laiką
    for (int i = 1; i <= numMarks; ++i) {
        kietiakaiFile << "\tND" << i;
        vargsiukaiFile << "\tND" << i;
    }
    kietiakaiFile << "\tEgz." << endl;
    vargsiukaiFile << "\tEgz." << endl;

    // Išvedame likusius duomenis
    for (const auto& student : students) {
        if (student.rusis == "kietiakas") {
            kietiakaiFile << student.vard << "\t" << student.pav;
            for (int mark : student.nd) {
                kietiakaiFile << "\t" << mark;
            }
            kietiakaiFile << "\t" << student.egzaminas << endl;
        } else {
            vargsiukaiFile << student.vard << "\t" << student.pav;
            for (int mark : student.nd) {
                vargsiukaiFile << "\t" << mark;
            }
            vargsiukaiFile << "\t" << student.egzaminas << endl;
        }
    }
    auto end_output = chrono::steady_clock::now(); // Baigiame matuoti laiką
    auto duration_output = chrono::duration_cast<chrono::milliseconds>(end_output - start_output);
    double seconds_output = duration_output.count() / 1000.0; // Konvertuojame milisekundes į sekundes
    cout << "Surusiuotu studentu isvedimas i du naujus failus:  " << seconds_output << " s" << endl;
    kietiakaiFile.close();
    vargsiukaiFile.close();

    auto endd = chrono::steady_clock::now(); // Baigiame matuoti laiką sekundėmis
    auto duration1_output = chrono::duration_cast<chrono::milliseconds>(endd - startt);
    double seconds1_output = duration1_output.count() / 1000.0; // Konvertuojame milisekundes į sekundes
    cout << "Visos programos veikimo laikas:  " << seconds1_output << " s" << endl;
}
void func_generate() {
    char d;
    cout << "Ar norite sugeneruoti faila? (T/N): ";
    while (true) {
        cin >> d;
        if (cin.fail() || (d != 'T' && d != 'N')) {
            cout << "Ivedete netinkama simboli, prasome pasirinkti 'T' arba 'N': ";
            cin.clear();
            cin.ignore(10000, '\n');
        } else {
            break;
        }
    }

    if (d == 'T') {
        generate_new_file();
    } else if (d == 'N') {
        use_existing_file();
    }
}
