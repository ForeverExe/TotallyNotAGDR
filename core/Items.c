/*
    Strutture delle armi e degli oggetti e funzioni annesse
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "misc.c"


typedef struct arma{
    int danno;                  //danno dell' arma
    int distanza;               //raggio dell' attacco
    char nome[50];              //nome dell' item
    char descrizione[200];      //descrizione dell' item
}Arma;

typedef struct armor{
    int armor;                  //resistenza armatura
    char nome[50];              //nome dell' item
    char descrizione[200];      //descrizione dell' item
}Armor;

typedef struct spell{
    int danno;
    int mana_richiesto;
    char nome[50];              //nome dell' item
    char descrizione[200];      //descrizione dell' item
}Spell;

typedef struct item{    
    int value;
    int utilizzi;
    char tag[5];
    char nome[50];
    char descrizione[200];
}Item;

Arma setWeapon(Arma arma, char* nome, char* descrizione, int danno, int distanza);
Armor setArmor(Armor armor, char* nome, char* descrizione, int armatura);
Item setItem(Item oggetto, char* nome, char* descrizione,char* tag, int value);

/**
 * @brief Imposta/aggiorna l'arma
 * 
 * @param Arma struttura arma 
 * @param char nome dell'arma
 * @param char descrizione dell'arma
 * @param int danno dell'arma
 * @param distanza raggio d'azione dell'arma
 * @return Arma 
 */
Arma setWeapon(Arma arma, char* nome, char* descrizione, int danno, int distanza){
    strcpy(arma.nome, nome);
    strcpy(arma.descrizione, descrizione);
    arma.danno = danno;
    arma.distanza = distanza;
    return arma;
}

/**
 * @brief Imposta/aggiorna l'armatura
 * 
 * @param Armor armor 
 * @param char nome 
 * @param char descrizione 
 * @param int armatura 
 * @return Armor 
 */
Armor setArmor(Armor armor, char* nome, char* descrizione, int armatura){
    strcpy(armor.nome, nome);
    strcpy(armor.descrizione, descrizione);
    armor.armor = armatura;
    return armor;
}

/**
 * @brief Imposta/aggiorna item
 * 
 * @param Item oggetto 
 * @param char nome 
 * @param char descrizione 
 * @param int value 
 * @return Item 
 */
Item setItem(Item oggetto, char* nome, char* descrizione,char* tag, int value){
    strcpy(oggetto.nome, nome);
    strcpy(oggetto.descrizione, descrizione);
    strcpy(oggetto.tag, tag);
    oggetto.value = value;
    return oggetto;
}
