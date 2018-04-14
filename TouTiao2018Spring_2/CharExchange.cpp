#include <iostream> 
#include <string.h> 
#include <algorithm> 
#define N 26 
using namespace std; 
int main() 
{ 
    string str; 
    int num; 
    cin >> str >> num; 
    int length = str.length(); 
    int a[length][N]; 
    int b[N]; //存放各字母在满足约束的情况下最大的连续数 
    int m[length]; 
    memset(a,0,sizeof(a)); 
    memset(b,0,sizeof(b)); 
    memset(m,0,sizeof(m)); 
    //lengthx26的矩阵，出现字母的地方都置1 
    for(int i=0;i<length;i++) 
    { 
        for(int j=0;j<N;j++) 
        { 
            a[i][str[i]-'a'] = 1; 
        } 
    }
    for(int j=0;j<N;j++) 
    { 
        int k=0; 
        for(int i=0;i<length;i++) 
        { 
            if(a[i][j] == 1) 
            { 
                m[k++] = i; 
            } 
        } 
        if(k == 1) 
        { 
            b[j] = 1; 
        } 
        else 
        { 
            //dynamic programming 
            vector<vector<int> > dp(k,vector<int> (k,0));
            for(int i=0;i<k-1;i++)
            {
                dp[i][i+1]=m[i+1]-m[i]-1;
            }
            for(int j=2;j<k;j++)
            {
                for(int i=0;i<k-j;i++)
                {
                    dp[i][i+j]=dp[i+1][i+j-1]+m[i+j]-m[i]-j;
                }
            }
            int temp=-1; 
            for(int i=0;i<k;i++) 
            { 
                for(int ii=i+1;ii<k;ii++) 
                { 
                    if( dp[i][ii]<= num ) 
                    { 
                        if((ii-i)+1> temp) 
                            temp = (ii-i)+1; 
                    } 
                } 
            } 
            b[j] = temp; 
        } 
    
    } 
    sort(b,b+N); 
    cout << b[N-1] << endl; 
    return 0; 
}
