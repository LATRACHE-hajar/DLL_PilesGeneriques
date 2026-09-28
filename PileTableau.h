#ifndef PILETABLEAU_H
#define PILETABLEAU_H

#include <iostream>
#include <stdexcept>
#include "PileExport.h"

template <class T>
class PILE_API PileTableau {
private:
    T* tab;
    int capacite;
    int sommetIndex;

    void redimensionner();

public:
    PileTableau(int capaciteInitiale = 4);
    ~PileTableau();
    PileTableau(const PileTableau<T>& autre);
    PileTableau<T>& operator=(const PileTableau<T>& autre);

    void empiler(const T& valeur);
    T depiler();
    T sommet() const;
    bool estVide() const;
    int taille() const;
};

#endif
