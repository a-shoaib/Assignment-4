#pragma once
#include<string>
#include<iostream>
#include "Employee.h"
using namespace std;

struct node {
    Employee data;
    node* next;
};

class CHash {
private:
    int numberElem;
    int numberCol;
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
    node* Ctable[10];
public:
    CHash() {
        numberCol = 0; numberElem = 0;
        for (int i = 0; i < 10; i++)
            Ctable[i] = NULL;
    }
    void insertItem(Employee d) {
        node* n = new node;
        n->data = d;
        n->next = NULL;

        int key = this->hash(d); // index represents where in the tableay the element will be stored
        if (Ctable[key] == NULL) // if position key is empty, the element is inserted, if not then the next empty place in the tableay is where the element is inserted
        {
            Ctable[key] = n; numberElem++;
        }
        else {
            node* p = this->Ctable[key];
            while (p->next != NULL && p->data.getName() != n->data.getName())
                p = p->next;

            if (p->data.getName() == n->data.getName()) {
                cout << "Student exists in table" << endl;
                return;
            }

            p->next = n; numberElem++; numberCol++;

        }
    }
    void removeItem(Employee d) {

        int key = this->hash(d);
        if (Ctable[key]->data.getName() == d.getName())
        {
            node* p = Ctable[key];
            Ctable[key] = Ctable[key]->next;
            delete p;
            numberElem--;
        }
        else if (Ctable[key] == NULL)
            cout << "Student not found" << endl;
        else {
            node* p = Ctable[key];
            node* q = Ctable[key];
            while (p != NULL && p->data.getName() != d.getName()) {
                q = p;
                p = p->next;
            }

            if (p == NULL)
                cout << "Student not found" << endl;
            else {
                q->next = p->next;
                delete p; numberElem--;
            }

        }
    }
    void Cprint() {
        for (int i = 0; i < 10; i++) {
            node* n = this->Ctable[i];
            cout << "Elements in position " << i << " in the table: " << endl;
            while (n != NULL) {
                cout << "Name: " << n->data.getName() << ", Age: " << n->data.getAge() << ", Salary: " << n->data.getSalary() << ", Experience:  " << n->data.getExperience() << endl;
                n = n->next;
            }
            cout << endl;
        }
    }
    float collisionsRate() {
        return static_cast<float>(numberCol) / static_cast<float>(numberElem);
    }
};