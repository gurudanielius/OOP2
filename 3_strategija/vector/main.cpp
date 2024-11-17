#include "header.h"
#include "Struct.h"
#include <limits>
string choice;
double nuskaitymo_failo_t, generavimo_failo_t, segregacija_t, sort_t, slabakai_output_t, ramiakai_output_t;
int lines_num;

int main() {
    Stud Temp;
    list<Stud> v1;
    int pasirinkimas,number_of_nd,number_of_students;
    string file_choice,output_choice,failo_pavadinimas;
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
                cout<<"Pasirinkite pagal ka skaiciuoti galutini: 1 - vidurki, 2 - mediana"<<endl;
                while (true) {
                    cin>>choice;
                    if (choice=="1" || choice=="2") {
                        break;
                    }
                    else {
                        cout<<"Neteisingas pasirinkimas, bandykite dar karta. 1-vidurkis, 2-mediana"<<endl;
                    }
                }
                string tekstinis;
                cout<<"Iveskite failo pavadinima"<<endl;
                cin>>tekstinis;
                auto t1_nuskaitymas=DabartinisLaikas();
                v1=nuskaitymas_is_failo(tekstinis);
                auto t2_nuskaitymas=DabartinisLaikas();
                segregacija(v1);
                nuskaitymo_failo_t=Skirtumas(t1_nuskaitymas,t2_nuskaitymas);
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
                    if (cin>>lines_num) {
                        break;
                    }
                    cin.clear();
                    cout << "Reikia ivesti skaiciu. Iveskite studentu skaiciu." << endl;
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                for (int i=0;i<lines_num;i++) {
                    ived(Temp);
                    v1.push_back(Temp);
                    val(Temp);
                }
                segregacija(v1);

                //output

                output(v1);
                break;
            }
            case 3:{
                cout<<"Iveskite kiek studentu norite sugeneruoti"<<endl;
                cin>>number_of_students;
                cout<<"Kiek namu darbu norite sugeneruoti?"<<endl;
                cin>>number_of_nd;
                cout<<"Iveskite failo pavadinima"<<endl;
                cin>>failo_pavadinimas;
                auto generavimo_t1=DabartinisLaikas();
                generavimas(number_of_students,failo_pavadinimas,number_of_nd);
                auto generavimo_t2=DabartinisLaikas();
                generavimo_failo_t=Skirtumas(generavimo_t1,generavimo_t2);
                break;
            }
            case 10: {
                cout<<"Failas uzdarytas"<< endl;
        }
        }

    }
    while (pasirinkimas!=10);
    if (generavimo_failo_t!=0) {
        lines_num=number_of_students;
        cout<<lines_num<<" generavimo laikas: "<<generavimo_failo_t<<"s. "<<endl;
    }
    output_times(lines_num,nuskaitymo_failo_t,sort_t,segregacija_t,slabakai_output_t,ramiakai_output_t);

    system("pause");
    return 0;
    }