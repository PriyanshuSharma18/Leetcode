class Solution {
public:
    int maxVowels(string s, int k) {
        int count=0; // counter for save number of vowel in substr
        
        //count first substring
        for(int i=0;i<k;i++){
            if(isVowel(s[i])) count++;
        }

        int ans=count; // variable for saving max counter
        for(int i=k;i<s.size();i++){
            if(isVowel(s[i-k])) count--; //if first element of window is vowel then we ** minus 1**
            if(isVowel(s[i])) count++; // if next element is vowel then we **add 1**
            ans=max(ans,count); // update answer
        }
        return ans;
    }
    bool isVowel(char a){
        return a=='u' || a=='e'|| a=='o'|| a=='a'|| a=='i';
    }
};