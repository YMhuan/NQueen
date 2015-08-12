#include<iostream>
#include<conio.h>
#include<time.h>
using namespace std;
//int number;
//*****************************************************************
class nqueen
{
	int n;
	int chessboard_size;
public:
//*****************************************************************
	void userinput()// user input 
	{
		cout<<"THE N-QUEEN PUZZLE BY RANDOM RESTART HILL CLIMBING"<<endl<<endl;
		cout<<"Please enter the number of queens\n"<<endl;
        cin>>chessboard_size;
		cout<<endl;
	}
//*****************************************************************
	void board()//assigns the queens to the board
	{
		int c[100][100],k,rand_counter=0;
		int i,j,column;
		int moves=0;
		for(i=1;i<=chessboard_size;i++)
		{
			for(j=1;j<=chessboard_size;j++)
			{
				c[i][j]=0;
			}
		}
		for(j=1;j<=chessboard_size;j++)
			c[1][j]=1;
		/*c[1][3]=1;
		c[2][1]=1;
		c[3][4]=1;
		c[4][2]=1;*/
		/*print_board(c);
		cout<<endl;
		cout<<heuristic(c)<<endl;*/
		/*random_restart(c);
		cout<<endl;
		random_restart(c);

		cout<<endl;
		random_restart(c);

		cout<<endl;

		move_queen(c,2);*/
		while(heuristic(c)!=0)
		{
			for(int column=1;column<=chessboard_size;column++)
			{
				move_queen(c,column);
				moves++;
				if(heuristic(c)==0)
					break;
			}
			random_restart(c);
			rand_counter++;
		}
		cout<<endl<<"Solution is: "<<endl<<endl;
		print_board(c);
		cout<<endl;
		cout<<"# of Random restarts: "<<rand_counter;
		cout<<endl<<endl;
		cout<<"# of Steps: "<<moves;


	}
//***********************************************************************************
void random_restart(int c[100][100])//resets the queeens in random positions in the chessboard
	{
		int x_coord=0;
		int y_coord=0;
		for(int i=1;i<=chessboard_size;i++)
		{
			for(int j=1;j<=chessboard_size;j++)
			{
				c[i][j]=0;
			}
		}
		/*while(count_queens(c)!=chessboard_size)
		{*/
			for(int i=1;i<=chessboard_size;i++)
			{
				x_coord=rand()%chessboard_size+1;
		

				
				/*y_coord=rand()%chessboard_size+1;
				cout<<endl<<"Y   "<<" "<<y_coord<<endl;*/
				c[x_coord][i]=1;
			}
		/*}*/
	}
//***********************************************************************************
int count_queens(int c[100][100])//counts the number of queens on board
{
	int counter=0;
	for(int i=1;i<=chessboard_size;i++)//determining x and y coordinates of queens
	{
		for(int j=1;j<=chessboard_size;j++)
		{
			if(c[i][j]==1)
			{
				counter++;
			}
		}
	}
	return counter;
}
//***********************************************************************************
void print_board(int c[100][100])//prints the n*n chess board
	{
		int i,j;
		for(i=1;i<=chessboard_size;i++)
		{
			for(j=1;j<=chessboard_size;j++)
			{
				cout<<c[i][j]<<" ";
			}
			cout<<endl;
			cout<<endl;
		}
	}
//************************************************************************************
int heuristic(int c[100][100])//calculates the heuristic for the chessboard(which is the number of queens colliding)
{
	int x[100];
	int y[100];
	int tempx=0;
	int tempy=0;
	int i=0,j=0;
	int k=1;
	int conflict=0;
	for(i=1;i<=chessboard_size;i++)//determining x and y coordinates of queens
	{
		for(j=1;j<=chessboard_size;j++)
		{
			if(c[i][j]==1)
			{
				tempx=i;
				x[k]=i;
				tempx=0;
				tempy=j;
				y[k]=j;
				tempy=0;
				k++;//run loop <k means k-1 queens
			}
		}
	}
	//(x[i]+y[i]==x[j]+y[j])
	/*for(i=1;i<k;i++)
	{
		cout<<x[i]<<" ";
	}
	cout<<endl;
	for(i=1;i<k;i++)
	{
		cout<<y[i]<<" ";
	}*/
	for(i=1;i<k;i++)
	{
		for(j=i+1;j<k;j++)
		{
			if((y[i]==y[j])||(x[i]==x[j])||(abs(x[i]-x[j])==abs(y[i]-y[j])))
			{
				conflict++;
			}
		}
	}
	return conflict;
}
void move_queen(int c[100][100],int column)// checks the heuristic value and moves the queen accordingly
{
	int row;
	int moves=0;
	int c_prev[100][100];
	for(int i=1;i<=chessboard_size;i++)
		{
			for(int j=1;j<=chessboard_size;j++)
			{
				c_prev[i][j]=c[i][j];
			}
		}
	for(row=1;row<=chessboard_size;row++)
	{
		if(c[row][column]==1)
		{
			if(row!=chessboard_size)
			{
				c[row][column]=0;
				c[row+1][column]=1;
			}
			else
			{
				c[row][column]=0;
				c[1][column]=1;
			}

			break;
		}
	}
	if(heuristic(c)>heuristic(c_prev))
	{
		for(int i=1;i<=chessboard_size;i++)
		{
			for(int j=1;j<=chessboard_size;j++)
			{
				c[i][j]=c_prev[i][j];
			}
		}
	}
	/*cout<<"Heuristic(c) "<<heuristic(c)<<endl;
	cout<<"Heuristic(c_prev) "<<heuristic(c_prev)<<endl;*/
	/*cout<<endl<<endl<<"Moving queen "<<endl<<endl;
	print_board(c);*/
	
}
//*****************************************************************************************************************
};
int main()//main function
{
	srand ( time(NULL) );
	nqueen obj;
	obj.userinput();
	obj.board();
	getch();
}
