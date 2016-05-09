#include <fstream>
using namespace std;
namespace emis{
int generator_id(void){//生成唯一id
	int id = 1000;
	ifstream ifs("id.dat");
	if(ifs){//第一次调用的时候ifs=false
		ifs >> id;
		id++;
		ifs.close();
	}
	//无论文件成功与否，我都将id写回到id.dat中
	ofstream ofs("id.dat");//无则创建,并写入
	ofs << id;
	ofs.close();
	return id;
}
}
//为了调用方便 提供头文件
