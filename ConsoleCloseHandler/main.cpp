#include<windows.h>
#include<thread.h>

 HANDLE hExit = NULL;
 BOOL HandlerRounte(DWORD dwCtrlType)
 {
 	BOOL Result = FALSE;
 	cout << "start now..."<<endl;
 	switch(dwCtrlType)
 	{
 	case CTRL_C_EVENT:
 	case CTRL_BREAK_EVENT:
 	case CTRL_CLOSE_EVENT:
 		Result = SetEvent(hExit);
 		cout << "sucess and return not 0 value"<<endl;
 		return TRUE;
 	default:
 		return FALSE;
 	}
 	return FALSE;
 }
 
 ---------------------------------------------
 void main()
 {
	thread CloseHandler= thread([=](){
		BOOL Result = FALSE;
		Result=SetConsoleCtrlHandler((PHANDLER_ROUTINE)HandlerRounte, TRUE);
		if(Result)
		{
			hExit = CreateEvent(NULL, FALSE,  FALSE, NULL);
			WaitForSingleObject(hExit, INFINITE);
			return;
		}
	});
	
	SetEvent(hExit);
	CloseHandler.join();
 }
