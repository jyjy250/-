#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;
void stringCompare(char str1[], char str2[]);

int main()
{
	char str1[100001]; //�ִ� 10�� ���̱��� �����Ҽ��ִ� ù��° ���ڹ迭 ����
	char str2[100001]; //�ִ� 10�� ���̱��� �����Ҽ��ִ� �ι�° ���ڹ迭 ����
	scanf("%s", str1); // ù��° ���ڿ� �Է�
	scanf("%s", str2); // �ι�° ���ڿ� �Է�
	stringCompare(str1, str2); // ���������� ���ϴ� �Լ� ȣ��
	return 0;
}

void stringCompare(char str1[], char str2[])
{
	int length; // ���ں� Ƚ���� ���ϱ� ���� int�� ������ ����
	bool equals = true; // ���ڿ��� �������� �����ϱ� ���� bool �� ���� ����
	if (strlen(str1) > strlen(str2)) // �ι��ڿ��� �� �� �����ǿ��� ���̸� �ݺ�Ƚ���� ����
		length = strlen(str1);
	else
		length = strlen(str2);
	for (int i = 0; i < length; i++)
	{
		if (str1[i] < str2[i]) // ���ڰ��� �ƽ�Ű���� ��ũ�ٸ� ���������� ���ڿ��ֱ� ������ �̰�� -1�� ���
		{
			printf("-1");
			equals = false; // ���������Ƿ� equals ������ false�� ����
			break; //�ݺ��� ����
		}
		if (str1[i] > str2[i]) // ���ڰ��� �ƽ�Ű���� ��ũ�ٸ� ���������� ���ڿ��ֱ� ������ �̰�� 1�� ���
		{
			printf("1");
			equals = false; // ���������Ƿ� equals ������ false�� ����
			break; //�ݺ��� ����
		}
	}
	if(equals) // ��� ���ڰ� �ƽ�Ű���� �����Ƿ� 0 ���
		printf("0");
}
