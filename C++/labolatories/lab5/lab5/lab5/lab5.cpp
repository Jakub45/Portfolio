#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

class my_vector
{
private:
	double* cr; //cr[0] - x; cr[1] - y; cr[2] - z
public:
	my_vector() : cr(NULL) {}
	my_vector(double xx, double yy, double zz);
	~my_vector() {
		if (cr)
			delete[] cr;
		cr = NULL;
	}
	my_vector(const my_vector& ob);
	my_vector(my_vector&& ob);
	my_vector& operator = (const my_vector& pb);
	my_vector& operator = (my_vector&& pb);
	my_vector operator + (const my_vector& right) const;
	my_vector operator * (const my_vector& right) const; //vector product: res = v1 x v2
	double operator * (const my_vector* right) const; //dot product: dot = v1 * v2

	friend std::istream& operator >> (std::istream& strm, my_vector& v) {
		return(strm >> v.cr[0] >> v.cr[1] >> v.cr[2]);
	}
	friend std::ostream& operator << (std::ostream& strm, const my_vector& v) {
		return(strm << v.cr[0] << " " << v.cr[1] << " " << v.cr[2]);
	}
	void disp(const char* str);
private:
	void alloc(); //allocation of memory
};


my_vector::my_vector(double xx, double yy, double zz) {
	alloc();
	this->cr[0] = xx;
	this->cr[1] = yy;
	this->cr[2] = zz;
}

my_vector::my_vector(const my_vector& ob) {
	alloc();
	this->cr[0] = ob.cr[0];
	this->cr[1] = ob.cr[1];
	this->cr[2] = ob.cr[2];
}
my_vector::my_vector(my_vector&& ob) {
	this->cr = ob.cr;
	ob.cr = NULL;
}

void my_vector::alloc()
{
	try
	{
		cr = new double[3];
		memset(cr, 0, 3 * sizeof(double));
	}
	catch (std::bad_alloc)
	{
		cout << "memory allocation error" << endl;
		system("pause");
		exit(1);
	}
}
void my_vector::disp(const char* str)
{
	if (cr)
	{
		cout << str << ":" << *this << endl;
	}
}

my_vector& my_vector::operator= (const my_vector& pb) {

	if (this == &pb)
		return *this;

	if (cr == NULL) {
		alloc();
	}
	this->cr[0] = pb.cr[0];
	this->cr[1] = pb.cr[1];
	this->cr[2] = pb.cr[2];
	return *this;
}

my_vector& my_vector::operator= (my_vector&& pb) {

	if (this == &pb)
		return *this;

	delete[] cr;

	this->cr = pb.cr;
	pb.cr = NULL;
	return *this;
}
//y1​z2​−z1​y2​,z1​x2​−x1​z2​,x1​y2​−y1​x
my_vector my_vector::operator* (const my_vector& right) const {
	return my_vector(
		(this->cr[1] * right.cr[2]) - (right.cr[1] * this->cr[2]),
		(this->cr[2] * right.cr[0]) - (right.cr[2] * this->cr[0]),
		(this->cr[0] * right.cr[1]) - (right.cr[0] * this->cr[1])
	);
}


double my_vector::operator*(const my_vector* right) const {
	return (
		(this->cr[0] * right->cr[0]) +
		(this->cr[1] * right->cr[1]) +
		(this->cr[2] * right->cr[2])
	);
}

my_vector my_vector::operator+(const my_vector& right) const
{
	return my_vector(
		cr[0] + right.cr[0],
		cr[1] + right.cr[1],
		cr[2] + right.cr[2]
	);
}


int main() {
	
	my_vector v1(1, 2, -1), v2(2, 1, 1), res;
	v1.disp("v1");
	v2.disp("v2");
	res = v1 + v2;
	res.disp("v1 + v2");
	my_vector res1 = v1 * v2;
	res1.disp("v1 x v2");
	res1 = v2 * v1;
	res1.disp("v2 x v1");
	cout << "v1 * v2: " << v1 * (&v2) << endl;
	my_vector v3(0, 0, 0);
	cin >> v3;
	v3.disp("v3");
	ofstream my_file("my_output_file.txt");
	if (my_file.is_open())
	{
		my_file << "v1 * v2: " << v1 * (&v2);
		my_file.close();
		system("notepad.exe my_output_file.txt");
	}
	return 0;
}