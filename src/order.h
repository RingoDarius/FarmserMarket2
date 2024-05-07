#ifndef ORDER_H
#define ORDER_H

namespace order
{
    const double NORMAL_RATE = .061;
    const double DISCOUNTED_RATE = .03;

    void CustomerMenu();

    double CalculatePrice(double price, double quantity);
    double CalculateTax(double price, double rate = NORMAL_RATE);
    void UpdateTotal(double computedPrice, double& total);
}  // namespace order
#endif  //ORDER_H

