#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <bits/stdc++.h>
using namespace std;
bool gameover;
const int width=40;
const int height=40;
int x,y,fruitx,fruity,score;
int tailx[100],taily[100];
int ntail;
enum knopka{stop=0,LEFT,RIGHT,UP,DOWN};
knopka kn;
void setup(){
	gameover=false;
	kn=stop;
	x=width/2-1;
	y=height/2-1;
	fruitx=rand()%width-1;
	fruity=rand()%height-1;
	score=0;
}
void draw(){
system("cls");
for(int i=0; i<width+1; i++){
	cout<<"�";
}
	cout<<endl;

for(int i=0; i<height; i++){
	for(int j=0; j<width; j++){
		if(j==0||j==width-1)
			cout<<"�";
			if(i==y&&j==x){
				cout<<"$";
			}else if(i==fruity&&j==fruitx){
				cout<<"@";
			}else{
				bool print=false;
				for(int k=0; k<ntail; k++){
					if(tailx[k]==j&&taily[k]==i){
						print=true;
						cout<<"o";
					}
				}
				if(!print){
					cout<<" ";
				}
				
			}
		
	}
	cout<<endl;
}
for(int i=0; i<width+1; i++){
	cout<<"�";
}
	cout<<endl;
		cout<<"Score: "<<score<<endl;
		cout<<endl;
		cout<<"w-Magla, d-Marjvniv, a-Marcxniv, s-Dabla"<<endl;
}
void input(bool &cikl){
	if(_kbhit()){
		switch (_getch()){
			case 'a': kn=LEFT;
			break;
			case 'd': kn=RIGHT;
			break;
			case 'w': kn=UP;
			break;
			case 's': kn=DOWN;
			break;
			case 'x': gameover=true;
			break;
			case 'r': gameover=false;
			cikl=false;
			break;
			
		}
	}
}
void logic(int choise){
	int prevx=tailx[0];
	int prevy=taily[0];
	int prev2x,prev2y;
	tailx[0]=x;
	taily[0]=y;
	for(int i=1; i<ntail; i++){
		prev2x=tailx[i];
		prev2y=taily[i];
		tailx[i]=prevx;
		taily[i]=prevy;
		prevx=prev2x;
		prevy=prev2y;
	}
	switch (kn){
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case UP:
			y--;
			break;
		case DOWN:
			y++;
			break;
	}
	if(choise==2){
		if(x>width||x<0||y>height||y<0){
		gameover=true;
	}
	}else if(choise==1){
		if(x>=width-1){
			x=0;
		}else if(x<0){
			x=width-2;
		}
		
		if(y>=height){
			y=0;
		}else if(y<0){
			y=height-1;
		}
	}
	
	for(int i=0; i<ntail; i++){
		if(tailx[i]==x&&taily[i]==y){
			gameover=true;
		}
	}
	if(x==fruitx&&y==fruity){
		score+=1;
		fruitx=rand()%width;
	fruity=rand()%height;
	ntail++;
	}
}
int main(){
	system("color 01");
	int choise;
	cout<<"Chaweret done 1 an 2"<<endl; //Done 1 Sheigvizlia kedelshi gasvla. done 2 kedelshi shejaxeba wagebaa
	cin>>choise;
	cout<<endl;
	setup();
	bool cikl=true;
	bool wh=false;
	while(!wh){
		while(!gameover){
		draw();
		input(cikl);
		logic(choise);
	}
	
	if(gameover){
		
		system("color 40");
		while(cikl){
			cout<<"GAME OVER!"<<endl;
			system("cls");
			input(cikl);
		}
		
		
	}	
	}
	
}
