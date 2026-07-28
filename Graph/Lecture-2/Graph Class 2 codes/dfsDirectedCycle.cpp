//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool dfsHelper(int node, unordered_map<int,bool>& vis, vector<int> adj[],
    unordered_map<int,bool>& dfsTracker) {
        
        vis[node] = true;
        dfsTracker[node] = true;
        
        for(auto nbr: adj[node]) {
            if(!vis[nbr]) {
                bool ans = dfsHelper(nbr, vis, adj, dfsTracker);
                if(ans == true) {
                    return true;
                }
            }
            else if(vis[nbr] == true && dfsTracker[nbr] == true) {
                //cycle present
                return true;
            }
        }
        
        //backtrack
        dfsTracker[node] = false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        bool ans = false;
        int n = V;
        unordered_map<int,bool> vis;
        unordered_map<int,bool> dfsTracker;
        
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                ans = dfsHelper(i,vis,adj, dfsTracker);
                if(ans == true) {
                    break;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        unordered_set<string>st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        while(!q.empty()){
            pair<string,int> front=q.front();
            q.pop();
            string frontWord=front.first;
            int curdistance=front.second;
            if(endWord==frontWord){
                return curdistance;
            }
            else {
                for(int i=0;i<frontWord.length();i++){
                    char original=frontWord[i];
                    for(char ch='a';ch<='z';ch++){
                        frontWord[i]=ch;
                        if(st.find(frontWord) !=st.end()){
                            st.erase(frontWord);
                            q.push({frontWord,curdistance+1});
                        }
                    }
                    frontWord[i]=original;
                }
            }
        }
        return 0;
    }
};















