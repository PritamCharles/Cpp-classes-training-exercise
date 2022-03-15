// -------------------------------------------------------------------------------------------
// Seance 4 - 23 fev. 2022
// Kantane Pritam Charles
// 3PSC - groupe 1
// Bibliothèque de fonctions et de procedures
// -------------------------------------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

void tirets() {
    cout << "-----------------------------------------------------" << endl;
}

void afficher_titre(string texte) {
    tirets();
    cout << texte << endl;
    tirets();
}


// --- classe date ---
class date {
private:
    int jour, mois, annee;

public:
    date(int, int, int);
    date(const date &);

    int get_jour();
    int get_mois();
    int get_annee();
    void set_jour(int);
    void set_mois(int);
    void set_annee(int);
    void verif_ddn();

    friend ostream &operator<<(ostream &, const date &);
    friend istream &operator>>(istream &, const date &);
};

void date::verif_ddn() {
    bool etat_jour, etat_mois, etat_annee, etat_gen;
    int j, m, a;

    do {
        if ((jour <= 0) || (jour > 31)) {
            cout << "\nLe jour doit etre compris 1 et 31. Veuillez corriger cette information.";     // si des le debut, jour > 31, on avertit l'utilisateur
            etat_jour = false;
        }
        else {
            etat_jour = true;
        }
        if ((annee < 1990) || (annee > 2010)) {     // annee comprise entre 1990 et 2010
            cout << "\nL'annee doit etre comprise entre 1990 (inclus) et 2010 (inclus). Veuillez corriger cette information.";
            etat_annee = false;
        }
        else {
            etat_annee = true;
        }

        if ((mois < 0) || (mois > 12)) {
            cout << "\nLe mois doit etre compris entre 1 et 12.";
            etat_mois = false;
        }
        else {
            etat_mois = true;
            if (etat_jour) {
                if (((mois > 0) && (mois < 8)) && (mois % 2 == 0)) {     // les mois pairs compris entre 1 et 7 ont 30 jours
                    if ((jour <= 0) || (jour > 30)) {
                        cout << "\nIl y a 30 jours dans ce mois. Veuillez corriger cette information.";
                        etat_jour = false;
                    }
                    else {
                        etat_jour = true;
                    }
                }
                else if (((mois > 0) && (mois < 8)) && (mois % 2 != 0)) {     // les mois impairs compris entre 1 et 7 ont 31 jours
                    if ((jour <= 0) || (jour > 31)) {
                        cout << "\nIl y a 31 jours dans ce mois. Veuillez corriger cette information.";
                        etat_jour = false;
                    }
                    else {
                        etat_jour = true;
                    }
                }

                if (((mois >= 8) && (mois < 13)) && (mois % 2 == 0)) {     // les mois pairs compris entre 8 et 12 ont 31 jours
                    if ((jour <= 0) || (jour > 31)) {
                        printf("\nIl y a 30 jours dans ce mois. Veuillez corriger cette information.");
                        etat_jour = false;
                    }
                    else {
                        etat_jour = true;
                    }
                }
                else if (((mois >= 8) && (mois < 13)) && (mois % 2 != 0)) {     // les mois impairs compris entre 8 et 12 ont 30 jours
                    if ((jour <= 0) || (jour > 30)) {
                        cout << "\nIl y a 31 jours dans ce mois. Veuillez corriger cette information.";
                        etat_jour = false;
                    }
                    else {
                        etat_jour = true;
                    }
                }
            }
            if (etat_annee) {
                if (mois == 2) {
                    if ((annee % 4 == 0) && (jour <= 0) || (jour >= 30)) {     // verification d l'annee bissextile ou non
                        cout << "\n%d est une annee bissextile. Il y a 29 jours dans ce mois." << annee;
                        etat_jour = false;
                    }
                    else if ((annee % 4 != 0) && (jour <= 0) || (jour >= 29)) {
                        cout << "\n%d n'est pas une annee bissextile. Il y a 28 jours dans ce mois." << annee;
                        etat_jour = false;
                    }
                    else {
                        etat_jour = true;
                    }
                }
            }
        }
        if ((!etat_jour) || (!etat_mois) || (!etat_annee)) {     // on demande la date de naissance tant qu'une condition est vérifiée
            cout << "\n\nEntrez votre date de naissance (jj/mm/aaaa) :";
            cin >> j;
            cin.ignore(1, '/');
            cin >> m;
            cin.ignore(2, '/');
            cin >> a;
            set_jour(j);
            set_mois(m);
            set_annee(a);
            etat_gen = false;     // on attribue FALSE a l'etat general pour refaire une verification du input qui vient d'etre fait
        }
        else {
            etat_gen = true;     // sinon on retourne TRUE et on quitte le do.
        }
    } while (!etat_gen);
}

