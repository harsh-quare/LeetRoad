class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        //What we are doing is, starting from leaf node, we are checking if the node can be individually taken as a component, if yes then take it, or else, it will be part of its parent node component, so transfer the value of this node to its parent node.

        if(n == 1) return 1;  //if one node, 0 edges: only one component possible

        vector<vector<int>> adj(n);
        vector<int> degree(n);  //degree[node] = 1 => Leaf node
        
        vector<long long> nodeVals(values.begin(), values.end());  //we will be adding

        for(auto& it: edges){
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++){
            if(degree[i] == 1) q.push(i);  //these are the leaf nodes, will be the starting points of out traversal
        }

        int compCnt = 0;
        while(!q.empty()){
            int cur = q.front();
            q.pop();

            degree[cur]--;
            long long addVal = (nodeVals[cur] % k == 0) ? 0 : nodeVals[cur];
            //agar iss node ko individual component bna skte h to addVal jo ham parent me add krenge woh zero hogi(and ham isko ek individual component bol denge) or else iski value ko parent ko transfer krenge
            if(addVal == 0){
                compCnt++;
            }

            for(int nbr: adj[cur]){
                if(degree[nbr] > 0){  //we have already ensured by reducing degree[cur], that the degreee of the leaf ndode will be down to zero, and so that's why we won't visit them again by putting this check > 0
                    degree[nbr]--;
                    nodeVals[nbr] += addVal;

                    if(degree[nbr] == 1) q.push(nbr);  //agar nbr me cur node add krne ya usko individual component banane ke baad nbr ki degree=1 ho gyi, to ab ye ek leaf node bn gyi, to isko daal do queue me
                }
            }
        }

        return compCnt;
    }
};