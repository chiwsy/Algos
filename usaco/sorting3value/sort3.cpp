/*
ID: chiwsyl1
PROG: sort3
LANG: C++
*/

#include<iostream>
#include<fstream>

using namespace std;
int step=0;

void swap(int &a, int&b){
    step++;
    int tmp=a;
    a=b;
    b=tmp;
}

int main(){
    int scale;
    ifstream fin("sort3.in");
    fin>>scale;
    int *arr=new int[scale];
    int cont[4]={0};
    for(int i=0;i<scale;i++){
        fin>>arr[i];
        cont[arr[i]]++;
    }

    int p1=0,p2=cont[1],p3=cont[1]+cont[2];
    int cnt[4][4]={0};
    for(int i=p1;i<p2;i++)
        cnt[1][arr[i]]++;
    for(int i=p2;i<p3;i++)
        cnt[2][arr[i]]++;
    for(int i=p3;i<scale;i++)
        cnt[3][arr[i]]++;

    int swapnum=0;
    if(cnt[1][2]<cnt[2][1]){
        swapnum+=cnt[1][2];
        cnt[2][1]-=cnt[1][2];
        cnt[1][2]=0;
    }else{
        swapnum+=cnt[2][1];
        cnt[1][2]-=cnt[2][1];
        cnt[2][1]=0;
    }

    if(cnt[1][3]<cnt[3][1]){
        swapnum+=cnt[1][3];
        cnt[3][1]-=cnt[1][3];
        cnt[1][3]=0;
    }
    else{
        swapnum+=cnt[3][1];
        cnt[1][3]-=cnt[3][1];
        cnt[3][1]=0;
    }

    if(cnt[2][3]<cnt[3][2]){
        swapnum+=cnt[2][3];
        cnt[3][2]-=cnt[2][3];
        cnt[2][3]=0;
    }
    else{
        swapnum+=cnt[3][2];
        cnt[2][3]-=cnt[3][2];
        cnt[3][2]=0;
    }

    swapnum+=2*cnt[1][2]+2*cnt[1][3];

    ofstream fout("sort3.out");
    fout<<swapnum<<endl;
    return 0;
}
