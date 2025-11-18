// our-company.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include "Publication.h"
using namespace std;

class Library
{
	string name;
	vector<Publication*> items;

public:
    Library(string n) : name(n) {}

    string getName() const {
        return name;
    }

    void setName(const string& n) {
        name = n;
    }

    void add(Publication* p) {
        items.push_back(p);
    }

    void show() {
        cout << "=== Бібліотека: " << name << " ===\n";
        for (auto p : items) p->Description();
    }

    void find(const string& text) {
        cout << "\nПошук: " << text << "\n";
        for (auto p : items) {
            if (p->getName() == text) p->Description();
        }
    }

    void remove(const string& text) {
        items.erase(remove_if(items.begin(), items.end(),
            [&](Publication* p) { return p->getName() == text; }), items.end());
    }
};

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
