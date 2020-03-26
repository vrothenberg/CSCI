/*
 * Project 4 - UNIT TESTS
 */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "word.h"
#include "bstree.hpp"

#include <iostream>
#include <sstream>
using std::ostringstream;
using std::streambuf;

/*
 * Unit tests. Do not alter.
 */
TEST_CASE ("Word class") {

	ostringstream outs;

	SECTION("Default constructor") {
		Word word1;

		CHECK(word1.getWord() == "");
		CHECK(word1.getCount() == 0);

		outs << word1;
		CHECK(outs.str() == " 0");
		outs.str("");

		word1.setWord("apple");
		CHECK(word1.getWord() == "APPLE");

		word1.incrementCount();
		CHECK(word1.getCount() == 1);

		outs << word1;
		CHECK(outs.str() == "APPLE 1");
		outs.str("");
	}

	SECTION("Overloaded constructor") {
		Word word1("apple");

		CHECK(word1.getWord() == "APPLE");
		CHECK(word1.getCount() == 1);

		outs << word1;
		CHECK(outs.str() == "APPLE 1");
		outs.str("");
	}

	SECTION("Overloaded operators") {
		Word word1("apple");
		Word word2("banana");

		CHECK((word1 > word2) == false);
		CHECK((word1 < word2) == true);
		CHECK((word1 == word2) == false);

		word2.setWord("apple");

		CHECK((word1 == word2) == true);
	}
}

