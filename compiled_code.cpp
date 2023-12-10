#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<algorithm>

using namespace std;
// This function displays the Instruction when the game starts
void displayInstructions()
{
    cout << setw(60) << "\x1b[33m--------------------------------- WELCOME !--------------------------------------\x1b[0m" << endl;
    cout << setw(60) << "\x1b[32m________________________________________________________________________________ \x1b[0m" << endl;
    cout << setw(60) << "\x1b[32m|                                                                              | \x1b[0m" << endl;
    cout << setw(60) << "\x1b[32m|---------------------------This is a Text based RPG---------------------------| \x1b[0m" << endl;
    cout << setw(60) << "\x1b[32m|               _____   _______              _____   _______                   | \x1b[0m" << endl;
    cout << setw(60) << "\x1b[32m|              /  ___| |__   __|    /\\      |  __ \\ |__   __|                  | \x1b[0m" << endl;
    cout << setw(60) << "\x1b[32m|              | |___     | |      /  \\     | |__) |   | |                     | \x1b[0m" << endl;
    cout << setw(60) << "\x1b[32m|              \\____  \\   | |     /    \\    |  _  /    | |                     | \x1b[0m" << endl;
    cout << setw(60) << "\x1b[32m|                ___| |   | |    / ____ \\   | | \\ \\    | |                     | \x1b[0m " << endl;
    cout << setw(60) << "\x1b[32m|               |_____/   |_|   /_/    \\_\\  |_|  \\_\\   |_|                     | \x1b[0m" << endl;
    cout << setw(60) << "\x1b[32m|______________________________________________________________________________| \x1b[0m" << endl
         << endl;
    cout << setw(60) << "\x1b[33m________________________________________________________________________________\x1b[0m" << endl
         << endl;
    cout << setw(60) << "\x1b[33m              Welcome to The DreamScape Voyage                       \x1b[0m " << endl;
    cout << setw(60) << "\n\n  \x1b[33m   Get ready to delve into the Word of dreams where reality is just a figment of imagination\x1b[0m" << endl;
    cout << setw(60) << "\n \x1b[33m I'm sure you are as excited as I am, so let's get started.\x1b[0m" << endl
         << endl;
   // cout << setw(60) << "\x1b[33m   Please Enter your good name:";
   /* string name;
    getline(cin, name);
    system("cls");
    cout << setw(20) << ", Here are the mechanics of the game:\x1b[0m" << endl;*/
    cout << setw(20) << "\x1b[33m\n You just woke up in your dream and your guide \"Morpheo\" told you that your dreamscape "
     << "is in peril, with mysterious darkness consuming it.\n MANAGMA, the evil ruler of the DreamScape, has fragmented the space."
     << "\n The only way for you to restore peace is by finding means to reach MANAGMA and defeat him in the boss battle."
     << "\n BUT here's the catch, you will have to embark on a perilous journey filled with adventures and thrills."
     << "\n WISH YOU THE BEST OF LUCK!!.\x1b[0m" << endl;

         cout<< endl;
    cout << setw(20) << "\x1b[37m***************************************************************************\x1b[0m" << endl;

    cout << setw(20) << "\x1b[37m***************************************************************************" << endl
         << endl;
}

void dialogue0()
{
    cout<<"You wake up in a dark forest. Trees surround you from all sides. you see a small path ahead of you. You follow the path and see a sword in front of you.\n[1) Pick up the sword 2) move ahead without the sword]";
}
void choice1a()
{
    cout<<"+12 attack\n";
    cout<<"You pick up the sword and move forward. You see a cave in front of you. You enter the cave and see a bear, and he looks hungry. You prepare yourself and put your sword up.\n";
}
void choice1b()
{
    cout<<"You move forward without the sword. You see a cave in front of you. You enter the cave and see a bear. The bear looks hungry. Bad luck for you. Looks like you should have picked up the sword the game throwed at you in the beginning. The bear attacks you. You are dead before the battle could even begin. \n";
}
void end()
{
    cout<<"===========================Game Over=================================================================================================";
}
void line()
{
    cout<<setw(60)<<"--------------------------------------------------------------------------------"<<endl;
}

