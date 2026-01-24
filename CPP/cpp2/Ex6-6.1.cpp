#include <iostream>



float square(float a) {
	return a*a;
}

double square(double a) {
	return a*a;
}
int main() {
	std::cout << square(3.0) << std::endl;
	std::cout << square(3.0f) << std::endl; 
}
