#include "doubleball_demo.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//���Ĵ���
int* gen(){
//1 �������
	int pool[LENGTH] = {0};
	int i;
	for(i=0; i<LENGTH; i++){
		pool[i] = i+1;
	}
	/*for(i=0; i<LENGTH; i++){
	printf("%d ",pool[i]);
}
	printf("\n");*/
//2 ����һ����ǳ�,���������Ƿ�ʹ�ù�
   int used[LENGTH] = {0};
//3 �����հ�����ź���
	int* balls = (int*)malloc(RED_LENGTH*sizeof(int));
//4 �����������ѭ���������ȡ������
	i = 0;//��������
	int index;
	while(1){
		//4.1 ����±�
		index = rand()%LENGTH;
		//4.2 ����±��Ƿ�ʹ�ù�
		if(used[index]){
			continue;
		}
		//4.3 ȡ��һ���������balls;
		balls[i++] = pool[index];
		//4.3 ���,��ʾpool�к����Ѿ�����
		used[index] = 1;
		if(i==RED_LENGTH) break;
	}
	printf("��������ǰ:");
	for(i=0;i<RED_LENGTH; i++){
		printf("%d ",balls[i]);
}
	printf("\n");
//5 �Ժ�������
	sort(balls,RED_LENGTH);
	printf("���������:");
	for(i=0;i<RED_LENGTH; i++){
		printf("%d ",balls[i]);
}
	printf("\n");
//6 �����������һ�������λ��
	int* realBalls = realloc(balls,(RED_LENGTH + BLUE_LENGTH)*sizeof(int));
//7 ���һ�����򣬷���balls��������
	index = rand()%16;
	realBalls[(RED_LENGTH+BLUE_LENGTH)-1] = pool[index];
//8 ����balls
	return realBalls;
}
//����
void sort(int* pArry, int count){
 	int i,j;
	for(i=0; i<count; i++){
		for(j=0; j<count-i-1; j++){
			if(pArry[j]>pArry[j+1]){
					int temp = pArry[j];
					pArry[j] = pArry[j+1];
					pArry[j+1] = temp;
			}
		}
	}	
}



