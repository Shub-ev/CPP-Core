#include <iostream>
#include <string_view>

int main()
{
    std::string str {"This is string"};
    std::string_view s1 (str);
    std::cout << s1 << std::endl;

    str = "Another string!";
    std::cout << s1 << std::endl;

    return 0;
}
