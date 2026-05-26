#include <iostream>

class Cube
{
public:
    Cube(double length, double width, double height)
        : length_(length), width_(width), height_(height)
    {
    }

    double area() const
    {
        return 2.0 * (length_ * width_ + length_ * height_ + width_ * height_);
    }

    double volume() const
    {
        return length_ * width_ * height_;
    }

    bool has_same_size(const Cube& other) const
    {
        return length_ == other.length_
            && width_ == other.width_
            && height_ == other.height_;
    }

private:
    double length_;
    double width_;
    double height_;
};

bool is_same_cube(const Cube& first, const Cube& second)
{
    return first.has_same_size(second);
}

int main()
{
    const Cube first(3.0, 4.0, 5.0);
    const Cube second(3.0, 4.0, 5.0);

    std::cout << "立方体表面积：" << first.area() << std::endl;
    std::cout << "立方体体积：" << first.volume() << std::endl;
    std::cout << "成员函数比较：" << (first.has_same_size(second) ? "相同" : "不同") << std::endl;
    std::cout << "全局函数比较：" << (is_same_cube(first, second) ? "相同" : "不同") << std::endl;
    return 0;
}
