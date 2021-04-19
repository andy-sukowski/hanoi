/* See LICENSE file for copyright and license details. */

#include <stdio.h>
#include <stdlib.h>

/* move n-th disk from `from` to `to` */
void move(long n, char from, char to, char via)
{
	if (n > 0) {
		move(n - 1, from, via, to);
		printf("%ld: %c → %c\n", n, from, to);
		move(n - 1, via, to, from);
	}
}

int main(void)
{
	/* scan for string */
	fputs("Number of disks: ", stdout);
	char input[10];
	fgets(input, sizeof input, stdin);

	/* convert string to long */
	char *rest;
	long n = strtol(input, &rest, 10);
	if (rest == input || *rest != '\n' || n < 1) {
		fputs("Error: invalid input\n", stderr);
		return EXIT_FAILURE;
	}

	move(n, 'a', 'c', 'b');
	return EXIT_SUCCESS;
}
