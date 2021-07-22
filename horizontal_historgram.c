#include <stdio.h>
#include <stdlib.h>
#include "histogram.h"

int maxi(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

static int max_array(const int *array, int length)
{
	int result;

	result = 0;
	for (int i = 0; i < length; i++)
		result = maxi(result, array[i]);
	return (result);
}

void horizontal_histogram(FILE *file, t_param *parameters)
{
	int *alphabet;
	int *numbers;
	int whitespaces;
	int newlines;
	int other;
	int c;

	alphabet = calloc(26, 4);
	numbers = calloc(10, 4);
	whitespaces = 0;
	newlines = 0;
	other = 0;
	while ((c = getc(file)) != EOF)
	{
		if (c >= '0' && c <= '9')
			++numbers[c - '0'];
		else if (c >= 'A' && c <= 'Z')
			++alphabet[c - 'A'];
		else if (c >= 'a' && c <= 'z')
			++alphabet[c - 'a'];
		else if (c == ' ')
			++whitespaces;
		else if (c == '\n')
			++newlines;
		else
			++other;
	}

	int max;

	max = 0;
	max = maxi(whitespaces, newlines);
	max = maxi(max, other);
	max = maxi(max, max_array(alphabet, 26));
	max = maxi(max, max_array(numbers, 10));

	for (int i = 0; i < 26; i++)
	{
		if (parameters->all || alphabet[i])
		{
			printf("%c:\t", (char) i + 65);
			for (int j = 0; j < ((float)alphabet[i] / max) * 100; j++)
				printf("|");
			if (parameters->verbose && alphabet[i] != 0)
				printf(" %i", alphabet[i]);
			printf("\n");
		}
	}
	for (int i = 0; i < 10; i++)
	{
		if (parameters->all || numbers[i])
		{
			printf("%d:\t", i);
			for (int j = 0; j < (float)(numbers[i] / max) * 100; j++)
				printf("|");
			if (parameters->verbose && numbers[i] != 0)
				printf(" %i", numbers[i]);
			printf("\n");
		}
	}
	if (parameters->all || whitespaces)
	{
		printf("\\W:\t");
		for (int j = 0; j < ((float)whitespaces / max) * 100; j++)
			printf("|");
		if (parameters->verbose && whitespaces != 0)
			printf(" %i", whitespaces);
		printf("\n");
	}
	if (parameters->all || newlines)
	{
		printf("\\n:\t");
		for (int j = 0; j < ((float)newlines / max) * 100; j++)
			printf("|");
		if (parameters->verbose && newlines != 0)
			printf(" %i", newlines);
		printf("\n");
	}
	if (parameters->all || other)
	{
		printf("\\o:\t");
		for (int j = 0; j < ((float)other / max) * 100; j++)
			printf("|");
		if (parameters->verbose && other != 0)
			printf(" %i", other);
		printf("\n");
	}

}