#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<time.h>
#include<vector>

using namespace std;

int fibonacciSequence(int n);

int main()
{
	int t; // �׽�Ʈ ���̽��� ���� �Է¹��� ���� t
	scanf("%d", &t); // �׽�Ʈ ���̽��� �Է�
	int* n = new int[t]; // �׽�Ʈ ���̽� ����ŭ�� ���̸� ���� �迭 n ����
	for( int i=0; i<t; i++) // �ڿ��� n�� �Է�
		scanf("%d", &n[i]);
	for (int i = 0; i < t; i++)
		fibonacciSequence(n[i]); 
}

int fibonacciSequence(int n)
{
	int front = 0; // ���� �ο����� ���� �ε����� ����Ű�� ���� front
	int back = 1; // ���� �ο����� ���� �ε����� ����Ű�� ���� back
	vector<unsigned long long> fibonacci; // fibonacci ������ ������ ����
	fibonacci.push_back(0); // ù���� ���� 0
	fibonacci.push_back(1); // �ι�° ���� 1
	if (n == 1) // n�� 1�϶� 0�� ���
	{
		printf("0\n");
		return 0;
	}
	if (n == 2) // n�� 2�϶� 1�� ���
	{
		printf("1\n");
		return 0;
	}
	while (fibonacci.size() != n) // n�� 3�̻��϶� n��° ���� �Ʒ������� ���� ���Ѵ�.
	{
		fibonacci.push_back(fibonacci[front] + fibonacci[back]); // ���� �ο����� ���� ���Ϳ� �߰�
		front++; // �ε����� ����
		back++; // �ε����� ����
		fibonacci.back() %= 100000000; 
	}

	printf("%d\n", fibonacci.back());
	return 0;
}





