

#ifndef ITERATOREN_SORT_H
#define ITERATOREN_SORT_H


#include <algorithm>

namespace Sort {

    template <typename T>
    void change(T num1, T num2){
        auto temp = *num1;
        *num1 = *num2;
        *num2 = temp;
    }

    template<typename T>
    void sort(T begin, T end) {
        for (T repeat = end - 1; repeat >= begin; repeat--) {
            for (T element = begin; element < repeat; element++) {
                if (*element > *(element + 1)) {
                    change(element, element+1);
                }
            }
        }
    }

    template<typename Container>
    void sort(Container &cont) {
        Sort::sort(cont.begin(), cont.end());
    }

//defines comparison operator
    struct Greater {
        bool operator()(int i, int j) {
            return (i > j);
        }
    };


// using sort algorithm implemented in  the std_lib
    template<typename Container>
    void greater_sort(Container &c) {
        std::sort(c.begin(), c.end(), Greater());
    }

    template<typename IT>
    void quick_sort(IT begin, IT end) {
        // Quicksort Algorithm
    }

    template<typename T>
    void quick_sort(T &cont) {
        quick_sort(cont.begin(), cont.end());
    }
}
#endif //ITERATOREN_SORT_H
