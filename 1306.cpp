class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> b(arr.size(),0);
        queue<int> q;
        int n=arr.size();
        q.push(start);
        while(!q.empty()){
            if(arr[q.front()]==0)
                return 1;
            if(q.front()+arr[q.front()]<n){
                if(b[q.front()+arr[q.front()]]!=1){
                    q.push(q.front()+arr[q.front()]);
                    b[q.front()+arr[q.front()]]=1;
                    // cout<<"first";
                }
            }
            if(q.front()-arr[q.front()]>=0){
                if(b[q.front()-arr[q.front()]]!=1){
                    q.push(q.front()-arr[q.front()]);
                    b[q.front()-arr[q.front()]]=1;
                    // cout<<"second";
                }
            }
            // cout<<q.front()<<" ";
            q.pop();
            // cout<<q.size()<<" ";
        }
        return 0;
    }
};
