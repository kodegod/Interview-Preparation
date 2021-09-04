//https://practice.geeksforgeeks.org/problems/count-the-reversals0401/1


int countRev (string str)
{
    // your code here
    char op = '{';
    char cl = '}';
    stack<int> s;
    s.push(str[0]);
    for(int i=1; i<str.size(); i++)
    {
        if(str[i] == '{')
            s.push(str[i]);
        else
        {
            if(s.empty())
                s.push(str[i]);
                
            else if(s.top() == op)
                s.pop();
                
            else
                s.push(str[i]);
        }
    }
    if(s.size()%2==1)
        return -1;
    int ans = 0;
    while(!s.empty())
    {
        char a = s.top();
        s.pop();
        char b = s.top();
        s.pop();
        if( a == b)
            ans++;
        else
            ans+=2;
    }
    return ans;
}
