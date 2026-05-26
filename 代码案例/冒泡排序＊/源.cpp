#include <algorithm>
#include <array>
#include <iostream>

void bubble_sort(std::array<int, 8>& numbers)
{
    for (std::size_t pass = 0; pass + 1 < numbers.size(); ++pass)
    {
        bool changed = false;
        for (std::size_t index = 0; index + 1 < numbers.size() - pass; ++index)
        {
            if (numbers[index] > numbers[index + 1])
            {
                std::swap(numbers[index], numbers[index + 1]);
                changed = true;
            }
        }
        if (!changed)
        {
            break;
        }
    }
}

int main()
{
    std::array<int, 8> numbers{18, 4, 25, 7, 11, 2, 16, 9};
    bubble_sort(numbers);

    std::cout << "排序结果：";
    for (int number : numbers)
    {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    return std::is_sorted(numbers.begin(), numbers.end()) ? 0 : 1;
}
