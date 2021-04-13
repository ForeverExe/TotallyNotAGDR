/*
Struttura personaggio e funzioni di modifica interna ad essa, come l'inserimento di item nell' inventario oppure di calcolo dei danni/sottrazione mana da incantesimi
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Items.c"
#include "misc.c"

typedef struct inventario{
    Arma arma;
    Armor armor;
    Item item1;
    Item item2;
    Spell incantesimo;
}Inventario;

typedef struct giocatore{
    char nome[40];
    int mana;
    int hp;

    Inventario inventory;

}Giocatore;

Giocatore* inizializzaPg(Giocatore* player);

//fase di creazione del personaggio
Giocatore* inizializzaPg(Giocatore* player){
    int opz;

    printf("\nInserisci il nome del personaggio: ");
    scanf("%s", player->nome);
    fflush(stdin);
    printf("%s", INTRO1);
    printf("%s", MERCANTEARMI);
    printf("Scegli un\'arma:\n ");
    printf("1. Spada a una mano [10 Attacco, 5 Distanza]\n2. Arco (con ovviamente delle frecce)[5 attacco, 20 distanza]\n3. Ascia da guerra (almeno secondo il mercante)[20 attacco, 3 distanza]\nMercante: Quindi? Cosa scegli? ");
    do{
        scanf("%d", &opz);
        fflush(stdin);
        switch(opz){
            case 1:{
                printf("%s", SPADA);
                player->inventory.arma = setWeapon(player->inventory.arma, "Spada a una mano", SPADA, 10, 5);
                break;
            }
            case 2:{
                printf("%s", ARCO);
                player->inventory.arma = setWeapon(player->inventory.arma, "Arco e frecce", ARCO, 5, 20);
                break;
            }
            case 3:{
                printf("%s", ASCIA);
                player->inventory.arma = setWeapon(player->inventory.arma, "Ascia", ASCIA, 20, 3);
                break;
            }
            default:{
                printf("%s", ERROREMERCANTE);
            }
        }
    }while(opz != 1 || opz != 2 || opz != 3);

    // TESTOINGAME("Mercante: Bene, adesso è meglio se ti scegli un' armatura per difenderti.")
    // printf("Scegli un' armatura:\n");
    // printf("1. Armatura completa [40 armatura]\n2. Armatura a placche [20 armatura]\n3. Armatura leggera [25 armatura]");
    // scanf("%d", opz);
    // fflush(stdin);





    return player;
}