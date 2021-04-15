#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<time.h>
#include<cmath>

using namespace std;

class Point2D // �������� ������ �Է¹��� Point2D Ŭ����
{
private:
	int x; // ���� x��ǥ�� ������ ���� x
	int y; // ���� y��ǥ�� ������ ���� y

public:
	Point2D(int x = 0, int y = 0) // x��ǥ�� y��ǥ�� �ʱ�ȭ �ϴ� ������
	{
		this->x = x;
		this->y = y;
	}
	double getDistance(Point2D target) // �� this�� �� traget ������ �Ÿ��� return �ϴ� �Լ� 
	{

		return sqrt(pow(x - target.getX(), 2) + pow(y - target.getY(), 2));
	}

	int getX() // x �� private �̹Ƿ�
	{
		return x;
	}
	int getY() //y �� private �̹Ƿ�
	{
		return y;
	}
};

int main()
{
	int n; // õü���� �Է¹��� ���� n
	Point2D* points; // õü���� ��ǥ������ ������ �迭 points
	double** distance; // õü�鰣�� �Ÿ������� ������ 2���� �迭 distance
	scanf("%d", &n); //õü���� �Է�
	points = new Point2D[n]; // �Է¹��� õü�� ����ŭ�� ���̸� ���� Point2D �迭 ����
	distance = new double* [n]; // n X n ũ���� 2���� �迭 ����
	for (int i = 0; i < n; i++)
		distance[i] = new double[n];
	for (int i = 0; i < n; i++) // õü���� ��ǥ ������ �Է�
	{
		int x, y;
		scanf("%d %d", &x, &y);
		points[i]= Point2D(x, y);
	}
	double minDistance = points[0].getDistance(points[1]); // ���� ����� �Ÿ��� ������ ���� minDistance�� �ʱ�ȭ
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			distance[i][j] = points[i].getDistance(points[j]); 
			if (distance[i][j] != 0) // distance[n][m]���� n-1��° õü�� m-1��° õü�� �Ÿ��� ����ȴ� �׷��Ƿ�  distance[n][n]�� ������ 0 �̹Ƿ� 0 �� �ƴҰ�쿡�� minDistance���� �����ϱ�� �Ѵ�
				if (minDistance > distance[i][j])
					minDistance = distance[i][j];
		}
	}
	int count = 0; // �����Ÿ��� ��츦 �����ϱ� ���� ���� count
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (minDistance == distance[i][j])
				count++;
		}
	}
	printf("%.1f\n", minDistance);
	printf("%d\n", count/2); // distance[n][m]�� distance[m][n] ���� �Ÿ��̹Ƿ� count ������ �ߺ����� ���������Ͽ��� �׷��Ƿ� 2�� �����ش�
	delete[] points;
	delete[] distance;
	return0;
}
