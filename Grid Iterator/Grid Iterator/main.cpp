#include "Grid.h"

int main() {

	Grid grid(0.0, 1.0);
	//grid.print();
	std::cout << "\n";
	grid.uniform_refine();
	grid.print(); std::cout << "\n";
	grid.uniform_refine();
	grid.print(); std::cout << "\n";

	std::cout << "no of segments = " << grid.nOfSegments() << "\n";

	
	try {
		grid.refine_selected(3);
		grid.print(); std::cout << "\n";
		grid.coarse_selected(3);
		grid.print(); std::cout << "\n";
	}
	catch (std::out_of_range &ex) {
		std::cout << ex.what();
	}
	
}