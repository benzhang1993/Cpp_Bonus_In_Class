#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

template <class T>
class too_low {
    T cutoff;
public:
    too_low(const T& c) {
        cutoff = c;
    }

    bool operator()(const T& value){
        return (value < cutoff);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;

    multimap<int, string> tonylist;
    multimap<int, string> samlist;
    multimap<int, string> bothlist;

    bool ended = false;
    string name;
    int grades;

    while(!ended) {
        cout << "Tony please enter friend name, enter done to continue" << endl;
        cin >> name;
        if(name == "done") {
            break;
        }
        cout << "Please enter friend's grades" << endl;
        cin >> grades;
        tonylist.insert(pair<int, string>(grades, name));
    }

    while(!ended) {
        cout << "Sam please enter friend name, enter done to quit" << endl;
        cin >> name;
        if(name == "done") {
            break;
        }
        cout << "Please enter friend's grades" << endl;
        cin >> grades;
        samlist.insert(pair<int, string>(grades, name));
    }

    bothlist.insert(tonylist.begin(), tonylist.end());
    bothlist.insert(samlist.begin(), samlist.end());

    for(auto it = bothlist.begin(); it != bothlist.end(); it++) {
        auto nextit = it++;
        if(nextit->first == it->first && nextit->second == it->second) {
            bothlist.erase(nextit);
        }
    }


    cout << "Tony's list: " << endl;
    for(auto it = tonylist.begin(); it != tonylist.end(); it++) {
        cout << it->second << ' ' << it->first << endl;
    }

    cout << "\nSam's list: " << endl;
    for(auto it = samlist.begin(); it != samlist.end(); it++) {
        cout << it->second << ' ' << it->first << endl;
    }

    cout << "\nCombined list: " << endl;
    for(auto it = bothlist.begin(); it != bothlist.end(); it++) {
        cout << it->second << ' ' << it->first << endl;
    }

    too_low<int> t(75);

    vector<int> list;

    cout << "\nAfter too low Combined list: " << endl;
    for(auto it = bothlist.begin(); it != bothlist.end(); it++) {
        if(t(it->first)) {
            list.push_back(it->first);
        }
    }

    for(int integer: list) {
        bothlist.erase(integer);
    }

    for(auto it = bothlist.begin(); it != bothlist.end(); it++) {
        cout << it->second << ' ' << it->first << endl;
    }

    return 0;
}