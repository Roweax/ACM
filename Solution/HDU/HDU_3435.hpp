//
//  HDU_3435.hpp
//  ACM
//
//  Created by Roweax on 2017/7/19.
//  Copyright © 2017年 Roweax. All rights reserved.
//

#ifndef HDU_3435_hpp
#define HDU_3435_hpp

#include "KM.hpp"

int main() {
    int c;
    cin >> c;
    int m, n;
    Roweax::KM<int> km;
    for (int icase = 1; icase <= c; ++icase) {
        scanf("%d%d", &m, &n);
        km.score = vector<vector<int>>(m, vector<int>(m, km.UNLINK));
        for (int i = 0; i < n; ++i) {
            int from , to, length;
            scanf("%d%d%d", &from, &to, &length);
            from--;
            to--;
            if(km.score[from][to] < -length) {
                km.score[to][from] = km.score[from][to] = -length;
            }
        }
        km.nx = km.ny = m;
        km.canInit();
        int sum = -km.solve();
        if (km.isAllLink()) {
            printf("Case %d: %d\n", icase, sum);
        } else {
            printf("Case %d: NO\n", icase);
        }
    }
}

#endif /* HDU_3435_hpp */
