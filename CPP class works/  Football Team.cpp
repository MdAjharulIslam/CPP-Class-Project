#include<iostream>
#include<string.h>
using namespace std;
class CSEFT{
private:
    string name;
    int goalgiven=0;

    int goalconsume=0;

    int matchesPlayed = 0;
    int matchesWon = 0;
    int matchesLost = 0;
    int matchesDrawn = 0;
public:

    //for set name

    void setname(string a){
    name=a;
    }
    string getname(){
        return name;
    }
    //for set given goal

    void setgoalgiven(int b){
     if(b>=0){
        goalgiven=b;
     }
      else{
       cout << "Goals given cannot be negative!" << endl;
      }
    }

    int getgoalgiven(){
    return goalgiven;
    }

    //for goal consume

    void setgoalconsume(int c){
    if(c>=0){
        goalconsume=c;
    }
    else {
        cout << "Goals consumed cannot be negative!" << endl;
    }
    }

    int getgoalconsume(){
    return goalconsume;
    }


     void incrementMatchesPlayed() {
        matchesPlayed++;
    }

    void incrementMatchesWon() {
        matchesWon++;
    }

    void incrementMatchesLost() {
        matchesLost++;
    }
    void incrementMatchesDrawn() {
        matchesDrawn++;
    }
    int getMatchesPlayed() const {
        return matchesPlayed;
    }

    int getMatchesWon() const {
        return matchesWon;
    }

    int getMatchesLost() const {
        return matchesLost;
    }
    int getMatchesDrawn() const {
        return matchesDrawn;
    }
};
// function for the winner

string forwinner(CSEFT &t1, CSEFT &t2) {

    int t1netgoals = t1.getgoalgiven() - t1.getgoalconsume();
    int t2netgoals = t2.getgoalgiven() - t2.getgoalconsume();


    if (t1netgoals > t2netgoals) {

        t1.incrementMatchesWon();
        t2.incrementMatchesLost();

     return "Congratulations team "+ t1.getname()+" wins";

    } else if (t1netgoals < t2netgoals) {

        t2.incrementMatchesWon();
        t1.incrementMatchesLost();

        return "Congratulations team "+ t2.getname() + "  wins";

    } else {

        t1.incrementMatchesDrawn();
        t2.incrementMatchesDrawn();

        return "It's a draw!";
    }
    return 0;
}

//function for total goal

int totalgoalsgiven(CSEFT t1, CSEFT t2) {

    return t1.getgoalgiven() + t2.getgoalgiven();
}

// Function to  the winner and the goal difference

string WinnerWithGoalDifference(CSEFT t1, CSEFT t2) {

    int t1NetGoals = t1.getgoalgiven();

    int t2NetGoals = t2.getgoalgiven();



    int goalDifference = abs(t1NetGoals - t2NetGoals);



    if (t1NetGoals > t2NetGoals) {

        return "\t" +t1.getname() + " wins by " + to_string(goalDifference) + " goal(s)!";

    } else if (t1NetGoals < t2NetGoals) {

        return "\t"+ t2.getname() + " wins by " + to_string(goalDifference) + " goal(s)!";

    }


     else if (t1NetGoals==t2NetGoals){

        return "Its a Draw!";
    }

    else{
        return "Invalid Goals!";
    }
}



int main(){
CSEFT t1, t2;
    string name;
    int goalgiven, goalconsume;



// Input for Team 1
    cout << "Enter the name of Team 1: ";
    cin >> name;
    t1.setname(name);

    cout << "Enter the goals given by " << name << ": ";
    cin >> goalgiven;
    t1.setgoalgiven(goalgiven);

    cout << "Enter the goals consumed by " << name << ": ";
    cin >> goalconsume;
    t1.setgoalconsume(goalconsume);

    // Input for Team 2
    cout << "Enter the name of Team 2: ";
    cin >> name;
    t2.setname(name);

    cout << "Enter the goals given by " << name << ": ";
    cin >> goalgiven;
    t2.setgoalgiven(goalgiven);

    cout << "Enter the goals consumed by " << name << ": ";
    cin >> goalconsume;
    t2.setgoalconsume(goalconsume);

// Track matches played
    t1.incrementMatchesPlayed();
    t2.incrementMatchesPlayed();

//for winner
cout<<endl;
 cout << "\t The Winner : "<<forwinner(t1, t2) << endl;

 //for the winner and the goal difference

 cout<<endl;
cout << WinnerWithGoalDifference(t1, t2) << endl;



 //for total goal
cout << "\t Total goals given in the match: " << totalgoalsgiven(t1, t2) << endl;


 // Display team statistics

    cout << "\n\t Team Statistics:" << endl;
    cout << t1.getname() << ": Played " << t1.getMatchesPlayed() << ", Won " << t1.getMatchesWon() << ", Lost "
     << t1.getMatchesLost() <<",Drawn " <<t1.getMatchesDrawn()<<endl;
    cout << t2.getname() << ": Played " << t2.getMatchesPlayed() << ", Won " << t2.getMatchesWon() << ", Lost "
    << t2.getMatchesLost() <<",Drawn " <<t2.getMatchesDrawn()<< endl;

return 0;

}
