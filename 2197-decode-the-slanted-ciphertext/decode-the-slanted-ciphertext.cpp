class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        string ans;
        int cols = encodedText.size() / rows;
        int row = 0, col = 0;
        int colPrime = 0;

        while (colPrime < cols) {        // break condition moved here
            if (row > rows - 1) {
                row = 0;
                colPrime++;
                col = colPrime;
            }
            if (col < cols) {            // only read valid columns
                int index = (row * cols) + col;
                ans += encodedText[index];
            }
            row++;
            col++;
        }

        while (!ans.empty() && ans.back() == ' ')
            ans.pop_back();

        return ans;
    }
};