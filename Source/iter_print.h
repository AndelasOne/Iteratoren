
#ifndef ITERATOREN_ITER_PRINT_H
#define ITERATOREN_ITER_PRINT_H

#include <cmath>
#include <iostream>
//copy assignment
// operatoren: !=, ++, *()
// vector.begin() vector.end() returns iterator
namespace Print
{
    template<typename T>
    void print(const T begin, const T end) {
        for (T pos = begin; pos != end; pos++) {
            std::cout << *pos << std::endl;
        }

    }

    template<typename Container>
    void print(Container const &c) {
        print(c.begin(), c.end());
    }

    template<typename Container>
    void print_half(Container const &c) {
        print(c.begin(), c.begin() + std::ceil(c.size() / 2));
    }

    //cout overload to print values in the container
    template <typename T>
    void operator <<(std::ostream & out, T const & container){
        print(container);
    }
}
#endif //ITERATOREN_ITER_PRINT_H
