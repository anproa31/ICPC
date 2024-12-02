#include <bits/stdc++.h>
using namespace std;


int main()
{
    priority_queue<int> left_queue;
    map<int, int> similarity_map;
    string currLine;
    int first_num, second_num;
    while(getline(cin, currLine)) {
        int first_space = currLine.find_first_of(' ');
        int last_space = currLine.find_last_of(' ');

        first_num = atoi(currLine.substr(0, first_space).c_str());
        second_num = atoi(currLine.substr(last_space, currLine.size()).c_str());

        left_queue.push(first_num);

        if(similarity_map[second_num] > 0) {
            similarity_map[second_num]++;
        } else {
            similarity_map.insert_or_assign(second_num, 1);
        }
    }

    int similarity_score = 0;
    while(!left_queue.empty()) {
        int num = left_queue.top();

        if(similarity_map[num] > 0) {
            similarity_score += (num * similarity_map.at(num));
        }

        left_queue.pop();
    }

    cout << similarity_score;
    return 0;
}
