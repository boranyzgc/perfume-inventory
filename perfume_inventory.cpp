#include <iostream>
#include <string>
using namespace std;

struct Perfume {
    string name;
    string brand;
    string category;
    float price;
    int rating;
    Perfume* next;
};

Perfume* head = nullptr;


void addPerfumeToEnd() {
    Perfume* newPerfume = new Perfume();

    cout << "Enter perfume name: ";
    getline(cin >> ws, newPerfume->name);
    cout << "Enter brand: ";
    getline(cin, newPerfume->brand);
    cout << "Enter category: ";
    getline(cin, newPerfume->category);
    cout << "Enter price: ";
    cin >> newPerfume->price;
    cout << "Enter rating (1-5): ";
    cin >> newPerfume->rating;
    newPerfume->next = nullptr;

    if (!head) {
        head = newPerfume;
    } else {
        Perfume* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newPerfume;
    }

    cout << "\n✅ Perfume added successfully!\n";
}


void displayPerfumes() {
    if (!head) {
        cout << "No perfumes in inventory.\n";
        return;
    }

    Perfume* temp = head;
    cout << "\n--- Perfume List ---\n";
    while (temp) {
        cout << "Name: " << temp->name << "\n";
        cout << "Brand: " << temp->brand << "\n";
        cout << "Category: " << temp->category << "\n";
        cout << "Price: $" << temp->price << "\n";
        cout << "Rating: " << temp->rating << "/5\n";
        cout << "----------------------\n";
        temp = temp->next;
    }
}


void deletePerfumeByName(string target) {
    if (!head) return;

    Perfume* temp = head;
    Perfume* prev = nullptr;

    while (temp && temp->name != target) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        cout << "❌ Perfume not found.\n";
        return;
    }

    if (!prev) {
        head = head->next;
    } else {
        prev->next = temp->next;
    }

    delete temp;
    cout << "✅ Deleted perfume: " << target << "\n";
}


void searchByBrand(string brand) {
    Perfume* temp = head;
    bool found = false;

    while (temp) {
        if (temp->brand == brand) {
            cout << "\nFound: " << temp->name << " (" << temp->category << ") - $" << temp->price << "\n";
            found = true;
        }
        temp = temp->next;
    }

    if (!found) cout << "❌ No perfumes found from that brand.\n";
}


void sortPerfumesByName() {
    if (!head || !head->next) return;

    bool swapped;
    do {
        swapped = false;
        Perfume* current = head;
        while (current->next) {
            if (current->name > current->next->name) {
                swap(current->name, current->next->name);
                swap(current->brand, current->next->brand);
                swap(current->category, current->next->category);
                swap(current->price, current->next->price);
                swap(current->rating, current->next->rating);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);

    cout << "✅ Sorted by name (A-Z).\n";
}


void sortPerfumesByPrice() {
    if (!head || !head->next) return;

    bool swapped;
    do {
        swapped = false;
        Perfume* current = head;
        while (current->next) {
            if (current->price > current->next->price) {
                swap(current->name, current->next->name);
                swap(current->brand, current->next->brand);
                swap(current->category, current->next->category);
                swap(current->price, current->next->price);
                swap(current->rating, current->next->rating);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);

    cout << "✅ Sorted by price (low to high).\n";
}


void cleanup() {
    while (head) {
        Perfume* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    int choice;
    do {
        cout << "\n==== Perfume Inventory ====\n";
        cout << "1. Add Perfume\n";
        cout << "2. Show All Perfumes\n";
        cout << "3. Delete Perfume by Name\n";
        cout << "4. Search by Brand\n";
        cout << "5. Sort by Name (A-Z)\n";
        cout << "6. Sort by Price (Low to High)\n";
        cout << "7. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
            case 1: addPerfumeToEnd(); break;
            case 2: displayPerfumes(); break;
            case 3: {
                string name;
                cout << "Enter perfume name to delete: ";
                getline(cin >> ws, name);
                deletePerfumeByName(name);
                break;
            }
            case 4: {
                string brand;
                cout << "Enter brand to search: ";
                getline(cin >> ws, brand);
                searchByBrand(brand);
                break;
            }
            case 5: sortPerfumesByName(); break;
            case 6: sortPerfumesByPrice(); break;
            case 7: cleanup(); cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 7);

    return 0;
}
