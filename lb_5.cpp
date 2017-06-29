// lb_5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

typedef struct triangle {
	int x1, x2, x3, y1, y2, y3;
	float S;
};

triangle ostr(float x1, float y1, float x2, float y2, float x3, float y3) {
	triangle triangl;
	triangl.S = 0;
	triangl.x1 = x1; triangl.x2 = x2; triangl.x3 = x3;
	triangl.y1 = y1; triangl.y2 = y2; triangl.y3 = y3;
	float a, b, c, p, S;
	a = sqrt(powf((x2 - x1), 2) + (powf((y2 - y1), 2)));
	b = sqrt(powf((x3 - x2), 2) + (powf((y3 - y2), 2)));
	c = sqrt(powf((x3 - x1), 2) + (powf((y3 - y1), 2)));
	p = fabs((a + b + c)) / 2;
	if (powf(c,2)<powf(a,2)+powf(b,2)) {
		triangl.S = sqrt(p*(p - a)*(p - b)*(p - c));
	} 
	return triangl;
}

int main(){
	setlocale(0, "rus");
	int N;
	float M[2][20];
	triangle triangl, tmptriangl;
	triangl.S = 0;
	printf("введите количество точек\n");
	scanf("%d", &N);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < N; j++) {
			M[i][j] = -10 + rand() % 20;
			printf("%1.f\t", M[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				tmptriangl = ostr(M[0][i], M[1][i], M[0][j], M[1][j], M[0][k], M[1][k]);
				if (triangl.S < tmptriangl.S) {
					triangl = tmptriangl;
				}
			}
		}
	}
	printf("x1 - %d x2 - %d x3 - %d y1 - %d y2 - %d y3 - %d S - %f",triangl.x1, triangl.x2, triangl.x3, triangl.y1, triangl.y2, triangl.y3, triangl.S );
	system("pause");
    return 0;
}

