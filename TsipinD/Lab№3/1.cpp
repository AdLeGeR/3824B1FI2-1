#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int main() {
	setlocale(LC_ALL, "rus");
	int length;
	printf("������� ����� �����: \n");
	while (scanf_s("%d", &length) != 1 || length < 2 || length > 5) { // �������� ����� �����
		printf_s("����� ������ ��������� �������� �� 2 �� 5.\n");
		char c;
		while ((c = getchar()) != '\n' && (c != EOF)) {}
	}
	int *digits = (int*)malloc(length * sizeof(int));
	char flag = 0;
	srand(time(NULL));
	digits[0] = rand() % 10;  // �������� n-�������� ����� � ���������������� �������
	for (int i = 1; i < length; i++) { 
		while (flag == 0) {
			flag = 1;
			digits[i] = rand() % 10;
			for (int j = 0; j < i; j++) {
				if (digits[i] == digits[j]) {
					flag = 0; break;
				}
			}
		}
		flag = 0;
	}
	int positions=0, counter;
	char input[6];  // ���� 6 ������, ����� ��� ���������� ����� ��������� ����� ���� ������ (*)
	int valid;
	int num_digits;
	int *digits_ask = (int*)malloc(length * sizeof(int));
	char ch;
	ch = getchar();
	while (positions != length) {
		valid = 0;
		while (!valid) { // �������� �������� ����� ��������� �����
			num_digits = 0;
			positions = 0;
			counter = 0;
			while (ch != 'n') {
				if (num_digits == 0) {
					printf_s("������� �����: ");
				}
				ch = getchar();
				if (ch >= '0' && ch <= '9') {
					input[num_digits] = ch;
					num_digits++;
				}
				else if (ch == '\n') {
					if (num_digits == length) {
						break;
					}
					else {
						printf("�������� ����� ������ ���� ������ %d.\n", length);
						num_digits = 0;
					}
				}
			}
			if (num_digits == length) {
				valid = 1;
			}
		}
		for (int i = 0; i < length; i++) {
			digits_ask[i] = input[i] - '0';
		}
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < length; j++) {
				if (digits_ask[i] == digits[j]) {
					if (i == j) {
						positions++;
					}
					counter++;
					break;
				}
			}
		}
		if (positions == length) {
			printf_s("\n�� ������� �����!\n");
		}
		else {
			printf_s("�����: %d. �����: %d\n\n", counter, positions);
		}
	}
	free(digits);
	free(digits_ask);
	return 0;
}
