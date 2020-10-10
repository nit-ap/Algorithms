// Finding the number of ways to reach from a starting position to an ending position travelling in specified directions only



#include <bits/stdc++.h>
    using namespace std;
    #define F(i,a,b) for(int i = (int)(a); i <= (int)(b); i++)
    #define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
    int main()
    {
        int X,Y; //X:number of rows, Y: number of columns
        X = Y = 10; //assuming 10X10 matrix

        int NumWays[X][Y]; //declare the NumWays matrix
        NumWays[0][0] = 1;
        // initialize first row of NumWays matrix
        F(j,1,Y-1)
            NumWays[0][j] = 1;
        //Initialize first column of NumWays Matrix
        F(i,1,X-1)
            NumWays[i][0] = 1;
        //This bottom-up approach ensures that all the sub-problems needed
        // have already been calculated.
        F(i,1,X-1)
        {
            F(j,1,Y-1)
            {
                //Calculate number of ways visiting (i,j) using the
                //recurrence relation discussed above
                NumWays[i][j] = NumWays[i-1][j] + NumWays[i][j-1];
            }
        }

        cout<<"Number of ways from(0,0) to (X,Y) is "<<NumWays[X-1][Y-1];
        return 0;
    }