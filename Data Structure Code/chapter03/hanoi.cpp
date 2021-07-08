#include "hanoi.h"

void move(char A, int n, char C)
{
	std::cout << ++m << "," << n << "," << A << "," << C << std::endl;
}

void Hanoi(int n, char A, char B, char C)
{
	if (n == 1)
	{
		move(A, 1, C);
	}
	else
	{
		Hanoi(n - 1, A, C, B);
		move(A, n, C);
		Hanoi(n - 1, B, A, C);
	}
}
