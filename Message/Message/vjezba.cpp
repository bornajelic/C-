
struct Foo {
	~Foo() {
		if (i != nullptr) {
			delete i;
			i = nullptr;
		}
	}
	int *i = nullptr;
};

void funcByValue(Foo other); //value semantics
void FuncByRef(Foo& other);  //reference semantics

int main() {

	Foo f1;
	f1.i = new int(42);

	Foo f2(f1);
}