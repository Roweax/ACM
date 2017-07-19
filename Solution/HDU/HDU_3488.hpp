//
//  HDU_3488.hpp
//  ACM
//
//  Created by Roweax on 2017/7/19.
//  Copyright © 2017年 Roweax. All rights reserved.
//

#ifndef HDU_3488_hpp
#define HDU_3488_hpp

#include "KM.hpp"

int main() {
    int c;
    cin >> c;
    int m, n;
    Roweax::KM<int> km;
    while (c-- > 0) {
        scanf("%d%d", &m, &n);
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
        if (km.isAllLink()) {
            cout << sum << endl;
        } else {
            cout << -1 << endl;
        }
    }
}

#endif /* HDU_3488_hpp */
