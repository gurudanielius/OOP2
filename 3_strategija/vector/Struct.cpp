#include "Struct.h"
#include "header.h"
//TODO: Realizacija pritaikyt prie klasiu o ne strukturu
int rusiavimas;
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
    string temp_vardas,temp_pavarde;
    vector<double> temp_ND;

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
    if (method==2) {
        cout<<"Vardas: "<<endl;
        cin>>temp_vardas;
		Lok.setVardas(temp_vardas);
        cout<<"Pavarde: "<<endl;
        cin>>temp_pavarde;
		Lok.setPavarde(temp_pavarde);
        Lok.setEgz(rand() % 10 + 1);
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
            temp_ND.push_back(rand()%10+1);
        }
        std::cout << "Egzamino rezultatas: " << Lok.getEgz() << std::endl;
		Lok.setND(temp_ND);
    }
    else {
        cout << "Vardas: " << endl;
        cin >> temp_vardas;
        Lok.setVardas(temp_vardas);
        cout << "Pavarde: " << endl;
        cin >> temp_pavarde;
        Lok.setPavarde(temp_pavarde);
        double temp,egz_temp;
        cout<<"Iveskite namu darbu rezultatus noredami uzbaigti iveskite -1: "<<endl;
        
        while (true) {

            if(cin>>temp && temp>=1 && temp<=10) {
                temp_ND.push_back(temp);
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
        Lok.setND(temp_ND);
        cout << "Iveskite egzamino rezultata: " << endl;
        while(true) {
            if(cin>>egz_temp && egz_temp>=1 && egz_temp<=10) {
				Lok.setEgz(egz_temp);
                break;
            }
            else {
                cin.clear();
                cout << "Reikia ivesti skaiciu nuo 1 iki 10. Iveskite egzamino rezultata." << endl;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }

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
        double egz;
        Stud Temp;
        std::ifstream infile(tekstinis);
        string eilute,token;
        if (!infile.is_open()) {
            throw std::ios_base::failure("Nepavyko atidaryti failo");
        }
        string vardas, pavarde;

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
            iss >>vardas>> pavarde;
			Temp.setVardas(vardas);
			Temp.setPavarde(pavarde);
            int ivertinimas;
			vector<double> ND_temp;
			ND_temp.clear();
            for (int i = 0; i < number_of_nd; i++) {
                iss >> ivertinimas;
				ND_temp.push_back(ivertinimas);
            }
            Temp.setND(ND_temp);
            iss >> egz;
			Temp.setEgz(egz);
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
void val(Stud &Lok) {
    Lok.setVardas("");
    Lok.setPavarde("");
    Lok.setND(vector<double>());
}



void output(list<Stud> &v1) {
    if (rusiavimas==1) {
        v1.sort([](const Stud &a, const Stud &b) {
            return a.getVardas()< b.getVardas();
        });
    }
    else if (rusiavimas==2) {
        v1.sort([](const Stud &a, const Stud &b) {
            return a.getPavarde() < b.getPavarde();
        });
    }
    else if (rusiavimas==3) {
        v1.sort([](const Stud &a, const Stud &b) {
            return a.med > b.med;
        });

    }
    else if (rusiavimas==4) {
        v1.sort([](const Stud &a, const Stud &b) {
            return a.vid > b.vid;
        });
    }
    else if (rusiavimas==5) {
        v1.sort([](const Stud &a, const Stud &b) {
            return a.rez > b.rez;
        });

    }
    cout <<left<<setw(15) << "Vardas" << "    "
         <<left<<setw(15) << "Pavarde" << "    "
         <<left<<setw(15) << "Vidurkis" << "    "
         <<left<<setw(15) << "Mediana" << "    "
         <<left<<setw(15) << "Galutinis" << "    "
         <<left<<setw(20) << "Adresas" << endl;

    for (auto it =v1.begin(); it != v1.end(); ++it) {
        cout<<left<<setw(15)<<it-> getVardas()<< "    "
            <<left<<setw(15)<<it-> getPavarde()<< "    "
            <<left<<setw(15)<<fixed<<setprecision(2)<<it->med << "    "
            <<left<<setw(15)<<fixed<<setprecision(2)<<it->vid << "    "
            <<left<<setw(15)<<fixed<<setprecision(2)<<it->rez<<"    "
            <<left<<setw(20)<<fixed<<setprecision(2)<<&(*it)<<endl;
    }

}
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
    outputFile << left << setw(15) << it->getVardas()<< "    "
               << left << setw(15) << it->getPavarde() << "    "
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

// void vidurkis(Stud &Lok) {
//     Lok.med = 0;
//     Lok.vid = 0;
//     for (int i = 0; i < Lok.getND().size(); i++) {
//         Lok.vid += Lok.getND().at(i);
//     }
//     Lok.vid = Lok.vid / Lok.getND().size();
//     if (Lok.getND().size() == 0) {
//         Lok.vid = 0;
//     }
//     sort(Lok.getND().begin(), Lok.getND().end());
//     if (Lok.getND().size() % 2 == 0) {
//         Lok.med = (Lok.getND().at(Lok.getND().size() / 2 - 1) + Lok.getND().at(Lok.getND().size() / 2)) / 2;
//     } else {
//         Lok.med = Lok.getND().at(Lok.getND().size() / 2);
//     }
//     Lok.rez = 0.4 * Lok.vid + 0.6 * Lok.getEgz();
// }

// void mediana(Stud &Lok) {
//     sort(Lok.getND().begin(), Lok.getND().end());
//     if (Lok.getND().size() % 2 == 0) {
//         Lok.med = (Lok.getND().at(Lok.getND().size() / 2 - 1) + Lok.getND().at(Lok.getND().size() / 2)) / 2;
//     } else {
//         Lok.med = Lok.getND().at(Lok.getND().size() / 2);
//     }
//     Lok.rez = 0.4 * Lok.med + 0.6 * Lok.getEgz();
// }
void vidurkis(Stud &Lok) {
    Lok.med = 0;
    Lok.vid = 0;
    int n=Lok.getND().size();
    for (int i = 0; i < n; i++) {
        Lok.vid += Lok.getND().at(i);
    }
    Lok.vid = Lok.vid / n;
    if (n == 0) {
        Lok.vid = 0;
    }
    vector<double> temp = Lok.getND();
    sort(temp.begin(), temp.end());
    if (n % 2 == 0) {
        Lok.med = (temp.at(n / 2 - 1) + temp.at(n / 2)) / 2;
    } else {
        Lok.med = temp.at(n / 2);
    }
    Lok.rez = 0.4 * Lok.vid + 0.6 * Lok.getEgz();
}

void mediana(Stud &Lok) {
    vector<double> temp = Lok.getND();

    sort(temp.begin(), temp.end());

    if (Lok.getND().size() % 2 == 0) {
        Lok.med = (temp.at(Lok.getND().size() / 2 - 1) + temp.at(Lok.getND().size() / 2)) / 2;
    } else {
        Lok.med = Lok.getND().at(Lok.getND().size() / 2);
    }
    Lok.rez = 0.4 * Lok.med + 0.6 * Lok.getEgz();
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

void segregacija(list<Stud> &v1) {
    list<Stud> slabakai;
    auto segregacija_t0=DabartinisLaikas();

    auto it = std::remove_if(v1.begin(), v1.end(), [&](const Stud& stud) {
    if (stud.rez < 5) {
        slabakai.push_back(stud);
        return true;
    }
    return false;
});
    v1.erase(it, v1.end());

    auto segregacija_t1=DabartinisLaikas();
    segregacija_t=Skirtumas(segregacija_t0,segregacija_t1);

    cout<<"Pagal ka norite rusiuoti sugrupuotus studentus? (Vardas - 1/Pavarde - 2/ Mediana - 3/Vidurkis - 4/Galutini - 5) "<<endl;
    cin>>rusiavimas;
    auto sort_t0=DabartinisLaikas();
    if (rusiavimas == 1) {
        v1.sort([](const Stud& a, const Stud& b) {
            return a.getVardas() < b.getVardas();
            });
    }
    else if (rusiavimas == 2) {
        v1.sort([](const Stud& a, const Stud& b) {
            return a.getPavarde() < b.getPavarde();
            });
    }
    else if (rusiavimas==3) {
        slabakai.sort([](const Stud &a, const Stud &b) {
            return a.med > b.med;
        });
        v1.sort([](const Stud &a, const Stud &b) {
            return a.med > b.med;
        });
    }
    else if (rusiavimas==4) {
        slabakai.sort([](const Stud &a, const Stud &b) {
            return a.vid > b.vid;
        });
        v1.sort([](const Stud &a, const Stud &b) {
            return a.vid > b.vid;
        });
    }
    else if (rusiavimas==5) {
        slabakai.sort([](const Stud &a, const Stud &b) {
            return a.rez > b.rez;
        });
        v1.sort([](const Stud &a, const Stud &b) {
            return a.rez > b.rez;
        });
}
    auto sort_t1=DabartinisLaikas();
    sort_t=Skirtumas(sort_t0,sort_t1);

    auto slabakai_output_t0=DabartinisLaikas();
    output2(slabakai,"slabakai.txt");
    auto slabakakai_output_t1=DabartinisLaikas();
    slabakai_output_t=Skirtumas(slabakai_output_t0,slabakakai_output_t1);
    auto ramiakai_output_t0=DabartinisLaikas();
    output2(v1,"ramiakai.txt");
    auto ramiakai_output_t1=DabartinisLaikas();
    ramiakai_output_t=Skirtumas(ramiakai_output_t0,ramiakai_output_t1);
}
void output_times(int lines_num,double nuskaitymo_failo_t, double sort_t, double segregacija_t, double slabakai_output_t, double ramiakai_output_t) {
    {
        cout<<"Failo is "+ std::to_string(lines_num) + " irasu nuskaitymo laikas: " + std::to_string(nuskaitymo_failo_t)<<"s."<<endl;
        cout<<std::to_string(lines_num) + " irasu rusiavimo laikas: "+ std::to_string(sort_t)<<"s."<<endl;
        cout<<std::to_string(lines_num) + " irasu dalijimo i dvi grupes laikas: "+std::to_string(segregacija_t)<<"s."<<endl;
        cout<<std::to_string(lines_num) + " slabaku isvedimo i faila laikas: "+std::to_string(slabakai_output_t)<<"s."<<endl;
        cout<<std::to_string(lines_num) + " rameku isvedimo i faila laikas: "+std::to_string(ramiakai_output_t)<<"s."<<endl;
    }
}

