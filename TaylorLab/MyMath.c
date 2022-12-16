#include "MyMath.h"


double exp_pr(double x, int terms_count) {
	double sum = 1, last = 1;
	for(int i = 1; i <= terms_count; i++) {
		last = last * x / i;
		sum += last;
	}
	return sum;
}

double sin_pr(double x, int terms_count) {
	double sum = 0, last = x;
	for (int i = 0; i < terms_count; i++) {
		sum += last;
		last = (last * x * x * (-1)) / (2 * (i + 1) * (2 * (i + 1) + 1));
	}
	return sum;
}

double cos_pr(double x, int terms_count) {
	double sum = 0, last = 1;
	for (int i = 1; i <= terms_count; i++) {
		sum += last;
		last = last * (-x) * x / (2 * i * (2 * i - 1));
	}
	return sum;
}

double ln_pr(double x, int terms_count) {
	x -= 1; /*Уменьшаем x, т.к. расчет происходит для ln(1+x)*/
	double sum = 0, last_numerator = x;
	for (int i = 1; i <= terms_count; i++) {
		sum += last_numerator / i;
		last_numerator *= (-x);
	}
	return sum;
}

