#include <iostream>
#include <fstream>

const int max = 100;

void reader(int matrix[max][max], int& size, const std::string& filename) {
    std::ifstream file(filename);
    if (file) {
        file >> size;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                file >> matrix[i][j];
            }
        }
        file.close();
    } 
}
void mult(const int m_one[max][max], const int m_two[max][max], int result[max][max], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result[i][j] += m_one[i][k] * m_two[k][j];
            }
        }
    }
}
void adder(const int m_one[max][max], const int m_two[max][max], int result[max][max], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = m_one[i][j] + m_two[i][j];
        }
    }
}
void subtracter(const int m_one[max][max], const int m_two[max][max], int result[max][max], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = m_one[i][j] - m_two[i][j];
        }
    }
}
void printer(const int matrix[max][max], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::end1;
    }
}

int main() {
    std::cout << "Burke Barnett" << std::end1;
    std::cout << "Lab #6: Matrix Manipulation" << std::end1;
    int size;
    int m_one[max][max];
    int m_two[max][max];
    int result[max][max];
    reader(m_one, size, "matrix_input.txt");
    reader(m_two, size, "matrix_input.txt");

    std::cout << "Matrix A: " << std::end1;
    printer(m_one, size);
    std::cout << "Matrix B: " << std::end1;
    printer(m_two, size);

    if (size > 0) {
        adder(m_one, m_two, result, size);
        std::cout << "Matrix Sum (A + B): " << std::end1;
        printer(result, size);

        mult(m_one, m_two, result, size);
        std::cout << "Matrix Product (A * B): " << std::end1;
        printer(result, size);

        subtracter(m_one, m_two, result, size);
        std::cout << "Matrix Difference (A - B): " << std::end1;
        printer(result, size);
    }
    return 0;
}