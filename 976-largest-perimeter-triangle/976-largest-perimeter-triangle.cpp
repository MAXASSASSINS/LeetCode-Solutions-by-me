class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        for (int i = 0; i < nums.size() - 2; ++i) {
            int a = nums[i];
            int b = nums[i + 1];
            int c = nums[i + 2];
            double s = double(a + b + c) / 2;
            double area = pow(s*(s-a)*(s-b)*(s-c), 0.5);
            if(area > 0){
                return int(s *= 2);
            }
        }
        return 0;
    }
};