#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> input()
{
    vector <int> p;
    int a = 0;
    cout << "Vvedite n1:" << endl;
    cin >> a;
    p.push_back(a);
    cout << "Vvedite m1:" << endl;
    cin >> a;
    p.push_back(a);
    cout << "Vvedite n2:" << endl;
    cin >> a;
    p.push_back(a);
    cout << "Vvedite m2" << endl;
    cin >> a;
    p.push_back(a);
    return p;
}
vector<int> getPath(int n, int m)
{
    vector<int> path;
    int current = 1;
    do 
    {
        path.push_back(current);  
        current = ((current - 1 + m - 1) % n) + 1;

    } while (current != 1);

    return path;
}

int main()
{
    vector<int> param = input();
    vector<int> path1 = getPath(param[0], param[1]);
    vector<int> path2 = getPath(param[2], param[3]);
    cout << "Konechnyi put': ";
    for (int i = 0; i <= path1.size()-1; i++)
    {
        cout << path1[i];
    }
    for (int i = 0; i <= path2.size() - 1; i++)
    {
        cout << path2[i];
    }
}   

