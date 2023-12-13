#ifdef ENDOCAM_UT
 
#define SHOULD_RUN false
 
#include "devlabs_test.h"
#include "GalleryScreen.h"
#include "UserSettingsScreen.h"
#include "ReviewScreen.h"
#include "MainWindow.h"
#include "SettingScreenComponent.h"
#include "Utility.h"
#include "SystemSettings.h"
#include "LiveViewComponent.h"
#include "CustomKeyboard.h"
#include "CustomFileExplorer.h"

using namespace std;

devLABS_TEST_HEADER(GUITest);

namespace tut {

class TestGalleryScreenModel: public GalleryScreenModel{
public:
	vector<string> m_fileList;
	TestGalleryScreenModel(){

		m_fileList.push_back("./test/data/2018-01-07/DOCTOR/PATIENT/.th/1516523745000_i_t.jpeg");
		m_fileList.push_back("./test/data/2018-01-07/DOCTOR/PATIENT/.th/1516523845000_i_t.jpeg");
		m_fileList.push_back("./test/data/2018-01-07/DOCTOR/PATIENT/.th/1516523945000_i_t.jpeg");
		m_fileList.push_back("./test/data/2018-01-07/DOCTOR/PATIENT/.th/1516524845000_i_t.jpeg");
		m_fileList.push_back("./test/data/2018-01-07/DOCTOR/PATIENT/.th/1516525845000_i_t.jpeg");
		m_fileList.push_back("./test/data/2018-01-07/DOCTOR/PATIENT/.th/1515335964440_i_t.jpeg");
		

		
		vector<string> dates=getDates();
		for(size_t i=0;i<dates.size();i++)
		{
			m_mapDateToThumbnailFiles[dates[i]]=m_fileList;
			int n=m_fileList.size()-1;
			n=std::max(0,n);
			m_fileList.resize(n);
		}
		
	}
};

	
struct GUITest {
	ContentComponent* m_testScreen;
	bool m_showGUI;
	GUITest():m_testScreen(0),m_showGUI(SHOULD_RUN){
	}
	~GUITest(){
		if(m_testScreen) delete m_testScreen;
		MainWindow::delete_instance();
	}
	bool shouldRun(){ return m_showGUI && gtk_init_check(0, 0);}
	
	void addscreen_run(ContentComponent* screen, int screenID)
	{
		addscreen_beforeShow(screen, screenID);
		gtk_main();
	}
	void addscreen_beforeShow(ContentComponent* screen, int screenID)
	{
		m_testScreen=screen;
		string screenName= string("test-screen-")+to_string(screenID);
		MainWindow::get_instance()->addContentComponent(screenName,m_testScreen);

		MainWindow::get_instance()->showWindow();
		MainWindow::get_instance()->showContentComponent(screenName);
	}
	
};
template<>
template<>
void testobject::test<1>() {
	set_test_name("Gate Keeper Test");
	ensure_equals("Do not check-in with m_showGUI=true", m_showGUI,false); 
}

template<>
template<>
void testobject::test<2>() {
	set_test_name("Gallery GUI Test");
	if(shouldRun()) 
	{
		addscreen_run(new GalleryScreen(new TestGalleryScreenModel), get_test_id());
	}
	
}

template<>
template<>
void testobject::test<3>() {
	set_test_name("User Setting GUI Test");
	if(shouldRun())
	{
		addscreen_run(new UserSettingsScreen(0), get_test_id());
	}

}

template<>
template<>
void testobject::test<4>() {
	set_test_name("Review Screen GUI Test");
	if(shouldRun())
	{
		addscreen_run(new ReviewScreen(0), get_test_id());
	}
}





template<>
template<>
void testobject::test<6>() {
	set_test_name("Review Screen GUI with thumbnail selection");
	if(shouldRun())
	{
		SystemSettings::getInstance().setDebug(true);
		SystemSettings::getInstance().add_update_setting(SYS_SETTINGS::TEST_STORAGE,"./test/data");

		ReviewScreen *screen=new ReviewScreen(0);
		addscreen_beforeShow(screen, get_test_id());
		TestGalleryScreenModel model;
		GalleryFile gf=Utility::getGalleryFileFromThumbnail(model.m_fileList[1]);
		screen->on_message("",&gf);
		gtk_main();	
	}
}

template<>
template<>
void testobject::test<7>() {
	set_test_name("Message Box test");
	if(shouldRun())
	{
		MainWindow::get_instance()->show_message("A Test Message","Some more details about the issue");
		gtk_main();	
	}
}

template<>
template<>
void testobject::test<8>() {
	set_test_name("Live View GUI Test");
	if(shouldRun())
	{
		SystemSettings::getInstance().setDebug(true);
		SystemSettings::getInstance().add_update_setting(SYS_SETTINGS::TEST_STORAGE,"./test/data");

		addscreen_run(new LiveViewComponent(0), get_test_id());
	}

}

template<>
template<>
void testobject::test<9>() {
	set_test_name("Keyboard GUI Test");
	if(shouldRun())
	{
//		addscreen_run(new CustomKeyboard(), get_test_id());
	}

}

template<>
template<>
void testobject::test<10>() {
	set_test_name("File Explorer GUI Test");
	if(shouldRun())
	{
		CustomFileExplorer* fileExp = new CustomFileExplorer();
		vector<string> a;
		for(int i=0;i<1000;i++){
			char buff[10] = { 0 };
			sprintf(buff,"%d",i);
			a.push_back(buff);
		}
		fileExp->populateWindow(a,"number","");
		addscreen_run(fileExp, get_test_id());
	}

}

template<>
template<>
void testobject::test<11>() {
	set_test_name("File Explorer GUI Test");
	if(shouldRun())
	{
		CustomFileExplorer* fileExp = new CustomFileExplorer();
		fileExp->populateWindow("src/","cpp","Source");
		addscreen_run(fileExp, get_test_id());
	}

}

}
#endif //ENDOCAM_UT
