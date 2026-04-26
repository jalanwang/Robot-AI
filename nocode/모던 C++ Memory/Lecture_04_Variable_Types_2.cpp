#include <iostream>
#include <iomanip>
#include <cstdint>
using namespace std;

int main() {
    // 5. 변수 타입 in 메모리 #2 (Variable Types in Memory #2)
    
    // 1) Signed vs Unsigned
    int8_t s_val = -1;
    uint8_t u_val = 255;
    
    cout << "--- Signed vs Unsigned ---" << endl;
    cout << "Signed -1 as hex: 0x" << hex << (int)(uint8_t)s_val << endl;
    cout << "Unsigned 255 as hex: 0x" << hex << (int)u_val << endl;
    cout << "(Same bit pattern: 1111 1111)" << endl;

    // 2) Endianness (Little Endian vs Big Endian)
    uint32_t val = 0x12345678;
    uint8_t* p = (uint8_t*)&val;

    cout << "\n--- Endianness Check ---" << endl;
    cout << "Value: 0x12345678" << endl;
    cout << "Memory layout (byte by byte):" << endl;
    for(int i=0; i<4; i++) {
        cout << "Addr[" << i << "]: 0x" << setfill('0') << setw(2) << hex << (int)p[i] << endl;
    }
    
    if (p[0] == 0x78) {
        cout << "Result: This system is Little Endian." << endl;
    } else {
        cout << "Result: This system is Big Endian." << endl;
    }

    return 0;
}
