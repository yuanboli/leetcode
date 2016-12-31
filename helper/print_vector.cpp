void printVector(const vector<vector<int> >& res)
{
    cout << "[";
    for(int i = 0; i < res.size(); i++)
    {
        cout << "[";
        for(int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << ",";
        }
        cout << "\b";

        cout << "]" << ", ";
    }
		cout << "\b\b";
    cout << "]\n";
}
