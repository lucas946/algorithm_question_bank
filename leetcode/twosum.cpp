#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

vector<int> two_sum(vector<int>& num_list, int target) {
    int tmp;
    vector<int> res;
    unordered_map<int, int> num_map;
    for(int i = 0; i < num_list.size(); ++i) {
        num_map[num_list[i]] = i;
    }
    for(int i = 0; i < num_list.size(); ++i) {
        tmp = target - num_list[i];
        if(num_map.count(tmp) && num_map[tmp] != i) {
            res.push_back(i);
            res.push_back(num_map[tmp]);
            break;
        }
    }
} 