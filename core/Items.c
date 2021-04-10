/*
    Strutture delle armi e degli oggetti e funzioni annesse
*/

typedef struct arma{
    int danno;                  //danno dell' arma
    int distanza;               //raggio dell' attacco
    char nome[50];              //nome dell' item
    char descrizione[100];      //descrizione dell' item
}Arma;

typedef struct armor{
    int armor;                  //resistenza armatura
    char nome[50];              //nome dell' item
    char descrizione[100];      //descrizione dell' item
}Armor;

typedef struct spell{
    int danno;
    int mana_richiesto;
    char nome[50];              //nome dell' item
    char descrizione[100];      //descrizione dell' item
}Spell;

typedef struct item{    
    int value;
    int utilizzi;
    char nome[50];
    char descrizione[100];
}Item;
