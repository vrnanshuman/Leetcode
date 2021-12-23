class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string token;
        stack<string> folderStack;
        folderStack.push("/");
                
        while(getline(ss, token, '/')) {
            if(token.compare("..") == 0) {
                if(folderStack.top().compare("/") == 0)
                    continue;
                folderStack.pop();
            } else if(token.compare(".") == 0) {
                continue;
            } else if(token.compare("") != 0) {
                folderStack.push(token); 
            }
             cout<<token<< endl;
        }
        string newPath = "";
        while(folderStack.top().compare("/") != 0) {
            newPath = "/" + folderStack.top() + newPath;
            folderStack.pop();
        }
        if(newPath.compare("") == 0)
            return "/";
        return newPath;
    }
};