//
// Created by DELL on 9/30/2023.
//
#include "iostream"
#include "vector"
#include "Customer.h"
#include <string>

class CustomerList {
private:
    vector<Customer> customerList;
public:
    void addCustomerToList(Customer customer) {
        customerList.push_back(customer);
    }

    vector<Customer> getCustomerList(){
        return customerList;
    }


    int getTotalCustomerInCity(string city) {
        int numberCustomer = 0;
        for (Customer p: customerList) {
            if (city==p.getCity()) {
                numberCustomer++;
            }
        }
        return numberCustomer;
    }

    Customer findCustomerByID(string orderID){
        for(Customer p:customerList){
            for(Order order:p.getOrderList()){
                if(order.getId()==orderID)
                    return p;
            }
        }
    cout<<"Error in find customer"<<endl;
    }
};


