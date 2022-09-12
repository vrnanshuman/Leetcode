/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
    unordered_set<string> visited;
    string hname;
    vector<string> results;
public:
    
    string getHostname(string url) {
        string tmp = url.substr(7);
        if(tmp.find('/')!=string::npos)
            return tmp.substr(0,tmp.find('/'));
        return tmp;
    }
    
    void dfs(string url, HtmlParser& parser) {
        if(visited.find(url) != visited.end())
            return;
        visited.insert(url);
        if(hname.compare(getHostname(url)) !=0 )
            return;
        results.push_back(url);
        for(string neighbour : parser.getUrls(url)) {
            dfs(neighbour, parser);
        }
    }
    
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        hname = getHostname(startUrl);
        dfs(startUrl, htmlParser);
        return results;
    }
};