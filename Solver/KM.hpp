//
//  KM.hpp
//  ACM
//
//  Created by Roweax on 2017/7/19.
//  Copyright © 2017年 Roweax. All rights reserved.
//

#ifndef KM_hpp
#define KM_hpp

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

namespace Roweax {
    template <class T>
    class KM {
    public:
        static T UNLINK;
        
        KM() {
        }
        
        
        void set(const vector<vector<T>> &input, size_t ix, size_t iy) {
            nx = ix;
            ny = iy;
            if (nx <= ny) {
                score = vector<vector<T>>(nx, vector<T>(ny, 0));
                for (int i = 0; i < nx; ++i) {
                    for (int j = 0; j < ny; ++j) {
                        score[i][j] = input[i][j];
                    }
                }
            } else {
                score = vector<vector<T>>(ny, vector<T>(nx, 0));
                for (int i = 0; i < ny; ++i) {
                    for (int j = 0; j < nx; ++j) {
                        score[i][j] = input[j][i];
                    }
                }
                swap(nx, ny);
            }
            
            canInit();
        }
        
        
        void set(const vector<vector<T>> &input) {
            set(input, input.size(), input[0].size());
        }
        
        void canInit() {
            can_x = vector<bool>(nx, false);
            for (int x = 0; x < nx; ++x) {
                for (int y = 0; y < ny; ++y) {
                    if(score[x][y] != UNLINK) {
                        can_x[x] = true;
                        break;
                    }
                }
            }
        }
        
        T solve() {
            link = vector<int>(ny, -1);
            lx = vector<T>(nx, 0);
            ly = vector<T>(ny, 0);
            
            for (int i = 0; i < nx; ++i) {
                lx[i] = *max_element(score[i].begin(), score[i].begin() + ny);
            }
            
            for (int x = 0; x < nx; ++x) {
                slack = vector<T>(ny, numeric_limits<T>::max());
                while (can_x[x]) {
                    visted_x = vector<bool>(nx, false);
                    visted_y = vector<bool>(ny, false);
                    if (DFS(x))
                        break;
                    int d = numeric_limits<T>::max();
                    
                    for (int i = 0; i < ny; i++)
                        if (!visted_y[i] && d > slack[i])
                            d = slack[i];
                    for (int i = 0; i < nx; i++)
                        if (visted_x[i])
                            lx[i] -= d;
                    for (int i = 0; i < ny; i++)
                        if (visted_y[i])
                            ly[i] += d;
                        else
                            slack[i] -= d;
                }
            }
            int result = 0;
            linked_count = 0;
            all_linked = true;
            if (nx == 0 || ny == 0) {
                all_linked = false;
            }
            for (int i = 0; i < ny; i ++) {
                if (link[i] > -1) {
                    if(score[link[i]][i] == UNLINK) {
                        all_linked = false;
                    } else {
                        result += score[link[i]][i];
                        linked_count++;
                    }
                }
            }
            return result;
        }
        
        bool isAllLink() const {
            return linked_count == nx;
        }
        
    private:
        bool DFS(int x) {
            visted_x[x] = 1;
            for (int y = 0; y < ny; y++) {
                if (visted_y[y] || score[x][y] == UNLINK)
                    continue;
                T t = lx[x] + ly[y] - score[x][y];
                if (t == 0) {
                    visted_y[y] = 1;
                    if (link[y] == -1 || DFS(link[y])) {
                        link[y] = x;
                        return true;
                    }
                }
                else if (slack[y] > t)
                    slack[y] = t;
            }
            return false;
        }
        
    public:
        size_t              nx;
        size_t              ny;
        vector<vector<T>>   score;
    private:
        vector<T>           lx;
        vector<T>           ly;
        vector<int>         link;
        vector<bool>        visted_x;
        vector<bool>        visted_y;
        vector<T>           slack;
        vector<bool>        can_x;
        bool                all_linked;
        int                 linked_count;
    };
}

template<> int Roweax::KM<int>::UNLINK = numeric_limits<int>::min() / 2;

#endif /* KM_hpp */
