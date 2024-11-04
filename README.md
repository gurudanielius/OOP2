# OOP
### Apie programa: studentų vertinimo sistema, leidžianti apskaičiuoti studentų galutinį rezultatą pagal namų darbų ir egzamino balus.
# Kompiuterio specifikacijos:
- Processor AMD Ryzen 9 6900HS with Radeon Graphics, 3301 Mhz, 3.30 GHz, 8 Core(s), 16 Logical Processor(s),
- Installed Physical Memory (RAM)	16.0 GB
- 1TB SSD storage
# Naudojimo instrukcija:
### Using compiler:
1. Clone the Repository:

       git clone https://github.com/gurudanielius/OOP/
       cd OOP
   
3. Compile the Code: Use a C++ compiler to compile the code. For example, using g++:

       g++ -std=c++11 *.cpp -o oop
   
5. Run the Application:

       ./blockchain
### Using cmake:
1. Terminale nurodome direktorija, kur egzistuoja projekto CMakeLists.txt failas, sukuriam build failams skirta direktorija :

       cd "[direktorija]"
       mkdir build
       cd build

2. Paleidžiame cmake, kad sugeneruoti build failus, nurodome jau minėta direktorija:
        
       cmake "[direktorija]"
   
4. Sukompiliuojame ir sukuriame .exe failą, taip pat galime pasirinkt konfigurijacija: Release arba Debug:

       cmake --build . --config [Release arba Debug]




#  v1.0
### Pokyčiai:
Dabar pateikiamos skirtingos programos realizacijos naudojant skirtingas studentų rūšiavimo strategijas (fill).
### Strategijų aprašymas:
- 1 strategija: 
        bendro studentai konteinerio (vector ir list tipų) skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius: "slabakai" ir "ramekai".
- 2 strategija: Bendro studentų konteinerio (vector ir list) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: "slabakai" ir pašalinant iš pirminio konteinerio.
- 3 strategija: tai yra 2 strategija panaudojant "efektyvaus" darbo su konteineriais metodą `std::remove_if` ir listams, ir vektoriams.

### Funkcijų aprašymai:
- `output2()` - sukuriamas išvedimo tekstinis failas.
- `segregacija()` - studentai yra sugrupuojami į "slabakus" ir "stiprekus", tada vartotojas pats pasirenka pagal kokį atributą (Vardas, Pavarde,Vidurkis, Mediana) šiuos studentus rušiuoti
- `DabartinisLaikas()` - grąžina dabartinį laiką
- `Skirtumas()` - grąžina dviejų laikų skirtumą
- `Generavimas()` - sugeneruojamas norimas studentų skaičius, namų darbų skaičių pasirenka vartotojas. Rezultatas yra išvedamas į tekstinį failą.

### Laikai
Kiekvienas laikas kiekvienam kiekiui ir strategijai buvo matuojamas 5 kartus ir išvestas vidurkis
- ### 1000:
| Veiksmas                               | strategija_1 su vektoriais | strategija_1 su listais | 2_strategija vektoriai | 2_strategija listai | list su remove_if | remove_if vektoriai |
|----------------------------------------|----------------------------|---------------|------------------------|---------------------|-------------------|---------------------|
| Failo iš įrašų nuskaitymo laikas       | 0.004083                   | 0.007082s     | 0.003850               | 0.003809           | 0.004269          | 0.004293           |
| Įrašų rūšiavimo laikas                 | 0.000800                   | 0.000341s     | 0.000626               | 0.000189           | 0.000740          | 0.000202           |
| Įrašų dalijimo į dvi grupes laikas     | 0.004089                   | 0.004645s     | 0.004104               | 0.004416           | 0.003959          | 0.003825           |
| Slabakų išvedimo į failą laikas        | 0.002991                   | 0.005859s     | 0.003840               | 0.003197           | 0.003222          | 0.002965           |
| Ramekų išvedimo į failą laikas         | 0.004089                   | 0.004645s     | 0.004104               | 0.004416           | 0.003959          | 0.003825           |

