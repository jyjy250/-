#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<time.h>
#include<vector>

using namespace std;

#define MAX 100001 // �ø��� ��ȣ�� 1�̻� 10�� ���� �̹Ƿ� ������ ���� ���� 100001���� MAX�� �����Ѵ�

void bubbleSort(vector<int> data);

int main()
{
	int n; // �ø��� ��ȣ�� ���� �Է¹��� ���� n
	scanf("%d", &n); // �ø��� ��ȣ �� �Է�
	int data[MAX] = {0, }; // �ε��� 0~10000 ������ ���Ҹ� 0���� �ʱ�ȭ �Ѵ�
	int serialnum;
	for (int i = 0; i < n; i++) // �ø��� ��ȣ�� �Է¹ް� �Է¹��� �ø��� ��ȣ�� ������ ī��Ʈ�Ѵ�
	{
		scanf("%d", &serialnum);
		data[serialnum]++;
	}
	vector<int> serial; // �ѹ��� ������ �ø��� ��ȣ�� �����ϱ� ���� ���� ����
	for (int i = 0; i < MAX; i++)
	{
		if (data[i] == 1) // �� �ѹ��� ������ �ø��� ��ȣ�� ���Ϳ� �����Ѵ�
			serial.push_back(i);
	}
	bubbleSort(serial); // ����� �ø��� �ѹ��� �������ķ� ������������ �����ؼ� ����Ѵ�
}




void bubbleSort(vector<int> data)
{
	for (int i = 0; i < data.size(); i++) // �Ʒ� ������ n�� �ݺ�
	{
		for (int j = 0; j < data.size() - 1; j++) // data[0]~data[n-2] ��ĭ�� ���ڰ� data[1]~ data[n-1] ĭ�� ���� ���� ũ�� �ΰ��� ��ġ�� ��ȯ�Ѵ�
		{
			if (data[j] > data[j + 1])
			{
				int temp = data[j]; // ���� ��ȯ�ϱ����� ��� �������� ������ ���� temp
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < data.size(); i++) // ���������� �迭 ���
		printf("%d ", data[i]);
}
