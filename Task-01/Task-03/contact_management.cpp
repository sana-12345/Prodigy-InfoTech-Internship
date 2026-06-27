#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Contact {
    string name;
    string phone;
    string email;
};

vector<Contact> contacts;

// Load contacts from file
void loadContacts() {
    ifstream file("contacts.txt");
    Contact c;
    while (file >> c.name >> c.phone >> c.email) {
        contacts.push_back(c);
    }
    file.close();
}

// Save contacts to file
void saveContacts() {
    ofstream file("contacts.txt");
    for (auto &c : contacts) {
        file << c.name << " " << c.phone << " " << c.email << endl;
    }
    file.close();
}

// Add a new contact
void addContact() {
    Contact c;
    cout << "Enter Name: ";
    cin >> c.name;
    cout << "Enter Phone Number: ";
    cin >> c.phone;
    cout << "Enter Email: ";
    cin >> c.email;

    contacts.push_back(c);
    saveContacts();
    cout << "Contact added successfully!\n";
}

// View all contacts
void viewContacts() {
    if (contacts.empty()) {
        cout << "No contacts available.\n";
        return;
    }

    for (int i = 0; i < contacts.size(); i++) {
        cout << i + 1 << ". "
             << contacts[i].name << " | "
             << contacts[i].phone << " | "
             << contacts[i].email << endl;
    }
}

// Edit a contact
void editContact() {
    viewContacts();
    int choice;
    cout << "Enter contact number to edit: ";
    cin >> choice;

    if (choice < 1 || choice > contacts.size()) {
        cout << "Invalid choice!\n";
        return;
    }

    cout << "Enter new Name: ";
    cin >> contacts[choice - 1].name;
    cout << "Enter new Phone: ";
    cin >> contacts[choice - 1].phone;
    cout << "Enter new Email: ";
    cin >> contacts[choice - 1].email;

    saveContacts();
    cout << "Contact updated successfully!\n";
}

// Delete a contact
void deleteContact() {
    viewContacts();
    int choice;
    cout << "Enter contact number to delete: ";
    cin >> choice;

    if (choice < 1 || choice > contacts.size()) {
        cout << "Invalid choice!\n";
        return;
    }

    contacts.erase(contacts.begin() + choice - 1);
    saveContacts();
    cout << "Contact deleted successfully!\n";
}

int main() {
    loadContacts();
    int option;

    do {
        cout << "\n--- Contact Management System ---\n";
        cout << "1. Add Contact\n";
        cout << "2. View Contacts\n";
        cout << "3. Edit Contact\n";
        cout << "4. Delete Contact\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
            case 1: addContact(); break;
            case 2: viewContacts(); break;
            case 3: editContact(); break;
            case 4: deleteContact(); break;
            case 5: cout << "Exiting program...\n"; break;
            default: cout << "Invalid option!\n";
        }
    } while (option != 5);

    cout << "\nPRODIGY INFOTECH" << endl;
    return 0;
}
