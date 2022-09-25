class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
	buildheap(nums);//maxheap
	for(int i=1;i<k;++i){
		swap(nums[0],nums.back());
		nums.pop_back();
		heapify(nums,0);
	}
	return nums[0];
}
void heapify(vector<int>& nums,int i){
	int leftIdx = (i<<1)+1, rightIdx = (i<<1)+2, largestIdx=i;
	if(leftIdx<nums.size() && nums[leftIdx]>nums[largestIdx]) largestIdx = leftIdx;
	if(rightIdx<nums.size() && nums[rightIdx]>nums[largestIdx]) largestIdx = rightIdx;
	if(largestIdx!=i)
		swap(nums[i], nums[largestIdx]), heapify(nums,largestIdx);
}
void buildheap(vector<int>& nums){
	//lastnodeindex = n-1, so lastParentIdx= (n-1-1)/2 = n/2-1
	for(int i=(nums.size()>>1)-1;i>=0;--i)  heapify(nums,i);
}

};