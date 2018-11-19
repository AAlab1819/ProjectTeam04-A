#include<bits/stdc++.h>
#include<omp.h>
using namespace std;

typedef long long ll;

// m is size of coins array (number of different coins)
ll minCoins(int coins[], int m, ll V)
{
    // table[i] will be storing the minimum number of coins
    // required for i value.  So table[V] will have result
    ll table[V+1];

    // Base case (If given value V is 0)
    table[0] = 0;

    // Initialize all table values as Infinite
    for (ll i=1; i<=V; i++)
        table[i] = LONG_LONG_MAX;

    // Compute minimum coins required for all
    // values from 1 to V
    for (ll i=1; i<=V; i++)
    {
        // Go through all coins smaller than i
        for (int j=0; j<m; j++)
          if (coins[j] <= i)
          {
              ll sub_res = table[i-coins[j]];
              if (sub_res != LONG_LONG_MAX && sub_res + 1 < table[i])
                  table[i] = sub_res + 1;
          }
    }
    return table[V];
}

int main()
{
    int coins[] =  {1,5,10,20,100}, m = 5;
    ll V;
    cin>>V;
    double startTime = omp_get_wtime();
    cout<<minCoins(coins, m, V)<<endl;
    double endTime = omp_get_wtime();
    cout<< fixed << setprecision(5) << "Start time: " << startTime << endl;
    cout<< fixed << setprecision(5) << "End time: " << endTime << endl;
    cout<< fixed << setprecision(5) << "Process time: " << endTime - startTime << endl;
    return 0;
}
