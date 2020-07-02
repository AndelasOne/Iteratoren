#include "iter_print.h"
#include "sort.h"
#include <vector>
#include "random_container.h"
int main() {


    //first version of container with random ints
    /*std::vector<int> v1 = Container::random_container<int>(5);
    print(v1);*/

    //template container of random ints
    std::vector<int> v3 = Container::random_container<int, std::vector>(5);
    print(v3);













    /*std::vector<int> test = {1111, 6, 5, 99 ,27, 12 ,4};
    print(test);


    Container::checksum_sort<std::vector<int>::iterator, int>(test.begin(), test.end());
    print(test);
    std::cout << Container::count_if(test, 1)<< std::endl;*/

    return 0;
}
