#ifdef ENDOCAM_UT
#include "devlabs_test.h"
#include "Utility.h"

using namespace std;

devLABS_TEST_HEADER(GalleryTest);

namespace tut {

struct GalleryTest {

};


template<>
template<>
void testobject::test<2>() {
	set_test_name("date format conversion");
	ensure_equals("JAN-07-18",Utility::ddmmyy_to_uiDate(string("2018-01-07")));
	ensure_equals("JUL-01-18",Utility::ddmmyy_to_uiDate(string("2018-07-01")));
	//invalid date scenario
	ensure_equals("2018-01-32",Utility::ddmmyy_to_uiDate(string("2018-01-32")));
	ensure_equals("2018-02-29",Utility::ddmmyy_to_uiDate(string("2018-02-29")));
}
template<>
template<>
void testobject::test<3>() {
	set_test_name("get path from thumbnail");
	ensure_equals("/media/Flash Drive/2017-12-22/A Doctor/Some Patient/",
		Utility::getFolderPathFromThumbnail("/media/Flash Drive/2017-12-22/A Doctor/Some Patient/.th/1515329406234_v_t.png"));
	
}
}
#endif //ENDOCAM_UT
