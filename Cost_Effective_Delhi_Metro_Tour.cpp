#include <bits/stdc++.h>
#include <cstdlib>
#include<map>
#include<conio.h>
#include<fstream>
using namespace std;

#define MAX 50
#define INF 99999

map<string,string>suggest;

map<string,int>Rating;

string sName[INF];

string rName[INF];

//it works for giving shortest distance from 
//one staion to other one

void dijk1(int g[MAX][MAX],int n,int start,int dest,map<int,string>map)
{

    int cost[MAX][MAX],dist[MAX],pred[MAX],visited[MAX];

    int i,j,count,mindist,nextNode;
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(g[i][j]==0)
            {
                cost[i][j]=INF;
            }
            else
            {
                cost[i][j]=g[i][j];
            }
        }

    }
    
    for(i=0;i<n;i++)
    {
        dist[i]=cost[start][i];

        pred[i]=start;

        visited[i]=0;
    }
    dist[start]=0;

    visited[start]=1;

    count=1;
    
    while(count<n-1)
    {
        mindist=INF;

        for(i=0;i<n;i++)
        {
            if(dist[i]<mindist && !visited[i])
            {
                mindist=dist[i];
                nextNode=i;
            }
        }

        visited[nextNode]=1;

        for(i=0;i<n;i++)
        {
            if(!visited[i])
            {
                if(mindist+cost[nextNode][i]<dist[i])
                {
                   dist[i]=mindist+cost[nextNode][i];

                   pred[i]=nextNode;
                }
            }
        }

        count++;

    }

    int s=0;
    
     i=dest;

	if (i != start)
	{
		cout << "\n\tThe total fare of metro to go to the station " << map[i] << " is " << dist[i] << endl;

		s = dist[i];

		cout << "\t";

		cout << map[i];

		j = i;

		do {
			j = pred[j];
			cout << "<--" << map[j];
		} while (j != start);
	}  
    
}


void dijk(int g[MAX][MAX],int n,int start,int dest,map<int,string>map)
{
    int cost[MAX][MAX],dist[MAX],pred[MAX],visited[MAX];

    int i,j,count,mindist,nextNode;
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(g[i][j]==0)
            {
                cost[i][j]=INF;
            }
            else
            {
                cost[i][j]=g[i][j];
            }
        }
    }
    
    for(i=0;i<n;i++)
    {
        dist[i]=cost[start][i];

        pred[i]=start;

        visited[i]=0;
    }
    dist[start]=0;

    visited[start]=1;

    count=1;
    
    while(count<n-1)
    {
        mindist=INF;

        for(i=0;i<n;i++)
        {
            if(dist[i]<mindist && !visited[i])
            {
                mindist=dist[i];

                nextNode=i;
            }
        }

        visited[nextNode]=1;

        for(i=0;i<n;i++)
        {
            if(!visited[i])
            {
                if(mindist+cost[nextNode][i]<dist[i])
                {
                   dist[i]=mindist+cost[nextNode][i];

                   pred[i]=nextNode;
                }
            }
        }

        count++;
    }

    int s=0;

    for(i=0;i<n;i++)
    {
        if(i!=start)
        {
            cout<<"the total fare of metro to go to the station "<<map[i]<<" is "<<dist[i]<<endl;

            s+=dist[i];

            cout<<map[i];
            
            j=i;

            do
            {
                j=pred[j];

                cout<<"<--"<<map[j];

            }while(j!=start);
        }

        printf("\n");

    }
    printf("SO IN TOTAL YOU HAVE TO KEEP FOR METRO FARE TO GO TO THE TOURIST PLACES IN DELHI :");

    printf("%d RS",s); 

    
}

void displaySuggest(int u)
{
    
    for(int i=0;i<u;i++)
    {
        
        cout<<"name: "<<sName[i]<<" suggestion: "<<suggest[sName[i]]<<endl;
    }

}

void displayRating(int u)
{
    for(int i=0;i<u;i++)
    {
        cout<<"name: "<<rName[i]<<" Rating: "<<Rating[rName[i]]<<endl;
    }

}


