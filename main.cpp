#include "header.h"
#include "Struct.h"'
string choice;
int main() {
    vector<Stud> v1;
    Stud Temp;
    int n;
    cout<<"Iveskite studentu skaiciu"<<endl;
    cin>>n;
    cout<<"Pasirinkite ka skaiciuoti: V - vidurki, M - mediana"<<endl;
    cin>>choice;
    for (int i=0;i<n;i++) {
        cout<<"Iveskite duomenis"<<endl;
        ived(Temp);
        v1.push_back(Temp);
        val(Temp);
    }
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


