/*
 *  DVR
 *  Author : Gourav
 */

#include<iostream>
using namespace std;

class DVR
{
private:
  int Total; 						//Total number of routers in subnet
  int Target; 						//Router whose table is to be found/calculated
  int **Adjacent; 					//Adjacency matrix showing which all routers are adjacent, dim = Total X Total
  int ***Table; 					//Table of each router showing (router, distance, outgoing line)
public:
  void getdata(); 					//Enter data and make Adjacent[Total][Total] and Table[Total][Total][3]
  void updateTarget();				//Update Target router table
  void updateTargetAdj();			//Update the Table of neighbours of Target
  void print();
};

void DVR::getdata()
{
  cout<<"Enter the total routers in the subnet (Max-10):";
  cin>>Total;
  
  cout<<"\r\n\n"<<"The routers are numbered starting with 0 "<<"\n";
  
  for(int i = 0; i <= Total-1; i++)
   cout<<i<<"\t";

  cout<<"\n"<<"Enter the number of the router (Target Router) whose routing table is to be found";
  cout<<"\n"<<"Please assume first router is named 0 : ";
  cin>>Target;

  Adjacent = new int*[Total];				//Creating Adjacent[Total][Total]
  for(int i = 0 ; i <= Total-1; i++)
   	Adjacent[i] = new int[Total]; 		

  cout<<"\n Enter the distance of adjacent/non-adjacent routers";
  cout<<"\n Enter 0 if its a Self Distance \n";
  cout<<"\n Enter actual distance if directly connected (adjacent) \n";
  cout<<"\n Enter -1 if not directly connected (non-adjacent)";


  for(int i = 0; i<= Total-1; i++)
  {
   cout<<"\n Please enter for router number " << i << endl;
   for(int j = 0; j<= Total-1; j++)
   {
    cout << "\n Enter distance from router number" << j << ":";
    cin>>Adjacent[i][j];
    cout<<endl;
   }
  }

  Table = new int **[Total] ; 				//Creating Table[Total][Total][3] 
  for(int i = 0 ; i<= Total-1; i++)			//Table[i][j][0] gives router number = router number j
   	Table[i] = new int*[Total]; 			//Table[i][j][1] gives distance of router i to router j	
   	
  for(int i = 0 ; i<= Total-1; i++)			//Table[i][j][2] gives outgoing line from router i to router j
   for(int j = 0 ; j<= Total-1; j++)		//Each router's table has an entry for every other router
     Table[i][j] = new int[3];


  
for(int i = 0 ; i<= Total-1; i++)			//Fill up initial Table[][][]
   {
    for (int j = 0 ; j<= Total-1; j++)
    {
     if( Adjacent[i][j] >= 0 )				//Clearly, router j is directly connected to router i
     {
      Table[i][j][0] = j;					//First entry is router number j
      Table[i][j][1] = Adjacent[i][j];		//Second entry is the direct distance from router i to router j 
      Table[i][j][2] = j;					//Third entry, since directly connected, hence outgoing line = j
     }
     else
     {
      Table[i][j][0] = j;					//First entry is router number j
      Table[i][j][1] = 32000; 				//Second entry denotes infinity, as i and j are not directly connected
      Table[i][j][2] = -1; 					//Third entry denotes outgoing line that does not exist right now.
     }
    }
  }
  print();
}

void DVR::updateTarget()
{
 for(int i = 0 ; i<= Total - 1; i++)
 	if(Adjacent[Target][i] > 0) 			//If > 0, then router i is adjacent to Target router
   		for(int j = 0 ; j<= Total - 1; j++)
    		if( Table[Target][j][1] > Table[i][j][1] + Adjacent[Target][i] )
    		{
      			Table[Target][j][1] = Table[i][j][1] + Adjacent[Target][i];
      			Table[Target][j][2] = i;
    		}
}

void DVR::updateTargetAdj()
{
 for(int i = 0 ; i <= Total - 1; i++)
 {
  if(Adjacent[Target][i] > 0 ) 				//Determining routers adjacent to Target
  {
   for(int j = 0 ; j <= Total - 1; j++)
   {
    if( Adjacent[i][j] > 0 ) 				//Determining routers adjacent to router i
    {
      for(int k = 0; k<= Total - 1; k++)
      {
       if(Table[i][k][1] > Table[j][k][1] + Adjacent[i][j] )
       {
		Table[i][k][1] = (Table[j][k][1] + Adjacent[i][j]);
		Table[i][k][2] = j;
       }
      }
    }
   }
  }
 }
}

void DVR::print()
{
 for(int i = 0 ; i<= Total-1; i++)
   {
    	cout<<"\n Table of router no. " << i << endl;
    	cout<<"Router No. | Dist | Line";
    	for (int j = 0 ; j<= Total-1; j++)
    	{
      		cout<<"\n";
      		cout<<Table[i][j][0]<<"\t";
      		cout<<Table[i][j][1]<<"\t";
      		cout<<Table[i][j][2];
    	}
   }
}

int main()
{
 int no_of_updates = 0 ; 						//Controls the number of update operations.
 
 DVR obj;
 obj.getdata();
 
 for(int i = 0; i<= no_of_updates; i++)
  {
	 obj.updateTarget();
	 obj.updateTargetAdj();
	 obj.print();
  }
  return 0;
}