int attack(int attack1, int z)        // generates random attack value
{
    int y; 
    srand(time(0));
    y = rand() % 11 + (attack1 - z);
    return y;

}
int defense(int enemy_attack)
{
    int y = attack(enemy_attack, 0);
    if(y%2 == 0)
    {
        return 0;
    }
    else if (y%2 > 0)
    {
        return y;
    }
}
int fight(string player_name, string enemy_name, int player_health, int enemy_health, int player_attack, int enemy_attack)
{  
    cout<<player_name<<"'s health: "<<player_health<<endl;
    cout<<enemy_name<<" health: "<<enemy_health<<endl;
    while(player_health>0 && enemy_health>0)
        {
            int choice;
            cout<<"[1)attack 2) defend]\n";
            cin>>choice;
            if(choice == 1)                                                           // attack
                {   int x,y;
                    x = attack(player_attack, 5);
                    y = attack(enemy_attack, 6);

                    cout<<"You attacked the "<<enemy_name;
                    enemy_health = enemy_health - x;
                    cout<< "\n" <<player_name<<" dealt "<<x<<" damage to "<<enemy_name<<endl;
                    
                    if(enemy_health>0 && player_health>0)
                    {
                        player_health = player_health - y ;
                        cout<<enemy_name<<"'s health: "<< enemy_health<<endl;
                        cout<<enemy_name<<" hit you for "<<y<<" damage"<<endl;
                        if(player_health>0)
                        {
                            cout<<player_name<<"'s health: "<<player_health<<endl;
                        }
                        else
                        {
                            cout<<"You lost"<<endl;
                            return 0;
                        }
                    }
                    else if(enemy_health<=0 && player_health>0)
                    {
                        cout<<player_name<<" killed the "<<enemy_name<<endl;
                        return 1;

                    }
                    else if(enemy_health>0 && player_health<=0)
                    {
                        cout<<"YOU LOST"<<endl;
                        return 0;
                    }                   
                } 
            else if (choice == 2)                                                      // defense
                {
                    int def;
                    def = defense(enemy_attack);
                    if(def == 0)                                                    //successful defense
                    {
                        int dam = attack(player_attack, 0); 
                        dam = dam / 2;
                        cout<<player_name<<" defended successfully\n";
                        cout<<enemy_name<<" took "<< (dam/2) <<" damage\n";                       
                        cout<<player_name<<"'s health: "<<player_health<<endl;
                        enemy_health = enemy_health -  dam;
                        cout<<enemy_name<<"'s health: "<<enemy_health<<endl;
                    }
                    else if(def > 0)                                               // unsuccessful defense
                    {
                        player_health = player_health - (def / 2);
                        cout<<player_name<<" tried to defend unsuccessfully\n";
                        cout<<enemy_name<<" hit "<<player_name<<" for "<<(def / 2)<<" damage\n";
                        if(player_health>0)
                        {cout<<player_name<<"'s health: "<<player_health<<endl;}
                        else {cout<<"You lost."; return 0;}
                        cout<<enemy_name<<"'s health: "<<enemy_health<<endl;  
                    }                
                }
        }  
    if (player_health <= 0)                              // returns 0 or 1 depending on player health
    {
        return 0;
    }
    else if (player_health>0)
    {
        return 1; 
    }
    
}
int bossfight(string player_name, string enemy_name, int player_health, int enemy_health, int player_attack, int enemy_attack, int special)
{  
    cout<<player_name<<"'s health: "<<player_health<<endl;
    cout<<enemy_name<<" health: "<<enemy_health<<endl;
    while(player_health>0 && enemy_health>0)
        {
            
            int choice;
            cout<<"[1)attack 2) defend 3) special power("<<special<<")]\n";
            cin>>choice;
            if(choice == 1)                                                           // attack
                {   int x,y;
                    x = attack(player_attack, 5);
                    y = attack(enemy_attack, 6);

                    cout<<"You attacked the "<<enemy_name;
                    enemy_health = enemy_health - x;
                    cout<< "\n" <<player_name<<" dealt "<<x<<" damage to "<<enemy_name<<endl;
                    
                    if(enemy_health>0 && player_health>0)
                    {
                        player_health = player_health - y ;
                        cout<<enemy_name<<"'s health: "<< enemy_health<<endl;
                        cout<<enemy_name<<" hit you for "<<y<<" damage"<<endl;
                        if(player_health>0)
                        {
                            cout<<player_name<<"'s health: "<<player_health<<endl;
                        }
                        else
                        {
                            cout<<"You lost"<<endl;
                            return 0;
                        }
                    }
                    else if(enemy_health<=0 && player_health>0)
                    {
                        cout<<player_name<<" killed the "<<enemy_name<<endl;
                        return 1;

                    }
                    else if(enemy_health>0 && player_health<=0)
                    {
                        cout<<"YOU LOST"<<endl;
                        return 0;
                    }                   
                } 
            else if (choice == 2)                                                      // defense
                {
                    int def;
                    def = defense(enemy_attack);
                    if(def == 0)                                                    //successful defense
                    {
                        int dam = attack(player_attack, 0); 
                        dam = dam / 2;
                        cout<<player_name<<" defended successfully\n";
                        cout<<enemy_name<<" took "<< (dam/2) <<" damage\n";                       
                        cout<<player_name<<"'s health: "<<player_health<<endl;
                        enemy_health = enemy_health -  dam;
                        cout<<enemy_name<<"'s health: "<<enemy_health<<endl;
                    }
                    else if(def > 0)                                               // unsuccessful defense
                    {
                        player_health = player_health - (def / 2);
                        cout<<player_name<<" tried to defend unsuccessfully\n";
                        cout<<enemy_name<<" hit "<<player_name<<" for "<<(def / 2)<<" damage\n";
                        if(player_health>0)
                        {cout<<player_name<<"'s health: "<<player_health<<endl;}
                        else {cout<<"You lost."; return 0;}
                        cout<<enemy_name<<"'s health: "<<enemy_health<<endl;  
                        
                    }                
                }
                else if(choice==3)
                {
                    if(special !=0)
                    {
                    int x = player_health*0.10;
                    player_health=x+player_health;
                    cout<<"You used special power."<<endl;
                    cout<<player_name<<"'s health: "<<player_health<<endl;
                    x = attack(player_attack,7);
                    enemy_health = enemy_health - x;
                    cout<<"You dealt "<<x<<" damage to"<<enemy_name<<endl;
                    cout<<enemy_name<<"'s health: "<<enemy_health<<endl;
                    special --;
                    }
                    else{cout<<"YOU HAVE NO SPECIAL POWERS REMAINING"<<endl;}
                }
        }  
    if (player_health <= 0)                              // returns 0 or 1 depending on player health
    {
        return 0;
    }
    else if (player_health>0)
    {
        return 1; 
    }
    
}
bool quizFileRead(string fileName, vector<string> &vecOfStrs) // to store the contents of non-empty lines of .txt files in a string 'vecOfStrs'
{
    ifstream in(fileName.c_str());
    // Checks if the file can be opened
    if (!in) // if not able to open; display an error message using 'cerr' and return false
    {
        cerr << "Cannot open the File : " << fileName << endl;
        return false;
    }
    string str;
    // Read the next line from File untill it reaches the end.
    while (getline(in, str))
    {
        // Fetch the contents of the non-empty (length>0) lines and store it in vector
        if (str.size() > 0)
            vecOfStrs.push_back(str);
    }
    // once data is fetched, close the file
    in.close();
    return true;
}

