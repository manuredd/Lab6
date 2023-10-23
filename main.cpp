#include <iostream>
#include <fstream>
#include <iomanip>

const int MAX_SIZE = 100;

void readMatrixFromFile(int matrix[MAX_SIZE][MAX_SIZE], int &size, const char *filename);
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size);
void addMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);
void multiplyMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);
void subtractMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);

int main() {
    int sizeA, sizeB;
    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];
    int resultSum[MAX_SIZE][MAX_SIZE];
    int resultProduct[MAX_SIZE][MAX_SIZE];
    int resultDifference[MAX_SIZE][MAX_SIZE];

    readMatrixFromFile(matrixA, sizeA, "matrix_input.txt");
    readMatrixFromFile(matrixB, sizeB, "matrix_input.txt");

    std::cout << "Manu Redd" << std::endl;
    std::cout << "Lab #6: Matrix manipulation" << std::endl;

    std::cout << "Matrix A:" << std::endl;
    printMatrix(matrixA, sizeA);

    std::cout << "Matrix B:" << std::endl;
    printMatrix(matrixB, sizeB);

    if (sizeA != sizeB) {
        std::cerr << "Error: Matrices A and B must be of the same size for addition, subtraction, and multiplication." << std::endl;
        return 1;
    }

    addMatrices(matrixA, matrixB, resultSum, sizeA);
    std::cout << "Matrix Sum (A + B):" << std::endl;
    printMatrix(resultSum, sizeA);

    multiplyMatrices(matrixA, matrixB, resultProduct, sizeA);
    std::cout << "Matrix Product (A * B):" << std::endl;
    printMatrix(resultProduct, sizeA);

    subtractMatrices(matrixA, matrixB, resultDifference, sizeA);
    std::cout << "Matrix Difference (A - B):" << std::endl;
    printMatrix(resultDifference, sizeA);

    return 0;
}

void readMatrixFromFile(int matrix[MAX_SIZE][MAX_SIZE], int &size, const char *filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        file >> size;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                file >> matrix[i][j];
            }
        }
        file.close();
    } else {
        std::cerr << "Error: Unable to open the file." << std::endl;
        exit(1);
    }
}

void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << std::setw(3) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void addMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void multiplyMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

void subtractMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}
