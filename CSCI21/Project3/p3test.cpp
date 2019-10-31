/**********************************************/
/***** Project 3                UNIT TEST *****/
/**********************************************/

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "dllist.hpp"

/*
 * Unit test. Do not alter.
 */

TEST_CASE ("Doubly linked list") {

	SECTION("empty list (bool)") {
		DLList<bool> list;

		CHECK(list.empty() == true);
		CHECK(list.getSize() == 0);
		CHECK(list.toString() == "");
		CHECK_THROWS_AS(list.front(), logic_error);
		CHECK_THROWS_AS(list.back(), logic_error);
		CHECK_THROWS_AS(list.popFront(), logic_error);
		CHECK_THROWS_AS(list.popBack(), logic_error);
		CHECK(list.get(true) == false);
		CHECK(list.removeFirst(true) == false);
		CHECK(list.removeAll(true) == false);
	}

	SECTION("unsorted list (int32_t)") {
		DLList<int32_t> list;

		list.pushFront(-50);
		list.pushBack(50);
		list.pushFront(-40);
		list.pushBack(40);
		list.pushFront(-30);
		list.pushBack(30);
		list.pushFront(-20);
		list.pushBack(20);
		list.pushFront(-10);
		list.pushBack(10);

		CHECK(list.empty() == false);
		CHECK(list.getSize() == 10);
		CHECK(list.toString() == "-10,-20,-30,-40,-50,50,40,30,20,10");
		CHECK(list.front() == -10);
		CHECK(list.back() == 10);

		list.pushFront(20);
		CHECK(list.getSize() == 11);
		CHECK(list.toString() == "20,-10,-20,-30,-40,-50,50,40,30,20,10");
		CHECK(list.front() == 20);
		CHECK(list.removeFirst(20) == true);
		CHECK(list.getSize() == 10);
		CHECK(list.toString() == "-10,-20,-30,-40,-50,50,40,30,20,10");
		CHECK(list.front() == -10);

		list.pushFront(20);
		list.pushFront(20);
		CHECK(list.getSize() == 12);
		CHECK(list.toString() == "20,20,-10,-20,-30,-40,-50,50,40,30,20,10");
		CHECK(list.removeAll(20) == true);
		CHECK(list.getSize() == 9);
		CHECK(list.toString() == "-10,-20,-30,-40,-50,50,40,30,10");

		list.clear();

		CHECK(list.empty() == true);
		CHECK(list.getSize() == 0);
		CHECK(list.toString() == "");
		CHECK_THROWS_AS(list.front(), logic_error);
		CHECK_THROWS_AS(list.back(), logic_error);
		CHECK_THROWS_AS(list.popFront(), logic_error);
		CHECK_THROWS_AS(list.popBack(), logic_error);
		CHECK(list.get(true) == false);
		CHECK(list.removeFirst(true) == false);
		CHECK(list.removeAll(true) == false);
	}

	SECTION("sorted list (int32_t)") {
		DLList<int32_t> list;

		for (int32_t i=50; i>0; i-=10) {
			list.insert(-i);
			list.insert(i);
		}

		CHECK(list.empty() == false);
		CHECK(list.getSize() == 10);
		CHECK(list.toString() == "-50,-40,-30,-20,-10,10,20,30,40,50");
		CHECK(list.front() == -50);
		CHECK(list.back() == 50);

		list.insert(20);
		CHECK(list.getSize() == 11);
		CHECK(list.toString() == "-50,-40,-30,-20,-10,10,20,20,30,40,50");
		CHECK(list.removeFirst(20) == true);
		CHECK(list.getSize() == 10);
		CHECK(list.toString() == "-50,-40,-30,-20,-10,10,20,30,40,50");

		list.insert(20);
		list.insert(20);
		CHECK(list.getSize() == 12);
		CHECK(list.toString() == "-50,-40,-30,-20,-10,10,20,20,20,30,40,50");
		CHECK(list.removeAll(20) == true);
		CHECK(list.getSize() == 9);
		CHECK(list.toString() == "-50,-40,-30,-20,-10,10,30,40,50");

		list.popFront();
		list.popBack();
		CHECK(list.getSize() == 7);
		CHECK(list.toString() == "-40,-30,-20,-10,10,30,40");

		list.popFront();
		list.popBack();
		CHECK(list.getSize() == 5);
		CHECK(list.toString() == "-30,-20,-10,10,30");

		list.popFront();
		list.popBack();
		CHECK(list.getSize() == 3);
		CHECK(list.toString() == "-20,-10,10");

		list.popFront();
		list.popBack();
		CHECK(list.getSize() == 1);
		CHECK(list.toString() == "-10");
		CHECK(list.front() == -10);
		CHECK(list.back() == -10);

		list.clear();

		CHECK(list.empty() == true);
		CHECK(list.getSize() == 0);
		CHECK(list.toString() == "");
		CHECK_THROWS_AS(list.front(), logic_error);
		CHECK_THROWS_AS(list.back(), logic_error);
		CHECK_THROWS_AS(list.popFront(), logic_error);
		CHECK_THROWS_AS(list.popBack(), logic_error);
		CHECK(list.get(true) == false);
		CHECK(list.removeFirst(true) == false);
		CHECK(list.removeAll(true) == false);
	}
}
