// -------------------------------------------------------------------------------------------
// Seance 4 - 23 fev. 2022
// Kantane Pritam Charles
// 3PSC - groupe 1
// Bibliotheque de la classe note
// -------------------------------------------------------------------------------------------
using namespace std;


// --- classe note ---

class note {
// Definition des attributs prives
private:
    string matiere;
    double n;
    int coef;

// Definition des methodes publiques et des constructeurs
public:
    note(string, double, int);  // Constructeur a trois arguments
    note(const note &);  // Constructeur par recopie

    // setter et getter
    string get_matiere();
    double get_n();
    int get_coef();
    void set_matiere(string);
    void set_n(double);
    void set_coef(int);

    // istream et ostream
    friend ostream &operator<<(ostream &, const note &);
    friend istream &operator>>(istream &, note &);
};

note::note(string texte, double note, int coefficient) {  // Constructeur de la classe note : comprend la matiere, la note et le coefficient de la note
    matiere = texte;         // On attribut a matiere la valeur de texe
    n = note;                // On attribut a n la valeur de note
    coef = coefficient;      // On attribut a coef la valeur de coefficient
}

note::note(const note &note) {  // Constructeur par recopie : les attributs de la classe prennent respectivement les valeurs des attributs de l'objet entre en argument
    matiere = note.matiere;
    n = note.n;
    coef = note.coef;
}

string note::get_matiere() {
    return matiere;  // getter : on retourne la valeur de matiere
}

double note::get_n() {
    return n;  // getter : on retorune la valeur de n
}

int note::get_coef() {
    return coef;  // getter : on retourne la valeur de coef
}

void note::set_matiere(string texte) {
    matiere = texte;  // setter : l'attribut matiere prend la valeur de texte
}

void note::set_n(double note) {
    n = note;  // setter : l'attribut n prend la valeur de note
}

void note::set_coef(int coefficient) {
    coef = coefficient;  // setter : l'attribut de coef prend la valeur de coefficient
}

ostream &operator<<(ostream &out, const note &note) {  // Affiche les elements liees a la note : la matiere, la note, le coefficient de la note
    out << "Matiere : " << note.matiere << endl;
    out << "Note : " << note.n << endl;
    out << "Coefficient associe a la note: " << note.coef << endl;

    return out;  // On retourne l'element associe a ostream
}

istream &operator>>(istream &in, note &note) {
    // Definition des variables locales
    string texte;
    double n;
    int coef;

    //Demande d'informations à l'utilisateur
    cout << "Saisir le nom de la matiere : ";
    in >> texte;
    cout << "Saisir la note : ";
    in >> n;
    cout << "Saisir le coefficient associe a la note : ";
    in >> coef;

    // On donnes les valeurs des entrees aux attributs respectifs
    note.set_matiere(texte);
    note.set_n(n);
    note.set_coef(coef);

    // On renvoie l'element associe a l'istream
    return in;
}
