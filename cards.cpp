#include <stdlib.h>
#include <stdio.h>
#include <list>

using namespace std;

class Card
{
public:
    int number;
    bool checked;
    Card(int i)
    {
        this->number = i;
        checked = false;
    };

};

void clearDupes(list<Card*>& cards);
void isDupe(Card *c,list<Card*>& cards);

int main(void)
{
    list<Card*> cards;

    cards.push_back(new Card(0));
    cards.push_back(new Card(0));
    for(int j = 1;j<=10;j++)
    {
        /*  Se genera una lista de cartas que
            contendra duplicados */
        Card *temp = new Card(j);
        if(j%2 == 0)
            temp->number = 2;
        if(j%3 == 0)
            temp->number = 3;
        if(j%4 == 0)
            temp->number = 4;
        cards.push_back(temp);
    }
    cards.push_back(new Card(5));
    cards.push_back(new Card(5));
    cards.push_back(new Card(5));
    cards.push_back(new Card(5));
    cards.push_back(new Card(1));
    cards.push_back(new Card(9));
    /*  y varios duplicados mas
        for good measure  */

    list<Card*>::iterator it;
    for(it = cards.begin();it != cards.end();++it)
        printf("Card %d \n",(*it)->number);
    printf("\nChecking for dupes...\n\n");

    clearDupes(cards);

    for(it = cards.begin();it != cards.end();++it)
        printf("Card %d \n",(*it)->number);

}

void clearDupes(list<Card*>& cards)
{
    list<Card*>::const_iterator it;
    for(it = cards.begin();it != cards.end();++it)
    {
        (*it)->checked = true;
        isDupe(*it, cards);
    }
    /*  se borran todas las cartas que tengan valor
        numerico de -1  */
    for(list<Card*>::iterator itr = cards.begin();itr != cards.end();)
    {
        if((*itr)->number == -1)
            itr = cards.erase(itr);
        else
        ++itr;
    }
}

void isDupe(Card *c,list<Card*>& cards)
{
    list<Card*>::const_iterator it;
    for(it = cards.begin();it != cards.end();++it)
    {
        if( (*it)->checked != true && (*it)->number == c->number)
            (*it)->number = -1;
    }
}
