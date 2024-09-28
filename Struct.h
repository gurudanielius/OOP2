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
    void output(Stud Lok);
    void val(Stud & Lok);
    void mediana(Stud & Lok);
    void output2(vector<Stud> Lok);
    void generavimas(int n,string failo_pavadinimasm, int number_of_nd);
    void isvedimas(vector <Stud> Lok);
