using namespace std;
#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<cstdlib>
#include<time.h>
#include<string>
#include<string.h>

class dice{
	public:
	int a;
	public:
	int rool(){
	srand(time(0));
	a=1+rand()%6;

cout << " ----- " << endl;
cout << "|@@@@@|" << endl;
cout << "|@@@@@|" << endl;
cout << "|@@@@@|" << endl;
cout <<  " -----" << endl;	
	}
	void show(){
		if(a==1)
{
cout << " ----- " << endl;
cout << "|     |" << endl;
cout << "|  O  |" << endl;
cout << "|     |" << endl;
cout <<  " -----" << endl;
}
else if(a==2)
{
cout << " -----" << endl;
cout << "|    O|" << endl;
cout << "|     |" << endl;
cout << "|O    |" << endl;
cout <<  " -----" << endl;
}
else if(a==3)
{
cout << " -----" << endl;
cout << "|    O|" << endl;
cout << "|  O  |" << endl;
cout << "|O    |" << endl;
cout <<  " -----" << endl;
}
else if(a==4)
{
cout << " -----" << endl;
cout << "|O   O|" << endl;
cout << "|     |" << endl;
cout << "|O   O|" << endl;
cout <<  " -----" << endl;
}
else if(a==5)
{
cout << " -----" << endl;
cout << "|O   O|" << endl;
cout << "|  O  |" << endl;
cout << "|O   O|" << endl;
cout << " -----" << endl;
}
else if(a==6)
{
cout << " -----" << endl;
cout << "|O   O|" << endl;
cout << "|O   O|" << endl;
cout << "|O   O|" << endl;
cout <<  "-----" << endl;
}
	}	
};



class player{
	public:
	bool has_sword = false;
	bool is_stuck = false;
	bool is_lost = false;
	string name;
	int posnum=0;
	int position[2]={0,0};
	
	public:
	int rolldice(){
	dice t;	
	
	char c;
	cout<<"press r to roll dice and any other to show\n";
	do	{
	
	t.rool();
	cin>>c;
	}while(c=='r');
	t.show();
	return t.a;
	}
	void move(int i){
		position[0] = position[1];
		if(is_stuck == false && is_lost == false && position[1]+i<=100){
			
			position[1]+=i;
		}
		else if(i==6){
			cout<<"You were held back in the forest but you have escaped the trap"<<endl;
			is_stuck=false;
			is_lost = false;
		}
		else{
		
		if(is_stuck)
			cout<<"You are stucked in mud, play six to move out"<<endl;
			if(is_lost)
			cout<<"you are lost in the Jungle, play six to find yourself"<<endl;
			}
		cout<<name<<"was in "<<position[0]<<"and is now in position"<<position[1]<<endl;
	}
};

class snake{
	public:
	int head;
	int size;
	int tail;
	snake(){
		head = 0;
		size = 0;
		tail =0;
	}
	snake(int a, int c){
		head = a;
		size = c;
		tail = a - c;
	}
	int eat(player* t){
		if(t->has_sword==false){
		
		t->position[1] = tail;
			cout<<t->name<<" Got Snake And demoted to "<<tail<<"\n"<<endl;
		cout << "              **    **    **        " << endl;
		cout << "    "<<head<<" <<*  *   *  *  *  *  *  *>>  "<<tail<<" "<< endl;
		cout << "          **     **    **    **     " << endl;	
		}
		return t->position[1];
	}
	void move(int i){
		head+=i;
		tail = head - size;
	};
};

class ladder{
	public:
	int bottom;
	int size;
	int top;
	ladder()
	{
		bottom = 0;
		size = 0;
		top = 0;
	}
	ladder(int a, int c){
		bottom = a;
		size = c;
		top = a + c;
	}
	int lift(player* t){
		t->position[1] = top;
		cout<<t->name<<" Got Ladder And promoted to "<<top<<"\n"<<endl;
		cout<<  "   "<<top<<"   "<<endl;
		cout << "  |__|  "<< endl;
        cout << "  |__|  "<< endl;
		cout << "  |__|  "<< endl;
		cout << "  |__|  "<< endl;
		cout << "  |__|  "<< endl;
		cout<<  "  |  |  "<<endl;
		cout<<  "   "<<bottom<<"   "<<endl;
		return top;
	}

};

class spring{
	public:
	int bottom;
	int size;
	int top;
	spring(){
	
	}
	spring(int a, int c){
		bottom = a;
		size = c;
		top = a + c;
	}
	int shoots(player* t){
		t->position[1] = top;
		cout<<t->name<<" Got Spring And promoted to "<<top<<"\n"<<endl;
cout<<  "                        "<<top<<"   "<<endl;
cout<<"		      ======   "<< endl;
cout<<"             "<<bottom<<"       \\\\  //   "<< endl;
cout<<"           ======      \\\\//    "<< endl;
cout<<"	   \\\\  //       ==     "<< endl;
cout<<"	    ====        ==     "<< endl;
cout<<"	    ====       //\\\\    "<< endl;
cout<<"	   //  \\\\     //  \\\\   "<< endl;
		cout<<  "      "<<endl;
		return top;
	}

};
class cell{
	public:
	snake s;
	ladder l;
	spring sp;
	bool has_snake;
	bool has_mud;
	bool has_spring;
	bool has_ladder;
	bool has_sword;
	bool has_bush;
	cell(){
		has_snake = false;
		has_mud = false;
		has_spring = false;
		has_ladder = false;
		has_sword = false;
		has_bush = false;
	}

};
cell board[100];
void arrangeboard(){
	int c;
	
	snake one(41,16);
	snake two(87,17);
	snake three(93,26);
	snake four(99,93);
	ladder on(7,78);
	ladder tw(10,40);
	ladder thre(33,36);
	ladder fou(77,20);
	spring spr(35,40);
	board[53].has_mud = true;
	board[90].has_sword = true;
	board[20].has_bush = true;
	board[98].s = four;
	board[98].has_snake = true;
	board[92].s = three;
	board[92].has_snake = true;
	board[86].s = two;
	board[86].has_snake = true;
	board[40].s = one;
	board[40].has_snake = true;
	
	board[6].l = on;
	board[6].has_ladder = true;
	board[9].l = tw;
	board[9].has_ladder = true;
	board[32].l = thre;
	board[32].has_ladder = true;
	board[76].l = on;
	board[76].has_ladder = true;
	
	board[35].sp = spr;
	board[35].has_spring = true;
}
static player PLAYER[4];


