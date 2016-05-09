void sort(int* a, int n){
	for(int i=0; i<n-1; i++){
		bool flag = true;
		for(int j=0; j<n-i-1; j++){
			if(a[j]>a[j+1]){
				int t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
				flag = false;
			}
		}
		if(flag)break;
	}
}

