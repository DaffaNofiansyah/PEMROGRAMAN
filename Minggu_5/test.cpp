#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Account {
public:
    map<string, int> accounts;
    int transactions;

    Account(string number) {
        this->number = "";
        this->transactions = 1;
    }
};

int main() 
{
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        

        for (int i = 0; i < n; i++) {
            string accountNumber;
            getline(cin, accountNumber);

            if (accounts.count(accountNumber) == 0) {
                accounts[accountNumber] = new Account(accountNumber);
            } else {
                accounts[accountNumber]->transactions++;
            }
        }

        vector<Account> accountList;
        for (auto it = accounts.begin(); it != accounts.end(); it++) {
            accountList.push_back(*(it->second));
        }
        sort(accountList.begin(), accountList.end());

        for (auto account : accountList) {
            cout << account.number << " " << account.transactions << endl;
        }

        cout << endl;
    }

    return 0;
}
