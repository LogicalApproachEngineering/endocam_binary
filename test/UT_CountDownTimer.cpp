#ifdef ENDOCAM_UT
#include <unistd.h>
#include "devlabs_test.h"
#include "CountDownTimer.h"

using namespace std;

devLABS_TEST_HEADER(CoutDownTimerTest);

namespace tut {
	struct CoutDownTimerTest {

	};

	template<>
	template<>
	void testobject::test<1>() {
		set_test_name("Simple Timer Test");
		CountDownTimer cdTimer;
		ensure_equals("check for initial reset", 0 , cdTimer.getTimeInSeconds());
		cdTimer.start();
		sleep(2);
		cdTimer.pause();
		ensure_equals("check if time lapsed is proper", 2 , cdTimer.getTimeInSeconds());
		cdTimer.stop();
		ensure_equals("check if reset works", 0 , cdTimer.getTimeInSeconds());
	}

	template<>
	template<>
	void testobject::test<2>() {
		set_test_name("Play Pause Timer Test");
		CountDownTimer cdTimer;
		cdTimer.start();
		sleep(2);
		cdTimer.pause();
		ensure_equals("check if time lapsed is proper", 2 , cdTimer.getTimeInSeconds());
		cdTimer.start();
		sleep(2);
		ensure_equals("check if time lapsed is proper", 4 , cdTimer.getTimeInSeconds());
		cdTimer.stop();
		ensure_equals("check if reset works", 0 , cdTimer.getTimeInSeconds());
	}

	template<>
	template<>
	void testobject::test<3>() {
		set_test_name("Reset running Timer Test");
		CountDownTimer cdTimer;
		cdTimer.start();
		sleep(2);
		ensure_equals("check if time lapsed is proper", 2 , cdTimer.getTimeInSeconds());
		cdTimer.start();
		ensure_equals("check if time lapsed is reset from beginning", 0 , cdTimer.getTimeInSeconds());
		cdTimer.stop();
		ensure_equals("check if reset works", 0 , cdTimer.getTimeInSeconds());
	}

	template<>
	template<>
	void testobject::test<4>() {
		set_test_name("String formatted Timer Test");

		CountDownTimer cdTimer;
		cdTimer.start();
		sleep(2);
		cdTimer.pause();
		ensure_equals("check if time lapsed is proper", "00:02" , cdTimer.getTimeInString());
		cdTimer.start();
		sleep(2);
		ensure_equals("check if time lapsed is proper", "00:04" , cdTimer.getTimeInString());
		cdTimer.stop();
		ensure_equals("check if reset works", "00:00" , cdTimer.getTimeInString());
	}
}
#endif //ENDOCAM_UT
