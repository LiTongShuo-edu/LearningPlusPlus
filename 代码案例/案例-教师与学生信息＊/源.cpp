#include <array>
#include <iostream>
#include <string>

struct Student
{
    std::string name;
    int score;
};

struct Teacher
{
    std::string name;
    std::array<Student, 3> students;
};

int main()
{
    const std::array<Teacher, 2> teachers{{
        {"教师甲", {{{"学生A", 87}, {"学生B", 93}, {"学生C", 89}}}},
        {"教师乙", {{{"学生D", 90}, {"学生E", 84}, {"学生F", 96}}}}
    }};

    for (const Teacher& teacher : teachers)
    {
        std::cout << teacher.name << "指导的学生：" << std::endl;
        for (const Student& student : teacher.students)
        {
            std::cout << "  " << student.name << "，成绩：" << student.score << std::endl;
        }
    }

    return 0;
}
