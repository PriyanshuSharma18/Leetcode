class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int i=0,j=0;
        int len1=haystack.length();
        int len2=needle.length();
        int count =0;
        int store;
        while(i<len1){
            if(haystack[i]==needle[j]){
                i++;
                j++;
                count++;
                if(count ==1){
                    store = i;
                }
                if(count==len2){
                    return i-len2;
                }
            }
            else if(count>0){
                count =0;
                j=0;
                i=store;
            }
            else{
                i++;
            }
        }
        return -1;

    }
};