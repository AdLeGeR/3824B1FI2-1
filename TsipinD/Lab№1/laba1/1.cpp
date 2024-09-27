#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "");
    int h, w, d, k;
    float t1 = 0.5, t2 = 1.5, t3 = 1.5, t4 = 1., t5 = 1., m, r_wood = 0.52, r_dsp = 0.7, r_dvp = 0.8;

    printf("������� ������ ����� (180 - 220 ��):\n");
    printf("������� ������ ����� (80 - 120 ��):\n");
    printf("������� ������� ����� (50 - 90 ��):\n");

    do {
        k = scanf_s("%d %d %d", &h, &w, &d);
        char c;
        while ((c = getchar()) != '\n' && c != EOF) {}

        if (k != 3) {
            printf("������������ ������. ������� ��� �����.\n");
        }
        else if ((h < 180 || h > 220) || (w < 80 || w > 120) || (d < 50 || d > 90)) {
            printf("�������� �� � ���������� ���������. ���������� �����.\n");
        }

    } while (k != 3 || (h < 180 || h > 220) || (w < 80 || w > 120) || (d < 50 || d > 90));

    m = (h * w * t1) * r_dvp;
    m += 2 * (h * d * t2) * r_dsp;
    m += 2 * (w * d * t3) * r_dsp;
    m += 2 * (h * w * t4) * r_wood;
    m += ((int)(h / (40 + (int)t5))) * ((w - 2 * t2) * d * t5) * r_dsp;
    m = m / 1000;

    printf("����� ������� �����: %.2f ��\n", m);

    return 0;
}