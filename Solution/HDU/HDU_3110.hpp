//
//  HDU_3110.hpp
//  ACM
//
//  Created by Roweax on 2017/7/19.
//  Copyright © 2017年 Roweax. All rights reserved.
//

#ifndef HDU_3110_hpp
#define HDU_3110_hpp

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    Solution(int w, int b, int k, int n)
    : base_cost(b)
    , storing_cost(k)
    , capacity(n) {
        dp.push_back(vector<int>(capacity + 1, numeric_limits<int>::max()));
        dp[0][0] = 0;
    }
    
    void PassWeek(int cost, int deliver) {
        
        dp.push_back(vector<int>(capacity + 1, numeric_limits<int>::max()));
        const auto& previous_week = *(dp.end() - 2);
        auto& current_week = dp.back();
        
        for (int cs = 0; cs <= capacity; ++cs) {
            int min_cost = numeric_limits<int>::max();
            int store_cost = CostOfStore(cs);
            for (int ps = 0; ps <= min(cs + deliver, capacity); ++ps) {
                if(previous_week[ps] == numeric_limits<int>::max()) {
                    break;
                }
                int total_cost = previous_week[ps] + CostOfBuy(cs + deliver - ps, cost) + store_cost;
                if (total_cost < min_cost) {
                    min_cost = total_cost;
                }
            }
            current_week[cs] = min_cost;
        }
    }
    
    
    int GetResult() {
        return dp.back()[0];
    }
    
private:
    int CostOfStore(int store) {
        return store * storing_cost;
    }
    
    int CostOfBuy(int num, int cost) {
        return num == 0 ? 0 : num * cost + base_cost;
    }
    
    vector<vector<int>> dp;
    int                 base_cost;
    int                 storing_cost;
    int                 capacity;
};

int main() {
    int base_cost, storing_cost, capacity;
    int week;
    while (scanf("%d", &week) != EOF && week > 0) {
        scanf("%d%d%d", &base_cost, &storing_cost, &capacity);
        Solution solution(week, base_cost, storing_cost, capacity);
        while (week-- > 0) {
            int week_cost, deliver;
            scanf("%d%d", &week_cost, &deliver);
            solution.PassWeek(week_cost, deliver);
        }
        printf("%d\n", solution.GetResult());
    }
}


#endif /* HDU_3110_hpp */
