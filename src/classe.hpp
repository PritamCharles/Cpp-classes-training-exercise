// -------------------------------------------------------------------------------------------
// Seance 4 - 23 fev. 2022
// Kantane Pritam Charles
// 3PSC - groupe 1
// Bibliotheque de la classe classe
// -------------------------------------------------------------------------------------------
using namespace std;

// --- Classe classe ---

class classe {
// Definition des attributs prives
private:
    string niveau, groupe, ecole;
    vector<etudiant*> liste_etudiants;
    vector<double> liste_moyennes;

// Definition des methodes publiques et des constructeurs
public:
    classe(string, string, string);  // Constructeur a trois parametres
    ~classe();

    // setter et getter
    string get_niveau();
    string get_groupe();
    string get_ecole();
    vector<etudiant*> get_liste_etudiants();  // Creation d'une liste avec la librairie vector, pour stocker les etudiants
    vector<double>  get_liste_moyennes();     // Creation d'une liste avec la librairie vector, pour stocker les moyennes, pour faire le rang plus tard
    void set_niveau(string);
    void set_groupe(string);
    void set_ecole(string);

    // istream et ostream
    friend ostream &operator<<(ostream &, const classe &);
    friend istream &operator>>(istream &, classe &);

    // Methodes publiques
    void ajouter_etudiants(etudiant);
    void afficher_etudiants();
    void rang_etudiants();
};

classe::classe(string nv, string grp, string ecl) {
    niveau = nv;
    groupe = grp;
    ecole = ecl;
}

classe::~classe() {
    int i;
    for (i = 0; i < liste_etudiants.size(); i++) {
        delete liste_etudiants[i];
    }
    liste_etudiants.clear();
    liste_moyennes.clear();
}

string classe::get_niveau() {
    return niveau;
}

string classe::get_groupe() {
    return groupe;
}

string classe::get_ecole() {
    return ecole;
}

vector<etudiant*> classe::get_liste_etudiants() {
    return liste_etudiants;
}

vector<double> classe::get_liste_moyennes() {
    return liste_moyennes;
}

void classe::set_niveau(string nv) {
    niveau = nv;
}

void classe::set_groupe(string grp) {
    groupe = grp;
}

void classe::set_ecole(string ecl) {
    ecole = ecl;
}

ostream &operator<<(ostream &out, const classe &c) {
    tirets();
    out << "Classe : " << c.niveau << endl;
    out << "Groupe : " << c.groupe << endl;
    out << "Location (ecole) : " << c.ecole << endl;
    tirets();

    return out;
}

istream &operator>>(istream &in, classe &classe) {
    // Demande les informations relatives au groupe, au niveau, et a l'ecole
    string nv, grp, ecl;

    cout << "Dans quelle ecole se trouve la classe ? ";
    in >> ecl;

    cout << "Quel est son niveau ? ";
    in >> nv;

    cout << "Quel groupe ?";
    in >> grp;

    classe.set_ecole(ecl);
    classe.set_niveau(nv);
    classe.set_groupe(grp);

    return in;
}

void classe::ajouter_etudiants(etudiant e) {
    int n;

    do {
        cout << "Combien d'etudiants voulez-vous rentrer ? ";  // On demande combien d'etudiants l'utilisateur veut entrer
        cin >> n;
        system("cls");

        for (int i = 0; i < n; i++) {  // Dans une boucle allant jusqu'a n etudiants a rentrer
            cin >> e;              // On saisit l'etudiant avec la methode istream de la classe etudiant
            cout << endl;
            liste_etudiants.push_back(new etudiant(e.get_prenom(), e.get_nom(), e.get_ddn(), e.get_n1(), e.get_n2(), e.get_n3()));   // push_back permet d'envoyer l'objet d'une classe vers une liste dans lquelle il va etre stocke
            liste_moyennes.push_back(e.calcul_moyenne(e.get_n1(), e.get_n2(), e.get_n3()));                                          // On envoie les moyennes de chaque etudiant dans une liste
        }
    } while ((n <= 0) || (n > 40));  // Verfication pour que le nombre d'etudiant d'une classe soit toujours comprise entre 1 et 40 inclus
}

void classe::afficher_etudiants() {
    int i = 0;
    system("cls");

    // Pour afficher tous les etudiants de la liste, on parcourt la liste et on affiche toutes les coordonnees en prenant chaque information
    for (i = 0; i < liste_etudiants.size(); i++) {
        tirets();
        cout << "Etudiant " << i + 1 << endl;
        tirets();

        cout << "Nom : " << liste_etudiants[i]->get_nom() << endl << "Prenom : " << liste_etudiants[i]->get_prenom() << endl;
        cout << "Date de naissance : " << liste_etudiants[i]->get_ddn() << endl;
        tirets();
        cout << liste_etudiants[i]->get_n1() << endl;
        cout << liste_etudiants[i]->get_n2() << endl;
        cout << liste_etudiants[i]->get_n3() << endl;
        tirets();
        liste_etudiants[i]->calcul_moyenne(liste_etudiants[i]->get_n1(), liste_etudiants[i]->get_n2(), liste_etudiants[i]->get_n3());
        cout << "Moyenne de l'etudiant : " << liste_etudiants[i]->get_moyenne() << endl;
        tirets();
        cout << endl;
    }
}

void classe::rang_etudiants() {
    int i, j, l;
    sort(liste_moyennes.begin(), liste_moyennes.end(), greater<>()); // Methode sort qui trie les elements d'un vecteur

    // Affichage du rang des eleves dans la classe
    system("cls");
    cout << "Rang des eleves de la classe " << niveau << " - " << niveau << " " << groupe << endl << endl;
    for (i = 0; i < liste_moyennes.size(); i++) {
        for (j = 0; j < liste_etudiants.size(); j++) {
            if (liste_etudiants[j]->get_moyenne() == liste_moyennes[i]) {
                cout << i + 1 << ". " << liste_etudiants[j]->get_prenom() << " " << liste_etudiants[j]->get_nom() << ", moyenne generale : " << liste_etudiants[j]->get_moyenne() << endl;
                liste_etudiants.erase(liste_etudiants.begin() + j);
            }
        }
    }
}
