#include<stdio.h>
#include<math.h>
#include<locale.h>
int main() {
	setlocale(LC_ALL, "Rus");
	int r1, r2, d; /*r1 - ������ ������ ����������, r2 - ������ ������, d - ���������� ����� �������� ������ �����������*/
	r1 = 6;
	r2 = 10;
	d = 20;
	if (d == r1 + r2 || d == abs(r1 - r2)) {
		printf("���������� �������� � ����� �����");
	}
	if (d > abs(r1 - r2) && d < (r1 + r2)) {
		printf("���������� ������������ � ���� ������");

	}
	if (d > (r1 + r2) || d < abs(r1 - r2)) {
		printf("���������� �� ����� ����� �����");
	}
	return 0;
}