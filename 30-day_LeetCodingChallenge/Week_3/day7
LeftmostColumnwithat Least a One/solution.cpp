/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int n = binaryMatrix.dimensions()[0];
        int m = binaryMatrix.dimensions()[1];
        int i = 0, j = m-1 , ans = -1;
       
        
        while(i<n && j>=0)
        {
           int value = binaryMatrix.get(i,j);
           if(value)
           { 
              ans = j;
               j--;
               
           }
            else
                i++;
        }
        return ans;
        
    }
};