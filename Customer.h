//
// Created by DELL on 9/30/2023.
//
#include <iostream>
#include <string>
#include <iostream>
#include "stdio.h"
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>

using namespace std;

class Customer {
private:
    string ID;
    string firstName;
    string lastName;
    string phoneNumber;
    string address;
    string city;
    string state;
    string zipcode;
    string country;
    vector<Order> *orderList = new vector<Order>();  //a list contains many orders
public:

    Customer(string id, string firstName, string lastName, string phoneNumber, string address, string city,
             string state,
             string zipcode, string country) : ID(id), firstName(firstName), lastName(lastName),
                                               phoneNumber(phoneNumber),
                                               address(address), city(city), state(state), zipcode(zipcode),
                                               country(country) {}


     string getId()  {
        return ID;
    }

    string getCity() {
        return city;
    }

    Order getOrderById(string id) {
        for (Order p: *orderList) {
            if (p.getId() == id)
                return p;
        }
    }

    vector<Order> getOrderList() {
        return *orderList;
    }

    void addItemToOrder(Item *newItem, string orderId) {
        for (Order order: *orderList) {
            if (order.getId() == orderId) {
                order.addItem(newItem);
                cout << "Add item successfully" << endl;
                return;
            }
        }
        cout << "Add item failed" << endl;
    }


    void customerInfo() {
        cout << "Name: " << firstName << " " << lastName << endl;
        cout << "ID: " << ID << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Address: " << address << endl;
        cout << "City: " << city << endl;
        cout << "State: " << state << endl;
        cout << "Zipcode: " << zipcode << endl;
        cout << "Country: " << country << endl;
    }     //Show customer Info


    void showAllOrderOfEachCustomer() {
        for (Order p: *orderList) {
            p.orderInfo();
            cout << endl;
        }
    }         //Display orderList of each customer;

    void addOrder(Order newOrder) {
        orderList->push_back(newOrder);


//    double totalMoneyPaid(){
//        double sum = 0;
//        for (Order p: *orderList) {
//            sum += p.totalPrice();
//        }
//        return sum;
//    }       //Total money which a customer pay;


//    }  //add a new order to the order list
//    double PriceOfEachOrder();
    };


    double totalPriceOfCustomerPaid() {
        double sum = 0;
        for (Order p: *orderList) {
            sum += p.calculatePriceOfOrder();
        }
        return sum;
    }
};

