#ifndef SWIMMING_H
#define SWIMMING_H

#define MAX_NAME 20
#define MAX_OPISANIE 100
#define MAX_MUSKULNI_GRUPI 50
#define MAX_WORKOUT 3

typedef struct LinkedList LinkedList;

typedef struct { 
    char name[MAX_NAME+1];
    char opisanie[MAX_OPISANIE+1];
    char muskulnigrupi[MAX_MUSKULNI_GRUPI+1];
    int povtorenie;
    int serii;
    float avrg_vreme;
    char polzi[MAX_OPISANIE+1];
}Workout;

typedef struct {
    char style[MAX_NAME+1];
    char opisanie[MAX_OPISANIE+1];
    char polzi[MAX_OPISANIE+1];
    Workout arr[MAX_WORKOUT];
    

}SwimmingStyle;

void addstyle (LinkedList * swimming);
void izvedi_vsichki_stilove (LinkedList * swimming);
void premahnistil (LinkedList * swimming);
void zapazi(LinkedList* swimming);
void zaredi(LinkedList* swimming);
void trimnewline(char* str);


#endif