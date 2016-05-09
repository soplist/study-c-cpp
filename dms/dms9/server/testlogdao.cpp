#include "logdao.h"
int main(){
   LogDao logdao;
   logdao.connect("openlab/open123");
   MatchedLogRec mlog={"openlab",9527,
   1000,3000,2000,"192.168.1.110",
   "192.168.0.20"};
   logdao.saveData(mlog);
   logdao.commit();
   logdao.disConnect();
}

