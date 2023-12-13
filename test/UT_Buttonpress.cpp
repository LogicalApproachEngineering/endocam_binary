#ifdef ENDOCAM_UT
#include "devlabs_test.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <PressState.h>
#include <unistd.h>

using namespace std;

devLABS_TEST_HEADER(ButtonPressTest);

namespace tut {
struct ButtonPressTest{

};

template<>
template<>
void testobject::test<1>() {
	PressStateTable p;
	PressState s;
	int setval = 1;
	s = p.DetectedPress(setval);
	printf("Curr :: %lld -> %d \n",p.m_currentTimeStamp,p.m_currval);
	printf("%d -> VAL %s\n", setval,
			s == NOPRESS ? "NC" : s == SHORTPRESS ? "SHORT" : "LONG");
	ensure_equals("F0->1", s, NOPRESS);

	setval = 0;
	s = p.DetectedPress(setval);
	printf("Curr :: %lld -> %d \n",p.m_currentTimeStamp,p.m_currval);
	printf("%d -> VAL %s\n", setval,
			s == NOPRESS ? "NC" : s == SHORTPRESS ? "SHORT" : "LONG");
	ensure_equals("F1->0", s, NOPRESS);

	s = p.DetectedPress(setval);
	printf("Curr :: %lld -> %d \n",p.m_currentTimeStamp,p.m_currval);
	printf("%d -> VAL %s\n", setval,
			s == NOPRESS ? "NC" : s == SHORTPRESS ? "SHORT" : "LONG");
	ensure_equals("F0->0", s, NOPRESS);

	sleep(1);
	setval = 1;
	s = p.DetectedPress(setval);
	printf("Curr :: %lld -> %d \n",p.m_currentTimeStamp,p.m_currval);
	printf("%d -> VAL %s\n", setval,
			s == NOPRESS ? "NC" : s == SHORTPRESS ? "SHORT" : "LONG");
	ensure_equals("S0->1", s, LONGPRESS);

	s = p.DetectedPress(setval);
	printf("Curr :: %lld -> %d \n",p.m_currentTimeStamp,p.m_currval);
	printf("%d -> VAL %s\n", setval,
			s == NOPRESS ? "NC" : s == SHORTPRESS ? "SHORT" : "LONG");
	ensure_equals("S1->1", s, NOPRESS);

	sleep(1);
	setval = 0;
	s = p.DetectedPress(setval);
	printf("Curr :: %lld -> %d \n",p.m_currentTimeStamp,p.m_currval);
	printf("%d -> VAL %s\n", setval,
			s == NOPRESS ? "NC" : s == SHORTPRESS ? "SHORT" : "LONG");
	ensure_equals("S1->0", s, NOPRESS);

	setval = 1;
	s = p.DetectedPress(setval);
	printf("Curr :: %lld -> %d \n",p.m_currentTimeStamp,p.m_currval);
	printf("%d -> VAL %s\n", setval,
			s == NOPRESS ? "NC" : s == SHORTPRESS ? "SHORT" : "LONG");
	ensure_equals("T0->1", s, SHORTPRESS);

	setval = 0;
	s = p.DetectedPress(setval);
	printf("Curr :: %lld -> %d \n",p.m_currentTimeStamp,p.m_currval);
	printf("%d -> VAL %s\n", setval,
			s == NOPRESS ? "NC" : s == SHORTPRESS ? "SHORT" : "LONG");
	ensure_equals("T1->0", s, NOPRESS);

}
template<>
template<>
void testobject::test<2>() {
	PressStateTable p;
	PressState s;
	int setval = 1;
	s = p.DetectedPress(setval);
	printf("Curr :: %lld -> %d \n",p.m_currentTimeStamp,p.m_currval);
	printf("%d -> VAL %s\n", setval,
			s == NOPRESS ? "NC" : s == SHORTPRESS ? "SHORT" : "LONG");
	ensure_equals("F0->1", s, NOPRESS);

	setval = 0;
	s = p.DetectedPress(setval);
	printf("Curr :: %lld -> %d \n",p.m_currentTimeStamp,p.m_currval);
	printf("%d -> VAL %s\n", setval,
			s == NOPRESS ? "NC" : s == SHORTPRESS ? "SHORT" : "LONG");
	ensure_equals("F1->0", s, NOPRESS);

	sleep(1);
	s = p.DetectedPress(setval);
	printf("Curr :: %lld -> %d \n",p.m_currentTimeStamp,p.m_currval);
	printf("%d -> VAL %s\n", setval,
			s == NOPRESS ? "NC" : s == SHORTPRESS ? "SHORT" : "LONG");
	ensure_equals("F0->0", s, LONGPRESS);

	sleep(1);
	s = p.DetectedPress(setval);
	printf("Curr :: %lld -> %d \n",p.m_currentTimeStamp,p.m_currval);
	printf("%d -> VAL %s\n", setval,
			s == NOPRESS ? "NC" : s == SHORTPRESS ? "SHORT" : "LONG");
	ensure_equals("F0->0", s, NOPRESS);
	
}

template<>
template<>
void testobject::test<3>() {
	PressStateTable p;
	PressState s;
	int setval = 0;
	s = p.DetectedPress(setval);
	printf("Curr :: %lld -> %d \n",p.m_currentTimeStamp,p.m_currval);
	printf("%d -> VAL %s\n", setval,
			s == NOPRESS ? "NC" : s == SHORTPRESS ? "SHORT" : "LONG");
	ensure_equals("F0->1", s, NOPRESS);
	sleep(1);
	setval = 0;
	s = p.DetectedPress(setval);
	printf("Curr :: %lld -> %d \n",p.m_currentTimeStamp,p.m_currval);
	printf("%d -> VAL %s\n", setval,
			s == NOPRESS ? "NC" : s == SHORTPRESS ? "SHORT" : "LONG");
	ensure_equals("F1->0", s, LONGPRESS);

	setval = 1;
	s = p.DetectedPress(setval);
	printf("Curr :: %lld -> %d \n",p.m_currentTimeStamp,p.m_currval);
	printf("%d -> VAL %s\n", setval,
			s == NOPRESS ? "NC" : s == SHORTPRESS ? "SHORT" : "LONG");
	ensure_equals("F0->1", s, NOPRESS);


	s = p.DetectedPress(0);
	printf("Curr :: %lld -> %d \n",p.m_currentTimeStamp,p.m_currval);
	printf("%d -> VAL %s\n", setval,
			s == NOPRESS ? "NC" : s == SHORTPRESS ? "SHORT" : "LONG");
	ensure_equals("S1->0", s, NOPRESS);

//	sleep(1);
	setval = 1;
	s = p.DetectedPress(setval);
	printf("Curr :: %lld -> %d \n",p.m_currentTimeStamp,p.m_currval);
	printf("%d -> VAL %s\n", setval,
			s == NOPRESS ? "NC" : s == SHORTPRESS ? "SHORT" : "LONG");
	ensure_equals("S0->0", s, SHORTPRESS);
	
}

template<>
template<>
void testobject::test<4>() {
	PressStateTable p;
	PressState s;
	int setval = 1;
	s = p.DetectedPress(setval);
	ensure_equals("Should have No_Change",s , NOPRESS);
	setval=0;
	for(int i=0;i<10;i++){
		s = p.DetectedPress(setval);
		if(i==5)
			ensure_equals("Should have Long_Press in loop",s , LONGPRESS);
		else
			ensure_equals("Should have No_Change in loop",s , NOPRESS);
		usleep(100000);
	}
	setval=1;
	s = p.DetectedPress(setval);
	ensure_equals("Should have No_Change after loop",s , NOPRESS);
	setval=0;
	s = p.DetectedPress(setval);
	usleep(200000);
	setval=1;
	s = p.DetectedPress(setval);
	ensure_equals("Should have short_press",s , SHORTPRESS);
}

}
#endif //ENDOCAM_UT