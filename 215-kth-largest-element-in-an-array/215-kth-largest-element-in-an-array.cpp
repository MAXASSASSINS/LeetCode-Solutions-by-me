class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
	multiset<int,greater<int>> mst(nums.begin(),nums.end());
	for(int i=1;i<k;++i) mst.erase(mst.begin());
	return *mst.begin();
}
};