void quizDisplayQuestionAndOptions(string options, string questions)
{
    cout << setw(10) << questions << endl;
    cout << setw(10) << options << endl;
}

void quizDisplayOnEveryIteration()
{
    cout << setw(10) << "\n \x1b[36;43m Do you want to continue playing the game? (yes/no)\x1b[0m" << endl;
}

void quizDisplayGameOverMessage(int Xp)
{
    cout << setw(10) << "Your current Xp is: " << Xp << endl;
}

void quizMoripheosHelp(string moripheosHelpArr[], int &moripheosHelpChances)
{
    if (moripheosHelpChances > 0)
    {
        srand(time(0));
        int random_guess = rand() % 3 + 1;
        cout << setw(20) << "\x1b[33m  \n  So you have chosen to ask Moripheo for the answer. \n\n \x1b[31mBUT BEWARE!!!\n Moripheo is your dream guide he may also be as clueless as you.\x1b[0m" << endl;
        cout << setw(20) << "\x1b[32m  \n Anyways, Moripheo thinks that " << moripheosHelpArr[random_guess] << " is the correct answer go ahead test your luck. \x1b[0m" << endl;
        cout << setw(20) << " \x1b[33m \nWith this, you have used one of the Moripheos help \x1b[0m" << endl;
        moripheosHelpChances--;
    }
    else
    {
        cout << setw(5) << "\n\n \x1b[33mSorry, but you have already used all help chances\x1b[0m";
        cout << setw(5) << " \n\x1b[33m  Try to answer the question on your own now \x1b[0m" << endl;
    }
}

