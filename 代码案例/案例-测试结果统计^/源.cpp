#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

struct TestResult
{
    std::string name;
    bool passed;
};

int main()
{
    const std::vector<TestResult> results{
        {"设备启动", true},
        {"图像采集", true},
        {"目标识别", true},
        {"异常输入处理", false},
        {"结果导出", true}
    };

    int passed_count = 0;
    std::vector<std::string> failed_cases;
    for (const TestResult& result : results)
    {
        if (result.passed)
        {
            ++passed_count;
        }
        else
        {
            failed_cases.push_back(result.name);
        }
    }

    const double pass_rate = 100.0 * passed_count / results.size();
    std::cout << "测试用例总数：" << results.size() << std::endl;
    std::cout << "通过数量：" << passed_count << std::endl;
    std::cout << "失败数量：" << failed_cases.size() << std::endl;
    std::cout << std::fixed << std::setprecision(1)
              << "通过率：" << pass_rate << "%" << std::endl;

    if (!failed_cases.empty())
    {
        std::cout << "失败项：" << std::endl;
        for (const std::string& name : failed_cases)
        {
            std::cout << "- " << name << std::endl;
        }
    }

    return 0;
}
