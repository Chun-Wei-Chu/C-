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
class testTmp
{
public:

	template<typename A, typename B> 
	void test(A a, B b)
	{
		cout << a-10 << b << endl;
	}
};

/*----------------------------------------------*/

testTmp hello;
hello.test<int, char>(1, 'f');
