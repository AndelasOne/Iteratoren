#include <iostream>
#include "iter_print.h"
#include "sort.h"
#include <vector>
#include <list>
#include <deque>
#include "Timer.h"

#include "random_container.h"
int main() {


    //first version of container with random ints
    std::vector<double> v1 = Container::random_container_test<double>(5);
    Print::print(v1);



    //template container of random ints
    std::vector<int> v3 = Container::random_container<int, std::vector>(29999);
    //print(v3);

    std::list<int> v4 = Container::random_container<int, std::list>(29999);
    //print(v4);

    std::cout << "-------------Sorting Vector-------------"<< std::endl;
    std::cout << "Bubble sort: " << time_methode([&v3](){Sort::sort(v3.begin(), v3.end());}) << " ms."<< std::endl;;
    std::cout << "Quick sort: " <<  time_methode([&v3](){Sort::quickSort(v3.begin(), v3.end());}) << " ms."<< std::endl;

    std::cout << "-------------Sorting List-------------"<< std::endl;
    std::cout << "Bubble sort: " << time_methode([&v4](){Sort::sort(v4.begin(), v4.end());})<< " ms." << std::endl;
    std::cout << "Quick sort: " << time_methode([&v4](){Sort::quickSort(v4.begin(), v4.end());})<< " ms."<< std::endl;
   // print(v4);


    std::deque<int> v5 = Container::random_container<int, std::deque>(5999);
    //print(v5);












    /*std::vector<int> test = {1111, 6, 5, 99 ,27, 12 ,4};
    print(test);


    Container::checksum_sort<std::vector<int>::iterator, int>(test.begin(), test.end());
    print(test);
    std::cout << Container::count_if(test, 1)<< std::endl;*/

    return 0;
}
