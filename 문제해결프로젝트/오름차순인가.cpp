#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>

using namespace std;
void isOrdered(int n, int data[]);

int main()
{
	int n; // �л����� ��Ÿ���� ���� n
	int* data; // �л����� Ű�� ��Ÿ���� �л�����ŭ�� ���̸� ���� �迭 data
	scanf("%d", &n); // �л����� �Է¹���
	data = new int[n]; // �л�����ŭ�� ���̸� ���� �迭 ����
	for (int i = 0; i < n; i++) // �迭�� Ű�� �Է¹���
		scanf("%d", &data[i]);
	isOrdered(n, data); // ������������ �ƴ��� �Ǵ��ϴ� �Լ� ���
	delete[] data; // data �迭 �޸𸮿��� ����
	return 0;
}

void isOrdered(int n, int data[])
{
	bool check = true; // �������������� �Ǻ��ϱ� ���� ����
	for (int i = 0; i < n - 1; i++)
	{
		if (data[i] > data[i + 1])
		{
			printf("NO"); // ���������� �ƴ϶�� NO�� ���
			check = false; // ���������� �ƴϹǷ� check�� false���� ����
		}
	}
	if (check)
		printf("YES"); // ���������� ��쿡�� YES �� ���
}