TEST_CASE("Binary Search Tree (int32_t)") {

	streambuf* oldCout = cout.rdbuf();
	ostringstream captureCout;

	SECTION("BSTree<int32_t> -- EMPTY") {
		BSTree<int32_t> tree;

		CHECK(tree.getSize() == 0);
		CHECK(tree.find(1) == false);
		CHECK(tree.get(1) == nullptr);
		CHECK(tree.remove(1) == false);

		captureCout.str("");
		cout.rdbuf(captureCout.rdbuf());
		tree.printInOrder();
		cout.rdbuf(oldCout);
		CHECK(captureCout.str() == "");

		captureCout.str("");
		cout.rdbuf(captureCout.rdbuf());
		tree.printReverseOrder();
		cout.rdbuf(oldCout);
		CHECK(captureCout.str() == "");
	}

	SECTION("BSTree<int32_t> -- ONE ITEM") {
		BSTree<int32_t> tree;

		CHECK(tree.insert(100) == true);

		CHECK(tree.getSize() == 1);
		CHECK(tree.find(100) == true);

		int32_t* t = tree.get(100);
		CHECK(t != nullptr);
		CHECK(*t == 100);

		captureCout.str("");
		cout.rdbuf(captureCout.rdbuf());
		tree.printInOrder();
		cout.rdbuf(oldCout);

		CHECK(captureCout.str() == "100\n");

		captureCout.str("");
		cout.rdbuf(captureCout.rdbuf());
		tree.printReverseOrder();
		cout.rdbuf(oldCout);
		CHECK(captureCout.str() == "100\n");

		CHECK(tree.insert(100) == false);
		
		CHECK(tree.remove(100) == true);
		CHECK(tree.getSize() == 0);
		CHECK(tree.find(100) == false);
		CHECK(tree.get(100) == nullptr);
		CHECK(tree.remove(100) == false);

		captureCout.str("");
		cout.rdbuf(captureCout.rdbuf());
		tree.printInOrder();
		cout.rdbuf(oldCout);
		CHECK(captureCout.str() == "");

		captureCout.str("");
		cout.rdbuf(captureCout.rdbuf());
		tree.printReverseOrder();
		cout.rdbuf(oldCout);
		CHECK(captureCout.str() == "");
	}

	SECTION("BSTree<int32_t> -- MULTIPLE ITEMS") {
		BSTree<int32_t> tree;

		tree.insert(100);
		tree.insert(50);
		tree.insert(150);
		tree.insert(25);
		tree.insert(75);
		tree.insert(125);
		tree.insert(175);

		CHECK(tree.getSize() == 7);

		captureCout.str("");
		cout.rdbuf(captureCout.rdbuf());
		tree.printInOrder();
		cout.rdbuf(oldCout);
		CHECK(captureCout.str() == "25\n50\n75\n100\n125\n150\n175\n");

		captureCout.str("");
		cout.rdbuf(captureCout.rdbuf());
		tree.printReverseOrder();
		cout.rdbuf(oldCout);
		CHECK(captureCout.str() == "175\n150\n125\n100\n75\n50\n25\n");

		CHECK(tree.insert(25) == false);
		CHECK(tree.insert(50) == false);
		CHECK(tree.insert(75) == false);
		CHECK(tree.insert(100) == false);
		CHECK(tree.insert(125) == false);
		CHECK(tree.insert(150) == false);
		CHECK(tree.insert(175) == false);
		CHECK(tree.getSize() == 7);

		CHECK(tree.remove(25) == true);
		CHECK(tree.getSize() == 6);

		captureCout.str("");
		cout.rdbuf(captureCout.rdbuf());
		tree.printInOrder();
		cout.rdbuf(oldCout);
		CHECK(captureCout.str() == "50\n75\n100\n125\n150\n175\n");

		CHECK(tree.remove(125) == true);
		CHECK(tree.getSize() == 5);

		captureCout.str("");
		cout.rdbuf(captureCout.rdbuf());
		tree.printReverseOrder();
		cout.rdbuf(oldCout);
		CHECK(captureCout.str() == "175\n150\n100\n75\n50\n");

		CHECK(tree.remove(100) == true);
		CHECK(tree.getSize() == 4);

		captureCout.str("");
		cout.rdbuf(captureCout.rdbuf());
		tree.printInOrder();
		cout.rdbuf(oldCout);
		CHECK(captureCout.str() == "50\n75\n150\n175\n");

		CHECK(tree.remove(75) == true);
		CHECK(tree.getSize() == 3);

		captureCout.str("");
		cout.rdbuf(captureCout.rdbuf());
		tree.printReverseOrder();
		cout.rdbuf(oldCout);
		CHECK(captureCout.str() == "175\n150\n50\n");

		CHECK(tree.remove(150) == true);
		CHECK(tree.getSize() == 2);

		captureCout.str("");
		cout.rdbuf(captureCout.rdbuf());
		tree.printInOrder();
		cout.rdbuf(oldCout);
		CHECK(captureCout.str() == "50\n175\n");

		CHECK(tree.remove(50) == true);
		CHECK(tree.getSize() == 1);

		captureCout.str("");
		cout.rdbuf(captureCout.rdbuf());
		tree.printReverseOrder();
		cout.rdbuf(oldCout);
		CHECK(captureCout.str() == "175\n");

		CHECK(tree.remove(50) == false);
		CHECK(tree.find(50) == false);
		CHECK(tree.get(50) == nullptr);


		CHECK(tree.remove(175) == true);
		CHECK(tree.getSize() == 0);

		captureCout.str("");
		cout.rdbuf(captureCout.rdbuf());
		tree.printInOrder();
		cout.rdbuf(oldCout);
		CHECK(captureCout.str() == "");

		tree.insert(100);
		tree.insert(50);
		tree.insert(150);
		tree.insert(25);
		tree.insert(75);
		tree.insert(125);
		tree.insert(175);
		tree.clear();
		CHECK(tree.getSize() == 0);

		captureCout.str("");
		cout.rdbuf(captureCout.rdbuf());
		tree.printInOrder();
		cout.rdbuf(oldCout);
		CHECK(captureCout.str() == "");
	}
}

TEST_CASE("Binary Search Tree (Word)") {
	streambuf* oldCout = cout.rdbuf();
	ostringstream captureCout;

	BSTree<Word> tree;

	tree.insert(Word("banana"));
	tree.insert(Word("apple"));
	tree.insert(Word("orange"));

	CHECK(tree.getSize() == 3);

	captureCout.str("");
	cout.rdbuf(captureCout.rdbuf());
	tree.printInOrder();
	cout.rdbuf(oldCout);
	CHECK(captureCout.str() == "APPLE 1\nBANANA 1\nORANGE 1\n");

	captureCout.str("");
	cout.rdbuf(captureCout.rdbuf());
	tree.printReverseOrder();
	cout.rdbuf(oldCout);
	CHECK(captureCout.str() == "ORANGE 1\nBANANA 1\nAPPLE 1\n");

	Word* w = tree.get(Word("apple"));
	w->incrementCount();
	w->incrementCount();

	w = tree.get(Word("orange"));
	w->incrementCount();

	captureCout.str("");
	cout.rdbuf(captureCout.rdbuf());
	tree.printInOrder();
	cout.rdbuf(oldCout);
	CHECK(captureCout.str() == "APPLE 3\nBANANA 1\nORANGE 2\n");

	CHECK(tree.insert(Word("apple")) == false);
}
