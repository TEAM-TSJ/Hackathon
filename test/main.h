
#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_data{
	int data00;
	int data01;
}				t_data;

typedef struct s_func{
	int func1;
	int func2;
}				t_func;

typedef struct s_info{
	t_data data;
	t_func func;
}				t_info;

#endif
