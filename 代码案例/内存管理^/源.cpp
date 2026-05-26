#include <iostream>

int main()
{
    const int sample_count = 4;
    int* samples = new int[sample_count]{21, 20, 22, 21};

    int total = 0;
    for (int index = 0; index < sample_count; ++index)
    {
        total += samples[index];
    }

    const double average = static_cast<double>(total) / sample_count;
    std::cout << "采样数量：" << sample_count << std::endl;
    std::cout << "平均值：" << average << std::endl;

    delete[] samples;
    samples = nullptr;
    std::cout << "动态数组已释放。" << std::endl;

    // 真实项目中优先使用标准容器或智能指针管理资源。
    return 0;
}
