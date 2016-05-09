#include "manager.h"
#include <cstring>
namespace emis{
Manager::Manager(void):m_id(1000){//ÏÈÐ´ËÀid
	//this->m_id = 1000;
}
Manager::Manager(int){}
int Manager::getId(void){
	return m_id;
}
string Manager::getName(){
	return m_name;
}
void Manager::setName(const char* name){
	strcpy(m_name, name);
}
string Manager::getPassword(){
	return m_password;
}
void Manager::setPassword(const char* password){
	strcpy(m_password, password);
}
}
