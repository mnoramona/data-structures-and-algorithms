# Task-ul 1: 
## - Timp de implementare:
  3 ore
## - Implementare: 
Dupa ce citesc tot ce este de citit pentru acest task, metoda de rezolvare este urmatoarea: Imi aloc memorie pentru matricile necesare pentru FloydWarshall,
"ajutor_floyd" pe care o folosesc pe post de "next" si pe care o initializez cu -1; "matrice_dist" pe care o folosesc pe post de "final"(sau "dist" pe wikipedia) si pe care
o initializez cu INF(definit 99999) si nu iau in considerare drumul de la un nod la el insusi; Aplic Floyd-Warshall, dupa care afisez ce mi se cere.

# Probleme intampinate: 
   - Toata discutia legata de spatii si "\n", a fost nevoie de multe rulari sa gasesc metoda buna,
   - Faptul ca avem doua drumuri de cost egal intr-un test, si am ales sa fac niste modificari pe functia de floyd,
   - Free-urile.
# Task-ul 2: 
## - Implementare: 
Am inceput prin a sterge muchiile care au legatura cu depozitele din matricea de adiacenta. Mi-am alocat memorie pentru vectorii folositi: 
- "vizitat1" si "vizitat2" in care imi salvez nodurile vizitate, "vizitat1" si "vizitat2" le folosesc in functiile "graf" si "graf_transpus", in care fac dfs pe graful 
respectiv si pe transpusa lui. "PlusMinus": - in primul rand mi-am facut o variabila ok care verifica daca nodul pe care il verific este un depozit;
- daca nodul pe care il verific nu face parte dintr-un depozit, atunciin vectorul "ctc", de componente conexe, la indexul nodului curent, salvez numarul componentei 
conexe din care face parte.

### In continuare in main imi creez alte doua variabile de ok("ok", respectiv "okok"):

  Pe "ok" il folosesc pentru a verifica nevoia de endline, ok devine 1 atunci cand gasesc un nod care face parte dintr-o componenta conexa, 
deci, la final, o sa am nevoie de un endline,clasic.

  Pe "okok" il folosesc pentru a verifica nevoia de spatiu. Dupa primul nod care face parte dintr-o componenta conexa, afisez nodul respectiv, 
dupa care intru intr-un for care porneste de la nodul urmator.
okok devine 1 cand se gaseste un alt nod ce face parte din componenta respectiva, deci afisez un spatiu. 
Repet pentru fiecare nod din componenta respectiva, astfel evitand sa afisez in final un spatiu.

# Probleme intampinate: 
   - am stat extraordinar de mult doar sa vad cum scot depozitele sa nu fie considerate componente conexe
   - normal ca am avut probleme la spatii, la endline a fost mai ok, dar la spatii...

# Pareri:
A fost o tema ok, nu mai fac task-ul trei din bun simt fata de alte materii la care am de invatat, dar overall o tema explicata ok si mult mai usor de implementat cu matrice. 
Sincera sa fiu a ajutat si faptul ca multe metode erau cunoscute deja, de exemplu cautarea drumului minim etc.
