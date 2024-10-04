#include <iostream>
#include <string>
#include <fstream>
#include <conio.h> 
#include <stdexcept> 

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
        loadFromFile(); 
    }

    void menu();
    void insert();
    void update();
    void search();
    void remove();
    void show();
    void sort();
    void login();
    void saveToFile();    
    void loadFromFile(); 
};

void Hotel::login() {
    string username, input_password;
    char ch;

    cout << "\n\t----Login Page----\n";
    cout << "Enter username: ";
    getline(cin, username);

    
    string stored_username = "maria";
    string stored_password = "maria1234";

    cout << "Enter password: ";
    
   
    ch = _getch();
    while (ch != 13) {
        input_password.push_back(ch);
        cout << '*'; 
        ch = _getch();
    }

    if (username == stored_username && input_password == stored_password) {
        cout << "\n\nLogin Successful!\n";
        menu(); 
    } else {
        cout << "\n\nInvalid username or password! Try again.\n";
        login(); 
    }
}

void Hotel::menu() {
    int choice;
    do {
        cout << "\n\t Welcome To Hotel Management System" << endl;
        cout << "\n\t____Hotel Management System____";
        cout << "\n\n1\tAllocate Room\t\tInsert New Room";
        cout << "\n2\tSearch Room\t\tSearch room using RoomID";
        cout << "\n3\tUpdate\t\t\tUpdate Record";
        cout << "\n4\tDelete Room\t\tDelete Room with RoomID";
        cout << "\n5\tShow Room records\tShow the room records";
        cout << "\n6\tSort Records\t\tSort the room records by RoomID";
        cout << "\n7\tExit" << endl;

        cout << "Enter Your Choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(10000, '\n'); 
            cout << "Invalid input! Please enter a valid number." << endl;
            continue;
        }

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
            cout << "Invalid choice! Please select a valid option." << endl;
        }
    } while (choice != 7);
}

void Hotel::insert() {
    try {
        cout << "\n\t____Hotel Management System____";
        Node* new_node = new Node;

        if (!new_node) throw runtime_error("Memory allocation failed!");

        cout << "\nEnter Room ID: ";
        cin >> new_node->id;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            throw runtime_error("Invalid Room ID input. Please enter a valid number.");
        }

        cin.ignore(); 

        cout << "\nEnter Customer Name: ";
        getline(cin, new_node->name);

        cout << "\nEnter Allocation Date: ";
        cin >> new_node->date;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            throw runtime_error("Invalid date input. Please enter a valid number.");
        }

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

        saveToFile();
        cout << "\n\nNew Room Inserted Successfully" << endl;

    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
    }
}

void Hotel::search() {
    try {
        cout << "\n\t____Hotel Management System____";
        int t_id;
        if (head == NULL) {
            throw runtime_error("The list is empty.");
        }

        cout << "\n\nEnter Room ID: ";
        cin >> t_id;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            throw runtime_error("Invalid Room ID input. Please enter a valid number.");
        }

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
            throw runtime_error("Room ID not found.");
        }

    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
    }
}

void Hotel::update() {
    try {
        cout << "\n\t____Hotel Management System____";
        int t_id;
        if (head == NULL) {
            throw runtime_error("The list is empty.");
        }

        cout << "\n\nEnter Room ID to update: ";
        cin >> t_id;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            throw runtime_error("Invalid Room ID input. Please enter a valid number.");
        }

        Node* ptr = head;
        bool found = false;
        while (ptr != NULL) {
            if (t_id == ptr->id) {
                cout << "\n\nEnter Updated Room ID: ";
                cin >> ptr->id;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    throw runtime_error("Invalid Room ID input. Please enter a valid number.");
                }

                cin.ignore(); 

                cout << "\n\nEnter Updated Customer Name: ";
                getline(cin, ptr->name);

                cout << "\n\nEnter Updated Allocation Date: ";
                cin >> ptr->date;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    throw runtime_error("Invalid date input. Please enter a valid number.");
                }

                cin.ignore(); 

                cout << "\n\nEnter Updated Room Type: ";
                getline(cin, ptr->roomtype);

                cout << "\n\nRecord Updated Successfully" << endl;
                found = true;
                break; 
            }
            ptr = ptr->next;
        }

        if (!found) {
            throw runtime_error("Room ID not found.");
        }

        saveToFile(); 

    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
    }
}

void Hotel::remove() {
    try {
        cout << "\n\t____Hotel Management System____";
        int t_id;
        if (head == NULL) {
            throw runtime_error("The list is empty.");
        }

        cout << "\n\nEnter Room ID to delete: ";
        cin >> t_id;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            throw runtime_error("Invalid Room ID input. Please enter a valid number.");
        }

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
            throw runtime_error("Room ID not found.");
        }

        saveToFile(); 

    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
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
    try {
        if (head == NULL) {
            throw runtime_error("The list is empty.");
        }

        Node* ptr;
        Node* last = NULL;
        bool swapped;

        do {
            swapped = false;
            ptr = head;

            while (ptr->next != last) {
                if (ptr->id > ptr->next->id) {
                    
                    swap(ptr->id, ptr->next->id);
                    swap(ptr->name, ptr->next->name);
                    swap(ptr->date, ptr->next->date);
                    swap(ptr->roomtype, ptr->next->roomtype);

                    swapped = true;
                }
                ptr = ptr->next; 
            }
            last = ptr;
        } while (swapped);

        saveToFile(); 
        cout << "\n\nRecords Sorted Successfully" << endl;

    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
    }
}


void Hotel::saveToFile() {
    ofstream file("hotel_data.txt", ios::out);
    if (!file) {
        cerr << "Error: Could not open file for saving data!" << endl;
        return;
    }
    Node* ptr = head;
    while (ptr != NULL) {
        file << ptr->id << endl;
        file << ptr->name << endl;
        file << ptr->date << endl;
        file << ptr->roomtype << endl;
        ptr = ptr->next;
    }
    file.close();
}


void Hotel::loadFromFile() {
    ifstream file("hotel_data.txt", ios::in);
    if (!file) {
        cerr << "Error: Could not open file for loading data!" << endl;
        return; 
    }

    while (!file.eof()) {
        Node* new_node = new Node;
        if (!new_node) {
            cerr << "Error: Memory allocation failed!" << endl;
            return;
        }
        file >> new_node->id;
        file.ignore(); 
        getline(file, new_node->name);
        file >> new_node->date;
        file.ignore(); 
        getline(file, new_node->roomtype);
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
    }

    file.close();
}

int main() {
    try {
        Hotel h;
        h.login(); 
    } catch (const exception& e) {
        cerr << "An unexpected error occurred: " << e.what() << endl;
        return 1;
    }
    return 0;
}
