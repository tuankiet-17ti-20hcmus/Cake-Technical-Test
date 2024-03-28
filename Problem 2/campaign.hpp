#ifndef CAMPAIGN_HPP_
#define CAMPAIGN_HPP_

#include "profile.hpp"

class campaign {
private:
    string name;
    int dayLeft; // Time left until the campaign stop.
    int voucherLeft; // Remaining number of vouchers.
    double discount; // Proportion of discount.
    voucher curVoucher; // Current voucher will give to new user. Then generate new voucher code.

public:
    campaign(string name_, int dayLeft_, int voucherLeft_, int discount_) {
        name = name_;
        dayLeft = dayLeft_;
        voucherLeft = voucherLeft_;
        discount = discount_;
    }

    int getVoucherLeft() const;

    double getDiscount() const;

    // Make a new voucher for next valid login user.
    void releaseVoucher();

    // Process a valid user to join the campaign.
    void add(Profile& user);

};

#endif
