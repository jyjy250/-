#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

class Square // �簢�������� ������ �����ϱ� ���� Ŭ���� Square
{
public:
	int leftloc; // ���ʸ�Ҹ��� x��ǥ�� ������ ���� leftloc
	int rightloc; // �����ʸ�Ҹ��� x��ǥ�� ������ ���� right loc
	int toploc; // ���� ��Ҹ��� y��ǥ�� ������ ���� toploc
	int bottomloc; // �Ʒ��� ��Ҹ��� y��ǥ�� ������ ���� bottomoc
	Square(int ax, int ay, int bx, int by) 
	{
		leftloc = min(ax, bx);
		rightloc = max(ax, bx);
		toploc = max(ay, by);
		bottomloc = min(ay, by);
	}
};

void getArea(Square a, Square b);

int main()
{
	int t; // �׽�Ʈ ���̽��� ���� ������ ���� t
	cin >> t; // �׽�Ʈ ���̽��� �� �Է�
	int ax, ay, bx, by, px, py, qx, qy; // a,b�� ù��° �簢���� �̷�� ���� �밢������ ���ֺ��� ������ ��ǥ p�� q�� �ι�° ���簢���� �̷�� ���� �밢������ ���ֺ��� ������ ��ǥ
	for (int i = 0; i < t; i++)
	{
		cin >> ax >> ay >> bx >> by >> px >> py >> qx >> qy; // ��ǥ�Է�
		Square a(ax, ay, bx, by); // �Է¹��� ��ǥ�� �簢�� ����
		Square b(px, py, qx, qy); // �Է¹��� ��ǥ�� �簢�� ����
		getArea(a, b); // ��ġ�� �κ��� ���̸� ���
	}
}

void getArea(Square a, Square b)
{
	int leftloc = max(a.leftloc, b.leftloc); // ��ġ�� �κ��� �׷��� �簢���� ���� ��Ҹ��� x��ǥ�� ������ ���� leftloc
	int rightloc = min(a.rightloc, b.rightloc); // ��ġ�� �κ��� �׷��� �簢���� ������ ��Ҹ��� x��ǥ�� ������ ���� rightloc
	int toploc = min(a.toploc, b.toploc); // ��ġ�� �κ��� �׷��� �簢���� ���� ��Ҹ��� y��ǥ�� ������ ���� toploc
	int bottomloc = max(a.bottomloc, b.bottomloc); // ��ġ�� �κ��� �׷��� �簢���� �Ʒ��� ��Ҹ��� y��ǥ�� ������ ���� bottomloc
	cout << (rightloc - leftloc) * (toploc - bottomloc) << endl;
}