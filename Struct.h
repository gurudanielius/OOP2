#include "header.h"

class zmogus {
 protected:
	string vardas;
	string pavarde;
 public:
	string getVardas() const { return vardas; }
	string getPavarde() const { return pavarde; }
	void setVardas(string vardas) { this->vardas = vardas; }
	void setPavarde(string pavarde) { this->pavarde = pavarde; }
	virtual void abstraktiFunkcija() const = 0;
};
class Stud : public zmogus {
	vector<double> ND;
	double egz;
public:
	void abstraktiFunkcija() const override {

	}
	double vid;
	double med;
	double rez;
	~Stud() { }
	Stud() : egz(0) { };
	Stud(std::istream& is);
	vector<double> getND() const { return ND; }
	double getEgz() const { return egz; }
	void setND(vector<double> ND) { this->ND = ND; }
	void setEgz(double egz) { this->egz = egz; }
	Stud(const Stud& a) {
		this->vardas = a.vardas;
		this->pavarde = a.pavarde;
		this->ND = a.ND;
		this->egz = a.egz;
		this->vid = a.vid;
		this->med = a.med;
		this->egz = a.egz;
		this->rez = a.rez;
	}
	Stud& operator=(const Stud& a) {
		if (this == &a) return *this;
		this->vardas = a.vardas;
		this->pavarde = a.pavarde;
		this->ND = a.ND;
		this->egz = a.egz;
		this->vid = a.vid;
		this->med = a.med;
		this->rez = a.rez;
		return *this;
	}
};

    void ived(Stud & Lok);
    void vidurkis(Stud & Lok);
    void output(list <Stud> & Lok);
	void val(Stud & Lok);
    void mediana(Stud & Lok);
    void output2(list<Stud> Lok,const string& file_name);
    void generavimas(int n,string failo_pavadinimasm, int number_of_nd);
    void segregacija(list <Stud> &Lok);
    std::chrono::steady_clock::time_point  DabartinisLaikas();
    double Skirtumas(std::chrono::steady_clock::time_point pradzia, std::chrono::steady_clock::time_point pabaiga);
    list<Stud> nuskaitymas_is_failo(string file_name);
    void output_times(int lines_num,double nuskaitymo_failo_t, double sort_t, double segregacija_t, double slabakai_output_t, double ramiakai_output_t);