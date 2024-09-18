#include "Struct.h"
#include "header.h"
void ived(Stud & Lok)
{
    cout << "Ar norite ivesti pazymius rankiniu budu, ar generuoti atsitiktinai? (Ivesti/Generuoti) " << endl;
    string method;
    cin>>method;
    //Pasirinkimas ivesti/generuoti/nuskaityti
    if (method=="Generuoti") {
        cout<<"Vardas: "<<endl;
        cin>>Lok.vardas;
        cout<<"Pavarde: "<<endl;
        cin>>Lok.pavarde;
        Lok.egz=rand()%10+1;
        cout << "Iveskite pazymiu skaiciu: " << endl;
        int n;
        cin>>n;
        for (int i=0;i<n;i++) {
            Lok.ND.push_back(rand()%10+1);
        }
    }
    else {
        cout<<"Vardas: "<<endl;
        cin>>Lok.vardas;
        cout<<"Pavarde: "<<endl;
        cin>>Lok.pavarde;
        double temp;
        cout<<"Iveskite namu darbu rezultatus noredami uzbaigti paspauskite iveskite bet koki neskaitini simboli: "<<endl;
        while (cin>>temp) {
            Lok.ND.push_back(temp);
        }
        cin.clear();
        cout << "Iveskite egzamino rezultata: " << endl;
        cin>>Lok.egz;
    }


    //Pasirinkimas tarp vidurkio ir medianos
    if (choice=="V") {
        vidurkis(Lok);
    }
    else {

        mediana(Lok);
    }
}


void output(Stud Lok) {
    if (Lok.vid==0) {
        cout<<setw(10)<<Lok.vardas << "    "
             <<setw(10)<<Lok.pavarde << "    "
             <<setw(10)<<fixed<<setprecision(2)<<Lok.med<<endl;
    }
    else {
        cout<<setw(10)<<Lok.vardas << "    "
            <<setw(10)<<Lok.pavarde << "    "
            <<setw(10)<<fixed<<setprecision(2)<<Lok.vid<<endl;
    }
}
void val(Stud & Lok) {
    Lok.vardas.clear();
    Lok.pavarde.clear();
    Lok.ND.clear();
}
void vidurkis(Stud &Lok) {
    Lok.med=0;
    Lok.vid=0;
    for (int i=0;i<Lok.ND.size();i++) {
        Lok.vid+=Lok.ND.at(i);
    }
    Lok.vid=Lok.vid/Lok.ND.size();
    Lok.rez=0.4*Lok.vid+0.6*Lok.egz;
}
void mediana(Stud &Lok) {
    Lok.vid=0;
    sort(Lok.ND.begin(), Lok.ND.end());
    if (Lok.ND.size()%2==0) {
        Lok.med=(Lok.ND.at(Lok.ND.size()/2-1)+Lok.ND.at(Lok.ND.size()/2))/2;
    }
    else {
        Lok.med=Lok.ND.at(Lok.ND.size()/2);
    }
    Lok.rez=0.4*Lok.med+0.6*Lok.egz;

}
