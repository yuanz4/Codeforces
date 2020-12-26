#include <bits/stdc++.h>
using namespace std;

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937_64 rng(seed);

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<uint64_t> hash_values(n+1);
    for (auto& i: hash_values)
    	i = rng();
    vector<int> freq(n+1);
    vector<queue<int>> indices(n+1);
    vector<uint64_t> hashes(n+1);
    unordered_map<uint64_t, int> hash_freq;
    hash_freq[hashes[0]]++;
    uint64_t ans = 0;
    int start = 0;
    for (int i = 0; i < n; i++) {
    	int a;
    	cin >> a;
    	if (indices[a].size() >= 3) {
    		int remove = indices[a].front();
    		indices[a].pop();
    		while (start <= remove) {
    			hash_freq[hashes[start]]--;
    			start++;
    		}
    	}
    	int before = freq[a];
    	freq[a] = (freq[a] + 1) % 3;
    	hashes[i+1] = hashes[i] + (freq[a] - before) * hash_values[a];
    	ans += hash_freq[hashes[i+1]]++;
    	indices[a].push(i);
    }
    cout << ans << '\n';
	return 0;
}