#ifndef PILELISTE_H
#define PILELISTE_H

#include <stdexcept>
#include "PileExport.h"

template <class T>
class PILE_API PileListe {
private:
    struct Cellule {
        T valeur;
        Cellule* suivant;
        Cellule(const T& v, Cellule* s) : valeur(v), suivant(s) {}
    };

    Cellule* tete;
    int nbElements;

public:
    PileListe();
    ~PileListe();
    PileListe(const PileListe<T>& autre);
    PileListe<T>& operator=(const PileListe<T>& autre);

    void empiler(const T& valeur);
    T depiler();
    T sommet() const;
    bool estVide() const;
    int taille() const;
};

#endif
