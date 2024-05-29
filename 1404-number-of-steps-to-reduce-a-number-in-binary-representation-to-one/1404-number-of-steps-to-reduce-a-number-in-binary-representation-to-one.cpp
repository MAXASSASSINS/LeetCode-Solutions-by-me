class Solution {
public:
    string addOne(string s){
        string t;
        int carry = 1;
        for(int i = s.length() - 1; i >= 0; i--){
            char c = s[i] + carry;
            if(c == '2'){
                c = '0';
                carry = 1;
            } 
            else{
                carry = 0;
            }
            t += c;
        }
        
        if(carry){
            t += '1';
        }
        reverse(t.begin(), t.end());
        return t;
    }
    
    string divideByTwo(string s){
        return s.substr(0, s.length() - 1);
    }
    
    
    
    int numSteps(string s) {
        if(s == "1") return 0;
        int steps = 0;   
        string temp = s;
        while(temp != "1"){
            
            
            int len = temp.length();
            if(temp[len - 1] == '1'){
                cout<<"addone\t"<<temp<<endl;
                temp = addOne(temp);
            }
            else{
                cout<<"divide 2\t"<<temp<<endl;
                temp = divideByTwo(temp);
            }
            steps++;
        }
        
        return steps;
    }
};