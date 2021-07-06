#include "CppUTest/TestHarness.h"

extern "C" {
#include "ucGenericFifo.h"
}

ucGenericFifo_t gfifo; 
uint8_t gbuffer[5] = {0}; 

TEST_GROUP(ucGenericFifoTestSuite) {

	void setup() {
		//Run before every test

		ucGenericFifo_Init_Static(&gfifo, gbuffer, sizeof(uint8_t), 5);
	}

	void teardown() {
		//Run after every test 
	}
}; 

TEST(ucGenericFifoTestSuite, InitTest) {

	LONGS_EQUAL(0, ucGenericFifo_Cnt(&gfifo));
	LONGS_EQUAL(0, ucGenericFifo_isFull(&gfifo));
	LONGS_EQUAL(1, ucGenericFifo_isEmpty(&gfifo));
}

TEST(ucGenericFifoTestSuite, PutTest) {
	uint8_t byte = 50; 

	ucGenericFifo_Put(&gfifo, &byte);
	LONGS_EQUAL(1, ucGenericFifo_Cnt(&gfifo));
	LONGS_EQUAL(0, ucGenericFifo_isFull(&gfifo));
	LONGS_EQUAL(0, ucGenericFifo_isEmpty(&gfifo));
}

TEST(ucGenericFifoTestSuite, GetTest) {
	uint8_t byte = 50; 
	ucGenericFifo_Put(&gfifo, &byte);

	ucGenericFifo_Get(&gfifo, &byte);
	LONGS_EQUAL(50, byte);
	LONGS_EQUAL(0, ucGenericFifo_isFull(&gfifo));
	LONGS_EQUAL(1, ucGenericFifo_isEmpty(&gfifo));
}

TEST(ucGenericFifoTestSuite, isFullTest) {
	uint8_t byte = 0; 
	byte = 100;
	ucGenericFifo_Put(&gfifo, &byte);
	byte = 200;
	ucGenericFifo_Put(&gfifo, &byte);
	byte = 300;
	ucGenericFifo_Put(&gfifo, &byte);
	byte = 400;
	ucGenericFifo_Put(&gfifo, &byte);
	byte = 500;
	ucGenericFifo_Put(&gfifo, &byte);

	LONGS_EQUAL(1, ucGenericFifo_isFull(&gfifo));
}

TEST(ucGenericFifoTestSuite, CntTest) {
	uint8_t byte = 0; 
	byte = 100;
	ucGenericFifo_Put(&gfifo, &byte);
	byte = 200;
	ucGenericFifo_Put(&gfifo, &byte);
	byte = 300;
	ucGenericFifo_Put(&gfifo, &byte);
	byte = 400;
	ucGenericFifo_Put(&gfifo, &byte);
	byte = 500;
	ucGenericFifo_Put(&gfifo, &byte);

	LONGS_EQUAL(1, ucGenericFifo_isFull(&gfifo));
	LONGS_EQUAL(5, ucGenericFifo_Cnt(&gfifo));

	byte = 600;
	ucGenericFifo_Put(&gfifo, &byte);
	LONGS_EQUAL(5, ucGenericFifo_Cnt(&gfifo));
}



