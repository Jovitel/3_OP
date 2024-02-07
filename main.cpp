#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>

using namespace std;

const int N=100;
struct duom
{
  string pav;
  string vard;
  int nd;
  int egz;
};
 duom duomenys [N];
int main()
{
  int n;
  cout<<"keliu mokiniu skaiciuosite pazymius? "<<endl;
  cin>>n;

  for (int i=0; i<=n; i++)
  {
    cout<<"iveskite varda: "<<endl;
    cin>>duomenys[i].vard;
    cout<<"iveskite pavarde: "<<endl;
    cin>>duomenys[i].pav;
    cout<<"iveskite namu darbu rezultata: "<<endl;
    cin>>duomenys[i].nd;
    cout<<"iveskite egzamino rezultata: "<<endl;
    cin>>duomenys[i].egz;
  }

  return 0;
}
