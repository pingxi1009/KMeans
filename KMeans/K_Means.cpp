#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <vector>

using namespace std;

int main()
{
	cout << "hello world" << endl;

	double arr[100] = { 0, };
	srand((int)time(0));
	for (int i = 0; i < 100; i++)
	{
		if (i < 20)
			arr[i] = rand() % 20 + 40;
		else if (i < 40)
			arr[i] = rand() % 20;
		else if (i < 60)
			arr[i] = rand() % 20 + 60;
		else if (i < 80)
			arr[i] = rand() % 20 + 100;
		else
			arr[i] = rand() % 20 + 80;
		cout << arr[i] << endl;
	}

	vector<double> grop1, grop2, grop3, grop4, grop5;
	double temp1, temp2, mintemp = 0;
	for (int i = 0; i < 100; i++)
	{
		mintemp = pow(i, 2) + pow(abs(arr[i] - arr[0]), 2);
		if (mintemp > pow(abs(i - 20), 2) + pow(abs(arr[i] - arr[20]), 2))
		{
			mintemp = pow(abs(i - 20), 2) + pow(abs(arr[i] - arr[20]), 2);
		}
	}

	return 0;
}