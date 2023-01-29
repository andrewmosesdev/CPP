#include <iostream>
#include "ItemToPurchase.h"

using namespace std;

int main() {
    ItemToPurchase item1;
    ItemToPurchase item2;

    std::string name;
    int price;
    int quantity;

    std::cout << "Item 1" << std::endl;
    std::cout << "Enter the item name:" << std::endl;
    std::getline(std::cin, name);
    item1.SetName(name);

    std::cout << "Enter the item price:" << std::endl;
    std::cin >> price;
    item1.SetPrice(price);

    std::cout << "Enter the item quantity:" << std::endl; 
    std::cin >> quantity;
    item1.SetQuantity(quantity);

    std::cout << "\n";
    std::cin.ignore();

    std::cout << "Item 2" << std::endl;
    std::cout << "Enter the item name:" << std::endl;
    std::getline(std::cin, name);
    item2.SetName(name);

    std::cout << "Enter the item price:" << std::endl;
    std::cin >> price;
    item2.SetPrice(price);

    std::cout << "Enter the item quantity:" << std::endl; 
    std::cin >> quantity;
    item2.SetQuantity(quantity);
    
    std::cout << "\n";
    std::cin.ignore();

    std::cout << "TOTAL COST" << std::endl;
    std::cout << item1.GetName() << " " << item1.GetQuantity() << " @ $" << item1.GetPrice() << " = $" << item1.GetPrice() * item1.GetQuantity() << std::endl;
    std::cout << item2.GetName() << " " << item2.GetQuantity() << " @ $" << item2.GetPrice() << " = $" << item2.GetPrice() * item2.GetQuantity() << std::endl;
    
    std::cout << "\n";
    std::cin.ignore();
    
    std::cout << "Total: $" << (item1.GetPrice() * item1.GetQuantity()) + (item2.GetPrice() * item2.GetQuantity()) << std::endl;

    return 0;
}
