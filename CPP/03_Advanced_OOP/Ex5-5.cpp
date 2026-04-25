#include <iostream>

bool average(int a[], int size, int &avg) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += a[i];
	}
	avg = sum / size; //레퍼런스를 통해 main함수의 avg변수에 값 전달
	
	return true;
}


int main()
{	

	int a[]={1,2,3,4,5};
	int avg;
	if(average(a,5, avg)) std::cout <<"평균은 :" << avg << std::endl;
	else std::cout <<"평균 구하기 실패" << std::endl;
	
	if(average(a,-2,avg)) std::cout << "평균은 :" << avg << std::endl;
	else std::cout << "평균 구하기 실패" << std::endl;

	return 0;
}