int main(int argc, char** argv)
{
cout<<"  _________              __                     ____    .____                .___  .___                    "<< endl;
cout<<" /   _____/ ____ _____  |  | __ ____   ______  /  _ \\   |    |   _____     __| _/__| _/___________  ______ "<< endl;
cout<<" \\_____  \\ /    \\\\__  \\ |  |/ // __ \\ /  ___/  >  _ </\\ |    |   \\__  \\   / __ |/ __ |/ __ \\_  __ \\/  ___/ "<< endl;
cout<<" /        \\   |  \\/ __ \\|    <\\  ___/ \\___ \\  /  <_\\ \\/ |    |___ / __ \\_/ /_/ / /_/ \\  ___/|  | \\/\\___ \\  "<< endl;
cout<<"/_______  /___|  (____  /__|_ \\\\___  >____  > \\_____\\ \\ |_______ (____  /\\____ \\____ |\\___  >__|  /____  > "<< endl;
cout<<"        \\/     \\/     \\/     \\/    \\/     \\/         \\/         \\/    \\/      \\/    \\/    \\/           \\/ "<< endl;
arrangeboard();
int players, moveValue, positionNumber =1;

int y;
int stop;
bool end = false;
    
		cout<<"\n===========>>>>>  Game Include Minimum 2 And Maximum 4 Players <<<<<<<=========="<<endl;
	cout<<"\nEnter The Number Of Players :  ";
	cin>>players;
	
		while(players==1||players>=5)
	{
		cout<<"\tYou Have Entered Invalid Numbers Of Players "<<endl;
		cout<<"\n\tEnter The number between 2-4: "<<endl;
		cin>>players;
	}
	stop = players;
	
	for(y=0; y<players; y++)
    {
    	if(y==0)
    	cout<<"Enter The Name Of First Player: "<<endl;
    	else if(y==1)
    	cout<<"Enter The Name Of Second Player: "<<endl;
    	else if(y==2)
    	cout<<"Enter The Name Of Third Player: "<<endl;
    	else if(y==3)
    	cout<<"Enter The Name Of Fourth Player: "<<endl;
    	

    	cin>>PLAYER[y].name;

	}
	
	
	
	if(players<=4 && players!=1)
	{
	while(!end)
		{
			for(y=0; y<players; y++)
			{
			
			if(PLAYER[y].position[1]!=100)
			{
			
			cout<<PLAYER[y].name<<" Turn To Play"<<endl;
			moveValue = PLAYER[y].rolldice();
			PLAYER[y].move(moveValue);
			if(board[PLAYER[y].position[1]-1].has_ladder)
			board[PLAYER[y].position[1]-1].l.lift(&PLAYER[y]);
			if(board[PLAYER[y].position[1]-1].has_snake)
			board[PLAYER[y].position[1]-1].s.eat(&PLAYER[y]);
			if(board[PLAYER[y].position[1]-1].has_spring)
			board[PLAYER[y].position[1]-1].sp.shoots(&PLAYER[y]);
			if(board[PLAYER[y].position[1]-1].has_mud)
			PLAYER[y].is_stuck=true;
			if(board[PLAYER[y].position[1]-1].has_bush)
			PLAYER[y].is_lost = true;
			if(board[PLAYER[y].position[1]-1].has_sword)
			PLAYER[y].has_sword = true;
			if(PLAYER[y].is_lost == true)
			cout<<PLAYER[y].name<<"  is lost in the forest"<<endl;
			if(PLAYER[y].is_stuck == true)
			cout<<PLAYER[y].name<<"  is lost is stuck in mud"<<endl;
			if(PLAYER[y].has_sword == true)
			cout<<PLAYER[y].name<<"  is has gotten a sword to deal with any further snake"<<endl;
			
			
				
				
			
				
				
				if(PLAYER[y].position[1]==100)
				{
					cout<<"\nHURRAY "<<PLAYER[y].name<<" HAS FOUND HOME AND IS OUT OF THIS COMBAT"<<endl;
					
					PLAYER[y].posnum = positionNumber;
					positionNumber++;
					stop=stop-1;
					break;
				}
				
				
				
				system("pause");
		        system("cls");
				if(stop==1)
			{
				end=true;
				break;
			}
			
			
			
		    }
		}
		
		}
		
cout<<"\n\t<======RESULTS=======>\n\n"<<endl;
for(y=0; y<players; y++)
    {
    cout<<"\t"<<PLAYER[y].name<<" Got :"<<PLAYER[y].posnum<<" Position"<<endl;
	}
    
    cout<<"\t\t============================="<<endl;
	cout<<"\t\t||       GAME OVER!!!      ||"<<endl;
	cout<<"\t\t============================="<<endl;
	



getch();
	
}
	
system("pause");
return 0;
}
