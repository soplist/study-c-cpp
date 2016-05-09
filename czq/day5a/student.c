/*写一个程序，用来管理学生信息。学生信息包括学号、姓名、性别、出生年月、联系方式、住址、成绩。程序用一个结构来保存每一个学生的信息，用一个文件来保存所有学生的信息。程序提供添加学生和查询学生信息（根据学号）功能。要求用菜单，学号自动产生，程序退出后再运行可继续工作。*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

//1、定义一个学生结构v
typedef struct {
	int num;//学号
	char name[20];//姓名
	char gender;//性别
	int yearmonth;//出生年月
	char tel[20];//联系方式
	char addr[50];//住址
	float score;//成绩
}Student;

int showmenu()
{
	char ch;
	do{
		printf("1--添加\n");
		printf("2--查询\n");
		printf("0--退出\n");
		printf("请选择:");
		scanf(" %c", &ch);//空格表示跳过输入的空白字符
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
//2、显示一个菜单（1添加、2查询学生信息和0退出）v
	int choice = showmenu();
//3、让用户选择，无效就重选v

//4、如果用户选择退出，程序结束v
	if(choice=='0') return 0;
//5、如果用户选择添加v
	Student s;
	if(choice=='1'){
	//5.1输入姓名、性别、出生年月、联系方式、住址、成绩v
		printf("请输入姓名、性别、出生年月、联系方式、住址、成绩:\n");
		scanf("%s %c%d%s%s%f",
			  &s.name,&s.gender,&s.yearmonth,
			  &s.tel,&s.addr,&s.score);
	//5.2自动产生学号
		//5.2.1取得文件长度lstat/stat/fstat st_size v
		int n = get_students();
		//5.2.2计算学生个数st_size/sizeof(结构) v
		//5.2.3加1得到新的学号
		s.num = n+1;
	//5.3保存到文件末尾open(O_APPEND)/lseek(SEEK_END)v
		int fd = open("stu.dat",
					O_WRONLY|O_APPEND|O_CREAT,0600);
		write(fd, &s, sizeof(s));
		close(fd);
	}
//6、否则（用户选择的查询）v
	else{
	//6.1输入学号，无效重新输入v
		int num;
		int n = get_students();
		do{
			printf("请输入学号:");
			scanf("%d", &num);
		}while(num<1||num>n);
	//6.2根据学号计算出学生信息在文件中的位置v
		int fd = open("stu.dat",O_RDONLY);
		if(fd<0){
			printf("无法取得学生信息");
			return 1;
		}
		lseek(fd,(num-1)*sizeof(s),SEEK_SET);
	//6.3读取学生信息v
		read(fd, &s, sizeof(s));
	//6.4显示v
		printf("姓名:%s,性别:%c,出生年月:%d,联系方式:%s,住址:%s,成绩:%g\n",
			  s.name,s.gender,s.yearmonth,
			  s.tel,s.addr,s.score);
	}
	}//反复
}	



