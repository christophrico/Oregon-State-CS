/****************************************************************************** 
 ** Program Name: tool.cpp
 ** Author: Kyle Martinez, Chris Rico, Paige Enoch, Stephen Manz, Sweta Khanal
 ** Date: 07/30/2017
 ** Description: Implementation file for the tool class.
 *               
 *****************************************************************************/
 
#include "tool.hpp"

/***************************************************************************** 
 ** Description: Constructors. 
 **              Default sets strength to 1.
 **              Non-default allows strenght to be set.
 ****************************************************************************/
Tool::Tool()
{
    strength = 1;
}

Tool::Tool(double s)
{
    strength = s;
}

/***************************************************************************** 
 ** Description: Virtual Destructor. Doesn't need to do anything, just needs
 **              to be virtual.
 ****************************************************************************/
 Tool::~Tool()
 {
 }
 
/***************************************************************************** 
 ** Description: Getters
 ****************************************************************************/ 
double Tool::getStrength()
{
    return strength;
}

char Tool::getType()
{
    return type;
}

/***************************************************************************** 
 ** Description: Setters
 ****************************************************************************/
void Tool::setStrength(double x)
{
    strength = x;
}


 /***************************************************************************** 
 ** Description: Fight function, compares 2 tol objects' strengths
 *               in tool class, is a virtual function that will never be called
 ****************************************************************************/
 int fight(Tool *competitor)
 {
     return 0;
 }