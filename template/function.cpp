template <class T>
T swaps(T& a1,T& a2){
	T tmp=a1;
	a1=a2;
	a2=tmp;
	return tmp;
}

int main()
{
	int a=10;
	int b=20;
	cout<<'('<<a<<','<<b<<')'<<endl;
	swaps(a,b);
	cout<<'('<<a<<','<<b<<')'<<endl;
	system("pause");
	return 0;
}
