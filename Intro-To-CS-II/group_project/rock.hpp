/****************************************************************************** 
 ** Program Name: rock.hpp
 ** Author: Kyle Martinez, Chris Rico, Paige Enoch, Stephen Manz, Sweta Khanal
 ** Date: 07/30/2017
 ** Description: Header file for the rock class.
 *              
 *****************************************************************************/
 
 #ifndef ROCK_HPP
 #define ROCK_HPP
 
 #include "tool.hpp"
 
 class Rock : public Tool
 {
     public:
        Rock();
        Rock(double s);
        virtual ~Rock();
        virtual int fight(Tool *competitor);
 };
 

 
 
 #endif  //ROCK 