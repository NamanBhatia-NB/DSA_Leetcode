class Solution {
public:
    bool ans(int idx, vector<int>& arr, vector<bool>& visited) {
        if(idx<0 || idx>=arr.size())
            return false;

        if (visited[idx])
            return false;

        if (arr[idx] == 0)
            return true;

        visited[idx] = true;

        return ans(arr[idx] + idx, arr, visited) || ans(idx - arr[idx], arr, visited);
    }

    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        return ans(start, arr, visited);
    }
};