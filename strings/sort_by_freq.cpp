#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution{	

	private:
		static bool comparator(pair<int,char> &p1, pair<int,char> &p2)
		{
			if(p1.first > p2.first) return true;
			if(p1.first < p2.first) return false;
			return p1.second < p2.second;
		}
	public:
		vector<char> frequencySort(string& s)
		{
			//your code goes here
			int maxfreq = 0;
			pair<int, char> freq[26];  // frequency, character

			for(int i=0; i<26; i++)
			{
				freq[i] = {0, i + 'a'};
			}
			
			for(char ch : s) {
				freq[ch - 'a'].first++;
			}

			// Sort based on custom comparator
			sort(freq, freq + 26, comparator);

			vector<char> ans;
			for(int i = 0; i < 26; i++) {
				if(freq[i].first > 0) ans.push_back(freq[i].second);
			}
			return ans;
			
		}
};