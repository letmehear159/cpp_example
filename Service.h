//
// Created by DELL on 9/30/2023.
//
#include "ctime"
#include "iostream"

void showTime(tm *ltm) {  //Function to show date and time
    cout << "Year: " << ltm->tm_year << endl;
    cout << "Month: " << ltm->tm_mon << endl;
    cout << "Day: " << ltm->tm_mday << endl;
};
//dc roi
#include "time.h"

using namespace std;

class Service : public Item {
private:
    tm *usingTimeStart;  //Create first point time;
    tm *usingTimeEnd;   //Create end point using time

    static double calculateTimeDuration(tm *a, tm *b) {
//        showTime(a);
        double dayYear = (a->tm_year - b->tm_year);
        double dayMonth = 0;
        double days = 0;
        if (a->tm_mon >= b->tm_mon) {
            dayMonth = (a->tm_mon - b->tm_mon);
        } else {
            dayYear -= 1;
            dayMonth = (a->tm_mon + 12 - b->tm_mon);
        }
        if (a->tm_mday >= b->tm_mday) {
            days = a->tm_mday - b->tm_mday;
        } else {
            dayMonth -= 1;
            days = a->tm_mday + 30 - b->tm_mday;
        }
        if (dayMonth < 0) {
            dayMonth += 12;
            dayYear -= 1;
        }
        double time = dayYear * 365 + dayMonth * 30 + days;
        return time;
    }

    tm *generateEndTimeUsing() {
        srand(time(nullptr));
        tm *rdTime = new tm();
        rdTime->tm_year = rand() % (2025 - 2024 + 1) + 2024;
        rdTime->tm_mon = rand() % 11 + 1;
        rdTime->tm_mday = rand() % 30 + 1;
        return rdTime;
    }

public:
    double duration;

    Service(const string &id, const string &name, double unitPrice, const string &category) : Item(id, name, unitPrice,
                                                                                                   category) {
        time_t now = time(0);
        usingTimeStart = localtime(&now);
        usingTimeStart->tm_year = usingTimeStart->tm_year + 1900;
        usingTimeStart->tm_mon = usingTimeStart->tm_mon + 1;
        usingTimeEnd = generateEndTimeUsing();
        duration = calculateTimeDuration(usingTimeEnd, usingTimeStart);
    }

    void showTimeEnd() {
        cout << usingTimeEnd->tm_year << endl;
        cout << usingTimeEnd->tm_mon << endl;
        cout << usingTimeEnd->tm_mday;
    }

    double calculatePrice() const override {
        return calculateTimeDuration(usingTimeEnd, usingTimeStart) * unitPrice;
    }

    void showItemInfo() const override {
        cout << "ID: " << ID << endl;
        cout << "Name: " << name << endl;
        cout << "Unit Price: " << unitPrice << endl;
        cout << "Duration: " << calculateTimeDuration(usingTimeEnd, usingTimeStart);
    }
};

