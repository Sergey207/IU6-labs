#include <iostream>

using namespace std;

struct elem {
    char c;
    elem* next = nullptr;
};

int main() {
    int N;
    cout << "Enter N (amount of elements): ";
    cin >> N;
    if (N < 1) {
        cout << "N must be > 0" << endl;
        return -1;
    }

    elem *head = nullptr, *tail = nullptr;
    for (int i = 0; i < N; ++i) {
        const auto new_elem = new elem();
        cin >> new_elem->c;
        if (head == nullptr) {
            head = new_elem;
        } else {
            tail->next = new_elem;
        }
        tail = new_elem;
    }

    elem *p = head, *temp;
    while (p != nullptr && p->next != nullptr) {
        temp = p->next;
        cout << "Deleting char " << temp->c << endl;
        p->next = temp->next;
        p = p->next;
        delete temp;
    }

    cout << "Chars that survive: ";
    p = head;
    while (p != nullptr) {
        cout << p->c;
        temp = p;
        p = p->next;
        delete temp;
    }

    return 0;
}
