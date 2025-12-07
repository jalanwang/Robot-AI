#include <iostream>
#include <string>

//string 
//getline으로 두 정수를 입력받아 
//삼각형의 넓이를 구하시오.
class Rectangle {
    private:
        int width;
        int height;
    public:
        template <typename T>
        T tirangleArea(T width, T height) {
        return (width * height) / 2;
        }   
        int getArea(int width, int height) {
            return (width * height) / 2;
        }
};


int main() {

    std::string width, height;
    std::getline(std::cin, width);
    std::getline(std::cin, height);

    Rectangle rect;

    int area = rect.getArea(std::stoi(width), std::stoi(height));
    //auto triangleArea = rect.tirangleArea<std::string>(std::stod(width), std::stod(height));
    //코드가 잘 안됨. stoi 말고 stod가 있을까?
    std::cout << "class 삼각형의 넓이: " << area << std::endl;
    
    //std::cout << "template 삼각형의 넓이: " << triangleArea << std::endl; 이넘도 
    
    return 0;
}
