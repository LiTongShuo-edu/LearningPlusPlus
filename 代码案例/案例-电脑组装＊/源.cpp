#include <iostream>
#include <memory>
#include <string>
#include <utility>

class Processor
{
public:
    virtual ~Processor() = default;
    virtual std::string run() const = 0;
};

class GraphicsCard
{
public:
    virtual ~GraphicsCard() = default;
    virtual std::string display() const = 0;
};

class Memory
{
public:
    virtual ~Memory() = default;
    virtual std::string store() const = 0;
};

class EfficientProcessor final : public Processor
{
public:
    std::string run() const override { return "节能处理器执行计算"; }
};

class PerformanceProcessor final : public Processor
{
public:
    std::string run() const override { return "高性能处理器执行计算"; }
};

class IntegratedGraphics final : public GraphicsCard
{
public:
    std::string display() const override { return "集成显卡输出图像"; }
};

class DedicatedGraphics final : public GraphicsCard
{
public:
    std::string display() const override { return "独立显卡输出图像"; }
};

class StandardMemory final : public Memory
{
public:
    std::string store() const override { return "标准内存保存数据"; }
};

class Computer
{
public:
    Computer(std::unique_ptr<Processor> processor,
             std::unique_ptr<GraphicsCard> graphics,
             std::unique_ptr<Memory> memory)
        : processor_(std::move(processor)),
          graphics_(std::move(graphics)),
          memory_(std::move(memory))
    {
    }

    void work(const std::string& label) const
    {
        std::cout << label << "开始工作：" << std::endl;
        std::cout << processor_->run() << std::endl;
        std::cout << graphics_->display() << std::endl;
        std::cout << memory_->store() << std::endl;
    }

private:
    std::unique_ptr<Processor> processor_;
    std::unique_ptr<GraphicsCard> graphics_;
    std::unique_ptr<Memory> memory_;
};

int main()
{
    const Computer office(
        std::make_unique<EfficientProcessor>(),
        std::make_unique<IntegratedGraphics>(),
        std::make_unique<StandardMemory>());
    const Computer workstation(
        std::make_unique<PerformanceProcessor>(),
        std::make_unique<DedicatedGraphics>(),
        std::make_unique<StandardMemory>());

    office.work("办公电脑");
    workstation.work("开发工作站");
    return 0;
}
