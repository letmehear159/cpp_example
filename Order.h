//
// Created by DELL on 9/30/2023.
//
#include "iostream"
#include "vector"

using namespace std;

void showTime(tm *ltm);

class Order {
private:
    string ID;
    vector<Item *> *itemList;
    tm *orderedTime;        //Create time that it is odered
    tm *getCurrentTime() {
        time_t now = time(0);
        return localtime(&now);
    }

public:
    Order(string id) : ID(id) {
        orderedTime = getCurrentTime();
        itemList = new vector<Item *>;
    }

    string getId() {
        return ID;
    }

    vector<Item *> *getItemList() {
        return itemList;
    }

    void addItem(Item *newItem) {
        itemList->push_back(newItem);
    }

    void orderInfo() {
        cout << "Order's ID: " << ID << endl;
        cout << "Ordered Time: " << endl;
        showTime(orderedTime);
//        showItemList();
    }

    void showItemList() {
        if (itemList->empty()) {
            cout << "Item list is empty" << endl;
        } else {

            for (const auto &item: *itemList) {
                item->showItemInfo();
            }
        }
    };

    void showTime(tm *ltm) {  //Function to show date and time
        cout << "Year: " << ltm->tm_year << endl;
        cout << "Month: " << ltm->tm_mon << endl;
        cout << "Day: " << ltm->tm_mday << endl;
        cout << "Time: " << ltm->tm_hour << ":";
    };

    double calculatePriceOfOrder() {
        double sum = 0;
        for (Item *p: *itemList) {
            sum += p->calculatePrice();
        }
        return sum;
    }


//    double calculateTotalPrice(){
//
//    }
    //Show order info


};