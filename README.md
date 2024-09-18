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
-----------------------------------------------
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



