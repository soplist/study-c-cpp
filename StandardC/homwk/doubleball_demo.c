#include "doubleball_demo.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//核心代码
int* gen(){
//1 创建球池
	int pool[LENGTH] = {0};
	int i;
	for(i=0; i<LENGTH; i++){
		pool[i] = i+1;
	}
	/*for(i=0; i<LENGTH; i++){
	printf("%d ",pool[i]);
}
	printf("\n");*/
//2 创建一个标记池,检查球序号是否使用过
   int used[LENGTH] = {0};
//3 创建空白区存放红球
	int* balls = (int*)malloc(RED_LENGTH*sizeof(int));
//4 创建随机对象，循环从球池中取出红球
	i = 0;//计数红球
	int index;
	while(1){
		//4.1 随机下标
		index = rand()%LENGTH;
		//4.2 检查下标是否使用过
		if(used[index]){
			continue;
		}
		//4.3 取出一个红球放入balls;
		balls[i++] = pool[index];
		//4.3 标记,表示pool中红球已经用了
		used[index] = 1;
		if(i==RED_LENGTH) break;
	}
	printf("红球排序前:");
	for(i=0;i<RED_LENGTH; i++){
		printf("%d ",balls[i]);
}
	printf("\n");
//5 对红球排序
	sort(balls,RED_LENGTH);
	printf("红球排序后:");
	for(i=0;i<RED_LENGTH; i++){
		printf("%d ",balls[i]);
}
	printf("\n");
//6 对数组扩充出一个兰球的位置
	int* realBalls = realloc(balls,(RED_LENGTH + BLUE_LENGTH)*sizeof(int));
//7 随机一个兰球，放入balls数组的最后
	index = rand()%16;
	realBalls[(RED_LENGTH+BLUE_LENGTH)-1] = pool[index];
//8 返回balls
	return realBalls;
}
//排序硶
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



