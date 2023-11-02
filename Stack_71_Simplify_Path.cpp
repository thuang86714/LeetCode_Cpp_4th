#include <string>
#include <stack>
using namespace std;


class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int i = 0;
        for(; i < path.size(); i++){
            if(path[i] == '/'){
                continue;
            }

            string temp = "";
            while(i < path.size() && path[i] != '/'){
                temp += path[i];
                i++;
            }

            if(temp == "."){
                continue;
            }else if(temp == ".."){
                if(!st.empty()){
                    st.pop();
                }
            }else{
                st.push(temp);
            }
        }
        if(st.empty()){
            return "/";
        }
        string res = "";
        while(!st.empty()){
            res = "/" + st.top() + res;
            st.pop();
        }
        return res;
    }
};