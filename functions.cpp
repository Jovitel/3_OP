#include "functions.h"

void func_input_hands() {
    int m = 100, n = 0, pazymys, sum = 0, a, s;
    vector<Studentas> studentai;

    while (n < m) {
        Studentas student;

        cout << "Įveskite vardą: " << endl;
        string vardas;
        cin >> vardas;
        student.setVardas(vardas);

        cout << "Įveskite pavardę: " << endl;
        string pavarde;
        cin >> pavarde;
        student.setPavarde(pavarde);

        cout << "Įveskite namų darbų rezultatus (Įveskite 0, kai norite baigti): " << endl;
        while (cin >> pazymys && pazymys != 0) {
            if (pazymys < 1 || pazymys > 10) {
                cout << "Netinkamas pažymys, įveskite naują: ";
                continue;
            }
            student.addnd(pazymys); // Naudojame addnd metodą
        }

        cout << "Įveskite egzamino rezultatą: ";
        int egzaminas;
        cin >> egzaminas;
        student.setEgzaminas(egzaminas);
        if (student.getEgzaminas() < 1 || student.getEgzaminas() > 10) {
            cout << "Netinkamas pažymys, įveskite naują: ";
            cin >> egzaminas;
            student.setEgzaminas(egzaminas);
        }

        sum = accumulate(student.getNd().begin(), student.getNd().end(), 0);
        student.setGalutinisVid(0.4 * (static_cast<double>(sum) / student.getNd().size()) + 0.6 * student.getEgzaminas());
        student.setGalutinisBal(0.4 * student.getGalutinisVid() + 0.6 * student.getEgzaminas());
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

        studentai.push_back(student);
    }

    for (int i = 0; i < n; i++) {
        vector<int> pazymiai = studentai[i].getNd();

        sort(pazymiai.begin(), pazymiai.end());

        int dydis = pazymiai.size();
        if (dydis % 2 == 0) {
            studentai[i].setGalutineMed((pazymiai[dydis / 2 - 1] + pazymiai[dydis / 2]) / 2.0);
        } else {
            studentai[i].setGalutineMed(pazymiai[dydis / 2]);
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
            cout << left << setw(20) << studentai[i].getVardas() << setw(20) << studentai[i].getPavarde() << setw(10) << fixed << setprecision(2) << studentai[i].getGalutineMed() << endl;
        }
    } else if (s == 0) {
        cout << left << setw(20) << "VARDAS" << setw(20) << "PAVARDĖ" << setw(10) << "GALUTUNIS (VID.)" << endl;
        cout << "------------------------------------------------------------------------" << endl;
        for (int i = 0; i < n; i++) {
            cout << left << setw(20) << studentai[i].getVardas() << setw(20) << studentai[i].getPavarde() << setw(10) << fixed << setprecision(2) << studentai[i].getGalutinisVid() << endl;
        }
    }
}

void func_generate_numbers() {
      int m = 100, n = 0, pazymys, sum = 0, a, s;
    vector<Studentas> studentai;

    srand(time(0)); 

    while (n < m) {
        Studentas student;

        cout << "Įveskite vardą: " << endl;
        string vardas;
        cin >> vardas;
        student.setVardas(vardas);

        cout << "Įveskite pavardę: " << endl;
        string pavarde;
        cin >> pavarde;
        student.setPavarde(pavarde);

        cout << "Ar norite, kad namų darbai būtu sugeneruoti? (taip - 1, ne - 0): " << endl;
        cin >> a;
        while (cin.fail() || (a != 0 && a != 1)) {
            cout << "Įvestas netinkamas skaičius, rinkitės iš 1 ir 0: ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> a;
        }

        if (a == 1) {
            student.setNdKiekis(rand() % (MAX_ND + 1));
            for (int j = 0; j < student.getNdKiekis(); j++) {
                student.addnd(rand() % 11);
            }
            student.setEgzaminas(rand() % 11);
        } else if (a == 0) {
            cout << "Įveskite namų darbų rezultatus (Įveskite 0, kai norite baigti): " << endl;
            while (cin >> pazymys && pazymys != 0) {
                if (pazymys < 1 || pazymys > 10) {
                    cout << "Netinkamas pažymys, įveskite naują: ";
                    continue;
                }
                student.addnd(pazymys);
            }

            cout << "Įveskite egzamino rezultatą: ";
            cin >> pazymys;
            student.setEgzaminas(pazymys);
            if (student.getEgzaminas() < 1 || student.getEgzaminas() > 10) {
                cout << "Netinkamas pažymys, įveskite naują: ";
                cin >> pazymys;
                student.setEgzaminas(pazymys);
            }
        }

        sum = accumulate(student.getNd().begin(), student.getNd().end(), 0);
        student.setGalutinisVid(0.4 * (static_cast<double>(sum) / student.getNd().size()) + 0.6 * student.getEgzaminas());
        student.setGalutinisBal(0.4 * student.getGalutinisVid() + 0.6 * student.getEgzaminas());
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
        vector<int> pazymiai = studentai[i].getNd();

        sort(pazymiai.begin(), pazymiai.end());

        int dydis = pazymiai.size();
        if (dydis % 2 == 0) {
            studentai[i].setGalutineMed((pazymiai[dydis / 2 - 1] + pazymiai[dydis / 2]) / 2.0);
        } else {
            studentai[i].setGalutineMed(pazymiai[dydis / 2]);
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
    }  if (s == 1) {
        cout << left << setw(20) << "VARDAS" << setw(20) << "PAVARDĖ" << setw(10) << "GALUTUNIS (MED.)" << endl;
        cout << "------------------------------------------------------------------------" << endl;
        for (int i = 0; i < n; i++) {
            cout << left << setw(20) << studentai[i].getVardas() << setw(20) << studentai[i].getPavarde() << setw(10) << fixed << setprecision(2) << studentai[i].getGalutineMed() << endl;
        }
    } else if (s == 0) {
        cout << left << setw(20) << "VARDAS" << setw(20) << "PAVARDĖ" << setw(10) << "GALUTUNIS (VID.)" << endl;
        cout << "------------------------------------------------------------------------" << endl;
        for (int i = 0; i < n; i++) {
            cout << left << setw(20) << studentai[i].getVardas() << setw(20) << studentai[i].getPavarde() << setw(10) << fixed << setprecision(2) << studentai[i].getGalutinisVid() << endl;
        }
    }

    
}

void func_generate_names() {
    int m = 100, n = 0, pazymys, sum = 0, a, s, w;
    Studentas student;
    vector<Studentas> studentai(m);
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
            studentai[n].setVardas(vard[rand() % 10]);
            studentai[n].setPavarde(pav[rand() % 10]);
            studentai[n].setNdKiekis(rand() % (MAX_ND + 1));
            for (int j = 0; j < studentai[n].getNdKiekis(); j++) {
                studentai[n].addnd(rand() % 11);
            }
        } else if (w == 0) {
                Studentas student;

                cout << "Įveskite vardą: " << endl;
                string vardas;
                cin >> vardas;
                student.setVardas(vardas);

                cout << "Įveskite pavardę: " << endl;
                string pavarde;
                cin >> pavarde;
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
            student.setNdKiekis(rand() % (MAX_ND + 1));
            for (int j = 0; j < student.getNdKiekis(); j++) {
                student.addnd(rand() % 11);
            }
            student.setEgzaminas(rand() % 11);
        } else if (a == 0) {
            cout << "Įveskite namų darbų rezultatus (Įveskite 0, kai norite baigti): " << endl;
            while (cin >> pazymys && pazymys != 0) {
                if (pazymys < 1 || pazymys > 10) {
                    cout << "Netinkamas pažymys, įveskite naują: ";
                    continue;
                }
                student.addnd(pazymys);
            }

            cout << "Įveskite egzamino rezultatą: ";
            cin >> pazymys;
            student.setEgzaminas(pazymys);
            if (student.getEgzaminas() < 1 || student.getEgzaminas() > 10) {
                cout << "Netinkamas pažymys, įveskite naują: ";
                cin >> pazymys;
                student.setEgzaminas(pazymys);
            }
        }

        sum = accumulate(student.getNd().begin(), student.getNd().end(), 0);
        student.setGalutinisVid(0.4 * (static_cast<double>(sum) / student.getNd().size()) + 0.6 * student.getEgzaminas());
        student.setGalutinisBal(0.4 * student.getGalutinisVid() + 0.6 * student.getEgzaminas());
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
        vector<int> pazymiai = studentai[i].getNd();

        sort(pazymiai.begin(), pazymiai.end());

        int dydis = pazymiai.size();
        if (dydis % 2 == 0) {
            studentai[i].setGalutineMed((pazymiai[dydis / 2 - 1] + pazymiai[dydis / 2]) / 2.0);
        } else {
            studentai[i].setGalutineMed(pazymiai[dydis / 2]);
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
           cout << left << setw(20) << studentai[i].getVardas() << setw(20) << studentai[i].getPavarde() << setw(10) << fixed << setprecision(2) << studentai[i].getGalutineMed() << endl;
        }
    } else if (s == 0) {
        cout << left << setw(20) << "VARDAS" << setw(20) << "PAVARDĖ" << setw(10) << "GALUTUNIS (VID.)" << endl;
        cout << "------------------------------------------------------------------------" << endl;
        for (int i = 0; i < n; i++) {
            cout << left << setw(20) << studentai[i].getVardas() << setw(20) << studentai[i].getPavarde() << setw(10) << fixed << setprecision(2) << studentai[i].getGalutinisVid() << endl;
        }
    }
}
}

