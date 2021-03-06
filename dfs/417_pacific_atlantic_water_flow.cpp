#include <vector>
#include <cstring>
using namespace std;


class Solution {
private:
    int atl[150][150];
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
 //       if(pc[i][j] == 0)
 //           return false;

        if(i == 0 || j == 0)
        {
            pc[i][j] = 1;
            return true;
        }

        for(int k = 0; k < 4; k++)
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

        if(atl[i][j] == 1)
            return true;
 //       if(atl[i][j] == 0)
 //           return false;

        if(i == matrix.size()-1 || j == matrix[0].size() - 1)
        {
            atl[i][j] = 1;
            return true;
        }

        for(int k = 0; k < 4; k++)
        {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if(nx >= 0 && nx < matrix.size() && ny >= 0 && ny < matrix[0].size() && flag1[nx][ny] != 1 && matrix[nx][ny] <= matrix[i][j] && reachAt(nx, ny, matrix))
            {
                atl[i][j] = 1;
                return true;
            }
        }

        atl[i][j] = 0;
        return false;
    }

public:
     vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> result;
        if(matrix.empty())
            return result;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            {
                atl[i][j] = -1;
                pc[i][j] = -1;
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
		Solution(){}
};

int main()// for test
{
	int a[5] = {1,2,2,3,4};
	int b[5] = {3,2,3,4,4};
	int c[5] = {2,4,5,3,1};
	int d[5] = {6,7,1,4,5};
	int e[5] = {5,1,1,2,4};

	vector<int> aa,bb,cc,dd,ee;
	for(int i = 0; i < 5; i++)
	{
		aa.push_back(a[i]);
		bb.push_back(b[i]);
		cc.push_back(c[i]);
		dd.push_back(d[i]);
		ee.push_back(e[i]);
	}

	vector<vector<int> > matrix;
	matrix.push_back(aa);
	matrix.push_back(bb);
	matrix.push_back(cc);
	matrix.push_back(dd);
	matrix.push_back(ee);
	Solution s;
	s.pacificAtlantic(matrix);
	return 0;
}
