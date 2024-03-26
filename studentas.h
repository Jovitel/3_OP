#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <vector>
#include <string>

const int MAX_ND = 100;

class Studentas {
private:
    std::string vardas_, pav_, rusis_;
    std::vector<int> nd_;
    int egzaminas_, nd_kiekis_;
    double gal_vid_, gal_bal_, gal_med_;

public:
    bool operator<(const Studentas& other) const {
        return gal_vid_ < other.gal_vid_;
    }

    const std::string& getVardas() const { return vardas_; }
    const std::string& getPavarde() const { return pav_; }
    const std::vector<int>& getNd() const { return nd_; }
    int getEgzaminas() const { return egzaminas_; }
    double getGalutinisVid() const { return gal_vid_; }
    double getGalutinisBal() const { return gal_bal_; }
    double getGalutineMed() const { return gal_med_; }
    int getNdKiekis() const { return nd_kiekis_; }
    const std::string& getRusis() const { return rusis_; }

    void setVardas(const std::string& vardas) { vardas_ = vardas; }
    void setPavarde(const std::string& pavarde) { pav_ = pavarde; }
    void setNd(const std::vector<int>& nd) { nd_ = nd; }
    void setEgzaminas(int egzaminas) { egzaminas_ = egzaminas; }
    void setGalutinisVid(double gal_vid) { gal_vid_ = gal_vid; }
    void setGalutinisBal(double gal_bal) { gal_bal_ = gal_bal; }
    void setGalutineMed(double gal_med) { gal_med_ = gal_med; }
    void setNdKiekis(int nd_kiekis) { nd_kiekis_ = nd_kiekis; }
    void setRusis(const std::string& rusis) { rusis_ = rusis; }
};

#endif /* STUDENTAS_H */
