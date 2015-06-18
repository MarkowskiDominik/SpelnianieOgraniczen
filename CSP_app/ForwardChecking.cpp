#include "ForwardChecking.h"

ForwardChecking::ForwardChecking()
{
}

ForwardChecking::ForwardChecking(int hetmanNumber)
{
	this->hetmanNumber = hetmanNumber;
}

ForwardChecking::~ForwardChecking()
{
	if (solution != nullptr) delete solution;
}

void ForwardChecking::start()
{
	solution = new int[hetmanNumber];
	solutions = 0;
	nodes = 0;

	int** scopes = new int*[hetmanNumber];
	for (int i = 0; i < hetmanNumber; i++)
	{
		scopes[i] = new int[hetmanNumber];
		for (int j = 0; j < hetmanNumber; j++)
			scopes[i][j] = 0;
	}

	action(scopes, 0);
}

void ForwardChecking::action(int** scopes, int number)
{
	nodes++;
	for (int i = 0; i < hetmanNumber; i++)
	{
		if (scopes[number][i] == number)
		{
			solution[number] = i;
			if (number < hetmanNumber - 1)
			{
				if (elimination(scopes, number, i))
					action(scopes, number + 1);
			}
			else
				solutions++;
		}
	}
	return;
}

bool ForwardChecking::elimination(int** scopes, int number, int value)
{
	bool empty;
	for (int i = number + 1; i < hetmanNumber; i++)
	{
		empty = true;
		for (int j = 0; j < hetmanNumber; j++)
		{
			if (scopes[i][j] >= number)
			{
				if (value != j && abs(number - i) != abs(value - j))
				{
					scopes[i][j] = number + 1;
					empty = false;
				}
				else
				{
					scopes[i][j] = number;
				}
			}
		}
		if (empty) return false;
	}
	return true;
}

long int ForwardChecking::numberSolutions()
{
	return solutions;
}

long long int ForwardChecking::numberNodes()
{
	return nodes;
}