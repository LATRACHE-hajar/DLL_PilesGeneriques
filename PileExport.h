#ifndef PILEEXPORT_H
#define PILEEXPORT_H

// Si "BUILD_DLL" est défini dans les options de votre projet, on exporte.
// Sinon, cela veut dire qu'on l'utilise depuis un autre projet, donc on importe.
#ifdef BUILD_DLL
    #define PILE_API __declspec(dllexport)
#else
    #define PILE_API __declspec(dllimport)
#endif

#endif
