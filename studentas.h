#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <vector>
#include <string>
#include <iostream>

const int MAX_ND = 100;

class Studentas {
 private:
    std::string vardas_, pav_;
    std::vector<int> nd_;
    int egzaminas_, nd_kiekis_;
    double gal_vid_, gal_bal_, gal_med_;

 public:
    bool operator<(const Studentas& other) const {
        return gal_vid_ < other.gal_vid_;
    }

    Studentas() : egzaminas_(0), nd_kiekis_(0), gal_vid_(0), gal_bal_(0), gal_med_(0) {}

    Studentas(const std::string& vardas, const std::string& pav, int egzaminas, const std::vector<int>& nd, int nd_kiekis, double gal_vid, double gal_med) 
        : vardas_(vardas), pav_(pav), egzaminas_(egzaminas), nd_(nd), nd_kiekis_(nd_kiekis), 
        gal_vid_(gal_vid), gal_med_(gal_med) {}

    ~Studentas() {nd_.clear();}
    //COPY KONSTRUKTORIUS
    Studentas(const Studentas& other)
        : vardas_(other.vardas_), pav_(other.pav_), nd_(other.nd_), egzaminas_(other.egzaminas_),
        nd_kiekis_(other.nd_kiekis_),gal_vid_(other.gal_vid_), gal_bal_(other.gal_bal_), gal_med_(other.gal_med_) {}

    Studentas& operator = (const Studentas& other)
    {
         if (this != &other) {
            vardas_ = other.vardas_;
            pav_ = other.pav_;
            nd_ = other.nd_;
            egzaminas_ = other.egzaminas_;
            nd_kiekis_ = other.nd_kiekis_;
            gal_vid_ = other.gal_vid_;
            gal_bal_ = other.gal_bal_;
            gal_med_ = other.gal_med_;
        }
        return *this;
    }
   // MOVE KONSTRUKTORIUS
    Studentas(Studentas&& other) noexcept
    : vardas_(std::move(other.vardas_)), pav_(std::move(other.pav_)),
      nd_(std::move(other.nd_)), egzaminas_(other.egzaminas_),
      nd_kiekis_(other.nd_kiekis_), gal_vid_(other.gal_vid_), 
      gal_bal_(other.gal_bal_), gal_med_(other.gal_med_) {
    // Nustatome kitų objekto narių reikšmes į pradines
    other.egzaminas_ = 0;
    other.nd_kiekis_ = 0;
    other.gal_vid_ = 0;
    other.gal_bal_ = 0;
    other.gal_med_ = 0;
    }


 Studentas& operator=(Studentas&& other) noexcept {
        if (this != &other) {
            vardas_ = std::move(other.vardas_);
            pav_ = std::move(other.pav_);
            nd_ = std::move(other.nd_);
            egzaminas_ = other.egzaminas_;
            nd_kiekis_ = other.nd_kiekis_;
            gal_vid_ = other.gal_vid_;
            gal_bal_ = other.gal_bal_;
            gal_med_ = other.gal_med_;

            // Nustatome kitų objekto narių reikšmes į pradines
            other.egzaminas_ = 0;
            other.nd_kiekis_ = 0;
            other.gal_vid_ = 0;
            other.gal_bal_ = 0;
            other.gal_med_ = 0;
        }
        return *this;
    }
    const std::string& getVardas() const { return vardas_; }
    const std::string& getPavarde() const { return pav_; }
    const std::vector<int>& getNd() const { return nd_; }
    int getEgzaminas() const { return egzaminas_; }
    double getGalutinisVid() const { return gal_vid_; }
    double getGalutinisBal() const { return gal_bal_; }
    double getGalutineMed() const { return gal_med_; }
    int getNdKiekis() const { return nd_kiekis_; }

    void setVardas(const std::string& vardas) { vardas_ = vardas; }
    void setPavarde(const std::string& pavarde) { pav_ = pavarde; }
    void setNd(const std::vector<int>& nd) { nd_ = nd; nd_kiekis_ = nd.size(); skaiciuotiGalutiniBal(); }
    void setEgzaminas(int egzaminas) { egzaminas_ = egzaminas; }
    void setGalutinisVid(double gal_vid) { gal_vid_ = gal_vid; }
    void setGalutinisBal(double gal_bal) { gal_bal_ = gal_bal; }
    void setGalutineMed(double gal_med) { gal_med_ = gal_med; }
    void setNdKiekis(int nd_kiekis) { nd_kiekis_ = nd_kiekis; }

    void addnd(int nd) { nd_.push_back(nd); nd_kiekis_++; skaiciuotiGalutiniBal(); }

    void skaiciuotiGalutiniBal() {
        if (nd_.empty()) {
            gal_bal_ = egzaminas_;
            return;
        }
        double suma = 0;
        for (int pazymys : nd_) {
            suma += pazymys;
        }
        gal_bal_ = 0.4 * (suma / nd_.size()) + 0.6 * egzaminas_;
    }

    //Input
    friend std::istream& operator>>(std::istream& in, Studentas& studentas) {
        in >> studentas.vardas_ >> studentas.pav_;

        int pazymys;
        studentas.nd_.clear(); // Išvalome namų darbų sąrašą
        while (in >> pazymys && pazymys >= 0)
        {
            studentas.addnd(pazymys); // Pridedame naują namų darbo pažymį
        }

        in >> studentas.egzaminas_; // Skaitome egzamino rezultatą

        return in;
    }


    //Output
    friend std::ostream& operator<<(std::ostream& out, const Studentas& studentas) {
        out << "Vardas: " << studentas.vardas_ << std::endl;
        out << "Pavarde: " << studentas.pav_ << std::endl;
        out << "Namu darbai: ";
        for (int pazymys : studentas.nd_) {
            out << pazymys << " ";
        }
        out << std::endl;
        out << "Egzamino rezultatas: " << studentas.egzaminas_ << std::endl;
        return out;
    }

};
#endif /* STUDENTAS_H */
