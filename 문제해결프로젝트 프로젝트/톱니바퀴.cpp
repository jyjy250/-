#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<iostream>
#include<time.h>

using namespace std;

void clockRotate(string* wheel);
void counterClockRotate(string* wheel);
bool shouldRotateLeft(string rotatingWheel, string rotatedWheel);
bool shouldRotateRight(string rotatingWheel, string rotatedWheel);
void rotate(int rotwheel, int rotdirection, string wheel[]);

int didRotate[4] = { 0,0,0,0 }; // ��Ϲ����� ȸ���̷��� �����ϱ����� �迭 didRotate

int main()
{
	string wheel[4]; // ��� ������ ���¸� �Է¹ޱ� ���� string �迭 wheel
	int score = 0; // ������ ������ ���� score
	int rotatenum; // ȸ�� Ƚ���� ������ ���� rotatenum
	int* rotwheel; // ȸ����Ų ��Ϲ����� ��ȣ�� ������ �迭 rotwheel
	int* rotdirection; // ȸ����ų ������ ������ �迭 rotdirection
	for (int i = 0; i < 4; i++) // wheel�� ���¸� �Է�
		cin >> wheel[i];
	cin >> rotatenum; // ȸ�� Ƚ���� �Է�
	rotwheel = new int[rotatenum]; // rotatenum��ŭ�� ���̸� ���� rotwheel �迭 ����
	rotdirection = new int[rotatenum]; // rtotatenum��ŭ�� ���̸� ���� rotdirection �迭 ����
	for (int i = 0; i < rotatenum; i++)
		cin >> rotwheel[i] >> rotdirection[i]; // rotwheel�� rotdirection �Է�
	clock_t start = clock();
	for (int i = 0; i < rotatenum; i++) // ȸ�� Ƚ����ŭ rotate �Լ� ����
	{
		rotate(rotwheel[i], rotdirection[i], wheel);
		for (int j = 0; j < 4; j++) // �ѹ��� ȸ���� ������ ȸ�� �̷� �ʱ�ȭ
			didRotate[j] = 0;
	}

	if (wheel[0].at(0) == '1') // ȸ����Ų ��Ϲ����� ���� ����
		score += 1;
	if (wheel[1].at(0) == '1')
		score += 2;
	if (wheel[2].at(0) == '1')
		score += 4;
	if (wheel[3].at(0) == '1')
		score += 8;
	cout << score << endl;
	clock_t end = clock();
	printf("����ð�: %lf��\n", (double)(end - start) / CLOCKS_PER_SEC);
}

void clockRotate(string* wheel) // �ð�������� ȸ����Ű�� �Լ�
{
	string rotated = "00000000"; // ȸ���� ����� �����ϱ� ���� string �迭 rotated
	rotated.at(0) = wheel->at(7); // ���ڿ��� ������ ���� rotated�迭�� ù������ �����Ѵ�
	for (int i = 1; i < 8; i++) // �ð�������� ȸ���ϴ°� �迭���忡�� ���� ���������� �̴°��̴�
		rotated.at(i) = wheel->at(i - 1);
	*wheel = rotated; // ȸ���� ����� wheel�� ����
}

void counterClockRotate(string* wheel) // �ݽð�������� ȸ�� ��Ű�� �Լ�
{
	string rotated = "00000000"; // ȸ���� ����� �����ϱ� ���� string �迭 rotated
	rotated.at(7) = wheel->at(0); // ���ڿ��� ���� ���� rotated�迭�� �����ʳ��� �����Ѵ�
	for (int i = 6; i > -1; i--) // �ݽð�������� ȸ���ϴ°� �迭���忡�� ���� �������� �̴°��̴�
		rotated.at(i) = wheel->at(i + 1);
	*wheel = rotated; // ȸ���� ����� wheel�� ����
}

bool shouldRotateRight(string rotatingWheel, string rotatedWheel) // �����ʿ� �ִ� ��Ϲ����� ���ʿ��ִ� ��Ϲ����� ȸ�������� ȸ���ؾ��ϴ��� �Ǵ�
{
	if (rotatingWheel.at(2) != rotatedWheel.at(6)) // ������ ������ �´��� �κ��� ���� �ٸ��ٸ� ȸ�����Ѿ� �ϹǷ� true
		return true;
	else
		return false;
}

bool shouldRotateLeft(string rotatingWheel, string rotatedWheel) // ���ʿ� �ִ� ��Ϲ����� �����ʿ��ִ� ��Ϲ����� ȸ�������� ȸ���ؾ��ϴ��� �Ǵ�
{
	if (rotatingWheel.at(6) != rotatedWheel.at(2)) // ������ ������ �´��� �κ��� ���� �ٸ��ٸ� ȸ�����Ѿ� �ϹǷ� true
		return true;
	else
		return false;
}

