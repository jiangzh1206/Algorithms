#include <string>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    // 28. Implement strStr()
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }

        int i = 0;  // haystack 指针
        int j = 0;  // 匹配串 指针
        for (int m = 0; m < haystack.size(); ) {
            if (haystack[m] == needle[j]) {
                j++;
                m++;
                if (j == needle.size()) {
                    return i;
                }
            } else {
                // 回退到i+1位置
                i++;
                m = i;
                j = 0;
            }
        }

        return -1;
    }

    // 30. Substring with Concatenation of All Words
    /*
        哈希表H<串，个数>: words中单词和其个数;
        哈希表T<串，个数>: 窗口W中单词和其个数;
        len;N;
        cnt = 0：窗口中已经找到的单词个数;
        left: 窗口左边界；
        for(word in words){++H[word];}
        for(i in [0,...,i+len <= s.length]){
            sub = s[i,...,i+len-1];
            if(sub in H 且 T[sub] < H[sub]){
                ++T[sub];
                if(cnt++ == 0) left= i;
                i += len;
                if(cnt == N){
                    //全找到
                    记录窗口W左边界;
                    窗口W右移一位;
                }
            }else{//要么是sub不在words中，要么sub个数多了
                窗口W右移一位;
            }
        }
*/
    vector<int> findSubstring(string s, vector<string>& words) {
        const int N = words.size();
        if(N == 0) return vector<int>();
        const int len = words[0].size();
        unordered_map<string,int> H;
        for(auto s: words){
            ++H[s];
        }
        vector<int> ans;
        int cnt = 0;
        unordered_map<string,int> T;
        int left;
        for(int i=0;i+len<=s.size();){
            string sub = s.substr(i,len);
            if(H.count(sub) && T[sub] < H[sub]){
                ++T[sub];
                if(cnt++ == 0) left = i;
                i+=len;      

                if(cnt == N){
                    ans.push_back(left);
                    reset(cnt,i,T,left);
                }
            }else{
                reset(cnt,i,T,left);
            }
        }
        return ans;
    }
    void reset(int& cnt,int& i,unordered_map<string,int>& T,int left){
        if(!cnt) ++i;
        else i = left+1;
        cnt = 0;
        T.clear();
    }

};


int main(int argc, char const *argv[])
{
    Solution sln;

    int ret = sln.strStr("mississippi", "issip");


    return 0;
}
