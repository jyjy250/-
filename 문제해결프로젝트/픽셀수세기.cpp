#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<time.h>
#include<cmath>

using namespace std;

bool isInside(int x, int y, int R);
void CirclePixelCount(int R);

int main()
{
	int caseSize; // �׽�Ʈ ���̽��� ���� �Է¹��� ���� caseSize
	int* R; // �������� �Է¹��� �迭 R
	scanf("%d", &caseSize); // �׽�Ʈ ���̽� �� �Է� 
	R = new int[caseSize]; // �׽�Ʈ ���̽� ����ŭ�� ���̸� ���� �迭 ����
	for (int i = 0; i < caseSize; i++) // �������� �Է�
		scanf("%d", &R[i]);
	for (int i = 0; i < caseSize; i++) // �׽�Ʈ ���̽� ����ŭ �ݺ�����
	{
		printf("#%d\n", i + 1);
		CirclePixelCount(R[i]);
	}
	delete[] R;
	return 0;
}

bool isInside(int x, int y, int R)
{
	if (pow(x, 2) + pow(y, 2) < pow(R, 2)) // x^2+y^2 < R^2 �ϰ�� �ȼ��� ���ȿ� �ִٰ� �Ǵ�
		return true;
	else // �׿��� ���� �ٱ��� �ִٰ� �Ǵ�
		return false;
}
void CirclePixelCount(int R)
{
	long long pixel=0;
	int height;
	for (int i = 0; i < R; i++)
	{
		height = R; // 
		for (int j = 0; j < R; j++)
		{
			if (isInside(i, height, R)) // ���ȿ� �ִٸ� �ݺ����� ������ pixel�� height���� ������
				break;
			else
				height--; // ���ۿ� �ִٸ� height���� 1 ���ε� �ٽ� �õ�
		}
		pixel += height+1; // ���� ����+1 ��ŭ�� �ȼ��� ����
	}
	printf("%lld\n", 4*pixel); // �ϳ��� ��и��� ������ ���ؼ� 4�� �����ص� ���
}