bool quizAnswerVerification(string usersAnswer, string correctAnswer)
{
    if (usersAnswer == correctAnswer)
        return true;
    else
        return false;
}

void bonusRound(string bonusQuestion, string bonusOptions)
{
    cout << setw(10) << "\n\x1b[44m -------------------- BONUS ROUND --------------------\x1b[0m" << endl;
    cout << setw(10) << "\x1b[33m\n Wow! You maintained a streak of 4 correct answers \n You deserve an oppurtunity to increase your Xp by \x1b[32m150 points\n\n \x1b[0m";
    cout << setw(10) << bonusQuestion << endl;
    cout << setw(10) << bonusOptions << endl;
}

void quizAccomplishmentMsg(int Xp)
{
    cout << setw(5) << "\x1b[33m   Congratulations! You accomplished this round\x1b[33m Your total Xp is " << Xp << "  \x1b[0m" << endl;
}

void quizInstructions()
{
    cout << setw(60) << "\n\x1b[36;43m Welldone You defeated the bear; it was one of the monsters of MANAGMA\x1b[0m" << endl;
    cout << setw(60) << "\x1b[36;43m Now I Welcome You to your next challenge: Quiz Trivia \x1b[0m" << endl;
    cout << setw(20) << "\n\x1b[33m Here are the rules for this game:\x1b[0m" << endl;
    cout << setw(20) << "\x1b[33m 1)you will be asked a total of 5 questions\x1b[0m" << endl;
    cout << setw(60) << "\x1b[33m 2)For each correct answer you will be rewarded 20 Xp points\x1b[0m" << endl;
    cout << setw(60) << "\x1b[33m 1)For every wrong answer there will a penealty of -5 in health\x1b[0m" << endl;
    cout << setw(60) << "\x1b[33m 1)you can use a lifeline to ask Moripheo but you can use it only 2 times\x1b[0m" << endl;
}
void quiz()
{
    quizInstructions();
    vector<string> vecOfQuestions;
    // fetch questions
    bool result = quizFileRead("questions1.txt", vecOfQuestions);

    vector<string> vecOfOptions;
    // Fetch options
    result = quizFileRead("options1.txt", vecOfOptions);

    vector<string> vecOfAnswers;
    quizFileRead("answers1.txt", vecOfAnswers);

    bool gameloop = true;
    bool answerVerification = false;

    string continueOpt = "";
    string moripheosHelp = "";

    int Xp = 0;
    int lives = 2;
    int moripheosHelpChances = 2;
    int iteration = 0;
    int streak = 0;

    char endingOpt;

    int XpArr[6] = {10, 20, 35, 55, 80, 110};
    string moripheosHelpArr[4] = {"a", "b", "c", "d"};

    while (gameloop)
    {
        quizDisplayOnEveryIteration();
        cin >> setw(10) >> continueOpt;
        system("cls");
        if (continueOpt == "no")
        {
            quizDisplayGameOverMessage(Xp);
            break;
        }
        quizDisplayQuestionAndOptions(vecOfOptions[iteration], vecOfQuestions[iteration]);

        // Ask if you want to take Lifeline
        cout << setw(10) << "\x1b[32m\n Do you want to use Moripheo's help? \n\n \x1b[0m";
        cout << "\x1b[33mpress 1 to use help \n press 2 to continue without help. \n\n \x1b[0m" << endl;
        cin >> setw(10) >> moripheosHelp;
        if (moripheosHelp == " " && moripheosHelp != "2")
        {
            cout << setw(10) << "\x1b[33mincorrect input, choose again\x1b[0m" << endl;
            cin >> setw(10) >> moripheosHelp;
        }
        if (moripheosHelp == "1")
        {
            quizMoripheosHelp(moripheosHelpArr, moripheosHelpChances);
        }

        cout << setw(10) << "\x1b[33m \n Answer: \x1b[0m" << endl;
        string answer = "";
        cin >> setw(10) >> answer;

        while (true)
        {
            if (answer == "a" || answer == "b" || answer == "c" || answer == "d")
            {
                break;
            }
            cout << setw(10) << "\x1b[33m \n Please enter correct option to proceed with the game!\x1b[0m" << endl;
            cin >> setw(10) >> answer;
        }

        answerVerification = quizAnswerVerification(answer, vecOfAnswers[iteration]);
        if (answerVerification)
        {

            Xp += XpArr[iteration];
            system("cls");
            cout << setw(10) << " \n\n\x1b[33m Congrats!\nYour answer is correct; you'll gain +\x1b[32m" << XpArr[iteration] << " \x1b[0m \x1b[33mpoints.)\x1b[0m " << endl;
            cout << setw(10) << "\n \x1b[33m Total Xp: \x1b[32m " << Xp << endl;
            streak += 1;

            if (streak == 4)
            {

                bonusRound(vecOfQuestions[6], vecOfOptions[6]);

                cout << setw(10) << "\x1b[33m Answer: \x1b[0m" << endl;
                string answer;
                cin >> setw(30) >> answer;
                answerVerification = quizAnswerVerification(answer, vecOfAnswers[6]);

                if (answerVerification)
                {

                    Xp += 150;
                    cout << setw(10) << " \n\n\x1b[33mCongrats you got this one! \n Your bonus of 150 Xp points is added\x1b[32m \x1b[0m\x1b[33mfor this right answer) \x1b[0m " << endl;
                    cout << setw(10) << "\n\x1b[33m  Total Xp: \x1b[0m\x1b[32m" << Xp << endl;
                }
                else
                {
                    system("cls");
                    cout << setw(10) << " \x1b[31m !WRONG ANSWER! \x1b[0m" << endl;
                }
            }
        }
        else
        {
            cout << setw(5) << "\n\x1b[37m ---------------------------\x1b[0m\n\n \x1b[31m  !Wrong answer! \n\x1b[0m ";
            streak = 0;
            lives--;
            if (lives == 0)
            {
                cout << setw(10) << "\x1b[31m \n Sorry! You ran out of lives \n\x1b[0m ";
                quizDisplayGameOverMessage(Xp);
                break;
            }
            else
                cout << setw(10) << "\x1b[31m You have " << lives << " live/s left\x1b[0m " << endl;
            Xp -= 30;
        }

        iteration++;
        if (iteration == 6)
            quizAccomplishmentMsg(Xp);
    }

    if (Xp == 0)
    {
        cout << "\n \x1b[33m Oh no! Your Xp is 0 \n Win other challenges to gain Xp.\x1b[0m ";
    }
    else
    {
        cout << "\n\t \x1b[33m-------------------QuizTrivia End!-------------------" << endl;
        cout << setw(10) << "You have reached the end of this round!\n \n Your total Xp is \x1b[32m" << Xp << endl;
    }
}
void anagramGame() {

    srand(time(0));
    cout << "When walking down the jungle, You hear some rustling in the bushes. You feel some roots grab your feet.";
    cout << "\nThey are going to drag you into the depths of the jungle!!!";
    cout << "\nYou try to untangle them but they are just holding on too tight. You see some glowing words appear in the sky that read:";
    cout << "\nThrough the vines and shadows cast, a puzzle holds you firm and fast, Decipher the anagram, break the grasp, or in the jungle, forever last.";
    
    string userGuess;
    string words[5] = {"forbidden", "mysterious", "enchanted", "uncharted", "wanderer"};

    int randomIndex = rand() % 5;
    string selectedWord = words[randomIndex];

    string anagram = selectedWord;
    random_shuffle(anagram.begin(), anagram.end());

    cout << "\nAnagram: " << anagram << endl;

  for (int chances = 0; chances < 3; chances++) {
        string userGuess;
        cout << "(Chance " << chances + 1 << "/3): ";
        cin >> userGuess;

        transform(userGuess.begin(), userGuess.end(), userGuess.begin(), ::tolower); //converts the user input to lower case for case insensitive comparison

        if (userGuess == selectedWord) {
            cout << "Correct! You solved the anagram." << endl;
            return;
        } else {
            cout << "Incorrect." << endl;
        }
    }

    cout << "Sorry, you couldn't guess the word. The correct word was: " << selectedWord << endl;
}

