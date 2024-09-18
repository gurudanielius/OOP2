#include "header.h"
#include "Struct.h"'
string choice;
int main() {
    vector<Stud> v1;
    Stud Temp;
    int n;
    string file_choice;

    cout<<"Pasirinkite ka skaiciuoti: V - vidurki, M - mediana"<<endl;
    cin>>choice;
    cout << "Ar skaityti duomenis is failo? taip/ne" << endl;
    cin>>file_choice;

    if (file_choice=="ne") {
        cout<<"Iveskite studentu skaiciu"<<endl;
        cin>>n;
        for (int i=0;i<n;i++) {
            ived(Temp);
            v1.push_back(Temp);
            val(Temp);
        }
    }
    if(file_choice=="taip") {
        string tekstinis;
        std::ifstream infile("C:/Users/danie/CLionProjects/vertinimas/kursiokai.txt");
        string eilute;
        if (!infile)
        {
            std::cerr << "Error: Failo atidaryti nepavyko." << endl;
            std::terminate();
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
    //Isvedimas
    if (choice=="V") {
        cout << std::setw(10) << "Vardas" << "    "
             << std::setw(10) << "Pavarde" << "    "
             << std::setw(10) << "Galutinis (Vid.)" << endl;
    }
    else {
        cout << std::setw(10) << "Vardas" << "    "
             << std::setw(10) << "Pavarde" << "    "
             << std::setw(10) << "Galutinis (Med.)" << endl;
    }
    cout << "-----------------------------------------------" << endl;


    for (int i=0;i<n;i++) {
        output(v1.at(i));
    }


    system("pause");

    return 0;
}


