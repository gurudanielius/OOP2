#include "header.h"
class Stud {
	string vardas;
        string pavarde;
        vector<double> ND;
        double egz;

public:
    double vid;
    double med;
    double rez;
~Stud() { }
	Stud() : egz(0) { };
	Stud(std::istream& is);
	string getVardas() const { return vardas; }
	string getPavarde() const { return pavarde; }
	vector<double> getND() const { return ND; }
	double getEgz() const { return egz; }
    void setVardas(string vardas) { this->vardas = vardas; }
	void setPavarde(string pavarde) { this->pavarde = pavarde; }
	void setND(vector<double> ND) { this->ND = ND; }
	void setEgz(double egz) { this->egz = egz; }
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