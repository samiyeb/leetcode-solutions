#include <string>
#include <map>
#include <set>
using namespace std;
class Solution {
public:
    bool equalFrequency(string word) {
        for (int i = 0 ; i < word.size(); i++) {
            map<char, int> freq = find_frequency(word, i);

            if (is_equal(freq)) {
                return true;
            }
        }

        return false;
        
    }

    map<char, int> find_frequency(string word, int index) {
        map<char, int> freq;

        for (int i = 0; i < word.size(); i++) {
            if (i != index) {
                freq[word[i]]++;
            }
        }
        return freq;
    }

    bool is_equal(map<char, int> freq) {
        set<int> frequencies;

        for (pair<char, int> index_to_count : freq) {
            frequencies.insert(index_to_count.second);
        }

        return frequencies.size() == 1;
    }
};