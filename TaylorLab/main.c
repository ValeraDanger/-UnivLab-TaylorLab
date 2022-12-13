#include <stdio.h>
#include <locale.h>
#include <math.h>
#include "Structs.h"
#include "MyMath.h"


void main() {
	setlocale(LC_ALL, "Russian");

	for (;;) {

		/*-------------------------------����� �������----------------------------------------------------------------*/

		printf_s("\n�������� �������: \n");
		uint8_t chosen_func_type;
		scanf_s("%"SCNu8, &chosen_func_type);

		double (*MyMathFuncPointer) (double x, int terms_count); /*��������� �� ������� � ����������� ����� �������*/
		double (*OriginalMathFuncPointer) (double x); /*��������� �� ������� �� ���������� math.h*/

		if (chosen_func_type == FunctionTypeNum.exp) {
			MyMathFuncPointer = exp_pr;
			OriginalMathFuncPointer = exp;
		}

		else if (chosen_func_type == FunctionTypeNum.sin) {
			MyMathFuncPointer = sin_pr;
			OriginalMathFuncPointer = sin;
		}

		else if (chosen_func_type == FunctionTypeNum.cos) {
			MyMathFuncPointer = cos_pr;
			OriginalMathFuncPointer = cos;
		}

		else if (chosen_func_type == FunctionTypeNum.ln) {
			MyMathFuncPointer = ln_pr;
			OriginalMathFuncPointer = log;
		}

		else {
			printf_s("������� ������ ����� �������!");
			continue;
		}
		/*--------------------------------------------------------------------------------------------------------------*/

		/*------------------------------------���� ��������� �������----------------------------------------------------*/

		printf_s("������� �������� ��� �������: \n");
		double chosen_x;
		scanf_s("%lf", &chosen_x);
		/*--------------------------------------------------------------------------------------------------------------*/

		/*-----------------------------���� ���������� ��������� � ���������� �������----------------------------------------*/

		printf_s("������� ���������� ��������� ��� ���������� �������: \n");
		int chosen_terms_count;
		scanf_s("%d", &chosen_terms_count);
		/*--------------------------------------------------------------------------------------------------------------*/

		printf_s("������� �������: %lf \n", (*MyMathFuncPointer)(chosen_x, chosen_terms_count));
		printf_s("������� �� math.h: %lf \n", (*OriginalMathFuncPointer)(chosen_x + 1));

	}
}