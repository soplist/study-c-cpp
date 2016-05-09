#include "manager.h"
#include <cstring>
#include "tools.h"
namespace emis{
Manager::Manager(void):m_id(generator_id()){//先写死id :: 调用generator_id() 产生唯一ID
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
