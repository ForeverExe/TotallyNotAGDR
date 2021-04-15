/*
File di funzioni e define miscellanee
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//-----TESTI PREDEFINITI----//
#define SPAZIO printf("#########################################################################################\n");
#define WELCOME "Benvenuto in Totally Not A GDR!\nIl gioco e\' abbastanza corto, pero\' spero che sia godibile.\nPrima di iniziare un paio di regole:\n1- Il gioco essendo corto va fatto tutto in un fiato, niente di troppo complicato pero\'.\n2- Fai attenzione alle tue scelte, alcune possono darti ricompense o terminare il gioco.\n3- In questo gioco e\' presente la meccanica della \'distanza\': A seconda del valore, il colpo puo\' andare o meno a segno, non include gli incantesimi.\n"
#define INTRO "Sei un classico avventuriero, con il desiderio di esplorare il mondo e guadagnare ricchezze.\nMa come puoi definirti tale se non hai nemmeno un\' equipaggiamento?\n\n"
#define MERCANTEARMI "Mercante: Oh salve! Lei deve essere nuovo da queste parti. Come? Non ha nulla per difendersi? Non si preoccupi, qua puo\' trovare quello che le serve!\n"
#define MERCANTEARMOR "Mercante: Bene, adesso e\' meglio se ti scegli un\' armatura per difenderti."
#define MERCANTESPELL "Mercante: Per ottimizzare i danni, e\' meglio se ti scegli un incantesimo da cambiare con l\'arma quando il nemico e\' distante. Usa questo grimorio.\n"
#define MERCANTEITEMS "Mercante: Ora sei pronto, tieni questi due oggetti, ti aiuteranno durante il viaggio."
#define ERROREMERCANTE "Mercante: Non credo di aver capito bene... Quindi, cosa scegli? "
#define ATTACCOMANCATO "Che sfortuna, l\'attacco non e\' passato...\n"
#define ITEMFINITO "Hai esaurito l\' item, la vedo male...\n"

//----Sconfitta/Vittoria----
#define PLAYERDEFEAT "Sei stato sconfitto. Premi un tasto per terminare l\'avventura."
#define ENEMYDEFEAT "Hai sconfitto il nemico! Premi un tasto per continuare."

//----Descrizione Armi/Armature/Spells----//
#define SPADA "La Spada a una mano e\' un classico: leggera, versatile, e sicuramente non la usi per tagliare il salame.\n\n"
#define ARCO "L\'arco, arma di cacciatori (che siano di animali o di teste). Utile per gli attacchi a distanza.\n\n"
#define ASCIA "L\'ascia, un\'arma grezza ma dall'alto valore d\'attacco malgrado lo scarso raggio.\n\n"
#define ARMORCOMPLETA "L\' armatura completa e\' la piu\' pesante che hai trovato, molto protettiva.\n\n"
#define ARMORPLACCHE "L\'armatura a placche e\' del tipo piu\' leggero, da\' poca difesa.\n\n"
#define ARMORLEGGERA "L\'armatura leggera e\' la piu\' bilanciata che il mercante puo\' offrirti.\n\n"
#define PALLAFUOCO "Un incantesimo base che permette di lanciare sfere di fuoco contro i nemici, o per accendere dei falo\', non si sa mai.\n\n"
#define PISTOLACQUA "Nemmeno il mercante sa come ci e\' finito in questo grimorio, pero\' meglio di niente.\n\n"
#define FRECCIALUCE "Leggenda narra che se l'utilizzatore e\' un credente religioso, l'incantesimo sia piu\' forte. Sfortunatamente, non hanno ancora capito quale religione sia quella corretta.\n\n"

#define CONTINUA printf("Premi un tasto per continuare.");



