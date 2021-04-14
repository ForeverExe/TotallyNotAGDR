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
    printf("%s", WELCOME);
    player = inizializzaPg(player);

    printf("Completato il tuo equipaggiamento, inizi la tua avventura!");
    printf("Durante il viaggio hai visitato molti posti, come villaggi di montagna, foreste, rovine e chi piu\' ne ha e piu\' ne metta! Finche\'...\n");
    printf("E\' comparso un lupo! Probabilmente ti vede come la sua cena. E\' il momento di agire!\n");    
    do{
    printf("Che vuoi fare?\n 1 - Affrontalo\n 2 - Dagli qualcosa da mangiare\n 3 - Scappa\n\nScegli un opzione: ");
    scanf("%d", &opz);
    fflush(stdin);

    switch(opz){
        case 1:{ //combattimento
            scelto = 1;
            combat(player, "Lupo", 20, 50, 5);
            if(player->hp <= 0){
                printf("%s", PLAYERDEFEAT);
                return 0;
            }else{
                printf("%s", ENEMYDEFEAT);
            }
            break;
        }
        case 2:{ //cibarlo
            printf("Per fortuna avevi della carne da parte, e chissa\' perche\' del sonnifero. Comunque, gliele dai insieme ed il lupo si addormenta, permettendoti di fuggire.");
            scelto = 1;
            break;
        }
        case 3:{ //fuggire (game over)
            printf("Hai provato a scappare, ma il lupo era piu\' veloce di te e ti ha preso. Su col morale, almeno avevi un buon sapore.\n\n%s", PLAYERDEFEAT);
            return 0;
        }
        default:{
            printf("Fai il serio, scegli una delle tre opzioni!\n");
        }
    }
    }while(scelto == 0);
    return 0;
}