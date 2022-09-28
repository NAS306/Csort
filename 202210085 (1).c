#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#pragma warning(disable:4996)
#define SCORE 50

void arrChange(int* i, int* j); // 배열 자리변경 
void printResult(int* score); // 출력
void random(int* score, int maxRand); // 무작위 (중복제거)
void compare(int* score); // 배열 값 비교
void guide(int code); // Guide 메시지
void file(); //결과값 파일에 저장

void arrChange(int* i, int* j) {
	int temp = *i;
	*i = *j;
	*j = temp;
}

// 출력
void printResult(int* score) {
	for (int i = 0; i < SCORE; i++) {
		for (int k = 0; k < score[i]; k++) {
			printf("|");
		}
		printf("%d\n", score[i]);
	}
}

// 무작위 (중복제거)
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

// 배열 값 비교
void compare(int* score) {
	for (int i = 0; i < SCORE; i++) {
		for (int j = 0; j < SCORE; j++) {
			if (score[i] < score[j]) {
				arrChange(&score[i], &score[j]);
			}
		}
	}
}

// Guide 메시지
void guide(int code) {
	switch (code) {
	case 1:
		printf("랜덤값 최대 숫자(50 ~ 100)만 입력 가능합니다.");
		Sleep(1000);
		system("cls");
		break;
	case 2:
		Sleep(1000);
		system("cls");
		printf("\n배열을 정렬하는 중...\n");
		break;
	case 3:
		Sleep(2000);
		system("cls");
		printf("\n정렬 완료.\n");
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
		printf("\n> '0' 을 눌러 종료 <");
		printf("랜덤값 최대 숫자(50 ~ 100)를 입력하세요: ");
		scanf("%d", &maxRand);

		if (maxRand >= 1 && maxRand < 50 || maxRand > 100) {
			guide(1);
			continue;
		}
		else {

			random(&score, maxRand); // 배열에 무작위 숫자 배치 및 중복 제거
 
			printResult(&score); // 배열에 최초로 배치된 숫자 출력
	
			guide(2); // 배열 정렬 출력

			compare(&score); // 배열 정렬

			guide(3); // 배열 정렬 완료 출력

			printResult(&score); // 정렬 결과 출력

			file(&score); //정렬 결과 파일에 저장
		}
	}
	return 0;
}