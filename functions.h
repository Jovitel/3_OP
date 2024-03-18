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
#include <list>
#include <deque>

using namespace std;

const int MAX_ND = 100;

struct duomenys {
    std::string vard, pav;
    std::vector<int> nd;
    int egzaminas;
    double gal_vid, gal_bal, gal_med;
    int nd_kiekis;
    string rusis;

     bool operator<(const duomenys& other) const {
        return gal_vid < other.gal_vid;
    }
};

void func_input_hands();
void func_generate_numbers();
void func_generate_names();
void func_input_file();
void func_generate();
void generate_new_file();
//3 STRATEGIJA
void use_existing_file();
void read_list();
void read_deque(); 
//2 STRATEGIJA
void use_existing_file_2();
void read_list_2();
void read_deque_2(); 
//3 STRATEGIJA
void use_existing_file_3();
void read_list_3();
void read_deque_3(); 
#endif /* FUNCTIONS_H */