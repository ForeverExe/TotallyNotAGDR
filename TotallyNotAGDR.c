/*
                        TOTALLY NOT A GDR
                    Progetto scolastico in C
                  Matteo Besutti, 4Informatico

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "core/misc.c"
#include "core/PG_stats.c"



int main(){
    int opz;
    int scelto=0;
    Giocatore* player = (Giocatore*)malloc(sizeof(Giocatore));
    SPAZIO
    printf("%s", WELCOME);
    SPAZIO
    printf("Iniziamo con la creazione del personaggio!");
    player = inizializzaPg(player);
    printf("\nCompletato il tuo equipaggiamento, inizi la tua avventura!\n\n");
    printf("Durante il viaggio hai visitato molti posti, come villaggi di montagna, foreste, rovine e chi piu\' ne ha e piu\' ne metta! Finche\'...\n");
    printf("E\' comparso un lupo! Probabilmente ti vede come la sua cena. E\' il momento di agire!\n\n");    
    do{
    printf("Che vuoi fare?\n 1 - Affrontalo\n 2 - Dagli qualcosa da mangiare\n 3 - Scappa\n\nScegli un opzione: ");
    scanf("%d", &opz);
    fflush(stdin);

    switch(opz){
        case 1:{ //combattimento 1
            scelto = 1;
            combat(player, "Lupo", 20, 50, 10);
            if(player->hp <= 0){
                printf("%s", PLAYERDEFEAT);
                getchar();
                return 0;
            }else{
                printf("%s", ENEMYDEFEAT);
                getchar();
            }
            break;
        }
        case 2:{ //cibarlo
            printf("Per fortuna avevi della carne da parte, e chissa\' perche\' del sonnifero. Comunque, gliele dai insieme ed il lupo si addormenta, permettendoti di fuggire.\n\n");
            scelto = 1;
            CONTINUA
            getchar();
            break;
        }
        case 3:{ //fuggire (game over)
            printf("Hai provato a scappare, ma il lupo era piu\' veloce di te e ti ha preso. Su col morale, almeno avevi un buon sapore.\n\n%s", PLAYERDEFEAT);
            getchar();
            return 0;
        }
        default:{
            printf("Fai il serio, scegli una delle tre opzioni!\n");
        }
    }
    }while(scelto == 0);
    scelto = 0;

    printf("Il viaggio continua, nel mentre ti stai procacciando del cibo essendo stato cosi\' furbo da non portarti dietro alcun soldo.\nComunque non sta andando male, hai anche trovato una rovina interessante: non e\' come quelle che hai visto in precedenza e quindi decidi di entrare.");
    printf("L\'entrata sembra decisamente antica e pericolante, per fortuna solo d\'aspetto.\n");
    printf("\n\nDopo un po\' di esplorazione, ti imbatti in una stanza con un altare e dei simboli sconosciuti, probabilmente di una civilta\' oppure un culto antico.\nQuello che sai, e\' che ci guadagnerai un bel gruzzoletto.\nIntanto ti avvicini ad osservare l\'altare presente nella stanza principale.\n");
    //combattimento 2
    if(strcmp(player->inventory.incantesimo.nome, "Freccia di Luce") == 0){
        printf("Guardando l'altare, senti una voce che ti chiama, come se fosse una divinità...\nEssere superiore: Oh giovane essere comune, fai attenzione a colui che mi ha imprigionato in questo posto. Accetta questo dono, in modo che tu possa combatterlo.\n\nLa tua Lancia di Luce riceve un potenziamento, sale a 40 danni!");
        player->inventory.incantesimo.danno = 40;
    }else{
        printf("Guardando l'altare, non senti nulla di strano... magari ti serve un incantesimo oppure un oggetto magico in particolare.\n\n");
    }
    printf("Dopo esserti allontanato dall\'altare, percepisci una presenza minacciosa. Non ti resta scelta che combattere.");
    player->hp = 100;
    player->mana = 100;
    combat(player, "Entita sconosciuta", 45, 100, 10);
        if(player->hp <= 0){
            printf("%s", PLAYERDEFEAT);
            getchar();
            return 0;
        }else{
            printf("%s", ENEMYDEFEAT);
            getchar();
        }
    //fine combattimento 2
    printf("Il combattimento e\' stato estenuante, ma ne sei uscito vittorioso!\nDecidi di esplorare il resto dello stanzone e le vicinanze...\n");
    CONTINUA
    getchar();
    printf("Dopo essere uscito dalla rovina, decidi di andare in una città vicina a vendere quello che hai ottenuto.\n\nFatte delle ricerche e cercato dei collezionisti e mercanti, scopri che il valore dei tuoi oggetti sono inestimabili, facendoti guadagnare cosi\' tanto da poter vivere come benestante per il resto della tua vita. \nE giustamente, fai cosi\'.\n\nGrazie per aver giocato Totally Not A GDR!\n\n");
    CONTINUA
    getchar();
    return 0;
}