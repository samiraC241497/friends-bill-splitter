#include <bits/stdc++.h>
using namespace std;

struct Friend {
    string name;
    float paid;
    float balance;
};

int main() {
    int n;
    cout << "Enter number of friends: ";
    cin >> n;

    vector<Friend> friends(n);

    // Taking name and paid amount input from user
    for (int i = 0; i < n; i++) {
        cout << "Enter name of friend " << i + 1 << ": ";
        cin >> friends[i].name;
        cout << "Enter amount paid by " << friends[i].name << ": ";
        cin >> friends[i].paid;
    }

    // Calculating total expense
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += friends[i].paid;
    }

    float perPerson = total / n;

    cout << fixed << setprecision(2);
    cout << "\nTotal expense: " << total << " Tk\n";
    cout << "Each person should pay: " << perPerson << " Tk\n\n";

    // Calculating balance for each person
    for (int i = 0; i < n; i++) {
        friends[i].balance = friends[i].paid - perPerson;
    }

    // Showing individual balance
    cout << "=== Settlements ===\n";
    for (int i = 0; i < n; i++) {
        if (friends[i].balance < 0) {
            cout << friends[i].name << " will GIVE " << -friends[i].balance << " Tk\n";
        } else if (friends[i].balance > 0) {
            cout << friends[i].name << " will RECEIVE " << friends[i].balance << " Tk\n";
        } else {
            cout << friends[i].name << " is SETTLED.\n";
        }
    }

    return 0;
}

