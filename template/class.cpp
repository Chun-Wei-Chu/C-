 template <class T, class V> //這一行是重點
 class testTmp
 {
 public:
	 T tmp;
	 void setTmp(T data)
	 {
		 tmp = data;
	 }

	 T getTmp()
	 {
		 return tmp;
	 }
 };
 
 /*---------------------------------------------*/
 
 testTmp<int, int> hello;
	hello.setTmp(1);
	cout << hello.getTmp() <<endl;

/***********************************************************************/
template <class T, class V>
class testTmp
{
public:
	template<class A, class B> 
	void test(A a, B b)
	{
		cout << b << endl;
	}
};

/*----------------------------------------------*/

testTmp<char, char> hello;
hello.test<int, int>(1, 2);
