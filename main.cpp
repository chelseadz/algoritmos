#include <iostream>

#include <Algoritmos.h>
#include <matrices.h>
#include <iostream>
#include <sys/time.h>
#include <stdlib.h>
#include <cmath>

template <typename T>
using Vec = std::vector<T>;

template <typename T>
using Matrix = std::vector<Vec<T>>;


//////////////////////////////////////////////////////////////////////////////////////
/*                      Analisis evaluacion de polinomios                           */
template <typename T>
double tryEval(T (eval)(Vec<T>&,T), Vec<T> arr, int X)
{
    ///////////////////////////////////////////////
    // MEDICIÓN

    struct timeval inicio, fin;
    double time = 0;
    for(int j = 0; j<10; j++){
        gettimeofday(&inicio, NULL);;

        eval(arr,X);

        gettimeofday(&fin, NULL);;
        double time_taken = (double)(fin.tv_sec - inicio.tv_sec) + (double)(fin.tv_usec - inicio.tv_usec) / 1000000;
        time = time + time_taken*1000;
    }
    return time/10;
}

Vec<double> tryEvalByLen(int len, Vec<double>& temp)
{

    Vec<int> v = createRandomVector<int>(len);

    temp[0] = tryEval(EvaluaPolinomio1,v,1);

    temp[1] = tryEval(EvaluaPolinomio2,v,1);

    temp[2] = tryEval(EvaluaPolinomio3,v,1);

    temp[3] = tryEval(EvaluaPolinomio4,v,1);

    return temp;
}

void analizeEval()
{

    int cantSz = 15;

    Vec<double> times1 = createZerosVector<double>(cantSz);
    Vec<double> times2 = createZerosVector<double>(cantSz);
    Vec<double> times3 = createZerosVector<double>(cantSz);
    Vec<double> times4 = createZerosVector<double>(cantSz);

    Vec<double> temp = createZerosVector<double>(4);

    int len =10000;
    for(int i = 0; i<cantSz; i++){

        temp = tryEvalByLen(len, temp);

        times1[i] = temp[0];
        times2[i] = temp[1];
        times3[i] = temp[2];
        times4[i] = temp[3];

        std::cout << "Len: "<< len << std::endl;
        printVector(temp);

        len = len+10000;
    }

    std::cout << std::endl;
    std::cout << "Eval1: ";
    printVector(times1);
    std::cout << "Eval2: ";
    printVector(times2);
    std::cout << "Eval3: ";
    printVector(times3);
    std::cout << "Eval4: ";
    printVector(times4);
    std::cout << std::endl;
}


//////////////////////////////////////////////////////////////////////////////////////
/*                                 Analisis suma                                  */

template <typename T>
double trySum(T (sum)(Vec<T>&,T), Vec<T> arr, int len)
{
    ///////////////////////////////////////////////
    // MEDICIÓN

    struct timeval inicio, fin;
    double time = 0;
    for(int j = 0; j<10; j++){
        gettimeofday(&inicio, NULL);;

        sum(arr,len);

        gettimeofday(&fin, NULL);;
        double time_taken = (double)(fin.tv_sec - inicio.tv_sec) + (double)(fin.tv_usec - inicio.tv_usec) / 1000000;
        time = time + time_taken*1000; //segundos/100
    }
    return time/10;
}

Vec<double> trySumByLen(int len, Vec<double>& temp)
{
    Vec<int> v = createRandomVector<int>(len);

    temp[0] = trySum(sum, v, len);

    temp[1] = trySum(Rsum, v, len);

    return temp;
}

void analizeSum()
{

    int cantSz = 32;

    Vec<double> times1 = createZerosVector<double>(cantSz);
    Vec<double> times2 = createZerosVector<double>(cantSz);

    Vec<double> temp = createZerosVector<double>(2);

    int len =1000;
    for(int i = 0; i<cantSz; i++){

        temp = trySumByLen(len, temp);

        times1[i] = temp[0];
        times2[i] = temp[1];

        std::cout << "Len: "<< len << std::endl;
        printVector(temp);

        len = len+1000;
    }

    std::cout << std::endl;
    std::cout << "Sum: ";
    printVector(times1);
    std::cout << "Rsum: ";
    printVector(times2);
    std::cout << std::endl;

}
///////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////
/*                                 Analisis Add                                  */
template <typename T>
double tryAdd(Matrix<T>& a, Matrix<T>& b, Matrix<T>& c, int rows, int cols)
{
    ///////////////////////////////////////////////
    // MEDICIÓN

    struct timeval inicio, fin;
    double time = 0;
    for(int j = 0; j<1; j++){
        gettimeofday(&inicio, NULL);;

        add_matrices(a,b,c,rows,cols);

        gettimeofday(&fin, NULL);;
        double time_taken = (double)(fin.tv_sec - inicio.tv_sec) + (double)(fin.tv_usec - inicio.tv_usec) / 1000000;
        time = time + time_taken*10; //segundos
    }
    return time;
}

