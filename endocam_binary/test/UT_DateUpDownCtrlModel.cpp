#ifdef ENDOCAM_UT
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <glib.h>
#include "devlabs_test.h"
#include "Utility.h"
#include "DateUpDownCtrlModel.h"

using namespace std;

devLABS_TEST_HEADER(DateUpDownCtrlModelTest);

namespace tut {

struct DateUpDownCtrlModelTest {
	UpDownCtrlModel *month_model=0, *year_model=0;
	DateUpDownCtrlModel *date_model=0;
	DateUpDownCtrlModelTest(){
		
		year_model = new UpDownCtrlModel(0,99,18);
		ensure_equals(year_model->getText(),string("18"));
		
		month_model = new UpDownCtrlModel(DateTimeHelper::getMonthNames(), 1); 
		ensure_equals(month_model->getText(),string("FEB"));
		
		date_model = new DateUpDownCtrlModel(year_model,month_model, 27);
		ensure_equals(date_model->getText(),string("27"));
	}
	~DateUpDownCtrlModelTest(){
		if(date_model) delete date_model;
		if(month_model) delete month_model;
		if(year_model) delete year_model;
	}
};
template<>
template<>
void testobject::test<1>() {
	set_test_name("Using up and down ticks on Date Ctrl");

	date_model->step(true);
	ensure_equals(date_model->getText(),string("28"));
	
	date_model->step(true);
	ensure_equals(date_model->getText(),string("01"));
	ensure_equals(month_model->getText(),string("FEB"));
	
	date_model->step(true);
	ensure_equals(date_model->getText(),string("02"));
	ensure_equals(month_model->getText(),string("FEB"));
	
	date_model->step(false);
	ensure_equals(date_model->getText(),string("01"));
	ensure_equals(month_model->getText(),string("FEB"));
	
	date_model->step(false);
	ensure_equals(date_model->getText(),string("28"));
	ensure_equals(month_model->getText(),string("FEB"));
	
	year_model->step(false);year_model->step(false); //2016
	
	date_model->step(true);
	ensure_equals(year_model->getText(),string("16"));
	ensure_equals(date_model->getText(),string("29"));
	ensure_equals(month_model->getText(),string("FEB"));
	
	month_model->step(true); 
	ensure_equals(month_model->getText(),string("MAR"));
	date_model->step(true);
	ensure_equals(date_model->getText(),string("30"));
	date_model->step(true);
	ensure_equals(date_model->getText(),string("31"));
	date_model->step(true);
	ensure_equals(date_model->getText(),string("01"));
	ensure_equals(month_model->getText(),string("MAR"));
	
	
}

}
#endif //ENDOCAM_UT