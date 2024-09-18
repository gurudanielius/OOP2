#include "Struct.h"
#include "header.h"
void ived(Stud & Lok)
{
    cout << "Ar norite ivesti pazymius rankiniu budu, ar generuoti atsitiktinai? (Ivesti/Generuoti) " << endl;
    string method;
    while (true) {
        cin>>method;

        if (method=="Ivesti" || method=="Generuoti"||method=="ivesti"||method=="generuoti") {
            break;
        }
        else {
            cout<<"Neteisingas pasirinkimas, bandykite dar karta. Kaip norite ivesti pazymius\nGeneruoti/Ivesti?"<<endl;
        }
    }
    //Pasirinkimas ivesti/generuoti/nuskaityti
    if (method=="Generuoti"||method=="generuoti") {
        cout<<"Vardas: "<<endl;
        cin>>Lok.vardas;
        cout<<"Pavarde: "<<endl;
        cin>>Lok.pavarde;
        Lok.egz=rand()%10+1;
        int n;
        cout << "Iveskite pazymiu skaiciu: " << endl;
        while (true) {
            if(cin>>n) {
                break;
            }
            else {
                cin.clear();
                cout << "Reikia ivesti skaiciu. Iveskite pazymiu skaiciu." << endl;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            }
        }
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
        cout<<"Iveskite namu darbu rezultatus noredami uzbaigti iveskite -1: "<<endl;
        while (true) {

            if(cin>>temp && temp>=1 && temp<=10) {
                Lok.ND.push_back(temp);
            }
            else if (temp==-1) {
                break;
            }
            else {
                cin.clear();
                cout<<"Iveskite tinkama pazymi nuo 1 iki 10. Noredami uzbaigti iveskite -1"<<endl;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        cout << "Iveskite egzamino rezultata: " << endl;
        while(true) {
            if(cin>>Lok.egz && Lok.egz>=1 && Lok.egz<=10) {
                break;
            }
            else {
                cin.clear();
                cout << "Reikia ivesti skaiciu nuo 1 iki 10. Iveskite egzamino rezultata." << endl;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }

    //Pasirinkimas tarp vidurkio ir medianos
    if (choice=="V") {
        vidurkis(Lok);
    }
    if (choice=="M") {

        mediana(Lok);
    }
}
void output(Stud Lok) {
    if (Lok.vid==0) {
        cout<<left<<setw(10)<<Lok.vardas << "    "
            <<left<<setw(10)<<Lok.pavarde << "    "
            <<left<<setw(10)<<fixed<<setprecision(2)<<Lok.med<<endl;
    }
    else {
        cout<<left<<setw(10)<<Lok.vardas << "    "
            <<left<<setw(10)<<Lok.pavarde << "    "
            <<left<<setw(10)<<fixed<<setprecision(2)<<Lok.vid<<endl;
    }


}
void output2(vector<Stud> Lok){
    std::ofstream outputFile;
    outputFile.open("C:/Users/danie/OneDrive/Stalinis kompiuteris/OOP-v.pradin-/rezultatai.txt");
    if (choice=="V") {
        outputFile<<left<<setw(10) << "Vardas" << "    "
            <<left<<setw(10) << "Pavarde" << "    "
            <<left<<setw(10) << "Galutinis (Vid.)" << endl;
        outputFile << "-----------------------------------------------" << endl;

    }
    else {
        outputFile<<left<<setw(10) << "Vardas" << "    "
             <<left<<setw(10) << "Pavarde" << "    "
             <<left<<setw(10) << "Galutinis (Med.)" << endl;
    }

    if (outputFile.is_open()) {
        for (int i=0;i<Lok.size();i++) {
            outputFile<<left<<setw(10)<<Lok.at(i).vardas << "    "
                <<left<<setw(10)<<Lok.at(i).pavarde << "    "
                <<left<<setw(10)<<fixed<<setprecision(2)<<Lok.at(i).vid<<endl;
        }
        outputFile.close();
        cout << "Data written to the file successfully." << std::endl;
    }
    else {
        cout << "Unable to open the file!" << std::endl;
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
