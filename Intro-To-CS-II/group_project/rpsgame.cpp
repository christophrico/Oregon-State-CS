/****************************************************************************** 
 ** Program Name: rpsgame.hpp
 ** Author: Kyle Martinez, Chris Rico, Paige Enoch, Stephen Manz, Sweta Khanal
 ** Date: 07/30/2017
 ** Description: Header file for rpsgame class.
*****************************************************************************/

#include "rpsgame.hpp"

//constructor
RPSGame::RPSGame(){
    human = nullptr;
    computer = nullptr;
    
    humanWins = 0;
    computerWins = 0;
    ties = 0;
}


/***************************************************************************** 
 ** Description: Compares the two opponent Tools and increments the score
 **              depending on who wins the round.
 **              NOTE: intended to be used after tools selected
 ** Parameters: human = pointer to human's selected tool.
 **             computer = pointer to computer's selected tool.
 ** Return value: Returns char signifying winner of the round
 ****************************************************************************/
char RPSGame::compareTools(Tool* human, Tool* computer){
        
        //if the human wins
        if(human -> fight(computer) == 1) {
            humanWins++;
            return 'h';
        }
        
        //if the computer wins
        else if (human -> fight(computer) == -1) {
            computerWins++;
            return 'c';
        }
        
        //if there's a tie
        else {
            ties++;
            return 't';
        }
}


/***************************************************************************** 
 ** Description: Chooses the Tool (Rock/Paper/Scissors) which the computer
 **              will use.
 ** Parameters: custStrength = strength to construct Tools with. Default = 1.
 ** Return value: Returns Tool* to newly allocated Rock/Paper/Scissors object
 ****************************************************************************/
Tool* RPSGame::chooseCompTool(double rS, double pS, double sS) {
    
    // generate random integer between 1 and 3
    // to choose the computer's tool
    int computerChoice = randIntRange(1,3);
    
    Tool* compChoice = nullptr;
    
    // one = rock
	if(computerChoice == 1) {
		compChoice = new Rock(rS);
		cout << "Computer chose rock" << endl;
	}
	// two = paper
	else if(computerChoice == 2) {
		compChoice = new Paper(pS);
		cout << "Computer chose paper" << endl;
	}
	// three = scissors
	else{
		compChoice = new Scissors(sS);
		cout << "Computer chose scissors" << endl;
	}
	
	return compChoice;
}


/***************************************************************************** 
 ** Description: Play the Rock/Paper/Scissors game until the user quits
 ** Parameters: None
 ** Return value: Void
 ****************************************************************************/
void RPSGame::playGame() {
    double rockStrength = 1;
    double scissorsStrength = 1;
    double paperStrength = 1;
    char chooseToolStrengths, chooseTool, roundWin;
    
    cout << "Welcome to rock paper scissors, woud you like to choose tool strengths?\n"
    << "Enter 'y' or 'n': ";
    
    //validate that user's input is y or n
    chooseToolStrengths = isChar2('y','n');
    
    if (chooseToolStrengths == 'y')
    {
        cout << "Enter the tool strength for rock: ";
        rockStrength = doubleRange(1);
        cout << "Enter the tool strength for scissors: ";
        scissorsStrength = doubleRange(1);
        cout << "Enter the tool strength for paper: ";
        paperStrength = doubleRange(1);
    }
    
    
    //get the tool the user wants, and play the game!
    do 
    {
        cout << "Choose what you'd like to play (r-rock, p-paper, s-scissor, e-exit ): ";
        
        //validate that user's input is r, p, s, or e
        chooseTool = isChar4('r','p','s','e');
        
        
        //as long as user did not choose to exit, continue playing
        if (chooseTool != 'e')
        {
            //assign tool depending on user choice
            switch(chooseTool)
            {
                case 'r': human = new Rock(rockStrength);
                    break;
                case 'p': human = new Paper(paperStrength);
                    break;
                case 's': human = new Scissors(scissorsStrength);
                    break;
            }
            
            //get the computer's tool
            computer = RPSGame::chooseCompTool(rockStrength, paperStrength, scissorsStrength);
            
            
            //face off! then print the winner of this round
            roundWin = RPSGame::compareTools(human, computer);
            if (roundWin == 'h')
            {
                cout << "You win!" << endl << endl;
            }
            else if (roundWin == 'c')
            {
                cout << "Computer wins" << endl << endl;
            }
            else if (roundWin == 't')
            {
                cout << "It's a tie" << endl << endl;
            }
            
            //print running score
            cout << "Human wins: " << humanWins << endl;
            cout << "Computer wins: " << computerWins << endl;
            cout << "Ties: " << ties << endl << endl;
            
            // need to delete current instance of human and computer
            // prevents memory leak when consecutive rounds are played
            delete human;
            delete computer;
            human = nullptr;
            computer = nullptr;
        }
        
    } while(chooseTool != 'e');
    
    cout << endl << "Thanks for playing!" << endl;
    
    return;
}