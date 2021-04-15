#include<stdio.h>
#include<iostream>

using namespace std;

class SudokuBoard // ������ ������ ��,��,�׷��� ���ϱ� ���� Ŭ���� ������ ����
{
public:
	int getRowByIndex(int idx) // �ε����� �Ű������� ���� ��ȯ
	{
		return ((idx - 1) / 9) + 1; // �ε��� ���� 1�� ���ص� 9�� �������� n�̶�� n+1 ���̴�
	}
	int getColumnByIndex(int idx) // �ε����� �Ű������� ���� ��ȯ
	{
		return ((idx - 1) % 9) + 1; // �ε��� ���� 1�� ���ص� 9�� ������������ n�̶�� n+1 ���̴�
	}
	int getGroupNumByIndex(int idx) // �ε����� �Ű������� �׷� ��ȣ�� ��ȯ
	{
		int row = getRowByIndex(idx); // �׷� ��ȣ�� �˾Ƴ������� ����ġ�� ����
		int column = getColumnByIndex(idx); // �׷� ��ȣ�� �˾Ƴ������� ����ġ�� ����
		return (((row - 1) / 3) * 3) + (((column - 1) / 3) + 1); // ������ 1~3 ,4~6 , 7~9 ������ ������ ���Ѵ����� ���� �׹����� �ϳ��� ����.
	}
};



int main()
{
	int caseSize; // �׽�Ʈ���̽��� ���� �����ϱ����� ���� caseSize
	cin >> caseSize; //�׽�Ʈ���̽��� �Է�
	int* idxes = new int[caseSize]; // �׽�Ʈ���̽� ����ŭ�� ���̸� ���� idxes �迭 ����
	for (int i = 0; i < caseSize; i++) // idxes �迭�� �ε������� ����
		cin >> idxes[i]; 
	SudokuBoard board = SudokuBoard(); // ������ ���� ����
	for (int i = 0; i < caseSize; i++) // �׽�Ʈ ���̽���ŭ �ݺ�
	{
		cout << "Case #" << i + 1 << ":" << endl;
		cout << board.getRowByIndex(idxes[i]) << " " << board.getColumnByIndex(idxes[i]) << " " << board.getGroupNumByIndex(idxes[i]) << endl; // �ε����� ���ڷ� ��,��,�׷��ȣ ���
	}
	return 0;
}