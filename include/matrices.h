#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <random>
#include <chrono>
#include <iomanip>

template <typename T>
using Matrix = std::vector<std::vector<T>>;

template <typename T>
void printMatrix(Matrix<T>& matrix) {
  int rows = matrix.size();
  int cols = matrix[0].size();

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

template <typename T>
Matrix<T> createZeroMatrix(int rows, int cols) {
  Matrix<T> matrix(rows, std::vector<T>(cols));

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      matrix[i][j] = 0;
    }
  }

  return matrix;
}

#include <type_traits>

template <typename T>
Matrix<T> createRandomMatrix(int rows, int cols) {
  Matrix<T> matrix(rows, std::vector<T>(cols));

  std::mt19937 gen(std::chrono::system_clock::now().time_since_epoch().count());
  typename std::conditional<std::is_integral<T>::value,
            std::uniform_int_distribution<T>,
            std::uniform_real_distribution<T>>::type dist(1,100);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      matrix[i][j] = dist(gen);
    }
  }

  return matrix;
}

template <typename T>
void printVector(Vec<T>& v) {
  int sz = v.size();

  for (int i = 0; i < sz; i++) {
      std::cout << std::setprecision(4) << v[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
Vec<T> createZerosVector(int sz) {
  Vec<T> v(sz);
  for (int i = 0; i < sz; i++){
      v[i] = 0;
  }
  return v;
}

template <typename T>
Vec<T> createRandomVector(int sz) {
  Vec<T> v(sz);

  std::mt19937 gen(std::chrono::system_clock::now().time_since_epoch().count());
  typename std::conditional<std::is_integral<T>::value,
            std::uniform_int_distribution<T>,
            std::uniform_real_distribution<T>>::type dist(1,100);

  for (int i = 0; i < sz; i++){
      v[i] = dist(gen);
  }

  return v;
}
#endif // MATRICES_H_INCLUDED
