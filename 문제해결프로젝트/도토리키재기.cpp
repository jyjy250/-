#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>

using namespace std;
void getMaximumHeight(int height[], int month[], int n, int m);

int main()
{
	int n, m; //���丮�� ���� ��Ÿ���� ���� n, ���� ���� �Է¹޴� ���� m
	int* height; // i��° ���丮�� Ű�� ��Ÿ���� ���� �迭 height
	int* month; // i��° ���丮�� ������ ��Ÿ���� ���� �迭 month
	scanf("%d", &n); //���丮�� ���� �Է¹���
	height = new int[n]; //���丮�� ����ŭ�� ���̸� ������ �迭�� ����
	month = new int[n]; //���丮�� ����ŭ�� ���̸� ������ �迭�� ����
	for (int i = 0; i < n; i++)//i���� ���丮�� Ű�� �Է¹���
		scanf("%d", &height[i]);
	for (int i = 0; i < n; i++)//i���� ���丮�� ������ �Է¹���
		scanf("%d", &month[i]);
	scanf("%d", &m);// ������� �Է¹���
	getMaximumHeight(height, month, n, m); // �������ִ� ���������� ���� Ű�� ū ���丮�� Ű�� ����ϴ� �Լ�
	delete[] height; // �޸� �������� height �迭����
	delete[] month; // �޸� �������� month �迭 ����
	return 0;
}

void getMaximumHeight(int height[], int month[], int n, int m)
{
	int maxheight = -1; // ���� ���ǹ����� ������ �ش� �޿� ���� ���丮�� ���ٸ� -1�� ����Ҽ��ְ� -1�� �ʱ�ȭ
	for (int i = 0; i < n; i++) 
	{
		if (month[i] == m)
			if (maxheight < height[i]) // ���� ���ǹ� ������ �ش�޿� �ְ� ���ݱ��� �����ؿ� maxheight���� Ű�� ũ�ٸ� maxheight�� ������Ʈ��
				maxheight = height[i];

	}
	printf("%d", maxheight); // ���
}