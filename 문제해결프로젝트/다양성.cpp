#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;
void getElementTypeCount(int n, int data[]);

int main()
{
	int n; // ȭ���� ���� ��Ÿ���� ���� n
	int* data; // ȭ���� ���� ��Ÿ���� ȭ���� ����ŭ�� ���̸� ���� �迭 data
	scanf("%d", &n); // ȭ���� ���� �Է¹���
	data = new int[n]; // ȭ���� ����ŭ�� ���̸� ���� �迭 ����
	for (int i = 0; i < n; i++) // �迭�� ������ȣ�� �Է¹���
		scanf("%d", &data[i]);
	getElementTypeCount(n, data); // ȭ���� ������ ���� �Լ� ȣ��
	delete[] data; // data �迭 �޸𸮿��� ����
	return 0;
}

void getElementTypeCount(int n, int data[])
{
	int count = 0; // ��ġ�°� �ִ��� ������ Ȯ���ϱ� ���� count ����
	vector<int> serialNum; // ȭ���� ������ȣ�� ��ġ�� �ʰ� �����ϱ����� vector 
	serialNum.push_back(data[0]); // ���� �˰����� ���� ������ȣ �ϳ��� ����
	for (int i = 1; i < n; i++)
	{	
		for (int j = 0; j < serialNum.size(); j++) // main�Լ����� �Է¹��� ������ȣ�� vector�� ��ϵǾ��ִ��� Ȯ��
		{
			if (data[i] != serialNum[j]) // ������ȣ�� vector�� ���ҵ��� �������� ��ġ�� ������ count ���� ����
				count++;
			if (count == serialNum.size()) // ������ȣ�� ��� vector�� ���ҵ�� ��ġ�� ������ ��ϵ��� ���� ������ȣ �̹Ƿ� vector�� ����
				serialNum.push_back(data[i]);
		}
		count = 0; // ������ȣ �񱳸� ���� �ٽ� count ���� 0���� �ʱ�ȭ 
	}
	printf("%d", serialNum.size()); // ��ġ�� �ʰ� ������ȣ�� ������ vector�� ��������Ƿ� vector�� ũ�Ⱑ �� ������ ����
}
