#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

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

void histrogram(FILE *file, int verbose)
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
		if (verbose || alphabet[i])
		{
			printf("%c:\t", (char) i + 65);
			for (int j = 0; j < alphabet[i]; j++)
				printf("|");
			printf("\n");
		}
	}
	for (int i = 0; i < 10; i++)
	{
		if (verbose || numbers[i])
		{
			printf("%d:\t", i);
			for (int j = 0; j < numbers[i]; j++)
				printf("|");
			printf("\n");
		}
	}
	if (verbose || whitespaces)
	{
		printf("\\W:\t");
		for (int j = 0; j < whitespaces; j++)
			printf("|");
		printf("\n");
	}
	if (verbose || newlines)
	{
		printf("\\n:\t");
		for (int j = 0; j < newlines; j++)
			printf("|");
		printf("\n");
	}
	if (verbose || other)
	{
		printf("\\o:\t");
		for (int j = 0; j < other; j++)
			printf("|");
		printf("\n");
	}


}