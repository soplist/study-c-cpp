#include <fstream>
using namespace std;
#include "managerdao_file_impl.h"
namespace emis{
void ManagerDaoFileImpl::load(vector<Manager>& managers){
		ifstream ifs("manager.dat");
		if(ifs){
			//���ϵ�ȥ��ȡ�ļ�ֱ����β
			Manager manager(0);//������Ԫ���캯��������:��ֹ����generator_id()
			while(ifs.read((char*)&manager
					,sizeof(manager)))
				managers.push_back(manager);
			ifs.close();
		}
}
void ManagerDaoFileImpl::save(vector<Manager>& managers){
		ofstream ofs("manager.dat");
		if(ofs){
		vector<Manager>::size_type size = 				managers.size();
		for(vector<Manager>::size_type 
			 i=0;i<size;i++)
	ofs.write((const char*)&managers[i],
						sizeof(managers[i]));
			ofs.close();
			//write �Զ�������ʽд��const char* 
		}
}
}
