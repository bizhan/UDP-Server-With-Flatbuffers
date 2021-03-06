#ifndef _UTILS_HPP_
#define _UTILS_HPP_

#include <ctime>
#include <string>
#include <vector>
#include <functional>
#include <initializer_list>
extern "C"{
#include <netinet/in.h>
#include <arpa/inet.h>
}

#include <schemas/core.h>

#ifndef RECV_BUFFER_SIZE
#define RECV_BUFFER_SIZE (2 * (1 << 10)) //2KB
#endif

#ifndef RESEND_THRESHOLD_NUM
#define RESEND_THRESHOLD_NUM    3
#endif

#ifndef RESEND_TIMEOUT_US
#define RESEND_TIMEOUT_US    100000 //100ms
#endif

namespace utils{
    
    inline void TrimString(std::string &str, char ch = ' '){
        int i;
        //Front
        for(i = 0; i < str.length(); i++){
            if(str[i] != ch) break;
        }
        if(i > 0) str.erase(0, i);
        
        //Tail
        for(i = str.length() - 1; i >= 0; i--){
            if(str[i] != ch) break;
        }
        if(i + 1 < str.length()) str.erase(i+1);
    }
    
    template <char sep = '/'>
    inline std::string JoinPath(std::initializer_list<std::string> segs){
        if(segs.size() <= 0) return std::string("");
        
        auto it_segs = segs.begin();
        std::string result(*it_segs);
        
        for(++it_segs; it_segs != segs.end(); ++it_segs){
            result.push_back(sep);
            result += *it_segs;
        }
        
        return result;
    }
    
    inline std::string GetCurrentTime(){
        time_t raw_time;
        time(&raw_time);
        auto* time_info = localtime(&raw_time);
        std::string time_str(asctime(time_info));
        TrimString(time_str);
        return time_str;
    }
    
    inline void ToSockAddrInet(struct sockaddr_in& addr, const char* addr_str, int port){
        bzero(&addr, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        inet_pton(AF_INET, addr_str, &addr.sin_addr);
    }
    
    typedef std::function<void(void)> FinalizeCallback;
    //Default: Push to the front
    void AddFinalizeCallback(const FinalizeCallback&);
    void PushBackFinalizeCallback(const FinalizeCallback&);
    void InsertFinalizeCallback(unsigned int, const FinalizeCallback&);
    void DoFinalize();
    
    //Flatbuffers stuff
    void BuildRequest(const std::string&,
                      flatbuffers::FlatBufferBuilder&, flatbuffers::FlatBufferBuilder&);
    inline std::string GetErrorVerbose(const fbs::Status& status){
        switch(status){
            case fbs::Status_OK:
                return "OK";
                
            case fbs::Status_AUTH_ERROR:
                return "Authorization Error";
                
            case fbs::Status_USER_EXIST:
                return "User already exist";
                
            case fbs::Status_REGISTER_INFO_INVALID:
                return "Registaration Error";
                
            case fbs::Status_PAYLOAD_FORMAT_INVALID:
                return "Invalid Payload Format";
                
            case fbs::Status_PERMISSION_DENIED:
                return "Permission Denied";
                
            case fbs::Status_INVALID_REQUEST_ARGUMENT:
                return "Invalid Request Argument";
                
            default:
                return "Unknown Error";
        }
    }
    
    //Account stuff
    namespace account{
        std::string GetNickName(const std::string& username);
    } //namespace account
    
    //UDP stuff
    int udp_connect(/*IPv4*/const char*, int);
    
    typedef std::function<void(char*,ssize_t)> ResponseHandleFunc;
    void ClientSendAndRead(int socket_fd,
                           flatbuffers::FlatBufferBuilder& builder,
                           const ResponseHandleFunc& callback);
    
}; //namespace utils

#endif