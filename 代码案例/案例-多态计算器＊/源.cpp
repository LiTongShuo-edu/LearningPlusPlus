#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Operation
{
public:
    virtual ~Operation() = default;
    virtual std::string name() const = 0;
    virtual double calculate(double left, double right) const = 0;
};

class Addition final : public Operation
{
public:
    std::string name() const override { return "加法"; }
    double calculate(double left, double right) const override { return left + right; }
};

class Subtraction final : public Operation
{
public:
    std::string name() const override { return "减法"; }
    double calculate(double left, double right) const override { return left - right; }
};

class Multiplication final : public Operation
{
public:
    std::string name() const override { return "乘法"; }
    double calculate(double left, double right) const override { return left * right; }
};

int main()
{
    std::vector<std::unique_ptr<Operation>> operations;
    operations.push_back(std::make_unique<Addition>());
    operations.push_back(std::make_unique<Subtraction>());
    operations.push_back(std::make_unique<Multiplication>());

    const double left = 12.0;
    const double right = 4.0;
    for (const std::unique_ptr<Operation>& operation : operations)
    {
        std::cout << operation->name() << "结果："
                  << operation->calculate(left, right) << std::endl;
    }
    return 0;
}
