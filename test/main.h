#ifndef MAIN_H
# define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

# define ERROR 1
# define ENCODE 2
# define DECODE 3
# define FORMAT 4
# define OPTION 5
# define ARGUMENT 6

int huffman_encode(int ac, char **av);
int huffman_decode(int ac, char **av);

#endif