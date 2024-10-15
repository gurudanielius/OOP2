#include "Struct.h"
#include "header.h"
std::chrono::steady_clock::time_point  DabartinisLaikas() {
    return std::chrono::steady_clock::now();
}
double Skirtumas(const std::chrono::steady_clock::time_point pradzia, const std::chrono::steady_clock::time_point pabaiga) {
    return std::chrono::duration_cast<std::chrono::duration<double>>(pabaiga-pradzia).count();
}
void ived(Stud & Lok)
{
    cout << "Ar norite ivesti pazymius rankiniu budu, ar generuoti atsitiktinai? (1-ivesti/2-Generuoti) " << endl;
    int method;
    while (true) {
        cin>>method;
        if (method==2 || method==1) {
            break;
        }
        else {
            cout<<"Neteisingas pasirinkimas, bandykite dar karta. Kaip norite ivesti pazymius\nGeneruoti/Ivesti?"<<endl;
        }
    }
    //Pasirinkimas ivesti/generuoti/nuskaityti
    if (method==1||method==2) {
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
        cout<<"*********************************"<<endl;

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
    if (choice=="1") {
        vidurkis(Lok);
    }
    if (choice=="2") {
        mediana(Lok);
    }
}
list<Stud> nuskaitymas_is_failo(string tekstinis) {
    try{
        list<Stud> v1;
        Stud Temp;
        std::ifstream infile(tekstinis);
        string eilute,token;
        if (!infile.is_open()) {
            throw std::ios_base::failure("Nepavyko atidaryti failo");
        }

        getline(infile,eilute);
        istringstream iss(eilute);
        vector<string> tokens;
        while(iss>>token) {
            tokens.push_back(token);
        }
        int number_of_nd=tokens.size()-3;
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
            if (choice=="1") {
                vidurkis(Temp);
            }
            else {
                mediana(Temp);
            }
            v1.push_back(Temp);
            val(Temp);
        }
        infile.close();
        lines_num--;
        return v1;
    }
    catch (const std::ios_base::failure& e) {
        std::terminate();
    }
}

