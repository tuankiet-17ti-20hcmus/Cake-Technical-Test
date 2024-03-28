#ifndef VOUCHER_HPP_
#define VOUCHER_HPP_

#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

class voucher {
private:
    string code;
    double discount;

public:
    voucher() {}

    voucher(string code_, double discount_) {
        code = code_;
        discount = discount_;
    }

    string getCode() const { return code; }
    double getDiscount() const { return discount; }
};

#endif
