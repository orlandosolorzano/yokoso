#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

typedef map<string, int> type_symbolMap;
typedef pair<int, int> type_position;
typedef set<string> type_symbolSet;

class Production {
    private vector<string> rightSymbols;
    private type_symbolSet predictSet;

    public Production () {
    }

    public void addSymbol(string symbol) {
        rightSymbols.push_back(symbol);
    }

    public void addPredict(string symbol) {
    }
};

class Nonterminal {
    string symbol;
    vector<production> productions;
    vector<type_position> positions;
    bool none;

    Nonterminal(string symbol) {
        this.symbol = symbol;
    }
};

vector<nonterminal> nonterminals;
vector<type_symbolSet> firstSet;
vector<type_symbolSet> fellowSet;

type_symbolMap nonterminalMap;

int proNum, nonNum;

void init() {
    int i, j, k;
    freopen("in.txt", "r", stdin);
//    for (i = 0; i < NUM_NOT; i++) {
//        cin >> ch;
//        notion.push_back(ch);
//    }
    nonNum = 0;
    cin >> proNum;
    for (i = 0; i < proNUM; i++) {
        char symbol;
        cin >> symbol;
        Nonterminal * nonterPt;
        if (nontermialMap.find(symbol) == nonterminalMap.end()) {
            nonterminals.push_back(Nonterminal(symbol));
            nonterPt = &nonterminals[nonNum];
            nonterminalMap.insert(make_pair(symbol, nonNum++));
        } else {
            nonterPt = &nonterminals[nonterminalMap[symbol]];
        }
        cin >> k;
        for (j = 0; j < k; j++) {
            cin >> symbol;
            nonterPt->.push_back(ch);
        }

        if (k == 1 && product[i][0] == '_') none[i] = true;
    }
}

set<char, compare> first(int i) {
    if (!first_cal[i] == true) {
        char ch = product[i][0];

        if (notion_map.find(ch) == notion_map.end()) {
            first_set[i].insert(ch);
        } else {
            pair<multimap<char, int>::iterator, multimap<char, int>::iterator> not_pro = notion_map.equal_range(ch);
            for(it_map = not_pro.first; it_map != not_pro.second; it_map++){
                int no_pro = it_map->second;
                if (none[i]) {
                    set<char, compare> tmpFirst = first(no_pro);
                    set<char, compare> tmpRes;
                    set_union(first_set[i].begin(), first_set[i].end(), tmpFirst.begin(), tmpFirst.end(), tmpRes, compare());
                    first_set[i] = tmpRes;
                } else {
                    first_set[i].erase('_');
                    set<char, compare> tmpFirst = first(no_pro);
                    set<char, compare> tmpRes;
                    set_union(first_set[i].begin(), first_set[i].end(), tmpFirst.begin(), tmpFirst.end(), tmpRes, compare());
                    first_set[i] = tmpRes;
                }
            }
        }
        first_cal[i] = true;
    }
    return first_set[i];
}

int main()
{
    init();
    for (int i = 0; i < NUM_PRO; i++) {
        first(i);
        for (it_set = first_set[i].begin(); it_set != first_set[i].end(); it_set++) {
            cout << &it_set << '\t';
        }
        cout << endl;
    }
    cout << "////////////////////////////" <<endl;
    for (int i = 0; i < NUM_PRO; i++) {
        for (int j = 0; j < product[i].size(); j++) {
            cout << product[i][j] << '\t';
        }
        cout << endl;
    }
    return 0;
}
