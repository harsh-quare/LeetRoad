class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.length();
        int A = 0;
        int B = 0;

        for(int i = 1; i < n-1; i++){
            if(colors[i]=='A' && colors[i-1]=='A' && colors[i+1]=='A') A++;
            if(colors[i]=='B' && colors[i-1]=='B' && colors[i+1]=='B') B++;
        }

        return (A > B);
    }
};