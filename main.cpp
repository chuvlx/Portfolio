/*
Author: Chukwuka Van-Lare

Problem: Using the VM for Ubuntu 20.04 LTS from Pgm1, write a C/C++ program which implements the banker's algorithm (Section 6.3). Verify your implementation using the data from the textbook as well as the attached, but unverified (meaning that it is possible the system is already in an unsafe state), file. The file format is as follows:

Date due: 10.18.2020
*/

#include <iostream> 
#include <string>
#include <fstream>
#include <sstream>
#include <string>
using namespace std; 
  
int main(){ 

int m=0; //number of resources
int n=0; //number of processes
int *mArr; //available vector
string line; 
	ifstream file("textbook6_8a.txt");   // read from the file
	if(file.is_open())                   //Do everything while the file is open
	{
		for(int i=0; i<3; i++)
		{
			getline(file,line);
			istringstream iss(line);
			if(i == 0)
			{
				iss >> m;
				cout << "Number of resources = " << m << endl;
				mArr =  new int[m];
			}
			if(i==1)
			{
        cout << "Resource vector\n"; 
				for(int j=0; j < m; j++)
				{
					
					iss  >> mArr[j];            //Initialize the resource vector
          cout << mArr[j];
				}
			}
			if(i == 2)
			{
				iss >> n;
			}
		}
		int lnum = 3; //file line number
    int avail [m];
          for(int x = 0; x < m;x++){
            avail[x] = 0;}
		int alloc [n][m];
		int claim [n][m];
		while(lnum >= 3 && lnum< 3+n)                 //counter to keep track of the lines
			{
        cout << "/nClaim matrix" ;
				for(int row=0; row < n;  row++ )
				{
					getline(file,line);                 //Read from the file assign to a string
					istringstream iss(line);            //string to string stream buffer 
          cout<<endl;
					for(int col=0; col < m; col++)      // assign the stream to the matrix
					{
						iss >> claim[row][col];  
						cout << claim[row][col];          // display it
					}
					lnum++;                             //nect line in file
					
				}
				
			}
		while(lnum >= 3+n && lnum< (3+n*2))         //loop to keep track of file line number
			{
        cout<< "\nallocation matrix";
				for(int row=0; row < n;  row++ )
				{
					getline(file,line);                   
					istringstream iss(line);
					cout<< endl;
					for(int col=0; col < m; col++)
					{
						iss >> alloc[row][col];
						cout<< alloc[row][col];
					}
					lnum++;
					
				}
				
			}	

      //Calculate available matrix
  int temp [m];                    // temp will help with our calculations
  for(int i =0; i < m;i++)         // Initialize temp
    temp[i] =0; 
  for(int x=0;x < n;x++)
  {
    for(int j=0; j < m;j++)
    {
      temp[j] += alloc[x][j];      //accumulate the total number of resources allocated 

    }
  }

cout << "\navailable vector\n";
    for(int x=0;x < m;x++)
    {
      avail[x] = mArr[x] - temp[x];   //available = resource vector-total allocated resources
      cout << avail[x] << endl;
    }
	
  
    int x, j, k;          //x will be used from rows
                          //j for columns                                                    // K represents the instances of a particular resource

    int f[n], ans[n], ind = 0; //f[n] finished vector
                               //ans is the safe order vector
                               //ind is the index of ans vector
    for (k = 0; k < n; k++) { 
        f[k] = 0; 
    } 
    int need[n][m]; 
    for (x = 0; x < n; x++) { 
        for (int j = 0; j < m; j++) 
            need[x][j] = claim[x][j] - alloc[x][j]; 
    } 
    int y = 0; 
    for (k = 0; k < n; k++) { 
        for (x = 0; x < n; x++) { 
            if (f[x] == 0) { 
  
                int flag = 0;                       //the "not ready" flag
                for (int j = 0; j < m; j++)
                 { 
                    if (need[x][j] > avail[j]){     //If need_j > avail_j
                        flag = 1;                   // this process is not done so flag
                        break;                      // break
                    } 
                } 
  
                if (flag == 0)                       //if a process is done we add it to ans
                { 
                  
                    ans[ind] = x;                             
                    ind++;
                    for (y = 0; y < m; y++)           //dealloacted resources
                        avail[y] += alloc[x][y]; 
                    f[x] = 1;                         //set the finished flag to true
                } 
            } 
        } 
    } 

  
  for(int x = 0; x < n; x++)                           //Check if its safe
  {
    if(f[x] == 0)                                      // if one of our processes is not done
    {
      cout << "\n Not in a safe sequence" << endl;     // it is not safe
      delete [] mArr;
      return 0;                                        //return
    }
  }
                                                        //if all f[] = 1
    cout << "\nFollowing is the SAFE Sequence" << endl; 
    for (int i = 0; i < n - 1; i++)
        cout << " P" << ans[i] << " ->"; 
    cout << " P" << ans[n - 1] <<endl;
  
  
	delete []  mArr;
    return (0); 
	
	
} 
}

  

/*Have  a resource allocation algorithm function*/