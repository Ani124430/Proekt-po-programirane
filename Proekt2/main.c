#include <stdio.h>
#include<stdlib.h> 
#include"dynArr.h"
#include"swimming.h"

int main() {
    int choice; 
    DynamicArray swimming = init(10);
    do {
        printf("---MENU---\n");
        printf("1.Dobavi nov stil\n");
        printf("2.Izvedi cqlta informaciq\n");
        printf("3.Premahni stil\n");
        printf("4.Zaredi faila\n");
        printf("5.Zapazi faila\n");
        printf("6.Izhod\n");
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1:
            addstyle(&swimming);
                break;
            case 2:
            izvedi_vsichki_stilove(&swimming);
                break;
            case 3:
            premahnistil(&swimming);
                break;
            case 4:
            zaredi(&swimming);
                break;
            case 5:
            zapazi(&swimming);
                break;
            case 6:
                break; 
            default: 
                printf("Izberi ot posochenite opcii\n");

        } 
     } while(choice != 6);


    free(swimming.buffer);
    return 0; 
}