//
// Created by DELL on 9/30/2023.
//
#include "iostream"
#include "vector"
#include "Customer.h"
#include <string>
class CustomerList {
private:

public:
    vector<Customer*> customerList;
    void addCustomerToList(Customer *customer) {
        customerList.push_back(customer);
    }




    int getTotalCustomerInCity(string city) {
        int numberCustomer = 0;
        for (Customer *p: customerList) {
            if (city == p->getCity()) {
                numberCustomer++;
            }
        }
        return numberCustomer;
    }

     Customer* findCustomerByOrderID(string orderID) {
        for (Customer *p: customerList) {
            for (Order &order: p->getOrderList()) {
                if (orderID==order.getId()) {
                    return p;
                }
            }
        }
        cout << "Error in find customer" << endl;
    }
    Customer* findCustomerByCustomerID(string customerID){
        for(Customer *p:customerList){
            if(p->getId()==customerID)
                return p;
        }
    }
    void creatNewCustomer(string id, string firstName, string lastName,string phoneNumber,string city,string country){
        Customer *customer=new Customer(id,firstName,lastName,phoneNumber,"",city,"","",country);
        customerList.push_back(customer);
    }

};


