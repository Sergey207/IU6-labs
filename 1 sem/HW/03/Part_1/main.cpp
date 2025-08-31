#include <iostream>
using namespace std;

struct q_elem {
    string word;
    q_elem* next = nullptr;
};

int main() {
    cout << "Enter amount of elements: ";
    int N;
    cin >> N;

    if (N <= 0) {
        cout << "Amount of elements must be > 0!\n";
        return -1;
    }

    q_elem* head = nullptr;
    q_elem* tail = nullptr;

    for (int i = 0; i < N; ++i) {
        auto* new_elem = new q_elem();
        cin >> new_elem->word;

        if (head == nullptr) {
            head = new_elem;
        } else {
            tail->next = new_elem;
        }
        tail = new_elem;
    }

    int counter = 0;
    q_elem* p = head;
    q_elem* prev = nullptr;

    while (p != nullptr) {
        if (p->word.find('a') != string::npos) {
            if (p == head) {
                head = p->next;
                delete p;
                p = head;
            } else {
                prev->next = p->next;
                delete p;
                p = prev->next;
            }
            counter++;
        } else {
            prev = p;
            p = p->next;
        }
    }

    cout << "Deleted " << counter << " elements\n";
    cout << "Remaining elements:\n";

    p = head;
    while (p != nullptr) {
        cout << p->word << endl;
        const q_elem* temp = p;
        p = p->next;
        delete temp;
    }

    return 0;
}
