#include <algorithm>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

class Worker
{
public:
    Worker(int id, std::string name) : id_(id), name_(std::move(name)) {}
    virtual ~Worker() = default;

    int id() const { return id_; }
    const std::string& name() const { return name_; }
    virtual int type() const = 0;
    virtual std::string position() const = 0;
    virtual std::string duty() const = 0;

    void show() const
    {
        std::cout << id_ << " | " << name_ << " | " << position()
                  << " | " << duty() << std::endl;
    }

private:
    int id_;
    std::string name_;
};

class Engineer final : public Worker
{
public:
    using Worker::Worker;
    int type() const override { return 1; }
    std::string position() const override { return "研发工程师"; }
    std::string duty() const override { return "实现功能模块"; }
};

class Tester final : public Worker
{
public:
    using Worker::Worker;
    int type() const override { return 2; }
    std::string position() const override { return "测试工程师"; }
    std::string duty() const override { return "设计并执行验证"; }
};

class Leader final : public Worker
{
public:
    using Worker::Worker;
    int type() const override { return 3; }
    std::string position() const override { return "项目负责人"; }
    std::string duty() const override { return "协调项目计划"; }
};

std::unique_ptr<Worker> make_worker(int id, const std::string& name, int type)
{
    if (type == 1)
    {
        return std::make_unique<Engineer>(id, name);
    }
    if (type == 2)
    {
        return std::make_unique<Tester>(id, name);
    }
    if (type == 3)
    {
        return std::make_unique<Leader>(id, name);
    }
    return nullptr;
}

class WorkerManager
{
public:
    bool add(int id, const std::string& name, int type)
    {
        if (index_of(id) >= 0)
        {
            return false;
        }
        std::unique_ptr<Worker> worker = make_worker(id, name, type);
        if (!worker)
        {
            return false;
        }
        workers_.push_back(std::move(worker));
        return true;
    }

    bool remove(int id)
    {
        const int index = index_of(id);
        if (index < 0)
        {
            return false;
        }
        workers_.erase(workers_.begin() + index);
        return true;
    }

    bool update(int id, const std::string& name, int type)
    {
        const int index = index_of(id);
        std::unique_ptr<Worker> replacement = make_worker(id, name, type);
        if (index < 0 || !replacement)
        {
            return false;
        }
        workers_[static_cast<std::size_t>(index)] = std::move(replacement);
        return true;
    }

    const Worker* find(int id) const
    {
        const int index = index_of(id);
        return index < 0 ? nullptr : workers_[static_cast<std::size_t>(index)].get();
    }

    void sort_by_id()
    {
        std::sort(workers_.begin(), workers_.end(),
            [](const std::unique_ptr<Worker>& left, const std::unique_ptr<Worker>& right) {
                return left->id() < right->id();
            });
    }

    void show_all() const
    {
        if (workers_.empty())
        {
            std::cout << "当前没有职工记录。" << std::endl;
        }
        for (const std::unique_ptr<Worker>& worker : workers_)
        {
            worker->show();
        }
    }

    bool save(const std::string& path) const
    {
        std::ofstream output(path);
        if (!output)
        {
            return false;
        }
        for (const std::unique_ptr<Worker>& worker : workers_)
        {
            output << worker->id() << "|" << worker->name()
                   << "|" << worker->type() << "\n";
        }
        return true;
    }

    bool load(const std::string& path)
    {
        std::ifstream input(path);
        if (!input)
        {
            return false;
        }
        workers_.clear();
        std::string line;
        while (std::getline(input, line))
        {
            std::istringstream record(line);
            std::string id_text;
            std::string name;
            std::string type_text;
            if (std::getline(record, id_text, '|')
                && std::getline(record, name, '|')
                && std::getline(record, type_text))
            {
                add(std::stoi(id_text), name, std::stoi(type_text));
            }
        }
        return true;
    }

    std::size_t size() const { return workers_.size(); }

private:
    int index_of(int id) const
    {
        for (std::size_t index = 0; index < workers_.size(); ++index)
        {
            if (workers_[index]->id() == id)
            {
                return static_cast<int>(index);
            }
        }
        return -1;
    }

    std::vector<std::unique_ptr<Worker>> workers_;
};

int run_demo(const std::string& path)
{
    WorkerManager manager;
    manager.add(103, "示例甲", 1);
    manager.add(101, "示例乙", 2);
    manager.add(102, "示例丙", 3);
    manager.sort_by_id();
    if (!manager.save(path))
    {
        return 1;
    }

    WorkerManager restored;
    if (!restored.load(path)
        || !restored.update(102, "示例丙", 2)
        || !restored.remove(103))
    {
        return 1;
    }

    std::cout << "文件读取、修改和删除后的职工记录：" << std::endl;
    restored.sort_by_id();
    restored.show_all();
    return restored.save(path) && restored.size() == 2 ? 0 : 1;
}

int read_number(const std::string& message)
{
    std::cout << message;
    int value = 0;
    std::cin >> value;
    return value;
}

std::string read_name()
{
    std::cout << "姓名：";
    std::string name;
    std::getline(std::cin >> std::ws, name);
    return name;
}

void show_menu()
{
    std::cout << "\n1.增加职工  2.显示职工  3.删除职工  4.修改职工\n"
              << "5.查找职工  6.按编号排序  7.保存文件  0.退出\n请选择：" << std::endl;
}

int main(int argc, char* argv[])
{
    const std::string path = argc > 2 ? argv[2] : "worker_records.txt";
    if (argc > 1 && std::string(argv[1]) == "--demo")
    {
        return run_demo(path);
    }

    WorkerManager manager;
    manager.load(path);
    while (true)
    {
        show_menu();
        int choice = 0;
        if (!(std::cin >> choice) || choice == 0)
        {
            manager.save(path);
            return 0;
        }
        if (choice == 1)
        {
            const int id = read_number("编号：");
            const std::string name = read_name();
            const int type = read_number("岗位类型（1研发/2测试/3负责人）：");
            std::cout << (manager.add(id, name, type) ? "添加成功。" : "添加失败。") << std::endl;
        }
        else if (choice == 2)
        {
            manager.show_all();
        }
        else if (choice == 3)
        {
            std::cout << (manager.remove(read_number("删除编号：")) ? "删除成功。" : "未找到编号。") << std::endl;
        }
        else if (choice == 4)
        {
            const int id = read_number("修改编号：");
            const std::string name = read_name();
            const int type = read_number("新岗位类型（1研发/2测试/3负责人）：");
            std::cout << (manager.update(id, name, type) ? "修改成功。" : "未找到编号。") << std::endl;
        }
        else if (choice == 5)
        {
            const Worker* worker = manager.find(read_number("查找编号："));
            if (worker)
            {
                worker->show();
            }
            else
            {
                std::cout << "未找到编号。" << std::endl;
            }
        }
        else if (choice == 6)
        {
            manager.sort_by_id();
            std::cout << "排序完成。" << std::endl;
        }
        else if (choice == 7)
        {
            std::cout << (manager.save(path) ? "文件保存成功。" : "文件保存失败。") << std::endl;
        }
    }
}
