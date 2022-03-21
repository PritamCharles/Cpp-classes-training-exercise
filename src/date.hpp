// -------------------------------------------------------------------------------------------
// Seance 4 - 23 fev. 2022
// Kantane Pritam Charles
// 3PSC - groupe 1
// Bibliotheque de la classe date
// -------------------------------------------------------------------------------------------
using namespace std;

// --- classe date ---
class date {
// Definition des attributs prives
private:
    int jour, mois, annee;

// Definition des methodes publiques et des constructeurs / destructeurs
public:
    date(int, int, int);  // Constructeur a trois attributs
    date(const date &);  // Constructeur par recopie

    // getter et setter
    int get_jour();
    int get_mois();
    int get_annee();
    void set_jour(int);
    void set_mois(int);
    void set_annee(int);

    // ostream et istream
    friend ostream &operator<<(ostream &, const date &);
    friend istream &operator>>(istream &, date &);

    // Methodes publiques
    void verif_ddn(int, int, int);
};

date::date(int j, int m, int a) {  // Le joue, le mois et l'annee sont donnes par les arguments entres lors de la creation de l'objet
    jour = j;
    mois = m;
    annee = a;
}

date::date(const date &d) {  // Le jour, le mois et l'annee prennent les valeurs de l'objet de type date mis en argument
    jour = d.jour;
    mois = d.mois;
    annee = d.annee;
}

int date::get_jour() {
    return jour;  // getter : retourne le jour : ideal pour la manipulation des attributs prives
}

int date::get_mois() {
    return mois;  // getter : retourne le mois
}

int date::get_annee() {
    return annee;  // getter : retourne l'annee
}

void date::set_jour(int j) {  // setter : attribut l'entier en argument a l'attribut jour
    jour = j;
}

void date::set_mois(int m) {  // setter : attribut l'entier en argument a l'attribut mois
    mois = m;
}

void date::set_annee(int a) {  // setter : attribut l'entier en argument a l'attribut annee
    annee = a;
}

ostream &operator<<(ostream &out, const date &d) {
    out << d.jour << "/" << d.mois << "/" << d.annee << endl;  // Affiche la date de naissance avec le format (jj/mm/aaaa)

    return out;  // On retorune l'element associe au ostream
}

istream &operator>>(istream &in, date &d) {
    int j, m, a;  // Definition de varibales locales

    cout << "Entrez la date de naissance (format jj/mm/aaaa) : ";
    in >> j; in.ignore(1, '/'); in >> m; in.ignore(2, '/'); in >> a;   // Saisie de la date de naissance avec le format predefini
    d.set_jour(j);               // On rentre la valeur de la variable locale a l'attribut concerne (jour ici)
    d.set_mois(m);               // On rentre la valeur de la variable locale a l'attribut concerne (mois ici)
    d.set_annee(a);              // On rentre la valeur de la variable locale a l'attribut concerne (annee ici)
    d.verif_ddn(j, m, a);        // Verification de la date de naissance valide12/12/

    return in;                   // On retourne l'element associe au istream
}

void date::verif_ddn(int jr, int ms, int ae) {  // Verification de la date de naissance saisie
    bool etat_jour, etat_mois, etat_annee, etat_gen;

    do {
        if ((jr <= 0) || (jr > 31)) {
            cout << "\nLe jour doit etre compris 1 et 31. Veuillez corriger cette information.";     // si des le debut, jour > 31, on avertit l'utilisateur
            etat_jour = false;
        }
        else {
            etat_jour = true;
        }
        if ((ae < 1990) || (ae > 2010)) {     // annee comprise entre 1990 et 2010
            cout << "\nL'annee doit etre comprise entre 1990 (inclus) et 2010 (inclus). Veuillez corriger cette information.";
            etat_annee = false;
        }
        else {
            etat_annee = true;
        }

        if ((ms < 0) || (ms > 12)) {
            cout << "\nLe mois doit etre compris entre 1 et 12.";
            etat_mois = false;
        }
        else {
            etat_mois = true;
            if (etat_jour) {
                if (((ms > 0) && (ms < 8)) && (ms % 2 == 0)) {     // les mois pairs compris entre 1 et 7 ont 30 jours
                    if ((jr <= 0) || (jr > 30)) {
                        cout << "\nIl y a 30 jours dans ce mois. Veuillez corriger cette information.";
                        etat_jour = false;
                    }
                    else {
                        etat_jour = true;
                    }
                }
                else if (((ms > 0) && (ms < 8)) && (ms % 2 != 0)) {     // les mois impairs compris entre 1 et 7 ont 31 jours
                    if ((jr <= 0) || (jr > 31)) {
                        cout << "\nIl y a 31 jours dans ce mois. Veuillez corriger cette information.";
                        etat_jour = false;
                    }
                    else {
                        etat_jour = true;
                    }
                }

                if (((ms >= 8) && (ms < 13)) && (ms % 2 == 0)) {     // les mois pairs compris entre 8 et 12 ont 31 jours
                    if ((jr <= 0) || (jr > 31)) {
                        printf("\nIl y a 30 jours dans ce mois. Veuillez corriger cette information.");
                        etat_jour = false;
                    }
                    else {
                        etat_jour = true;
                    }
                }
                else if (((ms >= 8) && (ms < 13)) && (ms % 2 != 0)) {     // les mois impairs compris entre 8 et 12 ont 30 jours
                    if ((jr <= 0) || (jr > 30)) {
                        cout << "\nIl y a 31 jours dans ce mois. Veuillez corriger cette information.";
                        etat_jour = false;
                    }
                    else {
                        etat_jour = true;
                    }
                }
            }
            if (etat_annee) {
                if (ms == 2) {
                    if ((ae % 4 == 0) && (jr <= 0) || (jr >= 30)) {     // verification d l'annee bissextile ou non
                        cout << "\n%d est une annee bissextile. Il y a 29 jours dans ce mois." << annee;
                        etat_jour = false;
                    }
                    else if ((ae % 4 != 0) && (jr <= 0) || (jr >= 29)) {
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
            cin >> jr; cin.ignore(1, '/'); cin >> ms; cin.ignore(2, '/'); cin >> ae;
            set_jour(jr);
            set_mois(ms);
            set_annee(ae);
            etat_gen = false;     // on attribue FALSE a l'etat general pour refaire une verification du input qui vient d'etre fait
        }
        else {
            etat_gen = true;     // sinon on retourne TRUE et on quitte le do.
        }
    } while (!etat_gen);
}