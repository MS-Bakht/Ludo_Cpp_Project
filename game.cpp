//|============================================================================|
//| Name        : Shayan Bakht                                                 |
//| Roll Number :                                                              |
//| Degree      : Artificial Intelligence                                      |
//| Secrion     :                                                              |
//| Description : Ludo Game                                                    |
//| Project     : Programming Fundamentals                                     |
//|============================================================================|

#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
//#include "Board.h"
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;







void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}

bool gamestart=0,torrB=1,torrY=0,torrR=0,torrG=0;
int blue[4]={-1,-1,-1,-1},yellow[4]={-1,-1,-1,-1},red[4]={-1,-1,-1,-1},green[4]={-1,-1,-1,-1},nplayers=0;
int pcolors[4]={-1,-1,-1,-1},turn=1;
long nn;
int bbuf[3]={0,0,0}, ybuf[3]={0,0,0},rbuf[3]={0,0,0},gbuf[3]={0,0,0};
string names[4];
int selectedKey=-1;
int scoreb=0, scorey=0, scorer=0, scoreg=0;
int test;


//Using arrays to define the possible path
	// Defining General paths:
	//Path for blue
	int GB[][2]={ {220,60},{220,100},{220,140},{220,180},{220,220},{180,220},{140,220},{100,220},{60,220},{20,220},{20,260},{20,300},{60,300},{100,300},{140,300},{180,300},{220,300},{220,340},{220,380},{220,420},{220,460},{220,500},{260,500},{300,500},{300,460},{300,420},{300,380},{300,340},{300,300},{340,300},{380,300},{420,300},{460,300},{500,300},{500,260},{500,220},{460,220},{420,220},{380,220},{340,220},{300,220},{300,180},{300,140},{300,100},{300,60},{300,20},{260,20} };
	
	//Path for yellow
	int GY[][2]={ {60,300},{100,300},{140,300},{180,300},{220,300},{220,340},{220,380},{220,420},{220,460},{220,500},{260,500},{300,500},{300,460},{300,420},{300,380},{300,340},{300,300},{340,300},{380,300},{420,300},{460,300},{500,300},{500,260},{500,220},{460,220},{420,220},{380,220},{340,220},{300,220},{300,180},{300,140},{300,100},{300,60},{300,20},{260,20},{220,20},{220,60},{220,100},{220,140},{220,180},{220,220},{180,220},{140,220},{100,220},{60,220},{20,220},{20,260} };
	
	//Path for red
	int GR[][2]={ {300,460},{300,420},{300,380},{300,340},{300,300},{340,300},{380,300},{420,300},{460,300},{500,300},{500,260},{500,220},{460,220},{420,220},{380,220},{340,220},{300,220},{300,180},{300,140},{300,100},{300,60},{300,20},{260,20},{220,20},{220,60},{220,100},{220,140},{220,180},{220,220},{180,220},{140,220},{100,220},{60,220},{20,220},{20,260},{20,300},{60,300},{100,300},{140,300},{180,300},{220,300},{220,340},{220,380},{220,420},{220,460},{220,500},{260,500}};
	
	//Path for green
	int GG[][2]={ {460,220},{420,220},{380,220},{340,220},{300,220},{300,180},{300,140},{300,100},{300,60},{300,20},{260,20},{220,20},{220,60},{220,100},{220,140},{220,180},{220,220},{180,220},{140,220},{100,220},{60,220},{20,220},{20,260},{20,300},{60,300},{100,300},{140,300},{180,300},{220,300},{220,340},{220,380},{220,420},{220,460},{220,500},{260,500},{300,500},{300,460},{300,420},{300,380},{300,340},{300,300},{340,300},{380,300},{420,300},{460,300},{500,300},{500,260} };
	
	//Defining special paths
	//S-path for blue
	int SB[][2]={ {220,60},{220,100},{220,140},{220,180},{220,220},{180,220},{140,220},{100,220},{60,220},{20,220},{20,260},{20,300},{60,300},{100,300},{140,300},{180,300},{220,300},{220,340},{220,380},{220,420},{220,460},{220,500},{260,500},{300,500},{300,460},{300,420},{300,380},{300,340},{300,300},{340,300},{380,300},{420,300},{460,300},{500,300},{500,260},{500,220},{460,220},{420,220},{380,220},{340,220},{300,220},{300,180},{300,140},{300,100},{300,60},{300,20},{260,20},{260,60},{260,100},{260,140},{260,180},{260,220},{260,260} };
	
	//S-path for yellow
	int SY[][2]={ {60,300},{100,300},{140,300},{180,300},{220,300},{220,340},{220,380},{220,420},{220,460},{220,500},{260,500},{300,500},{300,460},{300,420},{300,380},{300,340},{300,300},{340,300},{380,300},{420,300},{460,300},{500,300},{500,260},{500,220},{460,220},{420,220},{380,220},{340,220},{300,220},{300,180},{300,140},{300,100},{300,60},{300,20},{260,20},{220,20},{220,60},{220,100},{220,140},{220,180},{220,220},{180,220},{140,220},{100,220},{60,220},{20,220},{20,260},{60,260},{100,260},{140,260},{180,260},{220,260},{260,260}};
	
	//S-path for red
	int SR[][2]={ {300,460},{300,420},{300,380},{300,340},{300,300},{340,300},{380,300},{420,300},{460,300},{500,300},{500,260},{500,220},{460,220},{420,220},{380,220},{340,220},{300,220},{300,180},{300,140},{300,100},{300,60},{300,20},{260,20},{220,20},{220,60},{220,100},{220,140},{220,180},{220,220},{180,220},{140,220},{100,220},{60,220},{20,220},{20,260},{20,300},{60,300},{100,300},{140,300},{180,300},{220,300},{220,340},{220,380},{220,420},{220,460},{220,500},{260,500},{260,460},{260,420},{260,380},{260,340},{260,300},{260,260}};
	
	//S-path for green
	int SG[][2]={{460,220},{420,220},{380,220},{340,220},{300,220},{300,180},{300,140},{300,100},{300,60},{300,20},{260,20},{220,20},{220,60},{220,100},{220,140},{220,180},{220,220},{180,220},{140,220},{100,220},{60,220},{20,220},{20,260},{20,300},{60,300},{100,300},{140,300},{180,300},{220,300},{220,340},{220,380},{220,420},{220,460},{220,500},{260,500},{300,500},{300,460},{300,420},{300,380},{300,340},{300,300},{340,300},{380,300},{420,300},{460,300},{500,300},{500,260},{460,260},{420,260},{380,260},{340,260},{300,260},{260,260}};

  	//~~~~~Drawing~~~~~~~ 
