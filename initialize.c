#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "functions.h"
#include <time.h>
void initialize(struct Type type[], struct Move move[], struct Pokemon pokemons[],
                struct Player *player1, struct Player *player2){
    srand(time(NULL));
    initializeTypes(type);
    initializeMoves(move);
    initializePokemons(pokemons, move);
    strcpy(player1->name, "Player1");
    strcpy(player2->name, "Player2");
    int player1indices[6];
    int player2indices[6];
    for (int i = 0; i < 6; i++){
        int duplicate;
        int index;
        do{
            duplicate = 0;
            index = rand() % 1015;
            for (int j = 0; j < i; j++){
                if (player1indices[j] == index){
                    duplicate = 1;
                    break;
                }
            }

        } while (duplicate);
        player1indices[i] = index;
        player1->pokemons[i] = pokemons[index];
    }
    for (int i = 0; i < 6; i++){
        int duplicate;
        int index;
        do{
            duplicate = 0;
            index = rand() % 1015;
            for (int j = 0; j < i; j++){
                if (player2indices[j] == index){
                    duplicate = 1;
                    break;
                }
            }
            for (int j = 0; j < 6; j++){
                if (player1indices[j] == index){
                    duplicate = 1;
                    break;
                }
            }
        } while (duplicate);
        player2indices[i] = index;
        player2->pokemons[i] = pokemons[index];
    }
    player1->currentIndex = 0;
    player2->currentIndex = 0;
    game(player1,player2);

}

void initializeTypes(struct Type type[]){
    FILE *fptr;
    fptr = fopen("types.txt", "r");
    if (fptr == NULL){
        printf("types file doesn't open\n");
        return;
    }
    for (int i = 0; i < 18; i++){
        fscanf(fptr, "%s",type[i].name);
        for (int j = 0; j < 18; j++)
        {
            fscanf(fptr, "%s %f", type[i].effects[j].defNAme,&type[i].effects[j].multiplier);
            strcpy(type[i].effects[j].atkName, type[i].name);
        }
    }
    fclose(fptr);
}

void initializeMoves(struct Move move[]){
    FILE *fp;
    fp = fopen("moves.txt", "r");
    if (fp == NULL){
        printf("moves cannot open\n");
        return;
    }
    char category[50];
    for (int i = 0; i < 486; i++){
        fscanf(fp, "%s %s %s %f", move[i].name, move[i].type.name, category, &move[i].power);
        if (strcmp(category, "special") == 0){
            move[i].category = specialAttack;
        }
        else if (strcmp(category, "physical") == 0){
            move[i].category = physicalAttack;
        }
    }
    fclose(fp);
}

void initializePokemons(struct Pokemon pokemons[], struct Move moves[]){
    FILE *fp;
    fp = fopen("pokemon.txt", "r");
    if (fp == NULL){
        printf("pokemon file connot open\n");
        return;
    }
    int pokemonMoves[4];
    for (int i = 0; i < 1015; i++){
        fscanf(fp, "%s %s %s %f %f %f %f %f %f", pokemons[i].name, pokemons[i].types[0].name, pokemons[i].types[1].name,
               &pokemons[i].maxHP, &pokemons[i].attack, &pokemons[i].defense, &pokemons[i].spAtk, &pokemons[i].spDef, &pokemons[i].speed);
        if (strcmp(pokemons[i].types[1].name, "-") == 0){
            strcpy(pokemons[i].types[1].name, "None");
           /* for (int j = 0; j < 18; j++){
                pokemons[i].types[1].effects[j].multiplier = 1;
            }*/
        }
        pokemons[i].currentHP = pokemons[i].maxHP;

        for (int a = 0; a < 4; a++){
            int duplicate;
            int index;
            do{
                duplicate = 0;
                index = rand() % 486;
                for (int j = 0; j < a; j++){
                    if (pokemonMoves[j] == index){
                        duplicate = 1;
                        break;
                    }
                }
            } while (duplicate);
            pokemonMoves[a] = index;
            pokemons[i].moves[a] = &moves[index];
        }
    }
}
