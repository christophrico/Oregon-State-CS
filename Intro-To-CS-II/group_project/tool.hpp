/****************************************************************************** 
 ** Program Name: tool.hpp
 ** Author: Kyle Martinez, Chris Rico, Paige Enoch, Stephen Manz, Sweta Khanal
 ** Date: 07/30/2017
 ** Description: This file contains the definition of the Tool class
 *****************************************************************************/
 
 #ifndef TOOL_HPP
 #define TOOL_HPP
 
 class Tool
 {
     protected:
        double strength;
        char type;
        
    public:
        // constructors
        Tool();
        Tool(double);
        // virtual destructor
        virtual ~Tool();
        // getters/setters
        void setStrength(double);
        double getStrength();
        char getType();
        
        //pure virtual fight class; must be implemented in derived class
        virtual int fight(Tool*) = 0;
        
 };
 
 #endif // TOOL H