/* Матрицу заполнить последовательно идущими числами по спирали:
 1  2  3  4
12 13 14 15
11 16 15  6
10  9  8  7
*/

#include <stdio.h>   /* ввод - вывод */
#include <stdlib.h>  /* выделение памяти */
#include <time.h>    /* функции работы со временем */ 

#include "Spir.h"    /* прототипы наших функций */ 

int main()
{
    int nx, ny; /* кол-во столбцов и строк */
    int **A;  /* матрица */
    int i, smax;
    time_t t0; 
    float k;
    
    Input_nx_ny(&nx, &ny); /* Ввод nx и ny */
    Memory_for_A(nx, ny, &A); /* память для матрицы */
	smax = nx * ny;
    
    t0 = time(NULL); /* время от 00:00 1.01.1970 в секундах */
    for( i = 0; i < 1.e9/smax; i++ )
    {
        Initial_state_of_A(nx, ny, A); /* начальное состояние матрицы */
        Loop(nx, ny, A); /* решение с циклом */
    }
    printf("\nРешение с циклом. Время: %f мкс \n", (time(NULL)-t0)*0.001*smax);
    PrintResult(nx, ny, A); /* печать результата */
    
    t0 = time(NULL);
    for( i = 0; i < 1.e9/smax; i++ )
    {
        Initial_state_of_A(nx, ny, A); /* начальное состояние матрицы */
        Recursion(nx, ny, A); /* решение с рекурсией */
    }
    printf("\nРешение с рекурсией. Время: %f мкс \n", (time(NULL)-t0)*0.001*smax);
    PrintResult(nx, ny, A); /* печать результата */
    
    return 0;
}

void Input_nx_ny(int *nx, int *ny)
{   /* Ввод nx и ny */
    printf("Кол-во столбцов: ");
    scanf("%d", nx);
    printf("Кол-во строк: ");
    scanf("%d", ny);
    return;
}

void Memory_for_A(int nx, int ny, int ***A)
{   /* память для матрицы: (nx+2)x(ny+2) */
    int x, y;
    *A = (int**)malloc((nx+2)*sizeof(int*)); /* A - массив столбцов */
    for( x = 0; x < nx+2; x++ )
        *(*A+x) = (int*)malloc((ny+2)*sizeof(int)); /* каждый столбец - массив int*/
    return;    
}

void Initial_state_of_A(int nx, int ny, int **A)
{   /* начальное состояние матрицы */
    int x, y;
    for( x = 0; x < nx+2; x++)
        for( y = 0; y < ny+2; y++ )
            *(*(A+x)+y) = (x == 0 || x == nx+1 || y == 0 || y == ny+1 ? 1 : 0);
}

void PrintResult(int nx, int ny, int **A)
{   /* печать результата. "Рамку" из единиц не печатаю. */
    int x, y;
    for( y = 1; y < ny+1; y++ )
    {
        for( x = 1; x < nx+1; x++ )
            printf("%d\t", *(*(A+x)+y));
        printf("\n");
    };
}

void Loop(int nx, int ny, int **A)
{   /* решение с циклом */
    int s; /* текущее число для записи в матрицу */
    int x, y; /* текущая позиция */
    int v[] = {1,0}; /* вектор направления движения {dx, dy}. 
                        Ось x - вправо, ось y - вниз.  
                        Начальное значение - вправо: dx = 1, dy = 0 */
    for( s = 1, x = 1, y = 1; s <= nx*ny; NextXY(&x, &y, v, A), s++ ) 
        *(*(A+x)+y) = s; /* вписываю s в текущую ячейку */
}

void Recursion(int nx, int ny, int **A)
{   /* решение с рекурсией */
    int s; /* текущее число для записи в матрицу */
    int x = 1, y = 1; /* стартовая позиция */
    int v[] = {1,0}; /* вектор направления движения {dx, dy}. 
                        Ось x - вправо, ось y - вниз.  
                        Начальное значение - вправо: dx = 1, dy = 0 */
    Step(1, 1, 1, v, nx*ny, A);
}

void Step(int s, int x, int y, int *v, int smax, int **A)
{
	if( s <= smax )
	{
		*(*(A+x)+y) = s; /* вписываю s в текущую ячейку */
		NextXY(&x, &y, v, A );
		Step(s+1, x, y, v, smax, A);
	}
	else return;
}

void NextXY(int *x, int *y, int *v, int **A)
{   /* подготовка следующего шага */
    int w;
    if(*(*(A+(*x+v[0]))+(*y+v[1])) != 0)
    {
        w = v[1];
        v[1] = v[0];
        v[0] = -w;
    }
    *x += v[0];
    *y += v[1];
}





