#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<time.h>

using namespace std;


int main()
{
	int n; // ��ȭ��ȣ�� ���������� ���� n
	scanf("%d", &n); // ��ȭ��ȣ�� �� �Է�
	int* data = new int[n]; // ��ȭ��ȣ�� ����ŭ�� ���̸� ���� �迭 ����
	int cnt [10000] = { 0, }; // 0~9999 ������ ������ ������ ������ �迭 ����, 0���� �ʱ�ȭ
	for (int i = 0; i < n; i++) // ��ȭ��ȣ ����ŭ �ݺ��ؼ� ��ȭ��ȣ�� �Է¹޴´�
	{
		scanf("%d", &data[i]);
		cnt[data[i]] += 1; // cnt[��ȭ��ȣ] +=1 �̹Ƿ� ������ ī���õȴ�
	}
	int idx = 0; // ���帹�� ��ȭ��ȣ�� ������ ���� idx
	for (int i = 0; i < 10000; i++) // ���帹�� ��ȭ��ȣ��  ���� idx�� �����Ѵ�
	{
		if (cnt[i] > idx)
			idx = i;
	}
	printf("%04d ", idx); // ��ȭ��ȣ 0001�� cnt[1]�� ������ �ø��⶧���� %04d �������� ������ش�
}