#include <bits/stdc++.h>
#include <omp.h>
using namespace std;

typedef long long int ll;

int main()
{
    ll n, m = 0;
    cin >> n;
    double startTime = omp_get_wtime();
    if(n/100)   //Checks if its possible to use 100 bill
        m+=(n/100), n-=(n/100)*100; //Adds 100 bills used to m, reduce n by money taken in 100 bills
    if(n/20)   //Checks if its possible to use 20 bill
        m+=(n/20), n-=(n/20)*20; //Adds 50 bills used to m, reduce n by money taken in 50 bills
    if(n/10)   //Checks if its possible to use 10 bill
        m+=(n/10), n-=(n/10)*10; //Adds 20 bills used to m, reduce n by money taken in 20 bills
    if(n/5)   //Checks if its possible to use 5 bill
        m+=(n/5), n-=(n/5)*5; //Adds 10 bills used to m, reduce n by money taken in 10 bills
    m+=n;   //Use 1 bill for the leftover money
    cout<<m;
    double endTime = omp_get_wtime();
    cout<< fixed << setprecision(5) << "Start time: " << startTime << endl;
    cout<< fixed << setprecision(5) << "End time: " << endTime << endl;
    cout<< fixed << setprecision(5) << "Process time: " << endTime - startTime << endl;

    return 0;
}
