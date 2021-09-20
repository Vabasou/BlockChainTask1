# TASK 1 HASH GENERATOR CREATION

## Content



## Task

Sukurkite Jūsų maišos funkciją (hash kodų generatorių), kuris pasižymėtų šiais hash funkcijoms keliamais reikalavimais:

1. Maišos funkcijos įėjimas (angl. input) gali būti bet kokio dydžio simbolių eilutė (angl. string).
2. Maišos funkcijos išėjimas (angl. output) visuomet yra to paties, fiksuoto, dydžio rezultatas (pageidautina 256 bit'ų ilgio, t.y., 64 simbolių hex'as).
3. Maišos funkcija yra deterministinė, t. y., tam pačiam įvedimui (input'ui) išvedimas (output'as) visuomet yra tas pats.
4. Maišos funkcijos reikšmė/kodas (hash‘as) bet kokiai input'o reikšmei yra apskaičiuojamas greitai - efektyviai.
5. Iš hash funkcijos rezultato (output'o) praktiškai neįmanoma atgaminti pradinio įvedimo (input'o).
6. Maišos funkcija yra atspari "kolizijai" (angl. collision resistance).
7. Bent minimaliai pakeitus įvedimą, pvz.vietoj "Lietuva" pateikus "lietuva", maišos funkcijos rezultatas-kodas turi skirtis iš esmės.

---

### Proof that lenght of all Output's is the same and that different texts give different results

First Run:
```
1. Different Text: 0afd45c003f32ab675fc209b6b6e299140549b9a4639810c4f3f66f2b1386cd7
2. Different Text: bbed32e539aee552a9027801f88039b465f09d47144f1b08c7bc8b6c5a6bdaea
```

Secong run:
```
1. Different Text: 0afd45c003f32ab675fc209b6b6e299140549b9a4639810c4f3f66f2b1386cd7
2. Different Text: bbed32e539aee552a9027801f88039b465f09d47144f1b08c7bc8b6c5a6bdaea
```
Conclusion - every line contains 64 symbols in Hex code, all codes are different, but for the same Input code will always be the same;

### 