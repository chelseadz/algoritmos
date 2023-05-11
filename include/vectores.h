#ifndef VECTORES_H_INCLUDED
#define VECTORES_H_INCLUDED

template <typename T>
void randomArray(T arr[], unsigned long int len) {
    std::mt19937 gen(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<T> dist(1, 100);
    for(unsigned long int i = 0; i<len; i++)
    {
        arr[i] = dist(gen);
    }
}

#endif // VECTORES_H_INCLUDED
