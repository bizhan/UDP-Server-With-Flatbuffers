#include "Context.hpp"

#include <map>

static std::map<context::Screen, context::ScreenHandler> ScreenMap;

namespace context {
    
    std::string CurrentTokenStr("");
    
    int SocketFd = -1;
    
    const char PROMPT_CHAR = '>';
    
    namespace post{
        long MaxPid = -1;
        long CurrentPid = -1;
    } //namespace post
    
    ScreenHandler& GetScreen(Screen scr){
        auto it_screen = ScreenMap.find(scr);
        return (it_screen == ScreenMap.end())? ScreenMap[Screen::ENTRY] : (it_screen->second);
    }
    void AddScreen(Screen scr, const ScreenHandler& handler){
        ScreenMap[scr] = handler;
    }
    
    void InitScreens(){
        AddScreen(Screen::ENTRY, SCREEN_HANDLER(){
            
            PrintDivideLine();
            std::cout << "Welcome!!" << std::endl;
            PrintDivideLine();
            
            std::cout << "[R]egister\t" << "[L]ogin" << std::endl << "[Q]uit" << std::endl;
            std::cout << PROMPT_CHAR;
            
            char input_cmd;
            std::cin >> input_cmd;
            
            switch(std::tolower(input_cmd)){
                case 'l':{
                    return Screen::LOGIN;
                }
                    
                case 'r':{
                    return Screen::REGISTER;
                }
                    
                case 'q':{
                    return Screen::QUIT;
                }
                    
                default:
                    std::cout << "Unrecognized input: " << input_cmd << std::endl;
                    return Screen::STAY;
            }
        });
        
        AddScreen(Screen::MAIN, SCREEN_HANDLER(){
            PrintDivideLine();
            
            std::cout << "[A]dd Post\t" << "[V]iew Posts" << std::endl;
            std::cout << "[L]ogout" << std::endl;
            std::cout << PROMPT_CHAR;
            
            char input_cmd;
            std::cin >> input_cmd;
            
            switch(std::tolower(input_cmd)){
                case 'a':{
                    return Screen::ADD_POST;
                }
                    
                case 'v':{
                    return Screen::VIEW_NEXT_POST;
                }
                
                case 'l':{
                    return Screen::LOGOUT;
                }
                    
                default:{
                    std::cout << "Unrecognized input: " << input_cmd << std::endl;
                    return Screen::STAY;
                }
            }
        });
    }
}