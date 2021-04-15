#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<time.h>

using namespace std;

void paint(int seat[], int m);
void count(int seat[], int n);

int main()
{
	int n, m; // �¼��� ��, ��ĥ�� �� ����Ǽ��� �Է¹��� ���� n,m
	scanf("%d %d", &n, &m); // �¼��� �� , ��Ģ�� �� ����Ǽ��� �Է�
	int* seat = new int[n + 1]; // �¼��� ������ ������ �迭 seat, 0���¼��� ���������� �¼��� ������ 1���� ��� �����Ѵ�
	for (int i = 0; i < n + 1; i++)
		seat[i] = 0; // �ϴ� ��� 0�� ����� ĥ�Ѵ�
	paint(seat, m);
	count(seat, n);
	return 0;
}

void paint(int seat[], int m)
{
	int left; // ��ĥ�� ���� ���� �¼��� ��ȣ�� ������ ���� left
	int right; // ��ĥ�� ���� ������ �¼��� ��ȣ�� ������ ���� right
	int color; // ������ ��ȣ�� �Է¹��� ���� color
	for (int i = 0; i < m; i++) // ��ĥ�� ����� ����ŭ �ݺ��ؼ� ��ĥ
	{
		scanf("%d %d %d", &left, &right, &color);
		for (int j = left; j <= right; j++) // �¼� �Ѱ��� ��ĥ
			seat[j] = color;

	}
}

void count(int seat[], int n)
{
	int cnt[100] = { 0, }; // ������ �� 0~99 ���� 100�� �̹Ƿ� ����100 ¥�� �迭 ����
	for (int i = 1; i < n + 1; i++) // cnt[�����ȣ] +=1 �̹Ƿ� cnt�� �ε����� ������ ��ȣ�� ���ϰ� ��Ҵ� ������ ������ �ǹ��ϰԵȴ�.
		cnt[seat[i]] += 1;
	for (int i = 0; i < 100; i < i++)
	{
		if (cnt[i] == n) // 1���� ����� ĥ�Ұ�� ���� �˰������δ� ������ ���� ������ ���ܷ� ���⼭ ó���Ѵ�
		{
			printf("%d\n", i);
			printf("%d\n", i);
			exit(0);
		}
	}
	int max = cnt[0]; // ���� ���� ������ ������ ������ ���� max
	int maxIdx = 0; // ���� ���� ������ ��ȣ�� ������ ���� maxIdx
	int min = cnt[0]; // ���� ���� ������ ������ ������ ���� min
	int minIdx = 0; // ���� ���� ������ ��ȣ�� ������ ���� minIdx
	for (int i = 0; i < 100; i++)
	{
		if (cnt[i] > max)
		{
			max = cnt[i];
			maxIdx = i;
		}
		if (cnt[i] != 0) // ��ĥ���� ���� ������ ���� �ϱ����� ���ǹ�
			if (cnt[i] < min)
			{
				min = cnt[i];
				minIdx = i;
			}
	}
	printf("%d\n", maxIdx);
	printf("%d\n", minIdx);
}