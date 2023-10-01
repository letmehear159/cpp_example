//
// Created by DELL on 9/30/2023.
//
#include "Item.h"
#include "iostream"

using namespace std;

class Product : public Item {
private:
    int quantity;
public:
    Product(string id, string name, double unitPrice, string category, int quantity) :
            Item(id, name, unitPrice, category), quantity(quantity) {}

    Product() {}

    double calculatePrice() const override {
        return quantity * unitPrice;
    }         //Caculate price of and product=quantiy*unitPrice;

    void showItemInfo() const override {
        cout << "ID: " << ID << endl;
        cout << "Name: " << name << endl;
        cout << "Unit Price: " << unitPrice << endl;
        cout << "Quantity: " << quantity << endl;
    }


};

