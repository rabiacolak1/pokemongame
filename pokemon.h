#ifndef POKEMON_H
#define POKEMON_H
#include "type.h"
#include "move.h"
struct Pokemon{
char name[50];
struct Type types[2];
float maxHP;
float currentHP;
float attack;
float defense;
float spAtk;
float spDef;
float speed;
struct Move *moves[4];//UPDATED
};
#endif