int main()
{
    int Xp = 100;
    string name;           // name of the player
    int type, player_health, player_attack, defense;              
    displayInstructions();
    cout << "ENTER YOUR NAME: ";
    cin>> name;
    dialogue0();
    int choice1;
    cin>>choice1;
    
    if(choice1 == 1)                // game continues if user chooses 1                 
    {
        string bear = "Bear";
        int bear_health = 65;
        int bear_attack = 10;
        player_health = 70;
        player_attack = 12;
        choice1a();
        
        int resultfight1 = fight(name, bear, player_health, bear_health, player_attack, bear_attack);    // bear fight

        if (resultfight1 == 1)                                                    // if u win bear fight
        {
            cout<<"You won"<<endl;
            cout<<"You gained 20 hp."<<endl;
            cout<<"Total health: "<<player_health + 20<<endl;
            cout<<"You gained 5 attack power."<<endl;
            cout<<"Total attack: "<<player_attack+5<<endl;
            player_health = 90;
            player_attack= 17;
            line();
            //DIALOGUE//
            int choice2=0;
            cout<<"You move ahead and see 2 paths again. One path leads to a big dirty castle. The other path leads to an old temple. What is your choice?\n";
            cout<<"[1) move towards castle 2) move towards temple]\n";
            cin>>choice2;                                           // choice 2
            if(choice2==1)                                         // knight fight
            {
                cout<<"You start to move towards the castle. As you get closer you see the huge castle gates in front of you. You hear the noise of a horse. You move ahead and see a knight in black broken armour sitting on a horse. The knight lunges at you suddenly, but you dodge out of the way. Not quite the knight in shining armour that you were expecting.\n";
                cout<<"You get ready to fight.\n";
                line();
                string knight = "knight";
                int knight_attack = 14;
                int knight_health = 110;
                int resultknight = fight(name,knight, player_health,knight_health,player_attack,knight_attack);

                if(resultknight==1)                                      // if u win knight fight
                {
                    player_health = 110;
                    player_attack= 22;
                    cout<<"You won.\n";
                    cout<<"You gained 20 hp."<<endl;
                    cout<<"Total health: "<<player_health + 20<<endl;
                    cout<<"You gained 5 attack power."<<endl;
                    cout<<"Total attack: "<<player_attack+5<<endl;
                    line();
                    cout<<"You move ahead. You are almost there. One final challenge awaits you before you face Managma himself.\n";
                    cout<<"You see a jungle in front of you. You enter the jungle.";
                    anagramGame();
                    cout<<"Your long journey is almost over. Managma himself awaits you in his lair."<<endl;
                    cout<<"You enter the lair. Managma is sitting on his throne in front of you. You challenge him to a fight."<<endl;
                    int special = 0;
                    if(Xp<=100)
                    {
                        special = 2;
                    }
                    else{special = 4;}
                    int boss_health = 160;
                    int boss_attack= 25;
                    int resultboss = bossfight(name, "Managma", player_health,boss_health,player_attack,boss_attack,special);
                    if(resultboss ==1)
                    {
                        cout<<"You defeated Managma. Congratulations, You have won the game."<<endl;
                    }
                    else if(resultboss==0)
                    {
                        cout<<"You lost."<<endl;
                        end();
                    }
                   //LAST FIGHT CODE
                }
                else if(resultknight==0)                        // if u lose bear fight
                {
                    end();
                }
            }
            else if(choice2==2)                                         // quiz game
            {
                cout<<"You move to towards the temple. As you get closer, you see an old man sitting outside. The man looks harmless.\n";
                cout<<"You ask the man about the temple. He tells you that his name is Moripheo and that the temple belongs to him. You tell him to let him pass through the temple.\n";
                cout<<"Moripheo agrees, but on the condition that you take part in a quiz. If u pass, he will let you through.\n";
                cout<<"Press 1 to continue: ";
                int temp0;
                cin>>temp0;
                if(temp0==1)
                {
                quiz();
                }
                int temp;
                cout<<"Press 1 to continue: ";
                cin>>temp;
                if(temp==1)
                {
                cout<<"You move ahead. You are almost there. One final challenge awaits you before you face Managma himself.\n";
                cout<<"You see a cave in front of you. You enter the cave.\n";
                
                string witch = "witch";
                int witch_attack = 28;
                int witch_health = 120;
                int resultWitch = fight(name,witch, player_health,witch_health,player_attack,witch_attack);
                if(resultWitch==1)                                        // fINAL BOSS FIGHT
                {
                    player_health = 110;
                    player_attack= 22;
                    cout<<"You won.\n";
                    cout<<"You gained 20 hp."<<endl;
                    cout<<"Total health: "<<player_health + 20<<endl;
                    cout<<"You gained 5 attack power."<<endl;
                    cout<<"Total attack: "<<player_attack+5<<endl;
                    line();
                    cout<<"Your long journey is almost over. Managma himself awaits you in his lair."<<endl;
                    cout<<"You enter the lair. Managma is sitting on his throne in front of you. You challenge him to a fight."<<endl;
                    int special = 0;
                    if(Xp<=100)
                    {
                        special = 2;
                    }
                    else{special = 4;}
                    int boss_health = 160;
                    int boss_attack= 25;
                    int resultboss = bossfight(name, "Managma", player_health,boss_health,player_attack,boss_attack,special);
                    if(resultboss ==1)
                    {
                        cout<<"You defeated Managma. Congratulations, You have won the game."<<endl;
                    }
                    else if(resultboss==0)
                    {
                        cout<<"You lost."<<endl;
                        end();
                    }
                }
                else if(resultWitch == 0)
                {
                    end();
                }
                
                }
            }

        }
        else if (resultfight1 == 0)
        {
            cout<<" You lost."<<endl;
            end();
        }
    }
    else if(choice1 == 2)
    {
        choice1b();
        end();
    }
    return 0;
}
