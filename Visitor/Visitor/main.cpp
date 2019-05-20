#include "Visitor.h"
#include<list>
#include<iostream>
#include<memory>
#include <string>
int main() {

	typedef std::unique_ptr<DocumentPart> PTR;
	typedef std::list<PTR> Document;
	Document document;
	try {
		document.push_back(PTR(new PlainText("Ovo je obican text, a ovo ")));
		document.push_back(PTR(new BoldText("je podebljan text")));
		document.push_back(PTR(new PlainText(", konacno ")));
		document.push_back(PTR(new HyperLink("jedan hyperlink.", "web.math.hr")));
		


	HtmlVisitor *hv = new HtmlVisitor();
	for (Document::iterator it = document.begin(); it != document.end(); ++it)
		(*it)->accept(hv);

	std::cout << std::endl;
	LatexVisitor * lv = new LatexVisitor();
	for (Document::iterator it = document.begin(); it != document.end(); ++it)
		(*it)->accept(lv);

	std::cout << std::endl;
	}
	catch (std::exception e) {
		std::cout << e.what();
	}
	return 0;
}