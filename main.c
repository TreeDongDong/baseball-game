#include<stdio.h>
#include<stdlib.h>
#include <time.h>
 
// 1. �õ� Ƚ�� �ʰ��� ���� ���� ( ����� ���� 20~30 )
// 2. �Է¹��� ���ڰ� 4�ڸ� �̻��̰ų� �ߺ����ڰ� ���� ���, �ٽ� �Է¹ޱ�

int main() {

	int arr[4] = {-1,};
	srand(time(NULL));
	for (int i = 0; i < 4; i++) {
		int num = rand() % 10;

		int isValid = 0;
		while (isValid == 0)
		{
			num = rand() % 10;
			isValid = 1; 
			for (int j = 0; j < i; j++) {
				if (num == arr[j]) {
					isValid = 0;
					break;
				}
			}
			
		}
		arr[i] = num;
	}
	int big = 0;
	int strikecount = 0;
	int trycount = 20;
	int isAnswer = 1;
	while (strikecount < 4)
	{
		if (trycount == 0)
		{
			isAnswer = 0;
			break;
		}
		printf("%dȸ ����\n", trycount);
		printf("�ߺ����� �ʴ� ���ڸ� ���ڸ� �Է��ϼ��� : ");
		scanf_s("%d", &big);
		trycount--;
		int a_arr[4] = { -1 };
		for (int i = 3; i>= 0; i--) {
			a_arr[i] = big % 10;
			big /= 10;
		}
	
		int ballCount = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (a_arr[i] == arr[j]) {
					ballCount++;
				}
			}
		}
		strikecount = 0;
		for (int i = 0; i < 4; i++) {
			if (a_arr[i] == arr[i]) {
				strikecount++;
			}
		}
		ballCount -= strikecount;

		printf("ball : %d, strike : %d\n", ballCount, strikecount);

	}
	if (isAnswer == 1) {
		printf("����");
	}
	else {
		printf("�õ� Ƚ�� �ʰ�");
	}
}