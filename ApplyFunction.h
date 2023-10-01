using namespace std;
#include "iostream"
#include "vector"
#include "ctime"
#include "stdio.h"
//Customer findCustomerThroughOrderID(string orderID, vector<Customer> customerList);
//Customer findCustomerThroughOrderID(string orderID, vector<Customer> customerList) {
//    for (Customer customerIndex: customerList) {        ///Traverse customerList
//        for (Order orderIndex: customerIndex.getOrderList()) {      ///Traverse orderList
//            if (orderIndex.getId() == orderID) {
//                return customerIndex;
//            }
//        }
//    }
//    cout << "Doesnt exist";
//    Customer a("", "", "", "", "", "", "", "", "");
//    return a;
//}








void readCustomerFromFile(string &id, string &lastName, string &firstName, string &phoneNumber, string &city,
                          string &country, int line) {

    string getL;
    fstream fp;
    fp.open("D:/INPUT.TXT", ios::in);
    for (int i = 0; i < line; i++) {
        getline(fp, getL);
    }
    if (fp) {
        getline(fp, id);
        getline(fp, lastName);
        getline(fp, firstName);
        getline(fp, phoneNumber);
        getline(fp, city);
        getline(fp, country);
    } else {
        cout << "error";
        return;
    }
}
void readItemFromFile(string &id, string &orderID, string &name, double &price, int line) {
    string getL;
    fstream fp;
    fp.open("D:/INPUT1.TXT", ios::in);
    for (int i = 0; i < line; i++) {
        getline(fp, getL);
    }
    if (fp) {
        getline(fp, id);
        getline(fp, orderID);
        getline(fp, name);
        fp >> price;
    }
}



