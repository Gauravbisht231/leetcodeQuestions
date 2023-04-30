// leetcode weekly contest 343 easy quesiton -> 30/4/23
class Solution
{
public:
    int isWinner(vector<int> &a, vector<int> &b)
    {
        int score1 = 0, score2 = 0;
        for (size_t i = 0; i < a.size(); i++)
        {
            if ((i > 0 && a[i - 1] == 10) || (i > 1 && a[i - 2] == 10))
                score1 += 2 * a[i];
            else
                score1 += a[i];
        }
 
        for (size_t i = 0; i < b.size(); i++)
        {
            if ((i > 0 && b[i - 1] == 10) || (i > 1 && b[i - 2] == 10))
                score2 += 2 * b[i];
            else
                score2 += b[i];
        }
 
        return (score1 == score2 ? 0 : (score1 > score2 ? 1 : 2));
    }
};
