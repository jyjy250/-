#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int primeCount(int start, int end);

int main()
{
	int caseSize; // �׽�Ʈ ���̽��� ���� �����ϱ� ���� ���� caseSize;
	cin >> caseSize; //�׽�Ʈ ���̽��� �Է�
	int* start = new int[caseSize]; // �׽�Ʈ���̽�����ŭ�� ���̸� ���������� ������ ������ start �迭 
	int* end = new int[caseSize]; // �׽�Ʈ���̽�����ŭ�� ���̸� ���������� ���� ������ end �迭 ���� 
	for (int i = 0; i < caseSize; i++) // ������ �Է�
		cin >> start[i] >> end[i];
	for (int i = 0; i < caseSize; i++) // ���̽��� ����ŭ �Լ��� �ݺ�����
	{
		cout << "Case #" << i + 1 << ":" << endl;
		cout << primeCount(start[i], end[i]) << endl;
	}
}

int primeCount(int start, int end) // ������ �ָ� �׻����� �Ҽ��� ������ ��ȯ�ϴ� �Լ�
{
	int count = 0; // �Ҽ��� ������ ������ ���� count
	for (int i = start; i <= end; i++)
	{
		int factor = 0; // ����� ������ ������ ���� factor
		for (int j = 2; j <= i; j++) // j�� ������Ű�� i�� j�� ������������� Ȯ��
		{
			if (i % j == 0) // ������ �������� factor�� ����
				factor++;
		}
		if (factor == 1) // j���� 2���� �����̰� i������ �����ϱ� ������ factor ���� 1�̶�� �Ҽ��̴�
			count++; //�Ҽ��� ���� ����
	}
	return count; // �Ҽ��� ���� ��ȯ
}
