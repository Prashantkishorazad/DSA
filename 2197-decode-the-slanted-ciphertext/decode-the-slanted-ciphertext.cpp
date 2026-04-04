class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (rows == 1) return encodedText;
        
        int n = encodedText.size();
        int cols = n / rows;
        
        vector<vector<char>> matrix(rows, vector<char>(cols));
        
        // Fill matrix row-wise
        int idx = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = encodedText[idx++];
            }
        }
        
        // Read diagonally
        string result = "";
        
        for (int j = 0; j < cols; j++) {
            int i = 0, k = j;
            while (i < rows && k < cols) {
                result += matrix[i][k];
                i++;
                k++;
            }
        }
        
        // Remove trailing spaces
        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }
        
        return result;
    }
};