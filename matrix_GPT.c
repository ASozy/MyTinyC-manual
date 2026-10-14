#include <stdio.h>

int main(void)
{
    int rows, cols;
    int matrix[100][100]; /* максимальный размер 100x100 */

    printf("Введите количество строк: ");
    if (scanf("%d", &rows) != 1 || rows <= 0 || rows > 100) {
        printf("Некорректный размер строк.\n");
        return 1;
    }

    printf("Введите количество столбцов: ");
    if (scanf("%d", &cols) != 1 || cols <= 0 || cols > 100) {
        printf("Некорректный размер столбцов.\n");
        return 1;
    }

    /* Заполнение нулями */
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 0;
        }
    }

    /* Вывод матрицы */
    printf("\nМатрица %dx%d, заполненная нулями:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

