#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#pragma warning(disable:4996)
#define SCORE 50

void arrChange(int* i, int* j); // �迭 �ڸ����� 
void printResult(int* score); // ���
void random(int* score, int maxRand); // ������ (�ߺ�����)
void compare(int* score); // �迭 �� ��
void guide(int code); // Guide �޽���
void file(); //����� ���Ͽ� ����

void arrChange(int* i, int* j) {
	int temp = *i;
	*i = *j;
	*j = temp;
}

// ���
void printResult(int* score) {
	for (int i = 0; i < SCORE; i++) {
		for (int k = 0; k < score[i]; k++) {
			printf("|");
		}
		printf("%d\n", score[i]);
	}
}

// ������ (�ߺ�����)
void random(int* score, int maxRand) {
	for (int i = 0; i < SCORE; i++) {
		score[i] = rand() % maxRand + 1;
		for (int j = 1; j < SCORE; j++) {
			if (score[i] == score[i - j]) {
				i -= 1;
			}
		}
	}
	printf("\n");
}

// �迭 �� ��
void compare(int* score) {
	for (int i = 0; i < SCORE; i++) {
		for (int j = 0; j < SCORE; j++) {
			if (score[i] < score[j]) {
				arrChange(&score[i], &score[j]);
			}
		}
	}
}

// Guide �޽���
void guide(int code) {
	switch (code) {
	case 1:
		printf("������ �ִ� ����(50 ~ 100)�� �Է� �����մϴ�.");
		Sleep(1000);
		system("cls");
		break;
	case 2:
		Sleep(1000);
		system("cls");
		printf("\n�迭�� �����ϴ� ��...\n");
		break;
	case 3:
		Sleep(2000);
		system("cls");
		printf("\n���� �Ϸ�.\n");
		Sleep(1000);
		system("cls");
		break;
	}
}

void file(int* score) {
	FILE* f;
	f = fopen("test.text", "w");
	for (int i = 0; i < SCORE; i++) {
		for (int k = 0; k < score[i]; k++) {
			fprintf(f, "|");
		}
		fprintf(f, "%d\n", score[i]);
	}
	fclose(f);
}

int main(void) {

	int maxRand = 1, score[SCORE];

	srand(time(NULL));

	while (maxRand) {
		printf("\n> '0' �� ���� ���� <");
		printf("������ �ִ� ����(50 ~ 100)�� �Է��ϼ���: ");
		scanf("%d", &maxRand);

		if (maxRand >= 1 && maxRand < 50 || maxRand > 100) {
			guide(1);
			continue;
		}
		else {

			random(&score, maxRand); // �迭�� ������ ���� ��ġ �� �ߺ� ����
 
			printResult(&score); // �迭�� ���ʷ� ��ġ�� ���� ���
	
			guide(2); // �迭 ���� ���

			compare(&score); // �迭 ����

			guide(3); // �迭 ���� �Ϸ� ���

			printResult(&score); // ���� ��� ���

			file(&score); //���� ��� ���Ͽ� ����
		}
	}
	return 0;
}