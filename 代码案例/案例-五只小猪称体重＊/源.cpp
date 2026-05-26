#include <array>
#include <iostream>
#include <string>

struct Pig
{
    std::string name;
    int weight;
};

int main()
{
    const std::array<Pig, 5> pigs{{
        {"小猪甲", 245},
        {"小猪乙", 312},
        {"小猪丙", 278},
        {"小猪丁", 330},
        {"小猪戊", 296}
    }};

    const Pig* heaviest = &pigs.front();
    for (const Pig& pig : pigs)
    {
        std::cout << pig.name << "体重：" << pig.weight << std::endl;
        if (pig.weight > heaviest->weight)
        {
            heaviest = &pig;
        }
    }

    std::cout << "最重的是" << heaviest->name
              << "，体重为" << heaviest->weight << std::endl;
    return 0;
}