date::date(int j, int m, int a) {
    jour = j;
    mois = m;
    annee = a;
    verif_ddn();
}

date::date(const date &d) {
    jour = d.jour;
    mois = d.mois;
    annee = d.annee;
    verif_ddn();
}

int date::get_jour() {
    return jour;
}

int date::get_mois() {
    return mois;
}

int date::get_annee() {
    return annee;
}

void date::set_jour(int j) {
    jour = j;
}

void date::set_mois(int m) {
    mois = m;
}

void date::set_annee(int a) {
    annee = a;
}

ostream &operator<<(ostream &out, const date &d) {
    out << d.jour << "/" << d.mois << "/" << d.annee << endl;

    return out;
}

istream &operator>>(istream &in, date &d) {
    int j, m, a;

    in >> j;
    in >> m;
    in >> a;
    d.set_jour(j);
    d.set_mois(m);
    d.set_annee(a);

    return in;
}

// --- classe note ---

class note {
private:
    string matiere;
    double n;
    int coef;

public:
    note(string, double, int);
    note(const note &);

    string get_matiere();
    double get_n();
    int get_coef();
    void set_matiere(string);
    void set_n(double);
    void set_coef(int);

    friend ostream &operator<<(ostream &, const note &);
    friend istream &operator>>(istream &, const note &);
};

note::note(string texte, double note, int coefficient) {
    matiere = texte;
    n = note;
    coef = coefficient;
}

note::note(const note &note) {
    matiere = note.matiere;
    n = note.n;
    coef = note.coef;
}

string note::get_matiere() {
    return matiere;
}

double note::get_n() {
    return n;
}

int note::get_coef() {
    return coef;
}

void note::set_matiere(string texte) {
    matiere = texte;
}

void note::set_n(double note) {
    n = note;
}

void note::set_coef(int coefficient) {
    coef = coefficient;
}

ostream &operator<<(ostream &out, const note &note) {
    out << "Matiere : " << note.matiere << endl;
    out << "Note : " << note.n << endl;
    out << "Coefficient associe: " << note.coef << endl;
    return out;
}

istream &operator>>(istream &in, note &note) {
    string texte;
    double n;
    int coef;

    in >> texte;
    in >> n;
    in >> coef;

    note.set_matiere(texte);
    note.set_n(n);
    note.set_coef(coef);

    return in;
}

// --- classe etudiant ---

class etudiant {
private:
    string nom, prenom;
    date ddn;
    note n1, n2, n3;
    double moyenne;

public:
    etudiant(string, string, date, note, note, note);

    string get_nom();
    string get_prenom();
    date get_ddn();
    note get_n1();
    note get_n2();
    note get_n3();
    double get_moyenne();
    void set_nom(string);
    void set_prenom(string);
    void set_ddn(date);
    void set_n1(note);
    void set_n2(note);
    void set_n3(note);
    void set_moyenne(note, note, note);

    friend ostream &operator<<(ostream &, const etudiant &);
    friend istream &operator>>(istream &, const etudiant &);

    void afficher_1_etudiant(string);
    //void calcul_moyenne();
};

etudiant::etudiant(string nm, string pm, date d, note note1, note note2, note note3) : ddn(d), n1(note1), n2(note2), n3(note3) {
    prenom = pm;
    nom = nm;
}

string etudiant::get_prenom() {
    return prenom;
}

string etudiant::get_nom() {
    return nom;
}

date etudiant::get_ddn() {
    return ddn;
}

note etudiant::get_n1() {
    return n1;
}

note etudiant::get_n2() {
    return n2;
}

note etudiant::get_n3() {
    return n3;
}

double etudiant::get_moyenne() {
    return moyenne;
}

void etudiant::set_prenom(string chaine) {
    prenom = chaine;
}

void etudiant::set_nom(string chaine) {
    nom = chaine;
}

