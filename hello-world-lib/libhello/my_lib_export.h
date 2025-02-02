﻿#ifndef MY_HEADER_H
#define MY_HEADER_H

#ifdef MY_LIB_SHARED_BUILD
	#ifdef _WIN32
		#ifdef MY_LIB_EXPORTS
			#define MY_LIB_API __declspec(dllexport)
		#else
			#define MY_LIB_API __declspec(dllimport)
		#endif  // MY_LIB_EXPORTS
	#else
		#define MY_LIB_API
	#endif  // _WIN32
#else
	#define MY_LIB_API
#endif  // MY_LIB_SHARED_BUILD

#endif  // MY_HEADER_H
