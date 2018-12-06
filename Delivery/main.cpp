#include <iostream>
#include <string>

class Package {
protected:
    // std::string senderName;
    // std::string senderAddress;
    // std::string senderCity;
    // std::string senderProvince;
    // std::string senderPostcode;
    // std::string receiverName;
    // std::string receiverAddress;
    // std::string receiverCity;
    // std::string receiverProvince;
    // std::string receiverPostcode;
    double weight;
    double price;
public:
    Package(double weight_, double price_) : weight(weight_), price(price_) {
        if ((weight <= 0) || (price <= 0)) {
            throw "Invalid Argument";   // TODO
        }
    }
    virtual double calculateCost() const {
        return weight*price;
    }
};

class TwoDayPackage : public Package {
protected:
    double serviceFee;
public:
    TwoDayPackage(double weight_, double price_, double fee) : Package(weight_, price_), serviceFee(fee) {}
    virtual ~TwoDayPackage() = default;
    double calculateCost() const override {
        return Package::calculateCost() + serviceFee;
    }
};

class OvernightPackage : public Package {
protected:
    double extraFee;
public:
    OvernightPackage(double weight_, double price_, double fee) : Package(weight_, price_), extraFee(fee) {}
    virtual ~OvernightPackage() = default;
    double calculateCost() const override {
        return weight*(price+extraFee);
    }
};

void showprice(const Package &p) {
    if (typeid(OvernightPackage) == typeid(p)) {
        std::cout << "This is an OvernightPackage. Additional fee included." << std::endl;
    }
    else if (typeid(TwoDayPackage) == typeid(p)) {
        std::cout << "This is a TwoDayPackage. Additional fee included." << std::endl;
    }
    std::cout << "The price of this package is " << p.calculateCost() << " dollar." << std::endl;
}


using namespace std;
int main() {
    Package *p[100] = {};
    size_t cnt = 3;
    Package p1(10, 0.98);
    TwoDayPackage p2(10, 0.98, 4.99);
    OvernightPackage p3(10, 0.98, 0.49);
    p[0] = &p1;
    p[1] = &p2;
    p[2] = &p3;
    for (size_t i=0; i < cnt; ++i) {
        showprice(*p[i]);
    }
    return 0;
}
// output
// The price of this package is 9.8 dollar.
// The price of this package is 14.79 dollar.
// The price of this package is 14.7 dollar.
