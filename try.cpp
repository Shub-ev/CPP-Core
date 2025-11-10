#include <iostream>
#include <string_view>

class Ball
{
    private:
        std::string m_color {};
        int m_rad {};

    public:
        Ball(std::string color, double rad)
            : m_color(color), m_rad(rad)
        {}

        void printBall()
        {
            std::cout << "Color: " << m_color << "\nRadius: "
                << m_rad << std::endl;
        }
};

int main()
{
    Ball blue {"Blue", 10.0};
    blue.printBall();

    Ball pink {"Pink", 12.4};
    pink.printBall();

    return 0;
}
