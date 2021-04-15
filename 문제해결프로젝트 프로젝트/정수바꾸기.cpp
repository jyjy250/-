#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<cmath>
#include<time.h>
#include<vector>

using namespace std;

int ccount = 0; // ���� Ƚ���� ������ �������� ccount

int Double(int changeto);
int Addone(int changeto);
bool isAddedOne(int changeto);
void run(int num, int changeto, int maxcount);
int getMaxCount(int num, int changeto);

int main()
{
	int num, changeto; // ���� A�� �Է¹��� ���� num, B�� �Է¹��� ���� changeto
	int maxcount; // ���� ������ �����ϱ� ���ؼ� �ִ뿬��Ƚ���� ������ ���� maxcount
	scanf("%d %d", &num, &changeto); // ���� A�� B �Է�
	clock_t start = clock();
	maxcount = getMaxCount(num, changeto); // getMaxCount �Լ��� ���� maxcount ���� ����
	run(num, changeto, maxcount); // �ٽ� �Լ�
	clock_t end = clock();
	printf("����ð�: %lf��\n", (double)(end - start) / CLOCKS_PER_SEC);
}

int Double(int changeto) // ����Ƚ���� �����ϰ��ִ� �������� ccount���� ������Ű�� �Ű������� 2�� �������� ��ȯ �ϴ� �Լ�
{
	ccount++;
	return changeto / 2;
}

int Addone(int changeto) // ����Ƚ���� �����ϰ��ִ� �������� ccount���� ������Ű�� �Ű��������� 1�� ������ 10���� ���� ���� ��ȯ �ϴ� �Լ�
{
	ccount++;
	return ((changeto - 1) / 10);
}

void run(int num, int changeto, int maxcount) // changeto ������ num ������ ����� ����
{
	while (1) // ����Ƚ���� maxcount�� �����ϱ������� ���ѹݺ�
	{
		if (ccount == maxcount) // ���� Ƚ���� max count�� ���� �ߴµ��� (changeto == num) ���ǹ��� �ɸ��� ���� ��� , ���� �����̰� �ٲܼ� ���� ��� �̹Ƿ� -1����� �ݺ��� Ż��
		{
			printf("-1\n"); 
			break;
		}
		if (isAddedOne(changeto)) // �Ű� ���� ���ڸ��� 1�� �����ٸ� ������ �� ������ 1�� ���� ���� �����ʿ� �߰��ϴ� �����̴�
		{
			changeto = Addone(changeto);
		}
		else // �Ű����� ���ڸ��� 1�� ������ ���� ��쿡�� �������� 2�� ���ϴ� ���̿��ٰ� �����Ѵ�
		{
			changeto = Double(changeto);
		}
		if (changeto == num) // changeto ������ num�� ���ٸ� �ݺ��� Ż��
			break;
	}
	if (ccount != maxcount) // ���
		printf("%d\n", ccount + 1);
}

bool isAddedOne(int changeto) // �Ű����� ���ڸ��� 1�� �������� Ȯ�� �ϴ� �Լ�
{
	if (changeto % 10 == 1) // 10���� �������µ� �������� 1�̶�� ���ڸ��� 1�̴�
		return true;
	else
		return false;
}

int getMaxCount(int num, int changeto) 
{
	int count=0;
	while (1) // A�� B�� ����̹Ƿ� ���� ���� �۰� ������Ű�� ������ �ι��ϴ� �����̴�. �׷��Ƿ� 2���ϴ� ���길 ���� �������� MaxCount�� ���Ҽ��ִ�.
	{
		if (num < changeto)
		{
			num *= 2;
			count++;
		}
		else
			break;
	}
	return count;
}











