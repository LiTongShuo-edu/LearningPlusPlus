#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Beverage
{
public:
    virtual ~Beverage() = default;

    void prepare() const
    {
        std::cout << "\n开始制作" << name() << "：" << std::endl;
        boil_water();
        brew();
        pour();
        add_extra();
    }

protected:
    virtual std::string name() const = 0;
    virtual void brew() const = 0;
    virtual void add_extra() const = 0;

private:
    static void boil_water() { std::cout << "烧水" << std::endl; }
    static void pour() { std::cout << "倒入杯中" << std::endl; }
};

class Cocoa final : public Beverage
{
protected:
    std::string name() const override { return "可可饮品"; }
    void brew() const override { std::cout << "冲调可可粉" << std::endl; }
    void add_extra() const override { std::cout << "加入牛奶" << std::endl; }
};

class LemonTea final : public Beverage
{
protected:
    std::string name() const override { return "柠檬茶"; }
    void brew() const override { std::cout << "冲泡茶包" << std::endl; }
    void add_extra() const override { std::cout << "加入柠檬片" << std::endl; }
};

int main()
{
    std::vector<std::unique_ptr<Beverage>> drinks;
    drinks.push_back(std::make_unique<Cocoa>());
    drinks.push_back(std::make_unique<LemonTea>());

    for (const std::unique_ptr<Beverage>& drink : drinks)
    {
        drink->prepare();
    }
    return 0;
}
