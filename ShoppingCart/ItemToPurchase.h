#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

#include <string>

class ItemToPurchase
{
public:
    ItemToPurchase();
    void SetName(std::string name);
    std::string GetName() const;
    void SetPrice(int price);
    int GetPrice() const;
    void SetQuantity(int quantity);
    int GetQuantity() const;

private:
    std::string itemName;
    int itemPrice;
    int itemQuantity;
};

#endif