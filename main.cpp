#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

typedef map<string, int> SymbolMap;
typedef pair<int, int> Position;
typedef set<string> SymbolSet;
typedef vector<string> Production;

class Nonterminal {
    //Store a nonterminal.
    string symbol;
    //Store symbols on the right of production.
    vector<Production> productions;
    //Store the positions which the nonterminal appears.
    vector<type_position> positions;
    //Mark wheather the nonterminal can produce null.
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
    freopen("in.txt", "r", stdin);

    int i, j, k;

    cin >> proNum;
    nonNum = 0;

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
