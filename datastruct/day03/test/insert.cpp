void sort(int* a, int n){
	for(int i=1; i<n; i++){
		int t = a[i];//Ҫ���������
		int j;//�����λ�� 
		for(j=i; j>0&&a[j-1]>t; j--){ 
			a[j] = a[j-1];	
		}
		a[j] = t;
	}
}

