class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        bool divisibleBy3 = false;
        bool divisibleBy5 = false;

        for (int i = 1; i <= n; ++i) {
            if(i % 3 == 0)
                divisibleBy3 = true;
            if (i % 5 == 0)
                divisibleBy5 = true;
            if(divisibleBy3 && divisibleBy5){
                ans.push_back("FizzBuzz");
            }
            else if(divisibleBy5){
                ans.push_back("Buzz");
            }
            else if(divisibleBy3){
                ans.push_back("Fizz");
            }
            else{
                ans.push_back(to_string(i));
            }
            divisibleBy3 = false;
            divisibleBy5  = false;
        }
        return ans;
    }
};