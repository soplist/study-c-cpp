#include <algorithm>
using namespace std;
void sort(int* a, int n){
	for(int i=0; i<n-1; i++){
		int k = i;//������С�����±�
		for(int j=i+1; j<n; j++){
			if(a[j]<a[k]) k = j;
		}
		if(k!=i) swap(a[k], a[i]);
	}
}

