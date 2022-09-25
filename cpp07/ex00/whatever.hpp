#if !defined(WHATEVER_CPP)
#define WHATEVER_CPP

#include <iostream>

template <typename T>
void swap(T &first, T &second){
    T aux;

    aux = first;
    first = second;
    second = aux;
}

template <typename T>
T min(T &first, T &second){
    if (first < second)
        return(first);
    return(second);
}

template <typename T>
T max(T &first, T &second){
    if (first > second)
        return(first);
    return(second);
}

#endif
