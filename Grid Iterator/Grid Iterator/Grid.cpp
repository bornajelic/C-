#include "Grid.h"




//================SEGMENT================//
void Segment::refine() {

	if (this->isLeaf()) {
		this->mseg_l.reset(new Segment(mpt_l, (mpt_r + mpt_l) / 2, this));
		this->mseg_r.reset(new Segment((mpt_r + mpt_l) / 2, mpt_r, this));
	}
}

void Segment::coarse() {
	if (!this->getLeft()->isLeaf() || !this->getRight()->isLeaf()) {
		throw std::invalid_argument("Segment has no children, cannot be coarsed");
	}
	this->mseg_l.reset();
	this->mseg_r.reset();
}



//================GRID===============//

Grid::iterator Grid::begin() {
	std::stack<Segment*> tmpStack;
	tmpStack.push(nullptr);
	Segment *tmp = &root;

	if (tmp == nullptr) {
		throw std::invalid_argument("Iterator.begin() -> root = nullptr!");
	}
	while (!tmp->isLeaf()) {
		tmpStack.push(tmp);
		tmp = tmp->getLeft();
	}

	iterator it(tmp);
	it.setStack(tmpStack);
	return it;
}

Grid::iterator Grid::end() {
	iterator it(nullptr);
	return it;
}

void::Grid::uniform_refine() { //refine all leaf segments

	iterator it = begin();
	iterator it_end = end();
	for (it; it != it_end; ++it) {
		if (it->isLeaf()) {
			it->refine();
			++it;
			++it;
			++it;
		}
	}
	return;
}

void Grid::refine_selected(int noSeg) {
	
	iterator it = begin();
	if (noSeg > nOfSegments()) {
		throw std::out_of_range("Error in refine_selected, noSeg > nOfSegments");
	}
	for (int n = 1; n <= noSeg; ++n) {
		if (n == noSeg && it->isLeaf()) {
			std::cout << "profinjujem list "; it->print(); std::cout << "\n";
			it->refine();
			break;
		}
		++it;
	}
	return;
}

void Grid::coarse_selected(int noSeg) {
	iterator it = begin();
	if (noSeg > nOfSegments()) {
		throw std::out_of_range("Error in refine_selected, noSeg > nOfSegments");
	}
	for (int n = 1; n <= noSeg; ++n) {
		if (n == noSeg) {
			it->coarse();
			break;
		}
		++it;
	}
	return;

}


void Grid::print() {
	try {
		iterator it = begin(); //ovo je ok
		iterator it_end = end();
		for (it; it != it_end; ++it) {
			it->print();
		}
	}
	catch (std::out_of_range ex) {
		std::cout << ex.what();
	}
	return;
}

int Grid::nOfSegments() {

	int n = 0;
	auto it = begin();
	auto end_it = end();

	for (; it != end_it; ++it) {
		n++;
	}
	return n;
}




//=========GRID LEAD ITERATOR =============//

GridLeafIterator& GridLeafIterator::operator++() {//daj mi trenutni pa ga inkrementiraj

	if (current->isLeaf()) {

		current = stack.top(); /// mozda da nekako stavim nullptr na kraju stack-a, da iskoristis ako 
		stack.pop();
		flag = true;
		return *this;
	}
	if (flag == true) {
		current = current->getRight();
		flag = false;
	}
	while (!current->isLeaf()) {
		stack.push(current);
		current = current->getLeft();
	}

	if (current->isLeaf()) {
		return *this;
	}


}




