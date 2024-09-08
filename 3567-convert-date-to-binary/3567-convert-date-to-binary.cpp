class Solution {
public:
    string convertDateToBinary(string date) {
        int year= stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        
        string y = bitset<12>(year).to_string();
        string m = bitset<4>(month).to_string();
        string d = bitset<5>(day).to_string();
        
        y = y.substr(y.find('1'));
        m = m.substr(m.find('1'));
        d = d.substr(d.find('1'));
        
        return y + "-" + m + "-" + d;
    }
};