#include "Visitor.h"

#include<iostream>
#include<string>
//DocumentPart class

enum enumeration{
	LATEX,
	HTML
};

void writePlain(std::string text, enumeration e) {

	if (e == HTML) {
		std::cout << text;
	}
	else if (e == LATEX) {
		std::cout << text;
	}
	else {
		throw new std::exception("shit");
	}
}

void writeHyper(std::string text, std::string url, enumeration e) {
	std::string tmp("");
	if (e == HTML) {
		
		tmp += "<a href=\"";
		tmp += url;
		tmp += "\">";
		tmp += text;
		tmp += "<\a>";
		std::cout << tmp;
	}
	else if (e == LATEX) {
		tmp += "\\href{";
		tmp += url;
		tmp += "}{";
		tmp += text;
		tmp += "}";
		std::cout << tmp;
	}
	else {
		throw new std::exception("shit");
	}

}

void writeBold(std::string text, enumeration e) {

	if (e == HTML) {
		std::string tmp("");
		tmp += "<b>";
		tmp += text;
		tmp += "<\b>";
	}
	else if (e == LATEX) {
		std::string tmp("");
		tmp += "{\\bf";
		tmp += text;
		tmp += "}";
		std::cout << tmp;
	}
	else {
		throw new std::exception("shit");
	}

}


DocumentPart::DocumentPart(std::string text) : text(text) {}
DocumentPart::~DocumentPart() {}



//==============end DocumentPart====================//



void PlainText::accept(Visitor* visitor) {
	return visitor->visit(this);
}

void BoldText::accept(Visitor* visitor) {
	return visitor->visit(this);
}

void HyperLink::accept(Visitor* visitor) {
	return visitor->visit(this);
}



//classes which are implementing visitor interfaces

void HtmlVisitor::visit(PlainText *plainText) {
	writePlain(plainText->getText(),HTML);
}
void HtmlVisitor::visit(HyperLink *hyperText) {
	writeHyper(hyperText->getText(), hyperText->getURL(),HTML);
}

void HtmlVisitor::visit(BoldText *boldText) {
	writeBold(boldText->getText(), HTML);
}

void LatexVisitor::visit(PlainText *plainText) {
	writePlain(plainText->getText(), LATEX);
}
void LatexVisitor::visit(HyperLink *hyperText) {
	writeHyper(hyperText->getText(),hyperText->getURL(), LATEX);
}
void LatexVisitor::visit(BoldText *boldText) {
	writeBold(boldText->getText(), LATEX);
}


