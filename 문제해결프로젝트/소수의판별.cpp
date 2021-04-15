#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<time.h>

using namespace std;

bool isPrime(int testCase);

int main()
{
	int caseSize; // �׽�Ʈ���̽��� ������ �Է¹��� ���� caseSize
	int* testCase; // �׽�Ʈ���̽��� ���ڸ� �Է¹��� �迭 testCase
	scanf("%d", &caseSize); // �׽�Ʈ ���̽��� ������ �Է�
	testCase = new int[caseSize]; // �׽�Ʈ ���̽��� ������ŭ�� ���̸� ���� �迭 ����
	for (int i = 0; i < caseSize; i++) // �迭�� �׽�Ʈ ���̽����� ���ڸ� �Է�
		scanf("%d", &testCase[i]); 
	for (int i = 0; i < caseSize; i++) // �׽�Ʈ ���̽� ���� �Ҽ����� �ƴ��� �Ǵ��� �˸°� ���
	{
		printf("Case #%d\n", i + 1);
		if (isPrime(testCase[i])) // �Ҽ��ΰ��
			printf("YES\n");
		else // �Ҽ��� �ƴѰ��
			printf("NO\n");
	}
	delete[] testCase;
	return 0;
}

bool isPrime(int testCase) // �׽�Ʈ ���̽��� ���ڸ� �Է¹޾� �Ҽ����� �ƴ��� bool���� return���ִ� �Լ�
{
	int count = 0; // �׽�Ʈ ���̽��� ���ڰ� �󸶳� ���������� ������ ����
	for (int divison=2; divison <= testCase; divison++) // testCase�� 2���� �����ؼ� 1�� ������Ű�鼭 ��� ������
		if (testCase % divison == 0) // ������ �������ٸ� count ������ 1������Ų��
			count++;
	if (count > 1) // 1���� ū��� �� ������ �������� ��찡 �ڱ��ڽ� ���� �ѹ��̶� �� �ִٸ� �Ҽ��� �ƴϴ�
		return false;
	else // count ������ 1�ΰ�쿡�� �Ҽ��̴�
		return true;
}
