#ifndef _MANAGERDAO_H
#define _MANAGERDAO_H
#include <vector>
using namespace std;
#include "manager.h"
namespace emis{
class ManagerDao{
public:
		virtual ~ManagerDao(){}
		virtual void load(vector<Manager>& managers) = 0;//考虑到效率 返回vector效率低   传递引用
		virtual void save(vector<Manager>& managers) = 0;		
};
}
#endif//_MANAGERDAO_H
