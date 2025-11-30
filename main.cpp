#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

enum Suit { Hearts, Diamonds, Clubs, Spades };

string suitToString(Suit s) {
    switch (s) {
        case Hearts: return "♥";
        case Diamonds: return "♦";
        case Clubs: return "♣";
        case Spades: return "♠";
    }
    return "?";
}

struct Card {
    string rank;
    Suit suit;
    int value;
};

vector<Card> createDeck() {
    vector<Card> deck;
    string ranks[] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    int values[]   = { 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };

    for(int s = 0; s < 4; s++) {
        for(int r = 0; r < 13; r++) {
            deck.push_back({ranks[r], (Suit)s, values[r]});
        }
    }
    return deck;
}

int calculatePoints(const vector<Card> &hand) {
    int total = 0, aceCount = 0;
    for(auto &c : hand) {
        total += c.value;
        if(c.rank == "A") aceCount++;
    }
    while(total > 21 && aceCount > 0) {
        total -= 10;
        aceCount--;
    }
    return total;
}

void printHand(const vector<Card>& hand, bool hideFirst = false) {
    for (int i = 0; i < (int)hand.size(); i++) {
        if (hideFirst && i == 0) {
            cout << "[??] ";
        } else {
            cout << "[" << hand[i].rank << suitToString(hand[i].suit) << "] ";
        }
    }
    cout << endl;
}

int main() {
    random_device rd;
    mt19937 rng(rd());

    cout << "=== BLACKJACK C++ ===" << endl;

    while (true) {
        vector<Card> deck = createDeck();
        shuffle(deck.begin(), deck.end(), rng);

        vector<Card> player, dealer;

        player.push_back(deck.back()); deck.pop_back();
        dealer.push_back(deck.back()); deck.pop_back();
        player.push_back(deck.back()); deck.pop_back();
        dealer.push_back(deck.back()); deck.pop_back();

        bool playerBust = false;

        while(true) {
            cout << "\nYour cards: ";
            printHand(player);
            int playerPoints = calculatePoints(player);
            cout << "Points: " << playerPoints << endl;

            cout << "Dealer: ";
            printHand(dealer, true);

            if(playerPoints > 21) {
                cout << "BUST! You lose!" << endl;
                playerBust = true;
                break;
            }

            cout << "Hit (H) / Stand (S)? ";
            char choice;
            cin >> choice;

            if(choice == 'H' || choice == 'h') {
                player.push_back(deck.back());
                deck.pop_back();
            } else if(choice == 'S' || choice == 's') {
                break;
            } else {
                cout << "Invalid input. Please enter H or S." << endl;
            }
        }

        if(!playerBust) {
            while(calculatePoints(dealer) < 17) {
                dealer.push_back(deck.back());
                deck.pop_back();
            }

            cout << "\n=== Result ===" << endl;
            cout << "Your cards: ";
            printHand(player);
            int playerScore = calculatePoints(player);
            cout << "Points: " << playerScore << endl;

            cout << "Dealer cards: ";
            printHand(dealer);
            int dealerScore = calculatePoints(dealer);
            cout << "Points: " << dealerScore << endl;

            if(dealerScore > 21 || playerScore > dealerScore)
                cout << "You win!" << endl;
            else if(playerScore < dealerScore)
                cout << "You lose!" << endl;
            else
                cout << "Push! (Tie)" << endl;
        } else {
            cout << "\nDealer cards: ";
            printHand(dealer);
            cout << "Points: " << calculatePoints(dealer) << endl;
        }

        char again;
        cout << "\nPlay again? (Y/N): ";
        cin >> again;
        if(again != 'Y' && again != 'y')
            break;
    }

    cout << "Thanks for playing!" << endl;
    return 0;
}
