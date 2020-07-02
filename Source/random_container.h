#include <cstdio>      /* printf, scanf, puts, NULL */
#include <random>     /* srand, rand */
#include <ctime>       /* time */
#include <vector>
#include <string>
#include <tuple>
#include "sort.h"

#ifndef ITERATOREN_RANDOM_CONTAINER_H
#define ITERATOREN_RANDOM_CONTAINER_H
namespace Container{

    // Container contains only random int values
    template<typename T>
    std::vector<T> random_container_test(size_t n) {
        std::vector<T> new_vector;
        std::random_device dv;
        std::default_random_engine randomEngine(dv());
        for (size_t element = 0; element < n; element++) {
            std::uniform_real_distribution<double> distribution(0, 50);
            T random_numb = distribution(randomEngine);

            new_vector.push_back(random_numb);
        }
        return new_vector;
    }


    // Specific Container only containing random int values
    // template parameter declaration has exactly
    // the number of arguments in the definition as the corresponding template class

    template<typename T, template <typename, typename> class Cont>
    Cont <T, std::allocator<T>> random_container(size_t n) {
        using INT_CONT = Cont<T, std::allocator<T>>;
        INT_CONT new_container ;
        for (size_t element = 0; element < n; element++) {
            int random_numb = rand();
            //only works with vectors
            new_container.push_back(random_numb);
        }
        return new_container;
    }





    template <typename INT_CONT, size_t N>
    INT_CONT create_container()
    {
        return INT_CONT();
    }

    template <>
    std::array<int, 5> create_container<std::array<int,5>,5>()
    {
        return std::array<int, 5>();
    }


    template <template<typename,typename> class Cont>
    Cont<int,std::allocator<int>> random_container_simple(size_t n)
    {
        Cont<int,std::allocator<int>> res(n);
        for (size_t i = 0; i < n; ++i)
        {
            res[i] = rand();
        }
        return res;
    }













    template<typename T>
    int calculate_checksum(T &number) {
        std::string s = std::to_string(number);
        int sum = 0;
        for (int pos = 0; pos < s.size(); pos++) {
            //46 is equal to "."
            if (s[pos] != 46 and s[pos] != 45)
                sum += s[pos] - 48;
        }
        return sum;
    }



    template<typename T>
    void checksum_sort_2(T begin, T end) {
        for (T repeat = end; repeat >= begin; repeat--) {
            for (T element = begin; element < repeat; element++) {
                if (calculate_checksum(*element) > calculate_checksum(*(element + 1))) {
                    Sort::change(element, element + 1);
                }
            }
        }
    }

    template<typename IT, typename type>
    void checksum_sort(IT begin, IT end) {
        std::vector<std::tuple<type, int>> checksums;
        for (IT element = begin; element < end; element++) {
            std::tuple<type, int> temp(*element, calculate_checksum(*element));
            checksums.push_back(temp);
        }
        for (int repeat = checksums.size(); repeat > 0; repeat--) {
            for (int element = 0; element < repeat; element++) {
                if (std::get<1>(checksums[element]) > std::get<1>(checksums[element + 1])) {
                    Sort::change(begin + element, begin + (element + 1));
                    Sort::change(checksums.begin() + element, checksums.begin() + (element + 1));
                }
            }
        }
    }

    template<typename Cont>
    void checksum_sort(Cont &c) {
        checksum_sort_2(c.begin(), c.end());
    }



//returns number of elements greater than x_value
    template<typename Cont>
    int count_if(Cont & c, int x_value) {
        return std::count_if(c.begin(), c.end(), [&x_value](int y) { return (y > x_value); });
    }

}

#endif //ITERATOREN_RANDOM_CONTAINER_H
