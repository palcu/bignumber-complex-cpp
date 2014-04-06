bignumber-complex-cpp
=====================

Class for complex big numbers in C++11. Homework for my OOP lab. Statement:

```
13. Numere mari: Sa se implementeze clase aferente lucrului cu Numere Mari, astfel: Toate 
clasele sa permita operatiile +=, -=, *= (AddToMe, SubstractFromMe, MultiplyMeWith) 
si operatia Modul (returneaza Modulul numarului). Numerele mari sa poata fi construite 
pornind de la un numar mic, sau de la un sir de caractere ce reprezinta numarul. Vor 
exista 4 categorii de Numere Mari: Numere Naturale, Numere Intregi, Numere Reale si 
Numere Complexe. Numerele mari trebuie sa ofere si functionalitate de afisare.

Precizari: 

    Numerele intregi se citesc in format „-342342”; Numerele reale in format 
        „-123.4891” iar numerele complexe in format „-233.23 – 12.5i”;
    Incercati sa reutilizati cat mai mult cod.
    S-ar putea sa vreti sa implementati si alte operatii pe numere mari.
    Numerele mari au intre 1 si 10000 de cifre. Se acorda bonus daca folositi 
        eficient memoria (adica nu alocati cu mult mai mult spatiu pentru cifre 
        decat necesar).
```

# How to run

In `gtest` download the Google Test framework. Then:

```
cd gtest
mkdir build
cd build
cmake ..
make
```

Then go to the root directory and do the same.

```
mkdir build
cmake ..
make
./sample1
```

# Milestone 1

![diagram](https://app.genmymodel.com/files/_ZJiAoJ-dEDGn1-aaBa6y3w/oop-diag.jpg)

Just build the damn thing and use cppunit tests.

# Milestone 2

Transform the strings from base 10 to base 16.
