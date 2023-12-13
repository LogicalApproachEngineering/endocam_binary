#ifdef ENDOCAM_UT
#include "devlabs_test.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <thread>
#include "SystemSettings.h"
#include "Results.h"
#include "I2CCom.h"
#include "Utility.h"
#include "Logger.h"
#include <unistd.h>

using namespace std;

DEVLABS_TEST_HEADER(LoggingTest);

namespace tut {
struct 
LoggingTest{
	~LoggingTest(){
		Utility::exec(string("rm -rf ")+Logger::getLogFolder()+"/log_*.log");	
	}
};

void logSomething(){
		std::string fname=Logger::instance().getLogFileName();
		for(int i=0;i<10;i++)
		{
			Logger::instance().log("Log my first message", Logger::kLogLevelDebug);
			usleep(10000);
			Logger::instance().log("Log my Second message");
			vector<string> items = {"item1", "item2"};
			Logger::instance().log(items, Logger::kLogLevelError);
		}
		ensure("File should exist",Utility::isFileExist(fname));
	}
	
template<>
template<>
void testobject::test<1>() {
	
	logSomething();
	
	// now create 2 new threads and test
	  std::thread th1(logSomething);
	  std::thread th2(logSomething);
	  
	  th1.join();
	  th2.join();
}

}
#endif //ENDOCAM_UT

