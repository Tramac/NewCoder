class GrayCode {
public:
    vector<string> getGray(int n) {
        // write code here
        vector<string> gray;
		if (n == 1){
			gray.push_back("0");
			gray.push_back("1");
			return gray;
		}
		vector<string> lastGray = getGray(n - 1);
		for (int i = 0; i < lastGray.size(); ++i)
			gray.push_back("0" + lastGray[i]);
		for (int i = lastGray.size() - 1; i >= 0; --i)
			gray.push_back("1" + lastGray[i]);
		
		return gray;
	}
};
