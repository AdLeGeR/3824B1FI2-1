#include <stdio.h>
#include <math.h>
#include <locale.h>
main() {
	setlocale(LC_ALL, "RUS");
	//float r1=6, r2=2, O1x=7, O2x=14, O1y=5, O2y=8, sum, dist;
	float r1, r2, O1x, O2x, O1y, O2y, sum, dist;
	printf("������ ������ ����������(R, x, y):");
	scanf_s("%f%f%f", &r1, &O1x, &O1y);
	printf("������ ������ ����������(R, x, y):");
	scanf_s("%f%f%f", &r2, &O2x, &O2y);
	dist = sqrt(((O1x-O2x)*(O1x - O2x))+((O1y - O2y)*(O1y - O2y))); //������� ��������
	sum = r1 + r2;
	if (sum == dist) {
		printf("���������� �������� ���� �����!");
	}
	else {
		if (sum>dist) {
			printf("���������� ������������ � ���� ������!");
		}
		else {
			printf("���������� �� ������������!");
		}
	}
}