void func_input_file() {

    try {
        int s, rez;
        vector<Studentas> studentai;
        string line;
        Studentas studentas;
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
            string vardas, pavarde;
            iss >> vardas >> pavarde;
            studentas.setVardas(vardas);
            studentas.setPavarde(pavarde);

            int pazymys;
            while (iss >> pazymys) {
                studentas.addnd(pazymys);
            }

            // Skaitome egzamino rezultatą
            iss.clear();
            iss >> pazymys;
            studentas.setEgzaminas(pazymys);

            studentai.push_back(studentas);
        }

        fd.close();
        auto end = chrono::steady_clock::now(); // Baigiame matuoti laiką sekundemis
        cout << "Failo nuskaitymo laikas: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl; // Išvedame laiką į ekraną

        // Skaičiuojame medianą ir vidurkį
        for (int i = 0; i < studentai.size(); ++i) {
            vector<int> pazymiai = studentai[i].getNd();
            sort(pazymiai.begin(), pazymiai.end());

            int dydis = pazymiai.size();
            if (!pazymiai.empty()) {
                if (dydis % 2 == 0) {
                    int middle1 = dydis / 2 - 1;
                    int middle2 = dydis / 2;
                    studentai[i].setGalutineMed((pazymiai[middle1] + pazymiai[middle2]) / 2.0);
                } else {
                    int middle = dydis / 2;
                    studentai[i].setGalutineMed(pazymiai[middle]);
                }
            } else {
                // Tvarkome atvejį, kai nėra įvertinimų
                studentai[i].setGalutineMed(0.0); // arba kita tinkama vertė
            }

            double sum = accumulate(pazymiai.begin(), pazymiai.end(), 0.0);
            studentai[i].setGalutinisVid(0.4 * (sum / pazymiai.size()) + 0.6 * studentai[i].getEgzaminas());
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
            sort(studentai.begin(), studentai.end(), [](const Studentas &a, const Studentas &b) {
                return a.getVardas() < b.getVardas();
            });
            break;
        case 2:
            sort(studentai.begin(), studentai.end(), [](const Studentas &a, const Studentas &b) {
                return a.getPavarde() < b.getPavarde();
            });
            break;
        case 3:
            sort(studentai.begin(), studentai.end(), [](const Studentas &a, const Studentas &b) {
                return a.getGalutinisVid() > b.getGalutinisVid();
            });
            break;
        case 4:
            sort(studentai.begin(), studentai.end(), [](const Studentas &a, const Studentas &b) {
                return a.getGalutineMed() > b.getGalutineMed();
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
                   cout << left << setw(20) << studentai[i].getVardas() << setw(20) << studentai[i].getPavarde() << setw(10) << fixed << setprecision(2) << studentai[i].getGalutineMed() << endl;
                }
            } else if (s == 0) {
                cout << left << setw(20) << "VARDAS" << setw(20) << "PAVARDĖ" << setw(20) << "GALUTUNIS (VID.)" << endl;
                cout << "------------------------------------------------------------------------" << endl;
                for (int i = 0; i < studentai.size(); i++) {
                    cout << left << setw(20) << studentai[i].getVardas() << setw(20) << studentai[i].getPavarde() << setw(20) << fixed << setprecision(2) << studentai[i].getGalutinisVid() << endl;
                }
            }
        } else if (rez == 0) {
            if (s == 1) {
                fdd << left << setw(20) << "VARDAS" << setw(20) << "PAVARDĖ" << setw(20) << "GALUTUNIS (MED.)" << endl;
                fdd << "------------------------------------------------------------------------" << endl;
                for (int i = 0; i < studentai.size(); i++) {
                    fdd << left << setw(20) << studentai[i].getVardas() << setw(20) << studentai[i].getPavarde() << setw(20) << fixed << setprecision(2) << studentai[i].getGalutineMed() << endl;
                }
            } else if (s == 0) {
                fdd << left << setw(20) << "VARDAS" << setw(20) << "PAVARDĖ" << setw(20) << "GALUTUNIS (VID.)" << endl;
                fdd << "------------------------------------------------------------------------" << endl;
                for (int i = 0; i < studentai.size(); i++) {
                    fdd << left << setw(20) << studentai[i].getVardas() << setw(20) << studentai[i].getPavarde() << setw(20) << fixed << setprecision(2) << studentai[i].getGalutinisVid() << endl;
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

    vector<Studentas> students;

    for (int i = 1; i <= numStudents; ++i) {
        Studentas student;
        student.setVardas("Vardas" + to_string(i));
        student.setPavarde("Pavarde" + to_string(i));
        student.setNdKiekis(numMarks);
        for (int j = 0; j < numMarks; ++j) {
            student.addnd(dis(gen));
        }
        student.setEgzaminas(dis(gen));

        students.push_back(student);
    }

    // Rikiuojame studentus pagal galutinį vidurkį didėjančia tvarka
    sort(students.begin(), students.end(), [](const Studentas& a, const Studentas& b) {
        return a.getEgzaminas() < b.getEgzaminas();
    });

    // Įrašome išrikiuotus duomenis į failą
    for (const auto& student : students) {
        sortedFile << student.getVardas() << "\t" << student.getPavarde();
        for (int mark : student.getNd()) {
            sortedFile << "\t" << mark;
        }
        sortedFile << "\t" << student.getEgzaminas() << endl;
    }

    sortedFile.close();
    auto end_read = chrono::steady_clock::now();
    auto duration_read = chrono::duration_cast<chrono::milliseconds>(end_read - start);
    double seconds_read = duration_read.count() / 1000.0; // Konvertuojame milisekundes į sekundes
    cout << "Failo kurimas ir jo uzdarymas:  " << seconds_read << " s" << endl;
    
}
//1 STRATEGIJA
void use_existing_file() {
    string file_name;
    cout << "Koki faila naudosite? " << endl;
    cin >> file_name;

    ifstream fd(file_name);
    if (!fd.is_open()) {
        cout << "Nepavyko atidaryti failo." << endl;
    }

    cout << "VECTOR: " << endl;
    vector<Studentas> students;
    Studentas studentas;
    string line;
    int numMarks = 0; // Kintamasis saugantis namų darbų skaičių

    // Skaitome duomenis iš failo
    auto start_read = chrono::steady_clock::now(); // Pradedame matuoti laiką
    while (getline(fd, line)) {
        istringstream iss(line);
        Studentas student;

        // Nuskaitome vardą ir pavardę
        string vardas, pavarde;
        iss >> vardas >> pavarde;
        studentas.setVardas(vardas);
        studentas.setPavarde(pavarde);

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
            student.addnd(mark);
        }

        // Nuskaitome egzamino rezultatą
        int egzaminas;
        iss >> egzaminas;
        student.setEgzaminas(egzaminas);

        // Apskaičiuojame galutinį vidurkį
        student.setGalutinisVid(0.4 * (accumulate(student.getNd().begin(), student.getNd().end(), 0.0) / numMarks) + 0.6 * student.getEgzaminas());

        students.push_back(student);
    }
    auto end_read = chrono::steady_clock::now(); // Baigiame matuoti laiką
    auto duration_read = chrono::duration_cast<chrono::milliseconds>(end_read - start_read);
    double seconds_read = duration_read.count() / 1000.0; // Konvertuojame milisekundes į sekundes
    cout << "Duomenu nuskaitymas is failo:  " << seconds_read << " s" << endl;

    fd.close();

    // Rikiuojame studentus pagal galutinį vidurkį didėjančia tvarka
    auto start_sort = chrono::steady_clock::now(); // Pradedame matuoti laiką
    sort(students.begin(), students.end(), [](const Studentas& a, const Studentas& b) {
        return a.getGalutinisVid() > b.getGalutinisVid(); // Rūšiuojame nuo didžiausio iki mažiausio galutinio balo
    });
    auto end_sort = chrono::steady_clock::now(); // Baigiame matuoti laiką
    auto duration_sort = chrono::duration_cast<chrono::milliseconds>(end_sort - start_sort);
    double seconds_sort = duration_sort.count() / 1000.0; // Konvertuojame milisekundes į sekundes
    cout << "Studentu rusiavimas didejimo tvarka:  " << seconds_sort << " s" << endl;

    // Sukurkime naujus konteinerius kietuoliams ir vargsiukams
    vector<Studentas> kietiakai;
    vector<Studentas> vargsiukai;

    // Perskirstome studentus į kietuolius ir vargsiukus
    auto start_split = chrono::steady_clock::now(); // Pradedame matuoti laiką
    for (const auto& student : students) {
        if (student.getGalutinisVid() >= 5.0) {
            kietiakai.push_back(student);
        } else {
            vargsiukai.push_back(student);
        }
    }
    auto end_split = chrono::steady_clock::now(); // Baigiame matuoti laiką
    auto duration_split = chrono::duration_cast<chrono::milliseconds>(end_split - start_split);
    double seconds_split = duration_split.count() / 1000.0; // Konvertuojame milisekundes į sekundes
    cout << "Studentu suskirstymas i dvi grupes:  " << seconds_split << " s" << endl;

    // Išvedame kietuolius ir vargsiukus į atskirus failus
    ofstream kietiakaiFile("kietiakai_" + file_name + "_vector.txt");
    ofstream vargsiukaiFile("vargsiukai_" + file_name + "_vector.txt");

    // Pirmiausia išvedame antrą eilutę
    kietiakaiFile << "Vardas" << "\t" << "Pavarde";
    vargsiukaiFile << "Vardas" << "\t" << "Pavarde";

    for (int i = 1; i <= numMarks; ++i) {
        kietiakaiFile << "\tND" << i;
        vargsiukaiFile << "\tND" << i;
    }
    kietiakaiFile << "\tEgz." << endl;
    vargsiukaiFile << "\tEgz." << endl;

    // Išvedame likusius duomenis
    for (const auto& student : kietiakai) {
        kietiakaiFile << student.getVardas() << "\t" << student.getPavarde();
        for (int mark : student.getNd()) {
            kietiakaiFile << "\t" << mark;
        }
        kietiakaiFile << "\t" << student.getEgzaminas() << endl;
    }

    for (const auto& student : vargsiukai) {
        vargsiukaiFile << student.getVardas() << "\t" << student.getPavarde();
        for (int mark : student.getNd()) {
            vargsiukaiFile << "\t" << mark;
        }
        vargsiukaiFile << "\t" << student.getEgzaminas() << endl;
    }

    kietiakaiFile.close();
    vargsiukaiFile.close();
}

void read_list (){
    string file_name;
    cout << "Koki faila naudosite? " << endl;
    cin >> file_name;
    ifstream fd(file_name);
    if (!fd.is_open()) {
        cout << "Nepavyko atidaryti failo." << endl;
    }
    cout << "LIST: " << endl;
    list<Studentas> students;
    Studentas student;
    string line;
    int numMarks = 0; // Kintamasis saugantis namų darbų skaičių

    // Skaitome duomenis iš failo
    auto start_read = chrono::steady_clock::now(); // Pradedame matuoti laiką
    while (getline(fd, line)) {

        // Nuskaitome vardą ir pavardę
            istringstream iss(line);
            string vardas, pavarde;
            iss >> vardas >> pavarde;
            student.setVardas(vardas);
            student.setPavarde(pavarde);

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
            student.addnd(mark);
        }


        // Nuskaitome egzamino rezultatą
        int egzaminas;
        iss >> egzaminas;
        student.setEgzaminas(egzaminas);

        // Apskaičiuojame galutinį vidurkį
        student.setGalutinisVid(0.4 * (accumulate(student.getNd().begin(), student.getNd().end(), 0.0) / numMarks) + 0.6 * student.getEgzaminas());


        students.push_back(student);
    }
    auto end_read = chrono::steady_clock::now(); // Baigiame matuoti laiką
    auto duration_read = chrono::duration_cast<chrono::milliseconds>(end_read - start_read);
    double seconds_read = duration_read.count() / 1000.0; // Konvertuojame milisekundes į sekundes
    cout << "Duomenu nuskaitymas is failo:  " << seconds_read << " s" << endl;

    fd.close();

    // Rikiuojame studentus pagal galutinį vidurkį didėjančia tvarka
    auto start_sort = chrono::steady_clock::now(); // Pradedame matuoti laiką
    students.sort([](const Studentas& a, const Studentas& b) {
        return a.getGalutinisVid() > b.getGalutinisVid(); // Rūšiuojame nuo didžiausio iki mažiausio galutinio balo
    });
    auto end_sort = chrono::steady_clock::now(); // Baigiame matuoti laiką
    auto duration_sort = chrono::duration_cast<chrono::milliseconds>(end_sort - start_sort);
    double seconds_sort = duration_sort.count() / 1000.0; // Konvertuojame milisekundes į sekundes
    cout << "Studentu rusiavimas didejimo tvarka:  " << seconds_sort << " s" << endl;

    // Sukurkime naujus sąrašus kietuoliams ir vargsiukams
    list<Studentas> kietiakai;
    list<Studentas> vargsiukai;

    // Perskirstome studentus į kietuolius ir vargsiukus
    auto start_split = chrono::steady_clock::now(); // Pradedame matuoti laiką
    for (const auto& student : students) {
        if (student.getGalutinisVid() >= 5.0) {
            kietiakai.push_back(student);
        } else {
            vargsiukai.push_back(student);
        }
    }
    auto end_split = chrono::steady_clock::now(); // Baigiame matuoti laiką
    auto duration_split = chrono::duration_cast<chrono::milliseconds>(end_split - start_split);
    double seconds_split = duration_split.count() / 1000.0; // Konvertuojame milisekundes į sekundes
    cout << "Studentu suskirstymas i dvi grupes:  " << seconds_split << " s" << endl;

    // Išvedame kietuolius ir vargsiukus į atskirus failus
    ofstream kietiakaiFile("kietiakai_" + file_name + "_list.txt");
    ofstream vargsiukaiFile("vargsiukai_" + file_name + "_list.txt");

    // Pirmiausia išvedame antrą eilutę
    kietiakaiFile << "Vardas" << "\t" << "Pavarde";
    vargsiukaiFile << "Vardas" << "\t" << "Pavarde";

    for (int i = 1; i <= numMarks; ++i) {
        kietiakaiFile << "\tND" << i;
        vargsiukaiFile << "\tND" << i;
    }
    kietiakaiFile << "\tEgz." << endl;
    vargsiukaiFile << "\tEgz." << endl;

    // Išvedame likusius duomenis
    for (const auto& student : kietiakai) {
        kietiakaiFile << student.getVardas() << "\t" << student.getPavarde();
        for (int mark : student.getNd()) {
            kietiakaiFile << "\t" << mark;
        }
        kietiakaiFile << "\t" << student.getEgzaminas() << endl;
    }

    for (const auto& student : vargsiukai) {
        vargsiukaiFile << student.getVardas() << "\t" << student.getPavarde();
        for (int mark : student.getNd()) {
            vargsiukaiFile << "\t" << mark;
        }
        vargsiukaiFile << "\t" << student.getEgzaminas() << endl;
    }

    kietiakaiFile.close();
    vargsiukaiFile.close();

}

void read_deque (){
    deque<Studentas> students;
    Studentas student;
    string file_name;
    cout << "Koki faila naudosite? " << endl;
    cin >> file_name;
    ifstream fd(file_name);
    if (!fd.is_open()) {
        cout << "Nepavyko atidaryti failo." << endl;
    }
    cout << "DEQUE: " << endl;
    string line;
    int numMarks = 0; // Kintamasis saugantis namų darbų skaičių

    // Skaitome duomenis iš failo
    auto start_read = chrono::steady_clock::now(); // Pradedame matuoti laiką
    while (getline(fd, line)) {

         // Nuskaitome vardą ir pavardę
            istringstream iss(line);
            string vardas, pavarde;
            iss >> vardas >> pavarde;
            student.setVardas(vardas);
            student.setPavarde(pavarde);

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
            student.addnd(mark);
        }


        // Nuskaitome egzamino rezultatą
        int egzaminas;
        iss >> egzaminas;
        student.setEgzaminas(egzaminas);

        // Apskaičiuojame galutinį vidurkį
        student.setGalutinisVid(0.4 * (accumulate(student.getNd().begin(), student.getNd().end(), 0.0) / numMarks) + 0.6 * student.getEgzaminas());


        students.push_back(student);
    }
    auto end_read = chrono::steady_clock::now(); // Baigiame matuoti laiką
    auto duration_read = chrono::duration_cast<chrono::milliseconds>(end_read - start_read);
    double seconds_read = duration_read.count() / 1000.0; // Konvertuojame milisekundes į sekundes
    cout << "Duomenu nuskaitymas is failo:  " << seconds_read << " s" << endl;

    fd.close();

    // Rikiuojame studentus pagal galutinį vidurkį didėjančia tvarka
    auto start_sort = chrono::steady_clock::now(); // Pradedame matuoti laiką
    sort(students.begin(), students.end(), [](const Studentas& a, const Studentas& b) {
        return a.getGalutinisVid() > b.getGalutinisVid(); // Rūšiuojame nuo didžiausio iki mažiausio galutinio balo
    });
    auto end_sort = chrono::steady_clock::now(); // Baigiame matuoti laiką
    auto duration_sort = chrono::duration_cast<chrono::milliseconds>(end_sort - start_sort);
    double seconds_sort = duration_sort.count() / 1000.0; // Konvertuojame milisekundes į sekundes
    cout << "Studentu rusiavimas didejimo tvarka:  " << seconds_sort << " s" << endl;

    // Sukurkime naujus sąrašus kietuoliams ir vargsiukams
    deque<Studentas> kietiakai;
    deque<Studentas> vargsiukai;

    // Perskirstome studentus į kietuolius ir vargsiukus
    auto start_split = chrono::steady_clock::now(); // Pradedame matuoti laiką
    for (const auto& student : students) {
        if (student.getGalutinisVid() >= 5.0) {
            kietiakai.push_back(student);
        } else {
            vargsiukai.push_back(student);
        }
    }
    auto end_split = chrono::steady_clock::now(); // Baigiame matuoti laiką
    auto duration_split = chrono::duration_cast<chrono::milliseconds>(end_split - start_split);
    double seconds_split = duration_split.count() / 1000.0; // Konvertuojame milisekundes į sekundes
    cout << "Studentu suskirstymas i dvi grupes:  " << seconds_split << " s" << endl;

    // Išvedame kietuolius ir vargsiukus į atskirus failus
    ofstream kietiakaiFile("kietiakai_" + file_name + "_deque.txt");
    ofstream vargsiukaiFile("vargsiukai_" + file_name + "_deque.txt");

    // Pirmiausia išvedame antrą eilutę
    kietiakaiFile << "Vardas" << "\t" << "Pavarde";
    vargsiukaiFile << "Vardas" << "\t" << "Pavarde";

    for (int i = 1; i <= numMarks; ++i) {
        kietiakaiFile << "\tND" << i;
        vargsiukaiFile << "\tND" << i;
    }
    kietiakaiFile << "\tEgz." << endl;
    vargsiukaiFile << "\tEgz." << endl;

    // Išvedame likusius duomenis
   for (const auto& student : kietiakai) {
        kietiakaiFile << student.getVardas() << "\t" << student.getPavarde();
        for (int mark : student.getNd()) {
            kietiakaiFile << "\t" << mark;
        }
        kietiakaiFile << "\t" << student.getEgzaminas() << endl;
    }

    for (const auto& student : vargsiukai) {
        vargsiukaiFile << student.getVardas() << "\t" << student.getPavarde();
        for (int mark : student.getNd()) {
            vargsiukaiFile << "\t" << mark;
        }
        vargsiukaiFile << "\t" << student.getEgzaminas() << endl;
    }

    kietiakaiFile.close();
    vargsiukaiFile.close();
}
//2 STRATEGIJA
void use_existing_file_2(){
    string file_name;
    cout << "Koki faila naudosite? " << endl;
    cin >> file_name;
    ifstream fd(file_name);
    if (!fd.is_open()) {
        cout << "Nepavyko atidaryti failo." << endl;
    }
    cout << "VECTOR: " << endl;
    vector<Studentas> students;
    Studentas student;
    string line;
    int numMarks = 0; // Kintamasis saugantis namų darbų skaičių

    // Skaitome duomenis iš failo
    auto start_read = chrono::steady_clock::now(); // Pradedame matuoti laiką
    while (getline(fd, line)) {

        // Nuskaitome vardą ir pavardę
             istringstream iss(line);
            string vardas, pavarde;
            iss >> vardas >> pavarde;
            student.setVardas(vardas);
            student.setPavarde(pavarde);

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
            student.addnd(mark);
        }


        // Nuskaitome egzamino rezultatą
        int egzaminas;
        iss >> egzaminas;
        student.setEgzaminas(egzaminas);

        // Apskaičiuojame galutinį vidurkį
        student.setGalutinisVid(0.4 * (accumulate(student.getNd().begin(), student.getNd().end(), 0.0) / numMarks) + 0.6 * student.getEgzaminas());


        students.push_back(student);
    }
    auto end_read = chrono::steady_clock::now(); // Baigiame matuoti laiką
    auto duration_read = chrono::duration_cast<chrono::milliseconds>(end_read - start_read);
    double seconds_read = duration_read.count() / 1000.0; // Konvertuojame milisekundes į sekundes
    cout << "Duomenu nuskaitymas is failo:  " << seconds_read << " s" << endl;

    fd.close();

    // Rikiuojame studentus pagal galutinį vidurkį didėjančia tvarka
    auto start_sort = chrono::steady_clock::now(); // Pradedame matuoti laiką
    sort(students.begin(), students.end(), [](const Studentas& a, const Studentas& b) {
        return a.getGalutinisVid() > b.getGalutinisVid(); // Rūšiuojame nuo didžiausio iki mažiausio galutinio balo
    });
    auto end_sort = chrono::steady_clock::now(); // Baigiame matuoti laiką
    auto duration_sort = chrono::duration_cast<chrono::milliseconds>(end_sort - start_sort);
    double seconds_sort = duration_sort.count() / 1000.0; // Konvertuojame milisekundes į sekundes
    cout << "Studentu rusiavimas didejimo tvarka:  " << seconds_sort << " s" << endl;

  vector<Studentas> vargsiukai;

