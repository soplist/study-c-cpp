/*дһ��������������ѧ����Ϣ��ѧ����Ϣ����ѧ�š��������Ա𡢳������¡���ϵ��ʽ��סַ���ɼ���������һ���ṹ������ÿһ��ѧ������Ϣ����һ���ļ�����������ѧ������Ϣ�������ṩ���ѧ���Ͳ�ѯѧ����Ϣ������ѧ�ţ����ܡ�Ҫ���ò˵���ѧ���Զ������������˳��������пɼ���������*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

//1������һ��ѧ���ṹv
typedef struct {
	int num;//ѧ��
	char name[20];//����
	char gender;//�Ա�
	int yearmonth;//��������
	char tel[20];//��ϵ��ʽ
	char addr[50];//סַ
	float score;//�ɼ�
}Student;

int showmenu()
{
	char ch;
	do{
		printf("1--���\n");
		printf("2--��ѯ\n");
		printf("0--�˳�\n");
		printf("��ѡ��:");
		scanf(" %c", &ch);//�ո��ʾ��������Ŀհ��ַ�
	}while(ch!='0'&&ch!='1'&&ch!='2');
	return ch;
}
int get_students()
{
	struct stat s;
	if(lstat("stu.dat",&s)<0) return 0;
	return s.st_size/sizeof(Student);
}
int main()
{
	for(;;){
//2����ʾһ���˵���1��ӡ�2��ѯѧ����Ϣ��0�˳���v
	int choice = showmenu();
//3�����û�ѡ����Ч����ѡv

//4������û�ѡ���˳����������v
	if(choice=='0') return 0;
//5������û�ѡ�����v
	Student s;
	if(choice=='1'){
	//5.1�����������Ա𡢳������¡���ϵ��ʽ��סַ���ɼ�v
		printf("�������������Ա𡢳������¡���ϵ��ʽ��סַ���ɼ�:\n");
		scanf("%s %c%d%s%s%f",
			  &s.name,&s.gender,&s.yearmonth,
			  &s.tel,&s.addr,&s.score);
	//5.2�Զ�����ѧ��
		//5.2.1ȡ���ļ�����lstat/stat/fstat st_size v
		int n = get_students();
		//5.2.2����ѧ������st_size/sizeof(�ṹ) v
		//5.2.3��1�õ��µ�ѧ��
		s.num = n+1;
	//5.3���浽�ļ�ĩβopen(O_APPEND)/lseek(SEEK_END)v
		int fd = open("stu.dat",
					O_WRONLY|O_APPEND|O_CREAT,0600);
		write(fd, &s, sizeof(s));
		close(fd);
	}
//6�������û�ѡ��Ĳ�ѯ��v
	else{
	//6.1����ѧ�ţ���Ч��������v
		int num;
		int n = get_students();
		do{
			printf("������ѧ��:");
			scanf("%d", &num);
		}while(num<1||num>n);
	//6.2����ѧ�ż����ѧ����Ϣ���ļ��е�λ��v
		int fd = open("stu.dat",O_RDONLY);
		if(fd<0){
			printf("�޷�ȡ��ѧ����Ϣ");
			return 1;
		}
		lseek(fd,(num-1)*sizeof(s),SEEK_SET);
	//6.3��ȡѧ����Ϣv
		read(fd, &s, sizeof(s));
	//6.4��ʾv
		printf("����:%s,�Ա�:%c,��������:%d,��ϵ��ʽ:%s,סַ:%s,�ɼ�:%g\n",
			  s.name,s.gender,s.yearmonth,
			  s.tel,s.addr,s.score);
	}
	}//����
}	



