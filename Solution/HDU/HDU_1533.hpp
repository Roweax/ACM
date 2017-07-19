//
//  HDU_1533.hpp
//  ACM
//
//  Created by Roweax on 2017/7/19.
//  Copyright © 2017年 Roweax. All rights reserved.
//

#ifndef HDU_1533_hpp
#define HDU_1533_hpp

#include "KM.hpp"

int main() {
    Roweax::KM<int> km;
    int m, n;
    while (true) {
        cin >> m >> n;
        if(m == 0 && n == 0) {
            break;
        }
        vector<pair<int, int>> houses;
        vector<pair<int, int>> men;
        for (int y = 0; y < m; ++y) {
            for (int x = 0; x < n; ++x) {
                char c;
                cin >> c;
                switch (c) {
                    case 'm':
                        men.push_back({x, y});
                        break;
                    case 'H':
                        houses.push_back({x, y});
                        break;
                    default:
                        break;
                }
            }
        }
        vector<vector<int>> price(men.size(), vector<int>(houses.size(), 0));
        for (int m = 0; m < men.size(); ++m) {
            for (int h = 0; h < houses.size(); ++h) {
                auto& rm = men[m];
                auto& rh = houses[h];
                price[m][h] = -(abs(rm.first - rh.first) + abs(rm.second - rh.second));
            }
        }
        km.set(price, men.size(), houses.size());
        printf("%d\n", -km.solve());
    }
    return 0;
}


#endif /* HDU_1533_hpp */
