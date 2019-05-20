#pragma once
#ifndef __VISITOR__H__
#define __VISITOR__H__

#include <iostream>
// VISITOR INTERFACE
struct Visitor;

struct Visitable {
	virtual void accept(Visitor*) = 0;
};


/////////////////////////////

class DocumentPart : public Visitable {

private:

	std::string text;

public:

	DocumentPart(std::string);

	virtual ~DocumentPart();

	std::string getText() {
		return this->text; //error reading characters of a string, vjerojatno je string temp
	}

};


class PlainText : public DocumentPart  {

public:
	PlainText(std::string text) : DocumentPart(text) {}
	void accept(Visitor*);
	
};

class BoldText : public DocumentPart {

public:
	BoldText(std::string text) : DocumentPart(text) {}
	void accept(Visitor*);
};

class HyperLink : public DocumentPart {
private:
	std::string url;
public:
	HyperLink(std::string text, std::string url) : DocumentPart(text), url(url) {}
	void accept(Visitor*);
	std::string getURL() {
		return this->url;
	}
};

struct Visitor {

	virtual void visit(PlainText*) = 0;
	virtual void visit(BoldText*) = 0;
	virtual void visit(HyperLink*) = 0;
};

struct HtmlVisitor : public Visitor {

	void visit(PlainText*);
	void visit(BoldText*);
	void visit(HyperLink*);
};

struct LatexVisitor : public Visitor {

	void visit(PlainText*);
	void visit(BoldText*);
	void visit(HyperLink*);
};


#endif