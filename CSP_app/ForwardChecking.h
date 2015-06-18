#pragma once
#include <iostream>

using namespace std;

class ForwardChecking
{
	int hetmanNumber;
	int* solution;
	long int solutions;
	long long int nodes;

	void action(int** scopes, int number);
	bool elimination(int** scopes, int number, int value);

public:
	ForwardChecking();
	ForwardChecking(int hetmanNumber);
	~ForwardChecking();

	void start();
	long int numberSolutions();
	long long int numberNodes();
};