#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

#include "globaldef.h"
#include "Nonterminal.h"

vector<Nonterminal> nonterminals;
vector<SymbolSet> firstSet;
vector<SymbolSet> fellowSet;

SymbolMap nonterminalMap;

int nonSize, proSize;



void init() {
    freopen("in.txt", "r", stdin);

    int i, j;

    cin >> proSize;
    nonSize = 0;

    for (i = 0; i < proSize; i++) {
        string symbol;
        cin >> symbol;
        Nonterminal * nonterPt;
        Production productTmp;
        int symSize;

        if (nonterminalMap.find(symbol) == nonterminalMap.end()) {
            nonterminals.push_back(Nonterminal(symbol));
            nonterPt = &nonterminals[nonSize];
            nonterminalMap.insert(make_pair(symbol, nonSize++));
        } else {
            nonterPt = &nonterminals[nonterminalMap[symbol]];
        }

        cin >> symSize;
        for (j = 0; j < symSize; j++) {
            cin >> symbol;
            productTmp.push_back(symbol);
        }

        nonterPt->addProduction(productTmp);

        if (symSize == 0) {
            nonterPt->setNull();
        }
    }
}

//set<char, compare> first(int i) {
//    if (!first_cal[i] == true) {
//        char ch = product[i][0];
//
//        if (notion_map.find(ch) == notion_map.end()) {
//            first_set[i].insert(ch);
//        } else {
//            pair<multimap<char, int>::iterator, multimap<char, int>::iterator> not_pro = notion_map.equal_range(ch);
//            for(it_map = not_pro.first; it_map != not_pro.second; it_map++){
//                int no_pro = it_map->second;
//                if (none[i]) {
//                    set<char, compare> tmpFirst = first(no_pro);
//                    set<char, compare> tmpRes;
//                    set_union(first_set[i].begin(), first_set[i].end(), tmpFirst.begin(), tmpFirst.end(), tmpRes, compare());
//                    first_set[i] = tmpRes;
//                } else {
//                    first_set[i].erase('_');
//                    set<char, compare> tmpFirst = first(no_pro);
//                    set<char, compare> tmpRes;
//                    set_union(first_set[i].begin(), first_set[i].end(), tmpFirst.begin(), tmpFirst.end(), tmpRes, compare());
//                    first_set[i] = tmpRes;
//                }
//            }
//        }
//        first_cal[i] = true;
//    }
//    return first_set[i];
//}

int main()
{
    init();
//    for (int i = 0; i < NUM_PRO; i++) {
//        first(i);
//        for (it_set = first_set[i].begin(); it_set != first_set[i].end(); it_set++) {
//            cout << &it_set << '\t';
//        }
//        cout << endl;
//    }
    cout << "////////////////////////////" <<endl;
    for (int i = 0; i < nonSize; i++) {
        for (int j = 0; j < nonterminals[i].getProSize(); j++) {
            Production productTmp = nonterminals[i].getProduction(j);
            cout << nonterminals[i].getSymbol() << " ->";
            for (int k = 0; k < productTmp.size(); k++) {
                cout << ' ' << productTmp[k];
            }
            cout << endl;
        }
    }
    return 0;
}
