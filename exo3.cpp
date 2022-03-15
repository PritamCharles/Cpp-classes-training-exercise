// -------------------------------------------------------------------------------------------
// Seance 4 - 23 fev. 2022
// Kantane Pritam Charles
// 3PSC - groupe 1
// Exercice 3
// -------------------------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "src/biblio_exo3.hpp"
using namespace std;

// --- Programme principal ---
int main() {
    int jour, mois, annee;

    // Tests de la classe date
    //cout << "Entrez une date de naissance (jj/mm/aaaa) : ";
    //cin >> jour; cin.ignore(1, '/'); cin >> mois; cin.ignore(2, '/'); cin >> annee;
    date ddn(12, 12, 2000);
    //cout << ddn.get_jour();

    // Tests de la classe note
    note n1("Ma321", 15, 4);
    note n2("In313", 15, 3);
    note n3("La321", 18, 1);
    //cout << n1.get_n();

    // Tests de la classe etudiant
    etudiant etudiant1("NOM", "PRENOM", ddn, n1, n2, n3);
    //cin >> etudiant1;
    //cout << etudiant1.get_nom();
    //cout << etudiant1.get_ddn() << endl;

    etudiant1.set_moyenne(n1, n2, n3);
    cout << etudiant1;

    system("pause");
    return 0;
}

