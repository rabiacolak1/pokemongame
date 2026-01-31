#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "player.h"
#include "pokemon.h"
#include "move.h"
#include "type.h"
void initialize(struct Type type[], struct Move move[], struct Pokemon pokemons[],
                struct Player *player1, struct Player *player2);
void initializeTypes(struct Type type[]);
void initializeMoves(struct Move move[]);
void initializePokemons(struct Pokemon pokemons[], struct Move moves[]);
void game(struct Player *P1, struct Player *P2); 
void gameround(struct Player *P1, struct Player *P2);
void applyDamage(struct Player *Attacker,struct Player *Defenser,struct Move *attackerMove );
#endif               