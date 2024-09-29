#include "header.h"
#include "Struct.h"
#include <limits>
string choice;

int main() {
    vector<Stud> v1;
    Stud Temp;
    int n,pasirinkimas;
    string file_choice,output_choice;
    //Pasirinkimas skaiciuoti vidurki ar mediana

    do {
        cout<<"Meniu:"<<endl;
        cout<<"1:  Skaityti duomenis is failo"<<endl;
        cout<<"2:  Ivesti duomenis ranka"<<endl;
        cout<<"3:  Generuoti failus"<<endl;
        cout<<"10: Baigti programa"<<endl;
        cout<<"Iveskite pasirinkima:"<<endl;
        while (!(cin >> pasirinkimas))
            {
            cout<< "Klaida. Prasome ivesti skaiciu, atitinkanti meniu opcijas"<< endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (pasirinkimas) {
            case 1: {
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
                string tekstinis;
                try{
                    cout<<"Iveskite failo pavadinima"<<endl;
                    cin>>tekstinis;
                    std::ifstream infile(tekstinis);
                    string eilute;
                    if (!infile.is_open()) {
                        throw std::ios_base::failure("Nepavyko atidaryti failo");
                    }

                    getline(infile,eilute);
                    istringstream iss(eilute);
                    vector<string> tokens;
                    string token;
                    while(iss>>token) {
                        tokens.push_back(token);
                    }
                    int number_of_nd=tokens.size()-3;
                    int lines_num=0;
                    while(getline(infile,eilute)) {
                        istringstream iss(eilute);
                        lines_num++;
                        iss>>Temp.vardas>>Temp.pavarde;
                        Temp.ND.clear();
                        int ivertinimas;
                        for (int i = 0; i < number_of_nd; i++) {
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
                    infile.close();
                    segregacija(v1);
                    isvedimas(v1);
                }
                catch (const std::ios_base::failure& e) {
                    std::terminate();
                }

                break;
            }
            case 2: {
                cout<<"Pasirinkite ka skaiciuoti: 1 - vidurki, 2 - mediana"<<endl;
                while (true) {
                    cin>>choice;
                    if (choice=="1" || choice=="2") {
                        break;
                    }
                    else {
                        cout<<"Neteisingas pasirinkimas, bandykite dar karta. 1-vidurkis, 2-mediana"<<endl;
                    }
                }
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
                segregacija(v1);
                isvedimas(v1);
                break;
            }

            case 3:{
                int number_of_students,number_of_nd;
                string failo_pavadinimas;
                cout<<"Iveskite kiek studentu norite sugeneruoti"<<endl;
                cin>>number_of_students;
                cout<<"Kiek namu darbu norite sugeneruoti?"<<endl;
                cin>>number_of_nd;
                cout<<"Iveskite failo pavadinima"<<endl;
                cin>>failo_pavadinimas;
                generavimas(number_of_students,failo_pavadinimas,number_of_nd);

                break;

            }
        }
    }
    while (pasirinkimas!=10);
    system("pause");
    return 0;
    }

