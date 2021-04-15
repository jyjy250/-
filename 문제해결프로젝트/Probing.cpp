#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

class LottoTable // ���� ��ȣ�� �����ϰ� �����ϱ����� Ŭ����
{
public:
	vector<int> used; // ���޵� ���� ��ȣ�� �����ϱ����� ����
	bool isUsed(int lotto) // ���� ��ȣ�� ��� �Ǿ����� Ȯ���ϴ� �޼ҵ�
	{
		for (int i = 0; i < used.size(); i++)
		{
			if (lotto == used[i]) // ���Ǿ��ٸ� true ��ȯ
				return true;
		}
		return false; // ������ �ʾҴٸ� false ��ȯ
	}
	int makeLotto(int lottoAmount, int memberId) // ȸ�� ��ȣ�� ���� ��ȣ�� �����ϴ� �޼ҵ�
	{
		int lotto = memberId % lottoAmount; // ���� ��ȣ ����
		while (1)
		{
			if (isUsed(lotto)) // ������ ���� ��ȣ�� ���Ǿ��ٸ� ���� ����
				lotto++;
			else
				break; //�������ʾҴٸ� ������ Ż��
			if (lotto == lottoAmount) // ���ǹ�ȣ ������ ���ٸ� 0���� ���ư��� �ݺ�
				lotto = 0;

		}
		used.push_back(lotto); // ���������� ��ȣ�� ���ߴٸ� used���Ϳ� �߰�
		return lotto; // ���� ��ȣ ����
	}

};

int main()
{
	int lottoAmount, enterMember; // ������ ���� ������ ���� lottoAmount, ����ȸ���� �� enterMember
	cin >> lottoAmount >> enterMember; // ������ �� �Է�, ����ȸ���� �� �Է�
	int* memberId = new int[enterMember]; // ȸ����ȣ�� ������ �迭 memberId�� ����ȸ���� ����ŭ�� ���̷� ����
	for (int i = 0; i < enterMember; i++) //ȸ����ȣ �Է�
		cin >> memberId[i];
	LottoTable luck = LottoTable(); 
	for (int i = 0; i < enterMember; i++) // ���� ��ȣ ������ ���
		cout << luck.makeLotto(lottoAmount, memberId[i]) << endl;
}
