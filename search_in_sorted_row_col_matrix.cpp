// C++ program to search an element in row-wise
// and column-wise sorted matrix
#include <bits/stdc++.h>
 
using namespace std;
 
/* Searches the element x in mat[][]. If the
element is found, then prints its position
and returns true, otherwise prints "not found"
and returns false */
int search(int mat[4][4], int n, int x)
{
    if (n == 0)
        return -1;
   
    int smallest = mat[0][0], largest = mat[n - 1][n - 1];
    if (x < smallest || x > largest)
        return -1;
   
    // set indexes for top right element
    int i = 0, j = n - 1;
    while (i < n && j >= 0)
    {
        if (mat[i][j] == x)
        {
            cout << "n Found at "
                 << i << ", " << j;
            return 1;
        }
        if (mat[i][j] > x)
            j--;
       
        // Check if mat[i][j] < x
        else
            i++;
    }
 
    cout << "n Element not found";
    return 0;
}
