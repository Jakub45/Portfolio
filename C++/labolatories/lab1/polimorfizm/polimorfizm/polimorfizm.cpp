#include <iostream>
using namespace std;

class unit {
protected:
	int health = 0;
	int speed = 0;
public:
	void is_ready();
	virtual void print_parameters();
};

void unit::is_ready() {
	cout << "unit ready" << endl;
}

void unit::print_parameters() {
	cout << health << speed << endl;
}


class vehicle : public unit {
private:
	char name[10] = "titan";
	int armor = 50 ;
public:
	vehicle() {
		health = 100;
		speed = 20;
	}
	void print_parameters() override {
		cout << health << "\t" << speed << "\t" << name << "\t" << armor << endl;
	}
};
class infantry : public unit {
private:
	char name[10] = "infantry";
	int armor = 10 ;
public:
	infantry() {
		health = 20;
		speed = 15;
	}
	void print_parameters() override {
		cout << health << "\t" << speed << "\t" << name << "\t" << armor << endl;
	}
};

int main() {

	unit* infantry1 = new infantry();
	unit* titan1 = new vehicle();

	infantry1->print_parameters();
	titan1->print_parameters();
	return 0;
}