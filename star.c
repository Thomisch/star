/*
** EPITECH PROJECT , $YEAR
** B-CPE-100-STG-1-1-star-thomas.decaudain
** File description :
** star
*/

#include <unistd.h>
#include <stdlib.h>

void print_up(unsigned int size)
{
    int bsize = size * 3;
    int bspace = -1;

    if (size == 1)
        write(1, "   *\n", 5);

    else {
        for (int i = 0; i != size; i++) {
            for (int j = 1; j != bsize; j++) {
                write(1, " ", 1);
            }
            write(1, "*", 1);
            if (bspace != -1) {
                for (int k = 0; k != bspace; k++) {
                    write(1, " ", 1);
                }
                write(1, "*", 1);
                write(1, "\n", 1);
            }
            else if (bspace == -1)
                write(1, "\n", 1);
            bsize--;
            bspace = bspace + 2;
        }
    }
}

int calcul_spaces(unsigned int size)
{
    int ssbuff = 1;

    if (size == 1) {
        return (1);
    }
    else {
        for (int i = 0; i != size - 2; i++)
            ssbuff = ssbuff + 2;
    }
    return (ssbuff);
}

void print_line(unsigned int size)
{
    int pfstar = size * 3 - (size - 1);
    int psstar;

    for (int i = 0; i != pfstar; i++)
        write(1, "*", 1);
    for (int j = 0; j != calcul_spaces(size); j++)
        write(1, " ", 1);
    for (int i = 0; i != pfstar; i++)
        write(1, "*", 1);
    write(1, "\n", 1);
}

void print_middle(unsigned int size)
{
    int bspace = 1;
    int buffsz = 0;

    int inter_spaces = size * 6 - 5;

    if (size == 1)
        write(1, " *   *\n", 7);
    else {
        while (buffsz != size) {
            for (int i = 0; i != bspace; i++)
                write(1, " ", 1);
            write(1, "*", 1);
            for (int k = 0; k != inter_spaces; k++)
                write(1, " ", 1);
            write(1, "*\n", 2);
            bspace++;
            buffsz++;
            inter_spaces -= 2;
        }
        inter_spaces += 4;
        while (buffsz != 1) {
            for (int j = buffsz - 1; j != 0; j--) {
                write(1, " ", 1);
            }
            write(1, "*", 1);
            for (int l = 0; l != inter_spaces; l++)
                write(1, " ", 1);
            write(1, "*\n", 2);
            buffsz--;
            inter_spaces += 2;
        }
    }
}

void print_down(unsigned int size)
{
    int ssize = size * 2;
    int ispaces = calcul_spaces(size);

    if (size == 1)
        write(1, "   *\n", 5);
    else {
        for (int l = 0; l != size; l++) {
            for (int i = 0; i != ssize; i++)
                write(1, " ", 1);
            write(1, "*", 1);
            if (l != size - 1) {
                for (int j = 0; j < ispaces; j++)
                    write(1, " ", 1);
                write(1, "*", 1);
                write(1, "\n", 1);
                ssize++;
                ispaces -= 2;
            }
        }
    }
}

void star(unsigned int size)
{
    print_up(size);
    print_line(size);
    print_middle(size);
    print_line(size);
    print_down(size);
}

void main(int argc, char **argv)
{
    star(atoi(argv[1]));
}