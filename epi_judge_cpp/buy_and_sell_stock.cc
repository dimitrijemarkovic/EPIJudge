#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
double BuyAndSellStockOnce(const vector<double>& prices) {
  // TODO - you fill in here.

  if(prices.size() < 2) return 0.0;

  double result = 0.0, min = prices[0];

  for(auto i = 1; i < prices.size(); i++){
    if(prices[i] < min){
      min = prices[i];
    } else if(prices[i] - min > result) {
      result = prices[i] - min;
    }
  }

  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"prices"};
  return GenericTestMain(args, "buy_and_sell_stock.cc",
                         "buy_and_sell_stock.tsv", &BuyAndSellStockOnce,
                         DefaultComparator{}, param_names);
}
