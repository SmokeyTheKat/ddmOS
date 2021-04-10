#include <stdlib/time.h>
#include <kernel/system.h>

void sleep(uint32t secs)
{
	system_sleep(secs*1000000);
}