- ### 10 000:
| Veiksmas                               | strategija_1 su vektoriais | strategija_1 su listais | 2_strategija vektoriai | 2_strategija listai | list su remove_if | remove_if vektoriai |
|----------------------------------------|----------------------------|---------------|------------------------|---------------------|-------------------|---------------------|
| Failo iš įrašų nuskaitymo laikas       | 0.036271                   | 0.038414s     | 0.037203               | 0.037658           | 0.037578          | 0.038736           |
| Įrašų rūšiavimo laikas                 | 0.008440                   | 0.002534s     | 0.008531               | 0.002442           | 0.008996          | 0.002506           |
| Įrašų dalijimo į dvi grupes laikas     | 0.032235                   | 0.034855s     | 0.034082               | 0.034779           | 0.040938          | 0.035155           |
| Slabakų išvedimo į failą laikas        | 0.024280                   | 0.024945s     | 0.024473               | 0.024898           | 0.028195          | 0.024515           |
| Ramekų išvedimo į failą laikas         | 0.032235                   | 0.034855s     | 0.034082               | 0.034779           | 0.040938          | 0.035155           |

- ### 100 000:
| Veiksmas                               | strategija_1 su vektoriais | strategija_1 su listais | 2_strategija vektoriai | 2_strategija listai | list su remove_if | remove_if vektoriai |
|----------------------------------------|----------------------------|---------------|------------------------|---------------------|-------------------|---------------------|
| Failo iš įrašų nuskaitymo laikas       | 0.356733                   | 0.363788s     | 0.391728               | 0.384077           | 0.392623          | 0.363788           |
| Įrašų rūšiavimo laikas                 | 0.114551                   | 0.027505s     | 0.040480               | 0.043515           | 0.039085          | 0.027505           |
| Įrašų dalijimo į dvi grupes laikas     | 0.333200                   | 0.343392s     | 0.357057               | 0.356047           | 0.355554          | 0.343392           |
| Slabakų išvedimo į failą laikas        | 0.228788                   | 0.240831s     | 0.249972               | 0.255114           | 0.255086          | 0.240831           |
| Ramekų išvedimo į failą laikas         | 0.333200                   | 0.343392s     | 0.357057               | 0.356047           | 0.355554          | 0.343392           |

 ## 1 000 000:
| Veiksmas                               | strategija_1 su vektoriais | strategija_1 su listais | 2_strategija vektoriai | 2_strategija listai | list su remove_if | remove_if vektoriai |
|----------------------------------------|----------------------------|---------------|------------------------|---------------------|-------------------|---------------------|
| Failo iš įrašų nuskaitymo laikas       | 3.614022                   | 3.616999s     | 3.861661               | 3.714822           | 5.004823          | 3.616999           |
| Įrašų rūšiavimo laikas                 | 1.502412                   | 0.450904s     | 0.718605               | 0.760519           | 0.796152          | 0.450904           |
| Įrašų dalijimo į dvi grupes laikas     | 3.325965                   | 3.434312s     | 3.598118               | 3.614732           | 4.774052          | 3.434312           |
| Slabakų išvedimo į failą laikas        | 2.286499                   | 2.442912s     | 2.486440               | 2.461227           | 3.704613          | 2.442912           |
| Ramekų išvedimo į failą laikas         | 3.325965                   | 3.434312s     | 3.598118               | 3.614732           | 4.774052          | 3.434312           |

- ### 10 000 000:
| Veiksmas                               | strategija_1 su vektoriais | strategija_1 su listais | 2_strategija vektoriai | 2_strategija listai | list su remove_if | remove_if vektoriai |
|----------------------------------------|----------------------------|---------------|------------------------|---------------------|-------------------|---------------------|
| Failo iš įrašų nuskaitymo laikas       | 37.966504                  | 37.363967s    | 41.412445              | 57.873212          | 40.479116         | 37.363967          |
| Įrašų rūšiavimo laikas                 | 19.345238                  | 7.210146s     | 11.034102              | 11.589878          | 10.675159         | 7.210146           |
| Įrašų dalijimo į dvi grupes laikas     | 34.917649                  | 35.268519s    | 36.868533              | 35.156699          | 35.817448         | 35.268519          |
| Slabakų išvedimo į failą laikas        | 24.457310                  | 24.865331s    | 25.938105              | 25.236396          | 25.221774         | 24.865331          |
| Ramekų išvedimo į failą laikas         | 34.917649                  | 35.268519s    | 36.868533              | 35.156699          | 35.817448         | 35.268519          |


  

#  v0.3

