#include<iostream>
using namespace std;

class linkedlist {
protected:
    class node {
    public:
        int data;
        node *next;

        node(int value) {
            this->data = value;
            next = nullptr;
        }

        void displaydata() {
            cout << data << " ";
        }
    };

    int nodecount;
    node *head;

public:
    linkedlist() {
        nodecount = 0; // Corrected to 0
        head = nullptr;
    }

    ~linkedlist() { // Destructor to properly clean up the list
        while (head != nullptr) {
            node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    bool checkempty() {
        return (head == nullptr);
    }

    int getdata() {
        int a;
        cout << "Enter the data: ";
        cin >> a;
        return a;
    }

    void Insertdatafrombegining() {
        node *newnode = new node(getdata());
        if (checkempty()) {
            head = newnode;
        } else {
            newnode->next = head;
            head = newnode;
        }
        nodecount++; // Increment node count
    }

    void displaynode() { // Corrected method name
        node *temporary = head;

        if (checkempty()) {
            cout << "no data to display" << endl;
        } else {
            while (temporary != nullptr) { // Corrected loop condition
                temporary->displaydata();
                temporary = temporary->next;
            }
            cout << endl; /ng
        }
    }
};

int main() {
    linkedlist l1;
    l1.Insertdatafrombegining();
    l1.displaynode(); 
    l1.Insertdatafrombegining();
    l1.displaynode();
    return 0;
}
