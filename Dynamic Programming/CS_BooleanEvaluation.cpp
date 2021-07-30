//https://www.codingninjas.com/codestudio/problems/problem-name-boolean-evaluation_1214650?leftPanelTab=2

#include<bits/stdc++.h>
using namespace std;

int evaluateExp(string & exp) {
    // Write your code here.
    string ch,op;
    for(int i=0; i<exp.size(); i++)
    {
        if(i%2==0)
            ch.push_back(exp[i]);
        else
            op.push_back(exp[i]);
    }
    int n = ch.size();
    int dpt[n][n];
    int dpf[n][n];
    memset(dpt,0,sizeof dpt);
    memset(dpf,0,sizeof dpf);
    for(int i=0; i<n; i++)
    {
        if(ch[i]=='T')
        {
            dpt[i][i] = 1;
            dpf[i][i] = 0;
        }
        else
        {
            dpf[i][i] = 1;
            dpt[i][i] = 0;
        }
    }
    for(int d=1; d<n; d++)
    {
        int i=0, j=d; 
        while(i<n && j<n)
        {
            for(int k=i; k<j; k++)
            {
                if(op[k]=='^')
                {
                    dpt[i][j] += dpt[i][k]*dpf[k+1][j] + dpf[i][k]*dpt[k+1][j];
                    dpf[i][j] += dpt[i][k]*dpt[k+1][j] + dpf[i][k]*dpf[k+1][j];
                }
                else if(op[k]=='|')
                {
                    dpt[i][j] += dpt[i][k]*dpf[k+1][j] + dpf[i][k]*dpt[k+1][j] + dpt[i][k]*dpt[k+1][j];
                    dpf[i][j] += dpf[i][k]*dpf[k+1][j];
                }
                else
                {
                    dpt[i][j] += dpt[i][k]*dpt[k+1][j];
                    dpf[i][j] += dpt[i][k]*dpf[k+1][j] + dpf[i][k]*dpt[k+1][j] + dpf[i][k]*dpf[k+1][j];
                }
            }
            i++;
            j++;
        }
    }
    return dpt[0][n-1];
}
