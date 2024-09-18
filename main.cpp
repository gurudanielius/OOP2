#include "header.h"
#include "Struct.h"'
string choice;

int main() {
    vector<Stud> v1;
    Stud Temp;
    int n;
    string file_choice,output_choice;

    cout<<"Pasirinkite ka skaiciuoti: V - vidurki, M - mediana"<<endl;
    while (true) {
        cin>>choice;
        if (choice=="V" || choice=="M") {
            break;
        }
        else {
            cout<<"Neteisingas pasirinkimas, bandykite dar karta. V-vidurkis, M-mediana"<<endl;
        }
    }
    cout << "Ar skaityti duomenis is failo? taip/ne" << endl;
    while (true) {
        cin>>file_choice;
        if (file_choice=="taip" || file_choice=="ne") {
            break;
        }
        else {
            cout<<"Neteisingas pasirinkimas, bandykite dar karta. taip/ne"<<endl;
        }
    }
    if (file_choice=="ne") {
        cout<<"Iveskite studentu skaiciu"<<endl;
        while(true) {
            if (cin>>n) {
                break;
            }
            cin.clear();
            cout << "Reikia ivesti skaiciu. Iveskite studentu skaiciu." << endl;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        for (int i=0;i<n;i++) {
            ived(Temp);
            v1.push_back(Temp);
            val(Temp);
        }
    }
    if(file_choice=="taip") {
        string tekstinis;
        try{
            std::ifstream infile("C:/Users/danie/OneDrive/Stalinis kompiuteris/OOP-v.pradin-/studentai10000000.txt");
            string eilute;
            if (!infile.is_open()) {
                throw std::ios_base::failure("Nepavyko atidaryti failo");
            }
            getline(infile,eilute);

            int lines_num=0;
            while(getline(infile,eilute)) {
                lines_num++;
                istringstream iss(eilute);
                iss>>Temp.vardas>>Temp.pavarde;
                Temp.ND.clear();
                int ivertinimas;
                for (int i = 0; i < 5; i++) {
                    iss >> ivertinimas;
                    Temp.ND.push_back(ivertinimas);
                }
                iss >> Temp.egz;
                if (choice=="V") {
                    vidurkis(Temp);
                }
                else {
                    mediana(Temp);
                }
                v1.push_back(Temp);
                val(Temp);
            }
            n=lines_num;
            infile.close();
        }
        catch (const std::ios_base::failure& e) {
            std::terminate();
        }
    }
    //Isvedimas
    cout<<"Ar norite isvesti i faila? taip/ne "<<endl;
    while (true) {
        cin>>output_choice;
        if (output_choice=="taip" ||output_choice=="ne") {
            break;
        }
        else {
            cout<<"Neteisingas pasirinkimas, bandykite dar karta. taip/ne"<<endl;
        }
    }
    if (file_choice=="ne") {
        if (choice=="V") {
            cout <<left<<setw(10) << "Vardas" << "    "
                 <<left<<setw(10) << "Pavarde" << "    "
                 <<left<<setw(10) << "Galutinis (Vid.)" << endl;
        }
        else {
            cout <<left<<setw(10) << "Vardas" << "    "
                 <<left<<setw(10) << "Pavarde" << "    "
                 <<left<<setw(10) << "Galutinis (Med.)" << endl;
        }
        cout << "-----------------------------------------------" << endl;
        sort(v1.begin(), v1.end(), [](const Stud &a, const Stud &b) {
            return a.vardas < b.vardas;
        });
        for (int i=0;i<n;i++) {
            output(v1.at(i));
        }
    }
        else {
            output2(v1);
            system("pause");
            return 0;
        }
    }