// Perskirstome studentus į vargsiukus
auto start_split = chrono::steady_clock::now(); // Pradedame matuoti laiką
auto partition_point = partition(students.begin(), students.end(), [](const Studentas& student) {
    return student.getGalutinisVid() < 5.0; // Studentas su galutiniu vidurkiu < 5.0 eina į priekį
});
// Perskirstėme studentus į vargsiukus ir kietiakus, grąžindami pirmą kietiakų iteratorių

// Ištriname vargsiukus iš bendro konteinerio
vargsiukai.assign(partition_point, students.end());
students.erase(partition_point, students.end());
auto end_split = chrono::steady_clock::now(); // Baigiame matuoti laiką
auto duration_split = chrono::duration_cast<chrono::milliseconds>(end_split - start_split);
double seconds_split = duration_split.count() / 1000.0; // Konvertuojame milisekundes į sekundes
cout << "Studentu suskirstymas i dvi grupes:  " << seconds_split << " s" << endl;

// Išvedame vargsiukus į atskirą failą
ofstream vargsiukaiFile("vargsiukai_" + file_name + "_vector.txt");

// Išvedame antrą eilutę
vargsiukaiFile << "Vardas" << "\t" << "Pavarde";
for (int i = 1; i <= numMarks; ++i) {
    vargsiukaiFile << "\tND" << i;
}
vargsiukaiFile << "\tEgz." << endl;

