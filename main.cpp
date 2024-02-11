#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <vector>
#include <algorithm>

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
  double gal_bal;
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
    for (int j=0; j<=m; j++)
    {
      cout<<"iveskite namu darbu rezultatus (1-10): "<<endl;
      cin>>duomenys[i].nd;
      duomenys[i].sum += duomenys[i].nd;
    }
    cout<<"iveskite egzamino rezultata (1-10): "<<endl;
    cin>>duomenys[i].egz;
    duomenys[i].gal_vid = duomenys[i].sum / m;
    duomenys[i].gal_bal = 0.4 * duomenys[i].gal_vid + 0.6 * duomenys[i].egz;
  } 

  for (int i=0; i<=n; i++)
  {
        vector<int> pazymiai;                 //sukuriamas vektorius, kuriame bus pazymiai visi
        pazymiai.push_back(duomenys[i].egz);  //idedami egzamino rezultatai
        for (int j=0; j<m; j++)               //idedami namu darbu rezultatai
        {
            pazymiai.push_back(duomenys[i].nd);
        }
        
        sort(pazymiai.begin(), pazymiai.end());//surusiuojam eiles tvarka
      
        int size = pazymiai.size();
        if (size % 2 == 0)                     //tikrina lyginis ar nelyginis skacius
        {
            duomenys[i].gal_med = (pazymiai[size / 2 - 1] + pazymiai[size / 2]) / 2;
        }
        else
        {
            duomenys[i].gal_med = pazymiai[size / 2];
        }
  }

  for (int i=0; i<=n; i++)
  {
    
    cout<<duomenys[i].vard<<" "<<duomenys[i].pav<<" "<<setprecision(2)<<duomenys[i].gal_bal<<" "<<duomenys[i].gal_med<<endl;
  }

  return 0;
}
