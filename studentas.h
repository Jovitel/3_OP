#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <vector>
#include <string>
#include <iostream>

const int MAX_ND = 100;

class Zmogus {
protected:
    std::string vardas_, pav_; // Privatūs nariai, kurie saugo žmogaus vardą ir pavardę
    
    Zmogus() = default;  // Standartinis konstruktorius, inicializuoja vardą ir pavardę
    // Konstruktorius, kuris inicializuoja vardą ir pavardę pagal pateiktus parametrus
    Zmogus(const std::string& vardas, const std::string& pav) 
    : vardas_(vardas), pav_(pav) {}
    // Virtualus destruktorius, leidžiantis paveldėtoms klasėms tvarkyti atminties išlaisvinimą
    virtual ~Zmogus() {}

public:
    // Virtualus get metodai, gražinantys vardą arba pavarde
    virtual const std::string& getVardas() const { return vardas_; }
    virtual const std::string& getPavarde() const { return pav_; }
    // Virtualus set metodai, nustatantys varda arba pavarde
    virtual void setVardas(const std::string& vardas) { vardas_ = vardas; }
    virtual void setPavarde(const std::string& pavarde) { pav_ = pavarde; }
};

class Studentas : public Zmogus {
private:
    std::vector<int> nd_;
    int egzaminas_, nd_kiekis_;
    double gal_vid_, gal_bal_, gal_med_;

public:
    bool operator<(const Studentas& other) const {
        return gal_vid_ < other.gal_vid_;
    }

    Studentas() : egzaminas_(0), nd_kiekis_(0), gal_vid_(0), gal_bal_(0), gal_med_(0) {}

    Studentas(const std::string& vardas, const std::string& pav, int egzaminas, const std::vector<int>& nd, int nd_kiekis, double gal_vid, double gal_med) 
        : Zmogus(vardas, pav), nd_(nd), egzaminas_(egzaminas), nd_kiekis_(nd_kiekis), 
        gal_vid_(gal_vid), gal_med_(gal_med) {}

    ~Studentas() {}

    // COPY KONSTRUKTORIUS
    Studentas(const Studentas& other)
        : Zmogus(other.getVardas(), other.getPavarde()), nd_(other.nd_), egzaminas_(other.egzaminas_), 
        nd_kiekis_(other.nd_kiekis_), gal_vid_(other.gal_vid_), gal_bal_(other.gal_bal_), gal_med_(other.gal_med_) {}

    // COPY PRISKYRIMO OPERATORIUS
    Studentas& operator=(const Studentas& other)
    {
        if (this != &other) {
            setVardas(other.getVardas());
            setPavarde(other.getPavarde());
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
        : Zmogus(std::move(other.vardas_), std::move(other.pav_)), nd_(std::move(other.nd_)), 
        egzaminas_(std::move(other.egzaminas_)), nd_kiekis_(std::move(other.nd_kiekis_)), 
        gal_vid_(std::move(other.gal_vid_)), gal_bal_(std::move(other.gal_bal_)), gal_med_(std::move(other.gal_med_))
    {
        other.vardas_ = "";
        other.pav_ = "";
        other.egzaminas_ = 0;
        other.nd_kiekis_ = 0;
        other.gal_vid_ = 0;
        other.gal_bal_ = 0;
        other.gal_med_ = 0;
    }

    // MOVE PRISKYRIMO OPERATORIUS
    Studentas& operator=(Studentas&& other) noexcept
    {
        if (this != &other) {
            setVardas(std::move(other.getVardas()));
            setPavarde(std::move(other.getPavarde()));
            nd_ = std::move(other.nd_);
            egzaminas_ = std::move(other.egzaminas_);
            nd_kiekis_ = std::move(other.nd_kiekis_);
            gal_vid_ = std::move(other.gal_vid_);
            gal_bal_ = std::move(other.gal_bal_);
            gal_med_ = std::move(other.gal_med_);

            other.vardas_ = "";
            other.pav_ = "";
            other.egzaminas_ = 0;
            other.nd_kiekis_ = 0;
            other.gal_vid_ = 0;
            other.gal_bal_ = 0;
            other.gal_med_ = 0;
        }
        return *this;
    }

    const std::string& getVardas() const override { return Zmogus::getVardas(); }
    const std::string& getPavarde() const override { return Zmogus::getPavarde(); }
    const std::vector<int>& getNd() const { return nd_; }
    int getEgzaminas() const { return egzaminas_; }
    double getGalutinisVid() const { return gal_vid_; }
    double getGalutinisBal() const { return gal_bal_; }
    double getGalutineMed() const { return gal_med_; }
    int getNdKiekis() const { return nd_kiekis_; }

    void setVardas(const std::string& vardas) override { Zmogus::setVardas(vardas); }
    void setPavarde(const std::string& pavarde) override { Zmogus::setPavarde(pavarde); }
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

    // Input
    friend std::istream& operator>>(std::istream& in, Studentas& studentas) {
        in >> studentas.vardas_ >> studentas.pav_;

        int pazymys;
        studentas.nd_.clear(); // Išvalome namų darbų sąrašą
        while (in >> pazymys && pazymys >= 0) {
            studentas.addnd(pazymys); // Pridedame naują namų darbo pažymį
        }

        in >> studentas.egzaminas_; // Skaitome egzamino rezultatą

        return in;
    }

    // Output
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
