#ifndef ALGORITMOS_H_INCLUDED
#define ALGORITMOS_H_INCLUDED

#include <vector>


template <typename T>
using Vec = std::vector<T>;

template <typename T>
using Matrix = std::vector<Vec<T>>;

template <typename T>
T EvaluaPolinomio1(Vec<T>& P, T X){
    T s = P[0];
    int n = P.size();
    float xn;
    for(int i=0; i<n; i++){
        xn = 1;
        for(int j=1; j<i; j++){
            xn *= X;
        }
        s += P[i]*xn;
    }
    return s;
}

template <typename T>
T potencia(T X, int i){
    if(i==0) return 1;
    else if (i % 2 == 1) return X * potencia(X, i-1);
    else{
        T t = potencia(X, i/2);
        return t*t;
    }
}

template <typename T>
T EvaluaPolinomio2(Vec<T>& P, T X){
    T s = P[0];
    int n = P.size();
    for(int i=0; i<n; i++){
        s += P[i]* potencia(X,i);
    }
    return s;
}

template <typename T>
T EvaluaPolinomio3(Vec<T>& P, T X){
    T s = P[0], xn=1;
    int n = P.size();
    for(int i=0; i<n; i++){
        xn*=X;
        s+= P[i]*xn;
    }
    return s;
}

template <typename T>
T EvaluaPolinomio4(Vec<T>& P, T X){
    T s = 0;
    int n = P.size();
    for(int i=n; i>0; i--){
        s= P[i] + s*X;
    }
    return s;
}

template <typename T>
T sum(Vec<T>& A, int n){
    T s = 0;
    for(int i=1; i<n; i++){
        s+=A[i];
    }
    return s;
}

template <typename T>
T Rsum(Vec<T>&  A, int n){
    if(n<=0) return 0;
    else return Rsum(A,n-1) + A[n];
}

template <typename T>
void add_matrices(Matrix<T>& a, Matrix<T>& b, Matrix<T>& c, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

template <typename T>
void Transpose(Matrix<T>& a, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            int t = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = t;
        }
    }
}

template <typename T>
void multiply_matrices(Matrix<T>& a, Matrix<T>& b, Matrix<T>& c, int m, int n, int p) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            c[i][j] = 0;
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

template <typename T>
void perm(Vec<T>& a, int k, int n) {
    if (k == n) {

    } else {
        for (int i = k; i < n; i++) {
            swap(&a[k], &a[i]);
            perm(a, k+1, n);
            swap(&a[k], &a[i]);
        }
    }
}

template <typename T>
int seq_search(Vec<T>& a, int x, int n) {
    int i = n-1;
    a[0] = x;
    while(a[i] != x) {
        i--;
    }
    return i;
}


template <typename T>
int BinSearch(Vec<T>& a, int n, int x) {
    int low = 1, high = n + 1;
    while(low < high - 1) {
        int mid = (low + high) / 2;
        if(x < a[mid]) {
            high = mid;
        }
        else {
            low = mid;
        }
    }
    if(x == a[low]) {
        return low;
    }
    else {
        return 0;
    }
}

template <typename T>
int binarySearch(Vec<T>& a, int n, int x) {
    int low = 0;
    int high = n - 1;
    int mid;

    while (low <= high) {
        mid = (low + high)/2;

        if (x == a[mid]) {
            return mid;
        }
        else if (x < a[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return -1; // If x is not found in the array
}


void magic(int n) {
    if (n % 2 == 0) {
        printf("n is even\n");
        return;
    }

    int square[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            square[i][j] = 0;
        }
    }

    int i = 0, j = (n - 1) / 2;
    square[i][j] = 1;

    for (int key = 2; key <= n*n; key++) {
        int k = (i >= 1) ? (i - 1) : (n - 1);
        int l = (j >= 1) ? (j - 1) : (n - 1);
        if (square[k][l] >= 1) {
            i = (i + 1) % n;
        } else {
            i = k;
            j = l;
        }
        square[i][j] = key;
    }

    //printf("Magic Square of size %d:\n", n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //printf("%d ", square[i][j]);
            continue;
        }
        //printf("\n");
    }
}

#endif // ALGORITMOS_H_INCLUDED
