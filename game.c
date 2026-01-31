#include <stdio.h>
#include "functions.h"
#include <string.h>
#include <stdlib.h>
void game(struct Player *P1, struct Player *P2){
    /*float totalHP1=0;
    float totalHP2=0;*/

    /*totalHP1 +=P1->pokemons[i].currentHP;
    totalHP2 +=P2->pokemons[i].currentHP;*/

    int control1;
    int control2;
    do{
        gameround(P1,P2);
        control1 = 0;
        control2 = 0;
        for (int i = 0; i < 6; i++)
        {
            if (P1->pokemons[i].currentHP > 0)
            {
                control1 = 1;
            }
            if (P2->pokemons[i].currentHP > 0)
            {
                control2 = 1;
            }
        }
    } while (control1 && control2);
    if(control1==0 && control2==1){
     printf("Winner is:%s\n",P2->name);
    }
    else if(control2==0 && control1==1){
    printf("Winner is:%s\n",P1->name);
    }
    else {
    printf("The game is over in a draw");
    }
}

void gameround(struct Player *P1, struct Player *P2){
 int choice1,choice2;
 printf("Player1 pokemons:\n");
     for(int i=0; i<6; i++){
        if(P1->pokemons[i].currentHP>0){
         if(i%2==0){
            printf("\n");
         }
        printf("%d - %s\t",i,P1->pokemons[i].name);
        }
    }
printf("\n\nFor Player1:\n1- Attack \n2- Change Pokemon\n");
scanf("%d",&choice1);
while(choice1!=1 && choice1!=2){
printf("please enter correct number of the menu\n");
scanf("%d",&choice1);
}

printf("\nPlayer2 pokemons:\n");
  for(int i=0; i<6; i++){
        if(P2->pokemons[i].currentHP>0){
         if(i%2==0){
            printf("\n");
         }
        printf("%d - %s\t",i,P2->pokemons[i].name);
        }
    }
printf("\n\nFor Player2:\n1- Attack \n2- Change Pokemon\n");
scanf("%d",&choice2);
while(choice2!=1 && choice2!=2){
printf("please enter correct number of the menu\n");
scanf("%d",&choice2);
}
int p1Move=0;
if(choice1==1){
    printf("First player select number of move:\n");
    for(int i=0; i<4; i++){
        if(P1->pokemons[P1->currentIndex].currentHP>0){
            if(i%2==0){
            printf("\n");
         }
        printf("%d - %s\t ",i,P1->pokemons[P1->currentIndex].moves[i]->name);
        }
    }
    printf("\n");
    scanf("%d",&p1Move);
while(!(p1Move<4&&p1Move>=0)){
printf("please enter correct number of the menu\n");
scanf("%d",&p1Move);
}
}
int p1Pokemon=P1->currentIndex;
if(choice1==2){
    printf("First player choose number of pokemon:\n");
    for(int i=0; i<6; i++){
        if(P1->pokemons[i].currentHP>0){
         if(i%2==0){
            printf("\n");
         }
        printf("%d - %s\t",i,P1->pokemons[i].name);
        }
    }
    printf("\n");
    scanf("%d",&p1Pokemon);
while(!(p1Pokemon<6 && p1Pokemon>=0)||P1->pokemons[p1Pokemon].currentHP==0){
printf("please enter correct number of the menu\n");
scanf("%d",&p1Pokemon);
}
    P1->currentIndex=p1Pokemon;
}
int p2Move=0;
if(choice2==1){
    printf("Second player select number of move:\n");
    for(int i=0; i<4; i++){
        if(P2->pokemons[P2->currentIndex].currentHP>0){
         if(i%2==0){
            printf("\n");
         }
        printf("%d - %s\t ",i,P2->pokemons[P2->currentIndex].moves[i]->name);
        }
    }
    printf("\n");
    scanf("%d",&p2Move);
while(!(p2Move<4&&p2Move>=0)){
printf("please enter correct number of the menu\n");
scanf("%d",&p2Move);
}
}
int p2Pokemon=P2->currentIndex;
if(choice2==2){
    printf("Second player choose number of pokemon:\n");
    for(int i=0; i<6; i++){
        if(P2->pokemons[i].currentHP>0){
         if(i%2==0){
            printf("\n");
         }
        printf("%d - %s\t",i,P2->pokemons[i].name);
        }
    }
    printf("\n");
scanf("%d",&p2Pokemon);
while(!(p2Pokemon<6 && p2Pokemon>=0)|| P2->pokemons[p2Pokemon].currentHP==0){
printf("please enter correct number of the menu\n");
scanf("%d",&p2Pokemon);
}
    P2->currentIndex=p2Pokemon;
}
struct Move *move1=P1->pokemons[P1->currentIndex].moves[p1Move];
struct Move *move2=P2->pokemons[P2->currentIndex].moves[p2Move];
if(choice1==1&&choice2==1){
   if(P1->pokemons[p1Pokemon].speed > P2->pokemons[p2Pokemon].speed){
    applyDamage(P1,P2,move1);
    if(P2->pokemons[p2Pokemon].currentHP>0){/*'p2Pokemon' hide the player2 round pokemon it helps us to before the update of currentpokemon so 
                                            we can control the attacking right situation for defender player2.*/
    applyDamage(P2,P1,move2);
    }
   }
   else if(P2->pokemons[p2Pokemon].speed > P1->pokemons[p1Pokemon].speed){
    applyDamage(P2,P1,move2);
    if(P1->pokemons[p1Pokemon].currentHP>0){
    applyDamage(P1,P2,move1);
    }
   }
   else if(P2->pokemons[p2Pokemon].speed==P1->pokemons[p1Pokemon].speed){
    printf("speeds are equal, random attaker pokemon deciding");
    int random=rand()%2;
    if(random==0){
    applyDamage(P1,P2,move1);
    }
    else if(random==1){
    applyDamage(P2,P1,move2);
    }
   }
} 
   else if(choice1==2&&choice2==1){
    applyDamage(P2,P1,move2);
  }
  else if(choice1==1&&choice2==2){
    applyDamage(P1,P2,move1);
  }
  else if(choice1==2&&choice2==2){
   return;
  }
}
void applyDamage(struct Player *Attacker,struct Player *Defenser,struct Move *attackerMove ){
    struct Type types[18];
    float damage=0.0;
    float typeEffect1=1.0;
    float typeEffect2=1.0;
    float STAB=1.0;

     for(int i=0; i<18; i++){
        if(strcmp(types[i].name,attackerMove->type.name)==0){
            for(int j=0; j<18; j++){
               if(strcmp(types[i].effects[j].defNAme,Defenser->pokemons[Defenser->currentIndex].types[0].name)==0){
                typeEffect1=types[i].effects[j].multiplier;
               }
               if(strcmp(types[i].effects[j].defNAme,Defenser->pokemons[Defenser->currentIndex].types[1].name)==0){
                typeEffect2=types[i].effects[j].multiplier;
               }
               else if(strcmp("None",Defenser->pokemons[Defenser->currentIndex].types[1].name)==0){
                typeEffect2=1;
               }

            }
            break;
        }
    }
for(int i =0; i<2; i++){
    if(strcmp(attackerMove->type.name,Attacker->pokemons[Attacker->currentIndex].types[i].name)==0){
        STAB=1.5;
    }
}
if(attackerMove->category==1){
damage=attackerMove->power * ((float)Attacker->pokemons[Attacker->currentIndex].attack / (float)Defenser->pokemons[Defenser->currentIndex].defense)*typeEffect1*typeEffect2*STAB;
}
if(attackerMove->category==0){
damage=attackerMove->power * ((float)Attacker->pokemons[Attacker->currentIndex].spAtk / (float)Defenser->pokemons[Defenser->currentIndex].spDef)*typeEffect1*typeEffect2*STAB;
}
Defenser->pokemons[Defenser->currentIndex].currentHP -= damage;
if(Defenser->pokemons[Defenser->currentIndex].currentHP<0){
    Defenser->pokemons[Defenser->currentIndex].currentHP=0;
}
printf("---Round infomations---\n\n");
printf("%s is attacked %f damage to %s\n\n",Attacker->pokemons[Attacker->currentIndex].name,damage,Defenser->pokemons[Defenser->currentIndex].name);
printf("%s is current HP : %.1f \n\n",Defenser->pokemons[Defenser->currentIndex].name,Defenser->pokemons[Defenser->currentIndex].currentHP);

if(Defenser->pokemons[Defenser->currentIndex].currentHP==0){
 printf("%s your pokemon died: %s \n\n ",Defenser->name,Defenser->pokemons[Defenser->currentIndex].name);

   int start= Defenser->currentIndex;
   do{
      Defenser->currentIndex++;
    if(Defenser->currentIndex==6){
        Defenser->currentIndex=0;
    }
    if(Defenser->currentIndex==start){
       break; 
    }
}while(Defenser->pokemons[Defenser->currentIndex].currentHP==0);
}
   
}       





