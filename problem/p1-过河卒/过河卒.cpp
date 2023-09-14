// https://www.luogu.com.cn/problem/P1002
#include <bits/stdc++.h>
using namespace std;
int mp[25][25];
int n, m, a, b;
int dir1[2][2] = {{1, 0}, {0, 1}};
int dir2[9][2] = {{0, 0}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
long long ans[25][25];
int main()
{
    scanf("%d%d%d%d", &n, &m, &a, &b);
    for (int i = 0; i < 9; i++)
    {
        int x = a + dir2[i][0], y = b + dir2[i][1];
        if (x < 0 || y < 0)
        {
            continue;
        }
        mp[x][y] = 1;
    }

    if (mp[0][0] == 1)
    {
        ans[0][0] = 0;
    }
    else
    {
        ans[0][0] = 1;
    }

    for (int i = 1; i <= m; i++)
    {
        if (mp[0][i] == 1)
        {
            ans[0][i] = 0;
        }
        else
        {
            ans[0][i] = ans[0][i - 1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (mp[i][0] == 1)
        {
            ans[i][0] = 0;
        }
        else
        {
            ans[i][0] = ans[i - 1][0];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (mp[i][j] == 1)
            {
                ans[i][j] = 0;
            }
            else
            {
                ans[i][j] = ans[i - 1][j] + ans[i][j - 1];
            }
        }
    }

    printf("%lld", ans[n][m]);
    return 0;
}

/*
1.原始提交
#include<stdio.h>
int main()
{
    int book[25][25]={0},n,m,x,y;
    long long a[25][25]={0};
    a[0][0]=1;
    scanf("%d %d %d %d",&n,&m,&x,&y);
    book[x][y]=1;book[x+1][y+2]=1;book[x+2][y+1]=1;
    if(x-1>=0)book[x-1][y+2]=1;
    if(x-2>=0)book[x-2][y+1]=1;
    if(y-1>=0)book[x+2][y-1]=1;
    if(y-2>=0)book[x+1][y-2]=1;
    if(x-1>=0&&y-2>=0)book[x-1][y-2]=1;
    if(x-2>=0&&y-1>=0)book[x-2][y-1]=1;
    for(int i = 0; i <= n;i++)
    {
        for(int j = 0; j <= m; j++)
        {
            if(i-1>=0&&book[i-1][j]==0)
                a[i][j]+=a[i-1][j];
            if(j-1>=0&&book[i][j-1]==0)
                a[i][j]+=a[i][j-1];
        }
    }
    printf("%lld",a[n][m]);
    return 0;
}


2.自写1，tle

#include <bits/stdc++.h>
using namespace std;
int mp[25][25];
int n, m, a, b;
int sum = 0;
int dir1[2][2] = {{1, 0}, {0, 1}};
int dir2[9][2] = {{0, 0}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
void dfs(int x, int y)
{
    if(x > n || y > m || mp[x][y] == 1){
        return;
    }
    if (x == n && y == m){
        sum++;
        return;
    }
    for (int i = 0; i < 2; i++)
    {
        dfs(x+dir1[i][0],y+dir1[i][1]);
    }
}
int main()
{
    scanf("%d%d%d%d", &n, &m, &a, &b);
    for (int i = 0; i < 9; i++)
    {
        int x = a + dir2[i][0], y = b + dir2[i][1];
        if(x < 0 || y < 0){
            continue;
        }
        mp[x][y] = 1;
    }
    // for(int i = 0; i <= 10; i++){
    //     for(int j = 0; j <= 10; j++){
    //         printf("%d ",mp[i][j]);
    //     }
    //     printf("\n");
    // }
    dfs(0, 0);
    printf("%d",sum);
    return 0;
}
*/