void DrawBlue(int b,bool torrB)  
{
		
	if (torrB==true)
	{
		DrawCircle(SB[b][0],SB[b][1],15,colors[WHITE]);
		DrawCircle(SB[b][0],SB[b][1],10,colors[BLUE]);
	}
	else 
	{
		DrawCircle(GB[b][0],GB[b][1],15,colors[WHITE]);
		DrawCircle(GB[b][0],GB[b][1],10,colors[BLUE]);
	}
}	

void DrawYellow (int y,bool torrY) 
{
	if (torrY==true)
	{
		DrawCircle(SY[y][0],SY[y][1],15,colors[WHITE]);
		DrawCircle(SY[y][0],SY[y][1],10,colors[YELLOW]);
	}
	else 
	{
		DrawCircle(GY[y][0],GY[y][1],15,colors[WHITE]);
		DrawCircle(GY[y][0],GY[y][1],10,colors[YELLOW]);
	}
}	

void DrawRed (int r,bool torrR) 
{

	if (torrR==true)
	{
		DrawCircle(SR[r][0],SR[r][1],15,colors[WHITE]);
		DrawCircle(SR[r][0],SR[r][1],10,colors[RED]);
	}
	else 
	{
		DrawCircle(GR[r][0],GR[r][1],15,colors[WHITE]);
		DrawCircle(GR[r][0],GR[r][1],10,colors[RED]);
	}
}	



void DrawGreen (int g, bool torrG) 
{	
	if (torrG==true)
	{
		DrawCircle(SG[g][0],SG[g][1],15,colors[WHITE]);
		DrawCircle(SG[g][0],SG[g][1],10,colors[GREEN]);
	}
	else 
	{
		DrawCircle(GG[g][0],GG[g][1],15,colors[WHITE]);
		DrawCircle(GG[g][0],GG[g][1],10,colors[GREEN]);
	}
}

