#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>

using namespace std;

void findIndex(int data[], int n);


int main()
{
	int n;
	int* data;
	scanf("%d", &n);
	data = new int[n]; // ������ ����ŭ�� ���̸� ���� int�� �迭 ����
	for (int i = 0; i < n; i++)
		scanf("%d", &data[i]);
	findIndex(data, n);
	delete[] data;
	return 0;
}

void findIndex(int data[], int n)
{
	double average = 0;
	double* absol = new double[n]; // ������ �����ϱ����� �迭
	int minIdx = 0;
	for (int i = 0; i < n; i++) // ����� ���ϱ����� data�� ���� average�� ������
		average += data[i];
	average = average / n; // ����� ������
	for (int i = 0; i < n;i++)
		absol[i] = abs(average - data[i]); // abs �Լ��� ����ؼ� ������ ��������
	double minAbsol = absol[0]; // ���� �񱳸� ���� minAbsol ������ �ʱ�ȭ
	for (int i = 0; i < n; i++) // �񱳸����� ���ϰ��� �ϴ°��� ����
	{
		if (minAbsol > absol[i])
		{
			minAbsol = absol[i];
			minIdx = i + 1;
		}
	}
	printf("%d %d", minIdx, data[minIdx-1]);
}
