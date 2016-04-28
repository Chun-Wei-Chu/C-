template <typename T, int MAXSIZE>
class Stack{
private:
	T elems[MAXSIZE];
	int numElems;
public:
	 Stack():numElems(0)
	 {
		 
	 };
	 void push(T const& elem)
	 {
		 if(numElems == MAXSIZE){
			throw std::out_of_range("Stack<>::push(): stack is full.");
		 }
		 elems[numElems] = elem;
		 ++numElems;
	 };
	 void pop()
	 {
		 if(numElems <=0){
			throw std::out_of_range("Stacek<>::pop(): empty stack");
		 }
		 --numElems;
	 };
	 T top() const
	 {
		 if(numElems <=0){
			 throw std::out_of_range("Stacek<>::top(): empty stack");
		 }
		 return elems[numElems-1];
	 };
	 bool EmptyClipboard() const{
		return numElems == 0;
	 }
	 bool full(){
		 return numElems == MAXSIZE;
	 }
};


/***********************************************/
Stack<int, 40> int40Stack; //example
