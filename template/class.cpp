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
 
 /*-------------------------------------------------------*/
 
 testTmp<int, int> hello;
	hello.setTmp(1);
	cout << hello.getTmp() <<endl;