int main()
{
    int n,i,j,start,dest,user1=0,user2=0;

    map<int,string>map;

    ifstream st("stations.txt");
    
    if (!st) 
    {
       cout << "Cannot open file.\n";
    }

    for(int i=0;i<MAX;i++)
    {
        st>>map[i];
    }

    st.close();

    int g[MAX][MAX];

  ifstream in("dataset.txt");

  if (!in) 
  {
    cout << "Cannot open file.\n";
  }

  for (int y = 0; y < MAX; y++) 
  {
    for (int x = 0; x < MAX; x++)
    {
      in >> g[x][y];
    }
  }

  in.close();
    
  string name,name1,sugg;int choice=1;

  while(choice==1)
  {
    printf("#############################################################################\n");
    printf("#########********************************************************############\n");
    printf("##### ***** **** *** COST EFFECTIVE DELHI METRO TOUR *** **** ***** #########\n") ;
    printf("#########*******************************************************#############\n");
    printf("#############################################################################\n");
    

    printf("CREATED AND  PRESENTED BY:\n");
    printf("1.BISWARUP SAHA [BATCH-B2 ENROLLMENT NO.-19103073]\n");
    

    printf("YOUR CHOICES ARE:\n");
    printf("PRESS 1 FOR YOUR COST EFFECTIVE DELHI TOUR PLAN (only the metro station that are nearest to the tourist places included)\n");
    printf("PRESS 2 FOR GIVING US A RATING(it will be helpful for us to know your satisfaction level)\n");
    printf("PRESS 3 FOR YOUR SUGGESTION \n");
    printf("PRESS 4 TO SEE SUGGESTIONS AND RATINGS \n");
    printf("PRESS 5 TO TAKE ONE TO ONE PLAN \n");
    printf("PRESS 6 TO EXIT\n\n");
    
    int x;

    printf("ENTER YOUR CHOICE PLEASE:\n");

    cin>>x;
    
    switch(x)
    {
        case 1:
           printf("PLEASE ENTER YOUR STARTING METRO STATION ACCORDING TO THE INDEX LIST:\n");
    
           for(int i=0;i<MAX;i++)
           {
              cout<<i<<" "<<map[i]<<endl;
           }
           printf("enter the starting station index: ");
    
           cin>>start;

           dijk(g,MAX,start,-1,map);

           break;
        case 2:
            printf("enter your Name please: ");

            cin>>name;

            rName[user1]=name;

            int rating;
            printf("enter your rating for us: ");

            cin>>rating;

            Rating[name]=rating;

            user1++;

            break;
       case 3:
           printf("enter your Name please: ");

           cin>>name1;

           sName[user2]=name1;

           printf("enter your suggestion: ");
           cin>>sugg;

           suggest[name1]=sugg;

           user2++;

           break;
       case 4:
           printf("ENTER YOOUR ADMIN PASSWORD: ");

           int pass;

           cin>>pass;

           if(pass==INF)
           {
             printf("enter 1 to see suggestions\n");
             printf("enter 2 to see your ratings\n");
             int r,p;
             cin>>r;
             if(r==1)
             {
                 displaySuggest(user2);

                 printf("enter 2 if you want to see ratings also: ");

                 cin>>p;

                 if(p==2)displayRating(user1);
             }
             else if(r==2)
             {
                 displayRating(user1);

                printf("enter 1 if you want to see suggestions also: ");

                 cin>>p;

                 if(p==1)displaySuggest(user2);
             }
             else
             {
                 printf("INVALID CHOICE!!!!");
             }
           }

           else
           {
               printf("sorry it is an admin only portal sir!!");
           }

           break;

        case 5:
           printf("PLEASE ENTER YOUR METRO STATIONS ACCORDING TO THE INDEX LIST:\n");
    
           for(int i=0;i<MAX;i++)
           {
              cout<<i<<" "<<map[i]<<endl;
           }
           printf("enter the starting station index: ");
    
           cin>>start;

           printf("enter the destination station index: ");

           cin>>dest;

           dijk1(g,MAX,start,dest,map);
           
           break;
        case 6:
           choice=2;
    }
    printf("\nPress'ENTER' to continue: ");

    char keyy=getch();

    if(keyy==13)system("cls");

  } 

   printf("THANK YOU FOR HAVING A LOOK...");
   
    return 0;
}
