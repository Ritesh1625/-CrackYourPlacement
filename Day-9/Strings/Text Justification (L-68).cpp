//It is so hard :(  

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> ans, vs;
        string str;

        int len = 0;
        for (int i = 0; i < words.size(); ++i) {
            if (len + vs.size() + words[i].size() <= L) {
                // vs not full, need to get more words in the line
                vs.push_back(words[i]);
                len += words[i].size();
            }
            else {
                // vs full, get the whole line
                if (vs.size() == 1) {
                    // just one word, the left justify
                    str = vs[0];
                    str.append(L - str.size(), ' ');
                    ans.push_back(str);
                }
                else if (vs.size() > 1) {
                    // the first "mod" words get "div+1" spaces
                    // the remaining words get "div" spaces
                    int div = (L - len) / (vs.size() - 1);
                    int mod = (L - len) % (vs.size() - 1);
                    str = vs[0];
                    for (int j = 1; j < vs.size(); ++j) {
                        if (j <= mod) str.append(div+1, ' '); // one more space
                        else str.append(div, ' ');
                        str += vs[j];
                    }
                    ans.push_back(str);
                }

                vs.clear();
                vs.push_back(words[i]);
                len = words[i].size();
            }
        }

        // the last line, left justified and no extra space is inserted between words
        str = vs[0];
        for (int j = 1; j < vs.size(); ++j) str += ' ' + vs[j];
        str.append(L-str.size(), ' ');
        ans.push_back(str);
        return ans;
    }
};