// Išvedame likusius duomenis
for (const auto& student : vargsiukai) {
    vargsiukaiFile << student.getVardas()<< "\t" << student.getPavarde();
    for (int mark : student.getNd()) {
        vargsiukaiFile << "\t" << mark;
    }
    vargsiukaiFile << "\t" << student.getEgzaminas() << endl;
}

vargsiukaiFile.close();
}

void read_list_2 (){
    string file_name;
    cout << "Koki faila naudosite? " << endl;
    cin >> file_name;
    ifstream fd(file_name);
    if (!fd.is_open()) {
        cout << "Nepavyko atidaryti failo." << endl;
    }
    cout << "LIST: " << endl;
    list<Studentas> students;
    Studentas student;
    string line;
    int numMarks = 0; // Kintamasis saugantis namų darbų skaičių

    // Skaitome duomenis iš failo
    auto start_read = chrono::steady_clock::now(); // Pradedame matuoti laiką
    while (getline(fd, line)) {

        // Nuskaitome vardą ir pavardę
            istringstream iss(line);
            string vardas, pavarde;
            iss >> vardas >> pavarde;
            student.setVardas(vardas);
            student.setPavarde(pavarde);

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
            student.addnd(mark);
        }

        // Nuskaitome egzamino rezultatą
        int egzaminas;
        iss >> egzaminas;
        student.setEgzaminas(egzaminas);

        // Apskaičiuojame galutinį vidurkį
        student.setGalutinisVid(0.4 * (accumulate(student.getNd().begin(), student.getNd().end(), 0.0) / numMarks) + 0.6 * student.getEgzaminas());

        students.push_back(student);
    }
    auto end_read = chrono::steady_clock::now(); // Baigiame matuoti laiką
    auto duration_read = chrono::duration_cast<chrono::milliseconds>(end_read - start_read);
    double seconds_read = duration_read.count() / 1000.0; // Konvertuojame milisekundes į sekundes
    cout << "Duomenu nuskaitymas is failo:  " << seconds_read << " s" << endl;

    fd.close();

    // Rikiuojame studentus pagal galutinį vidurkį didėjančia tvarka
    auto start_sort = chrono::steady_clock::now(); // Pradedame matuoti laiką
    students.sort([](const Studentas& a, const Studentas& b) {
        return a.getGalutinisVid()> b.getGalutinisVid(); // Rūšiuojame nuo didžiausio iki mažiausio galutinio balo
    });
    auto end_sort = chrono::steady_clock::now(); // Baigiame matuoti laiką
    auto duration_sort = chrono::duration_cast<chrono::milliseconds>(end_sort - start_sort);
    double seconds_sort = duration_sort.count() / 1000.0; // Konvertuojame milisekundes į sekundes
    cout << "Studentu rusiavimas didejimo tvarka:  " << seconds_sort << " s" << endl;

     list<Studentas> vargsiukai;

    // Perskirstome studentus į vargsiukus
    auto start_split = chrono::steady_clock::now(); // Pradedame matuoti laiką
    auto partition_point = partition(students.begin(), students.end(), [](const Studentas& student) {
        return student.getGalutinisVid() < 5.0; // Studentas su galutiniu vidurkiu < 5.0 eina į priekį
    });
    // Perskirstėme studentus į vargsiukus ir kietiakus, grąžindami pirmą kietiakų iteratorių

    // Ištriname vargsiukus iš bendro konteinerio
    vargsiukai.assign(partition_point, students.end());
    students.erase(partition_point, students.end());
    auto end_split = chrono::steady_clock::now(); // Baigiame matuoti laiką
    auto duration_split = chrono::duration_cast<chrono::milliseconds>(end_split - start_split);
    double seconds_split = duration_split.count() / 1000.0; // Konvertuojame milisekundes į sekundes
    cout << "Studentu suskirstymas i dvi grupes:  " << seconds_split << " s" << endl;

    // Išvedame vargsiukus į atskirą failą
    ofstream vargsiukaiFile("vargsiukai_" + file_name + "_vector.txt");

    // Išvedame antrą eilutę
    vargsiukaiFile << "Vardas" << "\t" << "Pavarde";
    for (int i = 1; i <= numMarks; ++i) {
        vargsiukaiFile << "\tND" << i;
    }
    vargsiukaiFile << "\tEgz." << endl;

    // Išvedame likusius duomenis
    for (const auto& student : vargsiukai) {
        vargsiukaiFile << student.getVardas() << "\t" << student.getPavarde();
        for (int mark : student.getNd()) {
            vargsiukaiFile << "\t" << mark;
        }
        vargsiukaiFile << "\t" << student.getEgzaminas() << endl;
    }

    vargsiukaiFile.close();

}

