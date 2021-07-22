
#include "histogram.h"

int set(int *a)
{
	int *b;
	*a = b;
}

void init_params(t_param *params, int argc, char **argv)
{
	params->all = 0;
	params->verbose = 0;
	for (int i = 1; i < argc; ++i)
	{
		argv++;
		if (strcmp(*argv, "--all") == 0 || strcmp(*argv, "-a") == 0)
			params->all = 1;
		if (strcmp(*argv, "--verbose") == 0 || strcmp(*argv, "-v") == 0)
			params->verbose = 1;
	}
}

int main(int argc, char **argv) {
//	FILE *fp;
//
//	t_param parameters;
//	init_params(&parameters, argc, argv);
//
//
//
//	if((fp=fopen("C:\\Users\\kapuc\\CLionProjects\\histogram\\text", "r"))==NULL) {
//		printf ("Cannot open file.\n");
//	}
	//horizontal_histogram(fp, &parameters);

}
