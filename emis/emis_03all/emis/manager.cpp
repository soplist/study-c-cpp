#include "manager.h"
#include <cstring>
#include "tools.h"
namespace emis{
Manager::Manager(void):m_id(generator_id()){//��д��id :: ����generator_id() ����ΨһID
	//this->m_id = 1000;
}
Manager::Manager(int){}
int Manager::getId(void)const{
	return m_id;
}
string Manager::getName() const{
	return m_name;
}
void Manager::setName(const char* name){
	strcpy(m_name, name);
}
string Manager::getPassword() const{
	return m_password;
}
void Manager::setPassword(const char* password){
	strcpy(m_password, password);
}
}
