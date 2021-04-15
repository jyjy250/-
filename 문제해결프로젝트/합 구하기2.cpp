#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>

void solve(int data[], int n, int p, int q);


int main()
{
	int n, p, q;
	int* data;
	scanf("%d %d %d", &n, &p, &q); // n, p, q�� �Է�
	data = new int[n]; // ������� ���� ���� �� ���̸�ŭ�� int�� �迭�� ����
	for (int i = 0; i < n; i++)
		scanf("%d", &data[i]); // ������ �迭�� ������� ������ �Է�
	solve(data, n, p, q);
	delete[] data;
	return 0;
}

void solve(int data[], int n, int p, int q)
{
	int count = 0; //ž�°����� ������� �� ī��Ʈ
	int totalweight = 0; // ž�°����� ������� ���������� ������ ����
	for (int i = 0; i < n; i++)
	{
		if (data[i] <= p)  //i��° ����� �����԰� p kg ���϶�� ž�°��ɸ���� ī��Ʈ�ѵ� �������պ����� �����Ը�ŭ �ø�
		{
			count++;
			totalweight += data[i];
		}
	}
	printf("%d %d\n", count, totalweight);
	if (totalweight <= q)// q kg ���϶�� YES �ƴϸ� NO
		printf("YES");
	else
		printf("NO");
}
