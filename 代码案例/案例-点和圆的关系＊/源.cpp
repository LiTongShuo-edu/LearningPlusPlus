#include <cmath>
#include <iostream>
#include <string>

class Point
{
public:
    Point(double x, double y) : x_(x), y_(y) {}

    double distance_to(const Point& other) const
    {
        const double dx = x_ - other.x_;
        const double dy = y_ - other.y_;
        return std::sqrt(dx * dx + dy * dy);
    }

private:
    double x_;
    double y_;
};

class Circle
{
public:
    Circle(Point center, double radius) : center_(center), radius_(radius) {}

    std::string relation_to(const Point& point) const
    {
        const double distance = center_.distance_to(point);
        if (std::abs(distance - radius_) < 0.0001)
        {
            return "在圆上";
        }
        return distance < radius_ ? "在圆内" : "在圆外";
    }

private:
    Point center_;
    double radius_;
};

int main()
{
    const Circle circle(Point(0.0, 0.0), 5.0);
    const Point first(3.0, 4.0);
    const Point second(1.0, 1.0);
    const Point third(8.0, 0.0);

    std::cout << "点(3,4)：" << circle.relation_to(first) << std::endl;
    std::cout << "点(1,1)：" << circle.relation_to(second) << std::endl;
    std::cout << "点(8,0)：" << circle.relation_to(third) << std::endl;
    return 0;
}