### Atnaujinimai:
Stud objektai dabar yra talpinami List konteineryje.
### Funkcijų aprašymai:
- `output2()` - sukuriamas išvedimo tekstinis failas. 
- `segregacija()` - studentai yra sugrupuojami į "slabakus" ir "stiprekus", tada vartotojas pats pasirenka pagal kokį atributą (Vardas, Pavarde,Vidurkis, Mediana) šiuos studentus rušiuoti 
- `DabartinisLaikas()` - grąžina dabartinį laiką
- `Skirtumas()` - grąžina dviejų laikų skirtumą
- `Generavimas()` - sugeneruojamas norimas studentų skaičius, namų darbų skaičių pasirenka vartotojas. Rezultatas yra išvedamas į tekstinį failą.
#
### Laikai
Buvo išmatuoti 5 tekstinių failų generavimo trukmė. Šie tekstiniai failai buvo sudaryti iš 1 000, 10 000, 100 000, 1 000 000, 10 000 000 įrašų. Lentelė, vaizduojanti generavimo laiką skirtingam studentų generavimo kiekiui:
- ### 1000:
| Veiksmas                               | Vidurkis (s)  |
|----------------------------------------|---------------|
| Failo iš 1000 įrašų nuskaitymo laikas   | 0.007082s     |
| 1000 įrašų rūšiavimo laikas             | 0.000341s     |
| 1000 įrašų dalijimo į dvi grupes laikas | 0.004645s     |
| 1000 slabakų išvedimo į failą laikas    | 0.005859s     |
| 1000 ramekų išvedimo į failą laikas     | 0.004645s     |
- ### 10000:
| Veiksmas                               | Vidurkis (s)  |
|----------------------------------------|---------------|
| Failo iš 10000 įrašų nuskaitymo laikas  | 0.038414s     |
| 10000 įrašų rūšiavimo laikas            | 0.002534s     |
| 10000 įrašų dalijimo į dvi grupes laikas| 0.034855s     |
| 10000 slabakų išvedimo į failą laikas   | 0.024945s     |
| 10000 ramekų išvedimo į failą laikas    | 0.034855s     |
- ### 100000:
| Veiksmas                               | Vidurkis (s) | 
|----------------------------------------|----------------------------|
| Failo iš įrašų nuskaitymo laikas        | 0.363788s                 |
| Įrašų rūšiavimo laikas                 | 0.027505s                  |
| Įrašų dalijimo į dvi grupes laikas     | 0.343392s                  |
| Slabakų išvedimo į failą laikas        | 0.240831s                  |                    |
| Ramekų išvedimo į failą laikas         | 0.343392s                  |                    |
- ### 1000000:
| Veiksmas                               | Vidurkis (s) |
|----------------------------------------|-----------
| Failo iš įrašų nuskaitymo laikas       | 3.616999s                    | 
| Įrašų rūšiavimo laikas                 | 0.450904s                    | 
| Įrašų dalijimo į dvi grupes laikas     | 3.434312s                    | 
| Slabakų išvedimo į failą laikas        | 2.442912s                    | 
| Ramekų išvedimo į failą laikas         | 3.434312s                    | 
- ### 10000000:
| Veiksmas                               | Vidurkis (s) |
|----------------------------------------|-----------|
| Failo iš įrašų nuskaitymo laikas       | 37.363967s|
| Įrašų rūšiavimo laikas                 | 7.210146s |
| Įrašų dalijimo į dvi grupes laikas     | 35.268519s|
| Slabakų išvedimo į failą laikas        | 24.865331s|
| Ramekų išvedimo į failą laikas         | 35.268519s|


#  v0.2

1. Pridėta generavimo funkcija 
2. Atsirado funkcija, dalinanti studentus į dvi kategorijas. Studentai išvedami į du naujus failus:
    - Studentai, kurių galutinis balas < 5.0 - slabakai
    - Studentai, kurių galutinis balas >= 5.0 - ramekai
3. Pridėta funkcija, matuojanti kitų funkcijų laiką, išvedanti sugrupuotus studentus į naujus failus.
4. Nuo praeitos versijos atliktas refactoringas, dabar main.cpp veikia while-do principu.
#
### Funkcijų aprašymai:
- `output2()` - sukuriamas išvedimo tekstinis failas. 
- `segregacija()` - studentai yra sugrupuojami į "slabakus" ir "stiprekus", tada vartotojas pats pasirenka pagal kokį atributą (Vardas, Pavarde,Vidurkis, Mediana) šiuos studentus rušiuoti 
- `DabartinisLaikas()` - grąžina dabartinį laiką
- `Skirtumas()` - grąžina dviejų laikų skirtumą
- `Generavimas()` - sugeneruojamas norimas studentų skaičius, namų darbų skaičių pasirenka vartotojas. Rezultatas yra išvedamas į tekstinį failą.
#

