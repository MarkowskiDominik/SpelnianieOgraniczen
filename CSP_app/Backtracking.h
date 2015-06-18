#pragma once
#include <iostream>

using namespace std;

class Backtracking
{
	int hetmanNumber;
	int* solution;
	long int solutions;
	long long int nodes;

	void action(int number);
	bool check(int x, int y);

public:
	Backtracking();
	Backtracking(int hetmanNumber);
	~Backtracking();

	void start();
	long int numberSolutions();
	long long int numberNodes();
};