// concept_test.cpp : 定義主控台應用程式的進入點。
//
#include "stdafx.h"

#define WIN32_LEAN_AND_MEAN
#pragma warning(disable:4996)
#include "stdafx.h"
#include <stdio.h>
#include <Winsock2.h>
#include <Windows.h>
#include <string>

#pragma comment(lib, "ws2_32.lib")

#define HELO "HELO\r\n"
#define DATA "DATA\r\n"
#define QUIT "QUIT\r\n"

namespace mail {
    class SendMail {
    private:
        int sock;
        char buf[BUFSIZ];
        void send_socket(char *s)
        {
            send(sock, s, strlen(s), 0);
            //fprintf(stderr, s); 
        }
        void read_socket()
        {
            int len = recv(sock, buf, BUFSIZ, 0);
            //fprintf(stderr, ((std::string)buf).substr(0, len).c_str()); 
        }
    public:
        char* HostIp;
        unsigned short HostPort;
        char* To;
        char* From;
        char* Subject;
        char* Message;
        SendMail() {
            HostPort = 25;
        };
        ~SendMail() { };
        void Send() {
            struct sockaddr_in hostAddr; 
            WSADATA wsaData;
            if (WSAStartup(MAKEWORD(2, 0), &wsaData) != 0) {
                fprintf(stderr, "SendMail: WSAStartup() failed"); 
                return;
            }
            if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
                fprintf(stderr, "SendMail: socket() failed"); 
                return;
            }
            memset(&hostAddr, 0, sizeof(hostAddr)); 
            hostAddr.sin_family = AF_INET; 
            struct hostent *he;
            he = gethostbyname(HostIp);
            memcpy(&hostAddr.sin_addr.s_addr, he->h_addr_list[0], he->h_length); 
            hostAddr.sin_port = htons(HostPort); 
            if (connect(sock, (struct sockaddr *) &hostAddr, sizeof(hostAddr)) < 0) {
                fprintf(stderr, "SendMail: connect() failed"); 
                return;
            }
            read_socket();
            send_socket(HELO);
            read_socket();
            send_socket("MAIL FROM: "); 
            send_socket(From);
            send_socket("\r\n");
            read_socket();
            send_socket("VRFY ");
            send_socket(From);
            send_socket("\r\n");
            read_socket();
            send_socket("RCPT TO: ");
            send_socket(To);
            send_socket("\r\n");
            read_socket();
            send_socket(DATA);
            send_socket("Subject: ");
            send_socket(Subject);
            send_socket("\r\n");
            read_socket();
            send_socket(Message);
            send_socket("\r\n");
            send_socket(".\r\n");
            read_socket(); 
            send_socket(QUIT);
            read_socket();
            closesocket(sock); 
            WSACleanup(); 
        };
    };
}

int _tmain(int argc, _TCHAR* argv[])
{
    mail::SendMail* sendmail = new mail::SendMail();
    sendmail->HostIp = "smtp.moneydj.com";
    sendmail->From = "maxchu@moneydj.com";
    sendmail->To = "maxchu@moneydj.com";
    sendmail->Subject = "Test!";
    sendmail->Message = "Content:\nTest 123...";
    sendmail->Send();

    
    system("pause");

    return 0;
}