// void output(Stud Lok) {
//
//     cout<<left<<setw(15)<<Lok.vardas << "    "
//             <<left<<setw(15)<<Lok.pavarde << "    "
//             <<left<<setw(15)<<fixed<<setprecision(2)<<Lok.med << "    "
//             <<left<<setw(15)<<fixed<<setprecision(2)<<Lok.vid << "    "
//             <<left<<setw(15)<<fixed<<setprecision(2)<<Lok.rez<<endl;
//
// }
void output2(list<Stud> v,const string& file_name){
    std::ofstream outputFile;
    outputFile.open(file_name);
    outputFile<<left<<setw(15) << "Vardas" << "    "
       <<left<<setw(15) << "Pavarde" << "    "
       <<left<<setw(15) << "Vidurkis" << "    "
       <<left<<setw(15) << "Mediana" << "    "
       <<left<<setw(15) << "Galutinis (Vid.)" << endl;
    if (outputFile.is_open()) {
        for (auto it = v.begin(); it != v.end(); ++it) {
    outputFile << left << setw(15) << it->vardas << "    "
               << left << setw(15) << it->pavarde << "    "
               << left << setw(15) << fixed << setprecision(2) << it->vid << "    "
               << left << setw(15) << fixed << setprecision(2) << it->med << "    "
               << left << setw(15) << fixed << setprecision(2) << it->rez << endl;
}
        outputFile.close();
        cout << file_name+ " :Data written to the file successfully." << std::endl;
    }
    else {
        cout << file_name+" :Unable to open the file!" << std::endl;
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
    if (Lok.ND.size()==0) {
        Lok.vid=0;
    }
    sort(Lok.ND.begin(), Lok.ND.end());
    if (Lok.ND.size()%2==0) {
        Lok.med=(Lok.ND.at(Lok.ND.size()/2-1)+Lok.ND.at(Lok.ND.size()/2))/2;
    }
    else {
        Lok.med=Lok.ND.at(Lok.ND.size()/2);
    }
    Lok.rez=0.4*Lok.vid+0.6*Lok.egz;
}
void mediana(Stud &Lok) {
    for (int i=0;i<Lok.ND.size();i++) {
        Lok.vid+=Lok.ND.at(i);
    }
    Lok.vid=Lok.vid/Lok.ND.size();
    if (Lok.ND.size()==0) {
        Lok.vid=0;
    }
    sort(Lok.ND.begin(), Lok.ND.end());
    if (Lok.ND.size()%2==0) {
        Lok.med=(Lok.ND.at(Lok.ND.size()/2-1)+Lok.ND.at(Lok.ND.size()/2))/2;
    }
    else {
        Lok.med=Lok.ND.at(Lok.ND.size()/2);
    }
    Lok.rez=0.4*Lok.med+0.6*Lok.egz;

}
void generavimas(int n, string failo_pavadinimas, int number_of_nd) {
    std::ofstream outputFile;
    outputFile.open(failo_pavadinimas);
    if (!outputFile.is_open()) {
        std::cerr<<"Failas nerastas"<<endl;
    }
    outputFile<<left<<setw(15) << "Vardas" << "    "
        <<left<<setw(15) << "Pavarde";
    for (int i=0;i<number_of_nd;i++) {
        outputFile<<left<<setw(15)<<"ND"+std::to_string(i+1);
    }
    outputFile<<left<<setw(15)<<"Egzaminas"<<endl;
    for (int i=0;i<n+1;i++) {
        outputFile<<left<<setw(15)<<"Vardas"+std::to_string(i+1) << "    "
            <<left<<setw(15)<<"Pavarde"+std::to_string(i+1);
        for (int j=0;j<number_of_nd;j++) {
            outputFile<<left<<setw(15)<<std::to_string(rand()%10+1);
        }
        outputFile<<left<<setw(15)<<rand()%10+1<<endl;
    }
    outputFile.close();
}
// void isvedimas(list<Stud> v1) {
//     string output_choice;
//     cout<<"Ar norite isvesti i faila? taip/ne "<<endl;
//     while (true) {
//         cin>>output_choice;
//         if (output_choice=="taip" ||output_choice=="ne") {
//             break;
//         }
//         else {
//             cout<<"Neteisingas pasirinkimas, bandykite dar karta. taip/ne"<<endl;
//         }
//     }
//     string sort_choice;
//     cout<<"Ar norite isrusiuoti studentus pagal varda? taip/ne "<<endl;
//     cin>>sort_choice;
//     if (sort_choice=="taip") {
//         sort(v1.begin(), v1.end(), [](const Stud &a, const Stud &b) {
//        return a.vardas < b.vardas;
//          });
//     }
//     else if(sort_choice=="ne") {
//         sort(v1.begin(), v1.end(), [](const Stud &a, const Stud &b) {
//             return a.pavarde < b.pavarde;
//         });
//     }
//
//     if (output_choice=="ne") {
//             cout <<left<<setw(10) << "Vardas" << "    "
//                  <<left<<setw(10) << "Pavarde" << "    "
//                  <<left<<setw(10) << "Vidurkis" << "    "
//                  <<left<<setw(10) << "Mediana" << "    "
//                  <<left<<setw(20) << "Galutinis" << endl;
//
//         cout << "-----------------------------------------------" << endl;
//         for (auto it = v1.begin(); it != v1.end(); ++it) {
//             output(*it);
//         }
//     }
//     else {
//         output2(v1,"rezik.txt");
//     }
// }
void segregacija(list<Stud> v1) {
    list<Stud> slabakai, ramiakai;
    auto segregacija_t0=DabartinisLaikas();

    for (auto it =v1.begin(); it!=v1.end(); ++it) {
        if (it->rez<5) {
            slabakai.push_back(*it);
        }
        else {
            ramiakai.push_back(*it);
        }
    }
    auto segregacija_t1=DabartinisLaikas();
    segregacija_t=Skirtumas(segregacija_t0,segregacija_t1);

    cout<<"Pagal ka norite rusiuoti sugrupuotus studentus? (Vardas - 1/Pavarde - 2/ Mediana - 3/Vidurkis - 4/Galutini - 5) "<<endl;
    int rusiavimas;
    cin>>rusiavimas;
    auto sort_t0=DabartinisLaikas();
    if (rusiavimas==1) {
        sort(slabakai.begin(), slabakai.end(), [](const Stud &a, const Stud &b) {
       return a.vardas < b.vardas;
         });
        sort(ramiakai.begin(), ramiakai.end(), [](const Stud &a, const Stud &b) {
       return a.vardas < b.vardas;
         });
    }
    else if (rusiavimas==2) {
        sort(slabakai.begin(), slabakai.end(), [](const Stud &a, const Stud &b) {
            return a.pavarde < b.pavarde;
        });
        sort(ramiakai.begin(), ramiakai.end(), [](const Stud &a, const Stud &b) {
            return a.pavarde < b.pavarde;
        });
    }
    else if (rusiavimas==3) {
        sort(slabakai.begin(), slabakai.end(), [](const Stud &a, const Stud &b) {
            return a.med < b.med;
        });
        sort(ramiakai.begin(), ramiakai.end(), [](const Stud &a, const Stud &b) {
            return a.med < b.med;
        });
    }
    else if (rusiavimas==4) {
        sort(slabakai.begin(), slabakai.end(), [](const Stud &a, const Stud &b) {
            return a.vid < b.vid;
        });
        sort(ramiakai.begin(), ramiakai.end(), [](const Stud &a, const Stud &b) {
            return a.vid < b.vid;
        });
    }
    else if (rusiavimas==5) {
        sort(slabakai.begin(), slabakai.end(), [](const Stud &a, const Stud &b) {
            return a.rez < b.rez;
        });
        sort(ramiakai.begin(), ramiakai.end(), [](const Stud &a, const Stud &b) {
            return a.rez < b.rez;
        });
    }
    auto sort_t1=DabartinisLaikas();
    sort_t=Skirtumas(sort_t0,sort_t1);

    auto slabakai_output_t0=DabartinisLaikas();
    output2(slabakai,"slabakai.txt");
    auto slabakakai_output_t1=DabartinisLaikas();
    slabakai_output_t=Skirtumas(slabakai_output_t0,slabakakai_output_t1);
    auto ramiakai_output_t0=DabartinisLaikas();
    output2(ramiakai,"ramiakai.txt");
    auto ramiakai_output_t1=DabartinisLaikas();
    ramiakai_output_t=Skirtumas(ramiakai_output_t0,ramiakai_output_t1);
}
void output_times(int lines_num,double nuskaitymo_failo_t, double sort_t, double segregacija_t, double slabakai_output_t, double ramiakai_output_t) {
    {
        cout<<"Failo is "+ std::to_string(lines_num) + " irasu nuskaitymo laikas: " + std::to_string(nuskaitymo_failo_t)<<"s."<<endl;
        cout<<std::to_string(lines_num) + " irasu rusiavimo laikas: "+ std::to_string(sort_t)<<"s."<<endl;
        cout<<std::to_string(lines_num) + " irasu dalijimo i dvi grupes laikas: "+std::to_string(ramiakai_output_t)<<"s."<<endl;
        cout<<std::to_string(lines_num) + " slabaku isvedimo i faila laikas: "+std::to_string(slabakai_output_t)<<"s."<<endl;
        cout<<std::to_string(lines_num) + " rameku isvedimo i faila laikas: "+std::to_string(ramiakai_output_t)<<"s."<<endl;
    }
}

