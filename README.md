# OOP
### Apie programa: studentų vertinimo sistema, leidžianti apskaičiuoti studentų galutinį rezultatą pagal namų darbų ir egzamino balus.



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

# V0.1

###Atnaujinimai:
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
![Studentų duomenų apdorojimo srauto diagrama](https://github.com/user-attachments/assets/326e3b5e-f806-417b-90fe-e325cec5a8a6)


