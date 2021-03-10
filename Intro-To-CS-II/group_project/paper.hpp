/****************************************************************************** 
 ** Program Name: paper.hpp
 ** Author: Kyle Martinez, Chris Rico, Paige Enoch, Stephen Manz, Sweta Khanal
 ** Date: 07/30/2017
 ** Description: Header file for paper class
 *****************************************************************************/
 #ifndef PAPER_HPP
 #define PAPER_HPP
 
 #include "tool.hpp"
 
 class Paper : public Tool
 {
     public:
        Paper();
        Paper(double s);
        virtual ~Paper();
        virtual int fight(Tool *competitor);
 };
 
 
 #endif // PAPER H