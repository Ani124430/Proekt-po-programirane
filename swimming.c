#include <stdio.h>
#include<stdlib.h> 
#include"dynArr.h"

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

    
}

void addstyle (DynamicArray * swimming) {
    SwimmingStyle style; 
    if (swimming->size<swimming->capacity) {
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
    
    
}

void izvedi_vsichki_stilove (DynamicArray * swimming) { 
    printf("Eto spisuk s vsichki zapisani stilove:\n");
    for(int i=0; i<swimming->size; i++) {
        printf("%s\n %s\n %s \n", swimming->buffer[i].style, swimming->buffer[i].opisanie,swimming->buffer[i].polzi);
        for(int j=0; j<MAX_WORKOUT;j++) {
            printf("Ime:%s\n", swimming->buffer[i].arr[j].name);
            printf("Opisanie:%s\n", swimming->buffer[i].arr[j].opisanie);
            printf("Muskulni grupi:%s\n", swimming->buffer[i].arr[j].muskulnigrupi);
            printf("Povtorenie:%d\n", swimming->buffer[i].arr[j].povtorenie);
            printf("Serii:%d\n", swimming->buffer[i].arr[j].serii);
            printf("Sredno vreme:%f\n", swimming->buffer[i].arr[j].avrg_vreme);
            printf("Polzi:%s\n", swimming->buffer[i].arr[j].polzi);
        }
    }
}

void premahnistil (DynamicArray * swimming) { 
    int nomer;
    printf("Koi ot stilovete iskash da mahnesh:\n"); 
    for(int i=0; i<swimming->size; i++) {
        printf("%s %s %s \n", swimming->buffer[i].style, swimming->buffer[i].opisanie,swimming->buffer[i].polzi);
    }
    scanf("%d", &nomer);
    if(nomer <= swimming->size) {
    pop(swimming, nomer-1);
    }

}

