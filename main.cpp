#include <cstdio>
#include <cstring>
#include <stack>
#include <iostream>


using namespace std;
int face(char val)
{
    if(val == 'J') return 1;
    if(val == 'Q') return 2;
    if(val == 'K') return 3;
    if(val == 'A') return 4;
    return 0;
}
int main(){
int HERO=2;
int D=1;
    char carta[3];
    int n = 0;
    while(cin>>carta){
        if(carta[0]=='#'){
    break;
}
        n++;
        deque<int> hero,d;
        hero.push_front(face(carta[1]));
        cin>>carta;
        d.push_front(face(carta[1]));
        for(int i=0;i<25;i++){
            cin>>carta;
            hero.push_front(face(carta[1]));
            cin>>carta;
            d.push_front(face(carta[1]));
        }

        deque<int> deck;
        int turn = HERO, winner = 0;
        int jugar;
        bool end = false;
        while(!end){
            jugar = 0;
            if(deck.empty() or deck.front() == 0){
                if(turn == D) {
                    if(d.empty())
                        end = true;
                    else{
                        jugar = d.front();
                        d.pop_front();}}
                else {
                    if(hero.empty()) 
                        end = true;
                    else{
                        jugar = hero.front();
                        hero.pop_front();
                    }}
                        deck.push_front(jugar);
                if(jugar!= 0)
                    winner = turn;
            }
            else{
                if(turn == D){
                    int sacar = deck.front();
                    for(int j=0;j<sacar;j++){
                        if(d.empty()){
                            end = true;
                            break;
                        }
                        else{
                            jugar = d.front();
                            d.pop_front();
                            deck.push_front(jugar);
                            if(jugar != 0){
                                winner = turn; break;}
                        }}
                    if(winner != turn and !end){
                        while(!deck.empty()){
                            hero.push_back(deck.back());
                            deck.pop_back();
                        }}}
                else{
                    int sacar = deck.front();
                    for(int k=0;k<sacar;k++){
                        if(hero.empty()){
                            end = true;
                            break;
                        }
                        else{
                            jugar = hero.front();
                            hero.pop_front();
                            deck.push_front(jugar);
                            if(jugar != 0){
                                winner = turn;
                                break;
                            }
                        }}
                    if(winner != turn and !end){
                        while(!deck.empty()){
                            d.push_back(deck.back());
                            deck.pop_back();
                        }}}
                winner = 0;
            }
          if(turn==HERO)
                turn=D;
          else turn=HERO;
        }
        printf("%d%3d\n",turn,d.size()+hero.size());
    }
    return 0;
}
