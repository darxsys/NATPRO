#include <stdio.h>
#include <malloc.h>
#include <math.h>

double distanceTwoPoints(double x1, double y1, double x2, double y2) {

	return pow(pow(x2 - x1, 2.) + pow(y2 - y1, 2.), 0.5);
}

double findMinDis(double Mx, double My, double a, double b, double xLeft, double xRight) {

	int i;
	double left = xLeft;
	double right = xRight;
	double x1, x2;
	double y1, y2;
	double distanceLeft, distanceRight;
	double distance;

	distanceLeft = distanceTwoPoints(left, a * left + b, Mx, My);
	distanceRight = distanceTwoPoints(right, a * right + b, Mx, My);

	distance = distanceLeft > distanceRight ? distanceRight : distanceLeft;

	for (i = 0; i < 1000; i++) {

		x1 = left + (right - left) / 3;
		x2 = right - (right - left) / 3;

		if (x1 > x2) {
			break;
		}

		y1 = a * x1 + b;
		y2 = a * x2 + b;

		distanceLeft = distanceTwoPoints(x1, y1, Mx, My);
		distanceRight = distanceTwoPoints(x2, y2, Mx, My);

		if (distanceLeft > distanceRight) {
			if (distance > distanceRight) {
				distance = distanceRight;
			}
			left = x1;

		} else {
			right = x2;
			if (distance > distanceLeft) {
				distance = distanceLeft;
			}
		}
	}

	return distance;
}

double findMinDisVertical(double x, double inY1, double inY2, double Mx, double My) {

	int i;
	double left = inY1;
	double right = inY2;
	double y1, y2;
	double distanceLeft, distanceRight;
	double distance;

	distanceLeft = distanceTwoPoints(x, left, Mx, My);
	distanceRight = distanceTwoPoints(x, right, Mx, My);

	distance = distanceLeft > distanceRight ? distanceRight : distanceLeft;

	for (i = 0; i < 1000; i++) {

		y1 = left + 0.333 * (right - left);
		y2 = right - 0.333 * (right - left);

		distanceLeft = distanceTwoPoints(x, y1, Mx, My);
		distanceRight = distanceTwoPoints(x, y2, Mx, My);

		if (distanceLeft > distanceRight) {
			if (distance > distanceRight) {
				distance = distanceRight;
			}
			left = y1;
		} else {
			right = y2;
			if (distance > distanceLeft) {
				distance = distanceLeft;
			} 
		}
	}

	return distance;
}

int main(void) {

	double Mx, My;
	double Px, Py, Kx, Ky;
	double a, b;
	double result;

	scanf("%lf %lf %lf %lf %lf %lf", &Mx, &My, &Px, &Py, &Kx, &Ky);

	if (fabs(Kx - Px) < 1e-12) {
		if (Py < Ky) {
			result = findMinDisVertical(Px, Py, Ky, Mx, My);
		} else {
			result = findMinDisVertical(Px, Ky, Py, Mx, My);
		}
	} else {

		a = (Ky - Py) / (Kx - Px);
		b = -Px * a + Py;

		if (Px < Kx) {
			result = findMinDis(Mx, My, a, b, Px, Kx);
		} else {
			result = findMinDis(Mx, My, a, b, Kx, Px);
		}
	}

	printf("%lf\n", result);
	return 0;
}