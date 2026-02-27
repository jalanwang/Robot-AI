#include <iostream>
#include <string>

int g=20;

int add(int x, int y)
{
    return x+y;
}

int main()
{
    int a, b, sum;
    std::cin >> a >> b;
    sum=a+b;
    std::cout <<sum << std::endl;

    return 0;
}

