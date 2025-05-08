//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int cnt = 0;
        int el;
        for (int i = 0; i < arr.size(); i++) {
            if (cnt == 0) {
                cnt = 1; // Fixed
                el = arr[i];
            }
            else if (arr[i] == el) {
                cnt++;
            }
            else {
                cnt--;
            }
        }
        int cnt1 = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == el) cnt1++;
        }
        if (cnt1 > (arr.size() / 2)) {
            return el;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends