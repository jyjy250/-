#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>

void findIndex(int data[], int n, int m);


int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int* data = new int[n];
	data = new int[n]; //n���̸�ŭ�� �迭�� ����
	for (int i = 0; i < n; i++) // �迭�� ä������
		scanf("%d", &data[i]);
	findIndex(data, n, m);
	delete[] data;
	return 0;
}

void findIndex(int data[], int n ,int m)
{
	for (int i = 0; i < n; i++)
	{
		if (data[i] == m)// ã�� �����͸� �߰��ϸ� �ε����� ���
		{
			printf("%d", i);
			break;
		}
		if (i == n - 1) // �迭������ ã�ƺ������� ���ٸ� -1 ���
			printf("-1");
	}
}
