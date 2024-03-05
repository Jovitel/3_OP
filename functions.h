#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <istream>
#include <sstream>
#include <numeric>
#include <stdexcept>
#include <bits/stdc++.h>
#include <chrono>

using namespace std;

const int MAX_ND = 100;

struct duomenys {
    std::string vard, pav;
    std::vector<int> nd;
    int egzaminas;
    double gal_vid, gal_bal, gal_med;
    int nd_kiekis;
};

void func_input_hands();
void func_generate_numbers();
void func_generate_names();
void func_input_file();
void func_generate();

#endif /* FUNCTIONS_H */

