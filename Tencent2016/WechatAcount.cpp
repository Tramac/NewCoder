class Gift {
public:
    int getValue(vector<int> gifts, int n) {
        // write code here
        sort(gifts.begin(), gifts.end());
        int maxLength = 1;
        int currentLength = 1;
        int mostAmount;
        for(int i = 1; i < n; ++i)
        {
            if(gifts[i] == gifts[i-1]) currentLength++;
            else{
                if(currentLength > maxLength)
                {
                    maxLength = currentLength;
                    mostAmount = gifts[i-1];
                }
                currentLength = 1;
            }
        }
        if(maxLength >= n/2)
            return mostAmount;
        else
            return 0;
    }
};
