#include <cstdlib>
#include <iostream>
#include <ctime>

#include "Backtracking.h"
#include "ForwardChecking.h"

using namespace std;

int main()
{
	int sizeBoard;
	cin >> sizeBoard;
	Backtracking back(sizeBoard);
	ForwardChecking forward(sizeBoard);
	clock_t start = clock();
	system("PAUSE");

	start = clock();
	back.start();
	printf("Czas wykonywania: %lu ms\n", clock() - start);
	cout << back.numberSolutions() << "\t" << back.numberNodes() << endl;

	start = clock();
	forward.start();
	printf("Czas wykonywania: %lu ms\n", clock() - start);
	cout << forward.numberSolutions() << "\t" << forward.numberNodes() << endl;

	system("PAUSE");
	return 0;
}