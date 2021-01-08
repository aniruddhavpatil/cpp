class SubrectangleQueries {
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        sRectangle = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        changes.push_back({row1, col1, row2, col2, newValue});
        return;
    }
        
    
    int getValue(int row, int col) {
        for(int i = changes.size() - 1; i >= 0 ; --i){
            if(changes[i][0] <= row && changes[i][2] >= row && changes[i][1] <= col && changes[i][3] >= col) return changes[i][4];
        }
        return sRectangle[row][col];
    }
 private:
    vector<vector<int>> sRectangle;
    vector<vector<int>> changes;
    
};