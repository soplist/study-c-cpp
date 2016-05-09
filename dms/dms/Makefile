CXX=g++

server:DMSClient.o LogReader.o ILogSend.o\
          LogSender.o MLogrec.o Logrec.o mainclient.o
	$(CXX) -o server DMSClient.o LogReader.o ILogSend.o\
				LogSender.o MLogrec.o Logrec.o mainclient.o

Logrec.o:Logrec.cpp Logrec.h
	$(CXX) -c -o Logrec.o Logrec.cpp

MLogrec.o:MLogrec.cpp MLogrec.h
	$(CXX) -c -o MLogrec.o MLogrec.cpp

LogReader.o:LogReader.cpp LogReader.h
	$(CXX) -c -o LogReader.o LogReader.cpp

#ILogSend.o:ILogSned.cpp ILogSend.h
#	$(CXX) -c -o ILogSend.o ILogSend.cpp

LogSender.o:LogSender.cpp LogSender.h ILogSend.h
	$(CXX) -c -o LogSender.o LogSender.cpp

DMSClient.o:DMSClient.cpp DMSClient.h
	$(CXX) -c -o DMSClient.o DMSClient.cpp

mainclient.o:mainclient.cpp
	$(CXX) -c -o mainclient.o mainclient.cpp

#DMSClient:DMSClient.o LogReader.o ILogReader.o\
          LogReader.o MLogrec.o Logrec.o
#	$(CXX) -o DMSClient DMSClient.o LogReader.o ILogReader.o\
				LogReader.o MLogrec.o Logrec.o

recvser:recv.o
	$(CXX) -o recvser recv.o

recv.o:recv.cpp
	$(CXX) -c -o recv.o recv.cpp

PHONY:clean
clean:
	rm DMSClient.o
	rm LogReader.o
	rm ILogSend.o
	rm LogSender.o
	rm MLogrec.o
	rm Logrec.o
	rm mainclient.o
	rm server

PHONY:clr
clr:
	rm recv.o
	rm recvser
