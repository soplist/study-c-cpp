#include "buffer.h"
//º¯ÊýÄ£°å
template <typename T> 
void Buffer<T>::push(T x){ 
	buf[sz++] = x;
}	
template <typename T>
T Buffer<T>::get(){ 
	sz--; 
	return buf[sz]; 
}	

int main()
{
	Buffer<int> buf;
	buf.push(1);
}


