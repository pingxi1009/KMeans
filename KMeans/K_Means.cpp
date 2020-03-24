#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <vector>

using namespace std;
typedef struct
{
	double x;
	double y;
}M_POINT;

M_POINT g_orin[5] = {{10, 0},{ 21, 1 },{ 42, 2 },{ 73, 3 },{ 104, 4 }};

double GetDistance(M_POINT p1, M_POINT p2)
{
	return pow(abs(p1.x - p2.x), 2) + pow(abs(p1.y - p2.y), 2);
}

void CalculateMainPoint(vector<M_POINT> grop1, vector<M_POINT> grop2, vector<M_POINT> grop3, vector<M_POINT> grop4, vector<M_POINT> grop5, M_POINT *p)
{
	
}

double FindMinNum(double *temp, int len)
{
	double mintemp = temp[0];
	for (int i = 0 ; i<len ; i++)
	{
		if (mintemp > temp[i])
			mintemp = temp[i];
	}
	return mintemp;
}

int main()
{
	cout << "hello world" << endl;

	M_POINT arr[100] = { 0, };
	srand((int)time(0));
	for (int i = 0; i < 100; i++)
	{
		if (i < 20)
			arr[i].y = rand() % 20 + 40;
		else if (i < 40)
			arr[i].y = rand() % 20;
		else if (i < 60)
			arr[i].y = rand() % 20 + 60;
		else if (i < 80)
			arr[i].y = rand() % 20 + 100;
		else
			arr[i].y = rand() % 20 + 80;
		arr[i].x = i;
		//cout << arr[i] << endl;
	}

	vector<M_POINT> grop1, grop2, grop3, grop4, grop5;
	double distance[5] = { 0, };
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0 ; j < 5 ; j++)
		{
			distance[j] = GetDistance(g_orin[j], arr[i]);
		}
		double  minDistance = FindMinNum(distance, 5);
		int vecNum;
		for (int j = 0; j < 5; j++)
		{
			if (minDistance == distance[j])
				vecNum = j;
		}
		switch (vecNum)
		{
		case 0:
			grop1.push_back(arr[i]);
			break;
		case 1:
			grop2.push_back(arr[i]);
			break;
		case 2:
			grop3.push_back(arr[i]);
			break;
		case 3:
			grop4.push_back(arr[i]);
			break;
		case 4:
			grop5.push_back(arr[i]);
			break;
		default:
			break;
		}	
	}

	cout << "grop1 size = " << grop1.size() << endl;
	cout << "grop2 size = " << grop2.size() << endl;
	cout << "grop3 size = " << grop3.size() << endl;
	cout << "grop4 size = " << grop4.size() << endl;
	cout << "grop5 size = " << grop5.size() << endl;

	M_POINT p_sum[5] = { 0, };
	for (vector<M_POINT>::iterator iter = grop1.begin() ; iter != grop1.end() ; iter++)
	{
		p_sum[0].x += iter->x;
		p_sum[0].y += iter->y;
	}
	g_orin[0].x = p_sum->x / grop1.size();
	g_orin[0].y = p_sum->y / grop1.size();

	cout << g_orin[0].x << endl;
	cout << g_orin[0].y << endl;


	return 0;
}


// 2020/3/25完成一次迭代，还需封装迭代函数，完成多次迭代