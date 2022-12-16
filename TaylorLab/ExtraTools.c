#include "ExtraTools.h"
#include <stdio.h>
#include <math.h>

void printTableLine(int char_count) {
	printf_s(" ");
	for (int i = 0; i < char_count; i++) {
		printf_s("-");
	}
	printf_s("\n");
}

void printTable(double start_x, double step, int terms_count, int rows_count, double(*MyMathFuncPointer)(double x, int terms_count), double(*OriginalMathFuncPointer)(double x)) {
	double max_err = 0;
	double max_err_x;
	printTableLine(87);
	printf_s("|\tx\t|\tf(x)\t\t|\tf_pr(x)\t\t|\tErr(x)\t\t|\n");
	printTableLine(87);
	for (int row_num = 0; row_num < rows_count; row_num++) {
		double cur_x = start_x + row_num * step;
		double cur_func_res = (*OriginalMathFuncPointer)(cur_x);
		double cur_func_pr_res = (*MyMathFuncPointer)(cur_x, terms_count);
		double cur_err = cur_func_res - cur_func_pr_res;
		
		printf_s("| %lf\t| %lf\t\t| %lf\t\t| %lf\t\t|\n", cur_x, cur_func_res, cur_func_pr_res, cur_err);
		if (fabs(cur_err) > fabs(max_err)) {
			max_err = cur_err;
			max_err_x = cur_x;
		}
	}
	printTableLine(87);
	printf_s("Максимальная ошибка: %lf, достигается при х = %lf\n", max_err, max_err_x);
}
