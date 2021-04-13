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
    int preso=0;
    printf("\nInserisci il nome del personaggio: ");
    scanf("%s", player->nome);
    fflush(stdin);
    printf("\n%s", INTRO1);
    printf("%s", MERCANTEARMI);
    printf("Scegli un\'arma:\n ");
    printf("1. Spada a una mano [10 Attacco, 5 Distanza]\n2. Arco (con ovviamente delle frecce)[5 attacco, 20 distanza]\n3. Ascia da guerra (almeno secondo il mercante)[20 attacco, 3 distanza]\nMercante: Quindi? Cosa scegli? ");
    do{
        scanf("%d", &opz);
        fflush(stdin);
        switch(opz){
            case 1:{
                printf("%s", SPADA);
                player->inventory.arma = setWeapon(player->inventory.arma, "Spada a una mano", 10, 5);
                preso = 1;
                break;
            }
            case 2:{
                printf("%s", ARCO);
                player->inventory.arma = setWeapon(player->inventory.arma, "Arco e frecce", 5, 20);
                preso = 1;
                break;
            }
            case 3:{
                printf("%s", ASCIA);
                player->inventory.arma = setWeapon(player->inventory.arma, "Ascia", 20, 3);
                preso = 1;
                break;
            }
            default:{
                printf("%s", ERROREMERCANTE);
                break;
            }
        }
    }while(preso == 0 );

    preso = 0;
    printf("%s", MERCANTEARMOR);
    printf("Scegli un' armatura:\n");
    printf("1. Armatura completa [40 armatura]\n2. Armatura a placche [20 armatura]\n3. Armatura leggera [25 armatura]");
    do{
        scanf("%d", &opz);
        fflush(stdin);
        switch(opz){
            case 1:{
                printf("%s", ARMORCOMPLETA);
                player->inventory.armor = setArmor(player->inventory.armor, "Armatura Pesante", 40);
                preso = 1;
                break;
            }
            case 2:{
                printf("%s", ARMORPLACCHE);
                player->inventory.armor = setArmor(player->inventory.armor, "Armatura a placche", 20);
                preso = 1;
                break;
            }
            case 3:{
                printf("%s", ARMORLEGGERA);
                player->inventory.armor = setArmor(player->inventory.armor, "Armatura Leggera", 25);
                preso = 1;
                break;
            }
            default:{
                printf("%s", ERROREMERCANTE);
                break;
            }
        }
    }while(preso == 0 );

    preso=0;
    printf("%s", MERCANTESPELL);
    printf("Scegli un incantesimo (puramente estetico, forse, sebbene non ci sia un interfaccia grafica *occhiolino*):\n");
    printf("1. Palla di Fuoco\n2. Pistolacqua(?)\n2. Freccia di luce");
    do{
        scanf("%d", &opz);
        fflush(stdin);
        switch(opz){
            case 1:{
                printf("%s", PALLAFUOCO);
                player->inventory.incantesimo = setSpell(player->inventory.incantesimo, "Palla di Fuoco", 10, 10);
                preso = 1;
                break;
            }
            case 2:{
                printf("%s", PISTOLACQUA);
                player->inventory.incantesimo = setSpell(player->inventory.incantesimo, "Pistolaqua", 10, 10);
                preso = 1;
                break;
            }
            case 3:{
                printf("%s", FRECCIALUCE);
                player->inventory.incantesimo = setSpell(player->inventory.incantesimo, "Freccia di Luce", 10, 10);
                preso = 1;
                break;
            }
            default:{
                printf("%s", ERROREMERCANTE);
                break;
            }
        }
    }while(preso == 0 );




    return player;
}