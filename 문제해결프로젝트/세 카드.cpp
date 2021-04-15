#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

vector<int> cases; // ī�带 �̾Ƽ� ���� �� �ִ� ��� ����� ���� ������ ���� cases;
vector<int> possible; // ���� �� �ִ� ��÷ ��ȣ�� ������ ���� possible

void CaseCalculator(int cards[], int cardNum);
void bubbleSort(vector<int> data);

int main()
{
	int cardNum, lottoNum; // ����� ī���� ���ڸ� �Է¹��� ���� cardNum, ��÷��ȣ�� ���ڸ� �Է¹��� ���� lottoNum;
	cin >> cardNum >> lottoNum; // ī���� ���ڿ� ��÷��ȣ�� ������ �Է�
	int* cards = new int[cardNum]; // ī�� ���ڸ�ŭ�� ���̸� ���� �迭 cards ����
	int* lotto = new int[lottoNum]; // ��÷��ȣ�� ���ڸ�ŭ�� ���̸� ���� �迭 lotto ����
	bool posi; // possible ���͸� ä�ﶧ�� ������ �����ϱ� ���� bool ���� posi
	for (int i = 0; i < cardNum; i++) // ī�忡 ���� ���ڵ��� �Է�
		cin >> cards[i];
	for (int i = 0; i < lottoNum; i++)// ��÷��ȣ���� �Է�
		cin >> lotto[i];
	cases.push_back(cards[0] + cards[0] + cards[0]); // ������ ����� ���� ���� �˰����� ���� �Ѱ��� �߰����ش�
	CaseCalculator(cards, cardNum); // ������ ��� ����Ǽ��� ����ؼ� ä��� �Լ�
	for (int i = 0; i < lottoNum; i++) // ����� ���߿��� �̹��� ��÷��ȣ�� ��ģ�ٸ� possible ���Ϳ� �߰�
	{
		posi = false;
		for (int j = 0; j < cases.size(); j++)
			if (lotto[i] == cases[j])
				posi = true;
		if (posi)
			possible.push_back(lotto[i]);
	}
	bubbleSort(possible); // possible ���͸� ������������ ����
}
void CaseCalculator(int cards[], int cardNum)
{
	bool already; // �̹� �ִ� �����ΰ�츦 �Ǻ��ϱ� ���� ���� already
	for (int i = 0; i < cardNum; i++)
		for (int j = 0; j < cardNum; j++)
			for (int k = 0; k < cardNum; k++)
			{ 
				already = false; 
				for (int l = 0; l < cases.size(); l++)
					if (cards[i] + cards[j] + cards[k] == cases[l]) // �̹� �ִ� ����� ���ΰ�츦 �ɷ�����
						already = true;
				if (!already) //already �Լ��� false ��� �̹� �ִ� ����� ���� �ƴϹǷ� ����� ���� ���Ϳ� �߰�
					cases.push_back(cards[i] + cards[j] + cards[k]);
			}
}

void bubbleSort(vector<int> data)
{
	for (int i = 0; i < data.size(); i++) // �Ʒ� ������ ������ ���̸�ŭ �ݺ�
	{
		for (int j = 0; j < data.size() - 1; j++) // data[0]~data[n-2] ��ĭ�� ���ڰ� data[1]~ data[n-1] ĭ�� ���� ���� ũ�� �ΰ��� ��ġ�� ��ȯ�Ѵ�
		{
			if (data[j] > data[j + 1])
			{
				int temp = data[j]; // ���� ��ȯ�ϱ����� ��� �������� ������ ���� temp
				data.erase(data.begin() + j);
				data.insert(data.begin()+(j + 1), temp);
			}
		}
	}
	if (possible.size())
		for (int i = 0; i < data.size(); i++)
			cout << data[i] << " ";
	else
		cout << "NO";
}