void etudiant::set_ddn(date d) {
    ddn.set_jour(d.get_jour());
    ddn.set_mois(d.get_mois());
    ddn.set_annee(d.get_annee());
}

void etudiant::set_n1(note n) {
    n1.set_matiere(n.get_matiere());
    n1.set_n(n.get_n());
    n1.set_coef(n.get_coef());
}

void etudiant::set_n2(note n) {
    n2.set_matiere(n.get_matiere());
    n2.set_n(n.get_n());
    n3.set_coef(n.get_coef());
}

void etudiant::set_n3(note n) {
    n3.set_matiere(n.get_matiere());
    n3.set_n(n.get_n());
    n3.set_coef(n.get_coef());
}

void etudiant::set_moyenne(note n1, note n2, note n3) {
    double note1, note2, note3;
    int coef1, coef2, coef3;
    double somme_note = 0, somme_coef = 0;

    note1 = n1.get_n();
    note2 = n2.get_n();
    note3 = n3.get_n();

    coef1 = n1.get_coef();
    coef2 = n2.get_coef();
    coef3 = n3.get_coef();

    somme_note += ((note1 * coef1) + (note2 * coef2) + (note3 * coef3));
    somme_coef += coef1 + coef2 + coef3;

    moyenne = somme_note / somme_coef;
}

ostream &operator<<(ostream &out, const etudiant &e) {
    system("cls");
    tirets();
    out << "Fiche Etudiant" << endl;
    tirets();
    out << "Nom : " << e.nom << endl << "Prenom : " << e.prenom << endl;
    out << "Date de naissance : " << e.ddn << endl;
    tirets();
    out << e.n1 << endl << endl;
    out << e.n2 << endl << endl;
    out << e.n3 << endl;
    tirets();

    out << "Moyenne de l'etudiant : " << e.moyenne << endl;

    return out;
}

/*istream &operator>>(istream &in, etudiant &e) {
    int jour = 1, mois = 1, annee = 2000, coef1 = 1, coef2 = 1, coef3 = 1;
    string nom, prenom;
    string matiere1, matiere2, matiere3;
    double note1 = 0, note2 = 0, note3 = 0;
    date ddn(jour, mois, annee);
    note n1(matiere1, note1, coef1), n2(matiere2, note2, coef2), n3(matiere3, note3, coef3);

    cout << "Nom : ";
    in >> nom;
    cout << "Prenom : ";
    in >> prenom;

    cout << "Date de naissance : ";
    in >> jour;
    in.ignore(1, '/');
    in >> mois;
    in.ignore(2, '/');
    in >> annee;
    cout << endl;

    cout << "Matiere : ";
    in >> matiere1;
    cout << "Note : ";
    in >> note1;
    cout << "Coefficient associe a la note : ";
    in >> coef1;
    cout << endl;

    cout << "Matiere : ";
    in >> matiere2;
    cout << "Note : ";
    in >> note2;
    cout << "Coefficient associe a la note : ";
    in >> coef2;
    cout << endl;

    cout << "Matiere : ";
    in >> matiere3;
    cout << "Note 3 : ";
    in >> note3;
    cout << "Coefficient associe a la note : ";
    in >> coef3;

    e.set_nom(nom);
    e.set_prenom(prenom);
    e.set_ddn(ddn);
    e.set_n1(n1);
    e.set_n2(n2);
    e.set_n3(n3);

    return in;
}*/

void etudiant::afficher_1_etudiant(string chaine = "") {
    system("cls");
    tirets();
    cout << "Fiche Etudiant n° " << chaine << endl;
    tirets();
    cout << "Nom : " << nom << endl << "Prenom : " << prenom << endl;
    cout << "Date de naissance : " << ddn << endl;
    tirets();
    cout << n1 << endl;
    cout << n2 << endl;
    cout << n3 << endl;
    tirets();
    set_moyenne(n1, n2, n3);
    cout << "Moyenne de l'etudiant : " << moyenne << endl;
}

// --- Classe classe ---

class classe {
private:
    int static nb_etu;
    string nom;
    string groupe;
    etudiant liste_etu[40];

public:
    classe(etudiant);
    string get_nom();
    string get_groupe();
    int get_rang();
    etudiant get_liste_etu();
    void set_nom(string);
    void set_groupe(string);

    etudiant ajouter_etudiant();



};