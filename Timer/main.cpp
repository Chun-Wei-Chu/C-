class Timer
 {
 	thread th;
 	bool running;
 
 public:
 	typedef std::chrono::milliseconds Interval;

 	template<class T> void 
	start(const Interval &interval,
 	const std::function<void(T)>  &timeout, T data)
 	{
 		running = true;
 		th = thread([=]()
 		{
 			while (running) {
 				timeout(data);
 				if(!running)
 					break;
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
Timerfunction.start < someType > (chrono::milliseconds(milliseconde), []( someType dataClass){
  /*
  	do something
  	dataClass就是傳入的data
  */
}, dataClass);


