// -------------------------------------------------------------------------------------------
// Seance 4 - 23 fev. 2022
// Kantane Pritam Charles
// 3PSC - groupe 1
// Exercice 3 - version 1.1 (avec saisie des etudiants dans la classe classe)
// -------------------------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "src/outils.hpp"
#include "src/date.hpp"
#include "src/note.hpp"
#include "src/etudiant.hpp"
#include "src/classe.hpp"
using namespace std;

// --- Programme principal ---
int main() {
    // Initialisation des objets de classe et des variables
    string nom, prenom;
    note n1("", 0, 0), n2("", 0, 0), n3("", 0, 0);
    date ddn(0, 0, 0);

    /*// Classe date
    system("cls");
    cout << "Test classe date" << endl;
    date ddn1(12, 3, 2001);                                      // Instance de la classe date
    cout << ddn1 << endl;                                        // Affichage de la date
    date ddn2(0, 0, 0);
    cout << ddn.get_annee();
    cin >> ddn2;                                                 // Saisie de la date de naissance
    cout << ddn2;                                                // Affichage de la date de naissance
    cout << endl;

    // Classe note
    cout << "Test classe note" << endl;
    note nb1("Mathematiques", 15, 2);                            // Instance de la classe note
    cout << nb1 << endl;                                         // Affichage de la note avec ses informations complementaires
    note n2b("", 0, 0);                                          // Instance de la classe note
    cin >> n2b;                                                  // Saisie des coordonnees concernant la note
    cout << n2b;                                                 // Affichage de la note avec ses informations complementaires
    cout << endl;

    // Classe etudiant
    cout << "Test classe etudiant" << endl;
    etudiant etudiant1(nom, prenom, ddn, n1, n2, n3);            // Instance de la classe etudiant
    cin >> etudiant1;                                            // Saisie des coordonnees d'un etudiant
    cout << etudiant1;                                           // Affichage des coordonnees de l'etudiant
    cout << endl;*/

    // Classe classe
    cout << "Test classe classe" << endl;
    etudiant etudiant(nom, prenom, ddn, n1, n2, n3);  // Instance de la classe etudiant
    classe Bachelor2("", "", "");                       // Instance de la classe classe
    cin >> Bachelor2;
    cout << Bachelor2;                                               // Affichage des informations de cette classe
    Bachelor2.ajouter_etudiants(etudiant);                        // Saisie des etudiants dans la classe bachelor2
    system("pause");
    Bachelor2.afficher_etudiants();                                  // Affichage des etudiants dans cette classe
    Bachelor2.rang_etudiants();                                      // Etablissement du rang en fonction des moyennes

    Bachelor2.~classe();
    system("pause");
    return 0;
}
