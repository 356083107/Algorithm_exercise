#include <iostream>
#include <initializer_list>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <assert.h>
using namespace std;

//struct Point
//{
//	int _x;
//	int _y;
//};
//
//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//		cout << "Date(int year, int month, int day)" << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
////
////int main()
////{
////	Point p1 = { 1, 2 };
////	Point p2 { 1, 2 };
////	int x1 = 1;
////	int x2{ 2 };
////	// !!!
////	int* p3 = new int[4]{0};
////	int* p4 = new int[4]{1,2,3,4};
////
////	Date d1;
////	Date d2(2022, 1, 17);
////	// 这里虽然可以这么用，但是我们建议大家用，这种用法是为其他地方准备的
////	Date d3{2022, 1, 18};
////	Date d4 = { 2022, 1, 18 };
////
////
////	return 0;
////}
//
//namespace bit
//{
//	template<class T>
//	class vector {
//	public:
//		typedef T* iterator;
//
//		vector(initializer_list<T> l)
//		{
//			_start = new T[l.size()];
//			_finish = _start + l.size();
//			_endofstorage = _start + l.size();
//
//			iterator vit = _start;
//			/*typename initializer_list<T>::iterator lit = l.begin();
//			while (lit != l.end())
//			{
//				*vit++ = *lit++;
//			}*/
//
//			for (auto e : l)
//			   *vit++ = e;
//		}
//
//		vector<T>& operator=(initializer_list<T> l) {
//			vector<T> tmp(l);
//			std::swap(_start, tmp._start);
//			std::swap(_finish, tmp._finish);
//			std::swap(_endofstorage, tmp._endofstorage);
//
//			return *this;
//		}
//	private:
//		iterator _start;
//		iterator _finish;
//		iterator _endofstorage;
//	};
//}
//
//int main()
//{
//	auto il1 = { 10, 20, 30 };
//	std::initializer_list<int> il2 = { 1, 2, 3, 4 };
//	cout << typeid(il1).name() << endl;
//
//	vector<int> v = { 1, 2, 3, 4, 5 };
//	list<int> lt { 10, 20, 30};
//	vector<Date> vd = { { 2022, 1, 17 }, Date{ 2022, 1, 17 }, { 2022, 1, 17 } };
//	map<string, int> dict = { make_pair("sort", 1), { "insert", 2 } };
//	
//	bit::vector<int> bv = { 1, 2, 3, 4, 5 };
//	bv = { 10, 20, 30 };
//
//	return 0;
//}

// decltype的一些使用使用场景
template<class T1, class T2>
void F(T1 t1, T2 t2)
{
	decltype(t1 * t2) ret;
	cout << typeid(ret).name() << endl;

	//return ret;
}

void f(int)
{
	cout << "void f(int)" << endl;
}

void f(int*)
{
	cout << "void f(int*)" << endl;
}

//int main()
//{
//	//int i = 10;
//	//auto p = &i;
//	//auto pf = strcpy;
//
//	//cout << typeid(p).name() << endl;
//	//cout << typeid(pf).name() << endl;
//
//	//decltype(pf) px;
//	//cout << typeid(px).name() << endl;
//
//	const int x = 1;
//	double y = 2.2;
//
//	decltype(x * y) ret; // ret的类型是double
//	//auto ret = x*y;
//
//	decltype(&x) p;      // p的类型是int*
//	cout << typeid(ret).name() << endl;
//	cout << typeid(p).name() << endl;
//
//	f(NULL);
//	f(nullptr);
//
//	F(x, y);
//
//	return 0;
//}

#include <array>

int main()
{
	// 越界检查更标准严格
	array<int, 10> a1;
	array<int, 20> a2;
	//a1[11];
	//a1.at(11);

	int a3[10];
	a3[11];

	vector<int> v;
	v.resize(10);

	return 0;
}

//int main()
//{
//	double x = 1.1, y = 2.2;
//
//	// 以下几个都是常见的右值
//	10;
//	x + y;
//	fmin(x, y);
//
//	// 以下几个都是对右值的右值引用
//	int&& rr1 = 10;
//	double&& rr2 = x + y;
//	double&& rr3 = fmin(x, y);
//	cout << &rr1 << endl;
//
//	rr1 = 20;
//	cout << &rr1 << endl;
//
//	// 这里编译会报错：error C2106: “=”: 左操作数必须为左值
//	//10 = 1;
//	//x + y = 1;
//	//fmin(x, y) = 1;
//
//	return 0;
//}

// 1、左值引用  -》 左值
// 2、右值引用  -》 右值


// 3、const 左值引用  -》左值 或 右值
// 4、右值引用  -》 std::move(左值) 


//int main()
//{
//	// 左值引用只能引用左值，不能引用右值。
//	int a = 10;
//	int& ra1 = a;   // ra为a的别名
//	// int& ra2 = 10;   // 编译失败，因为10是右值
//
//	const int& ra2 = 10;
//	const int& ra3 = 10 + 20;
//
//	return 0;
//}

//int main()
//{
//	// 右值引用只能右值，不能引用左值。
//	int&& r1 = 10;
//
//	// error C2440: “初始化”: 无法从“int”转换为“int &&”
//	// message : 无法将左值绑定到右值引用
//	int a = 10;
//	//int&& r2 = a;
//
//	// 右值引用可以引用move以后的左值
//	int&& r3 = std::move(a);
//
//	return 0;
//}
//

namespace bit
{
	class string
	{
	public:
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			//cout << "string(char* str)" << endl;

			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		// s1.swap(s2)
		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}

		// 拷贝构造
		string(const string& s)
			:_str(nullptr)
		{
			cout << "string(const string& s) -- 深拷贝" << endl;

			string tmp(s._str);
			swap(tmp);
		}

		// 移动构造
		string(string&& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			cout << "string(string&& s) -- 移动构造" << endl;
			this->swap(s);
		}

		// 移动赋值 
		string& operator=(string&& s)
		{
			cout << "string& operator=(string&& s) -- 移动赋值" << endl;
			this->swap(s);

			return *this;
		}

		// 赋值重载
		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) -- 深拷贝" << endl;
			string tmp(s);
			swap(tmp);

			return *this;
		}	

		~string()
		{
			delete[] _str;
			_str = nullptr;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;

				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}

			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		//string operator+=(char ch)
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		const char* c_str() const
		{
			return _str;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity; // 不包含最后做标识的\0
	};

	bit::string to_string(int value)
	{
		bool flag = true;
		if (value < 0)
		{
			flag = false;
			value = 0 - value;
		}

		bit::string str;
		while (value > 0)
		{
			int x = value % 10;
			value /= 10;

			str += ('0' + x);
		}

		if (flag == false)
		{
			str += '-';
		}

		std::reverse(str.begin(), str.end());
		return str;
	}
}

// 左值引用的使用场景
// 1、做参数 
// 2、做返回值
void func1(bit::string s)
{}

void func2(const bit::string& s)
{}

int main()
{
	Self::string s1("hello world");
	// func1和func2的调用我们可以看到左值引用做参数减少了拷贝，提高效率的使用场景和价值
	//func1(s1);
	func2(s1);
 
	return 0;
}

int main()
{
	bit::string ret1;
	// ....

	ret1 = bit::to_string(1234);

	return 0;
}
