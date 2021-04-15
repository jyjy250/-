#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<time.h>

using namespace std;
void run(int r, int n, char* rsp, char** frsp);

int main()
{
	int r,n; // ���� ���� �Է¹��� ���� r, ģ���� ���� �Է¹��� ���� n
	char* rsp; // �����̰� �� ����� �����ϴ� �迭
	char** frsp; // �������� ģ���� �� ����� �����ϴ� �迭
	scanf("%d", &r); // ���� �� �Է�
	rsp = new char[r+1]; // �����̰� �� ����� �����ϴ� �迭 ����
	scanf("%s", rsp); // �����̰� �� ��� �Է�
	scanf("%d", &n); // ģ���� �� �Է�
	frsp = new char* [n];
	for (int i = 0; i < n; i++) // n X r+1 ũ���� 2���� �迭�� �������� ģ���� ������� �����ϴ� �迭�� ����
		frsp[i] = new char[r + 1];
	for (int i = 0; i < n; i++) // ģ������ �� ������ �Է�
		scanf("%s", frsp[i]);
	clock_t start = clock();
	run(r, n, rsp, frsp); // ���������� ����
	clock_t end = clock();
	printf("����ð�: %lf��\n", (double)(end - start) / CLOCKS_PER_SEC);
	return 0;
}

void run(int r, int n, char* rsp, char** frsp)
{
	int point = 0; //�������� ������ ������ ���� ����
	int maxPoint = 0; // �����̰� ģ������ ������ ���� �̸� �˰��ִٰ� �����Ҷ� ���� �� �ִ� ������ ������ ���� ����
	char* predict = new char[r + 1]; // �����̰� ģ������ ������ ���� �̸� �˰��ִٰ� �����Ҷ� ������ ����� ���� �迭
	int countr = 0; // �� predict �迭�� ����� ���� ������ ����
	int counts = 0; // �� predict �迭�� ����� ���� ������ ����
	int countp = 0; // �� predict �迭�� ����� ���� ������ ����
	int countmax= 0; // �� predict �迭�� ����� ���� ������ ����
	for (int i = 0; i < r; i++)
	{
		countr = 0; // predict �迭�� ��Ȯ�� ����� ���Ͽ� �ʱ�ȭ
		counts = 0; // predict �迭�� ��Ȯ�� ����� ���Ͽ� �ʱ�ȭ
 		countp = 0; // predict �迭�� ��Ȯ�� ����� ���Ͽ� �ʱ�ȭ
		for (int j = 0; j < n; j++) // point ������ �����ϴ� �˰���
		{
			if (rsp[i] == 'R') // �����̰� �����ϰ��
			{
				if (frsp[j][i] == 'R') // �����
					point += 1;
				if (frsp[j][i] == 'S') // �̱���
					point += 2;
			}
			if (rsp[i] == 'S') // �����̰� �����ϰ��
			{
				if (frsp[j][i] == 'S') // �����
					point += 1;
				if (frsp[j][i] == 'P') // �̱���
					point += 2;
			}
			if (rsp[i] == 'P') // �����̰� ���ϰ��
			{
				if (frsp[j][i] == 'P') // �����
					point += 1;
				if (frsp[j][i] == 'R') // �̱���
					point += 2;
			}
		}
		for (int j = 0; j < n; j++) // i+1 ���忡 ģ������ �� ����,����,�� ���ڸ� üũ�Ѵ�
		{
			if (frsp[j][i] == 'R')
				countr++;
			if (frsp[j][i] == 'S')
				counts++;
			if (frsp[j][i] == 'P')
				countp++;
		}
		countmax = (((countr > counts) ? countr : counts) > countp) ? ((countr > counts) ? countr : counts) : countp; // ����,����,�� �� ���帹�̳��� ����� ���ڸ� countmax�� �����Ѵ�
		if (countmax == countr) // ������ ���� ���ٸ� ���� ���°� �����ϴ�
			predict[i] = 'P';
		if (countmax == counts) // ������ ���� ���ٸ� ������ ���°� �����ϴ�
			predict[i] = 'R';
		if (countmax == countp) // ���� ���� ���ٸ� ������ ���°� �����ϴ�
			predict[i] = 'S';
	}
	for (int i = 0; i < r; i++) // �ϼ��� predict �迭�� ������������ �����Ѵ�
	{
		for (int j = 0; j < n; j++)
		{
			if (predict[i] == 'R')
			{
				if (frsp[j][i] == 'R')
					maxPoint += 1;
				if (frsp[j][i] == 'S')
					maxPoint += 2;
			}
			if (predict[i] == 'S')
			{
				if (frsp[j][i] == 'S')
					maxPoint += 1;
				if (frsp[j][i] == 'P')
					maxPoint += 2;
			}
			if (predict[i] == 'P')
			{
				if (frsp[j][i] == 'P')
					maxPoint += 1;
				if (frsp[j][i] == 'R')
					maxPoint += 2;
			}
		}
	}
	printf("%d\n", point);
	printf("%d\n", maxPoint);
}
