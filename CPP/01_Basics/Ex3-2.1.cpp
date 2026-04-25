#include <iostream>

class Rect {
    private:
        int m_width;
        int m_height;
    public:
        Rect() : m_width(1), m_height(1) {};

        int Area() {
            return m_width * m_height;
        }
        void setWidth(int width) {
            m_width = width;
        }
        void setHeight(int height) {
            m_height = height;
        }
    };

int main() {
    Rect r1;
    int width, height;
    
    std::cin >> width >> height;
    r1.setWidth(width);
    r1.setHeight(height);
    
    std::cout << r1.Area() << std::endl;
}