void analizeAdd(){

    int cantSz = 30;

    Vec<double> times1 = createZerosVector<double>(cantSz);

    double temp = 0;

    int len =1000;

    for(int i = 0; i<cantSz; i++){

        Matrix<int> a = createRandomMatrix<int>(len,len);
        Matrix<int> b = createRandomMatrix<int>(len,len);
        Matrix<int> result = createZeroMatrix<int>(len,len);

        temp = tryAdd(a,b,result,len,len);

        times1[i] = temp;

        std::cout << "Len: "<< len << std::endl;
        std::cout << temp << std::endl;

        len = len+1000;
    }

    std::cout << std::endl;
    std::cout << "Add matrices: ";
    printVector(times1);
    std::cout << std::endl;
}


///////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////
/*                                 Analisis transpose                                  */
template <typename T>
double tryTranspose(Matrix<T>& a, int n)
{
    ///////////////////////////////////////////////
    // MEDICIÓN

    struct timeval inicio, fin;
    double time = 0;
    for(int j = 0; j<1; j++){
        gettimeofday(&inicio, NULL);;

        Transpose(a,n);

        gettimeofday(&fin, NULL);;
        double time_taken = (double)(fin.tv_sec - inicio.tv_sec) + (double)(fin.tv_usec - inicio.tv_usec) / 1000000;
        time = time + time_taken*10;
    }
    return time/1;
}

void analizeTranspose(){

    int cantSz = 30;

    Vec<double> times1 = createZerosVector<double>(cantSz);

    double temp = 0;

    int len =1000;

    for(int i = 0; i<cantSz; i++){

        Matrix<int> a = createRandomMatrix<int>(len,len);

        temp = tryTranspose<int>(a,len);

        times1[i] = temp;

        std::cout << "Len: "<< len << std::endl;
        std::cout << temp << std::endl;

        len = len+1000;
    }

    std::cout << std::endl;
    std::cout << "Transpose matrix: ";
    printVector<double>(times1);
    std::cout << std::endl;
}

///////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
/*                                 Analisis multiply                                 */
template <typename T>
double tryMultiply(Matrix<T>& a, Matrix<T>& b, Matrix<T>& c, int m, int n, int p)
{
    ///////////////////////////////////////////////
    // MEDICIÓN

    struct timeval inicio, fin;
    double time = 0;
    for(int j = 0; j<1; j++){
        gettimeofday(&inicio, NULL);;

        multiply_matrices(a,b,c,m,n,p);

        gettimeofday(&fin, NULL);;
        double time_taken = (double)(fin.tv_sec - inicio.tv_sec) + (double)(fin.tv_usec - inicio.tv_usec) / 1000000;
        time = time + time_taken*1; //segundos
    }
    return time;
}

void analizeMultiply(){

    int cantSz = 30;

    Vec<double> times1 = createZerosVector<double>(cantSz);

    double temp = 0;

    int len =100;

    for(int i = 0; i<cantSz; i++){

        Matrix<int> a = createRandomMatrix<int>(len,len);
        Matrix<int> b = createRandomMatrix<int>(len,len);
        Matrix<int> result = createZeroMatrix<int>(len,len);

        temp = tryMultiply<int>(a,b,result,len,len,len);

        times1[i] = temp;

        std::cout << "Len: "<< len << std::endl;
        std::cout << temp << std::endl;

        len = len+100;
    }

    std::cout << std::endl;
    std::cout << "Multiply matrices: ";
    printVector(times1);
    std::cout << std::endl;
}

///////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////
/*                                 Analisis Permutaciones                                 */
template <typename T>
double tryPerm(Vec<T>& a, int k, int n)
{
    ///////////////////////////////////////////////
    // MEDICIÓN

    struct timeval inicio, fin;
    double time = 0;
    for(int j = 0; j<10; j++){
        gettimeofday(&inicio, NULL);;

        perm(a,k,n);

        gettimeofday(&fin, NULL);;
        double time_taken = (double)(fin.tv_sec - inicio.tv_sec) + (double)(fin.tv_usec - inicio.tv_usec) / 1000000;
        time = time + time_taken*10;
    }
    return time/10;
}


void analizePerm(){

    int cantSz = 10;

    Vec<double> timesworst = createZerosVector<double>(cantSz);

    double temp = 0;

    int len =2;
    for(int i = 0; i<cantSz; i++){

        Vec<int> v = createRandomVector<int>(len);

        temp = tryPerm(v,0,len);
        timesworst[i] = temp;

        std::cout << "Len: "<< len << std::endl;
        std::cout << temp << std::endl;

        len = len+1;
    }

    std::cout << std::endl;
    std::cout << "Worst case: ";
    printVector(timesworst);
    std::cout << std::endl;

}

///////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////
/*                                 Analisis Busquedas                                 */
template <typename T>
double trySearch(T (srch)(Vec<T>&,int,T), Vec<T> arr, int len, int X)
{
    ///////////////////////////////////////////////
    // MEDICIÓN

    struct timeval inicio, fin;
    double time = 0;
    for(int j = 0; j<10; j++){
        gettimeofday(&inicio, NULL);

        srch(arr,len,X);

        gettimeofday(&fin, NULL);;
        double time_taken = (double)(fin.tv_sec - inicio.tv_sec) + (double)(fin.tv_usec - inicio.tv_usec) / 1000000;
        time = time + time_taken*1000;
    }
    return time/10;
}

Vec<double> trySearchByLen(int len, Vec<double>& temp)
{
    Vec<int> v = createSortedVector<int>(len);

    temp[0] = trySearch(seqSearch,v, len, len); //peor caso no lo encuentra
    temp[1] = trySearch(seqSearch,v, len, 0);   //mejor caso lo encuentra al inicio
    temp[2] = trySearch(binSearch,v, len, len+1); //peor caso no lo encuentra
    temp[3] = trySearch(binSearch,v, len, 0);   //mejor caso lo encuentra al inicio
    temp[4] = trySearch(binarySearch,v, len, len+1);//peor caso no lo encuentra
    temp[5] = trySearch(binarySearch,v, len, 0); //mejor caso lo encuentra al inicio

    return temp;
}

void analizeSearch(){

    int cantSz = 10;

    Vec<double> timesSeqBest = createZerosVector<double>(cantSz);
    Vec<double> timesSeqWorst = createZerosVector<double>(cantSz);
    Vec<double> timesbinBest = createZerosVector<double>(cantSz);
    Vec<double> timesbinWorst = createZerosVector<double>(cantSz);
    Vec<double> timesBinaryBest = createZerosVector<double>(cantSz);
    Vec<double> timesBinaryWorst = createZerosVector<double>(cantSz);

    Vec<double> temp = createZerosVector<double>(6);

    int len =100000000;
    for(int i = 0; i<cantSz; i++){

        temp = trySearchByLen(len, temp);

        timesSeqWorst[i] = temp[0];
        timesSeqBest[i] = temp[1];
        timesbinWorst[i] = temp[2];
        timesbinBest[i] = temp[3];
        timesBinaryWorst[i] = temp[4];
        timesBinaryBest[i] = temp[5];

        std::cout << "Len: "<< len << std::endl;
        printVector(temp);

        len = len+10000000;
    }

    std::cout << std::endl;
    std::cout << "Sequential Best case: ";
    printVector(timesSeqBest);
    std::cout << "Sequential Worst case: ";
    printVector(timesSeqWorst);
    std::cout << "bin Best case: ";
    printVector(timesbinBest);
    std::cout << "bin Worst case: ";
    printVector(timesbinWorst);
    std::cout << "Binary Best case: ";
    printVector(timesBinaryBest);
    std::cout << "Binary Worst case: ";
    printVector(timesBinaryWorst);
    std::cout << std::endl;

}

///////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
/*                                 Analisis Magic                                  */
template <typename T>
double tryMagic(int n)
{
    ///////////////////////////////////////////////
    // MEDICIÓN

    struct timeval inicio, fin;
    double time = 0;
    for(int j = 0; j<1; j++){
        gettimeofday(&inicio, NULL);;

        magic(n);

        gettimeofday(&fin, NULL);;
        double time_taken = (double)(fin.tv_sec - inicio.tv_sec) + (double)(fin.tv_usec - inicio.tv_usec) / 1000000;
        time = time + time_taken*10;
    }
    return time;
}

void analizeMagic(){

    int cantSz = 30;

    Vec<double> times1 = createZerosVector<double>(cantSz);

    double temp = 0;

    int len =101;

    for(int i = 0; i<cantSz; i++){

        temp = tryMagic<int>(len);

        times1[i] = temp;

        std::cout << "Len: "<< len << std::endl;
        std::cout << temp << std::endl;

        len = len+20;
    }

    std::cout << std::endl;
    std::cout << "Magic times: ";
    printVector<double>(times1);
    std::cout << std::endl;
}

///////////////////////////////////////////////////////////////////////////////////////


int main(){

    system("pause");
    analizeMagic();
    system("pause");

    return 0;
}
