class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        unordered_map<long long, long long> freq;
                
        multiset<pair<long long,long long>> includedNumbers;
        multiset<pair<long long,long long>, greater<pair<long long,long long>>> unusedBucket;

        long long sum = 0;
        for (int i = 0; i < k; i++) {
            freq[nums[i]]++;
        }
        for (auto [a, b] : freq) {
            sum += a * b;
            includedNumbers.emplace(b, a);
        }
        
        while (includedNumbers.size() > x) {
            long long a = includedNumbers.begin()->first, b = includedNumbers.begin()->second;
            unusedBucket.emplace(a, b);
            sum -= a * b;
            includedNumbers.erase(includedNumbers.begin());
        }
        
        vector<long long> res = {sum};        

        int n = nums.size();
        for (int i = k; i < n; i++) {
            int left = nums[i-k], right = nums[i];
            if (left == right) {
                res.push_back(sum);
                continue;
            }

            auto deleter = includedNumbers.find(make_pair(freq[left], left));
            if (deleter != includedNumbers.end()) {
                sum -= left * freq[left];
                includedNumbers.erase(deleter);
            }
            else {
                unusedBucket.erase(make_pair(freq[left], left));
            }

            freq[left]--;
            if (freq[left]) unusedBucket.emplace(freq[left], left);
             
            if (freq.find(right) == freq.end()) {
                freq[right] = 0;
            }
            else if ((deleter = includedNumbers.find(make_pair(freq[right], right))) != includedNumbers.end()) {
                sum -= right * freq[right];
                includedNumbers.erase(deleter);
            }
            else {
                unusedBucket.erase(make_pair(freq[right], right));
            }
            
            freq[right]++;
            unusedBucket.emplace(freq[right], right);
            
            int repeats = min(unusedBucket.size(), x - includedNumbers.size());
            for (int j = 0; j < repeats; j++) {
                auto [a, b] = *unusedBucket.begin();
                sum += a * b;
                includedNumbers.emplace(a, b);
                unusedBucket.erase(unusedBucket.begin());
            }

            if (!unusedBucket.empty() && *unusedBucket.begin() > *includedNumbers.begin()) {
                auto [a, b] = *unusedBucket.begin();
                sum += a * b;
                includedNumbers.emplace(a, b);
                unusedBucket.erase(unusedBucket.begin());

                auto [c, d] = *includedNumbers.begin();
                sum -= c * d;
                unusedBucket.emplace(c, d);
                includedNumbers.erase(includedNumbers.begin());
            }

            res.push_back(sum);
        } 
        return res;
    }
};