//배열의 합을 구하여 리턴하는 제네릭 add() 함수 만들기 연습
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
    
// template <class T> T add(T data[], int n) {
//     T sum=0;
//     for(int i=0; i<n;i++)
//         sum+=data[i];
// return sum;
// }

// class Sum {
//     private:
    
//     public:
//     int sum(int data[], int b) {
//         int sum=0;
//         for(int i=0; i<b;i++)
//             sum+=data[i];
//         return sum;
//     }   
//     double sum(double ddata[], int b) {
//         double sum=0;
//         for(int i=0; i<b;i++)
//             sum+=ddata[i];
//         return sum;
//     }   
// };

int sum_func(int data[], int n) {
    int sum=0;
    for(int i=0; i<n;i++)
        sum+=data[i];
    return sum;
}
double sum_func(double ddata[], int n) {
    double sum=0;
    for(int i=0; i<n;i++)
        sum+=ddata[i];
    return sum;
}
  
int main() {
    // add add;

    int data[]={1,2,3,4,5};
    double ddata[]={1.2, 2.3, 3.4, 4.5, 5.6, 6.7};

    std::cout << "합계: data[]: " << sum_func(data,5) << std::endl;
    std::cout << "합계: ddata[]: " << sum_func(ddata,6) << std::endl;
    
    return 0;
}