#include <stdio.h>
#include<stdlib.h> 
#include"linkedlist.h"
#include<string.h>

void readworkout(Workout * w) {
        printf("Dobavi ime:\n");
        fgets(w->name, MAX_NAME+1, stdin);

        printf("Dobavi opisanie:\n");
        fgets(w->opisanie, MAX_OPISANIE+1, stdin);

        printf("Dobavi  muskulnigrupi, koito razviva:\n");
        fgets(w->muskulnigrupi, MAX_MUSKULNI_GRUPI+1, stdin);

        printf("Dobavi povtoreniq:\n");
        scanf("%d", &w->povtorenie);
        getchar();

        printf("Dobavi serii:\n");
        scanf("%d", &w->serii);
        getchar();

        printf("Dobavi sredno vreme za izpulnenie:\n");
        scanf("%f", &w->avrg_vreme);
        getchar();

        printf("Dobavi polzite ot tazi trenirovka:\n");
        fgets(w->polzi, MAX_OPISANIE+1, stdin);
    
}

void addstyle (LinkedList * swimming) {
    SwimmingStyle style; 
        printf("Dobavi stila:\n");
        fgets(style.style, MAX_NAME+1, stdin);

        printf("Dobavi opisanie:\n");
        fgets(style.opisanie, MAX_OPISANIE+1, stdin);

        printf("Dobavi polzite ot stila:\n");
        fgets(style.polzi, MAX_OPISANIE+1, stdin);

        for( int i =0; i<MAX_WORKOUT; i++) {
            printf("Trenirovka %d:\n", i+1);
        readworkout(&style.arr[i]);
        }

        pushBack(swimming, &style); 
}

void izvedi_vsichki_stilove (LinkedList * swimming) { 
    printf("Eto spisuk s vsichki zapisani stilove:\n");
    Node *current = swimming->head;
    while(current!=NULL) {
        printf("%s", current->value.style);
        printf("%s", current->value.opisanie);
        printf("%s", current->value.polzi);
        for(int j = 0; j<MAX_WORKOUT; j++) {
            printf("%s", current->value.arr[j].name);    
            printf("%s", current->value.arr[j].opisanie);     
            printf("%s", current->value.arr[j].muskulnigrupi);        
            printf("%d", current->value.arr[j].povtorenie);        
            printf("%d", current->value.arr[j].serii);  
            printf("%f", current->value.arr[j].avrg_vreme);        
            printf("%s", current->value.arr[j].polzi);        
        }

       current = current->next;

    }
}

void premahnistil (LinkedList * swimming) { 
    int nomer;
    printf("Koi ot stilovete iskash da mahnesh:\n"); 
    Node *current = swimming->head;
    while(current!=NULL) {
        printf("%s", current->value.style);
        printf("%s", current->value.opisanie);
        printf("%s", current->value.polzi);
        current=current->next;

    }
    scanf("%d", &nomer);
    if(nomer <= swimming->size) {
    pop(swimming, nomer-1);
    }

}

void zaredi(LinkedList* swimming) {
    FILE *f = fopen("swimming.txt", "r");
    if( f == NULL) {
        printf("Error");
        exit(1);
    }
    char line[200];
    fgets(line, 200, f);
    int broi = atoi(line);
    for (int i = 0; i < broi; i++) {
        SwimmingStyle tempStyle;
        fgets(line, 200, f);
        char* pos = strchr(line, ':');
        char* value = pos + 1;
        strcpy(tempStyle.style, value);
        fgets(line, 200, f);
        pos = strchr(line, ':');
        value = pos + 1;
        strcpy(tempStyle.opisanie, value);
        fgets(line, 200, f);
        pos = strchr(line, ':');
        value = pos + 1;
        strcpy(tempStyle.polzi, value);
        for(int j =0; j<MAX_WORKOUT; j++) {
            fgets(line, 200, f);
            char* pos = strchr(line, ':');
            char* value = pos + 1;
            strcpy(tempStyle.arr[j].name, value);

            fgets(line, 200, f);
            pos = strchr(line, ':');
            value = pos + 1;
            strcpy(tempStyle.arr[j].opisanie, value);

            fgets(line, 200, f);
            pos = strchr(line, ':');
            value = pos + 1;
            strcpy(tempStyle.arr[j].muskulnigrupi, value);

            fgets(line, 200, f);
            pos = strchr(line, ':');
            value = pos + 1;
            tempStyle.arr[j].povtorenie = atoi(value);

            fgets(line, 200, f);
            pos = strchr(line, ':');
            value = pos + 1;
            tempStyle.arr[j].serii = atoi(value);

            fgets(line, 200, f);
            pos = strchr(line, ':');
            value = pos + 1;
            tempStyle.arr[j].avrg_vreme = atof(value);

            fgets(line, 200, f);
            pos = strchr(line, ':');
            value = pos + 1;
            strcpy(tempStyle.arr[j].polzi, value);
        }
        pushBack(swimming, &tempStyle);
    }
    

    fclose(f);
}

void trimnewline(char* str) {
    char* newline = strchr(str, '\n');
    if (newline) *newline = '\0';
}

void zapazi(LinkedList* swimming) {
    FILE *f = fopen("swimming.txt", "w");
    if( f == NULL) {
        printf("Error");
        exit(1);
    }
    fprintf(f, "%d\n", swimming->size);
    Node *current = swimming->head;
    while(current!=NULL) {
        trimnewline(current->value.style);
        fprintf(f,"Stil:%s\n", current->value.style);

        trimnewline(current->value.opisanie);
        fprintf(f,"Opisanie:%s\n",current->value.opisanie);

        trimnewline(current->value.polzi);
        fprintf(f,"Polzi:%s\n", current->value.polzi);

        for(int j=0; j<MAX_WORKOUT;j++) {
            trimnewline(current->value.arr[j].name);
            fprintf(f,"Ime:%s\n", current->value.arr[j].name);

            trimnewline(current->value.arr[j].opisanie);
            fprintf(f,"Opisanie:%s\n", current->value.arr[j].opisanie);

            trimnewline(current->value.arr[j].muskulnigrupi);
            fprintf(f,"Muskulni grupi:%s\n", current->value.arr[j].muskulnigrupi);

            fprintf(f,"Povtorenie:%d\n", current->value.arr[j].povtorenie);

            fprintf(f,"Serii:%d\n", current->value.arr[j].serii);

            fprintf(f,"Sredno vreme:%f\n", current->value.arr[j].avrg_vreme);

            trimnewline(current->value.arr[j].polzi);
            fprintf(f,"Polzi:%s\n", current->value.arr[j].polzi );
        }

        current=current->next;
    }

    fclose(f);
}
