#include <stdio.h>

struct coaching {
    int fees;
    int skills[4];
    int (*fun_ptr)(void);
};

struct coaching majestine;
struct coaching *players;

int function_a (void) {
    printf ("Printing from function A \n\r");
    return 2;
}

int main(void) {

    majestine.fees = 3000;
    majestine.skills[2] = 2;
    majestine.fun_ptr = function_a;

    printf ("Printing Variable 1 = %d \n\r", majestine.fees);
    printf ("Printing Variable 2 = %d \n\r", majestine.skills[2]);
    printf ("Printing Variable 2.5 = %x \n\r", function_a());
    printf ("Printing Variable 3 = %d \n\r", (majestine.fun_ptr)() );
    printf ("Printing size = %d \n\r", sizeof(majestine));
    printf ("Struct address = %x \n\r\n\r", &(majestine));

    players = &majestine;

    printf ("Struct Variable 2 = %x \n\r", players);
    printf ("Struct Variable 1 = %d \n\r", players->skills[2]);
    printf ("Printing Variable 3 = %d \n\r", (players->fun_ptr)() );
    printf ("Printing size = %d \n\r", sizeof(players));
    printf ("Struct address = %x \n\r", &players);

    return 0;
}