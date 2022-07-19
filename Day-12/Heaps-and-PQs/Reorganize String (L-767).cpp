class Solution {
public:
    string reorganizeString(string s) {
    
        string ans;
        
        //Unordered Map for couting the frequencies of the char
        unordered_map<char, int> umap;
        for(char i: s) umap[i]++;

        //MaxHeap for getting the most frequent letters
        priority_queue<pair<int,char>> maxHeap;

        for(auto it = umap.begin(); it != umap.end(); it++){
            if(it->second>0) maxHeap.push({it->second, it->first});
        }

        while(maxHeap.size() > 1){
            //Arranging the most frequent letter..
            char first = maxHeap.top().second;
            umap[first]--;
            maxHeap.pop();
            //..using the next most frequent letter
            char second = maxHeap.top().second;
            umap[second]--;
            maxHeap.pop();

            //Appending them to the list
            ans += first;
            ans += second;

            //If the frequency after removing one element is greater than 0, we add it back to the heap
            if(umap[first]>0) maxHeap.push({umap[first], first});
            if(umap[second]>0) maxHeap.push({umap[second], second});

        }

        //If there's one left out element
        if(!maxHeap.empty()){
            char leftOut = maxHeap.top().second;

            //If it is occuring just once, add it to the ans string
            if(umap[leftOut]==1) ans += leftOut;

            //if freq>1, that means we cannot reorganise the string, we return empty string
            else return "";
        }

        return ans;

    }
};
