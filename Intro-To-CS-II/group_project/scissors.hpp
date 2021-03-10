/****************************************************************************** 
 ** Program Name: scissors.hpp
 ** Author: Kyle Martinez, Chris Rico, Paige Enoch, Stephen Manz, Sweta Khanal
 ** Date: 07/30/2017
 ** Description: Header file for scissors class
 *****************************************************************************/
 #ifndef SCISSORS_HPP
 #define SCISSORS_HPP
 
 #include "tool.hpp"
 
 class Scissors : public Tool
 {
     public:
        Scissors();
        Scissors(double s);
        virtual ~Scissors();
        virtual int fight(Tool *competitor);
 };
 

 
 
 #endif  //SCISSORS H