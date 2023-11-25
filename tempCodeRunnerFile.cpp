
        for(int j=0;j<=property;j++)
            dp[i][j]=j>v[i]? max(dp[i-1][j],dp[i-1][j-v[i]]+v[i]*w[i]):dp[i-1][j];