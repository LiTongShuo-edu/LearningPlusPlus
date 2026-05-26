#include <array>
#include <iostream>
#include <string>

int main()
{
    const std::array<std::string, 3> students{"学生甲", "学生乙", "学生丙"};
    const std::array<std::array<int, 3>, 3> scores{{
        {86, 92, 88},
        {91, 85, 94},
        {78, 90, 83}
    }};

    for (std::size_t student = 0; student < students.size(); ++student)
    {
        int total = 0;
        for (int score : scores[student])
        {
            total += score;
        }
        std::cout << students[student] << "总分：" << total << std::endl;
    }

    return 0;
}
