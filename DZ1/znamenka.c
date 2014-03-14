#include <stdio.h>
#include <math.h>

int findDigit(long int position) {

	long int decade = 1;
	long int digitInDecade = 0;
	long int indexOfNumber = 0;
	long int number = 0;
	long int digitPosition = 0;
	long int digit;
	long int currentNoDigits = decade * 9 * (long int) pow(10, decade - 1);

	while (position - currentNoDigits  > 0) {

		decade++;
		position -= currentNoDigits;
		currentNoDigits = decade * 9 * (long int) pow(10, decade - 1);
	}

	// printf("position: %ld, decade: %ld\n", position, decade);
	indexOfNumber = (long int) ceil((float)position / (float)decade);

	// printf("indexOfNumber: %ld\n", indexOfNumber);
	number = (long int) pow(10, (decade - 1));
	// printf("Number: %ld\n", number);
	number += indexOfNumber - 1;
	// printf("Number: %ld\n", number);
	digitPosition = position % decade;
	digitPosition = digitPosition > 0 ? digitPosition : decade;

	while (decade - digitPosition > 0) {
		number /= 10;
		digitPosition++;
	}

	return number % 10;
}

int main(void) {

	long int X;
	scanf("%ld", &X);

	printf("%d\n", findDigit(X));

	return 0;
}