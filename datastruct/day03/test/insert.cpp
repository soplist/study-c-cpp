void sort(int* a, int n){
	for(int i=1; i<n; i++){
		int t = a[i];//要插入的数据
		int j;//插入的位置 
		for(j=i; j>0&&a[j-1]>t; j--){ 
			a[j] = a[j-1];	
		}
		a[j] = t;
	}
}

