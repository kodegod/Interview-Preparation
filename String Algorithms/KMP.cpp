vector<int> lps;

void calcLPS(string &s, int n)
{
    int len = 0;
    int i = 1;
    while (i < n)
    {
        if (s[i] == s[len])
        {
            lps[i] = ++len;
            i++;
        }
        else
        {
            if (len > 0)
                len = lps[len - 1];
            else
            {
                len = 0;
                i++;
            }
        }
    }
}
