#ifndef PILETABLEAU_H
#define PILETABLEAU_H

#include <iostream>
#include <stdexcept>
#include "PileExport.h" // 1. On inclut la macro

template <class T>
class PILE_API PileTableau { // 2. On ajoute PILE_API pour l'exportation
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
