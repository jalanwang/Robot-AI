 #include <iostream>
 
 template <class T>
 T bigger(T a, T b)
 {
    return (a>b) ? a:b;
 }

 int main() {
    int a=3;
    int b=5;


    std::cout << bigger(a,b) << std::endl;
 }

// #include <iostream>
// #include <memory>

// template <typename T>
// T bigger (T a, T b)
// {
//     return (a > b) ? a : b;
// }

// int main() {
//     int a=4;
//     int b=5;

//     std::cout <<bigger(a,b) << std::endl;

//     char c='A';
//     char d='B';
//     std::cout <<bigger(c,d) << std::endl;
    
//     return 0;
// }