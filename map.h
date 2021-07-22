#ifndef MAP_H
#define MAP_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct	s_pair{
	char	*key;
	int		value;

}				t_pair;
typedef struct	s_map{
	int		length;
	t_pair	*pairs;

	/* DON'T TOUCH THIS PLS */
	int 	size;
}				t_map;

#endif //MAP_H
