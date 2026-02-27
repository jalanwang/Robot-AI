#include <iostream>

struct ST {
        int a;
        int b;
    };

int main() {
    int size = sizeof(ST);

    std::cout << size << std::endl;
    
    return 0;   

}