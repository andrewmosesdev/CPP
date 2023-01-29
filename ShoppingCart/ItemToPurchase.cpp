#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase()
{
    itemName = "none";
    itemPrice = 0;
    itemQuantity = 0;
}

void ItemToPurchase::SetName(std::string name)
{
    itemName = name;
}

std::string ItemToPurchase::GetName() const
{
    return itemName;
}

void ItemToPurchase::SetPrice(int price)
{
    itemPrice = price;
}

int ItemToPurchase::GetPrice() const
{
    return itemPrice;
}

void ItemToPurchase::SetQuantity(int quantity)
{
    itemQuantity = quantity;
}

int ItemToPurchase::GetQuantity() const
{
    return itemQuantity;
}