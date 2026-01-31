#ifndef PLAYER_H
#define PLAYER_H
#include "pokemon.h"
struct Player{
char name[50];
struct Pokemon pokemons[6];
int currentIndex;
};
#endif