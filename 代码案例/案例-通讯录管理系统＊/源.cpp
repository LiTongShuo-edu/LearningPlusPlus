#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Contact
{
    std::string name;
    std::string phone;
    std::string city;
};

class AddressBook
{
public:
    bool add(const Contact& contact)
    {
        if (find(contact.name) != nullptr)
        {
            return false;
        }
        contacts_.push_back(contact);
        return true;
    }

    const Contact* find(const std::string& name) const
    {
        const auto item = std::find_if(contacts_.begin(), contacts_.end(),
            [&name](const Contact& contact) { return contact.name == name; });
        return item == contacts_.end() ? nullptr : &*item;
    }

    bool remove(const std::string& name)
    {
        const auto old_size = contacts_.size();
        contacts_.erase(
            std::remove_if(contacts_.begin(), contacts_.end(),
                [&name](const Contact& contact) { return contact.name == name; }),
            contacts_.end());
        return old_size != contacts_.size();
    }

    bool update(const std::string& name, const Contact& replacement)
    {
        for (Contact& contact : contacts_)
        {
            if (contact.name == name)
            {
                contact = replacement;
                return true;
            }
        }
        return false;
    }

    void clear()
    {
        contacts_.clear();
    }

    void show() const
    {
        if (contacts_.empty())
        {
            std::cout << "通讯录为空。" << std::endl;
            return;
        }
        for (const Contact& contact : contacts_)
        {
            std::cout << contact.name << " | " << contact.phone
                      << " | " << contact.city << std::endl;
        }
    }

    std::size_t size() const
    {
        return contacts_.size();
    }

private:
    std::vector<Contact> contacts_;
};

int run_demo()
{
    AddressBook book;
    book.add({"示例甲", "100-0001", "北京"});
    book.add({"示例乙", "100-0002", "上海"});
    book.update("示例乙", {"示例乙", "100-0022", "杭州"});

    const Contact* result = book.find("示例乙");
    if (result == nullptr || result->city != "杭州")
    {
        return 1;
    }

    book.remove("示例甲");
    std::cout << "演示模式中的当前联系人：" << std::endl;
    book.show();
    book.clear();
    std::cout << "清空后记录数：" << book.size() << std::endl;
    return book.size() == 0 ? 0 : 1;
}

void show_menu()
{
    std::cout << "\n1. 添加联系人  2. 显示联系人  3. 删除联系人\n"
              << "4. 查找联系人  5. 修改联系人  6. 清空联系人  0. 退出\n"
              << "请选择：" << std::endl;
}

std::string input_text(const std::string& message)
{
    std::cout << message;
    std::string value;
    std::getline(std::cin >> std::ws, value);
    return value;
}

int main(int argc, char* argv[])
{
    if (argc > 1 && std::string(argv[1]) == "--demo")
    {
        return run_demo();
    }

    AddressBook book;
    while (true)
    {
        show_menu();
        int choice = 0;
        if (!(std::cin >> choice))
        {
            return 0;
        }
        if (choice == 0)
        {
            return 0;
        }
        if (choice == 1)
        {
            const Contact contact{
                input_text("姓名："), input_text("电话："), input_text("城市：")
            };
            std::cout << (book.add(contact) ? "添加成功。" : "姓名已存在。") << std::endl;
        }
        else if (choice == 2)
        {
            book.show();
        }
        else if (choice == 3)
        {
            std::cout << (book.remove(input_text("删除姓名：")) ? "删除成功。" : "未找到联系人。") << std::endl;
        }
        else if (choice == 4)
        {
            const Contact* contact = book.find(input_text("查找姓名："));
            if (contact == nullptr)
            {
                std::cout << "未找到联系人。" << std::endl;
            }
            else
            {
                std::cout << contact->name << " | " << contact->phone
                          << " | " << contact->city << std::endl;
            }
        }
        else if (choice == 5)
        {
            const std::string old_name = input_text("需要修改的姓名：");
            const Contact contact{
                input_text("新姓名："), input_text("新电话："), input_text("新城市：")
            };
            std::cout << (book.update(old_name, contact) ? "修改成功。" : "未找到联系人。") << std::endl;
        }
        else if (choice == 6)
        {
            book.clear();
            std::cout << "通讯录已清空。" << std::endl;
        }
    }
}
