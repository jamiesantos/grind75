#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
  int maxProfit (vector<int>& prices) {
    int maxProfit = 0;
    int min = 999999;
    //unordered_set<int> minPrices;
    
    for(int i = 0; i < prices.size(); ++i){
      if (prices.at(i) < min) {
        min = prices.at(i);
      //  minPrices.insert(prices.at(i));
      } else {
        //for (auto& price: minPrices) {
          int profit = prices.at(i) - min; 
          if (profit > maxProfit) maxProfit = profit;
//        } 
      }
    }
   return maxProfit;
  }

//  void printMax(set<int> minPrices) {
//    for (auto& price : minPrices) {
//      std::cout << price << ' ';
//  }
//}
};

int main() {
  Solution sol;
  vector<int> vect{ 7,6,4,3,1};
  int solution = sol.maxProfit(vect);
  cout << solution << endl;
  return 0;
}
