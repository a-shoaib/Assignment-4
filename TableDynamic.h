#pragma once
#include <string>
#include<iostream>
#include "Employee.h"
using namespace std;

class dynamicHash {
private:
    int numberElem, numberCol;
    int hash(Employee element) {
        string name = element.getName();
        int key;
        int sum = 0; // represents the sum of ASCII values of the characters in the string
        for (int i = 0; i < name.length(); i++) {
            sum += int(name[i]);
        }
        key = sum % 10;
        return key;
    }
    Employee* table;


public:
    dynamicHash() {
        numberCol = 0; numberElem = 0;
        table = new Employee[10];
    }

    void insertItem(Employee element) {
        int key = hash(element); // index represents where in the tableay the element will be stored
        if (this->table[key].getName() == "") // if position key is empty, the element is inserted, if not then the next empty place in the tableay is where the element is inserted
        {
            this->table[key] = element; numberElem++;
        }
        else {
            int start = key; // to store the starting point, if the loop passes on this starting point again, then the tableay is full
            while (this->table[key].getName() != "") {
                key = (key + 1) % 10; // to stay within the 10 of the table
                if (key == start) {
                    cout << "Table is full" << endl;
                    return;
                }
            }
            this->table[key] = element; numberElem++; numberCol++;
        }
    }
    void removeItem(Employee element) {

        int key = hash(element);
        if (table[key].getName() == element.getName())
        {
            table[key].setName("");
            table[key].setAge("");
            table[key].setSalary("");
            table[key].setExperience("");
            numberElem--;
        }
        else {
            int start = key; // to store the starting point, if the loop passes on this starting point again, then the element is not in the table
            while (this->table[key].getName() != element.getName()) {
                key = (key + 1) % 10;
                if (key == start) {
                    cout << "Element not found " << endl;
                    return;
                }
            }
            table[key].setName("");
            table[key].setAge("");
            table[key].setSalary("");
            table[key].setExperience("");
            numberElem--;
        }
    }
    void print() {
        for (int i = 0; i < 10; i++) {
            cout << "Element " << i << " in the table is: " << table[i].getName() << ", Age: " << table[i].getAge() << ", Salary: " << table[i].getSalary() << ", Experience: " << table[i].getExperience() << endl;
        }
    }
    float collisionsRate() {
        return static_cast<float>(numberCol) / static_cast<float>(numberElem);
    }
};