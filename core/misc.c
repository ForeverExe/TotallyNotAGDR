/*
File di funzioni e define miscellanee
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//-----TESTI PREDEFINITI----//
#define WELCOME "Benvenuto in Totally Not A GDR! Il gioco e\' abbastanza corto, pero\' spero che sia godibile.\nIniziamo con la creazione del personaggio!"
#define INTRO1 "Sei un classico avventuriero, con il desiderio di esplorare il mondo e guadagnare ricchezze.\nMa come puoi definirti tale se non hai nemmeno un\' equipaggiamento?\n"
#define MERCANTEARMI "Mercante: Oh salve! Lei deve essere nuovo da queste parti. Come? Non ha nulla per difendersi? Non si preoccupi, qua puo\' trovare quello che le serve!\n\n"
#define MERCANTEARMOR "Mercante: Bene, adesso e\' meglio se ti scegli un\' armatura per difenderti."
#define MERCANTESPELL "Mercante: Per ottimizzare i danni, e\' meglio se ti scegli un incantesimo da cambiare con l\'arma quando il nemico e\' distante. Usa questo grimorio."
#define MERCANTEITEMS "Mercante: Ora sei pronto, tieni questi due oggetti, ti aiuteranno durante il viaggio."
#define ERROREMERCANTE "Mercante: Non credo di aver capito bene... Quindi, cosa scegli? "
#define ATTACCOMANCATO "Che sfortuna, l\'attacco non e\' passato...\n"
#define ITEMFINITO "Hai esaurito l\' item, la vedo male...\n"

//----Sconfitta/Vittoria----
#define PLAYERDEFEAT "Sei stato sconfitto."
#define ENEMYDEFEAT "Hai sconfitto il nemico!"

//----Descrizione Armi/Armature/Spells----//
#define SPADA "La Spada a una mano e\' un classico: leggera, versatile, e sicuramente non la usi per tagliare il salame.\n\n"
#define ARCO "L\'arco, arma di cacciatori (che siano di animali o di teste). Utile per gli attacchi a distanza.\n\n"
#define ASCIA "L\'ascia, un\'arma grezza ma dall'alto valore d'attacco malgrado lo scarso raggio.\n\n"
#define ARMORCOMPLETA "L\' armatura completa e\' la più pesante che hai trovato, molto protettiva.\n\n"
#define ARMORPLACCHE "L\'armatura a placche e\' del tipo più leggero, dà poca difesa.\n\n"
#define ARMORLEGGERA "L\'armatura leggera e\' la piu\' bilanciata che il mercante puo\' offrirti.\n\n"
#define PALLAFUOCO "Un incantesimo base che permette di lanciare sfere di fuoco contro i nemici, o per accendere dei falo\', non si sa mai.\n\n"
#define PISTOLACQUA "Nemmeno il mercante sa come ci e\' finito in questo grimorio, però\' meglio di niente.\n\n"
#define FRECCIALUCE "Leggenda narra che se l'utilizzatore e\' un credente religioso, l'incantesimo sia più forte. Sfortunatamente, non hanno ancora capito quale religione sia quella corretta.\n\n"


