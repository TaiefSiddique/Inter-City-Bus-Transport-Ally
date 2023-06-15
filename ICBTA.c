#include<stdio.h>
#include<stdlib.h>
#define max=1000
#include<conio.h>
#define INFINITY 9999
#define MAX 8
int ue5;
int ii=0;
FILE *file;

int sc=0;

///////////////////////////////Ticket Counter///////////////////////////////////
struct account
{

    int number;
    char sit[2];
    char name1[25];
    char name[25];
    long long mobile_no;
    int roadNo;
    int houseNo;
    float payable;
    float paid;
    float returned;
    struct date
    {
        int month;
        int day;
        int year;
    } pay;
} ;
 struct account customer[100];
void input1(int i)
{

    file=fopen("file2.txt","a");
    fputs("\n",file);
    printf("\n\n         Ticket No:%d",ii);
    customer[i].number=ii++;
    fflush(stdin);
    printf("\n         Name:");
    scanf("%s",&customer[i].name);
    printf("         mobile no:");
    scanf("%lld",&customer[i].mobile_no);
    printf("         Seat:");
    scanf("%s",&customer[i].sit);
    printf("         Road No:");
    scanf("%d",&customer[i].roadNo);
    printf("         House No:");
    scanf("%d",&customer[i].houseNo);
    printf("         Total Payable:");
    scanf("%f",&customer[i].payable);
    printf("         Paid:");
    scanf("%f",&customer[i].paid);
    customer[i].returned=customer[i].paid-customer[i].payable;
    printf("         Returned:%.2f\n",customer[i].returned);
    printf("         Payment date(mm/dd/yyyy):");
    scanf("%d/%d/%d",&customer[i].pay.month,&customer[i].pay.day,&customer[i].pay.year);
}
void input()
{
    int i;
    printf("How many Accounts you want to enter: ");
    scanf("%d",&sc);

    for(i=0; i<sc; i++)
    {
        input1(i);
    }
    TicketCounter();
}
void search()
{
    int cc,kc,value;
    char name[10];
    system("cls");
    printf("Sub Menu\n");
    printf("1. Search by Ticket Number\n");
    printf("2. Search by Customer Name\n");
    scanf("%d",&kc);
    if(kc==1)
    {
        printf("Enter Ticket number to search ");
        scanf("%d",&cc);
        for(int i=0;i<sc;i++){
        if (cc==customer[i].number)
        {
            display(i);
            getch();
            TicketCounter();
        }
        }
    }
    else if(kc==2)
    {
        printf("Enter Customer name to search ");
        scanf("%s",&name);
        int flag=1;
        for(int i=0;i<sc;i++){
        value=strcmp(name,customer[i].name);
        if(value==0)
        {
            display(i);
           flag=0;
            getch();
            TicketCounter();
        }
        }

        if(flag)
        {
            printf("No account with searched Name\n");
            getch();
            TicketCounter();
        }

    }
    else
    {
        printf("\nInvalid Choice ");
        getch();
        TicketCounter();
    }

}
void display(int i)
{
    printf("\n\n    Ticket no    :%d\n",customer[i].number);
    printf("    Name           :%s\n",customer[i].name);
    printf("    Seat            :%c%c\n",customer[i].sit[0],customer[i].sit[1]);
    printf("    Mobile no      :0%lld\n",customer[i].mobile_no);
    printf("    Road No        :%d\n",customer[i].roadNo);
    printf("    House No       :%d\n",customer[i].houseNo);
    printf("    Payable        :%.2f\n",customer[i].payable);
    printf("    Paid           :%.2f\n",customer[i].paid);
    printf("    Returned       :%.2f\n",customer[i].returned);
    printf("    Payment date   :%d/%d/%d\n\n",customer[i].pay.month,customer[i].pay.day,customer[i].pay.year);
    return;
}
void DisplayBookedSits()
{
    for(int i=0;i<sc;i++){
    printf("%s\n",customer[i].sit);
    }
}

void TicketCounter()
{

    system("cls");
    printf("MENU\n");
    printf("1. Input\n");
    printf("2. Search\n");
    printf("3. Display All\n");
    printf("4. Booked Sits\n");
    int hg;
    scanf("%d",&hg);
    switch(hg)
    {
    case 1:
        input();
    case 2:
        search();
    case 3:
    {
        system("cls");
        for(int i=0;i<sc;i++)
            display(i);
        getch();
        TicketCounter();
    }
    case 4:
        {
        system("cls");

            DisplayBookedSits();
        getch();
        TicketCounter();
    }

    }
}

