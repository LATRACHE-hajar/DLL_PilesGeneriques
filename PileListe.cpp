#include "PileListe.h"
#include <utility>

template <class T>
PileListe<T>::PileListe() : tete(nullptr), nbElements(0) {}

template <class T>
PileListe<T>::~PileListe() {
    while (!estVide())
        depiler();
}

template <class T>
void PileListe<T>::empiler(const T& valeur) {
    tete = new Cellule(valeur, tete);
    nbElements++;
}

template <class T>
PileListe<T>::PileListe(const PileListe<T>& autre) : tete(nullptr), nbElements(0) {
    Cellule* dernier = nullptr;
    for (Cellule* p = autre.tete; p != nullptr; p = p->suivant) {
        Cellule* nouvelle = new Cellule(p->valeur, nullptr);
        if (dernier == nullptr) tete = nouvelle;
        else dernier->suivant = nouvelle;
        dernier = nouvelle;
        nbElements++;
    }
}

template <class T>
PileListe<T>& PileListe<T>::operator=(const PileListe<T>& autre) {
    if (this != &autre) {
        PileListe<T> copie(autre);
        std::swap(tete, copie.tete);
        std::swap(nbElements, copie.nbElements);
    }
    return *this;
}

template <class T>
T PileListe<T>::depiler() {
    if (estVide())
        throw std::runtime_error("Pile vide : depiler impossible");
    Cellule* ancienneTete = tete;
    T valeur = ancienneTete->valeur;
    tete = tete->suivant;
    delete ancienneTete;
    nbElements--;
    return valeur;
}

template <class T>
T PileListe<T>::sommet() const {
    if (estVide())
        throw std::runtime_error("Pile vide : pas de sommet");
    return tete->valeur;
}

template <class T>
bool PileListe<T>::estVide() const {
    return tete == nullptr;
}

template <class T>
int PileListe<T>::taille() const {
    return nbElements;
}

// INSTANCIATION EXPLICITE POUR LA DLL
template class PILE_API PileListe<char>;
template class PILE_API PileListe<int>;
