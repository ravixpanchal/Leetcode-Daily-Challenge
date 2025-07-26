class Solution {
public:

string removeSubstr(string & s, string &matchStr){
    stack<char>st;

    for(char &ch: s){
        if(ch==matchStr[1] && !st.empty() && st.top()==matchStr[0]){
            st.pop();
        }else{
            st.push(ch);
        }
    }

    string temp;
    while(!st.empty()){
        temp.push_back(st.top());
        st.pop();
    }

    reverse(temp.begin(),temp.end());
    return temp;
}

    int maximumGain(string s, int x, int y) {
        int n=s.size();
        int points=0;

        string maxStr=(x>=y)?"ab":"ba";
        string minStr=(x<y)?"ab":"ba";

        //First Pass
        string first_pass=removeSubstr(s,maxStr);
        int m=first_pass.size();

        int charRemoved=(n-m);
        points+=(charRemoved/2)*max(x,y);

        //Second Pass
        string second_pass=removeSubstr(first_pass,minStr);
        charRemoved=m-second_pass.size();

        points+=(charRemoved/2)*min(x,y);

        return points;
        
    }
};