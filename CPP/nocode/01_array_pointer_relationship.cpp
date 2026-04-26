#include <iostream>
using namespace std;

int main() {
    // 3. 배열과 포인터의 관계 (Array & Pointer Relationship)
    int arr[3] = {10, 20, 30};

    cout << "--- Array & Pointer Relationship ---" << endl;
    cout << "Array name 'arr' itself is a pointer (address): " << arr << endl;
    cout << "Address of arr[0]: " << &arr[0] << endl;
    cout << "Address of arr[1]: " << &arr[1] << " (4 bytes after arr[0])" << endl;

    // Pointer access
    cout << "\nAccessing using index vs pointer arithmetic:" << endl;
    cout << "arr[0] = " << arr[0] << " | *(arr + 0) = " << *(arr + 0) << endl;
    cout << "arr[1] = " << arr[1] << " | *(arr + 1) = " << *(arr + 1) << endl;
    cout << "arr[2] = " << arr[2] << " | *(arr + 2) = " << *(arr + 2) << endl;

    // Pointer variable pointing to array
    int* ptr = arr;
    cout << "\nUsing a pointer variable 'ptr':" << endl;
    cout << "ptr[1] = " << ptr[1] << endl;
    cout << "*(ptr + 1) = " << *(ptr + 1) << endl;

    return 0;
}