### Laikai:
Buvo išmatuoti 5 tekstinių failų generavimo trukmė. Šie tekstiniai failai buvo sudaryti iš 1 000, 10 000, 100 000, 1 000 000, 10 000 000 įrašų. 
Lentelė, vaizduojanti generavimo laiką skirtingam studentų generavimo kiekiui:
| Generavimo kiekis | Generavimo laikas |
|------------------|-------------------|
| 1000             | 0.0043209s        |
| 10000            | 0.0381509s        |
| 100000           | 0.389532s         |
| 1000000          | 3.7939s           |
| 10000000         | 39.7852s          |

Tada buvo matuojamas šių tekstinių failų nuskaitymo laikas, rušiavimo laikas, dalijimo į dvi grupes laikas, slabaku išvedimo i failą laikas, rameku išvedimo į failą laikas. Šiuos požymius, naudojant kiekvieną sugeneruotą failą, matavome po 5 kartus ir apskaičiavome laiko vidurkį.

- ### 1000:

| Veiksmas                               | Vidurkis (s)  |
|----------------------------------------|---------------|
| 1000 įrašų rūšiavimo laikas            | 0.000800s     |
| 1000 ramekų išvedimo į failą laikas    | 0.004089s     |
| 1000 įrašų dalijimo į dvi grupes laikas| 0.004089s     |
| 1000 slabakų išvedimo į failą laikas   | 0.002991s     |
| Failo iš 1000 įrašų nuskaitymo laikas  | 0.004083s     |
#
- ### 10000:
| Veiksmas                               | Vidurkis (s)  |
|----------------------------------------|---------------|
| Failo iš 10000 įrašų nuskaitymo laikas  | 0.036271s     |
| 10000 įrašų rūšiavimo laikas            | 0.008440s     |
| 10000 įrašų dalijimo į dvi grupes laikas| 0.032235s     |
| 10000 slabakų išvedimo į failą laikas   | 0.024280s     |
| 10000 ramekų išvedimo į failą laikas    | 0.032235s     |
#
- ### 100000:
| Veiksmas                               | Vidurkis (s)  |
|----------------------------------------|---------------|
| Failo iš 100000 įrašų nuskaitymo laikas | 0.356733s     |
| 100000 įrašų rūšiavimo laikas           | 0.114551s     |
| 100000 įrašų dalijimo į dvi grupes laikas| 0.333200s     |
| 100000 slabakų išvedimo į failą laikas  | 0.228788s     |
| 100000 ramekų išvedimo į failą laikas   | 0.333200s     |
#
- ### 1 000 000:
| Veiksmas                               | Vidurkis (s)  |
|----------------------------------------|---------------|
| Failo iš 1000000 įrašų nuskaitymo laikas | 3.614022s     |
| 1000000 įrašų rūšiavimo laikas           | 1.502412s     |
| 1000000 įrašų dalijimo į dvi grupes laikas| 3.325965s     |
| 1000000 slabakų išvedimo į failą laikas  | 2.286499s     |
| 1000000 ramekų išvedimo į failą laikas   | 3.325965s     |
#
- ### 10 000 000:
| Veiksmas                               | Vidurkis (s)  |
|----------------------------------------|---------------|
| Failo iš 10000000 įrašų nuskaitymo laikas | 37.966504s     |
| 10000000 įrašų rūšiavimo laikas           | 19.345238s     |
| 10000000 įrašų dalijimo į dvi grupes laikas| 34.917649s     |
| 10000000 slabakų išvedimo į failą laikas  | 24.457310s     |
| 10000000 ramekų išvedimo į failą laikas   | 34.917649s     |
#
![time_generation](https://github.com/user-attachments/assets/cdd887db-a22a-4c92-9d6c-106cf8bbbc8b)
### Veikimo schema
<p align="center">
  <img src="https://github.com/user-attachments/assets/9a1b620b-c31c-42df-b6e3-dcc4f47f4a5b](https://github.com/user-attachments/assets/326e3b5e-f806-417b-90fe-e325cec5a8a6" width="500"/>
</p>




# V0.1

### Atnaujinimai:
  1. Pridėtas klaidų tvarkymas ir apribojimai šiems klausimams, skirtiems vartotojui:
       - "Ar skaityti duomenis is failo? taip/ne"
       - "Iveskite studentu skaiciu"
       - "Ar norite ivesti pazymius rankiniu budu, ar generuoti atsitiktinai? (Ivesti/Generuoti) "
       - "Iveskite pazymiu skaiciu: "
       - "Iveskite namu darbu rezultatus noredami uzbaigti iveskite -1: "
       - Pridėta klaida, jei įvedamas neegzistuojantis arba neprieinamas nuskaitomo failo pavadiniimas
       - Pazymiai turi būti įvedami skaičiaus formatu ir priklausyti intervalui [1;10]
  2. Rezultatas išvedimas:
     - Pataisytas matmuo, kuris rodomas išvedant rezultatą.
     - Rezultatas išvedamas rūšiuojant studentus pagal vardą
     - Rezultatas išvedamas sulygiuotas palei kairę pusę
     - Pridėta galimybė išvesti rezultatą į failą
  4. Klaidų pataisymas:
     -Jei vartotojas įveda 0 namų darbų, nebelieka dalybos iš 0
       
### Detalus atnaujinimų aprašymas:
  - Klausimuose, kuriuose atlikti apribojimai ir klaidų tvarkymas, vartotojas yra priverstas atsakyti į klausimus. Kol atsakymo programa nepriims, tol klausimas vartotojui bus kartojamas.
  - Namų darbų įvedimo pabaigimas buvo atnaujintas iš neskaitinių simbolį į skaičių "-1". Taip pat dabar programa pateikia rezultatą ir nepateikus nei vieno namų darbo.
  - Namų darbų ir egzamino balai reikalauja, kad priklausytų intervalui [1;10]
  - Rezultatas pateikia ne egzamino balą, o yra apskaičiuojamas naudojant namų darbų ir egzamino balus. Formulė 0.4 [ND_balas] + 0.6 [Egz.balas]
  - Vartotojo yra paklausiama, ar norima rezultatą išvesti faile ar terminale. Pirmu atveju, rezultatas yra išsaugomas "rezultatas.txt", o antru rezultatas yra išvedamas ekrane. Rezultatas, tiek tekstiniame faile, tiek   `      terminale yra rūšiuojamas pagal vardą ir yra pritaikyta kairinė lygiuotė.
  - Pridėtas try-catch blokas, kai nerandamas arba neįrašomas taisyklingas failo pavadinimas. Programa išmeta klaida "terminate called after throwing an instance of 'std::ios_base::failure[abi:cxx11]'
         what():  Nepavyko atidaryti failo: iostream error

<h2>Programos veikimo schema</h2>

<p align="center">
  <img src="https://github.com/user-attachments/assets/9a1b620b-c31c-42df-b6e3-dcc4f47f4a5b" width="500"/>
</p>

# V.pradinė


### Sukurta pradinė vertinimo programos versija:
Programinis kodas:
1. Sukurta struktūra, kuri aprašo studentą, atributus ir metodus.
2. Sukurti skirtingi duomenų įvedimo būdai: generavimas, įvedimas ranka nežinant namų darbų skaičiaus, nuskaitymas 
3. Sukurti metodai, kurie leidžia įvesti duomenis, apskaičiuoja vidurkį ir medianą, išveda atsakymą, "atlaisvina" objektą.

### Veikimo schema ir detalus aprašymas;

1. Vartotojo yra paklausiama, kokiu matu (vidurkiu - V ar mediana -M) norima remtis skaičiuojant galutinį rezultatą. Jei vartotojas įveda bet kokį kitą simbolį apart "V" ar "M" , tai bus skaičiuojama mediana. 

2. Vartotojo yra paklausiama, ar norima duomenis nuskaityti iš failo. Jei atsakymas yra taip, skaitoma iš failo "kursiokai.txt". Jei atsakymas yra "ne", tada yra paprašoma įvesti studentų skaičių. Įvedus studentų skaičių vartotojo paklausiama, ar norėtų susivesti duomenis ranka, ar norėtų, kad jam juos sugeneruotų kompiuteris. Vartotojo paprašoma įvesti studento vardą ir pavardę.

  - Jei pasirenkama įvesti duomenis ranka, tada vartotojas veda tiek pažymių kiek nori, o pažymių įvedimą pabaigia parašydamas neskaitinį simbolį. Vartotojo galiausiai paprašoma įvesti egzamino rezultatą.

  - Jei pasirenkama sugeneruoti duomenis, tada paklausiama, kiek namų darbų pažymių norima sugeneruoti. Sugeneruojamas ir egz. rez
3. Išvedamas rezultatas tokia struktūra:
   Vardas       Pavarde    Galutinis (Vid.)\(Med.) 
Galutinis rezultatas rodo tik vidurkį arba medianą priklausomai nuo vartotojo pasirinkimo.

<h2>Programos veikimo schema</h2>
<p align="center">
  <img src="https://github.com/user-attachments/assets/f3660a21-ba19-410e-ab12-ec2820c58735" width="500"/>
</p>


