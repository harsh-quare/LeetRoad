class Spreadsheet {
private:
    unordered_map<string, int> cells;

    bool isNumber(const string& s){
        for(char c : s){
            if(!isdigit(c)) return false;
        }
        return true;
    }

public:
    Spreadsheet(int rows){
    }
    
    void setCell(string cell, int value) {
        cells[cell] = value;
    }
    
    void resetCell(string cell) {
        cells[cell] = 0;
    }
    
    int getValue(string formula) {
        size_t plusPos = formula.find('+'); 

        string left = formula.substr(1, plusPos - 1); 
        string right = formula.substr(plusPos + 1); 
        
        int leftValue = isNumber(left) ? stoi(left) : cells[left];
        int rightValue = isNumber(right) ? stoi(right) : cells[right];

        return leftValue + rightValue;
    }
};