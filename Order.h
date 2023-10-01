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
    tm *orderedTime;        //Create time that it is ordered
    tm *getCurrentTime() {
        time_t now = time(0);
        return localtime(&now);
    }
    vector<Item* > itemList ;
    int itemNumber=0;
public:
//    void openMemory(){
//        for(int i=0;i<5;i++){
//            Item* item =new Item();
//        }
//    }
    Order(string id) : ID(id) {
        orderedTime = getCurrentTime();

    }

    string getId() {
        return ID;
    }

//    vector<Item* > getItemList() {
//        return itemList;
//    }

    void addItem(Product *newItem) {
        itemList.push_back(newItem);
    }

    void orderInfo() {
        cout << "Order's ID: " << ID << endl;
        cout << "Ordered Time: " << endl;
        showTime(orderedTime);
//        showItemList();
    }
//
    void showItemList() {
        int i=0;
        if (itemList.empty()) {
            cout << "Item list is empty" << endl;
        } else {

            for(const auto& item: itemList){
                cout<<"Item "<<i<<endl;
                item->showItemInfo();
                i++;
            }
        }
    };
//
    void showTime(tm *ltm) {  //Function to show date and time
        cout << "Year: " << ltm->tm_year << endl;
        cout << "Month: " << ltm->tm_mon << endl;
        cout << "Day: " << ltm->tm_mday << endl;
        cout << "Time: " << ltm->tm_hour << ":";
    };
    void createNewProduct(string productId,string  productName, double unitPrice, string category, double quantity){
        Product *newProduct=new Product(productId,productName,unitPrice,category,quantity);
        itemList.push_back(newProduct);
    }
    void createNewService(string productId,string  productName, double unitPrice, string category){
        Service *newService=new Service(productId,productName,unitPrice,category);
        itemList.push_back(newService);
    }
    double calculatePriceOfOrder() {
        double sum = 0;
        for (Item *p: itemList) {          //CONST AUTO
            sum += p->calculatePrice();
        }
        return sum;
    }


//    double calculateTotalPrice(){
//
//    }
    //Show order info


};