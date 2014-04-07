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

I've used [TDD](http://en.wikipedia.org/wiki/Test-driven_development) for it.

![diagram](https://app.genmymodel.com/files/_ZJiAoJ-dEDGn1-aaBa6y3w/oop-diag.jpg)

# Milestone 0

- [x] Working sum for rational positive numbers.

# Milestone 1

- [ ] sum for negative rational numbers
- [ ] substract
- [ ] other number classes
- [ ] other operations

# Milestone 2

- [ ] remove the reverse stuff from the add function (use a `deque`)
- [ ] store in the vectors a number, not a char digit
- [ ] make it use base 16 or any other one
