void configureAndTestFile(char* fileName){
    FILE *fpin;
    fpin = fopen(fileName, "rb");
    if(!fpin){
        fclose(fpin);
        fpin = fopen(fileName, "wb");
        fclose(fpin);
    }
    else{
        fclose(fpin);
    }
}

Giocatore* downloadPersonaggio(char* fileName){
    FILE* fpin = fopen(fileName, "rb");
    Giocatore* temp = (Giocatore*)malloc(sizeof(Giocatore));
    if(fread(temp, sizeof(Giocatore), 1, fpin)){
        fclose(fpin);
        return temp;
    }else{
        fclose(fpin);
        return NULL;
    }
}

void uploadPersonaggio(char* fileName, Giocatore player){
    FILE* fpout = fopen(fileName, "wb");
    fwrite(&player, sizeof(Giocatore), 1, fpout);
    fclose(fpout);
}