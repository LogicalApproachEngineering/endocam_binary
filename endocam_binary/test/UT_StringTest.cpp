#ifdef ENDOCAM_UT

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <glib.h>
#include "devlabs_test.h"
#include "Utility.h"
#include "SystemSettings.h"

using namespace std;

devLABS_TEST_HEADER(StringTest);

namespace tut {

struct StringTest {
	std::string m_tempPath;
	~StringTest(){
		if(!m_tempPath.empty()){
		std::string cmd=std::string("rm -rf \"")+m_tempPath+string("\"");
			system(cmd.c_str());
		}
	}
	void makeTempFolder()
	{
		char path[100];
		GDateTime *date_time = g_date_time_new_now_local();
		gint64 dt = g_date_time_to_unix(date_time);
		gint dtms = (g_date_time_get_microsecond(date_time) / 1000);
		sprintf(path, "/tmp/%llu%03d", dt, dtms);
		m_tempPath=string(path);
		Utility::makeFolder(m_tempPath);
		
	}
	void checkPathCreation(string testPath)
{
	ensure_equals(m_tempPath+"/"+testPath,Utility::getStoragePath(testPath));
	ensure(Utility::isDirExist(m_tempPath+"/"+testPath+"/.th"));
}
};

template<>
template<>
void testobject::test<2>() {
	set_test_name("split string test");

	string strData = "omkar mujumdar is testing this function";
	vector<string> res = Utility::splitString(strData, " ");
	ensure_equals("String with space split", res.size(), 6);
	strData += " ";
	res = Utility::splitString(strData, " ");
	ensure_equals("String with space at end split", res.size(), 6);
}




template<>
template<>
void testobject::test<3>() {
	set_test_name("");
	
	makeTempFolder(); //so that we remove it
	string path=m_tempPath+"/2017-12-22/A Doctor/Some Patient/.th/";
	Utility::makeFolder(path);
	Utility::touch(path+string("1515329406234_i_t.png"));
	
	Utility::touch(path+string("1515329406235_i_t.png"));
	
	Utility::touch(path+string("1515329406236_v_t.png"));
	
	Utility::touch(path+string("1515329406237_v_t.png"));
	
	vector<string> result = Utility::searchFilePaths(m_tempPath,"*_t.png");
	ensure_equals("contains list of file paths", result.size(),4);
	
	result = Utility::searchFilePaths(m_tempPath,"*_i_*");
	ensure_equals("should contain only 2 file", result.size() , 2);
	
	SystemSettings::getInstance().add_update_setting(SYS_SETTINGS::TEST_STORAGE,m_tempPath);
	PTIMEOP(result = Utility::getThumbnails();,"getThumbnails");
	ensure_equals("should contain 4 thumbnails", result.size() , 4);
	
	vector<string> result1;
	PTIMEOP(result1 = Utility::getThumbnailsList();,"getThumbnailsList");
	ensure_equals("should contain 4 thumbnails",result1.size() , 4);
	
}

template<>
template<>
void testobject::test<4>() {
	string path="/tmp/some path with spaces.txt";
	int res = Utility::touch(path);
	bool res2 = Utility::isDirExist(path);
	remove(path.c_str());
	ensure_equals("open file with spaces", res, 0);
	ensure_equals("file is not a directory", res2, false);
	
}
template<>
template<>
void testobject::test<5>() {
	set_test_name("timestamp label test");
	gint64 ts=1516819555; //1516819555789 in ms
	GTimeZone *tz=	g_time_zone_new_local();
	gint interval=g_time_zone_find_interval (tz,G_TIME_TYPE_STANDARD,ts);
	gint32 diff=g_time_zone_get_offset(tz,interval);
	g_time_zone_unref (tz);
	
	ensure_equals(Utility::makeEndoDateTimeLabel(ts-diff)
	,string("Jan-24-18\n06:45:55 PM"));
}	

template<>
template<>
void testobject::test<6>() {
	set_test_name("Date validity test");
	ensure("1-Jan-2018",Utility::isValidDate(18,0,1));
	ensure("28-Feb-2018",Utility::isValidDate(18,1,28));
	ensure("29-Feb-2016",Utility::isValidDate(16,1,29));
	ensure("31-Dec-2018",Utility::isValidDate(18,11,31));
	ensure_not("29-Feb-2018",Utility::isValidDate(18,1,29));
	ensure_not("31-Feb-2018",Utility::isValidDate(18,1,31));
	ensure_not("31-Apr-2018",Utility::isValidDate(18,3,31));
}



template<>
template<>
void testobject::test<7>() {
	set_test_name("getStoragePath Test");
	makeTempFolder();
	SystemSettings::getInstance().add_update_setting(SYS_SETTINGS::TEST_STORAGE,m_tempPath);
	checkPathCreation(string("2018-02-12/A Doc/B Patient"));
	checkPathCreation(string("2018-02-12/doc-Mc'donald/B%Pa:tient"));
	
	
}	

#if 0
template<>
template<>
void testobject::test<9>() {
	set_test_name("get thumbnails");
	string mountpath;
	vector<string> vec;
		{
		TIMEOP(mountpath = Utility::GetUSBMediaPath();,t);
		printf("GetUSBMediaPath %lld -> %d \n", t, mountpath.length());
		}
		{
		TIMEOP(mountpath = Utility::get_popen("df");,t);
		printf("df %lld -> %d \n", t, mountpath.length());
		}
		{
		TIMEOP(mountpath = Utility::get_popen("df | grep /media");,t);
		printf("df | grep /media %lld -> %d \n", t, mountpath.length());
		}
		{
		TIMEOP(mountpath = Utility::get_popen("mount");,t);
		printf("mount %lld -> %d \n", t, mountpath.length());
		}
		
		{
		TIMEOP(vec = Utility::getThumbnails();,t);
		printf("getThumbnails %lld -> %d \n", t, vec.size());
		}

		{
			vector<string> files;
			TIMEOP({
			files=Utility::getThumbnailsList();
			},t);
			printf("getThumbnailsList %lld -> %d \n", t, files.size());
			for(int i=0;i< files.size();i++){
				printf("%d => %s\n",i,files[i].c_str());
			}
		}
	}	
#endif

template<>
template<>
void testobject::test<10>() {
	set_test_name("whiteSpace at the end");
	Utility::delSpacesAtCorners("its me");
	Utility::delSpacesAtCorners("   itsme ");
	Utility::delSpacesAtCorners("	it s me   	");
	Utility::delSpacesAtCorners(" \ritsme\n");
	Utility::delSpacesAtCorners("itsmen");

	

}
}
#endif //ENDOCAM_UT
