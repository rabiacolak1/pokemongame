#ifndef MOVE_H
#define MOVE_H
#include "type.h"
enum Category{
specialAttack,
physicalAttack
};
struct Move{
char name[50];
struct Type type;
enum Category category;
float power;
};
#endif
