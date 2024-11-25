#include "header.h"
    struct Stud {
        string vardas;
        string pavarde;
        vector<double> ND;
        double vid;              
        double med;              
        double egz;              
        double rez;              
    };
    void ived(Stud & Lok);
    void vidurkis(Stud & Lok);
    void output(list <Stud> & Lok);
    void val(Stud & Lok);
    void mediana(Stud & Lok);
    void output2(list<Stud> Lok,const string& file_name);
    void generavimas(int n,string failo_pavadinimasm, int number_of_nd);
    void isvedimas(list <Stud> Lok);
    void segregacija(list <Stud> &Lok);
    std::chrono::steady_clock::time_point  DabartinisLaikas();
    double Skirtumas(std::chrono::steady_clock::time_point pradzia, std::chrono::steady_clock::time_point pabaiga);
    list<Stud> nuskaitymas_is_failo(string file_name);
    void output_times(int lines_num,double nuskaitymo_failo_t, double sort_t, double segregacija_t, double slabakai_output_t, double ramiakai_output_t);