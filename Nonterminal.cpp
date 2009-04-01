#ifndef NONTERMINAL_CPP_INCLUDED
#define NONTERMINAL_CPP_INCLUDED
#endif // NONTERMINAL_CPP_INCLUDED

class Nonterminal {
    //Store a nonterminal.
    private string symbol;
    //Store symbols on the right of production.
    private vector<Production> productions;
    //Store the positions which the nonterminal appears.
    private vector<type_position> positions;
    //Mark wheather the nonterminal can produce null.
    private bool none;

    //Constructor of Nonterminal.
    public void Nonterminal(string symbol) {
        this.symbol = symbol;
    }

    //Add a production.
    public addProduction(Production prod) {
        productions.push_back(prod);
    }

    //Add a position.
    public addPosition(Position posi) {
        positions.push_back(posi);
    }

    //Get a production
    public Production getProduction(int i) {
        if (i >=0 && i < productions.size())
            return productions[i];
        else
            return NULL;
    }

    public Production getPosition(int i) {
        if (i >=0 && i < positions.size())
            return positions[i];
        else
            return NULL;
    }

    public void setNone() {
        this.none = true;
    }

    public bool getNone() {
        return this.none;
    }
};
