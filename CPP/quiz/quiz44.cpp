// #include <iostream>
// #include <string>
// #include <vector>
// #include <algorithm>

// //이름을 입력받아 가장 뒤에 나오는 문자열을 출력하시오.
// //단 stl 문법을 사용하여야 함.

// int main() {

//     std::vector<std::string> strVec;

//     for(int i=0;i<5;i++) {
//         std::string name;
//         std::getline(std::cin, name);
//         strVec.push_back(name);
//     }
//     std::cout << "==================================" << std::endl;
//     std::sort(strVec.begin(), strVec.end());
//     std::cout << "사전에서 가장 뒤에 나오는 이름 : " << strVec.back() << std::endl;
    
    
//     return 0;
// }


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

int main()
{
    list<string> strList;
    string str;

    auto it = strList.begin();
    for(int i = 0; i < 5; i++)
    {
        cout << "이름 >> ";
        getline(cin, str);
        strList.insert(it++, str);
    }
    cout << endl;

    strList.sort();

    cout << "사전에서 가장 뒤에 나오는 문자열은 " << *it << endl;

    return 0;
}
