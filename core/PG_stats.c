/*
Struttura personaggio e funzioni di modifica interna ad essa, come l'inserimento di item nell' inventario oppure di calcolo dei danni/sottrazione mana da incantesimi
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Items.c"
#include "misc.c"

Giocatore inizializzaPg(Giocatore player);

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

Giocatore inizializzaPg(Giocatore player){
    int opz;

    printf("Inserisci il nome del personaggio: ");
    gets(player.nome);
    fflush(stdin);
    TESTOINGAME("Sei un classico avventuriero, con il desiderio di esplorare il mondo e guadagnare ricchezze.\nMa come puoi definirti tale se non hai nemmeno un\' equipaggiamento?\n")
    TESTOINGAME("Mercante: Oh salve! Lei deve essere nuovo da queste parti. Come? Non ha nulla per difendersi? Non si preoccupi, qua può trovare quello che le serve!\n\n")
    printf("Scegli un\'arma:\n ");
    printf("1. Spada a una mano [10 Attacco, 5 Distanza]\n2. Arco (con ovviamente delle frecce)[5 attacco, 20 distanza]\n3. Ascia da guerra (almeno secondo il mercante)[20 attacco, 3 distanza]\nMercante: Quindi? Cosa scegli? ");
    scanf("%d", &opz);

    switch(opz){
        case 1:{
            printf("La Spada a una mano e\' un classico: leggera, versatile, e sicuramente non la usi per tagliare il salame.");
            player.inventory.arma = setWeapon(player.inventory.arma, "Spada a una mano", "E\' un classico: leggera, versatile, e sicuramente non la usi per tagliare il salame.", 10, 5);
            break;
        }
        case 2:{
            printf("L\'arco, arma di cacciatori (che siano di animali o di teste). Utile per gli attacchi a distanza.");
            player.inventory.arma = setWeapon(player.inventory.arma, "Arco e frecce", "L\' arco, arma di cacciatori (che siano di animali o di teste). Utile per gli attacchi a distanza.", 5, 20);
            break;
        }
        case 3:{
            printf("L\'ascia, un\'arma grezza ma dall'alto valore d'attacco malgrado lo scarso raggio.");
            player.inventory.arma = setWeapon(player.inventory.arma, "Ascia", "L\'ascia, un\'arma grezza ma dall'alto valore d'attacco malgrado lo scarso raggio.", 20, 3);
            break;
        }
    }

    TESTOINGAME("Mercante: Bene, adesso è meglio se ti scegli un' armatura per difenderti.")
    printf("Scegli un' armatura:\n");
    printf("1. Armatura completa [40 armatura]\n2. Armatura a placche [20 armatura]\n3. Armatura leggera [25 armatura]");





    return player;
}