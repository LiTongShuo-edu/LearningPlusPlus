#include <array>
#include <iostream>
#include <string>

struct Hero
{
    std::string name;
    int age;
    std::string role;
};

void sort_by_age(std::array<Hero, 5>& heroes)
{
    for (std::size_t pass = 0; pass + 1 < heroes.size(); ++pass)
    {
        for (std::size_t index = 0; index + 1 < heroes.size() - pass; ++index)
        {
            if (heroes[index].age > heroes[index + 1].age)
            {
                Hero temporary = heroes[index];
                heroes[index] = heroes[index + 1];
                heroes[index + 1] = temporary;
            }
        }
    }
}

int main()
{
    std::array<Hero, 5> heroes{{
        {"岚", 29, "侦查"},
        {"川", 23, "防守"},
        {"星", 31, "支援"},
        {"禾", 20, "突击"},
        {"屿", 26, "分析"}
    }};

    sort_by_age(heroes);
    for (const Hero& hero : heroes)
    {
        std::cout << hero.name << "，年龄：" << hero.age
                  << "，职责：" << hero.role << std::endl;
    }
    return 0;
}
