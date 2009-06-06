#include <malloc.h>
#include <mnemosyne.h>
#include "../unittest.h"

MNEMOSYNE_PERSISTENT void *dummy_ptr1;

SUITE(Suite1)
{
	TEST(Test1)
	{
		__tm_atomic {
			dummy_ptr1 = pmalloc(16);
		}
		CHECK(dummy_ptr1 != NULL);
	}

	TEST(Test2)
	{
		__tm_atomic {
			pfree(dummy_ptr1);
		}
		CHECK(true);
	}
}