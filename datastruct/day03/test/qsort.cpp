void sort(int* a, int n){
	if(n<1) return;
	int L = 0;
	int R = n-1;
	int M = a[L];//�м�ֵ
	while(L<R){
		while(L<R&&M<=a[R])R--;
		a[L] = a[R];
		while(L<R&&a[L]<=M)L++;
		a[R] = a[L];
	}	
	a[L] = M;//���м�ֵ������ȷλ��	
	sort(a, L); //����߽��з���
	sort(a+L+1, n-L-1); //���ұ߽��з���
}