////////////////////////////////Ticket Counter/////////////////////////////
///////////////////////////////Route Visualization/////////////////////////
void dijkstra(int G[MAX][MAX],int n,int startnode)
{
    system("cls");
    int cost[MAX][MAX],distance[MAX],pred[MAX];
    int visited[MAX],count,mindistance,nextnode,i,j;

    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            if(G[i][j]==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=G[i][j];
    for(i=0; i<n; i++)
    {
        distance[i]=cost[startnode][i];
        pred[i]=startnode;
        visited[i]=0;
    }
    distance[startnode]=0;
    visited[startnode]=1;
    count=1;
    while(count<n-1)
    {
        mindistance=INFINITY;
        for(i=0; i<n; i++)
            if(distance[i]<mindistance&&!visited[i])
            {
                mindistance=distance[i];
                nextnode=i;
            }
        visited[nextnode]=1;
        for(i=0; i<n; i++)
            if(!visited[i])
                if(mindistance+cost[nextnode][i]<distance[i])
                {
                    distance[i]=mindistance+cost[nextnode][i];
                    pred[i]=nextnode;
                }
        count++;
    }
char a[8][3];
    a[0][0]='R';
    a[0][1]='A';
    a[0][2]='N';

    a[1][0]='M';
    a[1][1]='Y';
    a[1][2]='M';

    a[2][0]='S';
    a[2][1]='Y';
    a[2][2]='L';

    a[3][0]='R';
    a[3][1]='A';
    a[3][2]='J';

    a[4][0]='D';
    a[4][1]='H';
    a[4][2]='K';

    a[5][0]='K';
    a[5][1]='H';
    a[5][2]='L';

    a[6][0]='B';
    a[6][1]='A';
    a[6][2]='R';

    a[7][0]='C';
    a[7][1]='T';
    a[7][2]='G';

///////
    for(i=0; i<n; i++)
        if(i!=startnode)
        {
            int temp1=i;
            int temp2=i;
            int k;
            printf("\n%d=",distance[temp2]);
            for (k=0;k<3;k++)
                printf("%c",a[i][k]);
            j=i;
            do
            {
                j=pred[j];
                printf("<-");
                for (k=0;k<3;k++)
                printf("%c",a[j][k]);

            }
            while(j!=startnode);
        }
}

int RouteVisualization()
{
    int G[MAX][MAX],i,j,n=8,u;
    /*
    Rangpur->Mymensingh->Sylhet->Rajshahi->Dhaka->Khulna->Barisal->CTG
    */
    G[0][0]=0;
    G[0][1]=292;
    G[0][2]=503;
    G[0][3]=211;
    G[0][4]=298;
    G[0][5]=395;
    G[0][6]=466;
    G[0][7]=546;
    G[1][0]=292;
    G[1][1]=0;
    G[1][2]=191;
    G[1][3]=239;
    G[1][4]=110;
    G[1][5]=330;
    G[1][6]=291;
    G[1][7]=357;

    G[2][0]=503;
    G[2][1]=191;
    G[2][2]=0;
    G[2][3]=448;
    G[2][4]=235;
    G[2][5]=440;
    G[2][6]=402;
    G[2][7]=358;
    G[3][0]=211;
    G[3][1]=239;
    G[3][2]=448;
    G[3][3]=0;
    G[3][4]=243;
    G[3][5]=266;
    G[3][6]=337;
    G[3][7]=491;

    G[4][0]=298;
    G[4][1]=110;
    G[4][2]=235;
    G[4][3]=243;
    G[4][4]=0;
    G[4][5]=221;
    G[4][6]=182;
    G[4][7]=248;
    G[5][0]=395;
    G[5][1]=330;
    G[5][2]=440;
    G[5][3]=266;
    G[5][4]=221;
    G[5][5]=0;
    G[5][6]=144;
    G[5][7]=348;

    G[6][0]=466;
    G[6][1]=291;
    G[6][2]=402;
    G[6][3]=337;
    G[6][4]=182;
    G[6][5]=144;
    G[6][6]=0;
    G[6][7]=238;
    G[7][0]=546;
    G[7][1]=357;
    G[7][2]=358;
    G[7][3]=491;
    G[7][4]=248;
    G[7][5]=348;
    G[7][6]=238;
    G[7][7]=0;


    printf(" ---------------------------------------");
    printf("\n");
    printf("|  0.Rangpur");printf("\n");
    printf("|  1.Mymensingh");printf("\n");
    printf("|  2.Sylhet");printf("\n");
    printf("|  3.Rajshahi");printf("\n");
    printf("|  4.Dhaka");printf("\n");
    printf("|  5.Khulna");printf("\n");
    printf("|  6.Barisal");printf("\n");
    printf("|  7.Chittagong");printf("\n");
    printf(" ---------------------------------------");printf("\n");
    printf("Enter Current Location: " );
    scanf("%d",&u);
    dijkstra(G,n,u);
    getch();
    main();
}
//////////////////////////////Route Visualization//////////////////////////
//////////////////////////////DriveAssist//////////////////////////////////
void dijkstra1(int G[MAX][MAX],int n,int startnode)
{
    system("cls");
    int cost[MAX][MAX],distance[MAX],pred[MAX];
    int visited[MAX],count,mindistance,nextnode,i,j;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            if(G[i][j]==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=G[i][j];
    for(i=0; i<n; i++)
    {
        distance[i]=cost[startnode][i];
        pred[i]=startnode;
        visited[i]=0;
    }
    distance[startnode]=0;
    visited[startnode]=1;
    count=1;
    while(count<n-1)
    {
        mindistance=INFINITY;
        for(i=0; i<n; i++)
            if(distance[i]<mindistance&&!visited[i])
            {
                mindistance=distance[i];
                nextnode=i;
            }
        visited[nextnode]=1;
        for(i=0; i<n; i++)
            if(!visited[i])
                if(mindistance+cost[nextnode][i]<distance[i])
                {
                    distance[i]=mindistance+cost[nextnode][i];
                    pred[i]=nextnode;
                }
        count++;
    }

char a[8][3];
    a[0][0]='R';
    a[0][1]='A';
    a[0][2]='N';

    a[1][0]='M';
    a[1][1]='Y';
    a[1][2]='M';

    a[2][0]='S';
    a[2][1]='Y';
    a[2][2]='L';

    a[3][0]='R';
    a[3][1]='A';
    a[3][2]='J';

    a[4][0]='D';
    a[4][1]='H';
    a[4][2]='K';

    a[5][0]='K';
    a[5][1]='H';
    a[5][2]='L';

    a[6][0]='B';
    a[6][1]='A';
    a[6][2]='R';

    a[7][0]='C';
    a[7][1]='T';
    a[7][2]='G';


    for(i=0; i<n; i++)
        if(i!=startnode)
        {
            int temp1=i;
            int temp2=i;
            int k;
             if(i==ue5){
            printf("\n%d=",distance[temp2]);
            for (k=0;k<3;k++)
                printf("%c",a[i][k]);

            j=i;
            do
            {
                j=pred[j];
                printf("<-");
                for (k=0;k<3;k++)
                printf("%c",a[j][k]);
            }
            while(j!=startnode);
        }
        }
}
int DriveAssist()
{
    int G[MAX][MAX],i,j,n=8,u1;

    /*
    Rangpur->Mymensingh->Sylhet->Rajshahi->Dhaka->Khulna->Barisal->CTG
    */
    G[0][0]=0;
    G[0][1]=292;
    G[0][2]=503;
    G[0][3]=211;
    G[0][4]=298;
    G[0][5]=395;
    G[0][6]=466;
    G[0][7]=546;
    G[1][0]=292;
    G[1][1]=0;
    G[1][2]=191;
    G[1][3]=239;
    G[1][4]=110;
    G[1][5]=330;
    G[1][6]=291;
    G[1][7]=357;

    G[2][0]=503;
    G[2][1]=191;
    G[2][2]=0;
    G[2][3]=448;
    G[2][4]=235;
    G[2][5]=440;
    G[2][6]=402;
    G[2][7]=358;
    G[3][0]=211;
    G[3][1]=239;
    G[3][2]=448;
    G[3][3]=0;
    G[3][4]=243;
    G[3][5]=266;
    G[3][6]=337;
    G[3][7]=491;

    G[4][0]=298;
    G[4][1]=110;
    G[4][2]=235;
    G[4][3]=243;
    G[4][4]=0;
    G[4][5]=221;
    G[4][6]=182;
    G[4][7]=248;
    G[5][0]=395;
    G[5][1]=330;
    G[5][2]=440;
    G[5][3]=266;
    G[5][4]=221;
    G[5][5]=0;
    G[5][6]=144;
    G[5][7]=348;

    G[6][0]=466;
    G[6][1]=291;
    G[6][2]=402;
    G[6][3]=337;
    G[6][4]=182;
    G[6][5]=144;
    G[6][6]=0;
    G[6][7]=238;
    G[7][0]=546;
    G[7][1]=357;
    G[7][2]=358;
    G[7][3]=491;
    G[7][4]=248;
    G[7][5]=348;
    G[7][6]=238;
    G[7][7]=0;


    printf(" ---------------------------------------");
    printf("\n");
    printf("|  0.Rangpur");printf("\n");
    printf("|  1.Mymensingh");printf("\n");
    printf("|  2.Sylhet");printf("\n");
    printf("|  3.Rajshahi");printf("\n");
    printf("|  4.Dhaka");printf("\n");
    printf("|  5.Khulna");printf("\n");
    printf("|  6.Barisal");printf("\n");
    printf("|  7.Chittagong");printf("\n");
    printf(" ---------------------------------------");printf("\n");
    printf("Enter Current Location: " );
    scanf("%d",&u1);
    printf("Enter Destined Location: " );
    scanf("%d",&ue5);
    dijkstra1(G,n,u1);
    getch();
    main();
}


/////////////////////////////DriveAssist////////////////////////////////////
int main()
{
    system("cls");
    printf("MENU\n");
    printf("1. Ticket Counter\n");//Bus name, Jousney date
    printf("2. Route Visualization\n");
    printf("3. Drive Assist\n");
    int hg;
    scanf("%d",&hg);
    switch(hg)
    {
    case 1:
        TicketCounter();
    case 2:
        RouteVisualization();
    case 3:
        DriveAssist();
    }

}