void DrawAll()
{

    for(int i=0;i<4;i++)
    {
     if((blue[i]!=-1) && (blue[i]!=-2))
      DrawBlue(blue[i],torrB);
    }
    for(int i=0;i<4;i++)
    {
    if((yellow[i]!=-1) && (yellow[i]!=-2))
      DrawYellow(yellow[i],torrY);
    }

    for(int i=0;i<4;i++)
    {
    if((red[i]!=-1) && (red[i]!=-2))
      DrawRed(red[i],torrR);
    }
    for(int i=0;i<4;i++)
    {
    if((green[i]!=-1) && (green[i]!=-2))
      DrawGreen(green[i],torrG);
    }
}
void board()
{
	//Board of ludo
	DrawSquare(0,0,520,colors[BLACK]); 
	
	//FIRST MAKING THE HOMES/BASES
	//Home 1
	if(yellow[0]==-1)
	DrawCircle(20,500,15,colors[YELLOW]);
	if(yellow[1]==-1)
	DrawCircle(60,500,15,colors[YELLOW]);
	if(yellow[2]==-1)
	DrawCircle(20,460,15,colors[YELLOW]);
	if(yellow[3]==-1)
	DrawCircle(60,460,15,colors[YELLOW]);
	
	//Home 2
	if(red[0]==-1)
	DrawCircle(460,500,15,colors[RED]);
	if(red[1]==-1)
	DrawCircle(500,500,15,colors[RED]);
	if(red[2]==-1)
	DrawCircle(460,460,15,colors[RED]);
	if(red[3]==-1)
	DrawCircle(500,460,15,colors[RED]);
	
	//Home 3
	if(blue[0]==-1)
	DrawCircle(20,60,15,colors[BLUE]);
	if(blue[1]==-1)
	DrawCircle(60,60,15,colors[BLUE]);
	if(blue[2]==-1)
	DrawCircle(20,20,15,colors[BLUE]);
	if(blue[3]==-1)
	DrawCircle(60,20,15,colors[BLUE]);
	
	//Home 4
	if(green[0]==-1)
	DrawCircle(460,60,15,colors[GREEN]);
	if(green[1]==-1)
	DrawCircle(500,60,15,colors[GREEN]);
	if(green[2]==-1)
	DrawCircle(460,20,15,colors[GREEN]);
	if(green[3]==-1)
	DrawCircle(500,20,15,colors[GREEN]);
 	
 	//SECONDLY MAKING LANES
 	//~~~~~VERTICLE~~~~~
 	//~~LEFT~~
 	//red-lane
 	DrawCircle(220,500,15,colors[WHITE]);
 	DrawCircle(220,460,15,colors[WHITE]);
 	DrawCircle(220,420,15,colors[RED]);
 	DrawCircle(220,380,15,colors[WHITE]);
 	DrawCircle(220,340,15,colors[WHITE]);
 	DrawCircle(220,300,15,colors[WHITE]);
 	
 	//blue-lane
 	DrawCircle(220,220,15,colors[WHITE]);
 	DrawCircle(220,180,15,colors[WHITE]);
 	DrawCircle(220,140,15,colors[WHITE]);
 	DrawCircle(220,100,15,colors[WHITE]);
 	DrawCircle(220,60,15,colors[BLUE]);
 	DrawCircle(220,20,15,colors[WHITE]);
 
	//~~MIDDLE~~
	//red-lane
 	DrawCircle(260,500,15,colors[WHITE]);
 	DrawCircle(260,460,15,colors[RED]);
 	DrawCircle(260,420,15,colors[RED]);
 	DrawCircle(260,380,15,colors[RED]);
 	DrawCircle(260,340,15,colors[RED]);

	//blue-lane
 	DrawCircle(260,180,15,colors[BLUE]);
 	DrawCircle(260,140,15,colors[BLUE]);
 	DrawCircle(260,100,15,colors[BLUE]);
 	DrawCircle(260,60,15,colors[BLUE]);
 	DrawCircle(260,20,15,colors[WHITE]);
 	
 	//~~RIGHT~~
 	//red-lane
 	DrawCircle(300,500,15,colors[WHITE]);
 	DrawCircle(300,460,15,colors[RED]);
 	DrawCircle(300,420,15,colors[WHITE]);
 	DrawCircle(300,380,15,colors[WHITE]);
 	DrawCircle(300,340,15,colors[WHITE]);
 	DrawCircle(300,300,15,colors[WHITE]);
 	
 	//blue-lane
 	DrawCircle(300,220,15,colors[WHITE]);
 	DrawCircle(300,180,15,colors[WHITE]);
 	DrawCircle(300,140,15,colors[WHITE]);
 	DrawCircle(300,100,15,colors[BLUE]);
 	DrawCircle(300,60,15,colors[WHITE]);
 	DrawCircle(300,20,15,colors[WHITE]);
 	
 	//~~~~~HORIZONTAL~~~~~
 	//~~UPPER~~
 	//yellow-lane
 	DrawCircle(20,300,15,colors[WHITE]);
	DrawCircle(60,300,15,colors[YELLOW]);
	DrawCircle(100,300,15,colors[WHITE]);
	DrawCircle(140,300,15,colors[WHITE]);
	DrawCircle(180,300,15,colors[WHITE]);
	
	//green-lane
	DrawCircle(340,300,15,colors[WHITE]);
	DrawCircle(380,300,15,colors[WHITE]);
	DrawCircle(420,300,15,colors[GREEN]);
	DrawCircle(460,300,15,colors[WHITE]);
	DrawCircle(500,300,15,colors[WHITE]);
	
	//~~MIDDLE~~
	//yellow-lane
 	DrawCircle(20,260,15,colors[WHITE]);
	DrawCircle(60,260,15,colors[YELLOW]);
	DrawCircle(100,260,15,colors[YELLOW]);
	DrawCircle(140,260,15,colors[YELLOW]);
	DrawCircle(180,260,15,colors[YELLOW]);
	
	//green-lane
	DrawCircle(340,260,15,colors[GREEN]);
	DrawCircle(380,260,15,colors[GREEN]);
	DrawCircle(420,260,15,colors[GREEN]);
	DrawCircle(460,260,15,colors[GREEN]);
	DrawCircle(500,260,15,colors[WHITE]);
	
	//~~Lower~~
	//yellow-lane
	DrawCircle(20,220,15,colors[WHITE]);
	DrawCircle(60,220,15,colors[WHITE]);
	DrawCircle(100,220,15,colors[YELLOW]);
	DrawCircle(140,220,15,colors[WHITE]);
	DrawCircle(180,220,15,colors[WHITE]);
	
	//green-lane
	DrawCircle(340,220,15,colors[WHITE]);
	DrawCircle(380,220,15,colors[WHITE]);
	DrawCircle(420,220,15,colors[WHITE]);
	DrawCircle(460,220,15,colors[GREEN]);
	DrawCircle(500,220,15,colors[WHITE]);
}

//Check for occupied colors
bool checkcolor(int x)
{
	for(int i=0; i<4;i++)
	{
		if(pcolors[i]==x)
		return false;
	}
	return true;
}
//This is initial for number of players
void playercountsetup()
{
	if((nplayers<2)||(nplayers>4))
	{
		int temp;
		cout<<"Please enter the number of players between 2 and 4"<<endl;
		cout<<"You Selected : ";
		cin>>temp;
		if(temp>=2 && temp<=4)
			{nplayers=temp;}
		else
			{cout<<"\nYou Need to choose between 2 and 4.\n"<<endl;}
	}
}
void playercolorsetup()
{	
	if ( (nplayers>=2)&&(nplayers<=4)&&(pcolors[nplayers-1]==-1))
	{ //pcolors will check if the color-slot is occupied or not
		for(int i=1;i<=nplayers;i++)
		{
			int temp;
			string st="Player "+to_string(i)+" , Enter color:\n 0 = blue \n 1 = yellow \n 2 = red \n 3 = green \n You choose : ";
			cout<<st;
			cin>>temp;
			if(checkcolor(temp)==true)
				{pcolors[i-1]=temp;}
			else 
			{cout<<"This color has already been taken,please choose another one";
			 i--;
			}
			cout<<"Now enter your name : ";
			cin>>names[i-1];
		}
	}
	else if( (nplayers>=2)&&(nplayers<=4)&&(pcolors[nplayers-1]!=-1)) 
	{
		cout<<"Setup completed";
		gamestart=1;
	}

}

