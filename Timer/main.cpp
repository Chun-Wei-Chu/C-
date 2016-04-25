class Timer
{
	thread th;
	bool running;

public:
	typedef std::chrono::milliseconds Interval;
	typedef std::function<void(void /*or other var ex: int*/)> Timeout;

	void start(const Interval &interval,
		const Timeout &timeout)
	{
		running = true;

		th = thread([=]()
		{
			while (running) {
				timeout();
				this_thread::sleep_for(interval);
			}
		});
	}

	void stop()
	{
		running = false;
		if(th.joinable())
			th.join();
	}
};

/*********************** use **********************/
Timer Timerfunction;
TimerfunctionCase2.start(chrono::milliseconds(milliseconde), [](void /*or other var ex: int a*/){
	/*希望他做什麼*/
});


