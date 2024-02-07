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
  int sum;
  double gal_vid;
  int gal_med;
};
 duom duomenys [N];
int main()
{
  int n, sum=0, m;
  cout<<"keliu mokiniu skaiciuosite pazymius? "<<endl;
  cin>>n;
  cout<<"kiek irasysite namu darbu rezultatu? "<<endl;
  cin>>m;

  for (int i=0; i<=n; i++)
  {
    cout<<"iveskite varda: "<<endl;
    cin>>duomenys[i].vard;
    cout<<"iveskite pavarde: "<<endl;
    cin>>duomenys[i].pav;
    cout<<"iveskite namu darbu rezultatus (1-10): "<<endl;
    cin>>duomenys[i].nd;
    cout<<"iveskite egzamino rezultata (1-10): "<<endl;
    cin>>duomenys[i].egz;
  }
  for (int i=0; i<=m; i++)
  {
    duomenys[i].sum = duomenys[i].sum + duomenys[i].s
  }

  for (int i=0; i<=n; i++)
  {
    cout<<duomenys[i].vard<<" "<<duomenys[i].pav<<" "<<duomenys[i].gal_med<<" "<<duomenys[i].gal_vid<<endl;
  }

  return 0;
}
