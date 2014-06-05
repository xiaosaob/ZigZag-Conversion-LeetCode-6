// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"
// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string text, int nRows);
// convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows == 1) return s;
        vector<string> res(nRows, "");
        int curRow = 0;
        int step = 1;
        for(int i = 0; i < s.size(); ++i) {
            res[curRow] += s[i];
            curRow += step;
            if(curRow == nRows) {
                curRow -= 2;
                step = -1;
            } else if(curRow < 0) {
                curRow += 2;
                step = 1;
            }
        }
        string resStr("");
        for(int i = 0; i < res.size(); ++i)
            resStr += res[i];
        return resStr;
    }
};
