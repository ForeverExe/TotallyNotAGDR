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

//----Struttura Nemico----//
typedef struct nemico{
    char nome[30];
    int danno;
    int hp;
    int distanza;
}Nemico;

Giocatore* inizializzaPg(Giocatore* player);
void combat(Giocatore* player, char* enemyName, int enemyDmg, int enemyHp, int enemyDistance);

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
    printf("1. Spada a una mano [10 Attacco, 10 Distanza]\n2. Arco (con ovviamente delle frecce)[5 attacco, 20 distanza]\n3. Ascia da guerra (almeno secondo il mercante)[20 attacco, 5 distanza]\nMercante: Quindi? Cosa scegli? ");
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
    printf("1. Palla di Fuoco [10 mana | 10 danno]\n2. Pistolacqua(?) [10 mana | 10 danno]\n2. Freccia di luce [10 mana | 10 danno]");
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

    printf("%s\nHai ottenuto:\n- 1x Pozione (HP, 5 usi)\n- 1x Acqua distillata (Mana, 5 usi)", MERCANTEITEMS);
    
    player->inventory.item1 = setItem(player->inventory.item1, "Pozione", "HP", 20, 5);
    player->inventory.item2 = setItem(player->inventory.item2, "Acqua Distillata", "MANA", 20, 5);

    return player;
}

/**
 * @brief Funzione che avvia la modalità combattimento dato il player ed i parametri del nemico
 * @param Giocatore La struttura Giocatore
 * @param char* Il nome del nemico
 * @param int I danni del nemico
 * @param int Gli HP del nemico
 * @return void
 */
void combat(Giocatore* player, char* enemyName, int enemyDmg, int enemyHp, int enemyDistance){
    bool turno = true; //true == turno player | false == turno nemico
    int scelta; 

    Nemico enemy;
    enemy.hp = enemyHp;
    enemy.danno = enemyDmg;
    enemy.distanza = enemyDistance;
    strcpy(enemy.nome, enemyName);

    do{
        if(turno){  //TURNO PG
            do{
                printf("\nHP: %d | Mana: %d\n", player->hp, player->mana);
                printf("1. %s\n2. %s\n3. %s\n4. %s\nCosa scegli? ", player->inventory.arma.nome, player->inventory.incantesimo.nome, player->inventory.item1.nome, player->inventory.item2.nome);
                scanf("%d", &scelta);
                fflush(stdin);
            }while(scelta);
            switch(scelta){
                case 1:{ //ATT CORPO A CORPO

                    if(player->inventory.arma.distanza >= enemy.distanza){
                        printf("Attacchi usando %s con successo, infliggi %d danni!", player->inventory.arma.nome, player->inventory.arma.danno);
                        enemy.hp = enemy.hp - player->inventory.arma.danno;
                    }else{
                        printf("%s", ATTACCOMANCATO);
                    }
                    break;
                }
                case 2:{ //ATT MAGIA

                    printf("Attacchi usando %s con successo, infliggi %d danni!", player->inventory.incantesimo.nome, player->inventory.incantesimo.danno);
                        enemy.hp = enemy.hp - player->inventory.incantesimo.danno;
                        player->mana = player->mana - 10;
                    break;
                }
                case 3:{ //item 1 == HP
                    if(player->inventory.item1.utilizzi > 0){
                        if(player->hp < 100){
                            printf("Utilizzi la %s, recuperi vita!");
                            player->hp += player->inventory.item1.value;
                            player->inventory.item1.utilizzi = player->inventory.item1.utilizzi - 1;
                            if(player->hp >100){ //se supera il cap dei 100hp
                                player->hp = 100;
                            }
                        }else{
                            printf("Sei già a pieni HP!");
                        }
                    }else{
                        printf("%s", ITEMFINITO);
                    }
                    break;
                }
                case 4:{ //item 2 == MANA
                    if(player->inventory.item2.utilizzi > 0){
                        if(player->hp < 100){
                            printf("Utilizzi la %s, recuperi mana!");
                            player->mana += player->inventory.item2.value;
                            player->inventory.item2.utilizzi = player->inventory.item2.utilizzi - 1;
                            if(player->mana >100){ //se supera il cap dei 100mana
                                player->mana = 100;
                            }
                        }else{
                            printf("Il tuo spirito e\' gia\' stabile!");
                        }
                    }else{
                        printf("%s", ITEMFINITO);
                    }
                    break;
                }
            }

            
            turno = false;
        }else{ //TURNO NEMICO




            turno = true;
        }
    }while(player->hp <= 0 || enemy.hp <= 0);


}













