
#include "Account.hpp"
#include "Session.hpp"
#include <Utils.hpp>
#include <schemas/account.h>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

static boost::property_tree::ptree AccountProfiles;

namespace handlers{
    
    namespace account {
        
        void loadAccountFile(){
            using namespace boost::property_tree;
            try{
                AccountProfiles.clear();
                read_json(ACCOUNT_FILE_NAME, AccountProfiles);
            }catch(const json_parser_error& e){
                Log::E("Account File Loader") << "Failed loading account file: " << e.message() << std::endl;
            }
        }
        
        const HandleFunc handleRegister = HANDLE_FUNC(){
            //Verify request
            flatbuffers::Verifier verifier(request.payload()->Data(), request.payload()->size());
            if(fbs::account::VerifyRegisterRequestBuffer(verifier)){
                auto* register_req = fbs::account::GetRegisterRequest(request.payload()->Data());
                
                auto username = register_req->username()->str();
                auto password = register_req->password()->str();
                
                if(username.length() <= 0 || password.length() <= 0){
                    SendStatusResponse(fbs::Status_REGISTER_INFO_INVALID, response_writer);
                    return;
                }
                
                using namespace boost::property_tree;
                //Check account exist
                bool exist = true;
                try{
                    AccountProfiles.get_child(GetPath(username));
                }catch(const ptree_bad_path&){
                    exist = false;
                }
                if(exist){
                    SendStatusResponse(fbs::Status_USER_EXIST, response_writer);
                    return;
                }
                
                ptree user_tree;
                user_tree.put(GetPath(PROFILE_PASSWORD_KEY), password)
                            .put(GetPath(PROFILE_NIKNAME_KEY), username);
                
                AccountProfiles.put_child(GetPath(username), user_tree);
                
                {
                    //Send response
                    flatbuffers::FlatBufferBuilder builder;
                    auto resp = fbs::CreateGeneralResponse(builder,
                                                           session::NewSession(builder, username),
                                                           fbs::Status_OK);
                    fbs::FinishGeneralResponseBuffer(builder, resp);
                    
                    response_writer(builder.GetBufferPointer(), builder.GetSize());
                }
            }else{
                SendStatusResponse(fbs::Status_PAYLOAD_FORMAT_INVALID, response_writer);
            }
        };
        
    } //namespace account
    
    void InitAccountHandlers(Router& router){
        
        account::loadAccountFile();
        //Schedule write back task
        utils::AddFinalizeCallback([&]{
            //Write account data back to file
            using namespace boost::property_tree;
            try{
                write_json(ACCOUNT_FILE_NAME, AccountProfiles);
            }catch(const json_parser_error& e){
                Log::E("Account File Loader") << "Failed writing back account file: " << e.message() << std::endl;
            }
        });
        
        router.Path("/register", account::handleRegister);
    }
    
}; //namespace handlers

