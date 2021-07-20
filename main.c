#include <stdio.h>

void histrogram(FILE *file, int verbose);

int main() {
	FILE *fp;

	if((fp=fopen("C:\\Users\\kapuc\\CLionProjects\\histogram\\text", "r"))==NULL) {
		printf ("Cannot open file.\n");
	}
	histrogram(fp, 0);
}
