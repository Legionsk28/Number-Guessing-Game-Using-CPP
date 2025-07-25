#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int randomNumGen(int start, int end) {
    srand(time(0));
    int randValue = ( rand() % end) + 1;
    if(start<=randValue && end >= randValue) {
        return randValue;
    } else {
        randValue *= start;
        return(randValue % end);
    }
}

void numGuessGame() {
    int attps = 5;
    int start = 1;
    int end = 100;
    int target;
    
    int randomNumber = randomNumGen(start, end);
    cout<<"----------------------------"<<endl;
    cout<<"Welcome to the Number Guessing Game! "<<endl;
    
    cout<<"You have "<<attps<<endl;
    cout<<"Range is "<<start<<" to "<<end<<endl;
    cout<<"----------------------------"<<endl;

    while (attps) {
        cout<<"Enter your Guess: ";
        cin>>target;

        if(target == randomNumber) {
            cout<<"Number is Correct!"<<endl;
            break;
        } else if(target > randomNumber && attps > 1) {
            cout<<"Number is too high! Decrease your guess!";
        } else if(target < randomNumber && attps > 1) {
            cout<<"Number is too low! Increase your guess!";
        }
        attps--;
    }
    if(attps) {
        cout<<"Your Guess is Correct! You Won the Game!"<<endl;
        cout<<"----------------------------"<<endl;
    } else {
        cout<<"----------------------------"<<endl;
        cout<<"Your Guess is Incorrect! You Lose the Game!"<<endl;
        cout<<"----------------------------"<<endl;
    }
}


int main() {
    numGuessGame();
    cout<<endl;
    return 0;
}