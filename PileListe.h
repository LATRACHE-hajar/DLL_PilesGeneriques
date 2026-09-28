#ifndef PILELISTE_H
#define PILELISTE_H

#include <stdexcept>
#include "PileExport.h" // 1. On inclut la macro d'exportation/importation

template <class T>
class PILE_API PileListe { // 2. On ajoute PILE_API ici
private:
    struct Cellule {
        T valeur;
        Cellule* suivant;
        Cellule(const T& v, Cellule* s) : valeur(v), suivant(s) {}
    };

    Cellule* tete;   // pointeur vers le sommet de la pile
    int nbElements;

public:
    PileListe();
    ~PileListe();
    PileListe(const PileListe<T>& autre);              // constructeur de copie
    PileListe<T>& operator=(const PileListe<T>& autre); // affectation

    void empiler(const T& valeur);
    T depiler();
    T sommet() const;
    bool estVide() const;
    int taille() const;
};

#endif
