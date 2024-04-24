#include "functions.h"

int main() {
    int choice;

    cout << "Pasirinkite, kaip norite įvesti studentų duomenis: " << endl;
    cout << "1 - ranka" << endl;
    cout << "2 - Sugeneruoti pažymius" << endl;
    cout << "3 - Sugeneruoti pažymius ir vardus" << endl;
    cout << "4 - Užbaigti programą" << endl;
    cout << "5 - Duomenis nuskaityti iš failo" << endl;
    cout << "6 - Generuoti failus " << endl;
    cout << "7 - Rule of 5" << endl;
    cin >> choice;

    while (cin.fail() || (choice < 1 || choice > 7)) {
        cout << "Netinkamas pasirinkimas. Įveskite 1, 2, 3, 4, 5, 6 arba 7";
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
    } else if (choice == 5) {
        func_input_file();
    } else if (choice == 6) {
        func_generate();
    } else if (choice == 7) {
        func_tests();
        func_input_output();
    } 


    return 0;
}