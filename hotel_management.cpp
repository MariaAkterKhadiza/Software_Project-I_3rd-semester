#include <iostream>
#include <string>
using namespace std;


struct Node {
    int id;
    int date;
    string name;
    string roomtype;
    Node* next;
};

class Hotel {
private:
    Node* head;

public:
    Hotel() {
        head = NULL;
    }

    void menu();
    void insert();
    void update();
    void search();
    void remove();
    void show();
    void sort();
};

void Hotel::menu() {
    int choice;
    do {
        cout << "\n\t Welcome To Hotel Management System" << endl;
        cout << "\n\t____Hotel Management System____";
        cout << "\n\ns.No    Function   Description" << endl;
        cout << "\n1\tAllocate Room\t\tInsert New Room";
        cout << "\n2\tSearch Room\t\tSearch room using RoomID ";
        cout << "\n3\tUpdate\t\t\tUpdate Record";
        cout << "\n4\tDelete Room\t\tDelete Room with RoomID";
        cout << "\n5\tShow Room records\tShow the room records (that we added)";
        cout << "\n6\tSort Records\t\tSort the room records by RoomID";
        cout << "\n7\tExit" << endl;

        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            insert();
            break;
        case 2:
            search();
            break;
        case 3:
            update();
            break;
        case 4:
            remove();
            break;
        case 5:
            show();
            break;
        case 6:
            sort();
            break;
        case 7:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (choice != 7);
}

void Hotel::insert() {
    cout << "\n\t____Hotel Management System____";
    Node* new_node = new Node;

    cout << "\nEnter Room ID: ";
    cin >> new_node->id;

    cin.ignore(); 

    cout << "\nEnter Customer Name: ";
    getline(cin, new_node->name);

    cout << "\nEnter Allocation Date: ";
    cin >> new_node->date;

    cin.ignore(); 

    cout << "\nEnter Room Type (single/double/twin): ";
    getline(cin, new_node->roomtype);

    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        Node* ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }

    cout << "\n\n\t\t New Room Inserted" << endl;
}

void Hotel::search() {
    cout << "\n\t____Hotel Management System____";
    int t_id;
    if (head == NULL) {
        cout << "\n\nLinkedList is Empty" << endl;
    } else {
        cout << "\n\nEnter Room ID: ";
        cin >> t_id;
        Node* ptr = head;
        bool found = false;
        while (ptr != NULL) {
            if (t_id == ptr->id) {
                cout << "\n\nRoom ID: " << ptr->id;
                cout << "\n\nCustomer Name: " << ptr->name;
                cout << "\n\nRoom Allocation Date: " << ptr->date;
                cout << "\n\nRoom Type: " << ptr->roomtype << endl;
                found = true;
                break; 
            }
            ptr = ptr->next;
        }
        if (!found) {
            cout << "\n\nRoom ID not found!" << endl;
        }
    }
}

void Hotel::update() {
    cout << "\n\t____Hotel Management System____";
    int t_id;
    if (head == NULL) {
        cout << "\n\nLinkedList is Empty" << endl;
    } else {
        cout << "\n\nEnter Room ID to update: ";
        cin >> t_id;
        Node* ptr = head;
        bool found = false;
        while (ptr != NULL) {
            if (t_id == ptr->id) {
                cout << "\n\nEnter Updated Room ID: ";
                cin >> ptr->id;

                cin.ignore(); 

                cout << "\n\nEnter Updated Customer Name: ";
                getline(cin, ptr->name);

                cout << "\n\nEnter Updated Allocation Date: ";
                cin >> ptr->date;

                cin.ignore(); 

                cout << "\n\nEnter Updated Room Type: ";
                getline(cin, ptr->roomtype);

                cout << "\n\n\t\t Update Record Successfully" << endl;
                found = true;
                break; 
            }
            ptr = ptr->next;
        }
        if (!found) {
            cout << "\n\nRoom ID not found!" << endl;
        }
    }
}

void Hotel::remove() {
    cout << "\n\t____Hotel Management System____";
    int t_id;
    if (head == NULL) {
        cout << "\n\nLinkedList is Empty" << endl;
    } else {
        cout << "\n\nEnter Room ID to delete: ";
        cin >> t_id;
        Node* ptr = head;
        Node* prev = NULL;
        bool found = false;
        while (ptr != NULL) {
            if (t_id == ptr->id) {
                if (prev == NULL) { 
                    head = ptr->next;
                } else {
                    prev->next = ptr->next;
                }
                delete ptr;
                cout << "\n\nRoom Record Deleted Successfully" << endl;
                found = true;
                break; 
            }
            prev = ptr;
            ptr = ptr->next;
        }
        if (!found) {
            cout << "\n\nRoom ID not found!" << endl;
        }
    }
}

void Hotel::show() {
    cout << "\n\t____Hotel Management System____";
    if (head == NULL) {
        cout << "\n\nLinkedList is Empty" << endl;
    } else {
        Node* ptr = head;
        while (ptr != NULL) {
            cout << "\n\nRoom ID: " << ptr->id;
            cout << "\n\nCustomer Name: " << ptr->name;
            cout << "\n\nAllocation Date: " << ptr->date;
            cout << "\n\nRoom Type: " << ptr->roomtype << endl;
            ptr = ptr->next;
        }
    }
}

void Hotel::sort() {
    if (head == NULL) {
        cout << "\n\nLinkedList is Empty" << endl;
        return;
    }

    Node* ptr;
    Node* last = NULL;
    bool swapped;

    do {
        swapped = false;
        ptr = head;

        while (ptr->next != last) {
            if (ptr->id > ptr->next->id) {
                // Swap data
                int temp_id = ptr->id;
                ptr->id = ptr->next->id;
                ptr->next->id = temp_id;

                string temp_name = ptr->name;
                ptr->name = ptr->next->name;
                ptr->next->name = temp_name;

                int temp_date = ptr->date;
                ptr->date = ptr->next->date;
                ptr->next->date = temp_date;

                string temp_roomtype = ptr->roomtype;
                ptr->roomtype = ptr->next->roomtype;
                ptr->next->roomtype = temp_roomtype;

                swapped = true;
            }
            ptr = ptr->next;
        }
        last = ptr;
    } while (swapped);

    cout << "\n\nRecords Sorted Successfully" << endl;
}

int main() {
    Hotel h;
    h.menu();
    return 0;
}