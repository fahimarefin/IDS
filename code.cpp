 #include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int row;
    int col;
};
Node temp;
int row,col;
int cost[1000][1000];
int grid[1000][1000];
int visited[1000][1000];
Node parent[1000][1000];

int ids(int start_i,int start_j,int end_i,int end_j,int level_threshold){

    if(start_i == end_i && start_j == end_j)
        return 1;

    if (level_threshold<=0)
        return 0;

    if(grid[start_i+1][start_j]!=-1 && start_i+1 <= row-1 && visited[start_i+1][start_j] != 1 ){

        cost[start_i+1][start_j]=cost[start_i][start_j]+grid[start_i+1][start_j];
        Node hold;
        hold.row=start_i;
        hold.col=start_j;
        parent[start_i+1][start_j]=hold;
        visited[start_i+1][start_j] = 1;
        if(ids(start_i+1,start_j,end_i,end_j,level_threshold-1) == 1)
        return 1;
    }
     if(grid[start_i][start_j+1]!=-1 && start_j+1 <=col-1 && visited[start_i][start_j+1 ] != 1 ){
        cost[start_i][start_j+1]=cost[start_i][start_j]+grid[start_i][start_j+1];
        Node hold;
        hold.row=start_i;
        hold.col=start_j;
        parent[start_i][start_j+1]=hold;
        visited[start_i][start_j+1 ] = 1;
        if( ids(start_i,start_j+1,end_i,end_j,level_threshold-1) == 1 ) return 1;
    }

    if(grid[start_i][start_j-1]!=-1 && start_j-1 >=0 && visited[start_i][start_j-1] != 1){
        cost[start_i][start_j-1]=cost[start_i][start_j]+grid[start_i][start_j-1];
        Node hold;
        hold.row=start_i;
        hold.col=start_j;
        parent[start_i][start_j-1]=hold;
        visited[start_i][start_j-1] = 1;
        if ( ids(start_i,start_j-1,end_i,end_j,level_threshold-1) == 1) return 1;
    }
     if(grid[start_i-1][start_j]!=-1 && start_i-1 >=0 && visited[start_i -1 ][start_j] != 1){
        cost[start_i-1][start_j]=cost[start_i][start_j]+grid[start_i-1][start_j];
        Node hold;
        hold.row=start_i;
        hold.col=start_j;
        parent[start_i-1][start_j]=hold;
        visited[start_i-1][start_j] = 1;
        if (ids(start_i-1,start_j,end_i,end_j,level_threshold-1) == 1) return 1;
    }
    return 0;

}
int counter=0;
void pathprint(int start_i,int start_j,int end_i , int end_j){


    if(start_i == end_i && start_j == end_j) {
            cout<<counter+1<<endl;
        cout<<start_i<<" "<<start_j;
        return;
    }
    counter++;



    pathprint(parent[start_i][start_j].row,parent[start_i][start_j].col,end_i,end_j);
    cout<<endl<<start_i<<" "<<start_j ;



}




int main(){
    cin>>row>>col;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>>grid[i][j];
            visited[i][j] = 0;
        }
    }

    int start_i,start_j,end_i,end_j;
    cin>>start_i>>start_j>>end_i>>end_j;

    Node hold;

    hold.row=-1;
    hold.col=-1;
    parent[start_i][start_j]=hold;
    visited[start_i][start_j] = 1;
    cost[start_i][start_j] = grid[start_i][start_j];

    ids(start_i,start_j,end_i,end_j,5000);
    cout<<cost[end_i][end_j]<<endl;
    pathprint(end_i,end_j,start_i,start_j);

}