void updateturn()
{
	if(turn==nplayers)
	turn=1;
	else
	turn++;

}

void AddMove(int arr[3],int f)
{
	if(arr[0]==0)
	{
		arr[0]=f;
	}
	else if (arr[1]==0)
	{
		arr[1]=f;
	}
	else if(arr[2]==0)
	{
		arr[2]=f;
	}

}

bool bufempty (int arr[3])
{
	for(int i=0;i<3;i++)
	{
		if(arr[i]!=0)
		return false;
		return true;	
	}
}

int popbuf (int arr[3],int f)
{
	if(arr[0]==f)
	{
		arr[0]=0;
		return f;
	}
	else if (arr[1]==f)
	{
		arr[1]=0;
		return f;
	}
	else if(arr[2]==f)
	{
		arr[2]=0;
		return f;
	}
	else
	{
		cout<<"This number is not accecptable";
	}

}

void GameDisplay()/**/
{
	
	if(gamestart!=0)
	{
	glClearColor(0, 0,0,1);
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	board();
	DrawString(10,650," Made by: Shayan Bakht ",colors[RED]);
	string player="TURN : Player "+ names[turn-1];
	DrawString(10,600,player,colors[GREEN]);
	string dice= "You Rolled : " + to_string(nn);
	DrawString(10,550,dice,colors[BLUE]);
	DrawLine(10,530,440,530,1.0);
	DrawAll();
	string doo = to_string(selectedKey);
	DrawString(300,550,doo,colors[WHITE]);
	//cout<<"BLUE : "<<blue[test]<<endl;
	string s1 = "Score Blue :"   + to_string(scoreb);
	string s2 = "Score Yellow :"  +  to_string(scorey);
	string s3 = "Score Red :"  +  to_string(scorer);
	string s4 = "Score Green :"  +  to_string(scoreg);
	
	DrawString(650,600,s1,colors[BLUE]);
	DrawString(650,550,s2,colors[YELLOW]);
	DrawString(650,500,s3,colors[RED]);
	DrawString(650,450,s4,colors[GREEN]);
	
	}
	else
	{ 
	playercountsetup();	
	playercolorsetup();
	}
	
	glutSwapBuffers(); // do not modify this line..
}
	
