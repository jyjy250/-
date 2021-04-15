#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<iostream>

using namespace std;

void printIndexes(string school[], int n);


int main()
{
	int n;
	char buff[11];
	scanf("%d", &n);
	string* school = new string[n]; // ������ ����ŭ ���̸� ���� string�迭�� ����
	for (int i = 0; i < n; i++) // string �迭�� ���� �Է¹���
	{
		scanf("%s", buff);
		school[i] = buff;
	}
	printIndexes(school, n);
	delete[] school;
	return 0;
}

void printIndexes(string school[], int n)
{
	int first = -1;
	int last = -1;
	string str = "AJOU";
	for (int i = 0; i < n; i++)
	{
		if (school[i].compare(str) == 0)// first ���� ���ϸ� �ݺ����� ����
		{
			first = i + 1;
			break;
		}
	}
	for (int i = first; i < n; i++)// last���� ���ϱ����� �ѹ��� �ݺ����� ������
	{
		if (school[i].compare(str) == 0)
			last = i + 1;
	}
	printf("%d %d", first, last);
}
