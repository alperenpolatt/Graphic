#include <stdio.h>
#define M 20
#define N 20

// Here the parameter is a static 2D array
void InitWindowArray(char arr[M][N]) // or arr[][N]
{
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			arr[i][j] = '-';
		}
	}
}
void PrintWindowArray(char arr[M][N]) // or arr[][N]
{
	printf(" ");
	for (int j = 0; j < N; j++) {

		printf("%i", j%10);
	}
	printf("\n");

	for (int i = 0; i < M; i++) {
		printf("%i", i%10);
		for (int j = 0; j < N; j++) {
			
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
}

void PutStar(char * c) // or arr[][N]
{
		*c = '*';
}



void drawline(int x0, int y0, int x1, int y1, char arr[M][N])
{
	int dx, dy, p, x, y;

	dx = x1 - x0;
	dy = y1 - y0;

	x = x0;
	y = y0;

	p = 2 * dy - dx;

	while (x < x1)
	{
		if (p >= 0)
		{
			PutStar(&arr[x][y]);
			y = y + 1;
			p = p + 2 * dy - 2 * dx;
		}
		else
		{
			PutStar(&arr[x][y]);
			p = p + 2 * dy;
		}
		x = x + 1;
	}
}

void main() {
	char window[M][N];
	char printedArr[M][N];
	
	InitWindowArray(window);
	drawline(1, 2, 12,12, window);// ab
	drawline(1, 2, 8,1, window);//ac
	
	drawline(8,1,12, 12, window);//cb
	

	//
	
	PrintWindowArray(window);
}





