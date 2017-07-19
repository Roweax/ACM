//
//  HDU_2255.h
//  ACM
//
//  Created by Roweax on 2017/7/19.
//  Copyright © 2017年 Roweax. All rights reserved.
//

#ifndef HDU_2255_hpp
#define HDU_2255_hpp

#include "KM.hpp"

int main() {
    int n;
    Roweax::KM<int> km;
    while (cin >> n) {
        km.score = vector<vector<int>>(n, vector<int>(n));
        for (int p = 0; p < n; ++p) {
            for (int h = 0; h < n; ++h) {
                scanf("%d", &km.score[p][h]);
            }
        }
        km.nx = km.ny = n;
        cout << km.solve() << endl;
    }
}


#endif /* HDU_2255_h */
