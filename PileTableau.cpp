#include "PileTableau.h"

template <class T>
PileTableau<T>::PileTableau(int capaciteInitiale) : capacite(capaciteInitiale), sommetIndex(-1) {
    tab = new T[capacite];
}

template <class T>
PileTableau<T>::~PileTableau() {
    delete[] tab;
}

template <class T>
PileTableau<T>::PileTableau(const PileTableau<T>& autre): capacite(autre.capacite), sommetIndex(autre.sommetIndex) {
    tab = new T[capacite];
    for (int i = 0; i <= sommetIndex; i++) {
        tab[i] = autre.tab[i];
    }
}

template <class T>
PileTableau<T>& PileTableau<T>::operator=(const PileTableau<T>& autre) {
    if (this != &autre) {
        T* nouveauTab = new T[autre.capacite];
        for (int i = 0; i <= autre.sommetIndex; i++) {
            nouveauTab[i] = autre.tab[i];
        }
        delete[] tab;
        tab = nouveauTab;
        capacite = autre.capacite;
        sommetIndex = autre.sommetIndex;
    }
    return *this;
}

template <class T>
void PileTableau<T>::redimensionner() {
    int nouvelleCapacite = capacite * 2;
    T* nouveauTab = new T[nouvelleCapacite];
    for (int i = 0; i <= sommetIndex; i++)
        nouveauTab[i] = tab[i];
    delete[] tab;
    tab = nouveauTab;
    capacite = nouvelleCapacite;
}

template <class T>
void PileTableau<T>::empiler(const T& valeur) {
    if (sommetIndex + 1 == capacite)
        redimensionner();
    tab[++sommetIndex] = valeur;
}

template <class T>
T PileTableau<T>::depiler() {
    if (estVide())
        throw std::runtime_error("Pile vide : depiler impossible");
    return tab[sommetIndex--];
}

template <class T>
T PileTableau<T>::sommet() const {
    if (estVide())
        throw std::runtime_error("Pile vide : pas de sommet");
    return tab[sommetIndex];
}

template <class T>
bool PileTableau<T>::estVide() const {
    return sommetIndex == -1;
}

template <class T>
int PileTableau<T>::taille() const {
    return sommetIndex + 1;
}

// ========================================================
// INSTANCIATION EXPLICITE POUR LA DLL
// Sans ces lignes, la DLL sera vide car les templates
// ne sont pas compilés tant qu'ils ne sont pas appelés.
// ========================================================
template class PILE_API PileTableau<char>; // Indispensable pour votre vérificateur d'expressions
template class PILE_API PileTableau<int>;  // Pratique pour vos tests de performance
