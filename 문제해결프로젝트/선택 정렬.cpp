#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>

using namespace std;

void selectionSort(int data[], int n);


int main()
{
	int n;
	int* data;
	scanf("%d", &n);
	data = new int[n]; // ������ ����ŭ�� ���̸� ���� int�� �迭 ����
	for (int i = 0; i < n; i++)
		scanf("%d", &data[i]);
	selectionSort(data, n);
	for (int i = 0; i < n; i++)
		printf("%d ", data[i]);
	delete[] data;
	return 0;
}

void selectionSort(int data[], int n)
{
	int keep=0;
	int min = 0;
	int idx = 0;
	for (int i = 0; i < n; i++)
	{
		min = data[i];
		for (int j = i; j < n; j++)
			if (min > data[j]) //�ּҰ��� ���ؼ� �ε����� ���������س���
			{
				min = data[j];
				idx = j;
			}
		if (data[i] != min) // 32���� ���ο��� min���� �ʱ�ȭ ���־��µ� ���Ŀ� �������� min���� �ٲ��� �ʴ´ٸ� ���̱� ������ if���� ���
		{                   // ���� ��ȯ
			keep = data[i];
			data[i] = min;
			data[idx] = keep;
		}
	}
}
