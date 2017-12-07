#include <bits/stdc++.h>
#include <ncurses.h>
using namespace std;
struct state{
	string cur_stat;
	state *next;
	state()
	{
		cur_stat="";
		next=NULL;
		if_arrow_state=false;
	}
};
// declared as global variables for accesibility from functions
state *top = NULL;
state *redotop = NULL;

void psedopushintoredo(string content)
// the objective of this function is just to create a new node in the linked redo stack whose parameter cur_stat value is to be set to content 
{
      /*state *redotemp = new state;
      if(redotemp)
      {
        redotemp->next=redotop;
        redotemp->cur_stat=content;
        redotop=redotemp;
      }
      else
        printw("Overflow");*/
}

void psedopushintoundo(string content)
// the objective of this function is just to create a new node in the linked undo stack whose parameter cur_stat value is to be set to content 
{
  /*state *temp = new state;
  if(temp)
  {
    temp->next = top;
    top = temp;
    top->cur_stat=content;
  }
  else
    printw("Overflow");*/
}

int main()
{   
	int j,space_hit=0;
	char ch;
	string buffer; 
	buffer="";
	top = new state;
	redotop = new state;
	initscr();
  printw("Hit + to exit the editor ) for undo and ( for redo\n");
	printw("Hit space to go to your very own editor");
  refresh();
  getch();
  clear();
	 do
	 {
	     ch=getch();
	  
       if(ch==' ')
	     {  
		       buffer=buffer+ch; // buffer stores values that are entered so that when the next space is hit these values along with the space are pushed into the undo stack
           if(!space_hit)   //to check for non consecutive space hits 
		       {
			         space_hit=1;
               psedopushintoundo(top->cur_stat+buffer);
	             buffer="";
           }
        }

       else if(ch==')') // call to undo 
       {
    		  clear();
    	    refresh();
    	    if(buffer=="")  //if buffer not present pop top element of undo stack and display
          {
              if(top->next!=NULL)
              {
        	        psedopushintoredo(top->cur_stat);    //push the top element of undo stack to the redo stack
        	        top=top->next;                      // pop top element of the undo stack
        	        printw("%s",top->cur_stat.c_str());
              }
          }
          
          else //if buffer present update redo stack with this buffer and print the undo stack without the buffer/previous state
          {
        	    if(top->next)
        	    {
        		      printw("%s",top->cur_stat.c_str());
        		      psedopushintoredo(top->cur_stat+buffer);
        	    }    
          }

    	    buffer="";
    	    space_hit=0;
       }
    
        else if(ch=='(')  //call to redo
        {
    	
    	      if (redotop->next!=NULL)
    	      {
    		        clear();
    		        printw("%s",redotop->cur_stat.c_str());
    		        refresh();
    		        psedopushintoundo(redotop->cur_stat);
    		        redotop=redotop->next;
    	      }
    	      
            else
    	     {
    		       clear();
    		       string g = top->cur_stat + buffer;
    		       printw("%s",g.c_str());
    		       refresh();
    	     }


       }
    
       else // a key other than undo,redo and space
    	 {
    		    buffer=buffer+ch;
    		    space_hit=0;
       }

  }while(ch!='+');
    
  endwin(); // end graphics mode
  return 0;
}

