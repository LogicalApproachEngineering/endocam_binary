#ifndef devLABS_TEST_H_
#define devLABS_TEST_H_

#include <tut/tut.hpp>

#define devLABS_TEST_HEADER( TYPE) namespace tut \
{ \
	struct TYPE;	\
	typedef	test_group<TYPE> tg; \
	typedef tg::object testobject; \
}\
namespace {\
tut::tg test_group( #TYPE);\
}

#define devLABS_TEST_HEADER_MAX( TYPE,MAXTESTS) namespace tut \
{ \
	struct TYPE;	\
	typedef	test_group<TYPE,MAXTESTS> tg; \
	typedef tg::object testobject; \
}\
namespace {\
tut::tg test_group( #TYPE);\
}

#endif /* devLABS_TEST_H_ */
