#include "functions.h"

int main() {
    int choice;

    cout << "Pasirinkite, kaip norite įvesti studentų duomenis: " << endl;
    cout << "1 - ranka" << endl;
    cout << "2 - Sugeneruoti pažymius" << endl;
    cout << "3 - Sugeneruoti pažymius ir vardus" << endl;
    cout << "4 - užbaigti programą" << endl;
    cout << "5 - duomenis nuskaityti iš failo" << endl;
    cin >> choice;

    while (cin.fail() || (choice < 1 || choice > 5)) {
        cout << "Netinkamas pasirinkimas. Įveskite 1, 2, 3, 4 arba 5: ";
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
    }

    return 0;
}