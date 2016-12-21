#include <vector>
#include <cstring>
using namespace std;
class Solution {
private:
    int at[150][150];
    int pc[150][150];
    int flag1[150][150];
    int flag2[150][150];
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    bool reachPc(int i, int j, vector<vector<int>>& matrix)  //return true or false, update at and pc array
    {

        flag2[i][j] = 1;

        if(pc[i][j] == 1)
            return true;
//        if(pc[i][j] == 0)
//            return false;

        if(i == 0 || j == 0)
        {
            pc[i][j] = 1;
            return true;
        }

        for(int k = 0; k < 4; i++)
        {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if(nx >= 0 && nx < matrix.size() && ny >= 0 && ny < matrix[0].size() && flag2[nx][ny] != 1 && matrix[nx][ny] <= matrix[i][j] && reachPc(nx, ny, matrix))
            {
                pc[i][j] = 1;
                return true;
            }
        }

        pc[i][j] = 0;
        return false;
    }

    bool reachAt(int i, int j, vector<vector<int>>& matrix)  //return true or false, update at and pc array
    {

        flag1[i][j] = 1;

        if(at[i][j] == 1)
            return true;
//        if(at[i][j] == 0)
//            return false;

        if(i == matrix.size()-1 || j == matrix[0].size() - 1)
        {
            at[i][j] = 1;
            return true;
        }

        for(int k = 0; k < 4; i++)
        {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if(nx >= 0 && nx < matrix.size() && ny >= 0 && ny < matrix[0].size() && flag1[nx][ny] != 1 && matrix[nx][ny] <= matrix[i][j] && reachAt(nx, ny, matrix))
            {
                at[i][j] = 1;
                return true;
            }
        }

        at[i][j] = 0;
        return false;
    }

public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> result;
//        if(matrix.empty())
//            return result;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            {
                at[i][j] == -1;
                pc[i][j] == -1;
            }


        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            {
                memset(flag1, 0, sizeof(flag1));
                memset(flag2, 0, sizeof(flag2));
                if(reachAt(i, j, matrix) && reachPc(i, j, matrix))
                {
                    result.push_back(make_pair(i, j));
                }
            }

        return result;
    }
};
