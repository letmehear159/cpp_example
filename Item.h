
#include "iostream"
#include "string"

using namespace std;

class Item {
protected:
    string ID;
    string name;
    double unitPrice;
    string category;
public:
    Item( string id,  string name, double unitPrice,  string category) :
    ID(id), name(name),unitPrice(unitPrice),category(category) {}
    Item(){};

    virtual double calculatePrice() {}
    virtual void showItemInfo(){};

};

