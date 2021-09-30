# TASK 1 HASH GENERATOR CREATION

## Task

Sukurkite Jūsų maišos funkciją (hash kodų generatorių), kuris pasižymėtų šiais hash funkcijoms keliamais reikalavimais:

1. Maišos funkcijos įėjimas (angl. input) gali būti bet kokio dydžio simbolių eilutė (angl. string).
2. Maišos funkcijos išėjimas (angl. output) visuomet yra to paties, fiksuoto, dydžio rezultatas (pageidautina 256 bit'ų ilgio, t.y., 64 simbolių hex'as).
3. Maišos funkcija yra deterministinė, t. y., tam pačiam įvedimui (input'ui) išvedimas (output'as) visuomet yra tas pats.
4. Maišos funkcijos reikšmė/kodas (hash‘as) bet kokiai input'o reikšmei yra apskaičiuojamas greitai - efektyviai.
5. Iš hash funkcijos rezultato (output'o) praktiškai neįmanoma atgaminti pradinio įvedimo (input'o).
6. Maišos funkcija yra atspari "kolizijai" (angl. collision resistance).
7. Bent minimaliai pakeitus įvedimą, pvz.vietoj "Lietuva" pateikus "lietuva", maišos funkcijos rezultatas-kodas turi skirtis iš esmės.

## How to run the program

To compile the program, write in command line:
- On Windows ``` mingw32-make run ```
- On Linux, Mac OS ``` make run ```

To run the program, write in command line:
- On windows ``` ./main ```
- On Linux, Mac OS ``` ./main ```

After running program, you can choose which action you want to do:
```
0. Write text
1. Transform 2 files with different symbols
2. Transform 2 files with only one symbol 
3. Transform 2 same files, where only one symbol is different
4. Transform file with no symbols (empty file)
5. Benchmark the speed by transforming lines of konstitucija.txt
6. Benchmark the speed of this hash function compared to SHA-256, MD5, SHA-1
7. Ascertain that there are no collisions between 2 pairs of string
8. Find the difference in bits and hex levels
```

To delete generated .txt .exe files, write in command line:
- On Windows ``` mingw32-make clear ```
- On Linux, Mac OS ``` make clear```

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

---

### Test with files that have one symbol

```
texta.txt: 24ab2091d41542414e37f2bb60e76cdd10518e8d8a733ef7ac23a8195c9dcac9
textb.txt: bd34ca3b7ec0fdfc0af3be883db44abbfe407d7c8a733e08bd34ca3b7ec0fdfc
```

---

### Test with files that differs by only one symbol

```
text1000Same1.txt: 46ec14ab35fbd5411ceae402b2c1d3117367ba00822850e77137118d5826204e
text1000Same2.txt: 9a116c47f4fab54463549e9d60c3f876b9c067d09219644ffcf2bd4c6b5c9695
```

---

### Test with empty file

```
textEmpty.txt: 8248317fe0a69fdd4e04fd3bac625b990ac0b9f7682e1755c68c75b324ead311
```

---

### Benchmark with "konstitucija.txt" file, when hashing every line

For this test was hashed every line in file "konstitucija.txt".

```
Transformation for this hash took: 2969 micro s
```

---

### Benchmark against MD5, SHA-1, SHA-256 

This method was used to compare speed of different hash algorithms.
To test the time, the used file was "konstitucija.txt" and it was reapeated 7000 times.
```
Transformation for this hash took: 9981 micro s
Transformation for MD5 hash took: 20014 micro s
Transformation for SHA-1 hash took: 17943 micro s
Transformation for SHA-256 hash took: 25027 micro s
```

---

### Test to see collisions

To test collisions, 100000 pairs were created, which contained random symbols:
- 25000 pairs had 10 symbols
- 25000 pairs had 100 symbols
- 25000 pairs had 500 symbols
- 25000 pairs had 1000 symbols

And every element in the pair is compared with each other

```
No collisions were found
```

---

### Test to see the difference in hex levels

Used 100000 randomly generated pairs, where only one symbol in pair is different.

```
min difference in hex pair: 50
max difference in hex pair: 64
average difference in pair: 94.1837%
```
