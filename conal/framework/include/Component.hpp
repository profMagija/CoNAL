#pragma once 

#include "Message.hpp"
#include <thread>
#include "Logger.hpp"

namespace conal {
    namespace framework {
        class ComponentManager;
        
        /*! Represents specific component in CoNAL environment.
        */
        class Component {

                friend class ComponentManager;

                std::thread messageReadingThread;
                std::string name;
            
            protected:
                std::shared_ptr<Logger> logger;
                void sendMessage(std::string to_component, Performative performative, std::string body);

            public: 
                // needs to be implemented by component. 
                // This method is called when component is started.
                virtual void start() =0;

                // needs to be implemented by component. 
                // This method is called when component is stopped.
                virtual void stop() =0;

                // needs to be implemented by component. This method is called 
                // when component gets internal message from other 
                // component or from user through environment.
                virtual void handleMessage(Message msg) =0;

        };
    }
}