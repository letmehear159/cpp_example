////
//// Created by DELL on 9/27/2023.
////
//
//#include "OrderItem.h"
//
//
//using namespace std;
//
//
//
//
//
//
//
//
//
//
//
//
//
/////
//
//
//
//
//
//
/////
///// \param customerList
//
////
////double Order::totalPrice() {
////    double sum = 0;
////    Product *k;
////
////    for (Item *p: *itemList) {
////        if (1) {
////            sum += 0;
////        }
////
////    }
////    return sum;
////}
//
//
////
////const string &Order::getId() const {
////    return ID;
////}
//
//
//
//
//
/////
///// \param id
///// \param name
///// \param unitPrice
///// \param category
//
//
//
//
//
//
//
//
//
//
//
//void showTime(tm *ltm) {  //Function to show date and time
//    cout << "Year: " << 1900 + ltm->tm_year << endl;
//    cout << "Month: " << 1 + ltm->tm_mon << endl;
//    cout << "Day: " << ltm->tm_mday << endl;
//    cout << "Time: " << ltm->tm_hour << ":";
//}
//
/////
///// \param city : The city you want to know how many customer in that city
///// \param customerList : List contains customers;
///// \return : Number of customer in that city
//int numberOfCustomerInCity(string city, vector<Customer> customerList) {
//    int numberCustomer = 0;
//    string customerCity;
//    //delete all space in city string
//    deleteSpace(city);
//    //Change string customer.city into lowercase;
//    changeStringToLowercase(city);
//    //Change the city of each customer to form lowercase and doesn't have space;
//    for (Customer p: customerList) {
//        customerCity = p.getCity();       //Initialize city of customer for a new string variable
//        deleteSpace(customerCity);      //delete space and change to lowercase;
//        changeStringToLowercase(customerCity);
//        if (city == customerCity)          //if the customer is in the city we find
//            numberCustomer++;           //increase amount of customer in this
//    }
//    //
//    return numberCustomer;
//
//
//}
//
//void deleteSpace(string &a) {
//    for (int i = a.size() - 1; i >= 0; i--) {
//        if (a[i] == 32)
//            a.erase(i, 1);
//    }
//}
//
//void changeStringToLowercase(string &city) {
//    transform(city.begin(), city.end(), city.begin(), ::tolower);
//}
//
////double totalOrderMoneyPaid(vector<Customer> customerList) {
////    double sum = 0;
////    for (Customer p: customerList) {
////        sum += p.totalMoneyPaid();
////    }
////    return sum;
////}
//
///// \param a:usingTimeEnd
///// \param b :usingTimeStart
///// \return return a timeDuration with double days
//double timeDuration(tm *a, tm *b) {
//
//
//}
//
//tm *generate_time() {
//    tm *rdTime = new tm();
//    rdTime->tm_year = rand() % 1 + 2023;
//    rdTime->tm_mon = rand() % 11 + 1;
//    rdTime->tm_mday = rand() % 30 + 1;
//    return rdTime;
//
//}
//

//

//
