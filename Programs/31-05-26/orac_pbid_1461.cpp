#include <functional>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin>>n; n--;
    int k; cin>>k;
    vector<int> d(n),c(n);
    for(auto& i:d)cin>>i;
    for(auto& i:c)cin>>i;
    {int useless; cin>>useless;}
    priority_queue<int, vector<int>, greater<int>> pq;
    map<int,int> count;
    long long tcans=0, tcost=0;
    for(int i=0;i<n;i++){
        pq.push(c[i]);
        count[c[i]]+=k, tcans+=k; int fetch=d[i];
        while(fetch>0){
            int pc=pq.top(), tk=min(count[pc],fetch);
            tcost+=tk*pc, count[pc]-=tk, fetch-=tk, tcans-=tk;
            if(!count[pc]) pq.pop();
        }
    }
    cout<<tcost; return 0;
}

/* orac_pbid_1461.min.cpp

#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;int main(){ios_base::sync_with_stdio(false);cin.tie(nullptr);int n;cin>>n;n--;int k;cin>>k;vector<int>d(n),c(n);for(auto&i:d)cin>>i;for(auto&i:c)cin>>i;{int u;cin>>u;}priority_queue<int,vector<int>,greater<int>>pq;map<int,int>ct;int ts=0,tt=0;for(int i=0;i<n;i++){pq.push(c[i]);ct[c[i]]+=k,ts+=k;int f=d[i];while(f>0){int pc=pq.top(),tk=min(ct[pc],f);tt+=tk*pc,ct[pc]-=tk,f-=tk,ts-=tk;if(!ct[pc])pq.pop();}}cout<<tt;return 0;}

*/























/*
import heapq
from collections import defaultdict

def solve():
    N, K = map(int, input().split())
    D = [int(input()) for _ in range(N-1)]
    C = [int(input()) for _ in range(N)]
    
    # Min-heap of prices in backpack
    heap = []
    # Count of each price (for lazy deletion)
    count = defaultdict(int)
    total_cans = 0
    total_cost = 0
    
    for i in range(N-1):
        # Add K cans at price C[i]
        heapq.heappush(heap, C[i])
        count[C[i]] += K
        total_cans += K
        
        # If we exceed capacity, remove most expensive cans
        while total_cans > K:
            # Find most expensive (lazy approach - use max-heap or just keep min-heap and accept)
            # Simpler: Just don't exceed capacity by careful buying
            pass
        
        # Eat D[i] cans
        need = D[i]
        while need > 0:
            price = heap[0]  # peek cheapest
            take = min(count[price], need)
            total_cost += take * price
            count[price] -= take
            need -= take
            total_cans -= take
            
            # Remove price from heap if count reaches 0
            if count[price] == 0:
                heapq.heappop(heap)
    
    print(total_cost)
*/
