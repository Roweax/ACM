//
//  HDU_1853.hpp
//  ACM
//
//  Created by Roweax on 2017/7/19.
//  Copyright © 2017年 Roweax. All rights reserved.
//

#ifndef HDU_1853_hpp
#define HDU_1853_hpp

#include "KM.hpp"

int main() {
    int m, n;
    Roweax::KM<int> km;
    while (scanf("%d%d", &m, &n) != EOF) {
        km.score = vector<vector<int>>(m, vector<int>(m, km.UNLINK));
        for (int i = 0; i < n; ++i) {
            int from , to, length;
            scanf("%d%d%D", &from, &to, &length);
            if(km.score[from - 1][to - 1] < -length) {
                km.score[from - 1][to - 1] = -length;
            }
        }
        km.nx = km.ny = m;
        int sum = -km.solve();
        if (km.all_linked) {
            cout << sum << endl;
        } else {
            cout << -1 << endl;
        }
    }
}


#endif /* HDU_1853_hpp */
