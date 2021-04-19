/* See LICENSE file for copyright and license details. */

#include <iostream>

/* move n-th disk from `from` to `to` */
void move(long n, char from, char to, char via)
{
	if (n > 0) {
		move(n - 1, from, via, to);
		std::cout << n << ": " << from << " → " << to << '\n';
		move(n - 1, via, to, from);
	}
}

int main(void)
{
	long n;
	std::cout << "Number of disks: ";
	std::cin >> n;
	if (std::cin.fail() || n < 1) {
		std::cerr << "Error: invalid input\n";
		return EXIT_FAILURE;
	}

	move(n, 'a', 'c', 'b');
	return EXIT_SUCCESS;
}
