#include "header.h"
    struct Stud {
        string vardas;
        string pavarde;
        vector<double> ND;        // Grades for homework
        double vid;                    // Average grade
        double med;                    // Median grade
        double egz;                    // Exam grade
        double rez;                    // Final result
    };
    void ived(Stud & Lok);
    void output(Stud Lok);
    void val(Stud & Lok);
