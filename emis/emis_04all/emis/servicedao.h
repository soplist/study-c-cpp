#ifndef _MANAGERDAO_H
#define _MANAGERDAO_H
#include <vector>
using namespace std;
#include "manager.h"
namespace emis{
class ManagerDao{
public:
		virtual ~ManagerDao(){}
		virtual void load(vector<Manager>& managers) = 0;//���ǵ�Ч�� ����vectorЧ�ʵ�   ��������
		virtual void save(vector<Manager>& managers) = 0;		
};
}
#endif//_MANAGERDAO_H
