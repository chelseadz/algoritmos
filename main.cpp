#include <iostream>

#include <Algoritmos.h>
#include <matrices.h>
#include <iostream>
#include <sys/time.h>
#include <stdlib.h>

template <typename T>
using Vec = std::vector<T>;

template <typename T>
using Matrix = std::vector<Vec<T>>;


template <typename T>
double tryEval(T (eval)(Vec<T>&,T), Vec<T> arr, int X)
{
    ///////////////////////////////////////////////
    // MEDICIÓN

    struct timeval inicio, fin;
    double time = 0;
    for(int j = 0; j<10; j++){
        gettimeofday(&inicio, NULL);;

        eval(arr,1);

        gettimeofday(&fin, NULL);;
        double time_taken = (double)(fin.tv_sec - inicio.tv_sec) + (double)(fin.tv_usec - inicio.tv_usec) / 1000000;
        time = time + time_taken*1000;
    }
    return time/10;

    /*
    struct timeval inicio, fin;
    gettimeofday(&inicio, NULL);

    eval(arr, X);

    gettimeofday(&fin, NULL);

    return (double)(fin.tv_sec - inicio.tv_sec) + (double)(fin.tv_usec - inicio.tv_usec) / 1000000;;
    */
}


#include <cmath>

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

    int cantSz = 25;

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

int main(){
    analizeEval();
    return 0;
}
