#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int> left_queue;
    priority_queue<int> right_queue;

    string currLine;

    int first_num, second_num;

    while(getline(cin, currLine)) {
        int first_space = currLine.find_first_of(' ');
        int last_space = currLine.find_last_of(' ');

        first_num = atoi(currLine.substr(0, first_space).c_str());
        second_num = atoi(currLine.substr(last_space, currLine.size()).c_str());

        left_queue.push(first_num);
        right_queue.push(second_num);
    }


    int sum = 0;

    while(!left_queue.empty()) {
        int num_l = left_queue.top();
        int num_r = right_queue.top();

        sum = sum + abs(num_l - num_r);

        left_queue.pop();
        right_queue.pop();
    }

    cout << sum;

    return 0;
}
