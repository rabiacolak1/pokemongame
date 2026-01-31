#ifndef TYPE_H
#define TYPE_H
struct TypeEffect{
char atkName[50];
char defNAme[50];
float multiplier;
};
struct Type{
char name[50];
struct TypeEffect effects[18];
};
extern struct Type types[18];
#endif