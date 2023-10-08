// https://www.luogu.com.cn/problem/P1004
#include <bits/stdc++.h>
using namespace std;
int n;
int mp[15][15];
int ans[15][15][15][15];
int main()
{
    scanf("%d", &n);
    while (true)
    {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        if (x == 0 && y == 0 && z == 0)
        {
            break;
        }
        mp[x][y] = z;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int u = 1; u <= n; u++)
            {
                for (int v = 1; v <= n; v++)
                {
                    ans[i][j][u][v] = max(max(ans[i - 1][j][u - 1][v], ans[i - 1][j][u][v - 1]), max(ans[i][j - 1][u - 1][v], ans[i][j - 1][u][v - 1])) + mp[i][j] + mp[u][v];
                    if (i == u && j == v)
                    {
                        ans[i][j][u][v] -= mp[i][j];
                    }
                }
            }
        }
    }
    printf("%d", ans[n][n][n][n]);
}
/*
1. 原始提交
#include<stdio.h>
int n,i,j,tmp,k,l;
int puz[20][20], dp[20][20][20][20];
int max(int x,int y)
{
    if(x>y)
        return x;
    else
        return y;
}
int main()
{
       scanf("%d",&n);
       while(~scanf("%d %d %d", &i, &j, &tmp) && (i||j||tmp))
        puz[i][j] = tmp;

          for(i = 1;i <= n; i++)
              for(j = 1; j <= n; j++)
                  for(k = 1; k <= n; k++)
                      for(l = 1; l <= n; l++) {
                              dp[i][j][k][l] = max(max(dp[i-1][j][k-1][l],dp[i][j-1][k][l-1]),max(dp[i-1][j][k][l-1],dp[i][j-1][k-1][l]))+puz[i][j];
                             if(i != k||j != l) dp[i][j][k][l] += puz[k][l];
                             }
        printf("%d\n", dp[n][n][n][n]);
        return 0;
}


2.想不出来，看了一下以前提交的代码写了一版
#include <bits/stdc++.h>
using namespace std;
int n;
int mp[15][15];
int ans[15][15][15][15];
int main()
{
    scanf("%d", &n);
    while (true)
    {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        if (x == 0 && y == 0 && z == 0)
        {
            break;
        }
        mp[x][y] = z;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int u = 1; u <= n; u++)
            {
                for (int v = 1; v <= n; v++)
                {
                    ans[i][j][u][v] = max(max(ans[i - 1][j][u - 1][v], ans[i - 1][j][u][v - 1]), max(ans[i][j - 1][u - 1][v], ans[i][j - 1][u][v - 1])) + mp[i][j] + mp[u][v];
                    if (i == u && j == v)
                    {
                        ans[i][j][u][v] -= mp[i][j];
                    }
                }
            }
        }
    }
    printf("%d", ans[n][n][n][n]);
}
*/