#include "Backtracking.h"

Backtracking::Backtracking()
{
}

Backtracking::Backtracking(int hetmanNumber)
{
	this->hetmanNumber = hetmanNumber;
}

Backtracking::~Backtracking()
{
	if (solution != nullptr) delete solution;
}

void Backtracking::start()
{
	solution = new int[hetmanNumber];
	solutions = 0;
	nodes = 0;
	action(0);
}

void Backtracking::action(int number)
{
	nodes++;
	for (int i = 0; i < hetmanNumber; i++)
	{
		if (check(number, i))
		{
			solution[number] = i;
			if (number < hetmanNumber - 1)
				(action(number + 1));
			else
				solutions++;
		}
	}
	return;
}

bool Backtracking::check(int x, int y)
{
	for (int i = 0; i < x; i++)
		if (solution[i] == y || abs(i - x) == abs(solution[i] - y)) return false;
	return true;
}

long int Backtracking::numberSolutions()
{
	return solutions;
}

long long int Backtracking::numberNodes()
{
	return nodes;
}