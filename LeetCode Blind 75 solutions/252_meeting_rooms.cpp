/*
***Problem Statement taken from InterviewBit as it's a premium LeetCode problem***
Given an 2D integer array A of size N x 2 denoting time intervals of different meetings. Where:
A[i][0] = start time of the ith meeting.
A[i][1] = end time of the ith meeting.
Find the minimum number of conference rooms required so that all meetings can be done.
Note :- If a meeting ends at time t, another meeting starting at time t can use the same conference room

Problem Constraints
1 <= N <= 105
0 <= A[i][0] < A[i][1] <= 2 * 109

Input Format
The only argument given is the matrix A.

Output Format
Return the minimum number of conference rooms required so that all meetings can be done.

Example Input
Input 1:
 A = [      [0, 30]
            [5, 10]
            [15, 20]
     ]

Input 2:
 A =  [     [1, 18]
            [18, 23]
            [15, 29]
            [4, 15]
            [2, 11]
            [5, 13]
      ]

Example Output
Output 1:
 2
Output 2:
 4
*/

// Solution:
int Solution::solve(vector<vector<int> > &A) {
    sort(A.begin(), A.end());
    priority_queue<int, vector<int>, greater<int>>pq;
    for(int i=0;i<A.size();i++){
        if(pq.empty()){
            pq.push(A[i][1]);
        }
        else{
            if(pq.top()<=A[i][0]){
                pq.pop();
                pq.push(A[i][1]);
            }
            else{
                pq.push(A[i][1]);
            }
        }
    }
    return pq.size();
}
// Time: O(nlogn)
// Space: O(n)
