#include <stdio.h>
#include <locale.h>
#include <math.h>
#include "Structs.h"
#include "MyMath.h"


void main() {
	setlocale(LC_ALL, "Russian");

	for (;;) {

		/*-------------------------------Выбор функции----------------------------------------------------------------*/

		printf_s("\nВыберите функцию: \n");
		uint8_t chosen_func_type;
		scanf_s("%"SCNu8, &chosen_func_type);

		double (*MyMathFuncPointer) (double x, int terms_count); /*Указатель на функцию с применением рядов Тейлора*/
		double (*OriginalMathFuncPointer) (double x); /*Указатель на функцию из библиотеки math.h*/

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
			printf_s("Неверно указан номер функции!");
			continue;
		}
		/*--------------------------------------------------------------------------------------------------------------*/

		/*------------------------------------Ввод аргумента функции----------------------------------------------------*/

		printf_s("Введите аргумент для функции: \n");
		double chosen_x;
		scanf_s("%lf", &chosen_x);
		/*--------------------------------------------------------------------------------------------------------------*/

		/*-----------------------------Ввод количества слагаемых в разложении Тейлора----------------------------------------*/

		printf_s("Введите количество слагаемых для разложения Тейлора: \n");
		int chosen_terms_count;
		scanf_s("%d", &chosen_terms_count);
		/*--------------------------------------------------------------------------------------------------------------*/

		printf_s("Формула Тейлора: %lf \n", (*MyMathFuncPointer)(chosen_x, chosen_terms_count));
		printf_s("Формула из math.h: %lf \n", (*OriginalMathFuncPointer)(chosen_x + 1));

	}
}