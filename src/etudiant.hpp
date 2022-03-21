// -------------------------------------------------------------------------------------------
// Seance 4 - 23 fev. 2022
// Kantane Pritam Charles
// 3PSC - groupe 1
// Bibliotheque de la classe etudiant
// -------------------------------------------------------------------------------------------
using namespace std;

// --- classe etudiant ---

class etudiant {
// Definition des attributs prives
private:
    string nom, prenom;
    date ddn;
    note n1, n2, n3;
    double moyenne;

// Definition des methodes publiques et des constructeurs
public:
    etudiant(string, string, date, note, note, note);  // Constructeur a six parametres

    // getter et setter
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
    void set_moyenne(double);

    // istream et ostream
    friend ostream &operator<<(ostream &, const etudiant &);
    friend istream &operator>>(istream &, etudiant &);

    // Methodes publiques
    void afficher_1_etudiant(int);
    double calcul_moyenne(note, note, note);
};

etudiant::etudiant(string pm, string nm, date d, note note1, note note2, note note3) : ddn(d), n1(note1), n2(note2), n3(note3) { // Agregation de l'attribut ddn et n1, n2, n3 car ils ce sont des objets
    prenom = pm;                                                                                                                 // d'une classe a part entiere, hors de etudiant.
    nom = nm;

    ddn.set_jour(d.get_jour());
    ddn.set_mois(d.get_mois());
    ddn.set_annee(d.get_annee());

    n1.set_matiere(note1.get_matiere());
    n1.set_n(note1.get_n());
    n1.set_coef(note1.get_coef());

    n2.set_matiere(note2.get_matiere());
    n2.set_n(note2.get_n());
    n2.set_coef(note2.get_coef());

    n3.set_matiere(note3.get_matiere());
    n3.set_n(note3.get_n());
    n3.set_coef(note3.get_coef());

    moyenne = calcul_moyenne(n1, n2, n3);
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
    n2.set_coef(n.get_coef());
}

void etudiant::set_n3(note n) {
    n3.set_matiere(n.get_matiere());
    n3.set_n(n.get_n());
    n3.set_coef(n.get_coef());
}

void etudiant::set_moyenne(double moy) {
    moyenne = moy;
}

ostream &operator<<(ostream &out, const etudiant &e) {
    // Affichage des cooerdonnees de l'etudiant
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

istream &operator>>(istream &in, etudiant &e) {
    // Definition des variables locales : definition des objets de classe pour les utiliser juste ensuite + les autres variables
    int jour, mois, annee, coef1, coef2, coef3;
    string nom, prenom;
    string matiere1, matiere2, matiere3;
    double note1, note2, note3;
    date ddn(jour = 0, mois = 0, annee = 0);
    note n1(matiere1, note1 = 0, coef1 = 0), n2(matiere2, note2 = 0, coef2 = 0), n3(matiere3, note3 = 0, coef3 = 0);

    tirets();
    cout << "Fiche Etudiant" << endl;
    tirets();

    // Demande des informations que l'on stocke dans des varaibles locales
    cout << "Nom : ";
    in >> nom;
    cout << "Prenom : ";
    in >> prenom;

    cout << "Date de naissance : ";
    in >> jour; in.ignore(1, '/'); in >> mois; in.ignore(2, '/'); in >> annee;
    ddn.verif_ddn(jour, mois, annee);
    cout << endl;

    cout << "Matiere : ";
    in >> matiere1;
    do {
        cout << "Note : ";
        in >> note1;
    } while ((note1 < 0) || (note1 > 20)); // Verification avec une boucle do while pour que la note saisie soit toujours entre 0 et 20
    do {
        cout << "Coefficient associe a la note (entre 1 et 5 inclus) : ";
        in >> coef1;
    } while ((coef1 <= 0) || (coef1 > 5));  // Verfication avec une boucle do while pour que le coefficient saisi soit toujours entre 1 et 5 inclus
    cout << endl;

    cout << "Matiere : ";
    in >> matiere3;
    do {
        cout << "Note : ";
        in >> note3;
    } while ((note3 < 0) || (note3 > 20));
    do {
        cout << "Coefficient associe a la note (entre 1 et 5 inclus) : ";
        in >> coef3;
    } while ((coef3 <= 0) || (coef3 > 5));
    cout << endl;

    cout << "Matiere : ";
    in >> matiere2;
    do {
        cout << "Note : ";
        in >> note2;
    } while ((note2 < 0) || (note2 > 20));
    do {
        cout << "Coefficient associe a la note (entre 1 et 5 inclus) : ";
        in >> coef2;
    } while ((coef2 <= 0) || (coef2 > 5));
    cout << endl;

    // Attribution des valeurs aux attributs respectifs grace aux setters
    ddn.set_jour(jour);
    ddn.set_mois(mois);
    ddn.set_annee(annee);

    n1.set_matiere(matiere1);
    n2.set_matiere(matiere2);
    n3.set_matiere(matiere3);

    n1.set_n(note1);
    n2.set_n(note2);
    n3.set_n(note3);

    n1.set_coef(coef1);
    n2.set_coef(coef2);
    n3.set_coef(coef3);

    e.set_nom(nom);
    e.set_prenom(prenom);
    e.set_ddn(ddn);
    e.set_n1(n1);
    e.set_n2(n2);
    e.set_n3(n3);
    e.set_moyenne(e.calcul_moyenne(n1, n2, n3));

    return in;  // On retourne l'element associe au istream
}

void etudiant::afficher_1_etudiant(int nb) {  // Affiche les coordonnees d'un etudiant
    system("cls");
    tirets();
    cout << "Fiche Etudiant " << nb << endl;
    tirets();
    cout << "Nom : " << nom << endl << "Prenom : " << prenom << endl;
    cout << "Date de naissance : " << ddn << endl;
    tirets();
    cout << n1 << endl;
    cout << n2 << endl;
    cout << n3 << endl;
    tirets();
    calcul_moyenne(n1, n2, n3);
    cout << "Moyenne de l'etudiant : " << moyenne << endl;
}

double etudiant::calcul_moyenne(note n1, note n2, note n3) {
    double note1, note2, note3;
    int coef1, coef2, coef3;
    double somme_note = 0, somme_coef = 0;

    // On recupere les notes et les coefficients
    note1 = n1.get_n();
    note2 = n2.get_n();
    note3 = n3.get_n();

    coef1 = n1.get_coef();
    coef2 = n2.get_coef();
    coef3 = n3.get_coef();

    // Calcul de la moyenne
    somme_note += ((note1 * coef1) + (note2 * coef2) + (note3 * coef3));
    somme_coef += coef1 + coef2 + coef3;

    moyenne = somme_note / somme_coef;

    return moyenne;
}