void read_deque_2 (){
    string file_name;
    cout << "Koki faila naudosite? " << endl;
    cin >> file_name;
    ifstream fd(file_name);
    if (!fd.is_open()) {
        cout << "Nepavyko atidaryti failo." << endl;
    }
    cout << "DEQUE: " << endl;
    deque<Studentas> students;
    Studentas studentas;
    string line;
    int numMarks = 0; // Kintamasis saugantis namų darbų skaičių

    // Skaitome duomenis iš failo
    auto start_read = chrono::steady_clock::now(); // Pradedame matuoti laiką
    while (getline(fd, line)) {

        // Nuskaitome vardą ir pavardę
            istringstream iss(line);
            string vardas, pavarde;
            iss >> vardas >> pavarde;
            studentas.setVardas(vardas);
            studentas.setPavarde(pavarde);

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
            studentas.addnd(mark);
        }

        // Nuskaitome egzamino rezultatą
        int egzaminas;
        iss >> egzaminas;
        studentas.setEgzaminas(egzaminas);

        // Apskaičiuojame galutinį vidurkį
        studentas.setGalutinisVid(0.4 * (accumulate(studentas.getNd().begin(), studentas.getNd().end(), 0.0) / numMarks) + 0.6 * studentas.getEgzaminas());

        students.push_back(studentas);
    }
    auto end_read = chrono::steady_clock::now(); // Baigiame matuoti laiką
    auto duration_read = chrono::duration_cast<chrono::milliseconds>(end_read - start_read);
    double seconds_read = duration_read.count() / 1000.0; // Konvertuojame milisekundes į sekundes
    cout << "Duomenu nuskaitymas is failo:  " << seconds_read << " s" << endl;

    fd.close();

    // Rikiuojame studentus pagal galutinį vidurkį didėjančia tvarka
    auto start_sort = chrono::steady_clock::now(); // Pradedame matuoti laiką
    sort(students.begin(), students.end(), [](const Studentas& a, const Studentas& b) {
        return a.getGalutinisVid() > b.getGalutinisVid(); // Rūšiuojame nuo didžiausio iki mažiausio galutinio balo
    });
    auto end_sort = chrono::steady_clock::now(); // Baigiame matuoti laiką
    auto duration_sort = chrono::duration_cast<chrono::milliseconds>(end_sort - start_sort);
    double seconds_sort = duration_sort.count() / 1000.0; // Konvertuojame milisekundes į sekundes
    cout << "Studentu rusiavimas didejimo tvarka:  " << seconds_sort << " s" << endl;

    deque<Studentas> vargsiukai;

    // Perskirstome studentus į vargsiukus
    auto start_split = chrono::steady_clock::now(); // Pradedame matuoti laiką
    auto partition_point = partition(students.begin(), students.end(), [](const Studentas& student) {
        return student.getGalutinisVid() < 5.0; // Studentas su galutiniu vidurkiu < 5.0 eina į priekį
    });
    // Perskirstėme studentus į vargsiukus ir kietiakus, grąžindami pirmą kietiakų iteratorių

    // Ištriname vargsiukus iš bendro konteinerio
    vargsiukai.assign(partition_point, students.end());
    students.erase(partition_point, students.end());
    auto end_split = chrono::steady_clock::now(); // Baigiame matuoti laiką
    auto duration_split = chrono::duration_cast<chrono::milliseconds>(end_split - start_split);
    double seconds_split = duration_split.count() / 1000.0; // Konvertuojame milisekundes į sekundes
    cout << "Studentu suskirstymas i dvi grupes:  " << seconds_split << " s" << endl;

    // Išvedame vargsiukus į atskirą failą
    ofstream vargsiukaiFile("vargsiukai_" + file_name + "_vector.txt");

    // Išvedame antrą eilutę
    vargsiukaiFile << "Vardas" << "\t" << "Pavarde";
    for (int i = 1; i <= numMarks; ++i) {
        vargsiukaiFile << "\tND" << i;
    }
    vargsiukaiFile << "\tEgz." << endl;

    // Išvedame likusius duomenis
    for (const auto& student : vargsiukai) {
        vargsiukaiFile << student.getVardas() << "\t" << student.getPavarde();
        for (int mark : student.getNd()) {
            vargsiukaiFile << "\t" << mark;
        }
        vargsiukaiFile << "\t" << student.getEgzaminas() << endl;
    }

    vargsiukaiFile.close();
}
//3 STRATEGIJA
void use_existing_file_3(){
      string file_name;
    cout << "Koki faila naudosite? " << endl;
    cin >> file_name;
    ifstream fd(file_name);
    
    cout << "VECTOR: " << endl;
    vector<Studentas> students;
    string line;
    int numMarks = 0; // Kintamasis saugantis namų darbų skaičių

    // Skaitome duomenis iš failo
    auto start_read = chrono::steady_clock::now(); // Pradedame matuoti laiką
    while (getline(fd, line)) {
        Studentas student;

        // Nuskaitome vardą ir pavardę
            istringstream iss(line);
            string vardas, pavarde;
            iss >> vardas >> pavarde;
            student.setVardas(vardas);
            student.setPavarde(pavarde);
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
            student.addnd(mark);
        }

        // Nuskaitome egzamino rezultatą
        int egzaminas;
        iss >> egzaminas;
        student.setEgzaminas(egzaminas);

        // Apskaičiuojame galutinį vidurkį
        student.setGalutinisVid(0.4 * (accumulate(student.getNd().begin(), student.getNd().end(), 0.0) / numMarks) + 0.6 * student.getEgzaminas());

        students.push_back(student);
    }
    auto end_read = chrono::steady_clock::now(); // Baigiame matuoti laiką
    auto duration_read = chrono::duration_cast<chrono::milliseconds>(end_read - start_read);
    double seconds_read = duration_read.count() / 1000.0; // Konvertuojame milisekundes į sekundes
    cout << "Duomenu nuskaitymas is failo:  " << seconds_read << " s" << endl;

    fd.close();

    // Rikiuojame studentus pagal galutinį vidurkį didėjančia tvarka
    auto start_sort = chrono::steady_clock::now(); // Pradedame matuoti laiką
    sort(students.begin(), students.end(), [](const Studentas& a, const Studentas& b) {
        return a.getGalutinisVid() > b.getGalutinisVid(); // Rūšiuojame nuo didžiausio iki mažiausio galutinio balo
    });
    auto end_sort = chrono::steady_clock::now(); // Baigiame matuoti laiką
    auto duration_sort = chrono::duration_cast<chrono::milliseconds>(end_sort - start_sort);
    double seconds_sort = duration_sort.count() / 1000.0; // Konvertuojame milisekundes į sekundes
    cout << "Studentu rusiavimas didejimo tvarka:  " << seconds_sort << " s" << endl;

    vector<Studentas> vargsiukai;

    // Perskirstome studentus į vargsiukus naudodami std::remove_if
    auto start_split = chrono::steady_clock::now(); // Pradedame matuoti laiką
    auto remove_point = remove_if(students.begin(), students.end(), [](const Studentas& student) {
        return student.getGalutinisVid() < 5.0; // Studentas su galutiniu vidurkiu < 5.0 eina į priekį
    });

    // Kopijuojame pašalintus vargsiukus į vargsiukai konteinerį
    copy(remove_point, students.end(), back_inserter(vargsiukai));

    // Ištriname vargsiukus iš bendro konteinerio
    students.erase(remove_point, students.end());
    auto end_split = chrono::steady_clock::now(); // Baigiame matuoti laiką
    auto duration_split = chrono::duration_cast<chrono::milliseconds>(end_split - start_split);
    double seconds_split = duration_split.count() / 1000.0; // Konvertuojame milisekundes į sekundes
    cout << "Studentu suskirstymas i dvi grupes:  " << seconds_split << " s" << endl;

    // Atidarykime failą vargsiukų rezultatams įrašyti
    ofstream vargsiukaiFile("vargsiukai_" + file_name + "_vector.txt");

    // Išvedame antrą eilutę
    vargsiukaiFile << "Vardas" << "\t" << "Pavarde";
    for (int i = 1; i <= numMarks; ++i) {
        vargsiukaiFile << "\tND" << i;
    }
    vargsiukaiFile << "\tEgz." << endl;

    // Išvedame likusius duomenis
    for (const auto& student : vargsiukai) {
        vargsiukaiFile << student.getVardas()<< "\t" << student.getPavarde();
        for (int mark : student.getNd()) {
            vargsiukaiFile << "\t" << mark;
        }
        vargsiukaiFile << "\t" << student.getEgzaminas() << endl;
    }

    vargsiukaiFile.close();
}

