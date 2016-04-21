#include <iostream>
#include <memory>

using namespace std;

void testPtr(BYTE* tmp)
{
	cout << &tmp[20] << endl;
}

int main()
{
  shared_ptr<BYTE> tmp (new BYTE[100]);
  memcpy(&(tmp.get())[0], "hello world\n",11);
  memcpy(&(tmp.get())[20], "hello world\n",11);
  testPtr(tmp.get());

  return 0;
}
