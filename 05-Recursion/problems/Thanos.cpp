#include<iostream>
#define ll long long int
using namespace std;

int a[20];

bool sorted_array(int l, int r) {
	for (int i=l;i<r-1;i++) {
		if(a[i]>a[i+1]) return false;
	}
	return true;
}
int thanos (int l, int r) {
	cout<<l<<" "<<r<<endl;
	if(r<=l) return 0;
	if(r-l == 1) return 1;
	if(sorted_array(l,r)) return r-l;
	else {
		return max(thanos(l,l+(l+r)/2),thanos(l+(l+r)/2,r));
	}
}

int main() {
	int n; cin>>n;
	for (int i=0;i<n;i++) {
		cin>>a[i];
	}
	
	cout<<thanos(0,n);

	return 0;
}