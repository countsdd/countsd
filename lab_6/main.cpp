#include <iostream>

// Пункт 1
int* findZeroes(int** matrix, int Rows, int Cols, int* zeroColsCount) {
    int* temp = (int*)malloc(Cols * sizeof(int));
    *zeroColsCount = 0;
    if (temp == NULL) {
        return NULL;
    }
    for (int j = 0; j < Cols; j++) {
        int isZero = 0;
        for (int i = 0; i < Rows; i++) {
            if (matrix[i][j] == 0) {
                isZero = 1;
                break;
            }
        }
        if (isZero) {
            temp[(*zeroColsCount)++] = j;
        }
    }


    int* zeroCols = (int*)malloc((*zeroColsCount) * sizeof(int));
    if (zeroCols == NULL) {
        free(temp);
        *zeroColsCount = 0;
        return NULL;
    }

    for (int i = 0; i < *zeroColsCount; i++) {
        zeroCols[i] = temp[i];
       
    }

    free(temp);
    return zeroCols;
}


int* deleteRows(int** matrix, int rows, int cols, int* zeroCols, int zeroColsCount, int* newCols) {
    *newCols = cols - zeroColsCount;


    int* newMatrix = (int*)malloc(rows *(*newCols)  * sizeof(int));
    if (newMatrix == NULL) {
        *newCols = 0;
        return NULL;
    }

    int newColIndex = 0;
    for (int j = 0; j < cols; j++) {

        bool skip = false;
        for (int k = 0; k < zeroColsCount; k++) {
            if (j == zeroCols[k]) {
                skip = true;
                break;
            }
        }

        if (skip == false) {

            for (int i = 0; i < rows; i++) {
                int newIndex = i * (*newCols) + newColIndex;
                newMatrix[newIndex] = matrix[i][j];
            }
            newColIndex++;
        }
    }

    return newMatrix;
}

int main(void) {
    int A, B, C, D;

    std::cout << "Enter A:" << std::endl;
    std::cin >> A;
    while (A < 0) {
        std::cout << "Incorrect input" << std::endl;
        std::cout << "Enter A:" << std::endl;
        std::cin >> A;
    }
    std::cout << "Enter B:" << std::endl;
    std::cin >> B;
    while (B < 0) {
        std::cout << "Incorrect input" << std::endl;
        std::cout << "Enter B:" << std::endl;
        std::cin >> B;
    }
    std::cout << "Enter C:" << std::endl;
    std::cin >> C;
    std::cout << "Enter D:" << std::endl;
    std::cin >> D;


    int** matrix = (int**)malloc(2 * sizeof(int*));
    for (int i = 0; i < 2; i++) {
        matrix[i] = (int*)malloc(2 * sizeof(int));
    }

    matrix[0][0] = A;
    matrix[0][1] = B;
    matrix[1][0] = C;
    matrix[1][1] = D;

    std::cout << "Original matrix:" << std::endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Создание расширенной матрицы
    int newRows = 2 + A;
    int newCols = 2 + B;

    int** newMatrix = (int**)malloc(newRows * sizeof(int*));
    for (int i = 0; i < newRows; i++) {
        newMatrix[i] = (int*)malloc(newCols * sizeof(int));
    }

    for (int i = 0; i < newRows; i++) {
        for (int j = 0; j < newCols; j++) {
            if (i < 2 && j < 2) {
                newMatrix[i][j] = matrix[i][j];
            }
            else {
                newMatrix[i][j] = (i - 1) * C + (j - 1) * D;
            }

        }
    }



    for (int i = 0; i < 2; i++) {
        free(matrix[i]);
    }
    free(matrix);

    std::cout << "New matrix:" << std::endl;
    for (int i = 0; i < newRows; i++) {
        for (int j = 0; j < newCols; j++) {
            std::cout << newMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }


    int zeroColsCount;
    int* zeroCols = findZeroes(newMatrix, newRows, newCols, &zeroColsCount);


    int finalCols;
    int* finalMatrix = deleteRows(newMatrix, newRows, newCols, zeroCols, zeroColsCount, &finalCols);


    for (int i = 0; i < newRows; i++) {
        free(newMatrix[i]);
    }
    free(newMatrix);
    std::cout << "New matrix without zeroes" << std::endl;
    if (finalMatrix != NULL) {
        for (int i = 0; i < newRows; i++) {
            for (int j = 0; j < finalCols; j++) {
                int index = i * finalCols + j;
                std::cout << finalMatrix[index] << " ";
            }
            std::cout << std::endl;
        }
        free(finalMatrix);
    }

    // Освобождаем zeroRows
    if (zeroCols != NULL) {
        free(zeroCols);
    }


    
    // Пункт 2
    float a1, b1;
    std::cout << "Enter A:" << std::endl;
    std::cin >> a1;
    std::cout << "Enter B:" << std::endl;
    std::cin >> b1;

    std::cout << "A: " << a1 << std::endl;
    std::cout << "B: " << b1 << std::endl;

    float* pa1 = new float(a1);
    float* pb1 = new float(b1);

    *pa1 *= 3;
    a1 = *pa1;
    std::cout << "New A: " << a1 << std::endl;

    float temp = *pa1;
    *pa1 = *pb1;
    *pb1 = temp;

    a1 = *pa1;
    b1 = *pb1;

    std::cout << "A: " << a1 << std::endl;
    std::cout << "B: " << b1 << std::endl;

    delete pa1;
    delete pb1;
    
}
