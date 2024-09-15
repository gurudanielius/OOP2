#include "Struct.h"
#include "header.h"
void ived(Stud & Lok)
{
    cout<<"Vardas: "<<endl;
    cin>>Lok.vardas;
    cout<<"Pavarde: "<<endl;
    cin>>Lok.pavarde;
    cout<<"Iveskite namu darbu rezultatus: "<<endl;
    double temp;
    while (cin>>temp) {
        Lok.ND.push_back(temp);
    }
    cin.clear();
    if (choice=="V") {
        Lok.med=0;
        Lok.vid=0;
        for (int i=0;i<Lok.ND.size();i++) {
            Lok.vid+=Lok.ND.at(i);
        }
        Lok.vid=Lok.vid/Lok.ND.size();

    }
    else {

        Lok.vid=0;
        sort(Lok.ND.begin(), Lok.ND.end());
        if (Lok.ND.size()%2==0) {
            Lok.med=(Lok.ND.at(Lok.ND.size()/2-1)+Lok.ND.at(Lok.ND.size()/2))/2;
        }
        else {
            Lok.med=Lok.ND.at(Lok.ND.size()/2);
        }
    }
}


void output(Stud Lok) {
    if (Lok.vid==0) {
        cout<<setw(10)<<Lok.vardas << "    "
             <<setw(10)<<Lok.pavarde << "    "
             <<setw(10)<<Lok.med<<endl;
    }
    else {
        cout<<setw(10)<<Lok.vardas << "    "
            <<setw(10)<<Lok.pavarde << "    "
            <<setw(10)<<Lok.vid<<endl;
    }
}
void val(Stud & Lok) {
    Lok.vardas.clear();
    Lok.pavarde.clear();
    Lok.ND.clear();
}
