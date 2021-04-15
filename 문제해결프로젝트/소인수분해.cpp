#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

void prime(int num);

int main()
{
	int caseSize; // �׽�Ʈ ���̽��� ���� �����ϱ� ���� ���� caseSize;
	cin >> caseSize; //�׽�Ʈ ���̽��� �Է�
	int* num = new int[caseSize]; // �׽�Ʈ���̽�����ŭ�� ���̸� ���� num �迭 ����
	for (int i = 0; i < caseSize; i++) // ���μ� ������ ���ڵ� �Է�
		cin >> num[i];
	for (int i = 0; i < caseSize; i++) // �׽�Ʈ ���̽���ŭ �ݺ��ؼ� ���μ����� �Լ� ����
	{
		cout << "#" << i + 1 << ":" << endl; 
		prime(num[i]);
		cout << endl;
	}
	return 0;
}

void prime(int num)
{
	vector<int> primes; // ���μ��� ������ ���� primes
	int m = 2; // �Է¹��� ���ڸ� �������� 2�� �ʱ�ȭ
	while (1) 
	{
		if (num % m == 0) // ������ �������ٸ� 
		{
			primes.push_back(m); // m���� ���μ��� �����ϴ� ���� primes�� �߰�
			num /= m; // num������ m������ ���� ��������
			m = 2; // �ٽ� m�� 2�� �ʱ�ȭ
		}
		else // ������ �������� �ʴ´ٸ�
		{
			m++; // m�� ���� 
		}
		if (sqrt(num) < m) // m���� ���������� ������ �����ٺ��� Ŀ���ٸ�
		{
			primes.push_back(num); // ���������� ���ڸ� ���� primes�� �߰�
			break; // �ݺ��� Ż��
		}
	}
	for (int i = 0; i < primes.size(); i++)
	{
		cout << primes[i] << " ";
	}
}
