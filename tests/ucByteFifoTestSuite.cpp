#include "CppUTest/TestHarness.h"

extern "C" {
#include "ucByteFifo.h"
}

ucByteFifo_t fifo; 
uint8_t buffer[5] = {0}; 

TEST_GROUP(ucByteFifoTestSuite) {

	void setup() {
		//Run before every test

		ucByteFifo_Init_Static(&fifo, buffer, sizeof(uint8_t), 5);
	}

	void teardown() {
		//Run after every tes
	}
}; 

TEST(ucByteFifoTestSuite, InitTest) {

	LONGS_EQUAL(0, ucByteFifo_Cnt(&fifo));
	LONGS_EQUAL(0, ucByteFifo_isFull(&fifo));
	LONGS_EQUAL(1, ucByteFifo_isEmpty(&fifo));
}

TEST(ucByteFifoTestSuite, PutTest) {
	uint8_t byte = 50; 

	ucByteFifo_Put(&fifo, byte);
	LONGS_EQUAL(1, ucByteFifo_Cnt(&fifo));
	LONGS_EQUAL(0, ucByteFifo_isFull(&fifo));
	LONGS_EQUAL(0, ucByteFifo_isEmpty(&fifo));
}

TEST(ucByteFifoTestSuite, GetTest) {
	uint8_t rxByte = 0; 
	ucByteFifo_Put(&fifo, 50);

	ucByteFifo_Get(&fifo, &rxByte);
	LONGS_EQUAL(50, rxByte);
	LONGS_EQUAL(0, ucByteFifo_isFull(&fifo));
	LONGS_EQUAL(1, ucByteFifo_isEmpty(&fifo));
}

TEST(ucByteFifoTestSuite, isFullTest) {
	uint8_t byte = 0; 
	byte = 100;
	ucByteFifo_Put(&fifo, byte);
	byte = 200;
	ucByteFifo_Put(&fifo, byte);
	byte = 300;
	ucByteFifo_Put(&fifo, byte);
	byte = 400;
	ucByteFifo_Put(&fifo, byte);
	byte = 500;
	ucByteFifo_Put(&fifo, byte);

	LONGS_EQUAL(1, ucByteFifo_isFull(&fifo));
}

TEST(ucByteFifoTestSuite, CntTest) {
	uint8_t byte = 0; 
	byte = 100;
	ucByteFifo_Put(&fifo, byte);
	byte = 200;
	ucByteFifo_Put(&fifo, byte);
	byte = 300;
	ucByteFifo_Put(&fifo, byte);
	byte = 400;
	ucByteFifo_Put(&fifo, byte);
	byte = 500;
	ucByteFifo_Put(&fifo, byte);

	LONGS_EQUAL(1, ucByteFifo_isFull(&fifo));
	LONGS_EQUAL(5, ucByteFifo_Cnt(&fifo));

	byte = 600;
	ucByteFifo_Put(&fifo, byte);
	LONGS_EQUAL(5, ucByteFifo_Cnt(&fifo));
}



