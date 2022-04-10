#include <vector>
#include <iostream>
#include <iterator>
#include <cmath>
using namespace std;

class Solution {
public:
    //static int max(int a, int b){ return a > b ? a : b; }

    // My Solution to LeetCode 121
    // https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
    // Scoring seems to be based on server load for this
    //
    // Time - O(n) faster than 70.59%
    // Space - O(1) Less than 53.52%
      int maxProfit(vector<int>& prices){
      if(&prices == NULL || prices.size() < 2) return 0;
      int maxProfit = 0, minPrice = prices[0];

      for(int ii = 1; ii < prices.size(); ii++){
        if(prices[ii] < prices[ii-1]){
          minPrice = min(minPrice, prices[ii]);
          continue;
        }
        maxProfit = max(maxProfit, prices[ii]-minPrice);
      }
      return maxProfit;
    }


    /*
    //Can it be better?
    //Time: O(n) - faster than 12.04%
    //Space O(1) - less than 53.52%
    int maxProfit(vector<int>& prices) {
      if(prices.size() < 2) return 0;
      int buy = 0;
      long profit = 0;
      for(int ii = 1; ii < prices.size(); ii++){
        if(prices[ii] < prices[buy]){
          buy = ii;
          continue;
        }
        profit = max(profit, prices[ii] - prices[buy]);
      }
      return profit;
    }
    */




    /*
    //Recursion Killed LC + Replit
    //
    int maxProfitRecursion(vector<int> prices){
      if (prices.size() == 1) return 0;
      int front = prices.front();
      int highest = 0;
      prices.erase(prices.begin());
      for(int num : prices){
        highest = max(highest, num);
      }
      return Solution::max(highest-front, maxProfitRecursion(prices));
      
    }
    int maxProfit(vector<int>& prices) {
        return maxProfitRecursion(prices);
    }
    */
};

main(){
  vector<int> input = {7,1,5,3,6,4};
  Solution test = Solution();
  cout << test.maxProfit(input)<< "\n";
}