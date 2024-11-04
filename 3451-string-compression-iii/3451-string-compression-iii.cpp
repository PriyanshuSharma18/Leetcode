class Solution {
public:
    string compressedString(string word) {
        vector<int>fr(26);
        int n=word.size();
        string h;
        char p='U';
        int c=0;
        for(int i=0;i<n;i++)
        {
            
            if(word[i]!=p||c==9)
            {
                c=1;
                p=word[i];
                while(i+1<n&&c<9&&p==word[i+1])
                {
                    i++;
                    c++;
                }
                char y=(char)(c+'0');
                h+=y;
                h+=p;
                
            }
        }
        return h;
    }
};