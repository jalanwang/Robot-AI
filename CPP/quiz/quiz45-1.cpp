#include <iostream>
#include <cstdlib>
#include <memory>


class Calculator {
  private:
  double mA;
  double mB;
  double mResult;

  public:
    double plus(double mA, double mB) {
      mResult=mA+mB;
      return mResult;

    }
    double minus(double mA, double mB) {
      mResult=mA-mB;
      return mResult;

    }
    double multiple(double mA, double mB) {
      mResult=mA*mB;
      return mResult;
    }
    double divide(double mA, double mB) {
      mResult=mA/mB;
      return mResult;
    }

    void getData(double& mA, double& mB) {
      std::cin >> mA >> mB;
    }

};

int main() {
  std::unique_ptr<Calculator> c= std::make_unique<Calculator>();
  double a, b;

  c->getData(a, b);
  
  std::cout << "plus: " << c->plus(a,b) << std::endl;
  std::cout << "minus: " << c->minus(a,b) << std::endl;
  std::cout << "multiple: " << c->multiple(a,b) << std::endl;
  std::cout << "divide: " << c->divide(a,b) << std::endl;
}