/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {

	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {

	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {

	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}
//Defining Functions to Unlock locked Keys
bool unlockBlue()
{
	if(blue[0]==-1)
	{blue[0]=0; return true;}
	else if(blue[1]==-1)
	{ blue[1]=0; return true;}
	else if(blue[2]==-1)
	{ blue[2]=0; return true;}
	else if(blue[3]==-1)
	{ blue[3]=0; return true;}
	else
	{return false;}
}
bool unlockYellow()
{
	if(yellow[0]==-1)
	{yellow[0]=0; return true;}
	else if(yellow[1]==-1)
	{ yellow[1]=0; return true;}
	else if(yellow[2]==-1)
	{ yellow[2]=0; return true;}
	else if(yellow[3]==-1)
	{ yellow[3]=0; return true;}
	else
	{return false;}
}
bool unlockRed()
{
	if(red[0]==-1)
	{red[0]=0; return true;}
	else if(red[1]==-1)
	{ red[1]=0; return true;}
	else if(red[2]==-1)
	{ red[2]=0; return true;}
	else if(red[3]==-1)
	{ red[3]=0; return true;}
	else
	{return false;}
}
bool unlockGreen()
{
	if(green[0]==-1)
	{green[0]=0; return true;}
	else if(green[1]==-1)
	{ green[1]=0; return true;}
	else if(green[2]==-1)
	{ green[2]=0; return true;}
	else if(green[3]==-1)
	{ green[3]=0; return true;}
	else
	{return false;}
}

bool decideUnlock()
{
	if(turn==1)
	{
		if(pcolors[0] == 0)
		{return unlockBlue();}
		else if(pcolors[0] == 1)
		{return unlockYellow();}
		else if(pcolors[0] == 2)
		{return unlockRed();}
		else if(pcolors[0] == 3)
		{return unlockGreen();}
	}
	else if (turn ==2)
	{
		if(pcolors[1] == 0)
		{return unlockBlue();}
		else if(pcolors[1] == 1)
		{return unlockYellow();}
		else if(pcolors[1] == 2)
		{return unlockRed();}
		else if(pcolors[1] == 3)
		{return unlockGreen();}
	}
	else if(turn == 3)
	{
		if(pcolors[2] == 0)
		{return unlockBlue();}
		else if(pcolors[2] == 1)
		{return unlockYellow();}
		else if(pcolors[2] == 2)
		{return unlockRed();}
		else if(pcolors[2] == 3)
		{return unlockGreen();}
	}
	else if(turn == 4)
	{
		if(pcolors[3] == 0)
		{return unlockBlue();}
		else if(pcolors[3] == 1)
		{return unlockYellow();}
		else if(pcolors[3] == 2)
		{return unlockRed();}
		else if(pcolors[3] == 3)
		{return unlockGreen();}
	}
}

int findIndex(int arr[4],int f)
{
	if (arr[0]==f)
	{return 0;}
	else if (arr[1] ==f)
	{return 1;}
	else if (arr[2] ==f)
	{return 2;}
	else if (arr[3] ==f)
	{return 3;}
	else
	{return -1;}
}
// Adding Movements
bool moveBlue(int k,int g)
{ //value, g numbers to move
	//finding piece based on value k
	int f = findIndex(blue,k);
	test = f;
	if(f!=-1)
	{
	if(blue[f]!=-1)
	{ 
		if((torrB==false))
		{
			
			if((blue[f]+g)<=46){
	 		blue[f]+=g;
	 		scoreb+=g;
	 		return true;}
	 	}
	 	else if((torrB==true))
	 	{	
	 		if ((blue[f]+g)<=52)
	 		{
	 			blue[f]+=g;
	 			scoreb+=g;
	 			if(blue[f]==52)
	 				blue[f]=-2;
	 				//scoreb+=15;
	 			return true;
	 		}
	 	}
	 	else
	 	return false;
	}
	}
	else
	return false;
	
}

bool moveYellow(int k,int g)
{ //value, g numbers to move
	//finding piece based on value k
	int f = findIndex(yellow,k);
	if(yellow[f]!=-1)
	{ 
		if((torrY==false))
		{
			
			if((yellow[f]+g)<=46){
	 		yellow[f]+=g;
	 		scorey+=g;
	 		return true;}
	 	}
	 	else if((torrY==true))
	 	{	
	 		if ((yellow[f]+g)<=52)
	 		{
	 			yellow[f]+=g;
	 			scorey+=g;
	 			if(yellow[f]==51)
	 			{
	 				yellow[f]=-2;
	 				scorey+=15;
	 			}
	 			return true;
	 		}
	 	}
	 	else
	 	return false;
	}
	else
	return false;
}

bool moveRed(int k,int g)
{ //value, g numbers to move
	//finding piece based on value k
	int f = findIndex(red,k);
	if(red[f]!=-1)
	{ 
		if((torrR==false))
		{
			
			if((red[f]+g)<=46){
	 		red[f]+=g;
	 		scorer+=g;
	 		return true;}
	 	}
	 	else if((torrR==true))
	 	{	
	 		if ((red[f]+g)<=52)
	 		{
	 			red[f]+=g;
	 			scorer+=g;
	 			if(red[f]==52)
	 			{
	 				scorer+=15;
	 				red[f]=-2;
	 			}

	 			return true;
	 		}
	 	}
	 	else
	 	return false;
	}
	else
	return false;
}

bool moveGreen(int k,int g)
{ //value, g numbers to move
	//finding piece based on value k
	int f = findIndex(green,k);
	if(green[f]!=-1)
	{ 
		if((torrG==false))
		{
			
			if((green[f]+g)<=46){
	 		green[f]+=g;
	 		scoreg+=g;
	 		return true;}
	 	}
	 	else if((torrG==true))
	 	{	
	 		if ((green[f]+g)<=52)
	 		{
	 			green[f]+=g;
	 			scoreg+=g;
	 			if(green[f]==52)
	 			{
	 				scoreg+=15;
	 				green[f]=-2;
	 			}
	 			return true;
	 		}
	 	}
	 	else
	 	return false;
	}
	else
	return false;
}

bool decideMove(int f,int g)
{
	if(turn==1)
	{
		if(pcolors[0] == 0)
		{return moveBlue(f, g);}
		else if(pcolors[0] == 1)
		{return moveYellow(f, g);}
		else if(pcolors[0] == 2)
		{return moveRed(f, g);}
		else if(pcolors[0] == 3)
		{return moveGreen(f, g);}
	}
	else if (turn ==2)
	{
		if(pcolors[1] == 0)
		{return moveBlue(f, g);}
		else if(pcolors[1] == 1)
		{return moveYellow(f, g);}
		else if(pcolors[1] == 2)
		{return moveRed(f, g);}
		else if(pcolors[1] == 3)
		{return moveGreen(f, g);}
	}
	else if(turn == 3)
	{
		if(pcolors[2] == 0)
		{return moveBlue(f, g);}
		else if(pcolors[2] == 1)
		{return moveYellow(f, g);}
		else if(pcolors[2] == 2)
		{return moveRed(f, g);}
		else if(pcolors[2] == 3)
		{return moveGreen(f, g);}
	}
	else if(turn == 4)
	{
		if(pcolors[3] == 0)
		{return moveBlue(f, g);}
		else if(pcolors[3] == 1)
		{return moveYellow(f, g);}
		else if(pcolors[3] == 2)
		{return moveRed(f, g);}
		else if(pcolors[3] == 3)
		{return moveGreen(f, g);}
	}
}

float distanceFormula(int x1, int y1, int x2, int y2)
{
	int p1 = pow(x2-x1,2);
	int  p2 = pow(y2-y1,2);
	float d = sqrt(p1+p2)*1.0;
	return d; 
}


int blueFinder(int x, int y)
{
	int d1=999,d2=999,d3=999,d4=999;
	if(torrB ==0)
	{
		if(blue[0]>-1)
			d1 = distanceFormula(GB[blue[0]][0], GB[blue[0]][1], x, y);
		if(blue[1]>-1)
			d2 = distanceFormula(GB[blue[1]][0], GB[blue[1]][1], x, y);
		if(blue[2]>-1)
			d3 = distanceFormula(GB[blue[2]][0], GB[blue[2]][1], x, y);
		if(blue[3]>-1)
			d4 = distanceFormula(GB[blue[3]][0], GB[blue[3]][1], x, y);
		if (d1<d2 && d1<d3 && d1<d4)
			{return blue[0];}
		else if (d2<d1 && d2<d3 && d2<d4)
			{return blue[1];}
		else if (d3<d1 && d3<d2 && d3<d4)
			{return blue[2];}
		else if (d4<d1 && d4<d3 && d4<d2)
			{return blue[3];}
		
	
	}
	else
	{
		if(blue[0]>-1)
			d1 = distanceFormula(SB[blue[0]][0], SB[blue[0]][1], x, y);
		if(blue[1]>-1)
			d2 = distanceFormula(SB[blue[1]][0], SB[blue[1]][1], x, y);
		if(blue[2]>-1)
			d3 = distanceFormula(SB[blue[2]][0], SB[blue[2]][1], x, y);
		if(blue[3]>-1)
			d4 = distanceFormula(SB[blue[3]][0], SB[blue[3]][1], x, y);
		if (d1<d2 && d1<d3 && d1<d4)
			{return blue[0];}
		else if (d2<d1 && d2<d3 && d2<d4)
			{return blue[1];}
		else if (d3<d1 && d3<d2 && d3<d4)
			{return blue[2];}
		else if (d4<d1 && d4<d3 && d4<d2)
			{return blue[3];}
	
	}
}

int yellowFinder(int x, int y)
{
	int d1=999,d2=999,d3=999,d4=999;
	if(torrY ==0)
	{
		if(yellow[0]>-1)
			d1 = distanceFormula(GY[yellow[0]][0], GY[yellow[0]][1], x, y);
		if(yellow[1]>-1)
			d2 = distanceFormula(GY[yellow[1]][0], GY[yellow[1]][1], x, y);
		if(yellow[2]>-1)
			d3 = distanceFormula(GY[yellow[2]][0], GY[yellow[2]][1], x, y);
		if(yellow[3]>-1)
			d4 = distanceFormula(GY[yellow[3]][0], GY[yellow[3]][1], x, y);
		if (d1<d2 && d1<d3 && d1<d4)
			{return yellow[0];}
		else if (d2<d1 && d2<d3 && d2<d4)
			{return yellow[1];}
		else if (d3<d1 && d3<d2 && d3<d4)
			{return yellow[2];}
		else if (d4<d1 && d4<d3 && d4<d2)
			{return yellow[3];}
		
	
	}
	else
	{
		if(yellow[0]>-1)
			d1 = distanceFormula(SY[yellow[0]][0], SY[yellow[0]][1], x, y);
		if(yellow[1]>-1)
			d2 = distanceFormula(SY[yellow[1]][0], SY[yellow[1]][1], x, y);
		if(yellow[2]>-1)
			d3 = distanceFormula(SY[yellow[2]][0], SY[yellow[2]][1], x, y);
		if(yellow[3]>-1)
			d4 = distanceFormula(SY[yellow[3]][0], SY[yellow[3]][1], x, y);
		if (d1<d2 && d1<d3 && d1<d4)
			{return yellow[0];}
		else if (d2<d1 && d2<d3 && d2<d4)
			{return yellow[1];}
		else if (d3<d1 && d3<d2 && d3<d4)
			{return yellow[2];}
		else if (d4<d1 && d4<d3 && d4<d2)
			{return yellow[3];}
	
	}
}

int redFinder(int x, int y)
{
	int d1=999,d2=999,d3=999,d4=999;
	if(torrR ==0)
	{
		if(red[0]>-1)
			d1 = distanceFormula(GR[red[0]][0], GR[red[0]][1], x, y);
		if(red[1]>-1)
			d2 = distanceFormula(GR[red[1]][0], GR[red[1]][1], x, y);
		if(red[2]>-1)
			d3 = distanceFormula(GR[red[2]][0], GR[red[2]][1], x, y);
		if(red[3]>-1)
			d4 = distanceFormula(GR[red[3]][0], GR[red[3]][1], x, y);
		if (d1<d2 && d1<d3 && d1<d4)
			{return red[0];}
		else if (d2<d1 && d2<d3 && d2<d4)
			{return red[1];}
		else if (d3<d1 && d3<d2 && d3<d4)
			{return red[2];}
		else if (d4<d1 && d4<d3 && d4<d2)
			{return red[3];}
		
	
	}
	else
	{
		if(red[0]>-1)
			d1 = distanceFormula(SR[red[0]][0], SR[red[0]][1], x, y);
		if(red[1]>-1)
			d2 = distanceFormula(SR[red[1]][0], SR[red[1]][1], x, y);
		if(red[2]>-1)
			d3 = distanceFormula(SR[red[2]][0], SR[red[2]][1], x, y);
		if(red[3]>-1)
			d4 = distanceFormula(SR[red[3]][0], SR[red[3]][1], x, y);
		if (d1<d2 && d1<d3 && d1<d4)
			{return red[0];}
		else if (d2<d1 && d2<d3 && d2<d4)
			{return red[1];}
		else if (d3<d1 && d3<d2 && d3<d4)
			{return red[2];}
		else if (d4<d1 && d4<d3 && d4<d2)
			{return red[3];}
	
	}
}

int greenFinder(int x, int y)
{
	int d1=999,d2=999,d3=999,d4=999;
	if(torrG ==0)
	{
		if(green[0]>-1)
			d1 = distanceFormula(GG[green[0]][0], GG[green[0]][1], x, y);
		if(green[1]>-1)
			d2 = distanceFormula(GG[green[1]][0], GG[green[1]][1], x, y);
		if(green[2]>-1)
			d3 = distanceFormula(GG[green[2]][0], GG[green[2]][1], x, y);
		if(green[3]>-1)
			d4 = distanceFormula(GG[green[3]][0], GG[green[3]][1], x, y);
		if (d1<d2 && d1<d3 && d1<d4)
			{return green[0];}
		else if (d2<d1 && d2<d3 && d2<d4)
			{return green[1];}
		else if (d3<d1 && d3<d2 && d3<d4)
			{return green[2];}
		else if (d4<d1 && d4<d3 && d4<d2)
			{return green[3];}
		
	
	}
	else
	{
		if(green[0]>-1)
			d1 = distanceFormula(SG[green[0]][0], SG[green[0]][1], x, y);
		if(green[1]>-1)
			d2 = distanceFormula(SG[green[1]][0], SG[green[1]][1], x, y);
		if(green[2]>-1)
			d3 = distanceFormula(SG[green[2]][0], SG[green[2]][1], x, y);
		if(green[3]>-1)
			d4 = distanceFormula(SG[green[3]][0], SG[green[3]][1], x, y);
		if (d1<d2 && d1<d3 && d1<d4)
			{return green[0];}
		else if (d2<d1 && d2<d3 && d2<d4)
			{return green[1];}
		else if (d3<d1 && d3<d2 && d3<d4)
			{return green[2];}
		else if (d4<d1 && d4<d3 && d4<d2)
			{return green[3];}
	
	}
}
int decideSelection(int x, int y)
{
	y = 700 - y;
	if (turn == 1)
	{
		if(pcolors[0]==0)
		{return blueFinder(x,y);}
		else if(pcolors[0]==1)
		{return yellowFinder(x,y);}
		else if(pcolors[0]==2)
		{return redFinder(x,y);}
		else if(pcolors[0]==3)
		{return greenFinder(x,y);}
	}
	else if (turn == 2)
	{
		if(pcolors[1]==0)
		{return blueFinder(x,y);}
		else if(pcolors[1]==1)
		{return yellowFinder(x,y);}
		else if(pcolors[1]==2)
		{return redFinder(x,y);}
		else if(pcolors[1]==3)
		{return greenFinder(x,y);}
	}
	else if (turn == 3)
	{
		if(pcolors[2]==0)
		{return blueFinder(x,y);}
		else if(pcolors[2]==1)
		{return yellowFinder(x,y);}
		else if(pcolors[2]==2)
		{return redFinder(x,y);}
		else if(pcolors[2]==3)
		{return greenFinder(x,y);}
	}
	else if (turn == 4)
	{
		if(pcolors[3]==0)
		{return blueFinder(x,y);}
		else if(pcolors[3]==1)
		{return yellowFinder(x,y);}
		else if(pcolors[3]==2)
		{return redFinder(x,y);}
		else if(pcolors[3]==3)
		{return greenFinder(x,y);}
	}
}
bool isTorrB()
{
	for(int i = 0; i<4; i++)
	{
		if ((blue[i]!=0 || blue[i]!=7 || blue[i]!=12 || blue[i]!=19 || blue[i]!=24 || blue[i]!=31 || blue[i]!=36 || blue[i]!=43) && (blue[i]>-1))
		{
			int s = blue[i];
			for(int j=0; j<4; j++)
			{
				int sa = yellow[j];
				int x1 = GB[s][0];
				int y1 = GB[s][1];
				int x2 = GY[sa][0];
				int y2 = GY[sa][1];
				if((x1 == x2) && (y1==y2))
				{yellow[j] = -1;
				scoreb+=10;
				return true;}	
			}
			for(int j=0; j<4; j++)
			{
				int sa = red[j];
				int x1 = GB[s][0];
				int y1 = GB[s][1];
				int x2 = GR[sa][0];
				int y2 = GR[sa][1];
				if((x1 == x2) && (y1==y2))
				{red[j] = -1;
				scoreb+=10;
				return true;}	
			}
			for(int j=0; j<4; j++)
			{
				int sa = green[j];
				int x1 = GB[s][0];
				int y1 = GB[s][1];
				int x2 = GG[sa][0];
				int y2 = GG[sa][1];
				if((x1 == x2) && (y1==y2))
				{green[j] = -1;
				scoreb+=10;
				return true;}	
			}
		}
	}
}

bool isTorrY()
{
	for(int i = 0; i<4; i++)
	{
		if ((yellow[i]!=0 || yellow[i]!=7 || yellow[i]!=12 || yellow[i]!=19 || yellow[i]!=24 || yellow[i]!=31 || yellow[i]!=36 || yellow[i]!=43) && (yellow[i]>-1))
		{
			int s = yellow[i];
			for(int j=0; j<4; j++)
			{
				int sa = blue[j];
				int x1 = GY[s][0];
				int y1 = GY[s][1];
				int x2 = GB[sa][0];
				int y2 = GB[sa][1];
				if((x1 == x2) && (y1==y2))
				{blue[j] = -1;
				scorey+=10;
				return true;}	
			}
			for(int j=0; j<4; j++)
			{
				int sa = red[j];
				int x1 = GY[s][0];
				int y1 = GY[s][1];
				int x2 = GR[sa][0];
				int y2 = GR[sa][1];
				if((x1 == x2) && (y1==y2))
				{red[j] = -1;
				scorey+=10;
				return true;}	
			}
			for(int j=0; j<4; j++)
			{
				int sa = green[j];
				int x1 = GY[s][0];
				int y1 = GY[s][1];
				int x2 = GG[sa][0];
				int y2 = GG[sa][1];
				if((x1 == x2) && (y1==y2))
				{green[j] = -1;
				scorey+=10;
				return true;}	
			}
		}
	}
}

bool isTorrR()
{
	for(int i = 0; i<4; i++)
	{
		if ((red[i]!=0 || red[i]!=7 || red[i]!=12 || red[i]!=19 || red[i]!=24 || red[i]!=31 || red[i]!=36 || red[i]!=43) && (red[i]>-1))
		{
			int s = red[i];
			for(int j=0; j<4; j++)
			{
				int sa = blue[j];
				int x1 = GR[s][0];
				int y1 = GR[s][1];
				int x2 = GB[sa][0];
				int y2 = GB[sa][1];
				if((x1 == x2) && (y1==y2))
				{blue[j] = -1;
				scorer+=10;
				return true;}	
			}
			for(int j=0; j<4; j++)
			{
				int sa = yellow[j];
				int x1 = GR[s][0];
				int y1 = GR[s][1];
				int x2 = GY[sa][0];
				int y2 = GY[sa][1];
				if((x1 == x2) && (y1==y2))
				{yellow[j] = -1;
				scorer+=10;
				return true;}	
			}
			for(int j=0; j<4; j++)
			{
				int sa = green[j];
				int x1 = GR[s][0];
				int y1 = GR[s][1];
				int x2 = GG[sa][0];
				int y2 = GG[sa][1];
				if((x1 == x2) && (y1==y2))
				{green[j] = -1;
				scorer+=10;
				return true;}	
			}
		}
	}
}

bool isTorrG()
{
	for(int i = 0; i<4; i++)
	{
		if ((green[i]!=0 || green[i]!=7 || green[i]!=12 || green[i]!=19 || green[i]!=24 || green[i]!=31 || green[i]!=36 || green[i]!=43) && (green[i]>-1))
		{
			int s = green[i];
			for(int j=0; j<4; j++)
			{
				int sa = blue[j];
				int x1 = GG[s][0];
				int y1 = GG[s][1];
				int x2 = GB[sa][0];
				int y2 = GB[sa][1];
				if((x1 == x2) && (y1==y2))
				{blue[j] = -1;
				scoreg+=10;				
				return true;}	
			}
			for(int j=0; j<4; j++)
			{
				int sa = yellow[j];
				int x1 = GG[s][0];
				int y1 = GG[s][1];
				int x2 = GY[sa][0];
				int y2 = GY[sa][1];
				if((x1 == x2) && (y1==y2))
				{yellow[j] = -1;
				scorey+=10;
				return true;}	
			}
			for(int j=0; j<4; j++)
			{
				int sa = red[j];
				int x1 = GG[s][0];
				int y1 = GG[s][1];
				int x2 = GR[sa][0];
				int y2 = GR[sa][1];
				if((x1 == x2) && (y1==y2))
				{red[j] = -1;
				scorey+=10;
				return true;}	
			}
		}
	}
}
void decideTorr()
{
	if (turn == 1)
	{
		if(pcolors[0]==0)
			torrB = isTorrB();
		else if(pcolors[0]==1)
			torrY = isTorrY();
		else if(pcolors[0]==2)
			torrR = isTorrR();
		else if(pcolors[0]==3)
			torrG = isTorrG();
	}
	else if (turn == 2)
	{
		if(pcolors[1]==0)
			torrB = isTorrB();
		else if(pcolors[1]==1)
			torrY = isTorrY();
		else if(pcolors[1]==2)
			torrR = isTorrR();
		else if(pcolors[1]==3)
			torrG = isTorrG();
	
	}
	else if (turn == 3)
	{
		if(pcolors[2]==0)
			torrB = isTorrB();
		else if(pcolors[2]==1)
			torrY = isTorrY();
		else if(pcolors[2]==2)
			torrR = isTorrR();
		else if(pcolors[2]==3)
			torrG = isTorrG();
	
	}
	else if (turn == 4)
	{
		if(pcolors[3]==0)
			torrB = isTorrB();
		else if(pcolors[3]==1)
			torrY = isTorrY();
		else if(pcolors[3]==2)
			torrR = isTorrR();
		else if(pcolors[3]==3)
			torrG = isTorrG();
	}
}
/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}
	
	if (key == 32) //Key for generating random number (ascii for spacebar
	{
		nn = GetRandInRange(1, 7);
		cout << nn << endl;

	}
	if ((key == 48) && (nn == 6))
	{
		decideUnlock();
	}
	if ((key == 49) && (nn == 1))
	{
		decideMove(selectedKey,nn);
		//decideTorr();
		updateturn();
	}
	if ((key == 50) && (nn == 2))
	{
		decideMove(selectedKey,nn);
		//decideTorr();
		updateturn();
	}
	if ((key == 51) && (nn == 3))
	{
		decideMove(selectedKey,nn);
		//decideTorr();
		updateturn();
	}
	if ((key == 52) && (nn == 4))
	{
		decideMove(selectedKey,nn);
		//decideTorr();
		updateturn();
	}
	if ((key == 53) && (nn == 5))
	{
		decideMove(selectedKey,nn);
		//decideTorr();
		updateturn();
	}
	if ((key == 54) && (nn == 6))
	{
		decideMove(selectedKey,nn);
		//decideTorr();
		
	}
	
	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000.0, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
			selectedKey = decideSelection(x,y);
		cout << GLUT_DOWN << " "<< GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {
 

	
	//b = new Board(60, 60); // create a new board object to use in the Display Function ...

	int width = 1020, height = 700; // i have set my window size to be 800 x 600
	//b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("PF Project"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	
	
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
