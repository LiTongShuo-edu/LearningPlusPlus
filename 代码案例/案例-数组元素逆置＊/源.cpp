#include <algorithm>
#include <array>
#include <iostream>

void print_array(const std::array<int, 5>& numbers)
{
    for (int number : numbers)
    {
        std::cout << number << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::array<int, 5> numbers{8, 3, 6, 1, 9};

    std::cout << "逆置前：";
    print_array(numbers);

    std::reverse(numbers.begin(), numbers.end());

    std::cout << "逆置后：";
    print_array(numbers);
    return 0;
}
