# Clasificator Finite-State

Acest proiect implementează un sistem de clasificare bazat pe un automat finit determinist (DFA)
sau expresii regulate (regex), destinat să rezolve probleme de clasificare a cuvintelor într-un
limbaj acceptat și unul respins. Proiectul utilizează Docker pentru a crea un mediu de rulare
izolat și include un sistem de validare automată pentru a verifica corectitudinea implementării. 
Codul sursă se ocupă cu construirea unui automat sau a unei expresii regulate, procesarea cuvintelor 
și validarea acestora.

## Structura Proiectului

### Fișiere și Directorii

- **`Dockerfile`**: Fișierul care descrie pașii necesari pentru a construi imaginea Docker, incluzând
-  instalarea dependențelor și a componentelor necesare pentru rularea aplicației.
- **`local.sh`**: Script shell care permite construirea, testarea, și împingerea imaginii Docker,
-  precum și rularea unui container interactiv.
- **`src/`**: Directorul care conține implementarea principală a clasificatorului.
  - Codul sursă din acest director implementează funcționalitatea principală a proiectului: un sistem
    de clasificare bazat pe un DFA sau pe expresii regulate.
  - Codul include procesarea input-ului, construcția automatului sau a expresiei regulate și verificarea
   fiecărui cuvânt din limbajul dat.
- **`checker/`**: Directorul care conține fișierele necesare pentru validarea corectitudinii implementării.
  - `checker_main.cpp` și fișierele de utilitare (`checker_utils.h` și `checker_utils.cpp`) sunt folosite
     pentru compararea soluției implementate cu soluțiile de referință.
  - `outputs_dfa/` și `outputs_regex/` conțin exemple de ieșiri corecte pentru a valida automat soluțiile tale.

## Descrierea Codului

Codul sursă al proiectului se axează pe două abordări principale: **Automatul Finit Determinist (DFA)** și **Expresiile Regulate (Regex)**. 

### Automat Finit Determinist (DFA)
Automatul finit determinist este folosit pentru a clasifica cuvintele în două categorii: cele care sunt
acceptate și cele care sunt respinse. Codul sursă pentru implementarea DFA include următoarele funcționalități:

- **Definirea stărilor**: Fiecare stare reprezintă o configurație posibilă a automatelor. Automatele
   finite deterministe sunt caracterizate prin faptul că fiecare stare are o tranziție unică pentru fiecare simbol de intrare.
- **Tranzițiile**: Tranzițiile definesc cum se schimbă automatul dintr-o stare în alta atunci
  când primește un anumit simbol din alfabet.
- **Stările finale**: Acestea sunt stările care, dacă sunt atinse la finalul procesării unui cuvânt,
   indică faptul că cuvântul a fost acceptat de automat.
- **Starea inițială**: Este starea din care începe procesarea unui cuvânt.

### Expresii Regulate (Regex)
Alternativ, poți implementa un sistem bazat pe expresii regulate. Codul utilizează expresii regulate 
pentru a verifica dacă un cuvânt respectă un anumit tipar, validând astfel dacă cuvântul aparține 
limbajului acceptat. Expresiile regulate sunt folosite pentru a descrie un set de cuvinte care se potrivesc unui model specificat.

### Algoritmi și Fluxul Codului

Codul sursă citește un fișier de intrare care conține cuvintele din cele două limbaje (acceptat și respins). Apoi, 
în funcție de alegerea utilizatorului, se poate construi fie un automat finit determinist (DFA),
fie o expresie regulată pentru validarea cuvintelor.

- **Input**: Fișierul de intrare conține cuvintele care fac parte din cele două limbaje și dimensiunea acestora.
- **Procesare**: Fiecare cuvânt este comparat cu regulile definite de automatul finit sau expresia regulată.
- **Output**: Cuvintele care sunt acceptate de clasificator sunt adăugate într-un fișier de ieșire, iar cele
   respinse sunt ignorate sau tratate într-un mod specificat.

## Structuri de Date Utilizate

### 1. **Stările Automatelor (DFA)**
Automatul finit determinist utilizează o **matrice de tranziție** pentru a reprezenta relațiile dintre stările
sale. Fiecare element din matrice indică în ce stare va ajunge automatul atunci când primește un simbol din
alfabet. Structura poate fi reprezentată astfel:
- **Matrice de tranziție**: O matrice bidimensională `M[i][j]`, unde `i` este indicele stării curente și
   `j` este indicele simbolului de intrare (corespunzător unui caracter din alfabetul a-z).
- **Stări finale**: Un vector de stări finale care conține indicii stărilor ce marchează acceptarea unui cuvânt.

### 2. **Expresii Regulate**
Pentru expresii regulate, structurile de date utilizate sunt tipice pentru implementările regex. Aceasta poate include:
- **Arbori de sintaxă abstractă**: Folosiți pentru a reprezenta sintaxa expresiilor regulate și pentru a
   evalua cuvintele care se potrivesc modelului.
- **Liste de caractere**: Folosite pentru a gestiona seturile de caractere care formează expresiile
   regulate (de exemplu, pentru a reprezenta un interval de caractere `a-z`).

### 3. **Liste de Cuvinte**
Pentru gestionarea cuvintelor din limbajele acceptate și respinse, codul folosește liste (de obicei,
vectori sau liste de șiruri de caractere). Acestea sunt utilizate pentru a păstra cuvintele care 
trebuie verificate de automatul finit sau de expresia regulată.

## Configurare

1. **Clonare Proiect**: Clonați repository-ul local:
    git clone https://github.com/enache-albertina/Clasificator-Finite-State.git
    

2. **Creare Imagine Docker**: Pentru a construi imaginea Docker utilizând `local.sh`, rulați:

    ./local.sh docker build

3. **Testare Proiect**: Pentru a testa proiectul utilizând checker-ul, rulați:
    ./local.sh checker

4. **Împingere Imagine Docker**: După construirea imaginii, o puteți împinge într-un registry folosind:
    ./local.sh docker push --user <user> --token <token>