void read_list_3 (){
    string file_name;
    cout << "Koki faila naudosite? " << endl;
    cin >> file_name;
    ifstream fd(file_name);
    if (!fd.is_open()) {
        cout << "Nepavyko atidaryti failo." << endl;
    }
    cout << "LIST: " << endl;
    list<Studentas> students;
    string line;
    int numMarks = 0; // Kintamasis saugantis namų darbų skaičių

    // Skaitome duomenis iš failo
    auto start_read = chrono::steady_clock::now(); // Pradedame matuoti laiką
    while (getline(fd, line)) {
        Studentas student;

        // Nuskaitome vardą ir pavardę
            istringstream iss(line);
            string vardas, pavarde;
            iss >> vardas >> pavarde;
            student.setVardas(vardas);
            student.setPavarde(pavarde);
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
            student.addnd(mark);
        }

        // Nuskaitome egzamino rezultatą
        int egzaminas;
        iss >> egzaminas;
        student.setEgzaminas(egzaminas);

        // Apskaičiuojame galutinį vidurkį
        student.setGalutinisVid(0.4 * (accumulate(student.getNd().begin(), student.getNd().end(), 0.0) / numMarks) + 0.6 * student.getEgzaminas());

        students.push_back(student);
    }
    auto end_read = chrono::steady_clock::now(); // Baigiame matuoti laiką
    auto duration_read = chrono::duration_cast<chrono::milliseconds>(end_read - start_read);
    double seconds_read = duration_read.count() / 1000.0; // Konvertuojame milisekundes į sekundes
    cout << "Duomenu nuskaitymas is failo:  " << seconds_read << " s" << endl;

    fd.close();

    // Rikiuojame studentus pagal galutinį vidurkį didėjančia tvarka
    auto start_sort = chrono::steady_clock::now(); // Pradedame matuoti laiką
    students.sort([](const Studentas& a, const Studentas& b) {
        return a.getGalutinisVid() > b.getGalutinisVid(); // Rūšiuojame nuo didžiausio iki mažiausio galutinio balo
    });
    auto end_sort = chrono::steady_clock::now(); // Baigiame matuoti laiką
    auto duration_sort = chrono::duration_cast<chrono::milliseconds>(end_sort - start_sort);
    double seconds_sort = duration_sort.count() / 1000.0; // Konvertuojame milisekundes į sekundes
    cout << "Studentu rusiavimas didejimo tvarka:  " << seconds_sort << " s" << endl;

     list<Studentas> vargsiukai;

     // Perskirstome studentus į vargsiukus naudodami std::remove_if
    auto start_split = chrono::steady_clock::now(); // Pradedame matuoti laiką
    auto remove_point = remove_if(students.begin(), students.end(), [](const Studentas& student) {
        return student.getGalutinisVid() < 5.0; // Studentas su galutiniu vidurkiu < 5.0 eina į priekį
    });

    // Kopijuojame pašalintus vargsiukus į vargsiukai konteinerį
    copy(remove_point, students.end(), back_inserter(vargsiukai));

    // Ištriname vargsiukus iš bendro konteinerio
    students.erase(remove_point, students.end());
    auto end_split = chrono::steady_clock::now(); // Baigiame matuoti laiką
    auto duration_split = chrono::duration_cast<chrono::milliseconds>(end_split - start_split);
    double seconds_split = duration_split.count() / 1000.0; // Konvertuojame milisekundes į sekundes
    cout << "Studentu suskirstymas i dvi grupes:  " << seconds_split << " s" << endl;

    // Išvedame vargsiukus į atskirą failą
    ofstream vargsiukaiFile("vargsiukai_" + file_name + "_vector.txt");

    // Išvedame antrą eilutę
    vargsiukaiFile << "Vardas" << "\t" << "Pavarde";
    for (int i = 1; i <= numMarks; ++i) {
        vargsiukaiFile << "\tND" << i;
    }
    vargsiukaiFile << "\tEgz." << endl;

    // Išvedame likusius duomenis
    for (const auto& student : vargsiukai) {
        vargsiukaiFile << student.getVardas() << "\t" << student.getPavarde();
        for (int mark : student.getNd()) {
            vargsiukaiFile << "\t" << mark;
        }
        vargsiukaiFile << "\t" << student.getEgzaminas() << endl;
    }

    vargsiukaiFile.close();

}

