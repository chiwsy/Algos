/*
ID: chiwsyl1
PROG: castle
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

struct room{
    int x,y;
    int wall;
    int area;
    room(const int& _x, const int& _y, const int& _wall){
        x=_x;
        y=_y;
        wall=_wall;
        area=1;
    }
    room(){
        x=y=wall=0;
        area=1;
    }
};
void visit(int row, int col, vector<vector<bool> >& visited, vector<vector<room> >& castle, int& roomnum,int& maxroom){

    visited[row][col]=true;
    int fx=row;
    int fy=col;
    while(fx!=castle[fx][fy].x||fy!=castle[fx][fy].y){
        int tfx=castle[fx][fy].x;
        int tfy=castle[fx][fy].y;
        castle[fx][fy].x=castle[tfx][tfy].x;
        castle[fx][fy].y=castle[tfx][tfy].y;
        fx=tfx;
        fy=tfy;
    }
    //cout<<fx<<' '<<fy<<' '<<castle[fx][fy].area<<endl;
    if((castle[row][col].wall&1)==0){
        if(col>0){
                //cout<<"ok"<<endl;
            int nfx=row;
            int nfy=col-1;
            while(nfx!=castle[nfx][nfy].x||nfy!=castle[nfx][nfy].y){
                int tfx=castle[nfx][nfy].x;
                int tfy=castle[nfx][nfy].y;
                castle[nfx][nfy].x=castle[tfx][tfy].x;
                castle[nfx][nfy].y=castle[tfx][tfy].y;
                nfx=tfx;
                nfy=tfy;
            }
            if(nfx!=fx||nfy!=fy){
                if(fx*visited[0].size()+fy<nfx*visited[0].size()+nfy){
                    castle[nfx][nfy].x=fx;
                    castle[nfx][nfy].y=fy;
                    castle[fx][fy].area+=castle[nfx][nfy].area;
                    maxroom=maxroom>castle[fx][fy].area?maxroom:castle[fy][fy].area;
                }else{
                    castle[fx][fy].x=nfx;
                    castle[fx][fy].y=nfy;
                    castle[nfx][nfy].area+=castle[fx][fy].area;
                    fx=nfx;
                    fy=nfy;
                    maxroom=maxroom>castle[nfx][nfy].area?maxroom:castle[nfy][nfy].area;
                }
            }
            if(!visited[row][col-1])
                visit(row,col-1,visited,castle,roomnum,maxroom);
        }
    }
    if((castle[row][col].wall&2)==0){
        if(row>0){
               // cout<<"ok"<<endl;
            int nfx=row-1;
            int nfy=col;
            while(nfx!=castle[nfx][nfy].x||nfy!=castle[nfx][nfy].y){
                int tfx=castle[nfx][nfy].x;
                int tfy=castle[nfx][nfy].y;
                castle[nfx][nfy].x=castle[tfx][tfy].x;
                castle[nfx][nfy].y=castle[tfx][tfy].y;
                nfx=tfx;
                nfy=tfy;
            }

            if(nfx!=fx||nfy!=fy){
                if(fx*visited[0].size()+fy<nfx*visited[0].size()+nfy){
                    castle[nfx][nfy].x=fx;
                    castle[nfx][nfy].y=fy;
                    castle[fx][fy].area+=castle[nfx][nfy].area;
                    maxroom=maxroom>castle[fx][fy].area?maxroom:castle[fy][fy].area;
                }else{
                    castle[fx][fy].x=nfx;
                    castle[fx][fy].y=nfy;

                    castle[nfx][nfy].area+=castle[fx][fy].area;
                    fx=nfx;
                    fy=nfy;
                    maxroom=maxroom>castle[nfx][nfy].area?maxroom:castle[nfy][nfy].area;
                }
            }
            if(!visited[row-1][col])
                visit(row-1,col,visited,castle,roomnum,maxroom);
        }
    }
    if((castle[row][col].wall&4)==0){
        if(col<visited[0].size()-1){
            int nfx=row;
            int nfy=col+1;
            //cout<<nfx<<' '<<nfy<<' ';
            while(nfx!=castle[nfx][nfy].x||nfy!=castle[nfx][nfy].y){
                int tfx=castle[nfx][nfy].x;
                int tfy=castle[nfx][nfy].y;
                castle[nfx][nfy].x=castle[tfx][tfy].x;
                castle[nfx][nfy].y=castle[tfx][tfy].y;
                nfx=tfx;
                nfy=tfy;
            }
            //cout<<nfx<<' '<<nfy<<endl;
            if(nfx!=fx||nfy!=fy){
                if(fx*visited[0].size()+fy<nfx*visited[0].size()+nfy){
                    castle[nfx][nfy].x=fx;
                    castle[nfx][nfy].y=fy;
                    castle[fx][fy].area+=castle[nfx][nfy].area;
                    maxroom=maxroom>castle[fx][fy].area?maxroom:castle[fy][fy].area;
                }else{
                    castle[fx][fy].x=nfx;
                    castle[fx][fy].y=nfy;
                    castle[nfx][nfy].area+=castle[fx][fy].area;
                    fx=nfx;
                    fy=nfy;
                    maxroom=maxroom>castle[nfx][nfy].area?maxroom:castle[nfy][nfy].area;
                }
            }
            if(!visited[row][col+1])
                visit(row,col+1,visited,castle,roomnum,maxroom);
        }
    }
    if((castle[row][col].wall&8)==0){
        if(row<visited.size()-1){
            int nfx=row+1;
            int nfy=col;
            while(nfx!=castle[nfx][nfy].x||nfy!=castle[nfx][nfy].y){
                int tfx=castle[nfx][nfy].x;
                int tfy=castle[nfx][nfy].y;
                castle[nfx][nfy].x=castle[tfx][tfy].x;
                castle[nfx][nfy].y=castle[tfx][tfy].y;
                nfx=tfx;
                nfy=tfy;
            }

            if(nfx!=fx||nfy!=fy){
                if(fx*visited[0].size()+fy<nfx*visited[0].size()+nfy){
                    castle[nfx][nfy].x=fx;
                    castle[nfx][nfy].y=fy;
                    castle[fx][fy].area+=castle[nfx][nfy].area;
                    maxroom=maxroom>castle[fx][fy].area?maxroom:castle[fy][fy].area;
                }else{
                    castle[fx][fy].x=nfx;
                    castle[fx][fy].y=nfy;

                    castle[nfx][nfy].area+=castle[fx][fy].area;
                    fx=nfx;
                    fy=nfy;
                    maxroom=maxroom>castle[nfx][nfy].area?maxroom:castle[nfy][nfy].area;
                }
            }
            if(!visited[row+1][col])
                visit(row+1,col,visited,castle,roomnum,maxroom);
        }
    }
}
int main(){
    ifstream fin("castle.in");
    int row, col;
    fin>>col>>row;
    //cout<<col<<' '<<row;
    vector<vector<room> > castle(row,vector<room>(col,room()));
    vector<vector<bool> > visited(row,vector<bool>(col,false));
    string up;
    string cur;
    //string down;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            castle[i][j].x=i;
            castle[i][j].y=j;
            fin>>castle[i][j].wall;
            //if(castle[i][j].wall&1) cur+="#   ";
            //else cur+="|   ";
            //if(castle[i][j].wall&2) up+="#####";
           // else up+="#---#";
           // if(castle[i][j].wall&4) {cur+="#";}
           // else cur+="|";
            //cout<<i<<' '<<j<<' '<<castle[i][j].wall<<' '<<((castle[i][j].wall&1)==0)<<endl;
            //printf("%d %d %d\n",i, j, castle[i][j].wall);
        }
        //cout<<up<<endl;
        //cout<<cur<<endl;
        //up="";
        //cur="";
    }
    fin.close();

    int roomnum=0;
    int maxroom=1;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(!visited[i][j]){
                roomnum++;
                visit(i,j,visited,castle,roomnum,maxroom);
            }
            //printf("%d %d %d %d %d\n",i, j,castle[i][j].x,castle[i][j].y,castle[i][j].area);
        }
    }


    int wx=0,wy=0;
    char wd='W';
    int maxarea=1;
    maxroom=1;
    for(int j=0;j<col;j++){
        for(int i=row-1;i>=0;i--){
            int fx=i;
            int fy=j;
            //cout<<i<<' '<<j<<endl;
            while(fx!=castle[fx][fy].x||fy!=castle[fx][fy].y){
                int tfx=castle[fx][fy].x;
                int tfy=castle[fx][fy].y;
                //cout<<tfx<<' '<<tfy<<endl;
                castle[fx][fy].x=castle[tfx][tfy].x;
                castle[fx][fy].y=castle[tfx][tfy].y;
                fx=tfx;
                fy=tfy;
            }
            if(castle[fx][fy].area>maxroom) maxroom=castle[fx][fy].area;

            if(castle[i][j].wall&2){
                if(i>0){
                    int nfx=i-1;
                    int nfy=j;
                    while(nfx!=castle[nfx][nfy].x||nfy!=castle[nfx][nfy].y){
                        int tfx=castle[nfx][nfy].x;
                        int tfy=castle[nfx][nfy].y;
                        castle[nfx][nfy].x=castle[tfx][tfy].x;
                        castle[nfx][nfy].y=castle[tfx][tfy].y;
                        nfx=tfx;
                        nfy=tfy;
                    }
                    if((fx!=nfx||fy!=nfy)&&castle[fx][fy].area+castle[nfx][nfy].area>maxarea){
                        maxarea=castle[fx][fy].area+castle[nfx][nfy].area;
                        wx=i;
                        wy=j;
                        wd='N';
                    }
                }
            }
            if(castle[i][j].wall&4){
                if(j<col-1){
                    int nfx=i;
                    int nfy=j+1;
                    while(nfx!=castle[nfx][nfy].x||nfy!=castle[nfx][nfy].y){
                        int tfx=castle[nfx][nfy].x;
                        int tfy=castle[nfx][nfy].y;
                        castle[nfx][nfy].x=castle[tfx][tfy].x;
                        castle[nfx][nfy].y=castle[tfx][tfy].y;
                        nfx=tfx;
                        nfy=tfy;
                    }
                    if((fx!=nfx||fy!=nfy)&&castle[fx][fy].area+castle[nfx][nfy].area>maxarea){
                        maxarea=castle[fx][fy].area+castle[nfx][nfy].area;
                        wx=i;
                        wy=j;
                        wd='E';
                    }
                }
            }
        }
    }

    ofstream fout("castle.out");
    fout<<roomnum<<endl;
    fout<<maxroom<<endl;
    fout<<maxarea<<endl;
    fout<<wx+1<<' '<<wy+1<<' '<<wd<<endl;
    return 0;
}
