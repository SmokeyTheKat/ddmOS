#ifndef __ddcDef__
#define __ddcDef__ 1



typedef enum DOStatus DOStatus;
typedef enum DODelete DODelete;
enum DOStatus { DOS_INACTIVE=0, DOS_ACTIVE, DOS_DELETED };
enum DODelete { DOD_MANUAL=0, DOD_AUTO };

//types
//ints
typedef signed char             int8t;
typedef signed int              int16t;
typedef signed long int         int32t;
typedef signed long long int    int64t;
typedef unsigned char           uint8t;
typedef unsigned int            uint16t;
typedef unsigned long int       uint32t;
typedef unsigned long long int  uint64t;
typedef unsigned long long int  sizet;

//other types
typedef uint8t 			byte;
typedef unsigned char		uchar;
typedef uint16t 		lchar;
typedef uint32t 		wchar;

#ifndef lambda
	#define lambda(lambda$_ret, lambda$_args, lambda$_body)\
	({\
	lambda$_ret lambda$__anon$ lambda$_args\
	lambda$_body\
	&amp;lambda$__anon$;\
	})
	#endif
#ifndef make
	#define make(t,s) ((t*)memBank_get_memory(s*sizeof(t)))
	#endif
#ifndef makea
	#define makea(t,s) ((t*)memBank_get_memory(s*sizeof(t)))
	#endif
#ifndef makep
	#define makep(t) ((t*)memBank_get_memory(sizeof(t)))
	#endif
#ifndef raze
	#define raze(t) (memBank_free_memory(t))
	#endif



#ifndef __RUN_ERROR
	//int __RUN_ERROR = 0;
	#endif
#ifndef run
	#define run __RUN_ERROR = -1;
	#endif
#ifndef end
	#define end(x) __EXIT_JMP_##x:if(__RUN_ERROR==x)
	#endif
#ifndef leave
	#define leave(x) __RUN_ERROR=x;goto __EXIT_JMP_##x;
	#endif


#ifndef __BYINC
	#define __BYINC 10
	#endif
#ifndef MAINF__
	#define MAINF__ int main(ddsize agsc, char** ags)
	#endif
#ifndef SET_DDARGS__
	#define SET_DDARGS__ ddArgs da = init_ddArgs(ags, agsc)
	#define SET_DDARGSV__(x) ddArgs x = init_ddArgs(ags, agsc)
	#endif
#ifndef oBLOCK
	#define oBLOCK {
	#define cBLOCK }
	#endif



#ifndef true
	#define true 1
	#endif
#ifndef false
	#define false 0
	#endif
#ifndef bool
	typedef char bool;
	#endif
#ifndef ddsize
	#define ddsize unsigned long long int
	#endif
#ifndef DNL
	#define DNL '\n'
	#endif
#ifndef NULL
	#define NULL 0
	#endif
#ifndef null
	#define null 0
	#endif
#ifndef nullptr
	#define nullptr 0x00000000
	#endif


#include "./kernel/memBank.h"




#endif
