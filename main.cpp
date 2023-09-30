#include <iostream>
#include <algorithm>
#include <cstdlib>
#include "OrderItem.h"
#include "vector"
#include "ctime"
#include "Product.h"
#include "Service.h"
#include "Order.h"
#include "CustomerList.h"
#include "ApplyFunction.h"

using namespace std;

int main() {
    int customerNumber = 0, itemNumber = 0;
    char ch;
    int option;  //Multiple choice
    double price;
////    vector<Customer> customerList;          // a list of customer
//    Customer customer("10", "Ho Chi Minh", " ", "", "", "", "", "", "");
//    Customer truyen("11", "Ho Chi Minh,"" ", "", "", "", "", "", "", "");
//    Customer truong("11", "Ho Chi Minh,"" ", "", "", "", "", "", "", "");
    CustomerList customerList;
//    Order order("23");
//    truong.addOrder(order);
//    customerList.addCustomerToList(customer);
//    customerList.addCustomerToList(truyen);
//    customerList.addCustomerToList(truong);
////    cout << endl << "Number of customer in HCM: " << customerList.getTotalCustomerInCity("Ho Chi Minh") << endl;
//    Product product("32323", "abc", 232, "", 2);
//    Service service("32323", "abc", 2, "");
//    cout << endl;
////    service.showItemInfo();
//    cout << endl;
//    order.addItem(&product);
//    order.addItem(&service);
//    Customer myco = customerList.findCustomerByID("23");
//    Order co = myco.getOrderById("23");
//    string idd, namee, orderIDD;
//    double unitPricee;
//    readItemFromFile(idd, orderIDD, namee, unitPricee, 0);
//    Product newProductt(idd, namee, unitPricee, "", 4);
//    co.showItemList();
//    string orderID;
//    cout << "Order's ID: ";
//    cin >> orderID;
//    Customer customerByID = customerList.findCustomerByID(orderID);
//    Order orderByID = customerByID.getOrderById(orderID);
//    orderByID.showItemList();
//    for(Item *i:*co.getItemList()){
//        cout<<i->calculatePrice()<<endl;
//    }
////
////    Order myOrder=
////    product.showItemInfo();
////    service.showItemInfo();

//    order.showItemList();
//    customer.addOrder(order);
//    vector<Order> orderList = customer.getOrderList();


//    string id, firstName, lastName, phoneNumber, city, country;
//    readCustomerFromFile(id, firstName, lastName, phoneNumber, city, country, 0);
//    string itemId, name, orderID;
//    double unitPrice;
//    readItemFromFile(itemId, orderID, name, price, 0);
//    Customer a(id, firstName, lastName, phoneNumber, "", city, "", "", country);
//    Product b(itemId, name, price, "", 3);
//    Product e(itemId, name, price, "", 323);
//    Order c("22110084");
//    customerList.push_back(a);
//    a.addOrder(c);
//    a.addItem(&b, "22110084");
//    a.addItem(&e, "22110084");
//    Order show = a.getOrder("22110084");
//    show.showItemList();
//    c.showItemList();
//    a.addItem(&b,orderID);
//    c.showItemList();
    Product* testProduct=new Product();
    if (1 == 1) {

        do {
            cout << "1: Add new customer: " << endl;
            cout << "2: Add new order to specific customer's orderList: " << endl;
            cout << "3: Add new Item to specific orderList: " << endl;
            cout << "4: Show number of customers in specific city " << endl;
            cout << "5: Show total price of an order " << endl;
            cout << "6: Show total money which a customer paid: " << endl;
            cout << "7: Show total price of all orders: " << endl;
            cout << "8: Show Customer List: " << endl;
            cout << "9: Show Order List of an customer: " << endl;
            cout << "10: Show Item List of an Order: " << endl;
            cout << "Choose and option: " << endl;
            cin >> option;
            if (option >= 1 && option <= 13) {
                switch (option) {
                    case 1: {
                        int choice;
                        string id, firstName, lastName, phoneNumber, city, country;
                        cout << "1: Read From File: " << endl;
                        cout << "2: Read From keyboard" << endl;
                        cin >> choice;
                        if (choice == 1) {
                            readCustomerFromFile(id, firstName, lastName, phoneNumber, city, country,
                                                 customerNumber * 6);
                            customerNumber++;
                        } else {
                            cout << "ID: " << endl;
                            cin >> id;
                            cout << "First name: " << endl;
                            cin >> firstName;
                            cout << "Last name: " << endl;
                            cin >> lastName;
                            cout << "Phone number: : " << endl;
                            cin >> phoneNumber;
                            cout << "city : " << endl;
                            getline(cin, city);
                            cout << "Country: " << endl;
                            getline(cin, country);
                        }
                        Customer customer(id, firstName, lastName, phoneNumber, "", city, "", "", country);
                        customerList.addCustomerToList(customer);
                        cout << "Action done" << endl;
                        break;
                    }

                    case 2: {

                        bool isAdded = false;
                        string orderId, customerId;
                        cout << "Order's ID: " << endl;
                        cin >> orderId;
                        cout << "Customer's ID: " << endl;
                        cin >> customerId;
                        Order newOrder(orderId);
                        for (Customer p: customerList.getCustomerList()) {
                            if (p.getId() == customerId) {
                                p.addOrder(newOrder);
                                isAdded = true;
                            }
                        }
                        if (isAdded)
                            cout << "Add completed" << endl;
                        else {
                            cout << "Add failed" << endl;
                        }
                        break;
                    }
                    case 3: {
                        int choice;
                        string id, name, orderID;
                        double unitPrice;
                        bool isAdded = false;
                        cout << "1: Read From File: " << endl;
                        cout << "2: Read From keyboard" << endl;
                        cin >> choice;
                        if (choice == 1) {
                            readItemFromFile(id, orderID, name, unitPrice, 4 * itemNumber);
                        } else {
                            cout << "Item's ID: " << endl;
                            cin >> id;
                            cout << "Name: " << endl;
                            cin >> name;
                            cout << "Price: " << endl;
                            cin >> unitPrice;
                            cout << "Order's ID: " << endl;
                            cin >> orderID;
                        }
                        cout << "This is a product or a Service? " << endl;
                        cout << "1: Product " << endl;
                        cout << "2: Service " << endl;
                        cin >> choice;
                        if (choice == 1) {
                            int quantity;
                            cout << "The quantity of this product: " << endl;
                            cin >> quantity;
                            Product newProduct(id, name, unitPrice, "", quantity);
                            testProduct=&newProduct;
                            ///Method: Traverse for each customer in customerList and
                            /// For each customerList we find the Order in the Orderlist which is match the id of OrderId input

                            for (Customer customerIndex: customerList.getCustomerList()) {        ///Traverse customerList
                                for (Order orderIndex: customerIndex.getOrderList()) {      ///Traverse orderList
                                    if (orderIndex.getId() == orderID) {                    ///If OrderId is matched
                                        customerIndex.addItemToOrder(testProduct,
                                                                     orderID);        ///ADD this item to that order
                                        isAdded = true;
                                    }
                                }
                            }
                        } else {
//                        Service newItem(id, name, unitPrice, "");
                            ///Method: Traverse for each customer in customerList and
                            /// For each customerList we find the Order in the Orderlist which is match the id of OrderId input
                            for (Customer customerIndex: customerList.getCustomerList()) {        ///Traverse customerList
                                for (Order orderIndex: customerIndex.getOrderList()) {      ///Traverse orderList
                                    if (orderIndex.getId() == orderID) {                    ///If OrderId is matchec
//                                    customerIndex.addItem(newItem, orderID);        ///ADD this item to that order
                                        isAdded = true;
                                    }
                                }
                            }
                        }
                        if (isAdded)
                            cout << "Add completed" << endl;
                        else {
                            cout << "Add failed" << endl;
                        }
                        break;
                    }
                    case 4: {
                        string city;
                        cout << "City you want to find customer living there" << endl;
                        cin.ignore(1, '\n');
                        getline(cin, city);
//    deleteSpace(city);          ///Change string to lowercase and has no space form
//    changeStringToLowercase(city); ///Change string to lowercase and has no space form
//                    for (Customer p: customerList) {
//                        cityFromCustomer = p.getCity();
//                        deleteSpace(cityFromCustomer); ///Change string to lowercase and has no space form
//                        changeStringToLowercase(cityFromCustomer);///Change string to lowercase and has no space form
//                        if (city == cityFromCustomer) {
//                            numberCustomer++;
//                        }
                        cout << "Number of customer living in: " << city << ": "
                             << customerList.getTotalCustomerInCity(city) << endl;
                        break;
                    }
                    case 5: {
                        string orderID;
                        cout << "Order's ID: " << endl;
                        cin >> orderID;
                        Customer a = customerList.findCustomerByID(orderID);
                        Order priceOfOrder = a.getOrderById(orderID);
                        cout << priceOfOrder.calculatePriceOfOrder();
                        break;

                    }
                        //6: Show total money which a customer paid:
                    case 6: {
                        double sum = 0;
                        string customerID;
                        cout << "Customer ID: " << endl;
                        cin >> customerID;
                        for (Customer customerIndex: customerList.getCustomerList()) {
                            if (customerIndex.getId() == customerID) {
                                cout << customerIndex.totalPriceOfCustomerPaid();
                            }
                        }
                        cout << "Total money which this customer paid: " << sum << endl;
                        break;
                    }
                        //7: Show total price of all orders:
                    case 7: {
                        double sum = 0;
                        for (Customer customerIndex: customerList.getCustomerList()) {
                            sum += customerIndex.totalPriceOfCustomerPaid();
                        }
                        cout << "Total price of all orders: " << sum << endl;
                        break;
                    }
                        //8: Show Customer List: "
                    case 8: {
                        for (Customer a: customerList.getCustomerList()) {
                            a.customerInfo();
                        }
                        break;

                    }


                    case 9: {
                        string orderID;
                        cout << "Order ID: ";
                        cin.ignore(1, '\n');
                        getline(cin, orderID);
                        Customer a = findCustomerThroughOrderID(orderID, customerList.getCustomerList());
                        a.showAllOrderOfEachCustomer();
                        break;
                    }
                        //10: Show Item List of an Order:
                    case 10: {
                        string orderID;
                        cout << "Order's ID: ";
                        cin >> orderID;
                        Customer customerByID = customerList.findCustomerByID(orderID);
                        Order orderByID = customerByID.getOrderById(orderID);
//                        orderByID.showItemList();
                        break;
                    }
                    default: {
                        cout << "Option doesnt exist, choose again!!!" << endl;
                    }

                }

                cout << "Press any to turn back" << endl;
                if (option == 11)
                    break;
                cin.ignore();
                cin.get();
                system("cls");


            }
        } while (option != 11);

    }

};








//    Customer a("33","#","3","342","2342","3","2343");
////
//        time_t now=time(0);
//        Order b("@@1");
//    showTime(b.orderedTime);
////    tm *ltm = localtime(&now);
//        return 0;

