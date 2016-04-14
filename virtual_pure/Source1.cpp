#include <iostream> 

using namespace std;

class AbstractCircle {
public:
	void radius(double radius) {
		_radius = radius;
	}
	double radius() {
		return _radius;
	}
	// 宣告虛擬函式
	virtual void render() = 0;

protected:
	double _radius;
};

class ConcreteCircle : public AbstractCircle  {
public:
	void render() {
		cout << "畫一個半徑 "
			<< _radius
			<< " 的實心圓"
			<< endl;
	}
};

class HollowCircle : public AbstractCircle  {
public:
	void render() {
		cout << "畫一個半徑 "
			<< _radius
			<< " 的空心圓"
			<< endl;
	}
};

void render(AbstractCircle &circle) {
	circle.render();
}

int main() {
	ConcreteCircle concrete;
	concrete.radius(10.0);
	render(concrete);

	HollowCircle hollow;
	hollow.radius(20.0);
	render(hollow);

	return 0;
}