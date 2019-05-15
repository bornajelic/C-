#pragma once
#ifndef GRID_H
#define GRID_H

#include <memory>
#include <iostream>
#include <stack>
#include <stdexcept>


class Segment {

private:
	double mpt_l; //left end of a segment
	double mpt_r; //right end of a segment

	//children of segments
	std::unique_ptr<Segment> mseg_l; //left sub-segment
	std::unique_ptr<Segment> mseg_r; //right sub-segment

	//parent segment
	Segment *mparent;
	friend class GridLeafIterator;

public:
	/*Constructor. It represents left and right end of the interval and
		a pointer to a parent
	*/
	Segment(double left, double right, Segment* parent) :mpt_l(left), mpt_r(right), mparent(parent) {}

	//is this segment a leaf?
	bool isLeaf() const { return mseg_l.get() == nullptr; }

	//Refine a segment, if it has children, do nothing
	void refine();
	
	// remove children of a segment, with this, segment becomes a leaf
	void coarse();

	Segment* getLeft() { return mseg_l.get(); }
	Segment* getRight() { return mseg_r.get(); }

	void print() {
		std::cout << "(" << mpt_l << "," << mpt_r << ") "; 
	}
	Segment *parent() { return mparent; }
};

class GridLeafIterator;




class Grid {

private:
	Segment root;

public:
	
	Grid(double a, double b) :root(a, b, nullptr) {}
	using iterator = GridLeafIterator;
	iterator begin();
	iterator end();

	void uniform_refine();
	void print();
	int nOfSegments();
	void refine_selected(int noSeg);
	void coarse_selected(int noSeg);

};




class GridLeafIterator {

private:
	Segment *mRoot;
	Segment *current; //this one is 
	std::stack<Segment*> stack; //iterator stack
	bool flag; //flag for iterator++

	friend
		bool operator==(GridLeafIterator const &lhs, GridLeafIterator const &rhs) {
		return lhs.current == rhs.current ? 1 : 0;
	}
	friend
		bool operator!=(GridLeafIterator const &lhs, GridLeafIterator const &rhs) {
		return lhs.current != rhs.current ? 1 : 0;
	}

public:
	
	GridLeafIterator(Segment *root) : mRoot(root),current(root){
		stack.push(nullptr);
		flag = false;
	} //drzim mRoot da imam referencu za pocetak

	GridLeafIterator& operator++(); //prefix increment
	Segment& operator*() { return *current; }
	Segment* operator->() { return current; }
	std::stack<Segment*> setStack(std::stack<Segment*>& tmpStack) {
		this->stack = tmpStack;
		return this->stack;
	}
	
};
#endif