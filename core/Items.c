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
}Arma;

typedef struct armor{
    int armor;                  //resistenza armatura
    char nome[20];              //nome dell' item
}Armor;

typedef struct spell{
    int danno;                  //danno dell' incantesimo
    int mana_richiesto;         //mana richiesto per lanciare l'incantesimo
    char nome[50];              //nome dell' item
}Spell;

typedef struct item{    
    int value;                  //valore numerico dell' item (Quanto cura o quanto mana dà)
    int utilizzi;               //quante volte l'item è utilizzabile
    char nome[50];              //nome dell'item
}Item;

Arma setWeapon(Arma arma, char* nome, int danno, int distanza);
Armor setArmor(Armor armor, char* nome, int armatura);
Spell setSpell(Spell incantesimo, char* nome, int danno, int mana);
Item setItem(Item oggetto, char* nome, int value, int utilizzi);

/**
 * @brief Imposta/aggiorna l'arma
 * 
 * @param Arma struttura arma 
 * @param char nome dell'arma
 * @param int danno dell'arma
 * @param distanza raggio d'azione dell'arma
 * @return Arma 
 */
Arma setWeapon(Arma arma, char* nome, int danno, int distanza){
    strcpy(arma.nome, nome);
    arma.danno = danno;
    arma.distanza = distanza;
    return arma;
}

/**
 * @brief Imposta/aggiorna l'armatura
 * 
 * @param Armor armor 
 * @param char nome 
 * @param int armatura 
 * @return Armor 
 */
Armor setArmor(Armor armor, char* nome, int armatura){
    strcpy(armor.nome, nome);
    armor.armor = armatura;
    return armor;
}

/**
 * @brief Imposta incantesimo
 * 
 * @param Spell struttura incantesimo 
 * @param char* nome dell' incantesimo 
 * @param int danno dell' incantesimo 
 * @param int mana richiesto 
 * @return Spell 
 */
Spell setSpell(Spell incantesimo, char* nome, int danno, int mana){
    strcpy(incantesimo.nome, nome);
    incantesimo.danno = danno;
    incantesimo.mana_richiesto = mana;
}

/**
 * @brief Imposta/aggiorna item
 * 
 * @param Item oggetto 
 * @param char nome 
 * @param int value
 * @param int utilizzi 
 * @return Item 
 */
Item setItem(Item oggetto, char* nome, int value, int utilizzi){
    strcpy(oggetto.nome, nome);
    oggetto.value = value;
    return oggetto;
}
