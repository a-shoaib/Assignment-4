#pragma once
#include <string>
#include<iostream>
using namespace std;

class Employee {
private:
	string name;
	string age;
	string salary;
	string experience;

public:
	Employee() {
		name = "";
		age = -1;
		salary = -1;
		experience = -1;
	}

	Employee(string n, string a, string s, string e) {
		name = n;
		age = a;
		salary = s;
		experience = e;
	}

	string getName() {
		return name;
	}
	string getAge() {
		return age;
	}
	string getSalary() {
		return salary;
	}
	string getExperience() {
		return experience;
	}

	void setName(string n) {
		name = n;
	}

	void setAge(string a) {
		age = a;
	}

	void setSalary(string s) {
		salary = s;
	}

	void setExperience(string e) {
		experience = e;
	}
};