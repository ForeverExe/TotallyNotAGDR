/*
File di funzioni e define miscellanee
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//-----TESTI PREDEFINITI----//
#define WELCOME "Benvenuto in Totally Not A GDR! Si, il titolo e\' abbastanza autoesplicativo.\nIniziamo con la creazione del personaggio!"
#define INTRO1 "Sei un classico avventuriero, con il desiderio di esplorare il mondo e guadagnare ricchezze.\nMa come puoi definirti tale se non hai nemmeno un\' equipaggiamento?\n"
#define MERCANTEARMI "Mercante: Oh salve! Lei deve essere nuovo da queste parti. Come? Non ha nulla per difendersi? Non si preoccupi, qua può trovare quello che le serve!\n\n"
#define MERCANTEARMOR "Mercante: Bene, adesso è meglio se ti scegli un' armatura per difenderti."
#define MERCANTESPELL "Mercante: Per ottimizzare i danni, è meglio se ti scegli un incantesimo da cambiare con l'arma quando il nemico è distante. Usa questo grimorio."
#define ERROREMERCANTE "Mercante: Non credo di aver capito bene... Quindi, cosa scegli? "

//----Sconfitta/Vittoria----
#define PLAYERDEFEAT "Sei stato sconfitto."
#define ENEMYDEFEAT "Hai sconfitto il nemico!"

//----Descrizione Armi/Armature/Spells----//
#define SPADA "La Spada a una mano e\' un classico: leggera, versatile, e sicuramente non la usi per tagliare il salame."
#define ARCO "L\'arco, arma di cacciatori (che siano di animali o di teste). Utile per gli attacchi a distanza."
#define ASCIA "L\'ascia, un\'arma grezza ma dall'alto valore d'attacco malgrado lo scarso raggio."
#define ARMORCOMPLETA "L\' armatura completa e\' la più pesante che hai trovato, molto protettiva"
#define ARMORPLACCHE "L\'armatura a placche e\' del tipo più leggero, dà poca difesa."
#define ARMORLEGGERA "L\'armatura leggera e\' la piu\' bilanciata che il mercante puo\' offrirti."
#define PALLAFUOCO "Un incantesimo base che permette di lanciare sfere di fuoco contro i nemici, o per accendere dei falo\', non si sa mai."
#define PISTOLACQUA "Nemmeno il mercante sa come ci e\' finito in questo grimorio, però\' meglio di niente."
#define FRECCIALUCE "Leggenda narra che se l'utilizzatore e\' un credente religioso, l'incantesimo sia più forte. Sfortunatamente, non hanno ancora capito quale religione sia quella corretta."