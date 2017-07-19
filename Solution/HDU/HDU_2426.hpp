//
//  HDU_2426.hpp
//  ACM
//
//  Created by Roweax on 2017/7/19.
//  Copyright © 2017年 Roweax. All rights reserved.
//

#ifndef HDU_2426_hpp
#define HDU_2426_hpp

#include "KM.hpp"

int main() {
    Roweax::KM<int> km;
    int ns, nr, nc;
    int icase = 1;
    while (scanf("%d%d%d", &ns, &nr, &nc) != EOF) {
        km.score = vector<vector<int>>(ns, vector<int>(nr, Roweax::KM<int>::UNLINK));
        for(int i = 0; i < nc; ++i) {
            int student, room, rank;
            scanf("%d%d%d", &student, &room, &rank);
            if (rank >= 0) {
                km.score[student][room] = rank;
            }
        }
        km.nx = ns;
        km.ny = nr;
        int result = km.solve();
        if (km.isAllLink()) {
            printf("Case %d: %d\n", icase++,  result);
        } else {
            printf("Case %d: -1\n", icase++);
        }
    }
}

#endif /* HDU_3718_hpp */
