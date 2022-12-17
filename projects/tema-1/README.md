### 4/10/2022 17:52 - Am terminat task-ul 4, deci toata tema.

# Timp de implementare: 

## Task-ul 1:

- A fost gata intr-o zi (4/04/2022). Am prelucrat functiile clasice folosite la laboratoare (initializare nod/lista, inserare etc.). Am incercat sa fac listele pentru 
"ferestrele de 5" cu "for", dar imi dadea segmentation fault asa ca m-am lasat si am facut listele verde in fata in functie de pozitia unui nod de baza. Tot in ziua asta 
am inceput sa organizez fiecare task in parte, inainte sa le rezolv.

## Task-ul 2 si 3:

- Am scris o incercare de rezolvare intr-o zi si nu-mi dadea nimic, si le-am rezolvat pe amandoua inainte de laboratoarele de joi (7/04/2022). La task-ul 2 am avut probleme
de intelegere a functiei de inserare crescator, dar am rezolvat; iar la task-ul 3 m-am incurcat singura cu inputul (inainte sa verific pe checker rulam sa vad pe exemplele
din pdf si am scris ceva gresit si mi-a luat o ora sa imi dau seama de greseala mea).

## Task-ul 5:

- Am ales sa sar peste task-ul 4 si sa fac task-ul 5 inainte (8/04/2022). Am stat cred ca o zi intreaga doar sa gasesc informatii despre cum sa fac capatul inferior, si 
pana sa gasesc "floor" a durat.

## Task-ul 4:

- Si task-ul acesta a durat o zi (10/04/2022), si a durat mult sa observ ca impartirile din formula (si anume impartirile de la formula lui "scalar" din functia "valoare"
care imi dadeau mereu 0 pana am descoperit ca trebuie (double)).

# Implementare: 

## Task-ul 1:

- Am facut o lista noua cu valorile bune, in aceasta lista am inserat primii (k/2) termeni, adica primii 2 termeni, dupa care imi formez listele de cate 5 elemente in 
functie de un nod-baza, fac formula sumei si deviatiei si verific daca face parte din interval, daca raspunsul e da, atunci inserez nodul-baza respectiv.

## Task-ul 2:

- Imi iau cate 5 elemente in functie de un nod-baza, fac o lista noua in care introduc aceste elemente crescator si o alta lista in care introduc valorile de la mijloc, 
si returnez lista buna. Tot la fel, cu cate 5 elemente, carora le fac media aritmetica si le introduc intr-o lista pe care o returnez.

## Task-ul 3:

- Parcurg lista, verific diferenta intre timestamp-uri, si daca este cazul updatez valoarea si timestamp-ul nodului cu formulele.

## Task-ul 4:

- Am facut o functie care calculeaza coeficientul C, o functie care calculeaza valoarea pe care o are nodul care trebuie inserat. Parcurg lista si verific diferenta de 
timestamp, parcurg lista si formez listele de left si right, in ordine dupa cat de aproape este de nodul-baza, introduc in lista noduri cu timestamp-uri din 200 in 200,
si cu valorile din functie.

## Task-ul 5:

- Am facut o noua functie in care introduc nodurile in ordine crescatoare, aflu capatul de interval folosind "floor" la care tot adaug "delta" pentru a crea urmatoarele 
intervale. Tin un contor care numara elementele din fiecare interval pe care il afisez.
