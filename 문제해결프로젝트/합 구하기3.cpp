#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>

using namespace std;

void getAnswer(int n);


int main()
{
	int n;
	scanf("%d", &n);
	getAnswer(n);
	return 0;
}

void getAnswer(int n)
{
	long long answer = 0;
	int count = 1;
	for (int i = 1; i <= n; i++) //answer�� �ٽ� 1���� ��������  count ���� 1�� �ʱ�ȭ
	{
		count = 1;
		for (int j = 1; j <= i; j++) // 1�̻� i ���� �ڿ����� ���� count���� 1�� �÷����� answer�� ����
		{
			answer += count;
			count++;
		}
	}
	printf("%ld", answer);
}
