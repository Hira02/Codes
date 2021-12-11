
// Sample code to perform I/O:

#include <bits/stdc++.h>

using namespace std;

int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	// cout << "Input number is " << num << endl;		// Writing output to STDOUT
	vector<string> arr;
	for(int i = 0 ; i< num*2 ; i++){
		string str;
		cin>>str;
		arr.push_back(str);
	}
	int i = 0;
	while(i<arr.size()-1){
		string f = arr[i];
		string s = arr[i+1];
		int currDiff = (s[0]-65) - (f[0] - 65);
		for(int j = 1;  j< f.length() ; j++){

			if(currDiff != (s[j]-65) - (f[j] - 65))
				cout<<-1<<"\n";
		}
		cout<<currDiff<<"\n";
		i += 2;

	}
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail


// Write your code here