void read_deque_3 (){
    string file_name;
    cout << "Koki faila naudosite? " << endl;
    cin >> file_name;
    ifstream fd(file_name);
    if (!fd.is_open()) {
        cout << "Nepavyko atidaryti failo." << endl;
    }
    cout << "DEQUE: " << endl;
    deque<Studentas> students;
    string line;
    int numMarks = 0; // Kintamasis saugantis namų darbų skaičių

    // Skaitome duomenis iš failo
    auto start_read = chrono::steady_clock::now(); // Pradedame matuoti laiką
    while (getline(fd, line)) {
        Studentas student;

        // Nuskaitome vardą ir pavardę
             istringstream iss(line);
            string vardas, pavarde;
            iss >> vardas >> pavarde;
            student.setVardas(vardas);
            student.setPavarde(pavarde);

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
            student.addnd(mark);
        }

        // Nuskaitome egzamino rezultatą
        int egzaminas;
        iss >> egzaminas;
        student.setEgzaminas(egzaminas);

        // Apskaičiuojame galutinį vidurkį
        student.setGalutinisVid(0.4 * (accumulate(student.getNd().begin(), student.getNd().end(), 0.0) / numMarks) + 0.6 * student.getEgzaminas());

        students.push_back(student);
    }
    auto end_read = chrono::steady_clock::now(); // Baigiame matuoti laiką
    auto duration_read = chrono::duration_cast<chrono::milliseconds>(end_read - start_read);
    double seconds_read = duration_read.count() / 1000.0; // Konvertuojame milisekundes į sekundes
    cout << "Duomenu nuskaitymas is failo:  " << seconds_read << " s" << endl;

    fd.close();

    // Rikiuojame studentus pagal galutinį vidurkį didėjančia tvarka
    auto start_sort = chrono::steady_clock::now(); // Pradedame matuoti laiką
    sort(students.begin(), students.end(), [](const Studentas& a, const Studentas& b) {
        return a.getGalutinisVid() > b.getGalutinisVid(); // Rūšiuojame nuo didžiausio iki mažiausio galutinio balo
    });
    auto end_sort = chrono::steady_clock::now(); // Baigiame matuoti laiką
    auto duration_sort = chrono::duration_cast<chrono::milliseconds>(end_sort - start_sort);
    double seconds_sort = duration_sort.count() / 1000.0; // Konvertuojame milisekundes į sekundes
    cout << "Studentu rusiavimas didejimo tvarka:  " << seconds_sort << " s" << endl;

    deque<Studentas> vargsiukai;

     // Perskirstome studentus į vargsiukus naudodami std::remove_if
    auto start_split = chrono::steady_clock::now(); // Pradedame matuoti laiką
    auto remove_point = remove_if(students.begin(), students.end(), [](const Studentas& student) {
        return student.getGalutinisVid() < 5.0; // Studentas su galutiniu vidurkiu < 5.0 eina į priekį
    });

    // Kopijuojame pašalintus vargsiukus į vargsiukai konteinerį
    copy(remove_point, students.end(), back_inserter(vargsiukai));

    // Ištriname vargsiukus iš bendro konteinerio
    students.erase(remove_point, students.end());
    auto end_split = chrono::steady_clock::now(); // Baigiame matuoti laiką
    auto duration_split = chrono::duration_cast<chrono::milliseconds>(end_split - start_split);
    double seconds_split = duration_split.count() / 1000.0; // Konvertuojame milisekundes į sekundes
    cout << "Studentu suskirstymas i dvi grupes:  " << seconds_split << " s" << endl;

    // Išvedame vargsiukus į atskirą failą
    ofstream vargsiukaiFile("vargsiukai_" + file_name + "_vector.txt");

    // Išvedame antrą eilutę
    vargsiukaiFile << "Vardas" << "\t" << "Pavarde";
    for (int i = 1; i <= numMarks; ++i) {
        vargsiukaiFile << "\tND" << i;
    }
    vargsiukaiFile << "\tEgz." << endl;

    // Išvedame likusius duomenis
    for (const auto& student : vargsiukai) {
        vargsiukaiFile << student.getVardas() << "\t" << student.getPavarde();
        for (int mark : student.getNd()) {
            vargsiukaiFile << "\t" << mark;
        }
        vargsiukaiFile << "\t" << student.getEgzaminas() << endl;
    }

    vargsiukaiFile.close();
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
        cout << "---------- 1 STRATEGIJA ---------- " << endl;
        use_existing_file();
        read_list();
        read_deque(); 
        cout << "---------- 2 STRATEGIJA ---------- " << endl;
        use_existing_file_2();
        read_list_2();
        read_deque_2();
        cout << "---------- 3 STRATEGIJA ---------- " << endl;
        use_existing_file_3();
        read_list_3();
        read_deque_3();
    }
}


void func_tests(){
    // KONSTRUKTORIUS
    {    
        // Inicializuojame kintamuosius su testinėmis reikšmėmis
        std::string vardas = "Vardenis";
        std::string pav = "Pavardenis";
        std::vector<int> nd = {2, 9, 7};
        int egzaminas = 4;
        int nd_kiekis = 3;
        double gal_vid = 9.9;
        double gal_med = 7.5;

        // Sukuriame studento objektą naudodami konstruktorių
        Studentas studentas(vardas, pav, egzaminas, nd, nd_kiekis, gal_vid, gal_med); 

        // Gauti duomenys iš studento objekto
        const std::string& get_vardas = studentas.getVardas();
        const std::string& get_pavarde = studentas.getPavarde();
        const std::vector<int>& get_nd = studentas.getNd();
        int get_egzaminas = studentas.getEgzaminas();
        int get_nd_kiekis = studentas.getNdKiekis();
        double get_gal_vid = studentas.getGalutinisVid();
        double get_gal_med = studentas.getGalutineMed();

        // Patikriname, ar gauti duomenys atitinka nurodytas reikšmes
        assert(get_vardas == vardas);
        assert(get_pavarde == pav);
        assert(get_nd == nd);
        assert(get_egzaminas == egzaminas);
        assert(get_nd_kiekis == nd_kiekis);
        assert(get_gal_vid == gal_vid);
        assert(get_gal_med == gal_med);
    }
    // COPY KONSTRUKSTORIUS
    {
        std::string vardas = "Vardenis";
        std::string pav = "Pavardenis";
        std::vector<int> nd = {2, 9, 7};
        int egzaminas = 4;
        int nd_kiekis = 3;
        double gal_vid = 9.9;
        double gal_med = 7.5;

        Studentas studentas(vardas, pav, egzaminas, nd, nd_kiekis, gal_vid, gal_med); 
        Studentas copy(studentas);

        assert(copy.getVardas() == vardas);
        assert(copy.getPavarde() == pav);
        assert(copy.getNd() == nd);
        assert(copy.getEgzaminas() == egzaminas);
        assert(copy.getNdKiekis() == nd_kiekis);
        assert(copy.getGalutinisVid() == gal_vid);
        assert(copy.getGalutineMed() == gal_med);
    }

    // MOVE KONTRUKTORIUS
    {
        std::string vardas = "Vardenis";
        std::string pav = "Pavardenis";
        std::vector<int> nd = {2, 9, 7};
        int egzaminas = 4;
        int nd_kiekis = 3;
        double gal_vid = 9.9;
        double gal_med = 7.5;

        Studentas studentas(vardas, pav, egzaminas, nd, nd_kiekis, gal_vid, gal_med); 
        Studentas copy(std::move(studentas)); 

        // assert tikrina ar salyga yra teisinga
        assert(copy.getVardas() == vardas);
        assert(copy.getPavarde() == pav);
        assert(copy.getNd() == nd);
        assert(copy.getEgzaminas() == egzaminas);
        assert(copy.getNdKiekis() == nd_kiekis);
        assert(copy.getGalutinisVid() == gal_vid);
        assert(copy.getGalutineMed() == gal_med);

        // Patikriname, ar perkeltas objektas yra tuščias
       // assert(studentas.getVardas().empty());
        //assert(studentas.getPavarde().empty());
       // assert(studentas.getNd().empty());
        // assert(studentas.getEgzaminas() == 0);
        // assert(studentas.getNdKiekis() == 0);
        // assert(studentas.getGalutinisVid() == 0);
        // assert(studentas.getGalutineMed() == 0);
    }
    // Destruktoriaus patikrinimas
    {
    // Sukuriamas dinaminis studento objektas
    Studentas* studentas = new Studentas();

    // Pridedami pažymiai
    studentas->addnd(8);
    studentas->addnd(9);
    studentas->addnd(10);

    // Patikrinama, ar studento objekto pažymiai ne tušti
    assert(!studentas->getNd().empty()); 

    // Studento objektas sunaikinamas
    delete studentas; 

    // Sukuriamas naujas studento objektas naudojant default konstruktorių
    Studentas SStudentas;

    // Patikrinama, ar studento objekto pažymiai ne tušti
    assert(SStudentas.getNd().empty());
    }

    cout << "Visi testai sekmingi." << endl;

}

void func_input_output(){
    Studentas student;

    cout << "Iveskite varda: " << endl;
    cin >> student.vardas_;

    cout << "Iveskite pavarde: " << endl;
    cin >> student.pav_;

    int pazymys;

    cout << "Iveskite namu darbu rezultatus (Iveskite 0, kai norite baigti): " << endl;
    while (cin >> pazymys && pazymys != 0) {
        if (pazymys < 1 || pazymys > 10) {
            cout << "Netinkamas pazymys, iveskite nauja: ";
            continue;
        }
        student.addnd(pazymys); // Naudojame addnd metodą
    }

    cout << "Iveskite egzamino rezultata: ";
    cin >> student.egzaminas_;
    if (student.getEgzaminas() < 1 || student.getEgzaminas() > 10) {
        cout << "Netinkamas pazymys, iveskite nauja: ";
        cin >> student.egzaminas_;
    }

    // Patikrinimas, ar įvesti duomenys yra tinkami
    cout << "Patikrinkime ivestus duomenis:" << endl;
    cout << "Vardas: " << student.vardas_ << endl;
    cout << "Pavarde: " << student.pav_ << endl;
    cout << "Namu darbai: ";
    for (int pazymys : student.nd_) {
        cout << pazymys << " ";
    }
    cout << endl;
    cout << "Egzamino rezultatas: " << student.egzaminas_ << endl;
}
