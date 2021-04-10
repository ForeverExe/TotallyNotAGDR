/*
Struttura personaggio e funzioni di modifica interna ad essa, come l'inserimento di item nell' inventario oppure di calcolo dei danni/sottrazione mana da incantesimi
*/

#include "Items.c"
typedef struct giocatore{
    char nome[40];
    int mana;
    int hp;

    Inventario inventory;

}Giocatore;

typedef struct inventario{
    Arma arma;
    Armor armor;
    Item item1;
    Item item2;
    Spell incantesimo;
}Inventario;