void rotate(int rotwheel, int rotdirection, string wheel[])
{
	didRotate[rotwheel - 1] = 1; // ȸ�� �̷��� ����
	if (rotwheel == 1) // ȸ�����Ѿ� �ϴ� ��Ϲ����� 1���� ���
	{
		if (rotdirection == 1) // �ð�������� ȸ�� ��Ű�� ���
		{
			if (shouldRotateRight(wheel[0], wheel[1]) && !didRotate[1]) // 2�� ��Ϲ����� ȸ������ ����, ȸ���̷��� ���� �´��� ���� �ٸ��� ����
				rotate(2, -1, wheel);
			clockRotate(&wheel[0]);
		}
		else // �ݽð�������� ȸ�� ��Ű�� ���
		{
			if (shouldRotateRight(wheel[0], wheel[1]) && !didRotate[1]) // 2�� ��Ϲ����� ȸ������ ����, ȸ���̷��� ���� �´��� ���� �ٸ��� ����
				rotate(2, 1, wheel);
			counterClockRotate(&wheel[0]);
		}
	}
	if (rotwheel == 2) // ȸ�����Ѿ� �ϴ� ��Ϲ����� 2���� ���
	{
		if (rotdirection == 1) // �ð� �������� ȸ�� ��Ű�� ���
		{
			if (shouldRotateRight(wheel[1], wheel[2]) && !didRotate[2]) // 3�� ��Ϲ����� ȸ�� ���� ����, ȸ���̷��� ���� �´��� ���� �ٸ��� ����
				rotate(3, -1, wheel);
			if (shouldRotateLeft(wheel[1], wheel[0]) && !didRotate[0]) // 1�� ��Ϲ����� ȸ�� ���� ����, ȸ���̷��� ���� �´��� ���� �ٸ��� ����
				rotate(1, -1, wheel);
			clockRotate(&wheel[1]);
		}
		else // �ݽð� �������� ȸ�� ��Ű�� ���
		{, ȸ���̷��� ���� �´��� ���� �ٸ��� ����
			if (shouldRotateRight(wheel[1], wheel[2]) && !didRotate[2]) // 3�� ��Ϲ����� ȸ�� ���� ����, ȸ���̷��� ���� �´��� ���� �ٸ��� ����
				rotate(3, 1, wheel);
			if (shouldRotateLeft(wheel[1], wheel[0]) && !didRotate[0]) // 1�� ��Ϲ����� ȸ�� ���� ����, ȸ���̷��� ���� �´��� ���� �ٸ��� ����
				rotate(1, 1, wheel);
			counterClockRotate(&wheel[1]);
		}
	}
	if (rotwheel == 3) // ȸ�����Ѿ� �ϴ� ��Ϲ����� 3���� ���
	{
		if (rotdirection == 1) // �ð� �������� ȸ�� ��Ű�� ���
		{
			if (shouldRotateRight(wheel[2], wheel[3]) && !didRotate[3]) // 4�� ��Ϲ����� ȸ�� ���� ����, ȸ���̷��� ���� �´��� ���� �ٸ��� ����
				rotate(4, -1, wheel);
			if (shouldRotateLeft(wheel[2], wheel[1]) && !didRotate[1]) // 2�� ��Ϲ����� ȸ�� ���� ����, ȸ���̷��� ���� �´��� ���� �ٸ��� ����
				rotate(2, -1, wheel);
			clockRotate(&wheel[2]);
		}
		else // �ݽð� �������� ȸ�� ��Ű�� ���
		{
			if (shouldRotateRight(wheel[2], wheel[3]) && !didRotate[3]) // 4�� ��Ϲ����� ȸ�� ���� ����, ȸ���̷��� ���� �´��� ���� �ٸ��� ����
				rotate(4, 1, wheel);
			if (shouldRotateLeft(wheel[2], wheel[1]) && !didRotate[1]) // 2�� ��Ϲ����� ȸ�� ���� ����, ȸ���̷��� ���� �´��� ���� �ٸ��� ����
				rotate(2, 1, wheel);
			counterClockRotate(&wheel[2]);
		}
	}
	if (rotwheel == 4) // ȸ�����Ѿ� �ϴ� ��Ϲ����� 4���� ���
	{
		if (rotdirection == 1) // �ð� �������� ȸ�� ��Ű�� ���
		{
			if (shouldRotateLeft(wheel[3], wheel[2]) && !didRotate[2]) // 3�� ��Ϲ����� ȸ�� ���� ����, ȸ���̷��� ���� �´��� ���� �ٸ��� ����
				rotate(3, -1, wheel);
			clockRotate(&wheel[3]);
		}
		else // �ݽð� �������� ȸ�� ��Ű�� ���
		{
			if (shouldRotateLeft(wheel[3], wheel[2]) && !didRotate[2]) // 3�� ��Ϲ����� ȸ�� ���� ����, ȸ���̷��� ���� �´��� ���� �ٸ��� ����
				rotate(3, 1, wheel);
			counterClockRotate(&wheel[3]);
		}
	}
}














