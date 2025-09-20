class Spreadsheet {
private:
    map<pair<int, int>, int> mp;
    pair<int, int> findCoords(string cell){
        int i = cell[0] - 'A';
        int j = stoi(cell.substr(1));

        return {i, j};
    }


public:
    Spreadsheet(int rows) {
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < 26; j++){
                mp[{i,j}] = 0;
            }
        }
    }
    
    void setCell(string cell, int value) {
        pair<int, int> coords = findCoords(cell);
        mp[{coords.first, coords.second}] = value;
    }
    
    void resetCell(string cell) {
        pair<int, int> coords = findCoords(cell);
        mp[{coords.first, coords.second}] = 0;
    }
    
    int getValue(string formula) {
        // first expression
        int i = 1, j = 1;
        bool isIntgr1 = isdigit(formula[i]);
        while(j < formula.size() && formula[j] != '+'){
            j++;
        }

        string eval1 = formula.substr(i, j-i);
        int val1 = 0;
        pair<int, int> coord1;
        if(isIntgr1){
            val1 = stoi(eval1);
        }
        else{
            coord1 = findCoords(eval1);
        }

        // second expression
        i = j+1, j = i;
        bool isIntgr2 = isdigit(formula[i]);
        string eval2 = formula.substr(i);  // till end
        int val2 = 0;
        pair<int, int> coord2;
        if(isIntgr2){
            val2 = stoi(eval2);
        }
        else{
            coord2 = findCoords(eval2);
        }

        if(isIntgr1 && isIntgr2){
            return val1 + val2;
        }
        else if(isIntgr1 && !isIntgr2){
            return val1 + mp[{coord2.first, coord2.second}];
        }
        else if(!isIntgr1 && isIntgr2){
            return val2 + mp[{coord1.first, coord1.second}];
        }
        else{
            return mp[{coord1.first, coord1.second}] + mp[{coord2.first, coord2.second}];
        }
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */