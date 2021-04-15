#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<time.h>
#include<cmath>

using namespace std;

void bubbleSort(int data[], int n);
void isConsecutive(int data[], int n);

int main()
{
	int n; // ������ ���� �Է¹��� ���� n
	int* data; // �����͸� �Է¹��� �迭 data
	scanf("%d", &n); // ������ ���� �Է�
	data = new int[n]; // ������ �� ��ŭ�� ���̸� ���� �迭 ����
	for (int i = 0; i < n; i++) // ������ �Է�
		scanf("%d", &data[i]);
	bubbleSort(data, n); // �Է� ���� �����͸� ���������Ѵ�
	isConsecutive(data, n);
	delete[] data;
	return 0;
}

void bubbleSort(int data[], int n)
{
	for (int i = 0; i < n; i++) // �Ʒ� ������ n�� �ݺ�
	{
		for (int j = 0; j < n - 1; j++) // data[0]~data[n-2] ��ĭ�� ���ڰ� data[1]~ data[n-1] ĭ�� ���� ���� ũ�� �ΰ��� ��ġ�� ��ȯ�Ѵ�
		{
			if (data[j] > data[j + 1])
			{
				int temp = data[j]; // ���� ��ȯ�ϱ����� ��� �������� ������ ���� temp
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
	}
}

void isConsecutive(int data[], int n)
{
	int count=0; // �������� �������� �Ǻ��ϱ����� count ����
	for (int i = 0; i < n - 1; i++)
	{
		if (data[i] + 1 != data[i + 1])
			printf("NO"); // �������� ������ �ƴ϶�� NO ���
		else if(data[i] + 1 == data[i + 1])
			count++; // �������� ���� �̶�� count �� ����
	}
	if (count == n - 1) // n-1�� �ݺ��ؼ� �ѹ��� if���� ���ǿ� �ɸ��� �ʾҴٸ� �������� �����̴�
		printf("YES");
}