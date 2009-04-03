#ifndef NONTERMINAL_H_INCLUDED
#define NONTERMINAL_H_INCLUDED
#endif // NONTERMINAL_H_INCLUDED

class Nonterminal {

private:
    //Store a nonterminal.
    string symbol;
    //Store symbols on the right of production.
    vector<Production> productions;
    //Store the positions which the nonterminal appears.
    vector<Position> positions;
    //Mark wheather the nonterminal can derive null.
    bool isNull;

public:
    //Constructor of Nonterminal.
    Nonterminal(string symbol) {
        this->symbol = symbol;
    }

    //Add a production.
    void addProduction(Production prod) {
        productions.push_back(prod);
    }

    //Add a position.
    void addPosition(Position posi) {
        positions.push_back(posi);
    }

    //Get a production.
    Production getProduction(unsigned int i) {
        if (i >= 0 && i < productions.size())
            return productions[i];
    }

    //Get a position.
    Position getPosition(unsigned int i) {
        if (i >=0 && i < positions.size())
            return positions[i];
    }

    //Mark the nonterminal derives null;
    void setNull() {
        this->isNull = true;
    }

    //Get the state of isNull.
    bool getNull() {
        return this->isNull;
    }

    //Get the size of productions' vector.
    int getProSize() {
        return this->productions.size();
    }

    //Get the size of positions' vector.
    int getPosSize() {
        return this->positions.size();
    }

    //Get the nonterminal symbol.
    string getSymbol() {
        return this->symbol;
    }
};

