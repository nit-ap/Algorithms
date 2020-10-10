//Finding the number of ways to reach a particular position in a grid from a starting position (given some cells which are blocked)


#include <bits/stdc++.h>
    using namespace std;
    typedef long long int ll;
    #define F(i,a,b) for(int i = (int)(a); i <= (int)(b); i++)
    #define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
    #define MOD 1000000007
    int main()
    {
        int M,N,P,_i,_j;

        //Take input the number of rows, columns and blocked cells
        cin>>M>>N>>P;

        //declaring a Grid array which stores the number of paths
        ll Grid[M+1][N+1];

        //Note that we'll be using 1-based indexing here.
        //initialize all paths initially as 0
        memset(Grid, 0, sizeof(Grid));

        F(i,0,P-1)
        {
            //Take in the blocked cells and mark them with a special value(-1 here)
            cin>>_i>>_j;
            Grid[_i][_j] = -1;
        }

        // If the initial cell is blocked, there is no way of moving anywhere
        if(Grid[1][1] == -1)
        {
            printf("0");
            return 0;
        }


        // Initializing the leftmost column
        //Here, If we encounter a blocked cell, there is no way of visiting any cell
        //directly below it.(therefore the break)
        F(i,1,M)
        {
            if(Grid[i][1] == 0) Grid[i][1] = 1LL;
            else break;
        }


        //Similarly initialize the topmost row.
        F(i,2,N)
        {
            if(Grid[1][i] == 0) Grid[1][i] = 1LL;
            else break;
        }


        //Now the recurrence part
        //The only difference is that if a cell has been marked as -1,
        //simply ignore it and continue to the next iteration.
        F(i,2,M)
        {
            F(j,2,N)
            {
                if(Grid[i][j] == -1) continue;

                //While adding the number of ways from the left and top cells,
                //check that they are reachable,i.e. they aren't blocked

                if(Grid[i-1][j] > 0) Grid[i][j] = (Grid[i][j] + Grid[i-1][j] + MOD)%MOD;
                if(Grid[i][j-1] > 0) Grid[i][j] = (Grid[i][j] + Grid[i][j-1] + MOD)%MOD;
            }
        }


        //If the final cell is blocked, output 0, otherwise the answer
        printf("%lld",(Grid[M][N] >= 0 ? Grid[M][N] : 0));
        return 0;
    }
