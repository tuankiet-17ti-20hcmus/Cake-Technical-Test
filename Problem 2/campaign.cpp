#include "campaign.hpp"

double campaign::getDiscount() const { return discount; }

int campaign::getVoucherLeft() const { return voucherLeft; }

// This function generate new voucher will be give for next valid user.
void campaign::releaseVoucher() {
    string newCode = "CAKE_DISCOUNT_" + to_string(voucherLeft);
    voucher newVoucher(newCode, discount);
    curVoucher = newVoucher; // Update current voucher to be new voucher has been released.
}

// A new valid user join the campaign and get the voucher.
void campaign::add(Profile& user) {
    voucherLeft--;
    user.setVoucher(curVoucher); // Give voucher for the user.
}
