#include <string>
#include <vector>
#include <set>
using namespace std;
struct Transaction {
    string name;
    int time;
    int amount;
    string city;
    Transaction(string t) {
        int data_field = 1;
        string part = "";
        for (int i = 0; i < t.size(); i++) {
            if (t[i] == ',') {
                if (data_field == 1) {
                    name = part;
                } else if (data_field == 2) {
                    time = stoi(part);
                } else if (data_field == 3) {
                    amount = stoi(part);
                }
                part = "";
                data_field++;
            } else {
                part += t[i];
            }
        }
        city = part;
    }
};

class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string> invalid;
        set<int> visited;

        vector<Transaction> record;
        for (string s : transactions) {
            record.push_back(Transaction(s));
        }

        for (int i = 0; i < record.size(); i++) {
            if (record[i].amount > 1000 && !(visited.find(i) != visited.end())) {
                invalid.push_back(transactions[i]);
                visited.insert(i);
            } else {
                for (int j = 0; j < record.size(); j++) {
                    if (!(visited.find(i) != visited.end()) && j != i && in_range(record[i].time, record[j].time, record[i].city, record[j].city, record[i].name, record[j].name)) {
                        invalid.push_back(transactions[i]);
                        visited.insert(i);
                    }
                }
            }
        }

        return invalid;
        
    }

private:
    bool in_range(int t1, int t2, string c1, string c2, string n1, string n2) {
        return ((t1 + 60 >= t2 && t1 <= t2) || (t1 - 60 <= t2 && t1 >= t2)) && c1 != c2 && n1 == n2;
    }
};