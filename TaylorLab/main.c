#include <stdio.h>
#include <locale.h>
#include <math.h>
#include "Structs.h"
#include "MyMath.h"
#include "ExtraTools.h"


void main() {
	setlocale(LC_ALL, "Russian");

	for (;;) {

		/*-------------------------------Выбор функции----------------------------------------------------------------*/

		printf_s("\nВыберите функцию: \n");

		printf("\t%d. f(x) = e^x (Экспонента)\n", FunctionTypeNum.exp);
		printf("\t%d. f(x) = sin(x) (Синус)\n", FunctionTypeNum.sin);
		printf("\t%d. f(x) = cos(x) (Косинус)\n", FunctionTypeNum.cos);
		printf("\t%d. f(x) = ln(x), x = (0, 2] (Натуральный логарифм)\n", FunctionTypeNum.ln);

		uint8_t chosen_func_type;
		scanf_s("%"SCNu8, &chosen_func_type);

		typedef double (*t_MyMathFuncPointer) (double x, int terms_count);		/*Тип указателя на функцию с применением рядов Тейлора*/
		typedef double (*t_OriginalMathFuncPointer) (double x);					/*Тип казателя на функцию из библиотеки math.h*/

		t_MyMathFuncPointer MyMathFuncPointer;						/*Создаем переменные соотвествующих типов*/
		t_OriginalMathFuncPointer OriginalMathFuncPointer;


		if (chosen_func_type == FunctionTypeNum.exp) {
			MyMathFuncPointer = &exp_pr;						/*Присваиваем указателям на функции соответствующие адреса*/
			OriginalMathFuncPointer = &exp;
		}

		else if (chosen_func_type == FunctionTypeNum.sin) {
			MyMathFuncPointer = &sin_pr;
			OriginalMathFuncPointer = &sin;
		}

		else if (chosen_func_type == FunctionTypeNum.cos) {
			MyMathFuncPointer = &cos_pr;
			OriginalMathFuncPointer = &cos;
		}

		else if (chosen_func_type == FunctionTypeNum.ln) {
			MyMathFuncPointer = &ln_pr;
			OriginalMathFuncPointer = &log;
		}

		else {
			printf_s("Неверно указан номер функции!");
			continue;
		}
		/*--------------------------------------------------------------------------------------------------------------*/

		/*------------------------------------Ввод аргумента функции----------------------------------------------------*/

		printf_s("Введите аргумент для функции: ");
		double chosen_x;
		scanf_s("%lf", &chosen_x);
		/*--------------------------------------------------------------------------------------------------------------*/

		/*-----------------------------Ввод количества слагаемых в разложении Тейлора----------------------------------------*/

		printf_s("Введите количество слагаемых для разложения Тейлора: ");
		int chosen_terms_count;
		scanf_s("%d", &chosen_terms_count);
		/*--------------------------------------------------------------------------------------------------------------*/

		//printf_s("Формула Тейлора: %lf \n", (*MyMathFuncPointer)(chosen_x, chosen_terms_count));
		//printf_s("Формула из math.h: %lf \n", (*OriginalMathFuncPointer)(chosen_x));

		/*--------------------------------------------Ввод параметров таблицы--------------------------------------------*/

		printf_s("Введите шаг увеличения x: ");
		double chosen_step;
		scanf_s("%lf", &chosen_step);

		printf_s("Введите количество строк в таблице: ");
		int chosen_rows_count;
		scanf_s("%d", &chosen_rows_count);

		/*------------------------------------------------------------------------------------------------------------------*/
		printTable(chosen_x, chosen_step, chosen_terms_count, chosen_rows_count, MyMathFuncPointer, OriginalMathFuncPointer);

	}
}