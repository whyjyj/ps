#include <bits/stdc++.h>
using namespace std;

int n, m;
int seq[9];
bool usedFlag[9];

void NM(int k) {
	// BASE CASE
	if(k==m) {
		for(int i=0;i<k;i++) {
			cout << seq[i] << " ";
		}
		cout << '\n';
		return;
	}
	
	for(int i=1;i<=n;i++) {
		if(!usedFlag[i]) {
			if(k==0 || (k>0 && (i > seq[k-1]) ) ) {
				seq[k] = i;
				usedFlag[i] = 1;
				NM(k+1);
				usedFlag[i] = 0;
			}
		}
	}
}

int main(void) {
	cin >> n >> m;
	NM(0);
	
	return 0;
}