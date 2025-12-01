#include <bits/stdc++.h>

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif

    // Stacks Queues
    // ! Stacks are LIFO/FILO
    // ! Queues are FIFO/LILO
    // stack<int> st;
    // queue<int> q;

    // * to add
    // int x = 5;
    // st.push(x);
    // q.push(x);

    // int y = 4;
    // st.push(y);
    // q.push(y);

    // * to check if empty
    // st.empty();
    // q.empty();

    // st.pop();
    // q.pop();

    // st.top();

    // q.front();
    // q.back();


    // * example
    // int n; cin >> n;
    // stack<int> s;
    // queue<int> Q;
    // for (int i = 0; i < n; i++){
    //     int x; cin >> x;
    //     s.push(x);
    //     Q.push(x);
    // }
    // cout << s.top() << '\n';
    // cout << Q.front() << '\n';
    
    // s.pop();
    // Q.pop();

    // cout << s.top() << '\n';
    // cout << Q.front() << '\n';


    // ! Deques are Stacks and Queues in the same time
    int n; cin >> n;
    deque<int> dq;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        dq.push_back(x);
    }

    if (dq.front() > 0){
        dq.push_front(0);
    }
    if (dq.back() < 6){
        dq.push_back(6);
    }

    cout << dq.front() << '\n';
    cout << dq.back() << '\n';


    // ! Priority Queues
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(9);
    pq.push(8);
    pq.push(6);

    auto temp = pq;
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    return 0;
    // * Output: 6 8 9 

    // ! Time Complexity
    // The below table lists the time complexity of the above operations on priority queue:

    // * Operation	                                            Time Complexity
    // * Add element	                                            O(log n)
    // * Delete element	                                        O(log n)
    // * Find maximum element in max heap.	                    O(1)
    // * Find minimum element in min heap.                       O(1)
    // * Initialize priority queue from another container.           O(n)
}