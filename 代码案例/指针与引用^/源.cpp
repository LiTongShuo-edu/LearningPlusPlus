#include <iostream>
#include <string>

void mark_as_checked(std::string& status)
{
    status = "已检查";
}

void print_measurement(const int* measurement)
{
    if (measurement == nullptr)
    {
        std::cout << "测量值指针为空，无法读取。" << std::endl;
        return;
    }

    std::cout << "测量值：" << *measurement << std::endl;
}

int main()
{
    int exposure = 80;
    int* exposure_pointer = &exposure;
    std::string status = "待检查";

    std::cout << "变量地址已保存到指针。" << std::endl;
    print_measurement(exposure_pointer);

    *exposure_pointer = 85;
    mark_as_checked(status);

    std::cout << "修改后的测量值：" << exposure << std::endl;
    std::cout << "状态：" << status << std::endl;
    print_measurement(nullptr);
    return 0;
}
