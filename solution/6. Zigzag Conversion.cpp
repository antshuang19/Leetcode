class Solution {
public:
    string convert(string s, int numRows) 
    {
        if(numRows == 1) return s;
        vector<string> temp (min(numRows,int(s.size())));
        int current_row =0;
        bool down = false;
        for(char character : s)
        {
            temp[current_row] += character;
            if(current_row == 0 or current_row == numRows-1) down = !down;
            current_row = current_row + (down ? 1:-1);
        }
        //convert vector to string
        string result;
        for(string row : temp)
        {
            result += row;
        }
        return result;
    }
};