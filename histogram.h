#ifndef HISTOGRAM_H
#define HISTOGRAM_H
#include <stdio.h>
#include <string.h>
typedef struct	s_param
{
	int	verbose;
	int	all;
}		t_param;

void horizontal_histogram(FILE *file, t_param *parameters);
#endif //HISTOGRAM_HISTOGRAM_H
