#include <fstream>
using namespace std;
namespace emis{
int generator_id(void){//����Ψһid
	int id = 1000;
	ifstream ifs("id.dat");
	if(ifs){//��һ�ε��õ�ʱ��ifs=false
		ifs >> id;
		id++;
		ifs.close();
	}
	//�����ļ��ɹ�����Ҷ���idд�ص�id.dat��
	ofstream ofs("id.dat");//���򴴽�,��д��
	ofs << id;
	ofs.close();
	return id;
}
}
//Ϊ�˵��÷��� �ṩͷ�ļ�
