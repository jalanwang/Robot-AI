#include <iostream>
using namespace std;

int main() {
    // 4. 변수 타입과 메모리 레이아웃 (Variable Types & Memory Layout)
    char c = 'A';
    int i = 100;
    double d = 3.14;

    cout << "--- Variable Types & Memory Layout ---" << endl;
    cout << "[char]   Value: " << c << ", Size: " << sizeof(c) << " byte, Address: " << (void*)&c << endl;
    cout << "[int]    Value: " << i << ", Size: " << sizeof(i) << " bytes, Address: " << &i << endl;
    cout << "[double] Value: " << d << ", Size: " << sizeof(d) << " bytes, Address: " << &d << endl;

    // Pointer arithmetic based on type size
    int arr[2] = {1, 2};
    cout << "\n[Pointer Arithmetic]" << endl;
    cout << "arr[0] address: " << &arr[0] << endl;
    cout << "arr[1] address: " << &arr[1] << " (Offset: " << (long)&arr[1] - (long)&arr[0] << " bytes)" << endl;

    return 0;
}
