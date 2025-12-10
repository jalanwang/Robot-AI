#include <iostream> 

int main()
{
    int * numsPtr=new int[5];

    for (int i=0;i<5;i++) {
        numsPtr[i]=i;
        std::cout << numsPtr[i] << " ";
    }

    delete numsPtr;
}